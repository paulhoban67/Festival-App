#include "Repo_txt.h"
#include "Artists.h"
#include "Films.h"
#include <fstream>

Repo_Txt::Repo_Txt() : Repo()
{

}

Repo_Txt::Repo_Txt(string file_name) : Repo(file_name)
{
	this->load_to_file();
}

Repo_Txt::~Repo_Txt()
{

}

void Repo_Txt::load_to_file() // incarcarea datelor din fisierul txt
{
	ifstream f(this->file_name);
	if (f.is_open())
	{
		this->festivals.clear();
		string line;
		string delimitator = " ";
		while (getline(f, line))
		{
			if (line.substr(0, 2) == "FI")
			{
				line = line.erase(0, 3);

				int pos = line.find(delimitator);
				string name_film = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				string list_actors = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				string date = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				string place = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				int number_free = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				int number_sold = stoi(line.substr(0, pos));

				Films* f = new Films(name_film, list_actors, date, place, number_free, number_sold);
				this->festivals.push_back(f->clone());
				delete f;
			}
			else if (line.substr(0, 2) == "AR")
			{
				line = line.erase(0, 3);

				int pos = line.find(delimitator);
				string name_artist = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				string date = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				string place = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				int number_free = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delimitator);
				int number_sold = stoi(line.substr(0, pos));

				Artists* a = new Artists(name_artist, date, place, number_free, number_sold);
				this->festivals.push_back(a->clone());
				delete a;
			}
		}
		f.close();
	}
}

void Repo_Txt::save_to_file() // salvarea datelor in fisierul txt
{
	ofstream f(this->file_name);
	if (f.is_open())
	{
		for (Festival* elem : this->festivals)
		{
			f << elem->to_string_festival(" ") << endl;
		}
	}
}
