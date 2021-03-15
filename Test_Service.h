#ifndef TEST_SERVICE_H
#define TEST_SERVICE_H

#include "Service_Artists.h"
#include "Service_Users.h"
#include <vector>
#include <cassert>

class Test_Service
{
private:
	Service_Artists service_artists;
	Service_Users service_users;

	void test_add();
	void test_update();
	void test_show();
	void test_delete();

	void test_verify_username();
	void test_verify_password();

public:
	Test_Service();
	void test_all();
};

#endif // !TEST_SERVICE_H