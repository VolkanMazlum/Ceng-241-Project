#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "person.h"
#include "Date.h"
#include "Discount.h"
#include "admin.h"
#include "ticket.h"


using namespace std;

const string password = "admin123";
const string admin_name = "admin";

int findUser(Person people[], string user_name, string user_surname, int lenght, string password);                        //for find index of obejct
void my_cancel_method(Person &person);                                                                                   //to achieve cancel method in class person  with dynamic binding
void my_calculate_method(Person &person);                                                                               //to achiece calculate method in class person with dynamic binding
void my_cancel_ticket_price(Person &person);                                                                           //to achiece calculate method in class person with dynamic binding
bool setInformation(Adult adult[], Student student[], Sehit sehit[], Gazi gazi[], Disability disability[]);           //to converst hard way to easiest way for setting information

static int c_gazi = 0;                                        //to take how many number gazi or other object we have
static int c_sehit = 0;
static int c_student = 0;
static int c_adult = 0;
static int c_disability = 0;

static int number_ticket = 0;                             //to count number of ticket our system sold

int main() {

	int choice = 0;

	string pass, name;
	Person person;

	Disability *disability = new Disability[50];
	Adult *adult = new Adult [50];
	Student *student = new Student[50];
	Gazi *gazi = new Gazi[50];
	Sehit *sehit = new Sehit[50];                     //Sehit yakini

	// current date/time based on current system
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm,&now);
	// print various components of tm structure.
	person.date->set_year(1900 + ltm.tm_year);    
	person.date->set_month(1 + ltm.tm_mon);
	person.date->set_day(ltm.tm_mday);

	cout << "-------Reservation System-------" << endl;
	cout << "1-Admin Mode" << endl << "2-User Mode" << endl
		<< "3- Reservation " << endl << "4-Cancel " << endl
		<< "5-Display" << endl << "6-Buy" << endl << "7-Exit" << endl;
	cin >> choice;
	while (choice != 7 && person.date->work_time()) {      //if day is sunday , you can not open system.

		switch (choice) {
		case 1: {
			admin admin;
			cout << "Enter your name: ";
			cin >> name;
			cout << "Enter your password: ";
			cin >> pass;
			if (admin_name == name && password == pass) {                                //to control admin password and name are similar or not
				
				int option=0;
			
				do {
					switch (option) {                                
					case 1: {
						for (int i = 0; i < 50; i++) {
							
							if (disability[i].getUsername() != "Unknown") {                                      //for not writing unknown name ,surname, just write user's name,surname

								display(disability[i]);
								
							}
							if (adult[i].getUsername() != "Unknown") {                                      //for not writing unknown name ,surname, just write user's name,surname
								display(adult[i]);
								
							}
							if (student[i].getUsername() != "Unknown") {                                      //for not writing unknown name ,surname, just write user's name,surname
								display(student[i]);
								
							}
							if (gazi[i].getUsername() != "Unknown") {                                      //for not writing unknown name ,surname, just write user's name,surname
								display(gazi[i]);
								
							}
							if (sehit[i].getUsername() != "Unknown") {                                        //for not writing unknown name ,surname, just write user's name,surname
								display(sehit[i]);
							}
							
						}
						cout <<endl << "Total Price our company have is : " << person.getTotalPrice() << endl;            //for showing total price
						break;
					}
					case 2: {
						cout << "There are " << number_ticket << " number of ticket own company sold. " << endl;         //for showing number of tkicket are sold
						break;
					}
					case 3:
					{
						setInformation(adult, student, sehit, gazi, disability);
						break;
					}
					case 4: {
						string user_name, user_surname, password;
						cout << "Enter name, surname and password you want to delete: ";
						cin >> user_name >> user_surname >> password;
						cout << "Choose option" << endl << "1-Adult" << "2-Student" << "3-Gazi " << "4-Sehit" << "5-Disability" << endl;
						int opt;
						cin >> opt;
						if (opt == 1) {

							int index = findUser(adult, user_name, user_surname, c_adult, password);
							if (index != -1) {
								if(adult[index].date->discount_user.get_value()>0){
									my_cancel_ticket_price(adult[index]);
								}
								
								if (adult[index].ticket->buy_train_choice > 0) {
									adult[index].ticket->seat_num[adult[index].ticket->buy_train_choice - 1][adult[index].ticket->buy_seat_choice - 1] = 0;
									adult[index].ticket->buy_seat_choice = 0;                              //for deleting ticket user took
									adult[index].ticket->buy_train_choice = 0;
									number_ticket--;                                                     //for decreasing number of tickets are sold
								}

								adult[index].setSurname("Unknown");                                     //to delete user's account
								adult[index].setPassword("Unknown");
								adult[index].setUsername("Unknown");



							}
							else
								cout << "Password or username should be wrong." << endl;
						}
						else if (opt == 2) {
							int index = findUser(student, user_name, user_surname, c_student, password);
							if (index != -1) {
								if (student[index].date->discount_user.get_value() > 0) {
									my_cancel_ticket_price(student[index]);
								}

								
								if (student[index].ticket->buy_train_choice > 0) {
									student[index].ticket->seat_num[student[index].ticket->buy_train_choice - 1][student[index].ticket->buy_seat_choice - 1] = 0;
									student[index].ticket->buy_seat_choice = 0;                              //for deleting ticket user took
									student[index].ticket->buy_train_choice = 0;
									number_ticket--;                                                          //for decreasing number of tickets are sold
								}

								student[index].setSurname("Unknown");                              //to delete user's account
								student[index].setPassword("Unknown");
								student[index].setUsername("Unknown");


							}
							else
								cout << "Password or username should be wrong." << endl;
						}
						else if (opt == 3) {
							int index = findUser(gazi, user_name, user_surname, c_gazi, password);
							if (index != -1) {
								if (gazi[index].date->discount_user.get_value() > 0) {
									my_cancel_ticket_price(gazi[index]);
								}

								
								if (gazi[index].ticket->buy_train_choice > 0) {
									gazi[index].ticket->seat_num[gazi[index].ticket->buy_train_choice - 1][gazi[index].ticket->buy_seat_choice - 1] = 0;
									gazi[index].ticket->buy_seat_choice = 0;                              //for deleting ticket user took
									gazi[index].ticket->buy_train_choice = 0;
									number_ticket--;                                                    //for decreasing number of tickets are sold
								}

								gazi[index].setSurname("Unknown");                                       //to delete user's account
								gazi[index].setPassword("Unknown");
								gazi[index].setUsername("Unknown");

							}
							else
								cout << "Password or username should be wrong." << endl;
						}
						else if (opt == 4) {
							int index = findUser(sehit, user_name, user_surname, c_sehit, password);
							if (index != -1) {
								if (sehit[index].date->discount_user.get_value() > 0) {
									my_cancel_ticket_price(sehit[index]);
								}

								if (sehit[index].ticket->buy_train_choice > 0) {
									sehit[index].ticket->seat_num[sehit[index].ticket->buy_train_choice - 1][sehit[index].ticket->buy_seat_choice - 1] = 0;
									sehit[index].ticket->buy_seat_choice = 0;                                  //for deleting ticket user took
									sehit[index].ticket->buy_train_choice = 0;
									number_ticket--;                                                          //for decreasing number of tickets are sold
								}

								sehit[index].setSurname("Unknown");                                         //to delete user's account
								sehit[index].setPassword("Unknown");
								sehit[index].setUsername("Unknown");


							}
							else
								cout << "Password or username should be wrong." << endl;
						}
						else if (opt == 5) {
							int index = findUser(disability, user_name, user_surname, c_disability, password);
							if (index != -1) {
								if (disability[index].date->discount_user.get_value() > 0) {
									my_cancel_ticket_price(disability[index]);
								}

								if (disability[index].ticket->buy_train_choice > 0) {
									disability[index].ticket->seat_num[disability[index].ticket->buy_train_choice - 1][disability[index].ticket->buy_seat_choice - 1] = 0;
									disability[index].ticket->buy_seat_choice = 0;                              //for deleting ticket user took
									disability[index].ticket->buy_train_choice = 0;
									number_ticket--;                                                          //for decreasing number of tickets are sold
								}

								disability[index].setSurname("Unknown");                                    //to delete user's account
								disability[index].setPassword("Unknown");
								disability[index].setUsername("Unknown");

							}
							else
								cout << "Password or username should be wrong." << endl;
						}
						else
							cout << "Wrong choice" << endl;
						break;
					}
					default:
						break;
					   
					}
					cout << "-----------Admin------------" << endl;
					cout << "1-Display" << endl << "2-Show Number of Tickets are Bought" << endl << "3-Add" << endl << "4-Delete" << endl << "5-Exit" << endl;					
					cin >> option;
				}while (option != 5);
			}
			break;
		}

		case 2: {
			bool control = setInformation(adult , student , sehit , gazi , disability);                       //it is a choice that user can open a new account for own-self
			if (control) {
				cout << "Setting information is successful." << endl;
			}
			else 
				cout << "Setting information is not successful." << endl;
			break;
		}

		case 3: {
			string user_name, password, user_surname;
			cout << "Please enter your name, surname and password" << endl;
			cin >> user_name >> user_surname >> password;
			cout << "Choose option" << endl << "1-Adult" << "2-Student" << "3-Gazi " << "4-Sehit" << "5-Disability" << endl;
			int opt;
			cin >> opt;

			if (opt == 1) {
				for (int i = 0; i < c_adult; i++) {
					while (true) {
						if (adult[i].getUsername() == user_name && adult[i].getPassword() == password && adult[i].getSurname() == user_surname) { // for controlling name , surname are same or not

							adult[i].ticket->reserve();                                      //if there is a person like that, he or she can reserve ticket which one wants
							break;

						}
						else {
							cout << "Password or name can be wrong. Please check again." << endl;
						}

						cout << "Please enter your name, surname and password" << endl;
						cin >> user_name >> user_surname >> password;
					}
				}
			}
			else if (opt == 2) {
				for (int i = 0; i < c_student; i++) {
					while (true) {
						if (student[i].getUsername() == user_name && student[i].getPassword() == password && student[i].getSurname() == user_surname) {  // for controlling name , surname are same or not

						    student[i].ticket->reserve();                              //if there is a person like that, he or she can reserve ticket which one wants
							break;
						}
						else {
							cout << "Password or name can be wrong. Please check again." << endl;
						}

						cout << "Please enter your name, surname and password" << endl;
						cin >> user_name >> user_surname >> password;

					}
				}
			}
			else if (opt == 3) {
				for (int i = 0; i < c_gazi; i++) {
					while (true) {
						if (gazi[i].getUsername() == user_name && gazi[i].getPassword() == password && gazi[i].getSurname() == user_surname) {  // for controlling name , surname are same or not

							gazi[i].ticket->reserve();                          //if there is a person like that, he or she can reserve ticket which one wants
							break;
						}
						else {
							cout << "Password or name can be wrong. Please check again." << endl;
						}

						cout << "Please enter your name, surname and password" << endl;
						cin >> user_name >> user_surname >> password;
						break;

					}
				}
			}
			else if (opt == 4) {

				for (int i = 0; i < c_sehit; i++) {
					while (true) {
						if (sehit[i].getUsername() == user_name && sehit[i].getPassword() == password && sehit[i].getSurname() == user_surname) {   // for controlling name , surname are same or not

							sehit[i].ticket->reserve();                     //if there is a person like that, he or she can reserve ticket which one wants
							break;		
						}
						else {
							cout << "Password or name can be wrong. Please check again." << endl;
						}

						cout << "Please enter your name, surname and password" << endl;
						cin >> user_name >> user_surname >> password;
					}
				}
			}
			else if (opt == 5) {
				for (int i = 0; i < c_disability; i++)
					while (true) {
						if (disability[i].getUsername() == user_name && disability[i].getPassword() == password && disability[i].getSurname() == user_surname) {  // for controlling name , surname are same or not

							disability[i].ticket->reserve();         //if there is a person like that, he or she can reserve ticket which one wants
							break;
						}
						else {
							cout << "Password or name can be wrong. Please check again." << endl;
						}

						cout << "Please enter your name, surname and password" << endl;
						cin >> user_name >> user_surname >> password;

					}
			}

			else {
				cout << "Wrong choice" << endl;
			}

			break;
		}

		case 4: {
			string user_name, password, user_surname;
			cout << "Please enter your name ,surname and password" << endl;
			cin >> user_name >> user_surname >> password;
			cout << "Choose option" << endl << "1-Adult" << "2-Student" << "3-Gazi " << "4-Sehit" << "5-Disability" << endl;
			int opt;
			cin >> opt;
			if (opt == 1) {

				int index = findUser(adult, user_name, user_surname, c_adult, password);

				if (index != -1) {

					if (adult[index].ticket->seat_num[adult[index].ticket->buy_train_choice - 1][adult[index].ticket->buy_seat_choice - 1] == 5) {    //to control there is a ticket user bought or not
						my_cancel_ticket_price(adult[index]);                // to access method of decreasing total price, if there is a similar ticket
					}
					my_cancel_method(adult[index]);                     // to access method of cancellation
					number_ticket--;
				}

			}
			else if (opt == 2) {
				int index = findUser(student, user_name, user_surname, c_student, password);

				if (index != -1) {

					if (student[index].ticket->seat_num[student[index].ticket->buy_train_choice - 1][student[index].ticket->buy_seat_choice - 1] == 5)      //to control there is a ticket user bought or not
						my_cancel_ticket_price(student[index]);               // to access method of decreasing total price, if there is a similar ticket

					my_cancel_method(student[index]);                    // to access method of cancellation
					number_ticket--;
					

				}
			}
			else if (opt == 3) {
				int index = findUser(gazi, user_name, user_surname, c_gazi, password);
				if (index != -1) {

					if (gazi[index].ticket->seat_num[gazi[index].ticket->buy_train_choice - 1][gazi[index].ticket->buy_seat_choice - 1] == 5) {       //to control there is a ticket user bought or not
						my_cancel_ticket_price(gazi[index]);               // to access method of decreasing total price, if there is a similar ticket
					}

					my_cancel_method(gazi[index]);                     // to access method of cancellation
					number_ticket--;

				}
			}
			else if (opt == 4) {
					int index = findUser(sehit, user_name, user_surname, c_sehit, password);
					if (index != -1) {

						if (sehit[index].ticket->seat_num[sehit[index].ticket->buy_train_choice - 1][sehit[index].ticket->buy_seat_choice - 1] == 5) {       //to control there is a ticket user bought or not
							my_cancel_ticket_price(sehit[index]);               // to access method of decreasing total price, if there is a similar ticket
						}

						 my_cancel_method(sehit[index]);                     // to access method of cancellation
						 number_ticket--;
					}

			}
			else if (opt == 5) {
				int index = findUser(disability, user_name, user_surname, c_disability, password);

				if (index != -1) {

					if (disability[index].ticket->seat_num[disability[index].ticket->buy_train_choice - 1][disability[index].ticket->buy_seat_choice - 1] == 5) {        //to control there is a ticket user bought or not
						my_cancel_ticket_price(disability[index]);                // to access method of decreasing total price, if there is a similar ticket
					}
					my_cancel_method(disability[index]);                                                           // to access method of cancellation
					number_ticket--;
				}
				else
					cout << "Wrong choice" << endl;
				break;
			

			}
				break;
		}
		case 5: {
			person.ticket->display();
			break;

		}

		case 6: {

			string user_name, password, user_surname;
			cout << "Please enter your name ,surname and password" << endl;
			cin >> user_name >> user_surname >> password;
			cout << "Choose option" << endl << "1-Adult" << "2-Student" << "3-Gazi " << "4-Sehit" << "5-Disability" << endl;
			int opt;
			cin >> opt;
			if (opt == 1) {

				int index = findUser(adult, user_name, user_surname, c_adult, password);                        //to take index of user account
				if (index == -1) {                                                                              //to control index for there is a person or not, or password and username are wrong
					cout << "Password or something is wrong. Do you want to continue (1) or not (2): " ;
					int control;
					cin >> control;
					if (control == 1) {
						continue;
					}
					else
						break;
				}
				if (adult[index].ticket->buy_seat_choice > 0 && adult[index].ticket->buy_train_choice > 0) {
					cout << "There is a ticket you bought at previous time. Do you want to continue or cancel this ticket. (1-Continue 2-Cancel)" << endl;
					int ch;                            // if there is a ticket user bought previous time, our program say that, if user continue, he or she loose option for deleting first ticket
					cin >> ch;
					if (ch == 1) {
						cout << "You can buy another ticket, but you don't have any option for changing previous ticket." << endl;
					}
					else if (ch == 2) {
						choice = 4;
						continue;
					}
				}
					adult[index].ticket->buy_ticket();                  //to buy ticket
					my_calculate_method(adult[index]);            //to access method of calculating total price
					number_ticket++;
			}
			else if (opt == 2) {

				int index = findUser(student, user_name, user_surname, c_student, password);                      //to take index of user account
				if (index == -1) {                                                                        //to control index for there is a person or not, or password and username are wrong
					cout << "Password or something is wrong. Do you want to continue (1) or not (2): " ;
					int control;
					cin >> control;
					if (control == 1) {
						continue;
					}
					else
						break;
				}
				if (student[index].ticket->buy_seat_choice > 0 && student[index].ticket->buy_train_choice > 0) {
					cout << "There is a ticket you bought at previous time. Do you want to continue or cancel this ticket. (1-Continue 2-Cancel)" << endl;
					int ch;                            // if there is a ticket user bought previous time, our program say that, if user continue, he or she loose option for deleting first ticket
					cin >> ch;
					if (ch == 1) {
						cout << "You can buy another ticket, but you don't have any option for changing previous ticket." << endl;
					}
					else if (ch == 2) {
						choice = 4;
						continue;
					}
				}				
					student[index].ticket->buy_ticket();                  //to buy ticket
					my_calculate_method(student[index]);            //to access method of calculating total price
					number_ticket++;
			}
			else if (opt == 3) {
				int index = findUser(gazi, user_name, user_surname, c_gazi, password);                      //to take index of user account
				if (index == -1) {                                                                        //to control index for there is a person or not, or password and username are wrong
					cout << "Password or something is wrong. Do you want to continue (1) or not (2)";  //for option to continue or leave
					int control;
					cin >> control;
					if (control == 1) {
						continue;
					}
					else
						break;
				}
				if (gazi[index].ticket->buy_seat_choice > 0 && gazi[index].ticket->buy_train_choice > 0) {
					cout << "There is a ticket you bought at previous time. Do you want to continue or cancel this ticket. (1-Continue 2-Cancel)" << endl;
					int ch;                            // if there is a ticket user bought previous time, our program say that, if user continue, he or she loose option for deleting first ticket
					cin >> ch;
					if (ch == 1) {
						cout << "You can buy another ticket, but you don't have any option for changing previous ticket." << endl;
					}
					else if (ch == 2) {
						choice = 4;
						continue;
					}
				}
					gazi[index].ticket->buy_ticket();                  //to buy ticket
					my_calculate_method(gazi[index]);            //to access method of calculating total price
					number_ticket++;
			}
			else if (opt == 4) {

				int index = findUser(sehit, user_name, user_surname, c_sehit, password);                      //to take index of user account
				if (index == -1) {                                                                        //to control index for there is a person or not, or password and username are wrong
					cout << "Password or something is wrong. Do you want to continue (1) or not (2)";  //for option to continue or leave
					int control;
					cin >> control;
					if (control == 1) {
						continue;
					}
					else
						break;
				}
				if (sehit[index].ticket->buy_seat_choice > 0 && sehit[index].ticket->buy_train_choice > 0) {
					cout << "There is a ticket you bought at previous time. Do you want to continue or cancel this ticket. (1-Continue 2-Cancel)" << endl;
					int ch;                            // if there is a ticket user bought previous time, our program say that, if user continue, he or she loose option for deleting first ticket
					cin >> ch;
					if (ch == 1) {
						cout << "You can buy another ticket, but you don't have any option for changing previous ticket." << endl;
					}
					else if (ch == 2) {
						choice = 4;
						continue;
					}
				}
		
					sehit[index].ticket->buy_ticket();                  //to buy ticket
					my_calculate_method(sehit[index]);                 //to access method of calculating total price
					number_ticket++;
			}
			else if (opt == 5) {

				int index = findUser(disability, user_name, user_surname, c_disability, password);                      //to take index of user account
				if (index == -1) {                                                                                     //to control index for there is a person or not, or password and username are wrong
					cout << "Password or something is wrong. Do you want to continue (1) or not (2)";   //for option to continue or leave
					int control; 
					cin >> control;
					if (control == 1) {
						continue;
					}
					else
						break;
				}
				if (disability[index].ticket->buy_seat_choice > 0 && disability[index].ticket->buy_train_choice > 0) {
					cout << "There is a ticket you bought at previous time. Do you want to continue or cancel this ticket. (1-Continue 2-Cancel)" << endl;
					int ch;                            // if there is a ticket user bought previous time, our program say that, if user continue, he or she loose option for deleting first ticket
					cin >> ch;
					if (ch == 1) {
						cout << "You can buy another ticket, but you don't have any option for changing previous ticket." << endl;
					}
					else if (ch == 2) {
						choice = 4;
						continue;
					}
				}
					disability[index].ticket->buy_ticket();            //to buy ticket
					my_calculate_method(disability[index]);            //to access method of calculating total price
					number_ticket++;
			}
			else
				cout << "Wrong choice" << endl;
			break;
		}

		case 7:
		{
			cout << "GOODBYE!!" << endl;
			break;
		}

		default:
			cout << "Wrong choice! " << endl;
			break;

		}
		cout << "1-Admin Mode" << endl << "2-User Mode" << endl
			<< "3- Reservation " << endl << "4-Cancel " << endl
			<< "5-Display" << endl << "6-Buy" << endl << "7-Exit" << endl;
		cin >> choice;

		}

		ofstream MyFile("TrainReservationSystem.txt");
	
		try {
			if (MyFile.good())                                                                                       //for control file is opened or not.
				std::cout << "Writing file is successful" << endl;
			else
				throw 1;
			
			MyFile << setw(15) << "Surname" << setw(15) << "Name" << setw(15) << "Type"                            //for making table in file
				<< setw(20) << "Last Ticket" << setw(15) << endl;
			for (int i = 0; i < 50; i++) {

				if (disability[i].getUsername() != "Unknown") {                                                             //for not writing unknown name
					MyFile << setw(15) << disability[i].getSurname() << setw(15) << disability[i].getUsername() << setw(15) << "Disability " << i
						<< setw(15) << disability[i].ticket->buy_train_choice << " "<< disability[i].ticket->buy_seat_choice << setw(13) << endl;

				}
				if (adult[i].getUsername() != "Unknown") {
					MyFile << setw(15) << adult[i].getSurname() << setw(15) << adult[i].getUsername() << setw(15) << "Adult " << i
						<< setw(15) << adult[i].ticket->buy_train_choice << " " << adult[i].ticket->buy_seat_choice << setw(13) << endl;
				}

				if (student[i].getUsername() != "Unknown") {
					MyFile << setw(15) << student[i].getSurname() << setw(15) << student[i].getUsername() << setw(15) << "Student " << i
						<< setw(15)  << student[i].ticket->buy_train_choice << " " << student[i].ticket->buy_seat_choice << setw(13) << endl;
				}
				if (gazi[i].getUsername() != "Unknown") {
					MyFile << setw(15) << gazi[i].getSurname() << setw(15) << gazi[i].getUsername() << setw(15) << "Gazi " << i
						<< setw(15)  << gazi[i].ticket->buy_train_choice << " " << gazi[i].ticket->buy_seat_choice << setw(13) << endl;
				}
				if (sehit[i].getUsername() != "Unknown") {
					MyFile << setw(15) << sehit[i].getSurname() << setw(15) << sehit[i].getUsername() << setw(15) << "Sehit " << i
						<< setw(15) << sehit[i].ticket->buy_train_choice << " " << sehit[i].ticket->buy_seat_choice << setw(13) << endl;
				}
			}
			MyFile << "Total Ticket Price are Sold: " << person.getTotalPrice() << endl;
		}
		catch (int e) {
			cerr << "Failing opening or writing in files" << endl ;                 // to hold expception if there is a problem
		}
		
		
		delete [] student;                        //to delete pointer of array
		delete [] disability;
		delete [] adult;
		delete [] sehit;
		delete [] gazi;
		return 0;
}


