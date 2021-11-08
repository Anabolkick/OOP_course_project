//#include <iostream>
//#include "Hash.h"
//#include <fstream>
//
//
//using namespace hash;
//
//
//class votting {
//public:
//	string FullName;
//	int amount;
//};
//
//class DataD {	//�������� ������� ����������������
//public:
//	string FullName;
//	long ID;
//	string HAsh;
//	string Vote;
//	friend ostream& operator<<(ostream& stream, DataD& c);
//
//	friend istream& operator>>(istream& stream, DataD& c);
//
//};
//
//class Set {
//
//private:
//
//	int size;
//public:
//	class Dyn
//	{
//	public:
//		Dyn* pNext;	//�������� ������ �� ��������
//		Dyn* pPrev;
//		DataD Inf;
//		Dyn(DataD In, Dyn* prev, Dyn* next = nullptr);
//
//	};
//	Dyn* Head;
//	Set();
//	~Set();
//	Set(const Set& Rop);
//	bool include(DataD V);//���������� � ������
//	void exclude(string H);//�������� �� ������
//	int CompHash(Dyn* Head, string H);//����� �� ����
//	int CompId(Dyn* Head, long Id);//����� �� ID
//	votting* Win(votting* VOTE, int amount);
//};
//
//
//Set::Set()
//{
//	Head = nullptr;
//
//	size = 0;
//}
//
//Set::~Set()
//{
//	Dyn* Tdelete;
//	do {
//		Tdelete = Head;
//		Head = Tdelete->pNext;
//		delete Tdelete;
//	} while (Head != nullptr);
//}
//Set::Set(const Set& Rop)
//{
//	Head = Rop.Head;
//	size = Rop.size;
//}
//int Set::CompHash(Dyn* Head, string H)//��������� �� ����
//{
//	Hash h1;
//	string str;
//	str = h1.getHash(H, 16);
//	Dyn* tmp, * current = nullptr;
//	tmp = Head;
//	int c = 0;
//	while (tmp != nullptr) {
//		if (tmp->Inf.HAsh != str) {
//			c++;
//		}
//		else {
//			c = -1;
//			break;
//		}
//		current = tmp;
//
//		tmp = tmp->pNext;
//	}
//	if (current->Inf.HAsh != str) { c = -1; }
//	return c;
//}
//int Set::CompId(Dyn* Head, long Id)//��������� �� id
//{
//	Dyn* tmp, * current = nullptr;
//	tmp = Head;
//	int c = 0;
//	while (tmp != nullptr) {
//		if (tmp->Inf.ID != Id) {
//			c++;
//		}
//		else {
//			c = -1;
//			break;
//		}
//		current = tmp;
//
//		tmp = tmp->pNext;
//	}
//	return c;
//
//}
//votting* Set::Win(votting* VOTE, int amount)
//{
//	Dyn* tmp;
//	tmp = Head;
//	int counter = 0;
//	for (int i = 0; i < amount; i++) {
//		int counter = 0;
//		while (tmp != nullptr) {
//			if (tmp->Inf.Vote == VOTE[i].FullName) {
//				counter++;
//			}
//			tmp = tmp->pNext;
//		}
//		VOTE[i].amount = counter;
//	}
//	return VOTE;
//}
//bool Set::include(DataD V) //���������� ������ ��������
//{
//	if (Head == nullptr) {
//		Head = new Dyn(V, nullptr);
//		++size;
//		return true;
//	}
//	else if (CompId(Head, V.ID) != -1) {
//		Dyn* current = Head;
//		while (current->pNext != nullptr) {
//			current = current->pNext;
//		}
//		current->pNext = new Dyn(V, current);
//		++size;
//		return true;
//	}
//	else
//		return false;
//}
//void Set::exclude(string H)//�������� �� ����
//{
//	if (size == 1 && Head->Inf.HAsh == H) {
//		delete[] Head;
//		Head = nullptr;
//	}
//	else if (Head->Inf.HAsh == H) {
//		Dyn* current = Head;
//		Head = current->pNext;
//		Head->pPrev = nullptr;
//		delete[] current;
//	}
//	else if (CompHash(Head, H) != -1)
//	{
//		Dyn* current = Head, * prev = nullptr, * tmp;
//		while (current->Inf.HAsh != H) {
//			prev = current;
//			current = current->pNext;
//		}
//		prev->pNext = current->pNext;
//		tmp = current->pNext;
//		tmp->pPrev = prev;
//		delete current;
//	}
//	else cout << "no hash";
//}
//Set::Dyn::Dyn(DataD In, Dyn* prev, Dyn* next)
//{
//	Inf = In;
//	pPrev = prev;
//	pNext = next;
//}
///*int main() {
//	Set Vote;
//	DataD D;
//	votting* peop = new votting[3];
//	peop[0].FullName = "banan";
//	peop[0].FullName = "apple";
//	peop[0].FullName = "cherry";
//	for (int i = 0; i < 6; i++) {
//		cin >> D;
//		Vote.include(D);
//	}
//
//	cout << Vote.Head->Inf;
//	Vote.Win(peop, 3);
//	for (int i = 0; i < 3; i++) {
//		cout << peop[i].FullName << ":" << peop[i].amount;
//	}
//}*/
//
//istream& operator>>(istream& stream, DataD& c)
//{
//	Hash h;
//	string h1;
//	stream >> c.FullName >> c.ID >> c.Vote;
//	h1 = to_string(c.ID);
//	h1 = h1 + c.Vote;
//	c.HAsh = h.getHash(h1, 16);
//	return stream;
//}
//ostream& operator<<(ostream& stream, DataD& c)
//{
//	stream << "Id:" << c.ID << endl;
//	stream << "Full name:" << c.FullName << endl;
//	stream << "Hash:" << c.HAsh << endl;
//	stream << "Vote:" << c.Vote << endl;
//
//	return stream;
//}