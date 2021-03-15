#include "Test_Service.h"


void Test_Service::test_add() // TESTS
{
	Service_Artists service_artists(Repo& repo);
	string name_artist = "Paul", date = "12/02/2020", place = "Cluj-Napoca";
	int number_free = 200, number_sold = 100;
	Artists* a = new Artists(name_artist, date, place, number_free, number_sold);
	this->service_artists.add_artists_txt(name_artist, date, place, number_free, number_sold);
	string username = "paulhoban67", password = "2000";
	Users u(username, password);
	this->service_users.add_user(username, password);
	assert(this->service_artists.get_artist_txt(1)->to_string_festival(" ") == a->to_string_festival(" "));
	assert(this->service_users.show_users()[0] == u);
	delete a;
}

void Test_Service::test_update()
{
	Service_Artists service_artists(Repo & repo);
	string name_artist = "Paul", date = "12/02/2020", place = "Cluj-Napoca", name_artist1 = "Adriana", date1 = "12/02/2020", place1 = "Baia-Mare";
	int number_free = 200, number_sold = 100, number_free1 = 33, number_sold1 = 22;
	Artists* a1 = new Artists(name_artist1, date1, place1, number_free1, number_sold1);
	this->service_artists.add_artists_txt(name_artist, date, place, number_free, number_sold);
	this->service_artists.add_artists_txt(name_artist1, date1, place1, number_free1, number_sold1);
	this->service_artists.update_artists_txt(1, name_artist1, date1, place1, number_free1, number_sold1);
	string username = "paulhoban67", password = "2000", username1 = "dd", password1 = "45";
	Users u(username1, password1);
	this->service_users.add_user(username, password);
	this->service_users.add_user(username1, password1);
	this->service_users.update_user(1, username1, password1);
	assert(this->service_artists.get_artist_txt(1)->to_string_festival(" ") == a1->to_string_festival(" "));
	assert(this->service_users.show_users()[0] == u);
	delete a1;
}

void Test_Service::test_show()
{
	Service_Artists service_artists(Repo & repo);
	string name_artist = "Andrei", date = "12/02/2020", place = "Cluj-Napoca";
	int number_free = 200, number_sold = 100;
	Artists* a3 = new Artists(name_artist, date, place, number_free, number_sold);
	this->service_artists.add_artists_txt(name_artist, date, place, number_free, number_sold);
	string username = "paulhoban67", password = "2000";
	Users u(username, password);
	this->service_users.add_user(username, password);
	assert(this->service_artists.get_artist_txt(4)->to_string_festival(" ") == a3->to_string_festival(" "));
	assert(this->service_users.show_users()[1] == u);
	delete a3;
}

void Test_Service::test_delete()
{
	Service_Artists service_artists(Repo & repo);
	string name_artist = "Paul", date = "12/02/2020", place = "Cluj-Napoca";
	int number_free = 200, number_sold = 100;
	Artists* a = new Artists(name_artist, date, place, number_free, number_sold);
	this->service_artists.add_artists_txt(name_artist, date, place, number_free, number_sold);
	this->service_artists.delete_artists_txt(5);
	string username = "paulhoban67", password = "2000";
	Users u(username, password);
	this->service_users.add_user(username, password);
	this->service_users.delete_user(5);
	assert(this->service_artists.show_txt().size() == 4);
	assert(this->service_users.show_users().size() == 4);
}

void Test_Service::test_verify_username()
{
	string username = "paulhoban67", password = "2000", username1 = "adriana", password1 = "344";
	Users u(username, password);
	Users u1(username1, password1);
	this->service_users.add_user(username1, password1);
	this->service_users.add_user(username1, password1);
	assert(this->service_users.verify_username(username) == 1);
	assert(this->service_users.verify_username(username1) == 1);
}

void Test_Service::test_verify_password()
{
	string username = "paulhoban67", password = "2000", username1 = "adriana", password1 = "344";
	Users u(username, password);
	Users u1(username1, password1);
	this->service_users.add_user(username1, password1);
	this->service_users.add_user(username1, password1);
	assert(this->service_users.verify_user(password) == 1);
	assert(this->service_users.verify_user(password) == 1);
}

Test_Service::Test_Service()
{

}

void Test_Service::test_all()
{
	this->test_add();
	this->test_update();
	this->test_show();
	this->test_delete();
	this->test_verify_password();
	this->test_verify_username();
}
