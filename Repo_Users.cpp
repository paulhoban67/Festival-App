#include "Repo_Users.h"
#include <string>
using namespace std;
#include <fstream>

Repo_Users::Repo_Users()
{

}

Repo_Users::Repo_Users(string filename)
{
	this->filename = filename;
	this->load_to_file(); 
}

Repo_Users::Repo_Users(const Repo_Users& u)
{
	this->filename = u.filename;
}

Repo_Users::~Repo_Users()
{

}

Repo_Users& Repo_Users::operator=(const Repo_Users& u)
{
	this->load_to_file();
	this->filename = u.filename;
	return *this;
}

void Repo_Users::set_filename(string new_filename)
{
	this->filename = new_filename;
	this->load_to_file();
}

vector<Users> Repo_Users::get_all()
{
	return this->users;
}

void Repo_Users::add(Users users) // adaugarea unui utilizator
{
	this->users.push_back(users);
	this->save_to_file();
}

void Repo_Users::del(Users users) // stergerea unui utilizator
{
	typename vector<Users>::iterator it;
	it = find(this->users.begin(), this->users.end(), users);
	if (!(it == this->users.end()))
	{
		this->users.erase(it);
	}
	this->save_to_file();
}

void Repo_Users::update(Users old_users, Users new_users) // modificarea unui utilizator
{
	typename vector <Users>::iterator it;
	it = find(this->users.begin(), this->users.end(), old_users);
	if (!(it == this->users.end()))
	{
		*it = new_users;
	}
	this->save_to_file();
}

int Repo_Users::get_size()
{
	return this->users.size();
}

void Repo_Users::clear()
{
	this->users.clear();
}

Users Repo_Users::get_users(int pos)
{
	return this->users[pos - 1];
}

void Repo_Users::load_to_file() // incarcarea utilizatorilor din BD
{
	if (this->filename != " ")
	{
		string line;
		ifstream f("Users.txt");
		string delimitator = " ";
		while (getline(f,line))
		{
			int pos = line.find(delimitator);
			string username = line.substr(0, pos);
			line = line.erase(0, pos + 1);
			pos = line.find(delimitator);
			string password = line.substr(0, pos);
			Users user(username, password);
			this->users.push_back(user);
		}
		f.close();
	}
}

void Repo_Users::save_to_file() // salvarea utilizatorilor in BD
{
	if (this->filename != " ")
	{
		ofstream f(this->filename);
		int n = get_size();
		for (int i = 0; i < n; i++)
			f << this->users[i];
		f.close();
	}
}