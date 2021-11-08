#include <ostream>
#include <string>
#include "DataD.h"
#include "DataD.cpp"
#include "Dyn.h"

class Dyn
{
public:
	Dyn(DataD In, Dyn* prev, Dyn* next = nullptr)
	{
		Inf = In;
		pPrev = prev;
		pNext = next;
	}
	Dyn* pNext;	//�������� ������ �� ��������
	Dyn* pPrev;
	DataD Inf;
};


