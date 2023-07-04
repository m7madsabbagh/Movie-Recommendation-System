
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net::Mail;
using namespace MySql::Data::MySqlClient;

public ref class PasswordResetter
{
public:
    PasswordResetter() {}

    void sendResetEmail(String^ Username, MySqlConnection^ con, String^% OTP)
    {
        try
        {
            //to generate random otp
            Random^ r = gcnew Random();
            OTP = r->Next(100000, 9999999).ToString();

            String^ usrmn = "mohammed.ihab2016@gmail.com";
            String^ password = "bpgyisrkolrwzuym";
            String^ to;
            String^ from = "mohammed.ihab2016@gmail.com";
            String^ subject = "OTP reset password";
            String^ msg = "Hi " + Username + "," + "\n" + "Your OTP is: " + OTP;

            MySqlCommand^ cmd = gcnew MySqlCommand("select * from user_reg where Username = '" + Username + "';", con);
            MySqlDataReader^ dr;
            con->Open();
            dr = cmd->ExecuteReader();
            while (dr->Read())
            {
                to = dr->GetString(0);
            }
            con->Close();
            try
            {
                MailMessage^ mail = gcnew MailMessage(from, to, subject, msg);
                SmtpClient^ client = gcnew SmtpClient("smtp.gmail.com");
                client->Port = 587;
                client->Credentials = gcnew System::Net::NetworkCredential(usrmn, password);
                client->EnableSsl = true;
                client->Send(mail);
                MessageBox::Show("OTP sent!", "success", MessageBoxButtons::OK);
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message);
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(ex->Message);
        }
    }
};
