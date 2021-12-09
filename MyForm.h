#pragma once
#include "Csv_manipulator.h"
#include "Exeption.h"
#include "Set.h"
#include "Json_manipulator.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"

//using namespace std;

Chain block;
const int amount = 3;//166 строка
Candidates* Rez = new Candidates[amount];

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


	private: System::Windows::Forms::Button^ exportFileButton;

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::Button^ saveResultsBtn;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ developersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ statiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ chartToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->saveResultsBtn = (gcnew System::Windows::Forms::Button());
			this->exportFileButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->developersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->menuStrip1->SuspendLayout();
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
			this->searchByID->MaxLength = 8;
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
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->searchButton);
			this->groupBox1->Controls->Add(this->searchByID);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->groupBox1->Location = System::Drawing::Point(8, 296);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(460, 105);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Search";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(136, 72);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"8 numbers";
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
			this->groupBox2->Controls->Add(this->label5);
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
			this->groupBox2->Location = System::Drawing::Point(8, 24);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(460, 255);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Voting";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(312, 80);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"8 numbers";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox3->Controls->Add(this->saveResultsBtn);
			this->groupBox3->Controls->Add(this->exportFileButton);
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
			// saveResultsBtn
			// 
			this->saveResultsBtn->Location = System::Drawing::Point(248, 64);
			this->saveResultsBtn->Name = L"saveResultsBtn";
			this->saveResultsBtn->Size = System::Drawing::Size(184, 48);
			this->saveResultsBtn->TabIndex = 2;
			this->saveResultsBtn->Text = L"Save results";
			this->saveResultsBtn->UseVisualStyleBackColor = true;
			this->saveResultsBtn->Click += gcnew System::EventHandler(this, &MyForm::saveResultsBtn_Click);
			// 
			// exportFileButton
			// 
			this->exportFileButton->Location = System::Drawing::Point(24, 64);
			this->exportFileButton->Name = L"exportFileButton";
			this->exportFileButton->Size = System::Drawing::Size(184, 48);
			this->exportFileButton->TabIndex = 1;
			this->exportFileButton->Text = L"Export file";
			this->exportFileButton->UseVisualStyleBackColor = true;
			this->exportFileButton->Click += gcnew System::EventHandler(this, &MyForm::exportFileButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Control;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStripMenuItem,
					this->statiToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(475, 24);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->helpToolStripMenuItem,
					this->developersToolStripMenuItem
			});
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"&About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// developersToolStripMenuItem
			// 
			this->developersToolStripMenuItem->Name = L"developersToolStripMenuItem";
			this->developersToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->developersToolStripMenuItem->Text = L"Developers";
			this->developersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::developersToolStripMenuItem_Click);
			// 
			// statiToolStripMenuItem
			// 
			this->statiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->chartToolStripMenuItem });
			this->statiToolStripMenuItem->Name = L"statiToolStripMenuItem";
			this->statiToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->statiToolStripMenuItem->Text = L"&Statistics";
			// 
			// chartToolStripMenuItem
			// 
			this->chartToolStripMenuItem->Name = L"chartToolStripMenuItem";
			this->chartToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->chartToolStripMenuItem->Text = L"Chart";
			this->chartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::chartToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(475, 593);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(491, 632);
			this->MinimumSize = System::Drawing::Size(491, 632);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ChainVote";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{

		MyForm1^ loadData = gcnew MyForm1();
		loadData->ShowDialog();

		try
		{
			throw Csv_manipulator::ImportCsv("SavedData.csv", block);
		}
		catch (Csv_manipulator::FileStatus status)
		{
			string message;
			Exeption ex;

			switch (status)
			{
			case Csv_manipulator::opened:
				message = "File was successfully opened!";
				MessageBox::Show(this, "File was successfully opened!", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;

			case Csv_manipulator::changed:
				message = "Some votes was changed!";
				ex.SetCode(5);
				ex.SetMessage(message);
				Exeption::Show_exeption(ex);
				break;

			case Csv_manipulator::absent:
				message = "Can`t find file!";
				ex.SetCode(8);
				ex.SetMessage(message);
				Exeption::Show_exeption(ex);
				break;

			default:
				message = "Something went wrong!";
				ex.SetCode(9);
				ex.SetMessage(message);
				Exeption::Show_exeption(ex);
				break;
			}
		};
		
		//if (MessageBox::Show(this, "Load data from file?", "ChainVote", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
		//	String^ path = "";

		//	if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		//		path = openFileDialog->FileName;
		//		//сюда код
		//	}
		//}


		/*MyForm1^ loadData = gcnew MyForm1();
		loadData->ShowDialog();*/
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {

		//ID
		string id_str = String_manipulator::std_string(searchByID->Text);
		long id = atoi(id_str.c_str());
		string c = block.ShowV(id);
		String^ search;
		search = gcnew System::String(c.c_str());

		MessageBox::Show(this, search, "Result", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	private: System::Void voteConfirm_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBox1->Checked)
		{
			Node Pears;
			try
			{
				//Node Pears;
				string j = String_manipulator::std_string(voteOptions->SelectedItem->ToString());
				

				if (PIB->Text == "" || passportID->Text->Length < 8 || voteOptions->SelectedItem->ToString() == "" || voteOptions->SelectedIndex < 0)
				{
					throw false;
				}
				else {
					throw true;
				};


				//ID
				//string id_str = String_manipulator::std_string(passportID->Text);
				//long id = atoi(id_str.c_str());

				////Name
				//string name = String_manipulator::std_string(PIB->Text);

				////Vote
				//string vote = String_manipulator::std_string(voteOptions->SelectedItem->ToString());

				////if (Csv_manipulator::add_csv("vote_chain.csv", id, name, vote))	 // TODO try catch

				//	if (block.CompId(id) == -1 || block.CompId(id) == 0) {
				//		Pears.SetAll(name, id, vote, block.GetTailH());
				//		block.add(Pears);
				//		MessageBox::Show(this, "Vote submited!", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
				//	}
				//	else
				//	{
				//		Exeption_data ex("You have already voted!", 1);
				//		Show_exeption(ex);
				//	}
			}
			catch (bool temp)
			{
				if (temp == false) {
					Exeption ex("Enter a full info!", 2);
					Exeption::Show_exeption(ex);
				}
				else {
					string id_str = String_manipulator::std_string(passportID->Text);
					long id = atoi(id_str.c_str());

					//Name
					string name = String_manipulator::std_string(PIB->Text);

					//Vote
					string vote = String_manipulator::std_string(voteOptions->SelectedItem->ToString());

					//if (Csv_manipulator::add_csv("vote_chain.csv", id, name, vote))	 // TODO try catch

					if (block.CompId(id) == -1 || block.CompId(id) == 0) {
						Pears.SetAll(name, id, vote, block.GetTailH());
						block.add(Pears);
						MessageBox::Show(this, "Vote submited!", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						Exeption ex("You have already voted!", 1);
						Exeption::Show_exeption(ex);
					}
				}
			}
		}
		
		else
		{
			Exeption ex("Accept the agreement!", 3);
			Exeption::Show_exeption(ex);
		}
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void importFileButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		openFileDialog->Filter = "Files csv (*.csv)|*.csv";

		if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			string path = String_manipulator::std_string(openFileDialog->FileName);
			if (Csv_manipulator::ImportCsv(path, block) == false)
			{
				string msg = "Some votes was changed!";
				Exeption ex(msg, 5);
				Exeption::Show_exeption(ex);
			}
		}
		else {
			Exeption ex("Couldn`t open file", 6);
			Exeption::Show_exeption(ex);
		}
	}


	private: System::Void exportFileButton_Click(System::Object^ sender, System::EventArgs^ e)   // TODO try catch  файла не существует
	{
		saveFileDialog->Filter = "Files csv (*.csv)|*.csv";

		if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			string path = String_manipulator::std_string(saveFileDialog->FileName);
			Csv_manipulator::SaveCsv(path, block.GetHead());
		}
		else {
			Exeption ex("Couldn`t save file", 7);
			Exeption::Show_exeption(ex);
		}
	}
	private: System::Void saveResultsBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Rez[0].SetC("Somov Ivan Nikolaevich");//166 строка хранит даные о кандидатах
		Rez[1].SetC("Sokolenko Maria Dmitrievna");
		Rez[2].SetC("Dushnarev Nikita Aleksandrovich");
		for (int i = 0; i < amount; i++)
		{
			Rez[i].Seta(0);
		}

		block.Voice(Rez, amount);
		block.Win(Rez, amount);

		long max_votes = 0;
		bool haveWinner = false;
		Candidates winner;
		vector<Candidates> participants;

		for (int i = 0; i < amount; i++)
		{
			participants.push_back(Rez[i]);
			if (Rez[i].Geta() > max_votes)
			{
				winner = Rez[i];
				max_votes = Rez[i].Geta();
				haveWinner = true;
			}
		}
		if (haveWinner)
		{
			Json_manipulator::create_json(winner, participants);
			MessageBox::Show(this, "JSON file has been saved!", "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			Exeption ex("All candidates have 0 votes!", 4);
			Exeption::Show_exeption(ex);
		}

	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		Csv_manipulator::SaveCsv("SavedData.csv", block.GetHead());
	};

	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ helpInfo = gcnew MyForm2();
		helpInfo->Show();
	}
	private: System::Void developersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm3^ developersInfo = gcnew MyForm3();
		developersInfo->Show();
	}
	private: System::Void chartToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm4^ chartForm = gcnew MyForm4();
		chartForm->Show();
	}
	private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	};

}