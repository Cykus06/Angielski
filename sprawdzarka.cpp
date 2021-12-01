#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale.h>

void sprawdzarka(std::string plik)
{
	std::fstream in(plik);

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

		for (auto el : powt)
		{
			std::cout << "PL:\t" << el << "\nODP:\t";
			std::getline(std::cin, temp);
			while (temp != powtang[n])
			{
				if (temp == "!");
				{
					std::cout << "opd:\t" << ang << '\n';
					system("pause");
				}
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