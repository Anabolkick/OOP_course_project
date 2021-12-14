#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Csv_manipulator.h"
#include "Set.h"

using namespace std;

void Csv_manipulator::SaveRow(string file_name, ofstream& fout, string name, string vote, string hash, long id)
{
	fout << name << ','
		<< vote << ','
		<< hash << ','
		<< id << '\n';
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
	ofstream fout;
	fout.open(path);

	if (fout.is_open())
	{
		while (currNode != NULL)
		{
			node = *currNode;
			Csv_manipulator::SaveRow(path, fout, node.GetN(), node.GetV(), node.GetH(), node.GetID());
			currNode = node.GetNext();
		}
	}
}

Csv_manipulator::FileStatus Csv_manipulator::ImportCsv(string path, Chain& block)
{
	FileStatus status = FileStatus::opened;
	vector<Node> nodes;
	int nodesCount = 0;
	nodes = Csv_manipulator::GetNodes(path, nodesCount);

	string checkHash;

	if (nodesCount <= 0)
	{
		status = FileStatus::absent;
		return status;
	}

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
			status = FileStatus::changed;
			return status;
		}
	}
	return status;
}

