#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include "String_manipulator.h"

using namespace System;
using namespace std;

class String_manipulator
{
public:;
	static string std_string(String^ str);
	static String^ system_string(string str);
	static wstring std_wstring(String^ str);
	static wstring std_wstring(string s_str);
	static string Translit(wstring str);

};
