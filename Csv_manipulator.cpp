#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Csv_manipulator.h"
#include "Set.h"

using namespace std;

void Csv_manipulator::SaveAll(string file_name, string name, string vote, string hash, long id)
{
	ofstream fout;

	fout.open(file_name, fstream::app);
	if (fout.is_open())
	{
		fout << name << ','
			<< vote << ','
			<< hash << ','
			<< id << '\n';
	}

	fout.close();
}

vector<Node> Csv_manipulator::GetNodes(string file_name, int& count)
{
	ifstream fin(file_name);
	vector<Node> nodes;
	vector<string> row;
	string line;
	string word;

	if (fin.is_open() == true)
	{
		while (!fin.eof())
		{
			row.clear();
			getline(fin, line);

			//Разрешает работать со строкой, как с потоком
			stringstream ss(line);

			if (!line.empty())
			{
				while (getline(ss, word, ','))
				{
					row.push_back(word);
				}

				string name = row[0];
				string vote = row[1];
				string hash = row[2];

				//Пытаеться преобразовать в int
				long id = stoi(row[3]);

				Node node;
				node.SetAll(name, id, vote, nodes[nodes.capacity() - 1].GetID());
				nodes.push_back(node);
				count++;
			}
		}
	}
	return nodes;
}


