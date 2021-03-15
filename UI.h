#pragma once
#include "Service.h"
#include <iostream>
using namespace std;

class UI
{
private:
    Service service;
    void menu();
    void menu1();
    void menu2();
    void menu3();
    void menu4();
    void menu5();

    void add_artist();
    void update_artist();
    void del_artist();
    void show_artist();

    void add_film();
    void update_film();
    void del_film();
    void show_film();

    void add_user();
    void update_user();
    void del_user();
    void show_users();

    void login();
    void buy();
    void show_day();

public:
    UI();
    UI(Service& service);
    void run();
};