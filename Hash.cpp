#include "Hash.h"

#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Hash
{
private:
	string hash;

	int getSaul(string str)   //сумма всех символов введеніх в строку
	{
		unsigned int sum = 0, strlen = 0;
		for (; strlen < str.size(); strlen++)
			sum += int(str[strlen]);

		return sum;
	}

public:

	string getHash(string PasID, unsigned int lengHash) {//генерация хеша
		if (lengHash > 3) {
			unsigned int minLen = 2, realMinLen = 0, OrgSaul = this->getSaul(PasID), OrgLen = (PasID.size());

			while (minLen <= lengHash)	//получаем длину нужной строки
				realMinLen = (minLen *= 2);

			while (minLen < OrgLen)	//число ближайшее к длине иходной строки
				minLen *= 2;

			if ((minLen - OrgLen) < minLen)
				minLen *= 2;

			int addCount = minLen - OrgLen;//кол символ необходиміх для добавления к строке


			for (int i = 0; i < addCount; i++)		//добавляем значения
				PasID += this->getCod(PasID[i] + PasID[i + 1]);

			int maxSaul = this->getSaul(PasID), maxLen = PasID.size();

			//определение уменьшения строки 
			while (PasID.size() != realMinLen) {
				for (int i = 0, center = PasID.size() / 2; i < center; i++) {
					this->hash += this->getCod(PasID[center - i] + PasID[center + i]);
				}
				PasID = this->hash;
				this->hash.clear();

			}
			//нужная длина
			unsigned int Nlen = realMinLen - lengHash;//В нужную длину

			for (unsigned int i = 0, countCompr = realMinLen / Nlen; this->hash.size() < (lengHash - 4); i++) {
				if (i % countCompr == 0)
					this->hash += this->getCod(PasID[i] + PasID[++i]);
				else
					this->hash += PasID[i];

			}
			//добавление солей
			this->hash += this->getCod(OrgSaul);
			this->hash += this->getCod(OrgLen);
			this->hash += this->getCod(maxSaul);
			this->hash += this->getCod(maxLen);
			return this->hash;
		}
		return "";

	}

	int getCod(int x)
	{
		x += 256;
		while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) {
			if (x < 48) { x += 24; }
			else { x -= 47; }
		}
		return x;
	};
};
