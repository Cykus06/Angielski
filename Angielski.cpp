// Angielski.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	std::fstream in("slownik.txt");

	std::string pl, ang, temp;
	std::vector<std::string> powt, powtang;

	int  n = 0;
	bool a = true;

	if (in)
	{
		while (!in.eof())
		{
			std::getline(in, pl);
			std::getline(in, ang);

			std::cout << "PL:\t" << pl << "\nODP:\t";

			std::getline(std::cin, temp);

			while (temp != ang)
			{
				if (temp == "!");
				{
					std::cout << "opd:\t" << ang << '\n';
					system("pause");
				}
				if (a)
				{
					powt.push_back(pl);
					powtang.push_back(ang);
					a = false;
				}
				system("CLS");
				std::cout << "PL:\t" << pl << "\nODP:\t";
				getline(std::cin, temp);
			}
			system("CLS");

			a = true;
		}

		for (auto el: powt)
		{
			std::cout << "PL:\t" << el << "\nODP:\t";
			std::getline(std::cin, temp);
			while (temp != powtang[n])
			{
				system("CLS");
				std::cout << "PL:\t" << el << "\nODP:\t";
				getline(std::cin, temp);
			}

			system("CLS");

			n++;
		}
	}
	else
	{
		std::cout << "B£¥D: nie mo¿na otworzyæ pliku do odczytu." << '\n';
	}
	in.close();
    system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
