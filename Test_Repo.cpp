#include "Test_Repo.h"
#include "Repo_txt.h"
#include "Repo_csv.h"
#include "Films.h"
#include "Artists.h"
#include <assert.h>

void Test_Repo::test_get_size() // TESTS
{
	Repo* repo = new Repo_Txt();
	assert(repo->get_size() == 0);
	repo->add(new Festival());
	assert(repo->get_size() == 1);
}

void Test_Repo::test_get_all()
{
	Repo* repo = new Repo_Txt();
	Artists* ar = new Artists("CharliePuth", "15/07/2020", "Cluj-Napoca", 300, 200);
	Films* fi = new Films("Titanic", "LeonardoDiCaprio;KateWinslet", "16/07/2020", "Cluj-Napoca", 200, 150);
	repo->add(ar);
	repo->add(fi);
	vector<Festival*> festivals = repo->get_all();
	assert(*festivals[0] == *ar->clone());
	assert(*festivals[1] == *fi->clone());
}

void Test_Repo::test_get_festival()
{
	Repo* repo = new Repo_Txt();
	Artists* ar = new Artists("CharliePuth", "15/07/2020", "Cluj-Napoca", 300, 200);
	repo->add(ar);
	assert(*repo->get_festival(0) == *ar->clone());
	assert(*repo->get_festival(-1) == *(new Festival()));
	assert(*repo->get_festival(1) == *(new Festival()));
}

void Test_Repo::test_add()
{
	Repo* repo = new Repo_Txt();
	Artists* ar = new Artists("CharliePuth", "15/07/2020", "Cluj-Napoca", 300, 200);
	repo->add(ar);
	assert(*repo->get_festival(0) == *ar->clone());
}

void Test_Repo::test_update()
{
	Repo* repo = new Repo_Txt();
	Artists* ar1 = new Artists("CharliePuth", "15/07/2020", "Cluj-Napoca", 300, 200);
	repo->add(ar1);
	Artists* ar2 = new Artists("WizKhalifa", "17/07/2020", "Cluj-Napoca", 250, 180);
	Artists* ar3 = new Artists("LadyGaga", "18/07/2020", "Cluj-Napoca", 400, 350);
	repo->update(ar3, ar2);
	assert(*repo->get_festival(0) == *ar1);
	repo->update(ar1, ar2);
	assert(*repo->get_festival(0) == *ar2);
}

void Test_Repo::test_del()
{
	Repo* repo = new Repo_Txt();
	Artists* ar1 = new Artists("CharliePuth", "15/07/2020", "Cluj-Napoca", 300, 200);
	repo->add(ar1);
	Artists* ar2 = new Artists("WizKhalifa", "17/07/2020", "Cluj-Napoca", 250, 180);
	repo->del(ar2);
	assert(repo->get_size() == 1);
	assert(*repo->get_festival(0) == *ar1);
	repo->del(ar1);
	assert(repo->get_size() == 0);
}

void Test_Repo::test_load_from_file_txt()
{
	Repo* repo = new Repo_Txt(this->file_name_in_txt);
	repo->load_to_file();
	assert(repo->get_size() == this->festivals_in.size());
	assert(*repo->get_festival(0) == *this->festivals_in[0]);
	assert(*repo->get_festival(1) == *this->festivals_in[1]);
}

void Test_Repo::test_load_from_file_csv()
{
	Repo* repo = new Repo_Csv(this->file_name_in_csv);
	repo->load_to_file();
	assert(repo->get_size() == this->festivals_in.size());
	assert(*repo->get_festival(0) == *this->festivals_in[0]);
	assert(*repo->get_festival(1) == *this->festivals_in[1]);
}

void Test_Repo::test_save_to_file_txt()
{
	Repo* repo = new Repo_Txt(this->file_name_in_txt);
	//repo->load_to_file();
	repo->set_file_name(this->file_name_out_txt);
	Artists* new_ar = new Artists("LadyGaga", "18/07/2020", "Cluj-Napoca", 400, 350);
	repo->add(new_ar);
	repo->save_to_file();
	repo->load_to_file();
	assert(repo->get_size() == this->festivals_in.size() + 1);
	vector<Festival*> festivals = repo->get_all();
	for (int i = 0; i < repo->get_size() - 1; i++)
	{
		assert(*festivals[i] == *this->festivals_in[i]);
	}
	assert(*festivals[festivals.size() - 1] == *new_ar);
}

void Test_Repo::test_save_to_file_csv()
{
	Repo* repo = new Repo_Csv(this->file_name_in_csv);
	repo->load_to_file();
	repo->set_file_name(this->file_name_out_csv);
	Artists* new_ar = new Artists("LadyGaga", "18/07/2020", "Cluj-Napoca", 400, 350);
	repo->add(new_ar);
	repo->save_to_file();
	repo->load_to_file();
	assert(repo->get_size() == this->festivals_in.size() + 1);
	vector<Festival*> festivals = repo->get_all();
	for (int i = 0; i < repo->get_size() - 1; i++)
	{
		assert(*festivals[i] == *this->festivals_in[i]);
	}
	assert(*festivals[festivals.size() - 1] == *new_ar);
}

Test_Repo::Test_Repo()
{
	Artists* ar = new Artists("CharliePuth", "15/07/2020", "Cluj-Napoca", 300, 200);
	Films* fi = new Films("Titanic", "LeonardoDiCaprio;KateWinslet", "16/07/2020", "Cluj-Napoca", 200, 150);
	this->festivals_in.push_back(ar);
	this->festivals_in.push_back(fi);
}

Test_Repo::~Test_Repo()
{

}

void Test_Repo::test_all()
{
	this->test_get_size();
	this->test_get_all();
	this->test_get_festival();
	this->test_add();
	this->test_update();
	this->test_del();
	this->test_load_from_file_txt();
	this->test_load_from_file_csv();
	this->test_save_to_file_txt();
	this->test_save_to_file_csv();
}