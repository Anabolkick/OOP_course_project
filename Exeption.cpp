#include "Exeption.h"
#include "String_manipulator.h"
#include <string>
#include <windows.h>
#include <warning.h>
#using <System.Windows.Forms.dll>

using namespace System::Windows::Forms;
using namespace System;
using namespace std;

Exeption::Exeption(string message, int code)
{
	message_text = message;
	error_code = code;
}

Exeption::Exeption()
{
	message_text = "";
	error_code = 0;
}

void Exeption::Show_exeption(Exeption ex)
{
	String^ name = ex.getName();
	String^ message = ex.getMessage();
	MessageBox::Show(message, name, MessageBoxButtons::OK, MessageBoxIcon::Warning);
}

String^ Exeption::getName()
{
	string str = "Помилка " + to_string(error_code);
	String^ name = String_manipulator::system_string(str);
	return name;
}
String^ Exeption::getMessage()
{
	String^ message = String_manipulator::system_string(message_text);
	return  message;
}

void Exeption::SetMessage(string message)
{
	message_text = message;
}

void Exeption::SetCode(int code)
{
	error_code = code;
}
