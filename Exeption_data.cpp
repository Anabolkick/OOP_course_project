#include "Exeption_data.h"
#include <string>
#include <windows.h>
#include "String_manipulator.cpp"
#using <System.Windows.Forms.dll>
using namespace System::Windows::Forms;

using namespace std;

class Exeption_data
{
private:
    string message_text;
    int error_code;

public:
    Exeption_data(string message, int code)
    {
        message_text = message;
        error_code = code;
    }
  
    String^ getName()
    {
        string str = "Error " + to_string(error_code);
        String^ name = String_manipulator::system_string(str);
        return name;
    }
    String^ getMessage()
    {
        String^ message = String_manipulator::system_string(message_text);
        return  message;
    }
};
