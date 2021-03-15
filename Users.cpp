#include "Users.h"
#include <iostream>
#include <string>
#include "vector"
#include <sstream>
using namespace std;

Users::Users() // clasa Users
{

}

Users::Users(string username, string password)
{
	this->username = username;
	this->password = password;
}

Users::Users(const Users& u)
{
	this->username = u.username;
	this->password = u.password;
}

Users::~Users()
{

}

string Users::get_username()
{
	return this->username;
}


string Users::get_password()
{
	return this->password;
}

void Users::set_username(string username)
{
	this->username = username;
}

void Users::set_password(string password)
{
	this->password = password;
}

Users& Users::operator=(const Users& u) // definirea operatorului =
{
	this->username = u.username;
	this->password = u.password;
	return *this;
}

bool Users::operator==(const Users& u) // definirea operatorui ==
{
	return this->username == u.username && this->password == u.password;
}

istream& operator>>(istream& is, Users& u) // definirea operatorului >>
{
	is >> u.username >> u.password;
	return is;
}

ostream& operator<<(ostream& os, const Users& u) // definirea operatorului <<
{
	os << u.username << " -> " << u.password << endl;
	return os;
}
