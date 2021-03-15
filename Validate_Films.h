#ifndef VALIDATE_FILMS_H
#define VALIDATE_FILMS_H


#include "Films.h"
#include "Validate_Festivals.h"

class Validate_Films : public Validate_Festivals
{
public:
	Validate_Films() : Validate_Festivals() {};
	~Validate_Films() {};
	int validate(Festival* fi)
	{
		Films* f = (Films*)fi;
		Validate_Festivals::validate(f);
		if (f->get_name_film() == " ")
			this->nr_errors++, this->message += "Name film incorrect; ";
		if (f->get_list_actors() == " ")
			this->nr_errors++, this->message += "Name film incorrect; ";
		return this->nr_errors;
	}
};

#endif // !VALIDATE_FILMS_H