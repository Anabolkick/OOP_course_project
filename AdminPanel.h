#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for AdminPanel
	/// </summary>
	public ref class AdminPanel : public System::Windows::Forms::Form
	{
	public:
		AdminPanel(void)
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
		~AdminPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ addCandidates;
	protected:
	private: System::Windows::Forms::Button^ exportInfoCSV;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminPanel::typeid));
			this->addCandidates = (gcnew System::Windows::Forms::Button());
			this->exportInfoCSV = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// addCandidates
			// 
			this->addCandidates->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addCandidates->Location = System::Drawing::Point(16, 24);
			this->addCandidates->Name = L"addCandidates";
			this->addCandidates->Size = System::Drawing::Size(248, 40);
			this->addCandidates->TabIndex = 0;
			this->addCandidates->Text = L"Добавити кандидатів";
			this->addCandidates->UseVisualStyleBackColor = true;
			this->addCandidates->Click += gcnew System::EventHandler(this, &AdminPanel::addCandidates_Click);
			// 
			// exportInfoCSV
			// 
			this->exportInfoCSV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exportInfoCSV->Location = System::Drawing::Point(16, 88);
			this->exportInfoCSV->Name = L"exportInfoCSV";
			this->exportInfoCSV->Size = System::Drawing::Size(248, 40);
			this->exportInfoCSV->TabIndex = 1;
			this->exportInfoCSV->Text = L"Експортувати інформацію";
			this->exportInfoCSV->UseVisualStyleBackColor = true;
			this->exportInfoCSV->Click += gcnew System::EventHandler(this, &AdminPanel::exportInfoCSV_Click);
			// 
			// AdminPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 154);
			this->Controls->Add(this->exportInfoCSV);
			this->Controls->Add(this->addCandidates);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AdminPanel";
			this->Text = L"Панель керування";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void exportInfoCSV_Click(System::Object^ sender, System::EventArgs^ e) {
		if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
			
		}
	};
	private: System::Void addCandidates_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {

		}
	}
	};
}
