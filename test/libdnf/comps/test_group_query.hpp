/*
Copyright Contributors to the libdnf project.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef LIBDNF_TEST_COMPS_GROUP_QUERY_HPP
#define LIBDNF_TEST_COMPS_GROUP_QUERY_HPP

#include "base_test_case.hpp"

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>


class CompsGroupQueryTest : public BaseTestCase {
    CPPUNIT_TEST_SUITE(CompsGroupQueryTest);
    CPPUNIT_TEST(test_query_all);
    CPPUNIT_TEST(test_query_filter_groupid);
    CPPUNIT_TEST(test_query_filter_name);
    CPPUNIT_TEST(test_query_filter_uservisible);
    CPPUNIT_TEST(test_query_filter_default);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void test_query_all();
    void test_query_filter_groupid();
    void test_query_filter_name();
    void test_query_filter_uservisible();
    void test_query_filter_default();
};

#endif
