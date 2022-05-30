#include <iostream>
#include <fstream>
#include <string>
#include "mystruct.h"
#include "constants.h"
#include "myfuncs.h"
#include <Windows.h>
using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool cycle{ false };
	EquitiesList list;
	ifstream fin{ IN_OUT_FILE };

	if (fin.is_open()) {
		string Name{}, Transactions{}, Volume{};
		while (!fin.eof()) {
			getline(fin, Name, ';');
			getline(fin, Transactions, ';');
			getline(fin, Volume);
			list.push_back(Name, Transactions, Volume);
		}
		fin.close();
		cycle = true;
		cout << "Данные успешно загружены... \n";
	}

	else { cout << "Ошибка открытия файла! \n"; }

	while (cycle) {
		string way = getCase();
		if (way == "1") { //вывод на консоль всех элементов
			list.print();
		}
		else if (way == "2") {//добавить элемент в список
			cout << "Введите название элемента после, после которого хотите добавить новый элемент: \n";
			string s;
			cin.ignore();
			getline(cin, s);
			string Name{}, Transactions{}, Volume{};
			cout << "Введите название ценной бумаги: ";
			cin >> Name;
			
			bool flag = true;
			while (flag)
			{
				cout << "Введите количество транзакций: ";
				cin >> Transactions;
				try
				{
					if (stoi(Transactions) == stod(Transactions) && stoi(Transactions) >= 0) {
						flag = false;
					}
					else { cout << "Неправильный ввод данных. Попробуйте еще раз \n"; }
				}
				catch (...)
				{
					cout << "Введенное число должно быть целым положительным \n";
				}
			}
			flag = true;
			while (flag)
			{
				cout << "Введите количество объем торгов: ";
				cin >> Volume;
				try
				{
					if (stoi(Volume) == stod(Volume) && stoi(Volume) >= 0) {
						flag = false;
					}
				}
				catch (...)
				{
					cout << "Введенное число должно быть целым положительным \n";
				}
			}
			list.insert(Name, Transactions, Volume, s);
		}
		else if (way == "3") {//сброс свех элементов
			list.Reset();
		}
		else if (way == "4") {//выгрузка в файл и завершение работы
			ofstream fout{ "list.txt"};
			if (fout.is_open()) {
				list.print(fout);
				cout << "Изменения сохранены. Для проверки откройте файл list.txt \n";
				fout.close();
				cycle = false;
			}
			else {
				cout << "Невозможно сохранить изменения \n.";
				cycle = false;
			}
		}
	}
}
