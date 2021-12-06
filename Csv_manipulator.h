#pragma once
#include <vector>
#include "Set.h"

using namespace std;

class Csv_manipulator
{
private:
	static void SaveRow(string file_name, ofstream& fout, string name, string vote, string hash, long id);
	static vector<Node> GetNodes(string file_name, int& count);

public:	
	enum FileStatus
	{
		opened,
		changed,
		absent
	};
	static FileStatus ImportCsv(string path, Chain& block);
	static void SaveCsv(string path, Node* currNode);

	

};