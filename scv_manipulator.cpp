#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

public class scv_manipulator
{
public:
	static void add_csv(string file_name, int id, string name, string vote)
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

		bool found = false;
		for (int i = 0; i < all_id.capacity(); i++)
		{
			if (id == all_id[i])
			{
				found = true;
			}
		}

		fout.open(file_name, fstream::app);
		if (fout.is_open() && found == false)
		{
			fout << id << ','
				<< name << ','
				<< vote << '\n';
		}

		fin.close();    //todo exeptions on not open
		fout.close();

	}

	void read_id_csv(string file_name, int id)
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

				//–азрешает работать со строкой, как с потоком
				stringstream ss(line);
				if (line != "")
				{
					while (getline(ss, word, ','))
					{
						row.push_back(word);
					}

					//ѕытаетьс€ преобразовать в int
					curr_id = stoi(row[0]);            //TODO ошибка пусто или ищем р€док котрого нет

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

