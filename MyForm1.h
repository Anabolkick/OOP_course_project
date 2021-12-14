#pragma once
#include "Exeption.h"
#include "Csv_manipulator.h"
#include "String_manipulator.h"
//#include "MyForm.h"		 /////////////////

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
	//	MyForm^ loadData;	 ////////////////////
		/*MyForm1(MyForm^ main)		////////////////
		{
			InitializeComponent();
			loadData = main;
		}*/					   /////////////////////
		MyForm1()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ yesButton;
	private:

	private: System::Windows::Forms::Button^ noButton;
	public: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	public: System::Windows::Forms::Button^ manualLoad;
	private:



	private:



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->yesButton = (gcnew System::Windows::Forms::Button());
			this->noButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->manualLoad = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(40, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"How to load data from file\?";
			// 
			// yesButton
			// 
			this->yesButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->yesButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->yesButton->Location = System::Drawing::Point(32, 72);
			this->yesButton->Name = L"yesButton";
			this->yesButton->Size = System::Drawing::Size(96, 24);
			this->yesButton->TabIndex = 6;
			this->yesButton->TabStop = false;
			this->yesButton->Text = L"Autoload";
			this->yesButton->UseVisualStyleBackColor = true;
			// 
			// noButton
			// 
			this->noButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->noButton->Location = System::Drawing::Point(96, 112);
			this->noButton->Name = L"noButton";
			this->noButton->Size = System::Drawing::Size(96, 24);
			this->noButton->TabIndex = 7;
			this->noButton->Text = L"Do not load";
			this->noButton->UseVisualStyleBackColor = true;
			this->noButton->Click += gcnew System::EventHandler(this, &MyForm1::noButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// manualLoad
			// 
			this->manualLoad->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->manualLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->manualLoad->Location = System::Drawing::Point(160, 72);
			this->manualLoad->Name = L"manualLoad";
			this->manualLoad->Size = System::Drawing::Size(96, 24);
			this->manualLoad->TabIndex = 8;
			this->manualLoad->TabStop = false;
			this->manualLoad->Text = L"Manually";
			this->manualLoad->UseVisualStyleBackColor = true;
			this->manualLoad->Click += gcnew System::EventHandler(this, &MyForm1::manualLoad_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(289, 154);
			this->Controls->Add(this->manualLoad);
			this->Controls->Add(this->noButton);
			this->Controls->Add(this->yesButton);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ChainVote";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void noButton_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm1::Close();
	}

	private: System::Void manualLoad_Click(System::Object^ sender, System::EventArgs^ e) 
	{

		MyForm1::Close();
	};
};
}