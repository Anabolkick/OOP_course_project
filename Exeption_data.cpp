#include "Exeption_data.h"
#include "String_manipulator.h"
#include <string>

using namespace System;
using namespace std;

Exeption_data::Exeption_data(string message, int code)
{
	message_text = message;
	error_code = code;
}

Exeption_data::Exeption_data()
{
	message_text = "";
	error_code = 0;
}

String^ Exeption_data::getName()
{
	string str = "Error " + to_string(error_code);
	String^ name = String_manipulator::system_string(str);
	return name;
}
String^ Exeption_data::getMessage()
{
	String^ message = String_manipulator::system_string(message_text);
	return  message;
}

void Exeption_data::SetMessage(string message)
{
	message_text = message;
}

void Exeption_data::SetCode(int code)
{
	error_code = code;
}
