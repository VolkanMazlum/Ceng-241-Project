#include "admin.h"
#include <iostream>
#include <string>

using namespace std;



admin::admin() : username{ " " }, password{ " " } {

}
void admin::setInfo(string username, string password) {
	this->username = username;
	this->password = password;
}
void admin::setUsername(string username) {
	this->username = username;
}
void admin::setPassword(string password) {
	this->password = password;
}
string admin::getUsername() {
	return this->username;
}
string admin::getPassword() {
	return this->password;
}

