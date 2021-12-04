#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Csv_manipulator.h"

using namespace std;

public class Csv_manipulator
{
public:
	static bool add_csv(string file_name, int id, string name, string vote)
	{
		ofstream fout;
		ifstream fin;
		vector<int> all_id;
		string line, id_str;
		int id_int;

		fin.open(file_name);

		if (fin.is_open() == true)
		{
			while (!fin.eof()) //todo check eof  work
			{
				getline(fin, line);
				id_str = line.substr(0, line.find(','));

				//todo try catch atoi
				id_int = atoi(id_str.c_str());
				all_id.push_back(id_int);
			}
		}

		bool IsIdNew = true;
		for (int i = 0; i < all_id.capacity(); i++)
		{
			if (id == all_id[i])
			{
				IsIdNew = false;
			}
		}

		fout.open(file_name, fstream::app);
		if (fout.is_open() && IsIdNew == true)
		{
			fout << id << ','
				<< name << ','
				<< vote << '\n';
		}

		fin.close();    //todo exeptions on not open
		fout.close();
		return IsIdNew;
	}

	static void copy_csv(string from, string to)
	{
		ifstream fin;
		ofstream fout;
		try
		{
			fin.open(from, ios::binary);

			if (fin.is_open() == false)
			{
				throw false;
			}

			try
			{
				fout.open(to, ios::binary);

				if (fin.is_open() == false)
				{
					throw false;
				}

				fout << fin.rdbuf();

				fin.close();
				fout.close();

			}
			catch (bool)
			{
				//new exeption
				/*string ex = "Can`t import file to " + conv_file_name;
				String^ ex_cli = gcnew String(ex.c_str());
				MessageBox::Show(this, ex_cli, "Error 2!", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
			}
		}
		catch (bool)
		{
			//new exeption
			//MessageBox::Show(this, "Can`t open vote_chain.csv!", "Error 1!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	static void read_id_csv(string file_name, int id)
	{
		ifstream fin(file_name);

		if (fin.is_open() == true)
		{
			int curr_id;
			bool done = false;

			vector<string> row;
			string line, word;

			while (!fin.eof()) //todo check eof  work
			{
				row.clear();

				getline(fin, line);

				//Ðàçðåøàåò ðàáîòàòü ñî ñòðîêîé, êàê ñ ïîòîêîì
				stringstream ss(line);
				if (line != "")
				{
					while (getline(ss, word, ','))
					{
						row.push_back(word);
					}

					//Ïûòàåòüñÿ ïðåîáðàçîâàòü â int
					curr_id = stoi(row[0]);            //TODO îøèáêà ïóñòî èëè èùåì ðÿäîê êîòðîãî íåò

					if (curr_id == id)
					{
						done = true;
						cout << "ID: " << row[0] << "\n";
						cout << "Name: " << row[1] << "\n";
						cout << "Age: " << row[2] << "\n";
						cout << "Department: " << row[3] << "\n";
						break;
					}
				}
			}

			if (done == false)
			{
				cout << "Record not found\n";
			}
			fin.close();
		}
	}

};

