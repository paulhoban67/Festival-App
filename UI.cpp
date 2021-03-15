#include "UI.h"
#include "Artists.h"
#include "Exceptions.h"

void UI::menu() // MENIURI
{
	cout << "1.Search events" << '\n';
	cout << "2.Buy Tickets" << '\n';
	cout << "3.Log out" << '\n' << '\n';
	cout << "               Setings" << '\n';
	cout << "               Info Account" << '\n';
}
void UI::menu1()
{
	cout << "1.Add artist" << '\n';
	cout << "2.Show artists" << '\n';
	cout << "3.Update artist" << '\n';
	cout << "4.Delete artist" << '\n';
	cout << "5.Back" << '\n';
}

void UI::menu2()
{
	cout << "1.Modify account\n";
	cout << "2.Delete account\n";
	cout << "3.Show accounts\n";
	cout << "4.Back\n" << '\n';
}

void UI::menu3()
{
	cout << "1.Arist\n";
	cout << "2.Film\n";
	cout << "3.Back\n";
}

void UI::menu4()
{
	cout << "LOGIN" << '\n';
	cout << "SIGN UP" << '\n';
	cout << "STOP" << '\n';
}

void UI::menu5()
{
	cout << "1.Add film" << '\n';
	cout << "2.Show films" << '\n';
	cout << "3.Update film" << '\n';
	cout << "4.Delete film" << '\n';
	cout << "5.Back" << '\n' << '\n';
}

void UI::add_artist() // CRUDURI Artists
{
	try
	{
		string name_artist;
		cout << "Name: ", cin >> name_artist;
		string date;
		cout << "Date: ", cin >> date;
		string place;
		cout << "Place: ", cin >> place;
		int number_free;
		cout << "Number Free: ", cin >> number_free;
		int number_sold;
		cout << "Number Sold: ", cin >> number_sold;
		this->service.add_artist(name_artist, date, place, number_free, number_sold);
	}
	catch (MyException ex)
	{
		cout << "ERROR: " << ex.what() << endl;
	}
}

void UI::update_artist()
{
	try
	{
		int pos;
		cout << "Position: ", cin >> pos;
		string new_name_artist;
		cout << "NEW Name: ", cin >> new_name_artist;
		string new_date;
		cout << "NEW Date: ", cin >> new_date;
		string new_place;
		cout << "NEW Place: ", cin >> new_place;
		int new_number_free;
		cout << "NEW Number Free: ", cin >> new_number_free;
		int new_number_sold;
		cout << "NEW Number Sold: ", cin >> new_number_sold;
		this->service.update_artist(pos, new_name_artist, new_date, new_place, new_number_free, new_number_sold);
	}
	catch (MyException ex)
	{
		cout << "ERROR: " << ex.what() << endl;
	}
}

void UI::del_artist()
{
	try
	{
		int pos;
		cout << "Position: ", cin >> pos;
		this->service.delete_artist(pos);
		cout << "S-a sters artistul de pe pozitia " << pos;
	}
	catch (MyException ex)
	{
		cout << "ERROR: " << ex.what() << endl;
	}
}

void UI::show_artist()
{
	vector <Festival*> f = this->service.show_artists();
	int size = f.size();
	for (int i = 0; i < size; i++)
	{
		cout << f[i]->to_string_festival(" ") << "\n";
	}
}

void UI::add_film() //CRUDURI Films
{
	string name_film;
	cout << "Name: ", cin >> name_film;
	string list_actors;
	cout << "List Actors: ", cin >> list_actors;
	string date;
	cout << "Date: ", cin >> date;
	string place;
	cout << "Place: ", cin >> place;
	int number_free;
	cout << "Number Free: ", cin >> number_free;
	int number_sold;
	cout << "Number Sold: ", cin >> number_sold;
	this->service.add_film(name_film, list_actors, date, place, number_free, number_sold);
}

void UI::update_film()
{
	int pos;
	cout << "Position: ", cin >> pos;
	string new_name_artist;
	cout << "NEW Name Film: ", cin >> new_name_artist;
	string new_list_actors;
	cout << "NEW List Actors: ", cin >> new_list_actors;
	string new_date;
	cout << "NEW Date: ", cin >> new_date;
	string new_place;
	cout << "NEW Place: ", cin >> new_place;
	int new_number_free;
	cout << "NEW Number Free: ", cin >> new_number_free;
	int new_number_sold;
	cout << "NEW Number Sold: ", cin >> new_number_sold;
	this->service.update_film(pos, new_name_artist, new_list_actors, new_date, new_place, new_number_free, new_number_sold);
}

void UI::del_film()
{
	int pos;
	cout << "Position: ", cin >> pos;
	this->service.delete_film(pos);
	cout << "S-a sters filmul de pe pozitia " << pos;
}

void UI::show_film()
{
	vector <Festival*> f = this->service.show_films();
	int size = f.size();
	for (int i = 0; i < size; i++)
	{
		cout << f[i]->to_string_festival(" ") << "\n";
	}
}

