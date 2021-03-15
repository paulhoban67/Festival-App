#include "Repo.h"

Repo::Repo() // clasa parinte Repo pentru Repo_txt si Repo_csv
{

}

Repo::Repo(string file_name)
{
	this->file_name = file_name;
}

Repo::~Repo()
{
	
}

void Repo::set_file_name(string new_file_name)
{
	this->file_name = new_file_name;
}

vector<Festival*> Repo::get_all()
{
	return this->festivals;
}

void Repo::add(Festival* festival) // adaugarea unui element 
{
	this->festivals.push_back(festival->clone());
	this->save_to_file();
}

void Repo::del(Festival* festival) // stergerea unui element din repo
{
	for (int i = 0; i < this->festivals.size(); i++)
	{
		if (**(this->festivals.begin() + i) == *festival)
		{
			delete this->festivals[i];
			this->festivals.erase(this->festivals.begin() + i);
			this->save_to_file();
			return;
		}
	}
}

void Repo::update(Festival* old_festival, Festival* new_festival) // modificarea unui element
{
	for (int i = 0; i < this->festivals.size(); i++)
	{
		if (*(this->get_festival(i)) == *old_festival)
		{
			delete this->festivals[i];
			this->festivals[i] = new_festival->clone();
			this->save_to_file();
			return;
		}
	}
}

int Repo::get_size()
{
	return this->festivals.size();
}

Festival* Repo::get_festival(int pos)
{
	if (pos >= 0 && pos < this->get_size())
	{
		return this->festivals[pos]->clone();
	}
	return new Festival();
}