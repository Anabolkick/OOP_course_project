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
	wstring new_string = msclr::interop::marshal_as<wstring>(str);
	return 	new_string;
}

wstring String_manipulator::std_wstring(string str)
{
	String^ sys_str = String_manipulator::system_string(str);
	wstring new_string = msclr::interop::marshal_as<wstring>(sys_str);
	return 	new_string;
}

string String_manipulator::Translit(wstring wstr)
{
	string str;
	for (int i = 0; i < wstr.size(); i++)
	{
		switch (wstr[i])
		{
		case 'а': str += "a"; break;
		case 'б': str += "b"; break;
		case 'в': str += "v"; break;
		case 'г': str += "g"; break;
		case 'д': str += "d"; break;
		case 'е': str += "e"; break;
		case 'ё': str += "ye"; break;
		case 'ж': str += "zh"; break;
		case 'з': str += "z"; break;
		case 'и': str += "i"; break;
		case 'й': str += "y"; break;
		case 'к': str += "k"; break;
		case 'л': str += "l"; break;
		case 'м': str += "m"; break;
		case 'н': str += "n"; break;
		case 'о': str += "o"; break;
		case 'п': str += "p"; break;
		case 'р': str += "r"; break;
		case 'с': str += "s"; break;
		case 'т': str += "t"; break;
		case 'у': str += "u"; break;
		case 'ф': str += "f"; break;
		case 'х': str += "ch"; break;
		case 'ц': str += "z"; break;
		case 'ч': str += "ch"; break;
		case 'ш': str += "sh"; break;
		case 'щ': str += "ch"; break;
		case 'ъ': str += ""; break;
		case 'ы': str += "y"; break;
		case 'ь': str += ""; break;
		case 'э': str += "e"; break;
		case 'ю': str += "yu"; break;
		case 'я': str += "ya"; break;
		case 'і': str += "i"; break;
		case 'ї': str += "yi"; break;
		case 'А': str += "A"; break;
		case 'Б': str += "B"; break;
		case 'В': str += "V"; break;
		case 'Г': str += "G"; break;
		case 'Д': str += "D"; break;
		case 'Е': str += "E"; break;
		case 'Ё': str += "Ye"; break;
		case 'Ж': str += "Zh"; break;
		case 'З': str += "Z"; break;
		case 'И': str += "I"; break;
		case 'Й': str += "Y"; break;
		case 'К': str += "K"; break;
		case 'Л': str += "L"; break;
		case 'М': str += "M"; break;
		case 'Н': str += "N"; break;
		case 'О': str += "O"; break;
		case 'П': str += "P"; break;
		case 'Р': str += "R"; break;
		case 'С': str += "S"; break;
		case 'Т': str += "T"; break;
		case 'У': str += "U"; break;
		case 'Ф': str += "F"; break;
		case 'Х': str += "Ch"; break;
		case 'Ц': str += "Z"; break;
		case 'Ч': str += "Ch"; break;
		case 'Ш': str += "Sh"; break;
		case 'Щ': str += "Ch"; break;
		case 'Ъ': str += ""; break;
		case 'Ы': str += "Y"; break;
		case 'Ь': str += ""; break;
		case 'Э': str += "E"; break;
		case 'Ю': str += "Yu"; break;
		case 'Я': str += "Ya"; break;
		case 'І': str += "I"; break;
		case 'Ї': str += "Yi"; break;
		default: {  str += wstr[i]; }
		}
	}
	return str;
}

