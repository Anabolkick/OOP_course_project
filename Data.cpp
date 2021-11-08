#include <iostream>
#include "Hash.h"

using namespace hash;


struct Data {	//хранение даннных проголосовавшего
	string FullName;
	long ID;
	string HAsh;
};

class Set {
	class Dyn
	{
	public:
		Dyn* pNext;	//хранение ссылок на следущие
		Dyn* pPrev;
		Data Inf;
		Dyn(Data In, Dyn* prev, Dyn* next = nullptr);
	};
private:
	Dyn* Head;
	int size;
public:
	Set();
	~Set();
	Set(const Set& Rop);
	bool include(Data V);//добавление в список
	void exclude(string H);//удаление со списка
	int CompHash(Dyn* Head, string H);//поиск по хешу
	int CompId(Dyn* Head, long Id);//поиск по ID
};


Set::Set()
{
	Head = nullptr;

	size = 0;
}

Set::~Set()
{
	Dyn* Tdelete;
	do {
		Tdelete = Head;
		Head = Tdelete->pNext;
		delete Tdelete;
	} while (Head != nullptr);
}


Set::Set(const Set& Rop)
{
	Head = Rop.Head;
	size = Rop.size;
}



int Set::CompHash(Dyn* Head, string H)//сравнение по хешу
{
	Hash h1;
	string str;
	str = h1.getHash(H, 16);
	Dyn* tmp, * current;
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

int Set::CompId(Dyn* Head, long Id)//сравнение по id
{
	Dyn* tmp, * current;
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
	if (current->Inf.ID != Id) { c = -1; }
	return c;

}

bool Set::include(Data V) //добавление нового элемента
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

void Set::exclude(string H)//удаление по хешу
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
	else if (CompHash(Head, H) !=-1)
	{
		Dyn* current = Head, * prev = nullptr,*tmp;
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
}

Set::Dyn::Dyn(Data In, Dyn* prev, Dyn* next)
{
	Inf = In;
	pPrev = prev;
	pNext = next;


}
