#define BOOST_TEST_MODULE testcases

#ifdef WIN32
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include "BracketClass.h"

BOOST_AUTO_TEST_SUITE (BracketsTest)

BOOST_AUTO_TEST_CASE(EmptyStringCase)
{
    std::string data;
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::OK);
}

BOOST_AUTO_TEST_CASE(NoBracketsStringCase)
{
    std::string data("abc");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::OK);
}

BOOST_AUTO_TEST_CASE(OnlyOpen1BracketStringCase)
{
    std::string data("{");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(OnlyOpen2BracketsStringCase)
{
    std::string data("{[");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(OnlyOpen3BracketsStringCase)
{
    std::string data("{[(");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(OnlyClose1BracketStringCase)
{
    std::string data("}");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(OnlyClose2BracketsStringCase)
{
    std::string data(")}");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(OnlyClose3BracketsStringCase)
{
    std::string data(")}]");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(Open3CorrectlyClose1BracketsWithExtraSymbolsStringCase)
{
    std::string data("{[(abc)");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(Open3IncorrectlyClose1BracketsWithExtraSymbolsStringCase)
{
    std::string data("{[(abc]");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(Open3CorrectlyClose2BracketsWithExtraSymbolsStringCase)
{
    std::string data("{[(abc)]");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(Open3CorrectlyClose3BracketsWithExtraSymbolsStringCase)
{
    std::string data("{[(abc)]}");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::OK);
}

BOOST_AUTO_TEST_CASE(CloseOpenTheSameBracketsWithExtraSymbolsStringCase)
{
    std::string data("}{");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(CloseOpenDifferentBracketsWithExtraSymbolsStringCase)
{
    std::string data("}(");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::INVALID_SEQUENCE);
}

BOOST_AUTO_TEST_CASE(Open3CorrectlyClose3BracketsWithExtraComplexSymbolsStringCase)
{
    std::string data("{sdfg[ rety(abc) ]fry }");
    Brackets test(std::move(data));
    BOOST_CHECK(test.checkData() == Brackets::Errors::OK);
}

BOOST_AUTO_TEST_SUITE_END()
