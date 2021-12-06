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
					node.SetAll(name, hash, id, vote);
					nodes.push_back(node);
					count = count + 1;
			}
		}
	}
	return nodes;
}

void Csv_manipulator::SaveCsv(string path, Node* currNode)
{
	Node node;

	while (currNode != NULL)
	{
		node = *currNode;
		Csv_manipulator::SaveAll(path, node.GetN(), node.GetV(), node.GetH(), node.GetID());
		currNode = node.GetNext();
	}
}

bool Csv_manipulator::ImportCsv(string path, Chain &block)
{
	vector<Node> nodes;
	int nodesCount = 0;
	nodes = Csv_manipulator::GetNodes(path, nodesCount);

	string checkHash;

	for (int i = 0; i < nodesCount; i++)
	{
		Hash hash;
		if (i == 0)
		{
			checkHash = nodes[i].GetV() + to_string(nodes[i].GetID()) + to_string(0);
		}
		else
		{
			checkHash = nodes[i].GetV() + to_string(nodes[i].GetID()) + nodes[i - 1].GetH();
		}

		if (nodes[i].GetH() == hash.getHash(checkHash, 16))
		{
			block.add(nodes[i]);
		}
		else
		{
			return false;
		}
	}
	return true;
}

