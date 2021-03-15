#ifndef TEST_USERS_H
#define TEST_USERS_H

#include "Users.h"
#include <cassert>

class Test_Users
{
private:
	void test_implicit_consructor();
	void test_constructor_with_parameters();
	void test_copy_constructor();
	void test_gets();
	void test_sets();
	void test_assignment_operator();
	void test_equality_operator();

public:
	void test_all();
};
#endif // !TESTS_ARTISTS_H
