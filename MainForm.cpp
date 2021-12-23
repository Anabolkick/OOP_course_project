#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//ProjectName - name of your project
	//NameForm - name of the form to run
	Project1::MainForm form;
	Application::Run(% form);
}