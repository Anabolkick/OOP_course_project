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
	string translit;
	for (int i = 0; i < wstr.size(); i++)
	{
		switch (wstr[i])
		{
		case L'а': translit += "a"; break;
		case L'б': translit += "b"; break;
		case L'в': translit += "v"; break;
		case L'г': translit += "g"; break;
		case L'д': translit += "d"; break;
		case L'е': translit += "e"; break;
		case L'ё': translit += "ye"; break;
		case L'ж': translit += "zh"; break;
		case L'з': translit += "z"; break;
		case L'и': translit += "i"; break;
		case L'й': translit += "y"; break;
		case L'к': translit += "k"; break;
		case L'л': translit += "l"; break;
		case L'м': translit += "m"; break;
		case L'н': translit += "n"; break;
		case L'о': translit += "o"; break;
		case L'п': translit += "p"; break;
		case L'р': translit += "r"; break;
		case L'с': translit += "s"; break;
		case L'т': translit += "t"; break;
		case L'у': translit += "u"; break;
		case L'ф': translit += "f"; break;
		case L'х': translit += "ch"; break;
		case L'ц': translit += "z"; break;
		case L'ч': translit += "ch"; break;
		case L'ш': translit += "sh"; break;
		case L'щ': translit += "ch"; break;
		case L'ъ': translit += ""; break;
		case L'ы': translit += "y"; break;
		case L'ь': translit += ""; break;
		case L'э': translit += "e"; break;
		case L'ю': translit += "yu"; break;
		case L'я': translit += "ya"; break;
		case L'і': translit += "i"; break;
		case L'ї': translit += "yi"; break;
		case L'А': translit += "A"; break;
		case L'Б': translit += "B"; break;
		case L'В': translit += "V"; break;
		case L'Г': translit += "G"; break;
		case L'Д': translit += "D"; break;
		case L'Е': translit += "E"; break;
		case L'Ё': translit += "Ye"; break;
		case L'Ж': translit += "Zh"; break;
		case L'З': translit += "Z"; break;
		case L'И': translit += "I"; break;
		case L'Й': translit += "Y"; break;
		case L'К': translit += "K"; break;
		case L'Л': translit += "L"; break;
		case L'М': translit += "M"; break;
		case L'Н': translit += "N"; break;
		case L'О': translit += "O"; break;
		case L'П': translit += "P"; break;
		case L'Р': translit += "R"; break;
		case L'С': translit += "S"; break;
		case L'Т': translit += "T"; break;
		case L'У': translit += "U"; break;
		case L'Ф': translit += "F"; break;
		case L'Х': translit += "Ch"; break;
		case L'Ц': translit += "Z"; break;
		case L'Ч': translit += "Ch"; break;
		case L'Ш': translit += "Sh"; break;
		case L'Щ': translit += "Ch"; break;
		case L'Ъ': translit += ""; break;
		case L'Ы': translit += "Y"; break;
		case L'Ь': translit += ""; break;
		case L'Э': translit += "E"; break;
		case L'Ю': translit += "Yu"; break;
		case L'Я': translit += "Ya"; break;
		case L'І': translit += "I"; break;
		case L'Ї': translit += "Yi"; break;
		default: {  translit += wstr[i]; }
		}
	}
	return translit;
}

