#include "Registration.h"

RegistrationHandler::RegistrationHandler()
{
    String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";  
    con = gcnew MySqlConnection(constr);
}

String^ RegistrationHandler::registerUser(String^ Email, String^ Username, String^ Password, bool Action, bool Adventure, bool Animation, bool Comedy, bool Drama, bool Fantasy, bool History, bool Horror, bool Mystery, bool Romance, bool SciFi, bool Thriller)
{
    try
    {
        MySqlCommand^ cmdCheckEmail = gcnew MySqlCommand("SELECT * FROM user_reg WHERE Email = @Email", con);
        cmdCheckEmail->Parameters->AddWithValue("@Email", Email);

        MySqlCommand^ cmdCheckUsername = gcnew MySqlCommand("SELECT * FROM user_reg WHERE Username = @Username", con);
        cmdCheckUsername->Parameters->AddWithValue("@Username", Username);

        con->Open();

        MySqlDataReader^ drEmail = cmdCheckEmail->ExecuteReader();
        bool emailExists = drEmail->HasRows;
        drEmail->Close();

        MySqlDataReader^ drUsername = cmdCheckUsername->ExecuteReader();
        bool usernameExists = drUsername->HasRows;
        drUsername->Close();

        if (emailExists)
        {
            return "Email already in use";
        }
        else if (usernameExists)
        {
            return "Username already in use";
        }

        else
        {
            MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO user_reg (Email, Username, Password, Action, Adventure, Animation, Comedy, Drama, Fantasy, History, Horror, Mystery, Romance, SciFi, Thriller) VALUES (@Email, @Username, @Password, @Action, @Adventure, @Animation, @Comedy, @Drama, @Fantasy, @History, @Horror, @Mystery, @Romance, @SciFi, @Thriller)", con);

            cmd->Parameters->AddWithValue("@Email", Email);
            cmd->Parameters->AddWithValue("@Username", Username);
            cmd->Parameters->AddWithValue("@Password", Password);
            cmd->Parameters->AddWithValue("@Action", Action);
            cmd->Parameters->AddWithValue("@Adventure", Adventure);
            cmd->Parameters->AddWithValue("@Animation", Animation);
            cmd->Parameters->AddWithValue("@Comedy", Comedy);
            cmd->Parameters->AddWithValue("@Drama", Drama);
            cmd->Parameters->AddWithValue("@Fantasy", Fantasy);
            cmd->Parameters->AddWithValue("@History", History);
            cmd->Parameters->AddWithValue("@Horror", Horror);
            cmd->Parameters->AddWithValue("@Mystery", Mystery);
            cmd->Parameters->AddWithValue("@Romance", Romance);
            cmd->Parameters->AddWithValue("@SciFi", SciFi);
            cmd->Parameters->AddWithValue("@Thriller", Thriller);

            cmd->ExecuteNonQuery();

            return "Sign up success, please go to the login page";
        }
    }
    catch (Exception^ ex)
    {
        return ex->Message;
    }
    finally
    {
        if (con->State == ConnectionState::Open)
            con->Close();
    }
}
