#include "Test_Artists.h"

void Test_Artists::test_implicit_consructor() // TESTS
{
	Artists a;
	assert(a.get_name_artist().empty() == 1);
	assert(a.get_number_free() == -1);
}

void Test_Artists::test_constructor_with_parameters()
{
	Artists a("Paul", "12/02/2020", "Cluj-Napoca", 120, 56);
	assert(a.get_name_artist() == "Paul");
	assert(a.get_number_free() == 120);
}

void Test_Artists::test_copy_constructor()
{
	Artists a("Paul", "12/02/2020", "Cluj-Napoca", 120, 56);
	Artists ar(a);
	assert(ar.get_name_artist() == a.get_name_artist());
	assert(ar.get_number_free() == a.get_number_free());
}

void Test_Artists::test_clone()
{
	Artists a("Paul", "12/02/2020", "Cluj-Napoca", 120, 56);
	Artists* aclone = (Artists*)a.clone();
	assert(a == *aclone);
	assert(&a != aclone);
}

void Test_Artists::test_gets()
{
	Artists a("Paul", "12/02/2020", "Cluj-Napoca", 120, 56);
	assert(a.get_name_artist() == "Paul");
	assert(a.get_number_free() == 120);
}

void Test_Artists::test_sets()
{
	Artists a;
	a.set_name_artist("Paul");
	a.set_date("12/02/2020");
	a.set_place("Cluj-Napoca");
	a.set_number_free(120);
	a.set_number_sold(56);
	assert(a.get_name_artist() == "Paul");
	assert(a.get_date() == "12/02/2020");
	assert(a.get_place() == "Cluj-Napoca");
	assert(a.get_number_free() == 120);
	assert(a.get_number_sold() == 56);
}

void Test_Artists::test_assignment_operator()
{
	Artists a1("Paul", "12/02/2020", "Cluj-Napoca", 120, 56);
	Artists a2;
	a2 = a1;
	assert(a1.get_name_artist() == a2.get_name_artist());
	assert(a1.get_number_free() == a2.get_number_free());
}

void Test_Artists::test_equality_operator()
{
	Artists a1("Paul", "12/02/2020", "Cluj-Napoca", 120, 56);
	Artists a2 = a1;
	assert(a2 == a1);
}

void Test_Artists::test_to_string()
{
	Artists a("Paul", "12/02/2020", "Cluj-Napoca", 120, 56);
	assert(a.to_string_festival(" ") == "AR Paul 12/02/2020 Cluj-Napoca 120 56");
	assert(a.to_string_festival(",") == "AR,Paul,12/02/2020,Cluj-Napoca,120,56");
}

void Test_Artists::test_all()
{
	this->test_implicit_consructor();
	this->test_constructor_with_parameters();
	this->test_copy_constructor();
	this->test_clone();
	this->test_gets();
	this->test_sets();
	this->test_assignment_operator();
	this->test_equality_operator();
	this->test_to_string();
}