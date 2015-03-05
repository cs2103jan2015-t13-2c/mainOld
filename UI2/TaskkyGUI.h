#pragma once

namespace UI2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TaskkyGUI
	/// </summary>
	public ref class TaskkyGUI : public System::Windows::Forms::Form
	{
	public:
		TaskkyGUI(void)
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
		~TaskkyGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	protected:

	protected:

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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(114, 91);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(47, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Test";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &TaskkyGUI::checkBox1_CheckedChanged);
			// 
			// TaskkyGUI
			// 
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->checkBox1);
			this->Name = L"TaskkyGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
