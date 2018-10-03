#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>
#include<windows.h>

using namespace std;

struct Contact
{
	char fname[30];
	char sname[30];
	char address[150];
	char age[5];
	char phone[15];
};

const int EXT = 5;

void AddContact(Contact *&newcontact, int &size, int &count, Contact &NewContact);  //Add new contact
void DeleteContactNumber(Contact*& newcontact, int & count, int size, int number);	//Deleted contact to the sequence number
void DeleteContactName(Contact*& newcontact, int & count, int size, char * Name);	//Deleted contact to the name
void DeleteContactSname(Contact*& newcontact, int & count, int size, char * sName);	//Deleted contact to the surname
void ShowContact(Contact *ptr, int index);											//Show any number you want to print it
void ShowAll(Contact* arr, int count);												//Show all contact
void FindContactFromNumber(Contact *arr, int count, char * Number);					//Search contact from sequence number
void FindContactFromName(Contact *arr, int count, char * Name);						//Search contact from name
void FindContactFromSname(Contact *arr, int count, char * sName);					//Search contact from surname
void FindContactFromTo(Contact *arr, int count, char from, char to);				//Search contact from which is beetwen 2 alphabet 
bool EditContactNumber(Contact* arr, int &count, int number);						//Edit contact to the sequence number
void WriteFile(Contact *arr, int count, ofstream & ofile);							//To write data to file
void ReadFile(Contact *&newcontacts, int & size, int & count, ifstream & ifile);	//To read information from a file
int compareByName(const void *v1, const void *v2);									//sort by name
int compareBySname(const void *v1, const void *v2);									//sort by surname
int compareByAge(const void *v1, const void *v2);									//sort by age
int compareByPhoneNumber(const void *v1, const void *v2);							//sort by phone number