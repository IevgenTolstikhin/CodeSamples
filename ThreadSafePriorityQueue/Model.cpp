#include "Model.h"
#include <chrono>
#include <fstream>
#include "string.h"

#ifndef _WIN32
#include <sys/time.h>
unsigned long
GetTickCount( )
{
    struct timeval tv;
    gettimeofday( &tv, NULL );
    return ( tv.tv_sec * 1000 + tv.tv_usec / 1000 );
}
#endif

const unsigned char Model::min_priority = 255;
const unsigned char Model::max_priority = 0;
const int32_t Model::min_client_sleep_in_milliseconds = 100;
const int32_t Model::max_client_sleep_in_milliseconds = 1000;
const int32_t Model::server_sleep_time_in_seconds = 1;

Model::Model( const int32_t clients_number, const std::string& log_path )
    : clients_number( clients_number )
    , log_file_name( log_path )
    , work_finished( false )
    , priority_distribution( max_priority, min_priority )
    , delay_distribution( min_client_sleep_in_milliseconds, max_client_sleep_in_milliseconds )
{
}

Model::~Model( )
{
    work_finished = true;
    for ( auto& thread : client_threads )
        if ( thread.joinable( ) )
            thread.join( );

    if ( server_thread.joinable( ) )
        server_thread.join( );
}

void
Model::start( )
{
    if ( client_threads.size( ) == 0 )
    {
        for ( int32_t i = 1; i <= clients_number; ++i )
            client_threads.push_back( std::thread( &Model::run_client, this, i ) );

        server_thread = std::thread( &Model::run_server, this );
    }

    work_finished = false;
}

void
Model::stop( )
{
    work_finished = true;
}

void
Model::run_client( const int32_t client_id )
{
    while ( !work_finished )
    {
        queue.push( generate_random_data( client_id ) );
        std::this_thread::sleep_for( std::chrono::milliseconds( delay_distribution( engine ) ) );
    }
}

void
Model::run_server( )
{
    std::ofstream myfile;
    myfile.open( log_file_name, std::ios::in | std::ios::trunc );

    int32_t record_number = 0;

    while ( !work_finished )
    {
        int32_t record_count = 0;
        while ( auto tdata = queue.try_pop( ) )
        {
            myfile << "Record number = " << record_number++ << std::endl;
            myfile << "Write time (in ticks) = " << GetTickCount( ) << std::endl;
            myfile << "Client ID = " << tdata->client_id << std::endl;
            myfile << "Priority = " << tdata->priority << std::endl;
            myfile << "Data Ticks = " << tdata->ticks << std::endl << std::endl;
            ++record_count;
        }

        myfile << record_count << " records is processed. waiting for another data... \n\n";
        myfile.flush( );

        std::this_thread::sleep_for( std::chrono::seconds( server_sleep_time_in_seconds ) );
    }

    myfile.close( );
}

TDATA
Model::generate_random_data( const int32_t client_id )
{
    TDATA tmp;
    tmp.priority = priority_distribution( engine );
    tmp.ticks = GetTickCount( );
    tmp.client_id = client_id;
    tmp.data = L"Some data";

    return tmp;
}
