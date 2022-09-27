#pragma once
#include <iostream>
#include "person.h"
using namespace std;


class admin :public Person
{
private:
	string username;
	string password;
public:
	admin();
	void setInfo(string username, string password);
	void setUsername(string username);
	void setPassword(string password);
	string getUsername();
	string getPassword();
};
