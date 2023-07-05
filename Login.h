



using namespace MySql::Data::MySqlClient;
using namespace System;

public ref class LoginHandler {
private:
    MySqlConnection^ con;
public:
    LoginHandler() {
        String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
        con = gcnew MySqlConnection(constr);
    }

    String^ logInUser(String^ Username, String^ Password) {
        MySqlCommand^ cmd = gcnew MySqlCommand("select * from user_reg where Username=@Username and Password=@Password", con);
        cmd->Parameters->AddWithValue("@Username", Username);
        cmd->Parameters->AddWithValue("@Password", Password);

        MySqlDataReader^ dr;
        con->Open();

        try {
            dr = cmd->ExecuteReader();
            int count = 0;
            while (dr->Read()) {
                count += 1;
            }
            if (count == 1) {
                return "Login successful.";
            }
            else {
                return "Username or password is incorrect.\nPlease try again";
            }
        }
        catch (Exception^ ex) {
            return ex->Message;
        }
        finally {
            con->Close();
        }
    }
};
