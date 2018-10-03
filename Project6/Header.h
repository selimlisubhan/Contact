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

void AddContact(Contact *&newcontact, int &size, int &count, Contact &NewContact);  //Yeni kontakt əlavə etmək üçün istifadə olunur
void DeleteContactNumber(Contact*& newcontact, int & count, int size, int number);	//Sıra nömrəsinə görə kontkaktı silir 
void DeleteContactName(Contact*& newcontact, int & count, int size, char * Name);	//Ada görə kontaktı silir
void DeleteContactSname(Contact*& newcontact, int & count, int size, char * sName);	//Soyada görə kontaktı silir
void ShowContact(Contact *ptr, int index);											//Hansı nömrəli kontaktı istəsən onu çap etmək üçün
void ShowAll(Contact* arr, int count);												//Bütün konaktları çap etmək üçün
void FindContactFromNumber(Contact *arr, int count, char * Number);					//Sıra nömrəsinə görə kontaktı tapan funksiya
void FindContactFromName(Contact *arr, int count, char * Name);						//Ada görə kontaktı tapan funksiya
void FindContactFromSname(Contact *arr, int count, char * sName);					//Soyada görə kontaktı tapan funksiya
void FindContactFromTo(Contact *arr, int count, char from, char to);				//Adı iki böyük hərf aralığında olan adları tapır
bool EditContactNumber(Contact* arr, int &count, int number);						//Sıra nömrəsinə görə kontaktı redaktə etmək üçün
void WriteFile(Contact *arr, int count, ofstream & ofile);							//Məlumatları fayla yazmaq üçün
void ReadFile(Contact *&newcontacts, int & size, int & count, ifstream & ifile);	//Məlumatı fayldan oxumaq üçün
int compareByName(const void *v1, const void *v2);									//Kontaktın ada görə sıralanması 
int compareBySname(const void *v1, const void *v2);									//Kontaktın soyada görə sıralanması 
int compareByAge(const void *v1, const void *v2);									//Kontaktın yaşa görə sıralanması 
int compareByPhoneNumber(const void *v1, const void *v2);							//Kontaktın nömrəyə görə sıralanması 