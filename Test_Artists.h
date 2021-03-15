#ifndef TESTS_ARTISTS_H
#define TESTS_ARTISTS_H

#include "Artists.h"
#include <cassert>

class Test_Artists
{
private:
	void test_implicit_consructor();
	void test_constructor_with_parameters();
	void test_copy_constructor();
	void test_clone();
	void test_gets();
	void test_sets();
	void test_assignment_operator();
	void test_equality_operator();
	void test_to_string();

public:
	void test_all();
};
#endif // !TESTS_ARTISTS_H
