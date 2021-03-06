// Write a program that demonstrates the try / catch exception handler blocks for a minimum of 4 different exceptions.
// Include sufficient output to indicate the exception and the condition that caused it.Use more than one catch type.
// Explanation of the exceptions and conditions that caused them should be commented appropriately in the program.

#include "stdafx.h"
#include <iostream>
#include <exception>
#include <string>

using namespace std;


int main()
{
	int select = 0;
	int stats = 20;
	int strength = 5;
	int dexterity = 5;
	int intelligence = 5;
	string select01;
	string name = "";

	do
	{
		cout << "Welcome To Character Creation.\n";
		cout << "Please read the menu carefully.\n";
		cout << "(1) Create a name for the character.\n";
		cout << "(2) Add to your character's Strength.\n";
		cout << "(3) Add to your character's Dexterity.\n";
		cout << "(4) Add to your character's Intelligence.\n";
		cout << "(5) Display stats and point(s) remaining.\n";
		cout << "(6) Exit Program.\n";
		cout << "==================================================\n\n";
		cin >> select01;

		try
		{
			
			//using "stoi" to detect integer value in string and convert variable, throw exception if needed
			select = stoi(select01);
			//creating exception parameters, less than 1 and greater than 6
			if (select < 1 && select > 6)
			{
				throw "Please select a numerical value between 1 and 6.\n\n";
			}
			if (select == 1)
			{
				//creating exception parameters, name already set
				if (name == "")
				{
					cout << "What is your Name?\n";
					cin >> name;
				}
				else
				{
					throw "You have already named your character.\n\n";
				}
			}
			else if (select == 2)
			{
				if (stats <= 0)
				{
					throw "Insufficient Points.\n\n";
				}
				else
				{
					cout << "Strength augmented by 1.\n\n";
					strength = strength + 1;
					stats = stats - 1;
				}
			}
			else if (select == 3)
			{
				if (stats <= 0)
				{
					throw "Insufficient Points.\n\n";
				}
				else
				{
					cout << "Dexterity augmented by 1.\n\n";
					dexterity = dexterity + 1;
					stats = stats - 1;
				}
			}
			else if (select == 4)
			{
				if (stats <= 0)
				{
					throw "Insufficient Points.\n\n";
				}
				else
				{
					cout << "Intelligence augmented by 1.\n\n";
					intelligence = intelligence + 1;
					stats = stats - 1;
				}
			}
			else if (select == 5)
			{
				cout << "Name: " << name << ".\n";
				cout << "Health: " << (strength * 10) << ".\n";
				cout << "Mana: " << (intelligence * 5) << ".\n";
				cout << "Stamina: " << (dexterity *5) << ".\n";
				cout << "Attack: " << (strength + dexterity) << ".\n";
				cout << "Defence: " << ((strength + dexterity) / 2) << ".\n";
				cout << "Magic Attack: " << (intelligence + dexterity) << ".\n";
				cout << "Magic Defense: " << ((intelligence + dexterity) / 2) << ".\n";
				cout << "==================================================\n";
				cout << "Strength: " << strength << ".\n";
				cout << "Dexterity: " << dexterity << ".\n";
				cout << "Intelligence: " << intelligence << ".\n";
				cout << "Allotable Stats: " << stats << ".\n";
				cout << "==================================================\n\n";

			}
		}
		// setting the catches for the throws
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << ".\n";
		}
		catch (...)
		{
			cout << "Not sure what happened, let's try that again.\n";
		}
	} while (select != 6);
	
	cout << "Goodbye!\n";
	system("pause");
    return 0;
}

