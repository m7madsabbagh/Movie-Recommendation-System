

namespace LoginForm {

    public ref class Overview : public System::Windows::Forms::Form
    {
    public:
        Overview(System::String^ title, System::String^ overview, System::String^ posterPath, System::String^ release_date, double rating);

    private:
        System::Windows::Forms::Button^ saveButton;
        System::String^ Username;
        System::String^ MovieID;
        System::Windows::Forms::Label^ titleLabel;
        System::Windows::Forms::Label^ overviewLabel;
        System::Windows::Forms::Label^ releaseDateLabel;
        System::Windows::Forms::Label^ ratingLabel;
        System::Windows::Forms::PictureBox^ posterPictureBox;

        System::Windows::Forms::Label^ CreateLabel(System::String^ text);




        System::Void InitializeComponent() {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Overview::typeid));
            this->SuspendLayout();

            // Overview

            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(500, 562);
            this->Name = L"Overview";
            this->ResumeLayout(false);


        }

        System::Void SaveMovieButton_Click(System::Object^ sender, System::EventArgs^ e);

    };

}

