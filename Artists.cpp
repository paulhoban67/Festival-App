#include "Artists.h"

Artists::Artists() : Festival() // Artists este o clasa fiu pentru Festival
{

}

Artists::Artists(string name_artist, string date, string place, int number_free, int number_sold) : Festival(date,place,number_free,number_sold)
{
	
	this->name_artist = name_artist;
}

Artists::Artists(const Artists& a) : Festival(a)
{
	this->name_artist = a.name_artist;
}

Artists::~Artists()
{

}

Festival* Artists::clone()
{
	return new Artists(this->name_artist, this->date, this->place, this->number_free, this->number_sold);
}

string Artists::get_name_artist()
{
	return this->name_artist;
}

void Artists::set_name_artist(string new_name_arist)
{
	this->name_artist = new_name_arist;
}

Artists& Artists::operator=(const Artists& a) // definirea operatoului =
{
	this->name_artist = a.name_artist;
	Festival::operator=(a);
	return *this;
}

bool Artists::operator==(const Artists& a) // definirea operatoului ==
{
	return this->name_artist == a.name_artist && Festival::operator==(a);
}

bool Artists::operator!=(const Artists& a) // definirea operatoului !=
{
	return this->name_artist != a.name_artist && Festival::operator!=(a);
}

string Artists::to_string_festival(string delimitator) // toString pentru clasa Artists
{
	return "AR" + delimitator + this->name_artist + delimitator + Festival::to_string_festival(delimitator);
}