#include "Test_Festival.h"

void Test_Festival::test_implicit_consructor() // TESTS
{
	Festival f;
	assert(f.get_place().empty() == 1);
	assert(f.get_number_free() == -1);
}

void Test_Festival::test_constructor_with_parameters()
{
	Festival f("12/02/2020", "Cluj-Napoca", 120, 56);
	assert(f.get_date() == "12/02/2020");
	assert(f.get_number_free() == 120);
}

void Test_Festival::test_copy_constructor()
{
	Festival f("12/02/2020", "Cluj-Napoca", 120, 56);
	Festival fe(f);
	assert(fe.get_date() == f.get_date());
	assert(fe.get_number_free() == f.get_number_free());
}

void Test_Festival::test_clone()
{
	Festival f("12/02/2020", "Cluj-Napoca", 120, 56);
	Festival* fclone = f.clone();
	assert(f == *fclone);
	assert(&f != fclone);
}

void Test_Festival::test_gets()
{
	Festival f("12/02/2020", "Cluj-Napoca", 120, 56);
	assert(f.get_date() == "12/02/2020");
	assert(f.get_place() == "Cluj-Napoca");
	assert(f.get_number_free() == 120);
	assert(f.get_number_sold() == 56);
}

void Test_Festival::test_sets()
{
	Festival f;
	f.set_date("12/02/2020");
	f.set_place("Cluj-Napoca");
	f.set_number_free(120);
	f.set_number_sold(56);
	assert(f.get_date() == "12/02/2020");
	assert(f.get_place() == "Cluj-Napoca");
	assert(f.get_number_free() == 120);
	assert(f.get_number_sold() == 56);
}

void Test_Festival::test_assignment_operator()
{
	Festival f1("12/02/2020", "Cluj-Napoca", 120, 56);
	Festival f2;
	f2 = f1;
	assert(f1.get_date() == f2.get_date());
	assert(f1.get_number_free() == f2.get_number_free());
}

void Test_Festival::test_equality_operator()
{
	Festival f1("12/02/2020", "Cluj-Napoca", 120, 56);
	Festival f2 = f1;
	assert(f2 == f1);
}

void Test_Festival::test_to_string()
{
	Festival f("12/02/2020", "Cluj-Napoca", 120, 56);
	assert(f.to_string_festival(" ") == "12/02/2020 Cluj-Napoca 120 56");
	assert(f.to_string_festival(",") == "12/02/2020,Cluj-Napoca,120,56");
}

void Test_Festival::test_all()
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
