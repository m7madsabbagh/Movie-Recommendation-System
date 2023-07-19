public ref class LoginHandler {
private:
    MySqlConnection^ con;
    int failedAttempts = 0;  // keep track of failed attempts
    DateTime^ lockoutEnd; // keep track of when the lockout period ends

public:
    LoginHandler() {
        String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
        con = gcnew MySqlConnection(constr);
    }

    String^ logInUser(String^ Username, String^ Password) {
        // Check if we're in a lockout period
        if (lockoutEnd != nullptr && DateTime::Now < *lockoutEnd) {
            return "Wait a few seconds before trying again.";
        }

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
                failedAttempts = 0;  
                SaveUsername(Username);  
                return "Login successful.";
            }
            else {
                failedAttempts++;  
                
                if (failedAttempts >= 5) {
                    lockoutEnd = DateTime::Now.AddSeconds(30);  
                    return "Wait a few seconds before trying again.";
                }
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

    void SaveUsername(System::String^ Username)
    {
        User::Username = msclr::interop::marshal_as<std::string>(Username);
    }
};
