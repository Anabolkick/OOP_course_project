#pragma once
#include <vector>
#include "Set.h"

using namespace std;

class Csv_manipulator
{
public:
	static void SaveAll(string file_name, string name, string vote, string hash, long id);
	static vector<Node> GetNodes(string file_name, int& count);
};