#include "Set.h"

INF::INF()
{
	FullName = "";
	Id = 0;
	HAsh = "";
	Vote = "";
}

void INF::SetN(string N)
{
	FullName = N;
}

void INF::SetID(long int id)
{
	Id = id;
}

void INF::SetH(string hash)
{
	HAsh = hash;
}

void INF::SetV(string vote)
{
	Vote = vote;
}

string INF::GetN()
{
	return FullName;
}

long INF::GetID()
{
	return Id;
}

string INF::GetH()
{
	return HAsh;
}

string INF::GetV()
{
	return Vote;
}

void INF::SetAll(string name, long Id, string vote, string HaSh)
{
	SetN(name);
	SetID(Id);
	SetV(vote);
	string str = vote;
	str = str + to_string(Id)+HaSh;
	Hash h;
	h.getHash(str, 16);
	SetH(h.GetH());
}

void INF::SetAll(string name, string HaSh, long Id, string vote)
{
	SetN(name);
	SetH(HaSh);
	SetID(Id);
	SetV(vote);
}

void INF::SetAllEmpty()
{
	FullName = "";
	Id = 0;
	HAsh = "";
	Vote = "";
}



Node::Node()
{
	pNext = nullptr;
	pPrev = nullptr;
}

Node::~Node()
{
	//delete[] pNext;
	//delete[] pPrev;
}

Node::Node(INF V, Node* prev, Node* next)
{
	SetN(V.GetN());
	SetID(V.GetID());
	SetH(V.GetH());
	SetV(V.GetV());
	pPrev = prev;
	pNext = next;
}

void Node::SetNext(Node* N)
{
	pNext = N;
}

void Node::SetPrev(Node* P)
{
	pPrev = P;

}

Node* Node::GetNext()
{
	return pNext;
}

Node* Node::GetPrev()
{
	return pPrev;
}

void Node::del(int h)
{
	if (pPrev == nullptr && pNext == nullptr && GetID() == h) {
		delete this;
	}
	else if (pPrev == nullptr && GetID() == h) {
		Node* current = this;
		*this = *current->GetNext();
		this->SetPrev(nullptr);
		delete current;
	}
	else if (pNext == nullptr && GetID() == h) {
		Node* prev = this->GetPrev(), * todel;
		todel = this;
		*this = *prev;
		delete todel;
	}
	else if (this->GetID() == h) {
		Node* current = this, * prev = nullptr, * next = nullptr;

		prev->SetNext(current->GetNext());
		next = current->GetNext();
		next->SetPrev(prev);
		delete[] current;
	}

}

void Node::SetAllEmpty()
{
	pNext = nullptr;
	pPrev = nullptr;
}

void Chain::del(string h)//не забіть добавить Name+to_string(Id)
{
	Hash H;
	H.getHash(h, 16);
	if (size == 1 && Head->GetH() == H.GetH()) { //удаление если 1 голова
		SetAllEmpty();
	}
	else if (Head->GetH() == H.GetH()) { //удаление если ошибка в глове
		Node* current = Head;
		Head = current->GetNext();
		Head->SetPrev(nullptr);
		delete current;
	}
	else if (Tail->GetH() == H.GetH()) {
		Node* prev = Tail->GetPrev(), * todel;
		todel = Tail;
		Tail = prev;
		delete todel;
	}
	else if (CompH(Head, H.GetH()) != 1) {//удаление
		Node* current = Head, * prev = nullptr, * next = nullptr;
		while (current->GetH() != H.GetH()) {
			prev = current;
			current = current->GetNext();
		}
		prev->SetNext(current->GetNext());
		next = current->GetNext();
		next->SetPrev(prev);
		delete[] current;

	}

}

void Chain::SetAllEmpty()
{
	Head = nullptr;
	Tail = nullptr;
	size = 0;
}

Chain::~Chain()
{
	Node* Tdelete;
	do {
		Tdelete = Head;
		Head = Tdelete->GetNext();
		delete Tdelete;
	} while (Head != nullptr);
}

Chain::Chain()
{
	Head = nullptr;
	Tail = nullptr;
	size = 0;
}

Chain::Chain(const Chain& Rop)
{
	Head = Rop.Head;
	Tail = Rop.Tail;
	size = Rop.size;

}

Node* Chain::GetHead()
{
	return Head;
}

int Chain::GetSiz()
{
	return size;
}

