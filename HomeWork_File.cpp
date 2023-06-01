#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>


void FillFile(std::string file) {
	std::ofstream fill(file);
	std::string str;
	for (int i = 1; i <= 3; i++)
	{
		std::cout << i << ")";
		std::cin >> str;
		fill << str << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choicefile, choice;
	std::string str, name, amounts, prices;
	std::string namefile1 = "ProductName.txt", namefile2 = "Amount.txt", namefile3 = "Price.txt";
	std::ifstream PN(namefile1);
	std::ifstream amount(namefile2);
	std::ifstream price(namefile3);
	std::cout << "Выберете Файл:\n1)ProductName.txt\n2)Amount.txt\n3)Price.txt\n0)Выход\n--->";
	std::cin >> choicefile;


	while (choicefile != 0)
	{
		if (choicefile == 1)
		{
			if (!PN.eof()) //switch при открытии файла через ofstream выдает ошибку
			{
				std::cout << "Файл заполнен!\n1)пропустить\n2)повторно заполнить\n--->)";
				std::cin >> choice;
				if (choice == 2)
				{
					std::ofstream FillPN(namefile1);
					FillFile(namefile1);
					FillPN.close();

				}
			}
			else {
				std::ofstream FillPN(namefile1);
				FillFile(namefile1);
				FillPN.close();
			}
		}
		else if (choicefile == 2)
		{
			if (!amount.eof())
			{
				std::cout << "Файл заполнен!\n1)пропустить\n2)повторно заполнить\n--->)";
				std::cin >> choice;
				if (choice == 2)
				{
					std::ofstream FillAmount(namefile2);
					FillFile(namefile2);
					FillAmount.close();

				}
			}
			else {
				std::ofstream FillAmount(namefile2);
				FillFile(namefile2);
				FillAmount.close();
			}
		}
		else if (choicefile == 3)
		{
			if (!PN.eof())
			{
				std::cout << "Файл заполнен!\n1)пропустить\n2)повторно заполнить\n--->)";
				std::cin >> choice;
				if (choice == 2)
				{
					std::ofstream FillPrice(namefile3);
					FillFile(namefile3);
					FillPrice.close();

				}
			}
			else {
				std::ofstream FillPrice(namefile3);
				FillFile(namefile3);
				FillPrice.close();
			}
		}
		else
		{
			std::cout << "ERROR";
		}

		std::cout << "\n\nВыберете Файл:\n1)ProductName.txt\n2)Amount.txt\n3)Price.txt\n0)Выход\n--->";
		std::cin >> choicefile;
	}

	std::cout << "Id Название  Кол-во  Цена\n";
	int i = 1;
	while (!PN.eof())
	{
		name = ""; //это для того чтоб повторно не выводились слова
		amounts = "";
		prices = "";
		std::getline(PN, name);
		std::getline(amount, amounts);
		std::getline(price, prices);
		if (i != 4) std::cout << i;//это для того чтоб повторно не выводилась id
		std::cout << ") " << name << "  " << amounts << "  " << prices << std::endl;

	}
	PN.close();
	amount.close();
	price.close();

}
