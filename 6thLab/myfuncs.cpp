#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "mystruct.h"
using namespace std;


string getCase() {
	cout << "�������� ��������: \n";
	cout << "1 - ������ ���� ��������� \n";
	cout << "2 - �������� ������� � ������ \n";
	cout << "3 - ����� ���� ��������� \n";
	cout << "4 - ����� \n";
	string s;
	cin >> s;
	while (true) {
		if ("1" <= s && s <= "4" && s.length() == 1) {
			return s;
		}
		else {
			cout << "������ �����. ���������� ��� ��� \n";
			cin >> s;
		}
	}
}
