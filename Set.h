#pragma once

#include <iostream>
#include "Hash.cpp"
#include <fstream>
#include<string>

using namespace std;

class Setting {	//виртуальний класс для возможности использования фугнкции задать значение для всех обьектов класса
public:
	virtual void SetAll() = 0;
};

class Candidates {
	string Cand;
	int amount;
public:
	void SetC(string C);
	void Seta(int a);
	string GetC();
	long Geta();
	void SetAll(string C,int a=0);
};

class INF  {
	string FullName;
	long int Id;
	string HAsh;
	string Vote;
public:
	INF();
	void SetN(string N);
	void SetID(long int id);
	void SetH(string hash);
	void SetV(string vote);
	string GetN();
	long GetID();
	string GetH();
	string GetV();
	void SetAll(string name, long Id, string vote);
	
};


class Node: public INF {
	
	Node* pNext;
	Node* pPrev;
public: 
	Node();
	~Node();
	Node( INF V, Node* prev, Node* next = nullptr);
	void SetNext(Node* N);
	void SetPrev(Node* P);
	Node* GetNext();
	Node* GetPrev();
	void del(int h);
	
	
};

class Chain {
	Node* Head;
	Node* Tail;
	int size;
public:
	~Chain();
	Chain();
	Chain(const Chain& Rop);
	Node* GetHead();
	int GetSiz();
	bool add(Node V);// добавленние данних
	
	int CompH(Node* head, string H);
	int CompId( long id);
	Candidates* Voice(Candidates* Vote, int amount);
	Candidates* Win(Candidates* Vote, int amount);
	string ShowV(long a);
	void del(Node* h);
	friend ostream& operator<<(ostream& stream, Chain& c);
	friend istream& operator>>(istream& stream, Chain& c);

};


