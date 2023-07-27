#pragma once
#include "MainPage.h"
#include "LoginForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;

void LoginForm::MainPage::logoutButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    LoginForm^ loginForm = gcnew LoginForm();
    loginForm->Show();
    this->Close();
}

[STAThread]
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Enable visual styles for Windows Forms application
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create the main form (MainPage)
    LoginForm::MainPage mainPage;

    // Run the application
    Application::Run(% mainPage);

    return 0;
}
