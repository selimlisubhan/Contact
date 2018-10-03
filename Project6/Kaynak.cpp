#include "Header.h"


/*
Yeni konaktın əlavə edilməsi
*/
void AddContact(Contact *&newcontact, int &size, int &count, Contact &NewContact)
{
	if (count + 1 >= size) //расширяем массив, если нет пустого места
	{
		size += EXT;
		Contact* temp = new Contact[size];
		for (int i = 0; i < count + 1; i++)
		{
			temp[i] = newcontact[i];
		}

		delete[]newcontact;
		newcontact = temp;
	}
	newcontact[count] = NewContact;  //копирование новой структуры

	cout << endl << "New contact has been added:" << endl;
	ShowContact(newcontact, count);
	count++;
}

/*
Sıra nömrəsinə görə kontkaktı silir
*/
void DeleteContactNumber(Contact*& newcontact, int & count, int size, int number)
{
	Contact* temp = new Contact[size];
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i+1 != number) {
			temp[j] = newcontact[i];
			j++;
		}
	}

	delete[]newcontact;
	newcontact = temp;
	count--;

	cout << endl << "Contact has been removed." << endl;
}

/*
Ada görə kontaktı silir
*/
void DeleteContactName(Contact*& newcontact, int & count, int size, char * Name)
{
	Contact* temp = new Contact[size];
	for (int i = 0, j = 0; i < size; i++)
	{
		if ((strcmp(newcontact[i].fname, Name)) != 0) {
			temp[j] = newcontact[i];
			j++;
		}
		continue;
	}

	delete[]newcontact;
	newcontact = temp;
	count--;

	cout << endl << "Contact has been removed." << endl;
}

/*
Soyada görə kontaktı silir
*/
void DeleteContactSname(Contact*& newcontact, int & count, int size, char * sName)
{
	Contact* temp = new Contact[size];
	for (int i = 0, j = 0; i < size; i++)
	{
		if ((strcmp(newcontact[i].sname, sName)) != 0) {
			temp[j] = newcontact[i];
			j++;
		}
		continue;
	}

	delete[]newcontact;
	newcontact = temp;
	count--;

	cout << endl << "Contact has been removed." << endl;
}

/*
Sıra nömrəsinə görə kontaktı redaktə etmək üçün
*/
bool EditContactNumber(Contact* arr, int &count, int number)
{
	number--;
	if (number < 0 || number >= count) return false;

	cout << "Enter first name : "; cin.getline(arr[number].fname, sizeof(arr[number].fname));
	cout << "Enter last name : "; cin.getline(arr[number].sname, sizeof(arr[number].sname));
	cout << "Enter address : "; cin.getline(arr[number].address, sizeof(arr[number].address));
	cout << "Enter age : "; cin.getline(arr[number].age, sizeof(arr[number].age));
	cout << "Enter phone : "; cin.getline(arr[number].phone, sizeof(arr[number].phone));

}

/*
Sıra nömrəsinə görə kontaktı tapan funksiya
*/
void FindContactFromNumber(Contact *arr, int count, char * Number)
{
	for (int i = 0; i < count; i++)
		if (strcmp(arr[i].phone, Number) == 0)
		{
			ShowContact(arr, i);
			return;
		}
	cout << endl << "Contact not found" << endl;
	Beep(2213, 1000);
}

/*
Ada görə kontaktı tapan funksiya
*/
void FindContactFromName(Contact *arr, int count, char * Name)
{
	for (int i = 0; i < count; i++)
		if (strcmp(arr[i].fname, Name) == 0)
		{
			ShowContact(arr, i);
			return;
		}
	cout << endl << "Cоntact not found" << endl;
	Beep(2213, 1000);
}

/*
Soyada görə kontaktı tapan funksiya
*/
void FindContactFromSname(Contact *arr, int count, char * sName)
{
	for (int i = 0; i < count; i++)
		if (strcmp(arr[i].sname, sName) == 0)
		{
			ShowContact(arr, i);
			return;
		}
	cout << endl << "Cоntact not found" << endl;
	Beep(2213, 1000);
}

/*
Adı iki böyük hərf aralığında olan adları tapır
*/
void FindContactFromTo(Contact *arr, int count, char from, char to) {

	for (int i = 0; i < count; i++)
	{
		if ((int(arr[i].fname[0]) >= (int)from) && (int(arr[i].fname[0]) <= (int)to)) {
			ShowContact(arr, i);
			cout << arr[i].fname[0] << endl;
		}
		continue;
	}
	cout << endl << "Cоntact not found" << endl;
	Beep(2213, 1000);

}

 /*
 Hansı nömrəli kontaktı istəsən onu çap etmək üçün
 */
void ShowContact(Contact *ptr, int index)
{
	cout << endl << "Contact number: " << index + 1 << endl;
	cout << "First name: " << ptr[index].fname << endl;
	cout << "Second name: " << ptr[index].sname << endl;
	cout << "Address: " << ptr[index].address << endl;
	cout << "Age: " << ptr[index].age << endl;
	cout << "Phone number: " << ptr[index].phone << endl;
}

/*
Bütün konaktları çap etmək üçün
*/
void ShowAll(Contact* arr, int count)
{
	for (int i = 0; i < count; i++)
		ShowContact(arr, i);
}

/*
Məlumatları fayla yazmaq üçün
*/
void WriteFile(Contact *arr, int count, ofstream & ofile)
{
	for (int i = 0; i < count; i++) {
		ofile << arr[i].fname << " "
			<< arr[i].sname << " "
			<< arr[i].address << " "
			<< arr[i].age << " "
			<< arr[i].phone << endl;
	}
}

/*
Məlumatı fayldan oxumaq üçün
*/
void ReadFile(Contact *&newcontacts, int & size, int & count, ifstream & ifile)
{
	char str[100];
	Contact NewContact;
	while (ifile.getline(str, 100))
	{
		sscanf(str, "%s %s %s %s %s", NewContact.fname, NewContact.sname, NewContact.address, NewContact.age, NewContact.phone);
		AddContact(newcontacts, size, count, NewContact);
	}

}

/*
Kontaktın ada görə sıralanması
*/
int compareByName(const void *v1, const void *v2) {
	Contact *c1 = (Contact*)v1;
	Contact *c2 = (Contact*)v2;
	return strcmp(c1->fname, c2->fname);
}

/*
Kontaktın soyada görə sıralanması
*/
int compareBySname(const void *v1, const void *v2) {
	Contact *c1 = (Contact*)v1;
	Contact *c2 = (Contact*)v2;
	return strcmp(c1->sname, c2->sname);

}

/*
Kontaktın yaşa görə sıralanması
*/
int compareByPhoneNumber(const void *v1, const void *v2) {
	Contact *c1 = (Contact*)v1;
	Contact *c2 = (Contact*)v2;
	return strcmp(c1->phone, c2->phone);
}

/*
Kontaktın nömrəyə görə sıralanması
*/
int compareByAge(const void *v1, const void *v2) {
	Contact *c1 = (Contact*)v1;
	Contact *c2 = (Contact*)v2;
	return strcmp(c1->age, c2->age);
}