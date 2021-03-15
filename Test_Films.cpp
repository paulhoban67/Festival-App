#include "Test_Films.h"

void Test_Films::test_implicit_consructor() // TESTS
{
	Films f;
	assert(f.get_name_film().empty() == 1);
	assert(f.get_number_free() == -1);
}

void Test_Films::test_constructor_with_parameters()
{
	Films f("Titanic", "LeonardoDiCaprio,KateWinslet,BillyZane", "12/02/2020", "Cluj-Napoca", 120, 56);
	assert(f.get_name_film() == "Titanic");
	assert(f.get_list_actors() == "LeonardoDiCaprio,KateWinslet,BillyZane");
	assert(f.get_number_free() == 120);
}

void Test_Films::test_copy_constructor()
{
	Films f("Titanic", "LeonardoDiCaprio,KateWinslet,BillyZane", "12/02/2020", "Cluj-Napoca", 120, 56);
	Films fi(f);
	assert(fi.get_name_film() == f.get_name_film());
	assert(fi.get_number_free() == f.get_number_free());
}

void Test_Films::test_clone()
{
	Films f("Titanic", "LeonardoDiCaprio,KateWinslet,BillyZane", "12/02/2020", "Cluj-Napoca", 120, 56);
	Films* fclone = (Films*)f.clone();
	assert(f == *fclone);
	assert(&f != fclone);
}

void Test_Films::test_gets()
{
	Films f("Titanic", "LeonardoDiCaprio,KateWinslet,BillyZane", "12/02/2020", "Cluj-Napoca", 120, 56);
	assert(f.get_name_film() == "Titanic");
	assert(f.get_list_actors() == "LeonardoDiCaprio,KateWinslet,BillyZane");
	assert(f.get_number_free() == 120);
}

void Test_Films::test_sets()
{
	Films f;
	f.set_name_film("Titanic");
	f.set_list_actors("LeonardoDiCaprio,KateWinslet,BillyZane");
	f.set_date("12/02/2020");
	f.set_place("Cluj-Napoca");
	f.set_number_free(120);
	f.set_number_sold(56);
	assert(f.get_name_film() == "Titanic");
	assert(f.get_list_actors() == "LeonardoDiCaprio,KateWinslet,BillyZane");
	assert(f.get_date() == "12/02/2020");
	assert(f.get_place() == "Cluj-Napoca");
	assert(f.get_number_free() == 120);
	assert(f.get_number_sold() == 56);
}

void Test_Films::test_assignment_operator()
{
	Films f1("Titanic", "LeonardoDiCaprio,KateWinslet,BillyZane", "12/02/2020", "Cluj-Napoca", 120, 56);
	Films f2;
	f2 = f1;
	assert(f1.get_name_film() == f2.get_name_film());
	assert(f1.get_list_actors() == f2.get_list_actors());
	assert(f1.get_number_free() == f2.get_number_free());
}

void Test_Films::test_equality_operator()
{
	Films f1("Titanic", "LeonardoDiCaprio,KateWinslet,BillyZane", "12/02/2020", "Cluj-Napoca", 120, 56);
	Films f2 = f1;
	assert(f2 == f1);
}

void Test_Films::test_to_string()
{
	Films f("Titanic", "LeonardoDiCaprio,KateWinslet,BillyZane", "12/02/2020", "Cluj-Napoca", 120, 56);
	assert(f.to_string_festival(" ") == "FI Titanic LeonardoDiCaprio,KateWinslet,BillyZane 12/02/2020 Cluj-Napoca 120 56");
	assert(f.to_string_festival(";") == "FI;Titanic;LeonardoDiCaprio,KateWinslet,BillyZane;12/02/2020;Cluj-Napoca;120;56");
}

void Test_Films::test_all()
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