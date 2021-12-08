#pragma once
#include <string>
#include "String_manipulator.h"
#include "Exeption_data.h"

using namespace System;
using namespace std;

class Exeption_data
{
private:
    string message_text;
    int error_code;

public:
    Exeption_data(string message, int code);
    Exeption_data();
    String^ getName();
    String^ getMessage();
    void SetMessage(string message);
    void SetCode(int code);
};

