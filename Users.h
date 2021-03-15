#ifndef USERS_H
#define USERS_H

#include <iostream>
using namespace std;

class Users
{
private:
	string username;
	string password;
public:
	Users();
	Users(string username, string password);
	Users(const Users& u);
	~Users();

	string get_username();
	string get_password();
	void set_username(string username);
	void set_password(string password);

	Users& operator=(const Users& u);
	bool operator==(const Users& u);
	//string to_string_users(string delimitator);
	friend ostream& operator<<(ostream& os, const Users& u);
	friend istream& operator>>(istream& is, Users& u);
};

#endif // !USERS_H