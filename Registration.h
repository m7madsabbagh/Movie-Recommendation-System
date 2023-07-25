#pragma once

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

public ref class RegistrationHandler
{
private:
    MySqlConnection^ con;

public:
    RegistrationHandler();
    String^ registerUser(String^ Email, String^ Username, String^ Password, bool Action, bool Adventure, bool Animation, bool Comedy, bool Drama, bool Fantasy, bool History, bool Horror, bool Mystery, bool Romance, bool SciFi, bool Thriller);
};
