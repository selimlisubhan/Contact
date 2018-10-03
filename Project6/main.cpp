#include "Header.h"


int main()
{
	int size = 0;			
	int count = 0;			
	int ContactNumber;

	Contact* Kontakt = new Contact[size];
	Contact n_contact;

	char MenuChoise, Exit;

	do
	{
		do
		{
			system("cls");
			cout << "******** Contact Book ********" << endl << endl;
			cout << "(1) ADD NEW CONTACT" << endl << "(2) EDIT CONTACT" << endl << "(3) DELETE CONTACT" << endl
				<< "(4) SHOW ALL CONTACTS" << endl << "(5) SHOW ONE CONTACT" << endl << "(6) FIND CONTACT" <<
				endl << "(7) SAVE FILE" << endl << "(8) LOAD FILE" <<
				endl << "(9) EXIT" << endl << endl;
			MenuChoise = _getch();
		} while (MenuChoise < '1'  &&  MenuChoise > '9');

		switch (MenuChoise)
		{
		case '1': //Yeni kontakt əlavə etmək üçün
			cout << "Entering new contact..." << endl << endl;
			cout << "Enter first name: " << endl;
			cin.getline(n_contact.fname, 30);
			cout << "Enter second name: " << endl;
			cin.getline(n_contact.sname, 30);
			cout << "Enter address: " << endl;
			cin.getline(n_contact.address, 150);
			cout << "Enter age: " << endl;
			cin.getline(n_contact.age, 5);
			cout << "Enter phone number (10 digits): " << endl;
			cin.getline(n_contact.phone, 15);

			AddContact(Kontakt, size, count, n_contact);  //Adds recorded information to contacts
			break;
		case '2': //Edit contact according to row number
			cout << "Enter the number of contact for edit: (0 - Number, else - break)" << endl;
			cin >> ContactNumber;
			cin.ignore();
			if (ContactNumber == 0)
			{
				int index1;
				cout << "Enter the contact id : ";
				if (cin >> index1 && (cin.ignore(), EditContactNumber(Kontakt, count, index1)))  //Write a contact's number to edit and returns true if the edit is successful
				{
					cout << "Contact has been successfully updated." << endl;
				}
				else //If the included contact number fails
				{
					cout << "Invalid contact id or the contact record does not exist. Please try again." << endl; 
					Beep(2213, 1000);
				}
			}
			break;
		case '3': //The deletes the property by its contact number or surname
			cout << "Please choise: can you delete contact with name (0) , number (1) or  surname (2) ?" << endl;
			cin >> ContactNumber;
			cin.ignore();
			if (ContactNumber == 0)
			{
				char Name[30];
				cout << "Enter name: " << endl;
				cin.getline(Name, 30);
				DeleteContactName(Kontakt, count, size, Name); //deletion of contact with name
			}
			else if (ContactNumber == 1)
			{
				char Number[150];
				cout << "Enter number: " << endl;
				cin.getline(Number, 150);
				if (ContactNumber > count || ContactNumber < 1)
				{
					cout << "Invalid number!" << endl;
					Beep(2213, 1000);
					break;
				}
				DeleteContactNumber(Kontakt, count, size, ContactNumber - 1); //deleting contact with contact number
			}
			else if (ContactNumber == 2)
			{
				char sName[30];
				cout << "Enter name: " << endl;
				cin.getline(sName, 30);
				DeleteContactSname(Kontakt, count, size, sName); //deleting contact with surname
			}
			break;
		case '4': // sort by
			cout << "Please choose you want to sort by: name (0) , age (1) , surname (2) , phone number (3) or id (4) ?  " << endl;
			cin >> ContactNumber;
			switch (ContactNumber)
			{
			case 0:
				qsort(Kontakt, count, sizeof(Contact), compareByName); // name
				ShowAll(Kontakt, count);
				break;
			case 1:
				qsort(Kontakt, count, sizeof(Contact), compareByAge); // age
				ShowAll(Kontakt, count);
				break;
			case 2:
				qsort(Kontakt, count, sizeof(Contact), compareBySname); // surname
				ShowAll(Kontakt, count);
				break;
			case 3:
				qsort(Kontakt, count, sizeof(Contact), compareByPhoneNumber); // phone number
				ShowAll(Kontakt, count);
				break;
			case 4:
				ShowAll(Kontakt, count);  // id
				break;
			}
			break;
		case '5': // Any number you want to print
			cout << "Enter the number of contact: " << endl;
			cin >> ContactNumber;
			cin.ignore();
			if (ContactNumber > count || ContactNumber < 1)
			{
				cout << "Invalid number!" << endl;
				Beep(2213, 1000);
				break;
			}
			ShowContact(Kontakt, ContactNumber - 1); 
			break;
		case '6': // search contact
			cout << "Enter the number of contact for searching: (0 - Name, 1 - Number, 2 - Surname, 3 - Alphabet, else - break)" << endl;
			cin >> ContactNumber;
			cin.ignore();
			if (ContactNumber == 0)
			{
				char Name[30];
				cout << "Enter name: " << endl;
				cin.getline(Name, 30);
				FindContactFromName(Kontakt, count, Name); // name
			}
			else if (ContactNumber == 1)
			{
				char Number[150];
				cout << "Enter number: " << endl;
				cin.getline(Number, 150);
				FindContactFromNumber(Kontakt, count, Number); // phone numer
			}
			else if (ContactNumber == 2)
			{
				char sName[30];
				cout << "Enter surname: " << endl;
				cin.getline(sName, 30);
				FindContactFromSname(Kontakt, count, sName); // surname
			}
			else if (ContactNumber == 3)
			{
				char a, b;
				cout << "Enter first (from): " << endl;
				cin >> a;
				cout << "Enter second (to): " << endl;
				cin >> b;
				if (((int)a >= 65) && ((int)b <= 90)) {
					FindContactFromTo(Kontakt, count, a, b); // choose 2 alphabetand found contact beetwen 2 alphabet
					break;
				}
				else {
					cout << "Please write only Alphabet and Big Letters!" << endl;
					Beep(2213, 1000);
					break;
				}
			}
			break;
		case '7': // To write data to file
		{

			cout << "Enter file name for writing: " << endl;
			char fName[30];
			cin.getline(fName, 30);
			ofstream ofile(fName);
			if (!ofile) {
				cout << "Error in openind file for writing.\n";
				Beep(2213, 1000);
			}
			else
				WriteFile(Kontakt, count, ofile);

		}
		break;
		case '8': // To read information from a file
		{

			cout << "Enter file name for reading: " << endl;
			char fName[30];
			cin.getline(fName, 30);
			ifstream ifile(fName);
			if (!ifile) {
				cout << "Error in openind file for reading.\n";
				Beep(2213, 1000);
			}
			else
			{
				ReadFile(Kontakt, size, count, ifile);
			}
		}
		break;
		case '9':
			return 0;
		}

		cout << endl << "Do you want to make another operation? (1 - yes, 0 - no)" << endl;
		Exit = _getch();
	} while (Exit != '0');


	delete[]Kontakt;
	Kontakt = nullptr;
}

