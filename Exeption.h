#pragma once
#include <string>
#include "String_manipulator.h"
#include "Exeption.h"

using namespace System;
using namespace std;

class Exeption
{
private:
    string message_text;
    int error_code;

public:
    Exeption(string message, int code);
    Exeption();
    String^ getName();
    String^ getMessage();
    void SetMessage(string message);
    void SetCode(int code);
    static void Show_exeption(Exeption ex); 
};

