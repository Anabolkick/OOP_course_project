#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(64, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Load data from file\?";
			// 
			// yesButton
			// 
			this->yesButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->yesButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->yesButton->Location = System::Drawing::Point(24, 64);
			this->yesButton->Name = L"yesButton";
			this->yesButton->Size = System::Drawing::Size(96, 24);
			this->yesButton->TabIndex = 6;
			this->yesButton->TabStop = false;
			this->yesButton->Text = L"Yes";
			this->yesButton->UseVisualStyleBackColor = true;
			this->yesButton->Click += gcnew System::EventHandler(this, &MyForm1::yesButton_Click);
			// 
			// noButton
			// 
			this->noButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->noButton->Location = System::Drawing::Point(160, 64);
			this->noButton->Name = L"noButton";
			this->noButton->Size = System::Drawing::Size(96, 24);
			this->noButton->TabIndex = 7;
			this->noButton->Text = L"No";
			this->noButton->UseVisualStyleBackColor = true;
			this->noButton->Click += gcnew System::EventHandler(this, &MyForm1::noButton_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(284, 111);
			this->Controls->Add(this->noButton);
			this->Controls->Add(this->yesButton);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(300, 150);
			this->MinimumSize = System::Drawing::Size(300, 150);
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
private: System::Void yesButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm1::Close();
}
};
}
