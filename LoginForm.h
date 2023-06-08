#pragma once

namespace LoginForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		String^ server = "Server=127.0.0.1;Uid=root;Pwd=your_password_here;Database=Database";
	private: System::Windows::Forms::Panel^ panel3;
	public:
	private: Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton25;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox9;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox10;
	private: Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton24;
	private: Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton23;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox7;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox8;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;

	public:








		   MySqlConnection^ con = gcnew MySqlConnection(server);
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox1;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox2;
	private: Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton21;
	private: System::Windows::Forms::LinkLabel^ linkLabel2;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::LinkLabel^ linkLabel4;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox6;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox5;
	private: System::Windows::Forms::LinkLabel^ linkLabel3;
	private: Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton22;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox3;
	private: Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox4;
	private: System::Windows::Forms::Label^ label2;
	private: Bunifu::Framework::UI::BunifuImageButton^ bunifuImageButton1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->bunifuThinButton21 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuTextbox2 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuTextbox1 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->linkLabel4 = (gcnew System::Windows::Forms::LinkLabel());
			this->bunifuTextbox6 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuTextbox5 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
			this->bunifuThinButton22 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuTextbox3 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuTextbox4 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->bunifuThinButton25 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuTextbox9 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuTextbox10 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuThinButton24 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuThinButton23 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuTextbox7 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuTextbox8 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->linkLabel1);
			this->panel1->Controls->Add(this->linkLabel2);
			this->panel1->Controls->Add(this->bunifuThinButton21);
			this->panel1->Controls->Add(this->bunifuTextbox2);
			this->panel1->Controls->Add(this->bunifuTextbox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(222, 88);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(391, 565);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panel1_Paint_1);
			// 
			// linkLabel1
			// 
		

			this->linkLabel1->ActiveLinkColor = System::Drawing::Color::MidnightBlue;
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->LinkColor = System::Drawing::Color::White;
			this->linkLabel1->Location = System::Drawing::Point(189, 349);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(91, 13);
			this->linkLabel1->TabIndex = 6;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Forgot password\?";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel1_LinkClicked_1);
			// 
			// linkLabel2
			// 
			this->linkLabel2->ActiveLinkColor = System::Drawing::Color::MidnightBlue;
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->LinkColor = System::Drawing::Color::White;
			this->linkLabel2->Location = System::Drawing::Point(128, 489);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(122, 13);
			this->linkLabel2->TabIndex = 5;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"Don\'t have an account\?";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel2_LinkClicked);
			// 
			// bunifuThinButton21
			// 
			this->bunifuThinButton21->ActiveBorderThickness = 1;
			this->bunifuThinButton21->ActiveCornerRadius = 20;
			this->bunifuThinButton21->ActiveFillColor = System::Drawing::Color::White;
			this->bunifuThinButton21->ActiveForecolor = System::Drawing::Color::White;
			this->bunifuThinButton21->ActiveLineColor = System::Drawing::Color::Honeydew;
			this->bunifuThinButton21->BackColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton21.BackgroundImage")));
			this->bunifuThinButton21->ButtonText = L"Log in";
			this->bunifuThinButton21->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->bunifuThinButton21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton21->ForeColor = System::Drawing::Color::White;
			this->bunifuThinButton21->IdleBorderThickness = 1;
			this->bunifuThinButton21->IdleCornerRadius = 20;
			this->bunifuThinButton21->IdleFillColor = System::Drawing::Color::White;
			this->bunifuThinButton21->IdleForecolor = System::Drawing::Color::Black;
			this->bunifuThinButton21->IdleLineColor = System::Drawing::Color::Black;
			this->bunifuThinButton21->Location = System::Drawing::Point(106, 420);
			this->bunifuThinButton21->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton21->Name = L"bunifuThinButton21";
			this->bunifuThinButton21->Size = System::Drawing::Size(181, 49);
			this->bunifuThinButton21->TabIndex = 3;
			this->bunifuThinButton21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton21->Click += gcnew System::EventHandler(this, &LoginForm::bunifuThinButton21_Click);
			// 
			// bunifuTextbox2
			// 
			this->bunifuTextbox2->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox2.BackgroundImage")));
			this->bunifuTextbox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox2->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox2->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox2.Icon")));
			this->bunifuTextbox2->Location = System::Drawing::Point(71, 281);
			this->bunifuTextbox2->Name = L"bunifuTextbox2";
			this->bunifuTextbox2->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox2->TabIndex = 2;
			this->bunifuTextbox2->text = L"Password";
			// 
			// bunifuTextbox1
			// 
			this->bunifuTextbox1->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox1.BackgroundImage")));
			this->bunifuTextbox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox1->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox1->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox1.Icon")));
			this->bunifuTextbox1->Location = System::Drawing::Point(71, 205);
			this->bunifuTextbox1->Name = L"bunifuTextbox1";
			this->bunifuTextbox1->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox1->TabIndex = 1;
			this->bunifuTextbox1->text = L"Username";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(116, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in";
			this->label1->Click += gcnew System::EventHandler(this, &LoginForm::label1_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->bunifuImageButton1);
			this->panel2->Controls->Add(this->linkLabel4);
			this->panel2->Controls->Add(this->bunifuTextbox6);
			this->panel2->Controls->Add(this->bunifuTextbox5);
			this->panel2->Controls->Add(this->linkLabel3);
			this->panel2->Controls->Add(this->bunifuThinButton22);
			this->panel2->Controls->Add(this->bunifuTextbox3);
			this->panel2->Controls->Add(this->bunifuTextbox4);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(566, 91);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(391, 565);
			this->panel2->TabIndex = 1;
			this->panel2->Visible = false;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panel1_Paint);
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(0, 0);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(71, 71);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 6;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &LoginForm::bunifuImageButton1_Click);
			// 
			// linkLabel4
			// 
			this->linkLabel4->ActiveLinkColor = System::Drawing::Color::MidnightBlue;
			this->linkLabel4->AutoSize = true;
			this->linkLabel4->LinkColor = System::Drawing::Color::White;
			this->linkLabel4->Location = System::Drawing::Point(128, 443);
			this->linkLabel4->Name = L"linkLabel4";
			this->linkLabel4->Size = System::Drawing::Size(132, 13);
			this->linkLabel4->TabIndex = 8;
			this->linkLabel4->TabStop = true;
			this->linkLabel4->Text = L"Already have an account\?";
			this->linkLabel4->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel4_LinkClicked);
			// 
			// bunifuTextbox6
			// 
			this->bunifuTextbox6->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox6.BackgroundImage")));
			this->bunifuTextbox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox6->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox6->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox6.Icon")));
			this->bunifuTextbox6->Location = System::Drawing::Point(71, 168);
			this->bunifuTextbox6->Name = L"bunifuTextbox6";
			this->bunifuTextbox6->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox6->TabIndex = 7;
			this->bunifuTextbox6->text = L"Email";
			// 
			// bunifuTextbox5
			// 
			this->bunifuTextbox5->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox5.BackgroundImage")));
			this->bunifuTextbox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox5->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox5->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox5.Icon")));
			this->bunifuTextbox5->Location = System::Drawing::Point(71, 365);
			this->bunifuTextbox5->Name = L"bunifuTextbox5";
			this->bunifuTextbox5->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox5->TabIndex = 6;
			this->bunifuTextbox5->text = L"Confirm Password";
			// 
			// linkLabel3
			// 
			this->linkLabel3->ActiveLinkColor = System::Drawing::Color::MidnightBlue;
			this->linkLabel3->AutoSize = true;
			this->linkLabel3->LinkColor = System::Drawing::Color::White;
			this->linkLabel3->Location = System::Drawing::Point(128, 489);
			this->linkLabel3->Name = L"linkLabel3";
			this->linkLabel3->Size = System::Drawing::Size(0, 13);
			this->linkLabel3->TabIndex = 5;
			// 
			// bunifuThinButton22
			// 
			this->bunifuThinButton22->ActiveBorderThickness = 1;
			this->bunifuThinButton22->ActiveCornerRadius = 20;
			this->bunifuThinButton22->ActiveFillColor = System::Drawing::Color::White;
			this->bunifuThinButton22->ActiveForecolor = System::Drawing::Color::White;
			this->bunifuThinButton22->ActiveLineColor = System::Drawing::Color::Honeydew;
			this->bunifuThinButton22->BackColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton22->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton22.BackgroundImage")));
			this->bunifuThinButton22->ButtonText = L"Register";
			this->bunifuThinButton22->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->bunifuThinButton22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton22->ForeColor = System::Drawing::Color::White;
			this->bunifuThinButton22->IdleBorderThickness = 1;
			this->bunifuThinButton22->IdleCornerRadius = 20;
			this->bunifuThinButton22->IdleFillColor = System::Drawing::Color::White;
			this->bunifuThinButton22->IdleForecolor = System::Drawing::Color::Black;
			this->bunifuThinButton22->IdleLineColor = System::Drawing::Color::Black;
			this->bunifuThinButton22->Location = System::Drawing::Point(110, 489);
			this->bunifuThinButton22->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton22->Name = L"bunifuThinButton22";
			this->bunifuThinButton22->Size = System::Drawing::Size(181, 49);
			this->bunifuThinButton22->TabIndex = 3;
			this->bunifuThinButton22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton22->Click += gcnew System::EventHandler(this, &LoginForm::bunifuThinButton22_Click);
			// 
			// bunifuTextbox3
			// 
			this->bunifuTextbox3->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox3.BackgroundImage")));
			this->bunifuTextbox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox3->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox3->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox3.Icon")));
			this->bunifuTextbox3->Location = System::Drawing::Point(71, 301);
			this->bunifuTextbox3->Name = L"bunifuTextbox3";
			this->bunifuTextbox3->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox3->TabIndex = 2;
			this->bunifuTextbox3->text = L"Password";
			// 
			// bunifuTextbox4
			// 
			this->bunifuTextbox4->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox4.BackgroundImage")));
			this->bunifuTextbox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox4->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox4->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox4.Icon")));
			this->bunifuTextbox4->Location = System::Drawing::Point(71, 238);
			this->bunifuTextbox4->Name = L"bunifuTextbox4";
			this->bunifuTextbox4->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox4->TabIndex = 1;
			this->bunifuTextbox4->text = L"Username";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(116, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 42);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Sign up";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel3->Controls->Add(this->bunifuThinButton25);
			this->panel3->Controls->Add(this->bunifuTextbox9);
			this->panel3->Controls->Add(this->bunifuTextbox10);
			this->panel3->Controls->Add(this->bunifuThinButton24);
			this->panel3->Controls->Add(this->bunifuThinButton23);
			this->panel3->Controls->Add(this->bunifuTextbox7);
			this->panel3->Controls->Add(this->bunifuTextbox8);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(991, 108);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(391, 565);
			this->panel3->TabIndex = 3;
			// 
			// bunifuThinButton25
			// 
			this->bunifuThinButton25->ActiveBorderThickness = 1;
			this->bunifuThinButton25->ActiveCornerRadius = 20;
			this->bunifuThinButton25->ActiveFillColor = System::Drawing::Color::White;
			this->bunifuThinButton25->ActiveForecolor = System::Drawing::Color::White;
			this->bunifuThinButton25->ActiveLineColor = System::Drawing::Color::Honeydew;
			this->bunifuThinButton25->BackColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton25->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton25.BackgroundImage")));
			this->bunifuThinButton25->ButtonText = L"Back";
			this->bunifuThinButton25->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->bunifuThinButton25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton25->ForeColor = System::Drawing::Color::White;
			this->bunifuThinButton25->IdleBorderThickness = 1;
			this->bunifuThinButton25->IdleCornerRadius = 20;
			this->bunifuThinButton25->IdleFillColor = System::Drawing::Color::White;
			this->bunifuThinButton25->IdleForecolor = System::Drawing::Color::Black;
			this->bunifuThinButton25->IdleLineColor = System::Drawing::Color::Black;
			this->bunifuThinButton25->Location = System::Drawing::Point(49, 489);
			this->bunifuThinButton25->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton25->Name = L"bunifuThinButton25";
			this->bunifuThinButton25->Size = System::Drawing::Size(137, 49);
			this->bunifuThinButton25->TabIndex = 9;
			this->bunifuThinButton25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton25->Click += gcnew System::EventHandler(this, &LoginForm::bunifuThinButton25_Click_1);
			// 
			// bunifuTextbox9
			// 
			this->bunifuTextbox9->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox9.BackgroundImage")));
			this->bunifuTextbox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox9->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox9->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox9.Icon")));
			this->bunifuTextbox9->Location = System::Drawing::Point(71, 425);
			this->bunifuTextbox9->Name = L"bunifuTextbox9";
			this->bunifuTextbox9->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox9->TabIndex = 8;
			this->bunifuTextbox9->text = L"Confirm Password";
			// 
			// bunifuTextbox10
			// 
			this->bunifuTextbox10->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox10.BackgroundImage")));
			this->bunifuTextbox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox10->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox10->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox10.Icon")));
			this->bunifuTextbox10->Location = System::Drawing::Point(71, 377);
			this->bunifuTextbox10->Name = L"bunifuTextbox10";
			this->bunifuTextbox10->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox10->TabIndex = 7;
			this->bunifuTextbox10->text = L"Password";
			// 
			// bunifuThinButton24
			// 
			this->bunifuThinButton24->ActiveBorderThickness = 1;
			this->bunifuThinButton24->ActiveCornerRadius = 20;
			this->bunifuThinButton24->ActiveFillColor = System::Drawing::Color::White;
			this->bunifuThinButton24->ActiveForecolor = System::Drawing::Color::White;
			this->bunifuThinButton24->ActiveLineColor = System::Drawing::Color::Honeydew;
			this->bunifuThinButton24->BackColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton24->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton24.BackgroundImage")));
			this->bunifuThinButton24->ButtonText = L"Send OTP";
			this->bunifuThinButton24->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->bunifuThinButton24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton24->ForeColor = System::Drawing::Color::White;
			this->bunifuThinButton24->IdleBorderThickness = 1;
			this->bunifuThinButton24->IdleCornerRadius = 20;
			this->bunifuThinButton24->IdleFillColor = System::Drawing::Color::White;
			this->bunifuThinButton24->IdleForecolor = System::Drawing::Color::Black;
			this->bunifuThinButton24->IdleLineColor = System::Drawing::Color::Black;
			this->bunifuThinButton24->Location = System::Drawing::Point(106, 220);
			this->bunifuThinButton24->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton24->Name = L"bunifuThinButton24";
			this->bunifuThinButton24->Size = System::Drawing::Size(181, 49);
			this->bunifuThinButton24->TabIndex = 4;
			this->bunifuThinButton24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bunifuThinButton23
			// 
			this->bunifuThinButton23->ActiveBorderThickness = 1;
			this->bunifuThinButton23->ActiveCornerRadius = 20;
			this->bunifuThinButton23->ActiveFillColor = System::Drawing::Color::White;
			this->bunifuThinButton23->ActiveForecolor = System::Drawing::Color::White;
			this->bunifuThinButton23->ActiveLineColor = System::Drawing::Color::Honeydew;
			this->bunifuThinButton23->BackColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton23->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton23.BackgroundImage")));
			this->bunifuThinButton23->ButtonText = L"Reset";
			this->bunifuThinButton23->Cursor = System::Windows::Forms::Cursors::AppStarting;
			this->bunifuThinButton23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton23->ForeColor = System::Drawing::Color::White;
			this->bunifuThinButton23->IdleBorderThickness = 1;
			this->bunifuThinButton23->IdleCornerRadius = 20;
			this->bunifuThinButton23->IdleFillColor = System::Drawing::Color::White;
			this->bunifuThinButton23->IdleForecolor = System::Drawing::Color::Black;
			this->bunifuThinButton23->IdleLineColor = System::Drawing::Color::Black;
			this->bunifuThinButton23->Location = System::Drawing::Point(195, 489);
			this->bunifuThinButton23->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton23->Name = L"bunifuThinButton23";
			this->bunifuThinButton23->Size = System::Drawing::Size(141, 49);
			this->bunifuThinButton23->TabIndex = 3;
			this->bunifuThinButton23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bunifuTextbox7
			// 
			this->bunifuTextbox7->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox7.BackgroundImage")));
			this->bunifuTextbox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox7->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox7->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox7.Icon")));
			this->bunifuTextbox7->Location = System::Drawing::Point(71, 329);
			this->bunifuTextbox7->Name = L"bunifuTextbox7";
			this->bunifuTextbox7->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox7->TabIndex = 2;
			this->bunifuTextbox7->text = L"Confirm OTP";
			// 
			// bunifuTextbox8
			// 
			this->bunifuTextbox8->BackColor = System::Drawing::Color::White;
			this->bunifuTextbox8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox8.BackgroundImage")));
			this->bunifuTextbox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox8->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox8->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox8.Icon")));
			this->bunifuTextbox8->Location = System::Drawing::Point(71, 168);
			this->bunifuTextbox8->Name = L"bunifuTextbox8";
			this->bunifuTextbox8->Size = System::Drawing::Size(250, 42);
			this->bunifuTextbox8->TabIndex = 1;
			this->bunifuTextbox8->text = L"Username";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(52, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(305, 42);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Reset Password";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1486, 840);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->panel1->BringToFront();
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		panel1->Visible = false;
		panel2->Visible = true;
	}
	private: System::Void bunifuImageButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panel2->Visible = false;
		this->panel1->Visible = true;
	}
	private: System::Void linkLabel4_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->panel2->Visible = false;
		this->panel1->Visible = true;
	}
	private: System::Void bunifuThinButton22_Click(System::Object^ sender, System::EventArgs^ e) {
		try {



			String^ Email = bunifuTextbox6->text;
			String^ Username = bunifuTextbox4->text;
			String^ Password = bunifuTextbox3->text;

			MySqlCommand^ cmd = gcnew MySqlCommand("Insert into register_table values ('" + Email + "','" + Username + "','" + Password + "')", con);


			MySqlDataReader^ dr;
			con->Open();
			try {
				dr = cmd->ExecuteReader();
				cmd->ExecuteNonQuery();

				bunifuTextbox6->text = "";
				bunifuTextbox4->text = "";
				bunifuTextbox3->text = "";
				bunifuTextbox5->text = "";

				MessageBox::Show("Sign up success\n, please go to login page");
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

			con->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
		   //login button clicked
	private: System::Void bunifuThinButton21_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{




			String^ Password = bunifuTextbox2->text;
			String^ Username = bunifuTextbox1->text;
			MySqlCommand^ cmd = gcnew MySqlCommand("select * from register_table where Username='" + Username + "' and Password='" + Password + "';", con);


			MySqlDataReader^ dr;
			con->Open();

			try
			{
				dr = cmd->ExecuteReader();
				int count = 0;
				while (dr->Read())
				{
					count += 1;
				}
				if (count == 1)
				{
					MessageBox::Show("Login successful.");
				}
				else
				{
					MessageBox::Show("Username and password is inncorrect.\n Please try again");
				}
			}

			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
			con->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}



	}
		  
		   private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			   // Method implementation here
		   }

	
private: System::Void linkLabel1_LinkClicked_1(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	panel1->Visible = false;
	panel3->Visible = true;
	panel2->Visible = false;
}
private: System::Void bunifuThinButton25_Click_1(System::Object^ sender, System::EventArgs^ e) {
	panel1->Visible = true;
	panel3->Visible = false;
	panel2->Visible = false;

}

};
}





