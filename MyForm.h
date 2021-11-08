#pragma once
#include "csv_manipulator.cpp"
#include "string_manipulator.cpp"
#include "Data.h"


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ PIB;
	private: System::Windows::Forms::TextBox^ passportID;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ voteOptions;
	private: System::Windows::Forms::TextBox^ searchByID;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ voteConfirm;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ searchButton;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::Button^ saveFileButton;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::Button^ saveResultsBtn;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->PIB = (gcnew System::Windows::Forms::TextBox());
			this->passportID = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->voteOptions = (gcnew System::Windows::Forms::ComboBox());
			this->searchByID = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->voteConfirm = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->saveFileButton = (gcnew System::Windows::Forms::Button());
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->saveResultsBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(20, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter your full name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(265, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter passport ID";
			// 
			// PIB
			// 
			this->PIB->Location = System::Drawing::Point(24, 55);
			this->PIB->Name = L"PIB";
			this->PIB->Size = System::Drawing::Size(216, 22);
			this->PIB->TabIndex = 2;
			// 
			// passportID
			// 
			this->passportID->Location = System::Drawing::Point(269, 55);
			this->passportID->MaxLength = 8;
			this->passportID->Name = L"passportID";
			this->passportID->Size = System::Drawing::Size(156, 22);
			this->passportID->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(20, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Choose an option";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// voteOptions
			// 
			this->voteOptions->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->voteOptions->FormattingEnabled = true;
			this->voteOptions->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Somov Ivan Nikolaevich", L"Sokolenko Maria Dmitrievna",
					L"Dushnarev Nikita Aleksandrovich"
			});
			this->voteOptions->Location = System::Drawing::Point(24, 120);
			this->voteOptions->Name = L"voteOptions";
			this->voteOptions->Size = System::Drawing::Size(400, 24);
			this->voteOptions->TabIndex = 5;
			// 
			// searchByID
			// 
			this->searchByID->Location = System::Drawing::Point(64, 48);
			this->searchByID->Name = L"searchByID";
			this->searchByID->Size = System::Drawing::Size(200, 22);
			this->searchByID->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(60, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Search by ID";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(24, 168);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(280, 24);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"I agree to the processing of my vote";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// voteConfirm
			// 
			this->voteConfirm->BackColor = System::Drawing::SystemColors::Control;
			this->voteConfirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->voteConfirm->Location = System::Drawing::Point(24, 208);
			this->voteConfirm->Name = L"voteConfirm";
			this->voteConfirm->Size = System::Drawing::Size(134, 28);
			this->voteConfirm->TabIndex = 9;
			this->voteConfirm->Text = L"Submit vote";
			this->voteConfirm->UseVisualStyleBackColor = false;
			this->voteConfirm->Click += gcnew System::EventHandler(this, &MyForm::voteConfirm_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Controls->Add(this->searchButton);
			this->groupBox1->Controls->Add(this->searchByID);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->groupBox1->Location = System::Drawing::Point(8, 288);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(460, 105);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Search";
			// 
			// searchButton
			// 
			this->searchButton->BackColor = System::Drawing::SystemColors::Control;
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->searchButton->Location = System::Drawing::Point(303, 48);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(97, 22);
			this->searchButton->TabIndex = 8;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = false;
			this->searchButton->Click += gcnew System::EventHandler(this, &MyForm::searchButton_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->voteOptions);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->voteConfirm);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->PIB);
			this->groupBox2->Controls->Add(this->passportID);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(8, 16);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(460, 255);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Voting";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox3->Controls->Add(this->saveResultsBtn);
			this->groupBox3->Controls->Add(this->saveFileButton);
			this->groupBox3->Controls->Add(this->openFileButton);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->groupBox3->Location = System::Drawing::Point(8, 416);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(460, 165);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Files";
			// 
			// saveFileButton
			// 
			this->saveFileButton->Location = System::Drawing::Point(248, 40);
			this->saveFileButton->Name = L"saveFileButton";
			this->saveFileButton->Size = System::Drawing::Size(184, 48);
			this->saveFileButton->TabIndex = 1;
			this->saveFileButton->Text = L"Import file";
			this->saveFileButton->UseVisualStyleBackColor = true;
			this->saveFileButton->Click += gcnew System::EventHandler(this, &MyForm::saveFileButton_Click);
			// 
			// openFileButton
			// 
			this->openFileButton->Location = System::Drawing::Point(24, 40);
			this->openFileButton->Name = L"openFileButton";
			this->openFileButton->Size = System::Drawing::Size(184, 48);
			this->openFileButton->TabIndex = 0;
			this->openFileButton->Text = L"Open file";
			this->openFileButton->UseVisualStyleBackColor = true;
			this->openFileButton->Click += gcnew System::EventHandler(this, &MyForm::openFileButton_Click);
			// 
			// saveResultsBtn
			// 
			this->saveResultsBtn->Location = System::Drawing::Point(132, 111);
			this->saveResultsBtn->Name = L"saveResultsBtn";
			this->saveResultsBtn->Size = System::Drawing::Size(184, 48);
			this->saveResultsBtn->TabIndex = 2;
			this->saveResultsBtn->Text = L"Save results";
			this->saveResultsBtn->UseVisualStyleBackColor = true;
			this->saveResultsBtn->Click += gcnew System::EventHandler(this, &MyForm::saveResultsBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(484, 593);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"ChainVote";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		Voting* Candidate = new Voting[3];
		Set* Vote=new Set[1];//хранение списка
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if ( searchByID->Text!="") { /*Vote[0].CompId(Vote.Head, searchByID->Text)!=-1*/

			MessageBox::Show(this, "ID [number] voted for [full name]", "Found!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show(this, "ID [number] not voted yet", "Failure!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}
	private: System::Void voteConfirm_Click(System::Object^ sender, System::EventArgs^ e)
	{

		if (checkBox1->Checked)
		{
			try
			{
				if (PIB->Text == "" || passportID->Text == "" || voteOptions->SelectedItem->ToString() == "")
				{
					throw false;
				}

				//ID
				string id_str = string_manipulator::std_string(passportID->Text);
				long id = atoi(id_str.c_str());

				//Name
				string name = string_manipulator::std_string(PIB->Text);

				//Vote
				string vote = string_manipulator::std_string(voteOptions->SelectedItem->ToString());

				if (csv_manipulator::add_csv("vote_chain.csv", id, name, vote))	 // TODO try catch
				{
					MessageBox::Show(this, "Vote submited!", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{
					MessageBox::Show(this, "You have already voted!", "Error 4!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			catch (bool)
			{
				MessageBox::Show(this, "Enter a full info!", "Error 3!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		else
		{
			MessageBox::Show(this, "Accept the agreement!", "Error 5!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		openFileDialog->Filter = "Files csv (*.csv)|*.csv";

		if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			string file_name = string_manipulator::std_string(openFileDialog->FileName);
			csv_manipulator::copy_csv(file_name, "vote_chain.csv");
		}
	}
	private: System::Void saveFileButton_Click(System::Object^ sender, System::EventArgs^ e)   // TODO try catch  файла не существует
	{
		saveFileDialog->Filter = "Files csv (*.csv)|*.csv";

		if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			string file_name = string_manipulator::std_string(saveFileDialog->FileName);
			csv_manipulator::copy_csv("vote_chain.csv", file_name);
		}
	}
	private: System::Void saveResultsBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	};

}