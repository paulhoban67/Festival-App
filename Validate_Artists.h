#ifndef VALIDATE_ARTISTS_H
#define VALIDATE_ARTISTS_H


#include "Artists.h"
#include "Validate_Festivals.h"

class Validate_Artists : public Validate_Festivals
{
public:
	Validate_Artists() : Validate_Festivals() {};
	~Validate_Artists() {};
	int validate(Festival* ar)
	{
		Artists* a = (Artists*)ar;
		Validate_Festivals::validate(a);
		if (a->get_name_artist() == " ")
			this->nr_errors++, this->message += "Name incorrect; ";
		return this->nr_errors;
	}
};

#endif // !VALIDATE_ARTISTS_H