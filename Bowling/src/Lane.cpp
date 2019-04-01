#include "Lane.h"
#include "Player.h"
#include "Utils.h"
#include "Game.h"
#include <iostream>

CLane::CLane( unsigned uAmountOfPlayers )
    : vpPlayer( uAmountOfPlayers )
    , puUtil( std::make_unique<CUtils>( ) )
    , gen( rd( ) )
    , m_uAmountOfItems( 0 )
    , m_uAmountOfPlayers( uAmountOfPlayers )
{
    for ( unsigned i = 0; i < m_uAmountOfPlayers; ++i )
    {
        std::string sName;
#ifdef UNIT_TEST
        sName = "Player" + std::to_string(i);
#else
        std::cout << "Input player # " << i + 1 << " name: ";
        std::cin >> sName;
#endif

        ModifyPlayer( i, sName );
    }
}

void
CLane::ModifyPlayer( unsigned uIndex, const std::string& sName )
{
    auto pPlayer = std::make_shared<CPlayer>( sName );
    vpPlayer.at( uIndex ) = std::move( pPlayer );
}

void
CLane::AddPlayer( const std::string& sName )
{
    auto pPlayer = std::make_shared<CPlayer>( sName );
    vpPlayer.push_back( std::move( pPlayer ) );
    puUtil->Log( "Current amount of players: " + std::to_string( vpPlayer.size( ) ) );
}

void
CLane::Play( )
{
    bool bFinish = false;
    while ( !bFinish )
    {
        for ( auto& pPlayer : vpPlayer )
        {
            if ( pPlayer->GetGame( )->GetCurrentFrameNumber( ) < puUtil->GetMaxFrames( ) )
            {
                puUtil->Log(
                    pPlayer->GetName( ),
                    "Current Frame number: "
                        + std::to_string( pPlayer->GetGame( )->GetCurrentFrameNumber( ) ) );
                if ( pPlayer->GetGame( )->GetCurrentFrame( )->GetCurrentTrialNumber( )
                     == TRIAL_NUMBER::FIRST  )
                {
                    WaitForKick( puUtil->GetMaxItems( ) );

                    puUtil->Log( pPlayer->GetName( ), "1st trial amount of items: "
                                                          + std::to_string( m_uAmountOfItems ) );

                    pPlayer->GetGame( )->GetCurrentFrame( )->SetFirstTrialItems( m_uAmountOfItems );
                    pPlayer->GetGame( )->ModifyCurrentTrialNumber( );
                }

                if ( pPlayer->GetGame( )->GetRestOfItems( ) > 0 )
                {
                    if ( pPlayer->GetGame( )->GetCurrentFrame( )->GetCurrentTrialNumber( )
                         == TRIAL_NUMBER::SECOND )
                    {
                        // Log("2nd trial rest of items: " +
                        // std::to_string(pPlayer->GetGame()->GetRestOfItems()));

                        WaitForKick( pPlayer->GetGame( )->GetRestOfItems( ) );

                        puUtil->Log(
                            pPlayer->GetName( ),
                            "2nd trial amount of items: " + std::to_string( m_uAmountOfItems ) );

                        pPlayer->GetGame( )->GetCurrentFrame( )->SetSecondTrialItems(
                            m_uAmountOfItems );
                        pPlayer->GetGame( )->ModifyCurrentTrialNumber( );
                    }
                }
                else
                {
                    if ( !pPlayer->GetGame( )->GetCurrentFrame( )->Get10thFrame( ) )
                    {
                        pPlayer->GetGame( )->ModifyCurrentTrialNumber( );
                    }
                    else if ( pPlayer->GetGame( )->GetCurrentFrame( )->GetCurrentTrialNumber( )
                              == TRIAL_NUMBER::SECOND )
                    {
                        // Log("2nd trial rest of items: " +
                        // std::to_string(pPlayer->GetGame()->GetRestOfItems()));

                        WaitForKick( puUtil->GetMaxItems( ) );

                        puUtil->Log(
                            pPlayer->GetName( ),
                            "2nd trial amount of items: " + std::to_string( m_uAmountOfItems ) );

                        pPlayer->GetGame( )->GetCurrentFrame( )->SetSecondTrialItems(
                            m_uAmountOfItems );
                        pPlayer->GetGame( )->ModifyCurrentTrialNumber( );
                    }
                }

                if ( pPlayer->GetGame( )->GetCurrentFrame( )->GetCurrentTrialNumber( )
                     == TRIAL_NUMBER::THIRD )
                {
                    if ( pPlayer->GetGame( )->GetCurrentFrame( )->GetCurrentTrialNumber( )
                         != TRIAL_NUMBER::SECOND )
                    {
                        if ( pPlayer->GetGame( )->GetCurrentFrame( )->Get10thFrame( )
                             && pPlayer->GetGame( )->GetCurrentFrame( )->GetFirstTrialItems( )
                                    == puUtil->GetMaxItems( ) )
                        {
                            WaitForKick( pPlayer->GetGame( )->GetRestOfItems( ) );
                        }
                        else
                        {
                            WaitForKick( puUtil->GetMaxItems( ) );
                        }

                        puUtil->Log(
                            pPlayer->GetName( ),
                            "3rd trial amount of items: " + std::to_string( m_uAmountOfItems ) );

                        pPlayer->GetGame( )->GetCurrentFrame( )->SetFirstTrialItems(
                            m_uAmountOfItems );
                        pPlayer->GetGame( )->ModifyCurrentTrialNumber( );
                    }

                    pPlayer->GetGame( )->GameOver( );
                }

                puUtil->Log( pPlayer->GetName( ),
                             "Current frame flag: "
                                 + pPlayer->GetGame( )->GetCurrentFrame( )->GetFlagsToString( )
                                 + "\n\n" );
            }
        }

        for ( auto& pPlayer : vpPlayer )
        {
            if ( pPlayer->GetGame( )->GetCurrentFrame( )->Get10thFrame( ) )
            {
                puUtil->Log(
                    pPlayer->GetName( ),
                    "Total of the game: " + std::to_string( pPlayer->GetGame( )->GetTotal( ) ) );
                bFinish = true;
            }

            pPlayer->GetGame( )->IncCurrentFrame( );
        }
    }
}

void
CLane::WaitForKick( unsigned uCurrentAmountOfItems )
{
    std::uniform_int_distribution<> dis( 0, uCurrentAmountOfItems );
    m_uAmountOfItems = dis( rd );

    // std::cout << "Input amount of pins: ";
    // std::cin >> m_uAmountOfItems;
}

std::vector< std::shared_ptr< CPlayer > > CLane::getPlayersList() const
{
    return vpPlayer;
}

unsigned CLane::getAmountOfItems() const
{
    return m_uAmountOfItems;
}

unsigned CLane::getAmountOfPlayers() const
{
    return m_uAmountOfPlayers;
}
