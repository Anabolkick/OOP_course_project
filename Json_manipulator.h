#pragma once
#include "Set.h"

class Json_manipulator
{
public:
	static void SaveJson(string path, Candidates winner, vector<Candidates> participants);
	static void ReadJson();
};
