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
string GameLogic(int n1, int  n2);


int main()
{

	string input("");
	int random_number, option,scores = 0;
	int tries = 0;
	bool run = true;

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
			
			auto result = GameLogic(random_number, atoi(input.c_str()));
			if (result.length() == 0)
				std::cout << "FALLASTE!" << endl;

			else if (result == "FFFF") 
			{
				std::cout << "FELICIDADES GANASTE !!!" << endl;
				run = false;
			}
			else
			{
				tries++;
				std::cout << result <<" tienes "<<tries<<" intentos "<<endl;
			}			

		}
		else
		{
			tries++;
			cout << "" << endl;
			cout << "La entrada no es correcta . Verifique e intente nuevamente" << std::endl;
			Sleep(2000);
			system("cls");
		}

	} while (run);


	
	system("pause");
    return 0;
}


int GenerateRandomNumber()
{
	int digit1, digit2, digit3, digit4 = 0;

	std::srand(unsigned(std::time(0)));
	std::vector<int> rangeNumbers;

	for (int i = 1; i < 10; i++){rangeNumbers.push_back(i); }

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
	if (input.length() > 4) return false;
	
	if (atoi(input.c_str()) == 0)
		return false;

	for (int i = 0; i < input.size(); i++)
	{
		
		for (int x = i+1; x < input.size(); x++)
		{
			if (input.at(i) == input.at(x))
				return false;
		}
	}
	


	return true;
}

string GameLogic(int n1, int n2)
{
	string random_number = std::to_string(n1);
	string input = std::to_string(n2);
	string result("");
	for (int i = 0; i < random_number.size(); i++)
	{
		for (int x = 0; x < input.size(); x++)
		{
			if(input.at(i) == random_number.at(x))
			{
				if (i == x) {
					result += 'F';
				}
				else {
					result += 'P';
				}
			}
		}
	}

	return result;

}

