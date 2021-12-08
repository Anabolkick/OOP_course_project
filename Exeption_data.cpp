#include "Exeption_data.h"
#include <string>
#include <windows.h>
#include "String_manipulator.h"

using namespace System::Windows::Forms;

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

    Exeption_data()
    {
        message_text = "";
        error_code = 0;
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

    void SetMessage(string message)
    {
        message_text = message;
    }

    void SetCode(int code)
    {
        error_code = code;
    }
};
