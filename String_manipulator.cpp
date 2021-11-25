#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "String_manipulator.h"

using namespace std;
using namespace System;

static class String_manipulator
{
public:
	static string std_string(String^ str)
	{
		string new_string = msclr::interop::marshal_as<string>(str);
		return 	new_string;
	}

	static String^ system_string(string str)
	{
		String^ new_string = gcnew String(str.c_str());
		return 	new_string;
	}
};
