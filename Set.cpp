#include "Set.h"
#include "votting.cpp"
#include "Hash.cpp"
#include "Hash.h"
#include "Dyn.h"
#include "Dyn.cpp"


class Set {

private:
	int size;

public:
	Dyn* Head;
	Set()
	{
		Head = nullptr;
		size = 0;
	}

	Set(const Set& Rop)
	{
		Head = Rop.Head;
		size = Rop.size;
	}

	~Set()
	{
		Dyn* Tdelete;
		do {
			Tdelete = Head;
			Head = Tdelete->pNext;
			delete Tdelete;
		} while (Head != nullptr);
	}

	bool include(DataD V) //добавление нового элемента
	{
		if (Head == nullptr) {
			Head = new Dyn(V, nullptr);
			++size;
			return true;
		}
		else if (CompId(Head, V.ID) != -1) {
			Dyn* current = Head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new Dyn(V, current);
			++size;
			return true;
		}
		else
			return false;
	}
	void exclude(string H)//удаление по хешу
	{
		if (size == 1 && Head->Inf.HAsh == H) {
			delete[] Head;
			Head = nullptr;
		}
		else if (Head->Inf.HAsh == H) {
			Dyn* current = Head;
			Head = current->pNext;
			Head->pPrev = nullptr;
			delete[] current;
		}
		else if (CompHash(Head, H) != -1)
		{
			Dyn* current = Head, * prev = nullptr, * tmp;
			while (current->Inf.HAsh != H) {
				prev = current;
				current = current->pNext;
			}
			prev->pNext = current->pNext;
			tmp = current->pNext;
			tmp->pPrev = prev;
			delete current;
		}
		else cout << "no hash";
	}
	int CompHash(Dyn* Head, string H)//сравнение по хешу
	{
		Hash h1;
		string str;
		str = h1.Hash::getHash(H, 16);
		Dyn* tmp, * current = nullptr;
		tmp = Head;
		int c = 0;
		while (tmp != nullptr) {
			if (tmp->Inf.HAsh != str) {
				c++;
			}
			else {
				c = -1;
				break;
			}
			current = tmp;

			tmp = tmp->pNext;
		}
		if (current->Inf.HAsh != str) { c = -1; }
		return c;
	}
	int CompId(Dyn* Head, long Id)//сравнение по id
	{
		Dyn* tmp, * current = nullptr;
		tmp = Head;
		int c = 0;
		while (tmp != nullptr) {
			if (tmp->Inf.ID != Id) {
				c++;
			}
			else {
				c = -1;
				break;
			}
			current = tmp;

			tmp = tmp->pNext;
		}
		return c;

	}
	votting* Win(votting* VOTE, int amount)
	{
		Dyn* tmp;
		tmp = Head;
		int counter = 0;
		for (int i = 0; i < amount; i++) {
			int counter = 0;
			while (tmp != nullptr) {
				if (tmp->Inf.Vote == VOTE[i].FullName) {
					counter++;
				}
				tmp = tmp->pNext;
			}
			VOTE[i].amount = counter;
		}
		return VOTE;
	}
};



/*int main() {
	Set Vote;
	DataD D;
	votting* peop = new votting[3];
	peop[0].FullName = "banan";
	peop[0].FullName = "apple";
	peop[0].FullName = "cherry";
	for (int i = 0; i < 6; i++) {
		cin >> D;
		Vote.include(D);
	}

	cout << Vote.Head->Inf;
	Vote.Win(peop, 3);
	for (int i = 0; i < 3; i++) {
		cout << peop[i].FullName << ":" << peop[i].amount;
	}
}*/
