#ifndef TEST_REPO_H
#define TEST_REPO_H

#include "Repo.h"

class Test_Repo
{
private:
	const string file_name_in_txt = "Test_Festival_In.txt";
	const string file_name_out_txt = "Test_Festival_Out.txt";
	const string file_name_in_csv = "Test_Festival_In.csv";
	const string file_name_out_csv = "Test_Festival_Out.csv";

	vector<Festival*>festivals_in;

	void test_get_size();
	void test_get_festival();

	void test_add();
	void test_update();
	void test_del();
	void test_get_all();

	void test_load_from_file_txt();
	void test_save_to_file_txt();
	void test_load_from_file_csv();
	void test_save_to_file_csv();
public:
	Test_Repo();
	~Test_Repo();
	void test_all();
};
#endif // !TEST_REPO_H