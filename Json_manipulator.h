#pragma once
#include "Set.h"

class Json_manipulator
{
public:
	static void create_json(Candidates winner, vector<Candidates> participants);
	static void read_json();
};
