#include <iostream>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "String_manipulator.h"
#include <codecvt>


using namespace System;
using namespace System::Configuration;
using namespace std;

string String_manipulator::std_string(String^ str)
{
	string new_string = msclr::interop::marshal_as<string>(str);
	return 	new_string;
}

String^ String_manipulator::system_string(string str)
{
	String^ new_string = gcnew String(str.c_str());
	return 	new_string;
}

wstring String_manipulator::std_wstring(String^ str)
{
	System::String^ managedString = str;

	msclr::interop::marshal_context context;

	//Actual format is UTF16, so represent as wstring
	std::wstring utf16NativeString = context.marshal_as<std::wstring>(managedString);

	return 	utf16NativeString;

}

