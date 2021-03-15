#include "Test_Users.h"

void Test_Users::test_implicit_consructor() // TESTS
{
	Users u;
	assert(u.get_username().empty() == 1);
	assert(u.get_password().empty() == 1);
}

void Test_Users::test_constructor_with_parameters()
{
	Users u("paulhoabn67", "45443");
	assert(u.get_username() == "paulhoabn67");
	assert(u.get_password() == "45443");
}

void Test_Users::test_copy_constructor()
{
	Users u("paulhoabn67", "45443");
	Users uc(u);
	assert(uc.get_username() == u.get_username());
	assert(uc.get_password() == u.get_password());
}

void Test_Users::test_gets()
{
	Users u("paulhoabn67", "45443");
	assert(u.get_username() == "paulhoabn67");
	assert(u.get_password() == "45443");
}

void Test_Users::test_sets()
{
	Users u;
	u.set_username("ppp");
	u.set_password("56");
	assert(u.get_username() == "ppp");
	assert(u.get_password() == "56");
}

void Test_Users::test_assignment_operator()
{
	Users u("paulhoabn67", "45443");
	Users ue;
	ue = u;
	assert(u.get_username() == ue.get_username());
	assert(u.get_password() == ue.get_password());
}

void Test_Users::test_equality_operator()
{
	Users u("paulhoabn67", "45443");
	Users ue = u;;
	assert(ue == u);
}

void Test_Users::test_all()
{
	this->test_implicit_consructor();
	this->test_constructor_with_parameters();
	this->test_copy_constructor();
	this->test_assignment_operator();
	this->test_equality_operator();
	this->test_gets();
	this->test_sets();
}
