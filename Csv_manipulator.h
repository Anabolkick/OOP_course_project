#pragma once
#include <vector>
#include "Set.h"

using namespace std;

class Csv_manipulator
{
private:
	static void SaveAll(string file_name, string name, string vote, string hash, long id);
	static vector<Node> GetNodes(string file_name, int& count);
public:	
	static bool ImportCsv(string path, Chain& block);
	static void SaveCsv(string path, Node* currNode);
};