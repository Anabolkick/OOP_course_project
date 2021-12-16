#include <fstream>
#include <json/json.h>
#include <iostream>
#include "Json_manipulator.h"
#include "Set.h"

using namespace Json;
using namespace std;


void Json_manipulator::SaveJson(string path, Candidates winner, vector<Candidates> participants)
{
  ofstream fout;
		fout.open(path);
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




