#define BOOST_TEST_MODULE ThreadSafePriorityQueue template testcases

#ifdef WIN32
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include <thread>
#include "ThreadsafePriorityQueue.hpp"
#include "TagData.h"

BOOST_AUTO_TEST_SUITE (ThreadSafePriorityQueueTemplateTest)

BOOST_AUTO_TEST_CASE(EmptyCheckCase)
{
    ThreadsafePriorityQueue<TDATA> data;
    BOOST_CHECK( data.empty() );
}

BOOST_AUTO_TEST_CASE(TryAddCheckCase)
{
    ThreadsafePriorityQueue<TDATA> data;
    data.push(TDATA {0, 1, 2, L""});
    BOOST_CHECK( !data.empty() );
}

BOOST_AUTO_TEST_CASE(TryDeleteFromEmptyCheckCase)
{
    TDATA item;
    ThreadsafePriorityQueue<TDATA> data;
    BOOST_CHECK( !data.try_pop(item) );
    BOOST_CHECK( data.empty() );
}

BOOST_AUTO_TEST_CASE(TryDeleteAndCheckDataFromEmptyCheckCase)
{
    ThreadsafePriorityQueue<TDATA> data;
    BOOST_CHECK( data.try_pop() == std::shared_ptr< TDATA >( ) );
    BOOST_CHECK( data.empty() );
}

BOOST_AUTO_TEST_CASE(TryAddAndDeleteCase)
{
    TDATA item {0, 1, 2, L""};
    ThreadsafePriorityQueue<TDATA> data;
    std::thread t1( [&data, &item] ()
    {
      data.push(item);
    });
    std::thread t2( [&data, &item] ()
    {
      data.wait_and_pop(item);
    });

    t1.join();
    t2.join();

    BOOST_CHECK( data.empty() );
}

BOOST_AUTO_TEST_CASE(TryAddAndDeleteWithCheckDataCase)
{
    TDATA item {0, 1, 2, L""};
    ThreadsafePriorityQueue<TDATA> data;
    std::thread t1( [&data, &item] ()
    {
      data.push(item);
    });
    std::thread t2( [&data, &item] ()
    {
      BOOST_CHECK (! (*data.wait_and_pop() > item));
    });

    t1.join();
    t2.join();

    BOOST_CHECK( data.empty() );
}

BOOST_AUTO_TEST_CASE(CheckSortingData1Case)
{
    TDATA item1 {1, 1, 2, L""};
    TDATA item2 {0, 1, 2, L""};
    ThreadsafePriorityQueue<TDATA> data;
    data.push(item1);
    data.push(item2);

    BOOST_CHECK( (*data.try_pop()).priority == 0);
    BOOST_CHECK( !data.empty() );
}

BOOST_AUTO_TEST_CASE(CheckSortingData2Case)
{
    TDATA item1 {1, 1, 2, L""};
    TDATA item2 {0, 1, 2, L""};
    TDATA retItem;
    ThreadsafePriorityQueue<TDATA> data;
    data.push(item1);
    data.push(item2);

    BOOST_CHECK( data.try_pop(retItem) );
    BOOST_CHECK( retItem.priority != item1.priority );
    BOOST_CHECK( retItem.priority == item2.priority );
    BOOST_CHECK( !data.empty() );
}

BOOST_AUTO_TEST_SUITE_END()