void my_cancel_method(Person &person) {                                                  //dynamic binding and this is a method for accessing cancel method in  ticket class
	bool control = person.ticket->cancel_ticket();
	if (control) {
		cout << "The cancellation is successful. " << endl;
	}
	else
		cout << "The cancellation is not successful. " << endl;
}

void my_calculate_method(Person &person) {                                              //dynamic binding and this is a method for accessing calculate method in  person class
	person.calculate_total_price();
}

void my_cancel_ticket_price(Person &person) {                                    //dynamic binding and this is a method for accessing cancel ticket price method in  person class
	person.cancel_ticket_price();
}

int findUser(Person people[], string user_name, string user_surname, int lenght , string password) {               //dynamic binding, and find user's index in array by controlling username, password and surname
	for (int i = 0; i < lenght; i++) {
		while (true) {
			if (people[i].getUsername() == user_name && people[i].getPassword() == password && people[i].getSurname() == user_surname) {

				return i;
			}
			else {
				cout << "Password or name can be wrong. " << endl;	
				return -1;
			}	
		}
	}
	return -1;
}

bool setInformation(Adult adult[], Student student[], Sehit sehit[], Gazi gazi[], Disability disability[]) {       //to set information
	string user_name, password, user_surname;
	cout << endl <<"Please enter your name ,surname and password" << endl;
	cin >> user_name >> user_surname >> password;
	cout << "Choose option" << endl << "1-Adult" << "2-Student" << "3-Gazi " << "4-Sehit" << "5-Disability" << endl;
	int opt;
	cin >> opt;
	if (opt == 1) {
		adult[c_adult].setUsername(user_name);
		adult[c_adult].setSurname(user_surname);
		adult[c_adult].setPassword(password);
		c_adult++;
		return true;
	}
	else if (opt == 2) {
		student[c_student].setUsername(user_name);
		student[c_student].setSurname(user_surname);
		student[c_student].setPassword(password);
		c_student++;
		return true;
	}
	else if (opt == 3) {
		gazi[c_gazi].setUsername(user_name);
		gazi[c_gazi].setSurname(user_surname);
		gazi[c_gazi].setPassword(password);
		c_gazi++;
		return true;
	}
	else if (opt == 4) {
		sehit[c_sehit].setUsername(user_name);
		sehit[c_sehit].setSurname(user_surname);
		sehit[c_sehit].setPassword(password);
		c_sehit++;
		return true;
	}
	else if (opt == 5) {
		disability[c_disability].setUsername(user_name);
		disability[c_disability].setSurname(user_surname);
		disability[c_disability].setPassword(password);
		c_disability++;
		return true;
	}
	else {
		cout << "Wrong choice" << endl;
		return false;
	}

}