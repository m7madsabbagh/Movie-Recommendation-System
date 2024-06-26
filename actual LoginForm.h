#pragma once
#include "MainPage.h"
#include <vcclr.h>
#include "Registration.h"
#include "Login.h"
#include "Reset.h"

//#include <msclr/marshal_cppstd.h>


namespace LoginForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Web;
	using namespace System::Net::Mail;
	using namespace System::Text::RegularExpressions;
	using namespace System::Security::Cryptography;
	using namespace System::Text;




	public ref class LoginForm : public System::Windows::Forms::Form
	{
	private:
		LoginHandler^ loginHandler;
		PasswordResetter^ resetter;
		String^ OTP;
		RegistrationHandler^ regHandler;


		System::Windows::Forms::Panel^ panel3;
		Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton25;
		Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox9;
		Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox10;
		Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton24;
		Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton23;
		Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox7;
		Bunifu::Framework::UI::BunifuTextbox^ bunifuTextbox8;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::LinkLabel^ linkLabel1;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::Label^ label1;


		Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton21;
		System::Windows::Forms::LinkLabel^ linkLabel2;

		System::Windows::Forms::Panel^ panel2;
		System::Windows::Forms::LinkLabel^ linkLabel4;


		System::Windows::Forms::LinkLabel^ linkLabel3;
		Bunifu::Framework::UI::BunifuThinButton2^ bunifuThinButton22;


		System::Windows::Forms::Label^ label2;
		Bunifu::Framework::UI::BunifuImageButton^ bunifuImageButton1;


		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;

		System::Windows::Forms::CheckBox^ checkBox1;
		System::Windows::Forms::CheckBox^ checkBox5;
		System::Windows::Forms::CheckBox^ checkBox4;
		System::Windows::Forms::CheckBox^ checkBox3;
		System::Windows::Forms::CheckBox^ checkBox2;
		System::Windows::Forms::CheckBox^ checkBox9;
		System::Windows::Forms::CheckBox^ checkBox8;
		System::Windows::Forms::CheckBox^ checkBox7;
		System::Windows::Forms::CheckBox^ checkBox6;
		System::Windows::Forms::CheckBox^ checkBox12;
		System::Windows::Forms::CheckBox^ checkBox11;
		System::Windows::Forms::CheckBox^ checkBox10;
System::Windows::Forms::TextBox^ textBox1;
	 System::Windows::Forms::TextBox^ textBox2;
	 System::Windows::Forms::TextBox^ textBox4;
	 System::Windows::Forms::TextBox^ textBox3;
	 System::Windows::Forms::Label^ label6;
	 System::Windows::Forms::Label^ label10;
	 System::Windows::Forms::Label^ label9;
	 System::Windows::Forms::Label^ label8;
	 System::Windows::Forms::Label^ label7;
	 System::Windows::Forms::Label^ label12;
	 System::Windows::Forms::Label^ label11;
	System::Windows::Forms::TextBox^ textBox6;
	 System::Windows::Forms::TextBox^ textBox5;




		String^ Username;


	public:
	String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";

	public:






	
		MySqlConnection^ con = gcnew MySqlConnection(constr);
		;
		LoginForm(void)
		{
			InitializeComponent();

			resetter = gcnew PasswordResetter();
			regHandler = gcnew RegistrationHandler();

		}





	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->bunifuThinButton21 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->linkLabel4 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
			this->bunifuThinButton22 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->bunifuThinButton25 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuTextbox9 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuTextbox10 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuThinButton24 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuThinButton23 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuTextbox7 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuTextbox8 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
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
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->linkLabel1);
			this->panel1->Controls->Add(this->linkLabel2);
			this->panel1->Controls->Add(this->bunifuThinButton21);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(624, 151);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(391, 565);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panel1_Paint_1);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label12->Location = System::Drawing::Point(83, 193);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(67, 17);
			this->label12->TabIndex = 34;
			this->label12->Text = L"Username";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label11->Location = System::Drawing::Point(86, 285);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(64, 17);
			this->label11->TabIndex = 33;
			this->label11->Text = L"Password";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(89, 221);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(213, 20);
			this->textBox6->TabIndex = 28;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(89, 316);
			this->textBox5->Name = L"textBox5";
			this->textBox5->PasswordChar = '*';
			this->textBox5->Size = System::Drawing::Size(213, 20);
			this->textBox5->TabIndex = 27;
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(116, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->checkBox12);
			this->panel2->Controls->Add(this->checkBox11);
			this->panel2->Controls->Add(this->checkBox10);
			this->panel2->Controls->Add(this->checkBox9);
			this->panel2->Controls->Add(this->checkBox8);
			this->panel2->Controls->Add(this->checkBox7);
			this->panel2->Controls->Add(this->checkBox6);
			this->panel2->Controls->Add(this->checkBox5);
			this->panel2->Controls->Add(this->checkBox4);
			this->panel2->Controls->Add(this->checkBox3);
			this->panel2->Controls->Add(this->checkBox2);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->bunifuImageButton1);
			this->panel2->Controls->Add(this->linkLabel4);
			this->panel2->Controls->Add(this->linkLabel3);
			this->panel2->Controls->Add(this->bunifuThinButton22);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(1018, 56);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(391, 660);
			this->panel2->TabIndex = 1;
			this->panel2->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label10->Location = System::Drawing::Point(93, 485);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(114, 17);
			this->label10->TabIndex = 32;
			this->label10->Text = L"Confirm Password";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label9->Location = System::Drawing::Point(93, 414);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 17);
			this->label9->TabIndex = 31;
			this->label9->Text = L"Password";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label8->Location = System::Drawing::Point(93, 182);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(67, 17);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Username";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label7->Location = System::Drawing::Point(93, 127);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(39, 17);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Email";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(96, 515);
			this->textBox4->Name = L"textBox4";
			this->textBox4->PasswordChar = '*';
			this->textBox4->Size = System::Drawing::Size(213, 20);
			this->textBox4->TabIndex = 28;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(96, 446);
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(213, 20);
			this->textBox3->TabIndex = 27;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(96, 205);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(213, 20);
			this->textBox2->TabIndex = 26;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(96, 147);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(213, 20);
			this->textBox1->TabIndex = 25;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBox1_TextChanged);
			// 
			// checkBox12
			// 
			this->checkBox12->AutoSize = true;
			this->checkBox12->ForeColor = System::Drawing::Color::White;
			this->checkBox12->Location = System::Drawing::Point(290, 353);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(57, 17);
			this->checkBox12->TabIndex = 24;
			this->checkBox12->Text = L"Thriller";
			this->checkBox12->UseVisualStyleBackColor = true;
			// 
			// checkBox11
			// 
			this->checkBox11->AutoSize = true;
			this->checkBox11->ForeColor = System::Drawing::Color::White;
			this->checkBox11->Location = System::Drawing::Point(81, 353);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(72, 17);
			this->checkBox11->TabIndex = 23;
			this->checkBox11->Text = L"Romance";
			this->checkBox11->UseVisualStyleBackColor = true;
			// 
			// checkBox10
			// 
			this->checkBox10->AutoSize = true;
			this->checkBox10->ForeColor = System::Drawing::Color::White;
			this->checkBox10->Location = System::Drawing::Point(180, 353);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(52, 17);
			this->checkBox10->TabIndex = 22;
			this->checkBox10->Text = L"Sci-Fi";
			this->checkBox10->UseVisualStyleBackColor = true;
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->ForeColor = System::Drawing::Color::White;
			this->checkBox9->Location = System::Drawing::Point(81, 310);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(63, 17);
			this->checkBox9->TabIndex = 21;
			this->checkBox9->Text = L"Fantasy";
			this->checkBox9->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->ForeColor = System::Drawing::Color::White;
			this->checkBox8->Location = System::Drawing::Point(290, 310);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(55, 17);
			this->checkBox8->TabIndex = 20;
			this->checkBox8->Text = L"Horror";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->ForeColor = System::Drawing::Color::White;
			this->checkBox7->Location = System::Drawing::Point(19, 353);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(62, 17);
			this->checkBox7->TabIndex = 19;
			this->checkBox7->Text = L"Mystery";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->ForeColor = System::Drawing::Color::White;
			this->checkBox6->Location = System::Drawing::Point(180, 310);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(58, 17);
			this->checkBox6->TabIndex = 18;
			this->checkBox6->Text = L"History";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->ForeColor = System::Drawing::Color::White;
			this->checkBox5->Location = System::Drawing::Point(81, 267);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(75, 17);
			this->checkBox5->TabIndex = 17;
			this->checkBox5->Text = L"Adventure";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->ForeColor = System::Drawing::Color::White;
			this->checkBox4->Location = System::Drawing::Point(180, 267);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(72, 17);
			this->checkBox4->TabIndex = 16;
			this->checkBox4->Text = L"Animation";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->ForeColor = System::Drawing::Color::White;
			this->checkBox3->Location = System::Drawing::Point(290, 267);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(64, 17);
			this->checkBox3->TabIndex = 15;
			this->checkBox3->Text = L"Comedy";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->ForeColor = System::Drawing::Color::White;
			this->checkBox2->Location = System::Drawing::Point(18, 310);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(57, 17);
			this->checkBox2->TabIndex = 14;
			this->checkBox2->Text = L"Drama";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::Color::White;
			this->checkBox1->Location = System::Drawing::Point(18, 267);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(56, 17);
			this->checkBox1->TabIndex = 13;
			this->checkBox1->Text = L"Action";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(93, 237);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(201, 16);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Select movie categories you like";
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
			this->linkLabel4->Location = System::Drawing::Point(120, 551);
			this->linkLabel4->Name = L"linkLabel4";
			this->linkLabel4->Size = System::Drawing::Size(132, 13);
			this->linkLabel4->TabIndex = 8;
			this->linkLabel4->TabStop = true;
			this->linkLabel4->Text = L"Already have an account\?";
			this->linkLabel4->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel4_LinkClicked);
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
			this->bunifuThinButton22->Location = System::Drawing::Point(96, 584);
			this->bunifuThinButton22->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton22->Name = L"bunifuThinButton22";
			this->bunifuThinButton22->Size = System::Drawing::Size(181, 49);
			this->bunifuThinButton22->TabIndex = 3;
			this->bunifuThinButton22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton22->Click += gcnew System::EventHandler(this, &LoginForm::bunifuThinButton22_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
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
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->bunifuThinButton25);
			this->panel3->Controls->Add(this->bunifuTextbox9);
			this->panel3->Controls->Add(this->bunifuTextbox10);
			this->panel3->Controls->Add(this->bunifuThinButton24);
			this->panel3->Controls->Add(this->bunifuThinButton23);
			this->panel3->Controls->Add(this->bunifuTextbox7);
			this->panel3->Controls->Add(this->bunifuTextbox8);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(110, 151);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(391, 565);
			this->panel3->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(80, 221);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(121, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"OTP sent to this number";
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
			this->bunifuTextbox9->text = L"";
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
			this->bunifuTextbox10->text = L"";
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
			this->bunifuThinButton24->Location = System::Drawing::Point(95, 239);
			this->bunifuThinButton24->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton24->Name = L"bunifuThinButton24";
			this->bunifuThinButton24->Size = System::Drawing::Size(181, 49);
			this->bunifuThinButton24->TabIndex = 4;
			this->bunifuThinButton24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton24->Click += gcnew System::EventHandler(this, &LoginForm::bunifuThinButton24_Click);
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
			this->bunifuThinButton23->Click += gcnew System::EventHandler(this, &LoginForm::bunifuThinButton23_Click);
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
			this->bunifuTextbox7->text = L"";
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
			this->bunifuTextbox8->text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(52, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(305, 42);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Reset Password";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label6->Location = System::Drawing::Point(656, 31);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(74, 13);
			this->label6->TabIndex = 4;
			this->label6->Text = L"CME MOVIES";
			this->label6->Click += gcnew System::EventHandler(this, &LoginForm::label6_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1486, 840);
			this->Controls->Add(this->label6);
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
			this->PerformLayout();

		}



	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->panel1->BringToFront();
		this->panel3->Visible = false;
	}

	 System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		panel1->Visible = false;
		panel2->Visible = true;
		this->panel3->Visible = false;
	}
	System::Void bunifuImageButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panel2->Visible = false;
		this->panel1->Visible = true;
		this->panel3->Visible = false;
	}
	 System::Void linkLabel4_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->panel2->Visible = false;
		this->panel1->Visible = true;
		this->panel3->Visible = false;
	}




		   //register

	 System::Void bunifuThinButton22_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			if (regHandler == nullptr)
			{
				regHandler = gcnew RegistrationHandler();
			}

			String^ Email = textBox1->Text;
			String^ Username = textBox2->Text;
			String^ Password = textBox3->Text;
			String^ ConfirmPassword = textBox4->Text;


			if (!IsValidEmail(Email))
			{
				MessageBox::Show("Please enter a valid email address.");
				return;
			}

			// Start of the new password validation block
			if (Password != ConfirmPassword)
			{
				MessageBox::Show("Passwords do not match.");
				return;
			}

			if (Password->Length < 7)
			{
				MessageBox::Show("Password must be at least 7 characters long.");
				return;
			}

			if (!Regex::IsMatch(Password, "[A-Z]"))
			{
				MessageBox::Show("Password is missing an uppercase letter.");
				return;
			}

			if (!Regex::IsMatch(Password, "[0-9]"))
			{
				MessageBox::Show("Password is missing a number.");
				return;
			}

			if (!Regex::IsMatch(Password, "[!@#$%^&*]")) 
			{
				MessageBox::Show("Password is missing a special character.");
				return;
			}
			

			String^ result = regHandler->registerUser(Email, Username, Password, checkBox1->Checked, checkBox5->Checked, checkBox4->Checked, checkBox3->Checked, checkBox2->Checked, checkBox9->Checked, checkBox6->Checked, checkBox8->Checked, checkBox7->Checked, checkBox11->Checked, checkBox10->Checked, checkBox12->Checked);

			if (result == "Sign up success, please go to the login page") {
				MessageBox::Show(result);
			}
			else {
				MessageBox::Show(result);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
		finally {
			if (con->State == ConnectionState::Open)
				con->Close();
		}
	}
		   bool IsValidEmail(String^ email)
		   {
			   // Regular expression pattern for email validation
			   String^ pattern = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$";

			   // Use regex to check if the email matches the pattern
			   return Regex::IsMatch(email, pattern);
		   }

	







		   //login button clicked
	private: System::Void bunifuThinButton21_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (loginHandler == nullptr) {
				loginHandler = gcnew LoginHandler();  // Create a new LoginHandler object
			}

			
			String^ Username = textBox6->Text;
			String^ Password = textBox5->Text;


			String^ result = loginHandler->logInUser(Username, Password);
			if (result == "Login successful.") {
				loginHandler->SaveUsername(Username);  // Save the username
				MessageBox::Show(result);
				this->Hide();  // Hide LoginForm

				MainPage^ mainPageForm = gcnew MainPage();  // Create MainPage instance
				mainPageForm->ShowDialog();  // Show MainPage
			}
			else {
				MessageBox::Show(result);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}



	 System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}


	 System::Void linkLabel1_LinkClicked_1(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		panel1->Visible = false;
		panel3->Visible = true;
		panel2->Visible = false;
	}
	System::Void bunifuThinButton25_Click_1(System::Object^ sender, System::EventArgs^ e) {
		panel1->Visible = true;
		panel3->Visible = false;
		panel2->Visible = false;

	}


		   //to reset password	
	 System::Void bunifuThinButton24_Click(System::Object^ sender, System::EventArgs^ e) {
		resetter->sendResetEmail(bunifuTextbox8->text, con, OTP);
		label4->Text = "OTP sent to email registered with this username.";
	}


	 System::Void bunifuThinButton23_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			Regex^ passwordRegex = gcnew Regex("^(?=.*[A-Z])(?=.*\\d)(?=.*[\\W])[\\s\\S]{7,}$");

			if (bunifuTextbox7->text == OTP)
			{
				if (bunifuTextbox9->text == bunifuTextbox10->text)
				{
					String^ password = bunifuTextbox10->text;
					if (!passwordRegex->IsMatch(password)) {
						MessageBox::Show("Password must be at least 7 characters long, contain at least 1 capital letter and 1 special character");
						return;
					}

					MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE user_reg set Password='" + password + "' where Username = '" + bunifuTextbox8->text + "'", con);
					con->Open();
					MySqlDataReader^ dr = cmd->ExecuteReader();
					con->Close();
					MessageBox::Show("Password reset successfully.");
				}
				else
				{
					MessageBox::Show("Confirm password does not match");
				}
			}
			else
			{
				MessageBox::Show("OTP does not match. Please try again");
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	 System::Void bunifuTextbox6_OnTextChange(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
 System::Void bunifuTextbox2_OnTextChange(System::Object^ sender, System::EventArgs^ e) {
}
 System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}




