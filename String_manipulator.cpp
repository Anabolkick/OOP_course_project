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

string String_manipulator::Translit(string str)
{
	string translit;
	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case 'а': translit += "a"; break;
		case 'б': translit += "b"; break;
		case 'в': translit += "v"; break;
		case 'г': translit += "g"; break;
		case 'д': translit += "d"; break;
		case 'е': translit += "e"; break;
		case 'ё': translit += "ye"; break;
		case 'ж': translit += "zh"; break;
		case 'з': translit += "z"; break;
		case 'и': translit += "i"; break;
		case 'й': translit += "y"; break;
		case 'к': translit += "k"; break;
		case 'л': translit += "l"; break;
		case 'м': translit += "m"; break;
		case 'н': translit += "n"; break;
		case 'о': translit += "o"; break;
		case 'п': translit += "p"; break;
		case 'р': translit += "r"; break;
		case 'с': translit += "s"; break;
		case 'т': translit += "t"; break;
		case 'у': translit += "u"; break;
		case 'ф': translit += "f"; break;
		case 'х': translit += "ch"; break;
		case 'ц': translit += "z"; break;
		case 'ч': translit += "ch"; break;
		case 'ш': translit += "sh"; break;
		case 'щ': translit += "ch"; break;
		case 'ъ': translit += ""; break;
		case 'ы': translit += "y"; break;
		case 'ь': translit += ""; break;
		case 'э': translit += "e"; break;
		case 'ю': translit += "yu"; break;
		case 'я': translit += "ya"; break;
		case 'і': translit += "i"; break;
		case 'ї': translit += "yi"; break;
		case 'А': translit += "A"; break;
		case 'Б': translit += "B"; break;
		case 'В': translit += "V"; break;
		case 'Г': translit += "G"; break;
		case 'Д': translit += "D"; break;
		case 'Е': translit += "E"; break;
		case 'Ё': translit += "Ye"; break;
		case 'Ж': translit += "Zh"; break;
		case 'З': translit += "Z"; break;
		case 'И': translit += "I"; break;
		case 'Й': translit += "Y"; break;
		case 'К': translit += "K"; break;
		case 'Л': translit += "L"; break;
		case 'М': translit += "M"; break;
		case 'Н': translit += "N"; break;
		case 'О': translit += "O"; break;
		case 'П': translit += "P"; break;
		case 'Р': translit += "R"; break;
		case 'С': translit += "S"; break;
		case 'Т': translit += "T"; break;
		case 'У': translit += "U"; break;
		case 'Ф': translit += "F"; break;
		case 'Х': translit += "Ch"; break;
		case 'Ц': translit += "Z"; break;
		case 'Ч': translit += "Ch"; break;
		case 'Ш': translit += "Sh"; break;
		case 'Щ': translit += "Ch"; break;
		case 'Ъ': translit += ""; break;
		case 'Ы': translit += "Y"; break;
		case 'Ь': translit += ""; break;
		case 'Э': translit += "E"; break;
		case 'Ю': translit += "Yu"; break;
		case 'Я': translit += "Ya"; break;
		case 'І': translit += "I"; break;
		case 'Ї': translit += "Yi"; break;
		default: {  translit += str[i]; }
		}
	}
	return translit;
}

