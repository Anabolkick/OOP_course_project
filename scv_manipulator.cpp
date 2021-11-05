#include "scv_manipulator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <json/json.h>

using namespace Json;
using namespace std;

void read_id_csv(string file, int id);
void add_csv(string file, int id, string name, int age, string department);
void read_json();
void create_json();

//int main()
//{
//	//read_csv();
//   // read_json();
//   // create_json();
//   // create_csv();
//	add_csv("Text.csv", 4889, "Oleg", 19, "It");
//	read_id_csv("Text.csv", 4889);
//
//}

void add_csv(string file_name, int id, string name, int age, string department)
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
				<< age << ','
				<< department << '\n';
		}
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

void read_json()
{
	ifstream fin("Winner.json");
	Value root;
	JSONCPP_STRING errs;
	CharReaderBuilder builder;
	builder["collectComments"] = true;
	bool success = parseFromStream(builder, fin, &root, &errs);
	if (!success)
	{
		cout << errs << std::endl;
		//TODO catch exeption
	}
	cout << "Winner: " << root["winner"] << '\n';

	Value partic = root["participants"];

	for (int index = 0; index < partic.size(); ++index)
	{
		cout << partic[index]["name"] << endl;
	}
}

void create_json()
{
	ofstream fout;
	fout.open("Winner.json");
	Value root;
	StreamWriterBuilder builder;
	const std::unique_ptr<StreamWriter> writer(builder.newStreamWriter());

	root["participants"] = Json::arrayValue;
	root["participants"][0]["age"] = "18";
	root["participants"][0]["name"] = "Ivan";
	root["participants"][1]["name"] = "Lera";
	root["participants"][1]["age"] = "22";

	writer->write(root, &fout);
}

