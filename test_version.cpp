#define BOOST_TEST_MODULE test_version

#include "lib.h"
#include "func.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    std::vector<std::vector<int>> arr = {{31}, {33}, {52}, {69}, {228}, {420}};
    BOOST_CHECK(LexiSort(arr[0], arr[1]));
    BOOST_CHECK(LexiSort(arr[2], arr[3]));
    BOOST_CHECK(LexiSort(arr[4], arr[5]));
}

BOOST_AUTO_TEST_SUITE_END()
