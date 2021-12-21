#include "AdminPanel.h"
#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PasswordForm
	/// </summary>
	public ref class PasswordForm : public System::Windows::Forms::Form
	{
	public:
		PasswordForm(void)
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
		~PasswordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ adminLogin;
	private: System::Windows::Forms::TextBox^ adminPassword;
	private: System::Windows::Forms::Button^ adminConfirm;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PasswordForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->adminLogin = (gcnew System::Windows::Forms::TextBox());
			this->adminPassword = (gcnew System::Windows::Forms::TextBox());
			this->adminConfirm = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введіть логін: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(16, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Введіть пароль:";
			// 
			// adminLogin
			// 
			this->adminLogin->Location = System::Drawing::Point(160, 16);
			this->adminLogin->Name = L"adminLogin";
			this->adminLogin->Size = System::Drawing::Size(136, 20);
			this->adminLogin->TabIndex = 2;
			// 
			// adminPassword
			// 
			this->adminPassword->Location = System::Drawing::Point(160, 56);
			this->adminPassword->Name = L"adminPassword";
			this->adminPassword->PasswordChar = '*';
			this->adminPassword->Size = System::Drawing::Size(136, 20);
			this->adminPassword->TabIndex = 3;
			// 
			// adminConfirm
			// 
			this->adminConfirm->Location = System::Drawing::Point(112, 96);
			this->adminConfirm->Name = L"adminConfirm";
			this->adminConfirm->Size = System::Drawing::Size(88, 23);
			this->adminConfirm->TabIndex = 4;
			this->adminConfirm->Text = L"Увійти";
			this->adminConfirm->UseVisualStyleBackColor = true;
			this->adminConfirm->Click += gcnew System::EventHandler(this, &PasswordForm::adminConfirm_Click);
			// 
			// PasswordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(312, 134);
			this->Controls->Add(this->adminConfirm);
			this->Controls->Add(this->adminPassword);
			this->Controls->Add(this->adminLogin);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(328, 173);
			this->MinimumSize = System::Drawing::Size(328, 173);
			this->Name = L"PasswordForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Панель керування";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PasswordForm::PasswordForm_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PasswordForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	}
private: System::Void adminConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
	if (adminLogin->Text == "admin" && adminPassword->Text == "admin") {
		AdminPanel^ adminPanel = gcnew AdminPanel();
		adminPanel->Show();
		PasswordForm::Hide();
	}
	else {
		MessageBox::Show(this, "Невірний логін або пароль", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
};
}
