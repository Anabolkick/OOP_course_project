#pragma once
#include "Set.h"

class Json_manipulator
{
public:
	static void Save_Json(string path, Candidates winner, vector<Candidates> participants);
	static void Read_Json();
};
