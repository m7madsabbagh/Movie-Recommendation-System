﻿#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
//int main (array＜String^＞^args )
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LoginForm::LoginForm form;
	Application::Run(% form);
	return 0;
}