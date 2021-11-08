#include "DataD.h"	 

#include <string>
#include <ostream>
#include "Hash.h"
using namespace std;


class DataD {	//хранение даннных проголосовавшего
public:
	DataD();
	string FullName;
	long ID;
	string HAsh;
	string Vote;
	/*friend ostream& operator<<(ostream& stream, DataD& c);
	friend istream& operator>>(istream& stream, DataD& c);*/
};



//istream& operator>>(istream& stream, DataD& c)
//{
//	Hash h;
//	string h1;
//	stream >> c.FullName >> c.ID >> c.Vote;
//	h1 = to_string(c.ID);
//	h1 = h1 + c.Vote;
//	c.HAsh = h.Hash::getHash(h1, 16);
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