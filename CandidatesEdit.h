//#include "MyForm.h"
#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CandidatesEdit
	/// </summary>
	public ref class CandidatesEdit : public System::Windows::Forms::Form
	{
	public:
		CandidatesEdit(void)
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
		~CandidatesEdit()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
	private: System::Windows::Forms::TextBox^ candidatesPIB;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ prevoteAddCandidates;
	private: System::Windows::Forms::Button^ skipCandidatesEdit;
	public: System::Windows::Forms::ListBox^ prevoteCandidates;
	private:



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CandidatesEdit::typeid));
			this->candidatesPIB = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->prevoteAddCandidates = (gcnew System::Windows::Forms::Button());
			this->skipCandidatesEdit = (gcnew System::Windows::Forms::Button());
			this->prevoteCandidates = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// candidatesPIB
			// 
			this->candidatesPIB->Location = System::Drawing::Point(16, 48);
			this->candidatesPIB->Name = L"candidatesPIB";
			this->candidatesPIB->Size = System::Drawing::Size(288, 20);
			this->candidatesPIB->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(190, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введіть ПІБ кандидата";
			// 
			// prevoteAddCandidates
			// 
			this->prevoteAddCandidates->Location = System::Drawing::Point(312, 48);
			this->prevoteAddCandidates->Name = L"prevoteAddCandidates";
			this->prevoteAddCandidates->Size = System::Drawing::Size(72, 24);
			this->prevoteAddCandidates->TabIndex = 3;
			this->prevoteAddCandidates->Text = L"Додати";
			this->prevoteAddCandidates->UseVisualStyleBackColor = true;
			this->prevoteAddCandidates->Click += gcnew System::EventHandler(this, &CandidatesEdit::prevoteAddCandidates_Click);
			// 
			// skipCandidatesEdit
			// 
			this->skipCandidatesEdit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->skipCandidatesEdit->Location = System::Drawing::Point(144, 160);
			this->skipCandidatesEdit->Name = L"skipCandidatesEdit";
			this->skipCandidatesEdit->Size = System::Drawing::Size(112, 24);
			this->skipCandidatesEdit->TabIndex = 4;
			this->skipCandidatesEdit->Text = L"Далі";
			this->skipCandidatesEdit->UseVisualStyleBackColor = true;
			this->skipCandidatesEdit->Click += gcnew System::EventHandler(this, &CandidatesEdit::skipCandidatesEdit_Click);
			// 
			// prevoteCandidates
			// 
			this->prevoteCandidates->FormattingEnabled = true;
			this->prevoteCandidates->Location = System::Drawing::Point(16, 88);
			this->prevoteCandidates->Name = L"prevoteCandidates";
			this->prevoteCandidates->Size = System::Drawing::Size(368, 56);
			this->prevoteCandidates->TabIndex = 5;
			// 
			// CandidatesEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(395, 196);
			this->Controls->Add(this->prevoteCandidates);
			this->Controls->Add(this->skipCandidatesEdit);
			this->Controls->Add(this->prevoteAddCandidates);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->candidatesPIB);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CandidatesEdit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Редагування кандидатів";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void prevoteAddCandidates_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!(candidatesPIB->Text == "")) {
			prevoteCandidates->Items->Add(candidatesPIB->Text);
		}
	}
private: System::Void skipCandidatesEdit_Click(System::Object^ sender, System::EventArgs^ e) {
	CandidatesEdit::Hide();
}
};
}
