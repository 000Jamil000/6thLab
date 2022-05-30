#ifndef mystruct_h
#define mystruct_h

#include <string>
#include <iostream>

using namespace std;

struct Equities{
	Equities* next;
	string Name;
	string Transactions;
	string Volume;
	Equities(string Name_, string Transactions_, string Volume_) : Name{ Name_ }, Transactions{ Transactions_},  Volume{ Volume_ }, next{ nullptr } {};
};

struct EquitiesList {
	Equities* first;
	Equities* last;
	
	EquitiesList() : first{ nullptr }, last{ nullptr } {};
	bool is_empty() {
		return first == nullptr;
	}

	void push_back(string Name_, string Transactions_, string Volume_) {
		Equities* p = new Equities(Name_, Transactions_, Volume_);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void print(ostream& f) {
		if (is_empty()) return;
		Equities* p = first;
		while (p) {
			if (p->next == nullptr) { f << p->Name << ";" << p->Transactions << ";" << p->Volume; }
			else{ f << p->Name << ";" << p->Transactions << ";" << p->Volume << "\n"; }
			p = p->next;
		}
	}

	void print() {
		if (is_empty()) return;
		Equities* p = first;
		unsigned int count = 0;
		while (p) {
			cout<< count << ". " << p->Name << ";" << p->Transactions << ";" << p->Volume << " \n";
			p = p->next;
			count++;
		}
		cout << endl;
	}

	Equities* find(string Name_) {
		Equities* p = first;
		while (p && p->Name != Name_) p = p->next;
		return (p && p->Name == Name_ ) ? p : nullptr;
	}

	Equities* operator[] (const int index) {
		if (is_empty()) return nullptr;
		Equities* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
	
	void insert(string Name_, string Transactions_, string Volume_, string Place) { 
		// ƒобавление ценной бумаги в односв€зный список по ее названию 
		//(если в списке нет Place, то элемент добавл€етс€  в конец списка)

		Equities* p = new Equities(Name_, Transactions_, Volume_);
		Equities* prev = find(Place);
		Equities* next;
		if (!prev) { push_back(Name_, Transactions_, Volume_); delete p; }
		else {
			next = prev->next;
			prev->next = p;
			p->next = next;
		}
		return;
	}

	void insert(string Name_, string Transactions_, string Volume_, unsigned int index) {
		// ƒобавление ценной бумаги в односв€зный список по ее названию 
		//(если в списке нет элемента с индексом index, то элемент добавл€етс€  в конец списка)
		Equities* p = new Equities(Name_, Transactions_, Volume_);
		Equities* prev = first;
		for (unsigned int i = 0; i < index; i++) {
			if (!prev->next) {
				prev = nullptr;
				break;
			}
			prev = prev->next;
		}
		if (!prev) {
			push_back(Name_, Transactions_, Volume_);
			delete p;
			return;
		}
		Equities* next = prev->next;
		prev->next = p;
		p->next = next;
		return;
	}

	void Reset() {
		Equities* p = first;
		while (p) {
			p->Name = "DefaultName";
			p->Transactions = "DefaultNumOfTransations";
			p->Volume = "DefaultVolume";
			p = p->next;
		}
	}
};

#endif 