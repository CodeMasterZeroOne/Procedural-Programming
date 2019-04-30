#include "Payroll.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Project name :: and form name
	PawelPayroll::Payroll form;
	Application::Run(% form);
}