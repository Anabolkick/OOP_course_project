#include <fstream>
#include <json/json.h>
#include <iostream>

using namespace Json;
using namespace std;

static class json_manipulator
{
	static void read_json()
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

	static void create_json()
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

};

