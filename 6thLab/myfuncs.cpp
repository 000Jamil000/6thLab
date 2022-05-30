#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "mystruct.h"
using namespace std;


string getCase() {
	cout << "Выберите действие: \n";
	cout << "1 - печать всех элементов \n";
	cout << "2 - добавить элемент в список \n";
	cout << "3 - сброс всех элементов \n";
	cout << "4 - выход \n";
	string s;
	cin >> s;
	while (true) {
		if ("1" <= s && s <= "4" && s.length() == 1) {
			return s;
		}
		else {
			cout << "Ошибка ввода. Попробуйте еще раз \n";
			cin >> s;
		}
	}
}