void UI::add_user() // CRUDURI Users
{
	string username;
	cout << "Username: ", cin >> username;
	string password;
	cout << "Password: ", cin >> password;
	this->service.add_user(username, password);
}

void UI::update_user()
{
	try {
		int pos;
		cout << "Position: ", cin >> pos;
		string username;
		cout << "Username: ", cin >> username;
		string password;
		cout << "Password: ", cin >> password;
		this->service.update_user(pos, username, password);
	}
	catch (MyException ex)
	{
		cout << "ERROR: " << ex.what() << endl;
	}
}

void UI::del_user()
{
	try {
		int pos;
		cout << "Position: ", cin >> pos;
		this->service.delete_user(pos);
	}
	catch (MyException ex)
	{
		cout << "ERROR: " << ex.what() << endl;
	}
}

void UI::show_users()
{
	vector <Users> u = this->service.show_users();
	for (int i = 0; i < u.size(); i++)
	{
		cout << u[i];
	}
}

void UI::login() // logarea utilizatorilor
{
	try
	{
		while (true)
		{
			string username;
			cout << "USERNAME: ", cin >> username;
			if (service.verify_username(username) == 1)
			{
				string password;
				cout << "PASSWORD: ", cin >> password;
				if (service.verify_password(password) == 1)
					if (service.login(username, password) == 1)
					{
						cout << "LOGAT" << "\n";
						break;
					}
			}
		}
	}
	catch (MyException e)
	{
		cout << "ERROR: " << e.what() << endl;
		login();
	}
}

void UI::buy() // cumpararea biletelor la film sau concert
{
	while (true)
	{
		menu3();
		string name;
		int number, opt = 0, pos;
		cout << "Option: ", cin >> opt;
		if (opt == 1)
		{
			this->show_artist();
			cout << "\nPOSITION: ", cin >> pos;
			cout << "NAME: ", cin >> name;
			cout << "NUMBER: ", cin >> number;
			service.buy_ticket_artist(pos, number);
		}
		else
			if (opt == 2)
			{
				this->show_film();
				cout << "\nPOSITION: ", cin >> pos;
				cout << "NAME: ", cin >> name;
				cout << "NUMBER: ", cin >> number;
				service.buy_ticket_film(pos, number);
			}
			else
				if (opt == 3)
					break;
	}	
}

void UI::show_day() // Afisarea filmelor si artistilor care au concert intr-o zi
{
	while (true)
	{
		menu3();
		int opt = 0, day;
		cout << "Option: ", cin >> opt;
		if (opt == 1)
		{
			cout << "DAY: ", cin >> day;
			vector <Festival*> a = this->service.show_day_artists(day);
			int size = a.size();
			for (int i = 0; i < size; i++)
			{
				cout << a[i]->to_string_festival(" ") << "\n";
			}
		}
		else
			if (opt == 2)
			{
				cout << "DAY: ", cin >> day;
				vector <Festival*> f = this->service.show_day_films(day);
				int size = f.size();
				for (int i = 0; i < size; i++)
				{
					cout << f[i]->to_string_festival(" ") << "\n";
				}
			}
			else
				if (opt == 3)
					break;
	}	
}

UI::UI()
{

}

UI::UI(Service& service)
{
	this->service = service;
}

void UI::run()
{
	while (true)
	{
		menu4();
		string o;
		cout << "OPTION: ", cin >> o;
		if (o == "LOGIN")
		{
			this->login();
			while (true)
			{
				menu();
				string option;
				cout << "Option: ", cin >> option;
				if (option == "1")
					this->show_day();
				if (option == "2")
					this->buy();
				if (option == "3")
					break;

				if (option == "Setings")
					while (true)
					{
						this->menu3();
						int option;
						cout << "Option: ", cin >> option;
						if (option == 1)
						{
							while (true)
							{
								this->menu1();
								int opt;
								cout << "Option: ", cin >> opt;
								if (opt == 1)
									this->add_artist();
								if (opt == 2)
									this->show_artist();
								if (opt == 3)
									this->update_artist();
								if (opt == 4)
									this->del_artist();
								if (opt == 5)
									break;
							}
						}
						else
							if (option == 2)
							{
								while (true)
								{
									this->menu5();
									int opt;
									cout << "Option: ", cin >> opt;
									if (opt == 1)
										this->add_film();
									if (opt == 2)
										this->show_film();
									if (opt == 3)
										this->update_film();
									if (opt == 4)
										this->del_film();
									if (opt == 5)
										break;
								}
							}
							else
								if (option == 3)
									break;
					}
				if (option == "Account")
					while (true)
					{
						this->menu2();
						int opt;
						cout << "Option: ", cin >> opt;
						if (opt == 1)
							this->update_user();
						if (opt == 2)
							this->del_user();
						if (opt == 3)
							this->show_users();
						if (opt == 4)
							break;
					}
			}
		}
		else
			if (o == "SIGN UP")
				this->add_user();
			else
				if (o == "STOP")
					break;
	}

}