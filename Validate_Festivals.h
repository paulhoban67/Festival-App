#ifndef VALIDATE_FESTIVALS_H
#define VALIDATE_FESTIVALS_H


#include "Festival.h"
#include <exception>
#include <string>
using namespace std;

class Validate_Festivals
{
protected:
	int nr_errors;
	string message;
public:
	Validate_Festivals() { this->nr_errors = 0; };
	~Validate_Festivals() {};
	virtual int validate(Festival* f)
	{
		this->nr_errors = 0;
		if (f->get_date()[2] != f->get_date()[5])
			this->nr_errors++, this->message += "Format date incorrect; ";
		if (f->get_place() == " ")
			this->nr_errors++, this->message += "Place incorrect; ";
		if (f->get_number_free() < 0 || f->get_number_sold() < 0)
			this->nr_errors++, this->message += "Number orders wrong; ";
		return this->nr_errors;
	};
	string to_string_v() { return this->message; };
};

#endif // !VALIDATE_FESTIVALS_H