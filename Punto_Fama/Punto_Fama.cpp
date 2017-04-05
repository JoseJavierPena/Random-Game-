// Punto_Fama.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm> 
#include <string>
#include <Windows.h>
using namespace std;


int GenerateRandomNumber();
bool IsValidUserInput(string input);
char ContaintsDigits(int n1, int  n2);


int main()
{

	string input("");
	int random_number, option,scores = 0;
	int tries = 10;

	//Generating the random number
	random_number = GenerateRandomNumber();

    

	do
	{
		cout << random_number << endl;
		cout<< "****PUNTO Y FAMA****" << std::endl;
		cout << "Adivine el numero de cuatro digitos" << endl;
		cin >> input;
	
		if (IsValidUserInput(input)) 
		{
			
			auto result = ContaintsDigits(random_number, stoi(input));
			if (result == 'A')
			{
				cout << "ADIVINASTE!!!!!!!" << std::endl;
				Sleep(2000);
				system("cls");
				random_number = GenerateRandomNumber();
				tries = 0;
				
			}else if( result == 'N')
			{
				cout << "FALLASTE" << endl;
				tries--;
			}
			else if (result == 'P') 
			{
				cout << "P" << endl;
				tries--;
			}
			else if(result == 'F')
			{
				cout << "F" << endl;
				scores++;
			}
			

		}
		else
		{
			tries--;
			cout << "" << endl;
			cout << "La entrada no es correcta . Verifique e intente nuevamente" << std::endl;
			Sleep(2000);
			system("cls");
		}

	} while (tries > 1);


	
	system("pause");
    return 0;
}


int GenerateRandomNumber()
{
	int digit1, digit2, digit3, digit4 = 0;

	std::srand(unsigned(std::time(0)));
	std::vector<int> rangeNumbers;

	for (int i = 1; i <= 4; i++){rangeNumbers.push_back(i); }

	// using built-in random generator:
	std::random_shuffle(rangeNumbers.begin(), rangeNumbers.end());
	
	
	digit1 = rangeNumbers[0];
	digit2 = rangeNumbers[1];
	digit3 = rangeNumbers[2];
	digit4 = rangeNumbers[3];

	return digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;
}

bool IsValidUserInput(string input)
{
	
	int value = atoi(input.c_str());

	if (value == 0)
		return false;


	if (value >= 1000 && value <= 99999)
	{
		int digit1, digit2, digit3, digit4 = 0;
		digit1 = value / 1000;
		digit2 = (value % 1000) / 100;
		digit3 = (value % 1000) / 10;
		digit4 = (value % 10);
		if (digit1 != digit2 && digit1 != digit3 && digit1 != digit4 &&
		    digit2 != digit3 && digit2 != digit4 &&
			digit3 != digit4 )
			return true;
	}


	return false;
}

char ContaintsDigits(int n1, int n2)
{
	//Returing A if all digits are equal
	if (n1 == n2)
	{
		return 'A';
	}

	string randomNumber = std::to_string(n1);
	string input = std::to_string(n2);
	int index = 0;
	int found = 0;
  
	for (int i = 0; i < randomNumber.size(); i++)
	{
		index = randomNumber.find_first_of(input.at(i));
		found++;
	}

	//Returnig N if none of the digits are containts in the random number
	if (found = 0)
		return 'N';
    

	char char1 = randomNumber.at(found);
	char char2 = input.at(found);

	
	if (char1 == char2)
		return 'F';

	
	if (char1 != char2)
		return 'P';
}

