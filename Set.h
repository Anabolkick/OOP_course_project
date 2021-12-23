#pragma once

#include <iostream>
#include "Hash.cpp"
#include <fstream>
#include<string>

using namespace std;

class Setting {	//виртуальний класс для возможности использования фугнкции задать значение для всех обьектов класса
public:
	virtual void SetAllEmpty() = 0;
};

class Candidates : public Setting {
	string Cand;
	int amount;
public:
	void SetC(string C);
	void Seta(int a);
	string GetC();
	long Geta();
	void SetAll(string C,int a=0);
	void SetAllEmpty();
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
	void SetAll(string name, long Id, string vote,string HaSh);
	void SetAll(string name, string HaSh, long Id, string vote);
	void SetAllEmpty();
	
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
	void SetAllEmpty();
	
};

class Chain: public Setting {
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
	string GetTailH();
	void del(string h);
	void SetAllEmpty();
	void getCandidates(vector<string>* Candi);
	//friend ostream& operator<<(ostream& stream, Chain& c);

};


