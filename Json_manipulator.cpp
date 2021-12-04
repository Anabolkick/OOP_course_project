#include <fstream>
#include <json/json.h>
#include <iostream>
#include "Json_manipulator.h"
#include "Set.h"

using namespace Json;
using namespace std;


void Json_manipulator::create_json(Candidates winner, vector<Candidates> participants)
{
  ofstream fout;
		fout.open("Winner.json");
		Value root;
		StreamWriterBuilder builder;
		const std::unique_ptr<StreamWriter> writer(builder.newStreamWriter());

		root["participants"] = Json::arrayValue;
		for (int i = 0; i < participants.capacity(); i++)
		{
			root["participants"][i]["name"] = Json::stringValue;
			root["participants"][i]["name"] = participants[i].GetC();
			root["participants"][i]["votes"] = Json::intValue;
			root["participants"][i]["votes"] = participants[i].Geta();
		}

		root["winner"];

		root["winner"]["name"] = Json::stringValue;
		root["winner"]["name"] = winner.GetC();
		root["winner"]["votes"] = Json::intValue;
		root["winner"]["votes"] = winner.Geta();
		int votes_win = winner.Geta();

		writer->write(root, &fout);
}

void Json_manipulator::read_json()
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