bool Chain::add(Node V)
{
	if (Head == nullptr) {
		Head = new Node(V, nullptr);
		Tail = Head;
		++size;
		return true;
	}
	else if (CompId(V.GetID()) != 0) {
		Node* current = Head;

		while (current->GetNext() != nullptr) {
			current = current->GetNext();
		}
		current->SetNext(new Node(V, current));
		Tail = current->GetNext();
		++size;

		return true;
	}
	return false;

}



int Chain::CompH(Node* head, string H)
{
	Hash h;
	string str;
	str = h.getHash(H, 16);
	Node* tmp, * current = nullptr;
	tmp = Head;
	signed int c = 0;
	while (tmp != nullptr) {
		if (tmp->GetH() != str) {
			c++;
		}
		else {
			c++;
			return c;
		}
		current = tmp;

		tmp = tmp->GetNext();
	}
	if (current->GetH() != str) {
		c = -1;
	}
	return c;

}


int Chain::CompId(long id)
{
	Node* tmp, * current = nullptr;
	tmp = Head;
	int c = 0;
	if (tmp != nullptr) {
		while (tmp != nullptr) {
			if (tmp->GetID() != id) {
				c++;
			}
			else {
				c++;
				return c;
			}
			current = tmp;

			tmp = tmp->GetNext();
		}
		if (current->GetID() != id) {
			c = -1;
		}
		return c;
	}
	else { return c = 0; }

}

Candidates* Chain::Voice(Candidates* Vote, int amount)
{
	Node* tmp;

	int counter = 0;
	for (int i = 0; i < amount; i++) {
		int counter = 0;
		tmp = Head;
		while (tmp != nullptr) {			//добавить проверку по хешу
			if (tmp->GetV() == Vote[i].GetC()) {
				counter++;
			}
			tmp = tmp->GetNext();
		}
		Vote[i].Seta(counter);
	}
	return Vote;
}

Candidates* Chain::Win(Candidates* Vote, int amount)
{
	int tmp;
	string current;
	for (int i = 0; i < amount - 1; i++) {
		for (int j = 0; j < amount - i - 1; j++) {
			if (Vote[j].Geta() < Vote[j + 1].Geta()) {
				tmp = Vote[j].Geta();
				current = Vote[j].GetC();
				Vote[j].Seta(Vote[j + 1].Geta());
				Vote[j].SetC(Vote[j + 1].GetC());
				Vote[j + 1].Seta(tmp);
				Vote[j + 1].SetC(current);
			}
		}
	}
	return Vote;
}

string Chain::ShowV(long a)
{
	string vote;
	Node* tmp;
	tmp = Head;
	int z = CompId(a);
	if (z == 0) {
		vote = "No one has votted yet";
	}
	else if (z == 1) {
		vote = "This ID " + to_string(a) + " voted for " + tmp->GetV();
	}
	else if (z != -1) {
		vote = "This ID " + to_string(a) + " voted for ";
		for (int i = 0; i < z - 1; i++) {
			tmp = tmp->GetNext();
		}
		vote = vote + tmp->GetV();
	}
	else { vote = "This ID " + to_string(a) + " hasn`t votted yet"; }
	return vote;
}

string Chain::GetTailH()
{
	if (Head != nullptr && Tail != nullptr) {
		return Tail->GetH();
	}
	else return to_string(0);
}


void Candidates::SetC(string C)
{
	Cand = C;
}

void Candidates::Seta(int a)
{
	amount = a;
}

string Candidates::GetC()
{
	return Cand;
}

long Candidates::Geta()
{
	return amount;
}

void Candidates::SetAll(string C, int a)
{
	SetC(C);
	Seta(a);

}

void Candidates::SetAllEmpty()
{
	Cand = "";
	amount = 0;
}


//перегрузка оператора <<

//ostream& operator<<(ostream& stream, Chain& c)
//{
//	Node* tmp, * current = nullptr;
//
//	tmp = c.GetHead();
//	int a = 0;
//	Hash h;
//	if (tmp != nullptr) {
//		stream << c.GetSiz();
//		while (tmp != nullptr) {
//			string check = tmp->GetN() + to_string(tmp->GetID());
//			if (tmp->GetH() == h.getHash(check, 16)) {
//				stream << tmp->GetID() << tmp->GetN() << tmp->GetV() << endl;
//			}
//			else {
//				tmp->del(tmp->GetID());
//			}
//			current = tmp;
//
//			tmp = tmp->GetNext();
//		}
//	}
//	return stream;
//}


