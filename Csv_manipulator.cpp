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
				if (nodes.capacity() == 0) 
				{
					node.SetAll(name, id, vote, 0);
					nodes.push_back(node);
					count = count + 1;
				}
				else 
				{
					long prevId = nodes[nodes.size()-1].GetID();
					node.SetAll(name, id, vote, prevId);
					nodes.push_back(node);
					count=count+1;
				}
			}
		}
	}
	return nodes;
}


