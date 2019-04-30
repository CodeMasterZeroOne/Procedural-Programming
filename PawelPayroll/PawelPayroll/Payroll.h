#include "Employee.h"
#include "CSVManipulator.h"

namespace PawelPayroll {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Payroll
	/// </summary>
	public ref class Payroll : public System::Windows::Forms::Form
	{

	private:
		List<Employee^>^ employees;
		Employee^ registeredEmployee;
		double enteredHours, enteredOvertime, gross, net, tax, roundedGross, roundedNet, roundedTax;

	public:

		Payroll(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			CSVManipulator manipulator;
			employees = manipulator.ReadData();

			//String^ displayString = gcnew String(employees.c_str());
			//groupBoxEmployeeID->Text = displayString;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Payroll()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelName;
	protected:

	private: System::Windows::Forms::Label^ labelEmployeeNameSurname;
	private: System::Windows::Forms::Label^ labelRole;
	private: System::Windows::Forms::Label^ labelEmployeeRole;

	private: System::Windows::Forms::Label^ labelHours;
	private: System::Windows::Forms::TextBox^ textBoxWorkingHours;
	private: System::Windows::Forms::Label^ labelOvertime;
	private: System::Windows::Forms::TextBox^ textBoxOvertimeHours;
	private: System::Windows::Forms::Button^ buttonCalculateIncome;
	private: System::Windows::Forms::GroupBox^ groupBoxIncome;

	private: System::Windows::Forms::Label^ labelTaxPaid;
	private: System::Windows::Forms::Label^ labelNet;
	private: System::Windows::Forms::Label^ labelGross;
	private: System::Windows::Forms::GroupBox^ groupBoxHoursWorked;
	private: System::Windows::Forms::GroupBox^ groupBoxEmployee;
	private: System::Windows::Forms::Label^ labelPaidTax;
	private: System::Windows::Forms::Label^ labelPaidNet;
	private: System::Windows::Forms::Label^ labelPaidGross;
	private: System::Windows::Forms::Button^ buttonAddHours;

	private: System::Windows::Forms::Button^ buttonSaveIncome;
	private: System::Windows::Forms::GroupBox^ groupBoxEmployeeID;
	private: System::Windows::Forms::Button^ buttonFindEmployee;
	private: System::Windows::Forms::TextBox^ textBoxEmployeeID;
	private: System::Windows::Forms::Label^ labelWeekSelect;
	private: System::Windows::Forms::ComboBox^ comboBoxWeekSelect;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Payroll::typeid));
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelEmployeeNameSurname = (gcnew System::Windows::Forms::Label());
			this->labelRole = (gcnew System::Windows::Forms::Label());
			this->labelEmployeeRole = (gcnew System::Windows::Forms::Label());
			this->labelHours = (gcnew System::Windows::Forms::Label());
			this->textBoxWorkingHours = (gcnew System::Windows::Forms::TextBox());
			this->labelOvertime = (gcnew System::Windows::Forms::Label());
			this->textBoxOvertimeHours = (gcnew System::Windows::Forms::TextBox());
			this->buttonCalculateIncome = (gcnew System::Windows::Forms::Button());
			this->groupBoxIncome = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSaveIncome = (gcnew System::Windows::Forms::Button());
			this->labelPaidTax = (gcnew System::Windows::Forms::Label());
			this->labelPaidNet = (gcnew System::Windows::Forms::Label());
			this->labelPaidGross = (gcnew System::Windows::Forms::Label());
			this->labelTaxPaid = (gcnew System::Windows::Forms::Label());
			this->labelNet = (gcnew System::Windows::Forms::Label());
			this->labelGross = (gcnew System::Windows::Forms::Label());
			this->groupBoxHoursWorked = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxEmployee = (gcnew System::Windows::Forms::GroupBox());
			this->labelWeekSelect = (gcnew System::Windows::Forms::Label());
			this->comboBoxWeekSelect = (gcnew System::Windows::Forms::ComboBox());
			this->buttonAddHours = (gcnew System::Windows::Forms::Button());
			this->groupBoxEmployeeID = (gcnew System::Windows::Forms::GroupBox());
			this->buttonFindEmployee = (gcnew System::Windows::Forms::Button());
			this->textBoxEmployeeID = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxIncome->SuspendLayout();
			this->groupBoxHoursWorked->SuspendLayout();
			this->groupBoxEmployee->SuspendLayout();
			this->groupBoxEmployeeID->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(6, 25);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(38, 13);
			this->labelName->TabIndex = 1;
			this->labelName->Text = L"Name:";
			// 
			// labelEmployeeNameSurname
			// 
			this->labelEmployeeNameSurname->AutoSize = true;
			this->labelEmployeeNameSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelEmployeeNameSurname->Location = System::Drawing::Point(41, 20);
			this->labelEmployeeNameSurname->Name = L"labelEmployeeNameSurname";
			this->labelEmployeeNameSurname->Size = System::Drawing::Size(0, 20);
			this->labelEmployeeNameSurname->TabIndex = 2;
			// 
			// labelRole
			// 
			this->labelRole->AutoSize = true;
			this->labelRole->Location = System::Drawing::Point(12, 55);
			this->labelRole->Name = L"labelRole";
			this->labelRole->Size = System::Drawing::Size(32, 13);
			this->labelRole->TabIndex = 3;
			this->labelRole->Text = L"Role:";
			// 
			// labelEmployeeRole
			// 
			this->labelEmployeeRole->AutoSize = true;
			this->labelEmployeeRole->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEmployeeRole->Location = System::Drawing::Point(41, 52);
			this->labelEmployeeRole->Name = L"labelEmployeeRole";
			this->labelEmployeeRole->Size = System::Drawing::Size(0, 20);
			this->labelEmployeeRole->TabIndex = 4;
			// 
			// labelHours
			// 
			this->labelHours->AutoSize = true;
			this->labelHours->Location = System::Drawing::Point(59, 39);
			this->labelHours->Name = L"labelHours";
			this->labelHours->Size = System::Drawing::Size(81, 13);
			this->labelHours->TabIndex = 7;
			this->labelHours->Text = L"Working Hours:";
			// 
			// textBoxWorkingHours
			// 
			this->textBoxWorkingHours->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxWorkingHours->Location = System::Drawing::Point(146, 31);
			this->textBoxWorkingHours->MaxLength = 2;
			this->textBoxWorkingHours->Name = L"textBoxWorkingHours";
			this->textBoxWorkingHours->Size = System::Drawing::Size(59, 26);
			this->textBoxWorkingHours->TabIndex = 8;
			this->textBoxWorkingHours->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// labelOvertime
			// 
			this->labelOvertime->AutoSize = true;
			this->labelOvertime->Location = System::Drawing::Point(57, 69);
			this->labelOvertime->Name = L"labelOvertime";
			this->labelOvertime->Size = System::Drawing::Size(83, 13);
			this->labelOvertime->TabIndex = 9;
			this->labelOvertime->Text = L"Overtime Hours:";
			// 
			// textBoxOvertimeHours
			// 
			this->textBoxOvertimeHours->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxOvertimeHours->Location = System::Drawing::Point(146, 63);
			this->textBoxOvertimeHours->MaxLength = 2;
			this->textBoxOvertimeHours->Name = L"textBoxOvertimeHours";
			this->textBoxOvertimeHours->Size = System::Drawing::Size(59, 26);
			this->textBoxOvertimeHours->TabIndex = 10;
			this->textBoxOvertimeHours->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// buttonCalculateIncome
			// 
			this->buttonCalculateIncome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonCalculateIncome->Location = System::Drawing::Point(27, 94);
			this->buttonCalculateIncome->Name = L"buttonCalculateIncome";
			this->buttonCalculateIncome->Size = System::Drawing::Size(226, 36);
			this->buttonCalculateIncome->TabIndex = 11;
			this->buttonCalculateIncome->Text = L"Calculate Income";
			this->buttonCalculateIncome->UseVisualStyleBackColor = true;
			this->buttonCalculateIncome->Click += gcnew System::EventHandler(this, &Payroll::ButtonCalculateIncome_Click);
			// 
			// groupBoxIncome
			// 
			this->groupBoxIncome->Controls->Add(this->buttonSaveIncome);
			this->groupBoxIncome->Controls->Add(this->labelPaidTax);
			this->groupBoxIncome->Controls->Add(this->labelPaidNet);
			this->groupBoxIncome->Controls->Add(this->labelPaidGross);
			this->groupBoxIncome->Controls->Add(this->labelTaxPaid);
			this->groupBoxIncome->Controls->Add(this->labelNet);
			this->groupBoxIncome->Controls->Add(this->labelGross);
			this->groupBoxIncome->Location = System::Drawing::Point(56, 308);
			this->groupBoxIncome->Name = L"groupBoxIncome";
			this->groupBoxIncome->Size = System::Drawing::Size(480, 93);
			this->groupBoxIncome->TabIndex = 1;
			this->groupBoxIncome->TabStop = false;
			this->groupBoxIncome->Text = L"Income";
			this->groupBoxIncome->Visible = false;
			// 
			// buttonSaveIncome
			// 
			this->buttonSaveIncome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSaveIncome->Location = System::Drawing::Point(280, 51);
			this->buttonSaveIncome->Name = L"buttonSaveIncome";
			this->buttonSaveIncome->Size = System::Drawing::Size(143, 36);
			this->buttonSaveIncome->TabIndex = 12;
			this->buttonSaveIncome->Text = L"Save Income";
			this->buttonSaveIncome->UseVisualStyleBackColor = true;
			this->buttonSaveIncome->Click += gcnew System::EventHandler(this, &Payroll::ButtonSaveIncome_Click);
			// 
			// labelPaidTax
			// 
			this->labelPaidTax->AutoSize = true;
			this->labelPaidTax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPaidTax->ForeColor = System::Drawing::Color::Red;
			this->labelPaidTax->Location = System::Drawing::Point(143, 60);
			this->labelPaidTax->Name = L"labelPaidTax";
			this->labelPaidTax->Size = System::Drawing::Size(0, 20);
			this->labelPaidTax->TabIndex = 17;
			// 
			// labelPaidNet
			// 
			this->labelPaidNet->AutoSize = true;
			this->labelPaidNet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPaidNet->ForeColor = System::Drawing::Color::Green;
			this->labelPaidNet->Location = System::Drawing::Point(335, 22);
			this->labelPaidNet->Name = L"labelPaidNet";
			this->labelPaidNet->Size = System::Drawing::Size(0, 20);
			this->labelPaidNet->TabIndex = 16;
			// 
			// labelPaidGross
			// 
			this->labelPaidGross->AutoSize = true;
			this->labelPaidGross->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPaidGross->ForeColor = System::Drawing::Color::Blue;
			this->labelPaidGross->Location = System::Drawing::Point(143, 22);
			this->labelPaidGross->Name = L"labelPaidGross";
			this->labelPaidGross->Size = System::Drawing::Size(0, 20);
			this->labelPaidGross->TabIndex = 15;
			// 
			// labelTaxPaid
			// 
			this->labelTaxPaid->AutoSize = true;
			this->labelTaxPaid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTaxPaid->Location = System::Drawing::Point(64, 60);
			this->labelTaxPaid->Name = L"labelTaxPaid";
			this->labelTaxPaid->Size = System::Drawing::Size(73, 20);
			this->labelTaxPaid->TabIndex = 14;
			this->labelTaxPaid->Text = L"Tax Paid:";
			// 
			// labelNet
			// 
			this->labelNet->AutoSize = true;
			this->labelNet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelNet->Location = System::Drawing::Point(291, 22);
			this->labelNet->Name = L"labelNet";
			this->labelNet->Size = System::Drawing::Size(38, 20);
			this->labelNet->TabIndex = 13;
			this->labelNet->Text = L"Net:";
			// 
			// labelGross
			// 
			this->labelGross->AutoSize = true;
			this->labelGross->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGross->Location = System::Drawing::Point(81, 22);
			this->labelGross->Name = L"labelGross";
			this->labelGross->Size = System::Drawing::Size(56, 20);
			this->labelGross->TabIndex = 12;
			this->labelGross->Text = L"Gross:";
			// 
			// groupBoxHoursWorked
			// 
			this->groupBoxHoursWorked->Controls->Add(this->labelHours);
			this->groupBoxHoursWorked->Controls->Add(this->textBoxWorkingHours);
			this->groupBoxHoursWorked->Controls->Add(this->buttonCalculateIncome);
			this->groupBoxHoursWorked->Controls->Add(this->labelOvertime);
			this->groupBoxHoursWorked->Controls->Add(this->textBoxOvertimeHours);
			this->groupBoxHoursWorked->Location = System::Drawing::Point(309, 151);
			this->groupBoxHoursWorked->Name = L"groupBoxHoursWorked";
			this->groupBoxHoursWorked->Size = System::Drawing::Size(273, 140);
			this->groupBoxHoursWorked->TabIndex = 12;
			this->groupBoxHoursWorked->TabStop = false;
			this->groupBoxHoursWorked->Text = L"Weekly Hours";
			this->groupBoxHoursWorked->Visible = false;
			// 
			// groupBoxEmployee
			// 
			this->groupBoxEmployee->Controls->Add(this->labelWeekSelect);
			this->groupBoxEmployee->Controls->Add(this->comboBoxWeekSelect);
			this->groupBoxEmployee->Controls->Add(this->buttonAddHours);
			this->groupBoxEmployee->Controls->Add(this->labelEmployeeNameSurname);
			this->groupBoxEmployee->Controls->Add(this->labelName);
			this->groupBoxEmployee->Controls->Add(this->labelRole);
			this->groupBoxEmployee->Controls->Add(this->labelEmployeeRole);
			this->groupBoxEmployee->Location = System::Drawing::Point(12, 151);
			this->groupBoxEmployee->Name = L"groupBoxEmployee";
			this->groupBoxEmployee->Size = System::Drawing::Size(273, 140);
			this->groupBoxEmployee->TabIndex = 13;
			this->groupBoxEmployee->TabStop = false;
			this->groupBoxEmployee->Text = L"Employee";
			this->groupBoxEmployee->Visible = false;
			// 
			// labelWeekSelect
			// 
			this->labelWeekSelect->AutoSize = true;
			this->labelWeekSelect->Location = System::Drawing::Point(178, 44);
			this->labelWeekSelect->Name = L"labelWeekSelect";
			this->labelWeekSelect->Size = System::Drawing::Size(72, 13);
			this->labelWeekSelect->TabIndex = 14;
			this->labelWeekSelect->Text = L"Select Week:";
			// 
			// comboBoxWeekSelect
			// 
			this->comboBoxWeekSelect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxWeekSelect->FormattingEnabled = true;
			this->comboBoxWeekSelect->Items->AddRange(gcnew cli::array< System::Object^  >(52) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43", L"44",
					L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52"
			});
			this->comboBoxWeekSelect->Location = System::Drawing::Point(181, 60);
			this->comboBoxWeekSelect->Name = L"comboBoxWeekSelect";
			this->comboBoxWeekSelect->Size = System::Drawing::Size(64, 28);
			this->comboBoxWeekSelect->TabIndex = 12;
			// 
			// buttonAddHours
			// 
			this->buttonAddHours->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAddHours->Location = System::Drawing::Point(24, 94);
			this->buttonAddHours->Name = L"buttonAddHours";
			this->buttonAddHours->Size = System::Drawing::Size(226, 36);
			this->buttonAddHours->TabIndex = 13;
			this->buttonAddHours->Text = L"Add Weekly Hours";
			this->buttonAddHours->UseVisualStyleBackColor = true;
			this->buttonAddHours->Click += gcnew System::EventHandler(this, &Payroll::ButtonAddHours_Click);
			// 
			// groupBoxEmployeeID
			// 
			this->groupBoxEmployeeID->Controls->Add(this->buttonFindEmployee);
			this->groupBoxEmployeeID->Controls->Add(this->textBoxEmployeeID);
			this->groupBoxEmployeeID->Location = System::Drawing::Point(85, 27);
			this->groupBoxEmployeeID->Name = L"groupBoxEmployeeID";
			this->groupBoxEmployeeID->Size = System::Drawing::Size(399, 118);
			this->groupBoxEmployeeID->TabIndex = 14;
			this->groupBoxEmployeeID->TabStop = false;
			this->groupBoxEmployeeID->Text = L"Enter Employee ID:";
			// 
			// buttonFindEmployee
			// 
			this->buttonFindEmployee->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonFindEmployee->Location = System::Drawing::Point(95, 75);
			this->buttonFindEmployee->Name = L"buttonFindEmployee";
			this->buttonFindEmployee->Size = System::Drawing::Size(226, 36);
			this->buttonFindEmployee->TabIndex = 12;
			this->buttonFindEmployee->Text = L"Find Employee";
			this->buttonFindEmployee->UseVisualStyleBackColor = true;
			this->buttonFindEmployee->Click += gcnew System::EventHandler(this, &Payroll::ButtonFindEmployee_Click);
			// 
			// textBoxEmployeeID
			// 
			this->textBoxEmployeeID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxEmployeeID->Location = System::Drawing::Point(152, 19);
			this->textBoxEmployeeID->MaxLength = 3;
			this->textBoxEmployeeID->Name = L"textBoxEmployeeID";
			this->textBoxEmployeeID->Size = System::Drawing::Size(100, 50);
			this->textBoxEmployeeID->TabIndex = 0;
			this->textBoxEmployeeID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->helpToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(594, 24);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Payroll::HelpToolStripMenuItem_Click);
			// 
			// Payroll
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(594, 412);
			this->Controls->Add(this->groupBoxEmployeeID);
			this->Controls->Add(this->groupBoxEmployee);
			this->Controls->Add(this->groupBoxHoursWorked);
			this->Controls->Add(this->groupBoxIncome);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(610, 450);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(610, 450);
			this->Name = L"Payroll";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Payroll";
			this->Load += gcnew System::EventHandler(this, &Payroll::Payroll_Load);
			this->groupBoxIncome->ResumeLayout(false);
			this->groupBoxIncome->PerformLayout();
			this->groupBoxHoursWorked->ResumeLayout(false);
			this->groupBoxHoursWorked->PerformLayout();
			this->groupBoxEmployee->ResumeLayout(false);
			this->groupBoxEmployee->PerformLayout();
			this->groupBoxEmployeeID->ResumeLayout(false);
			this->groupBoxEmployeeID->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/* Method on load: here we will read csv file with all employees*/
	private: System::Void Payroll_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void HelpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("User Help:\n\n1. Enter Employee Id.\n2. Click 'Find Employee' button.\n3. Select week number from dropdown list.\n4. Click 'Add Weekly Hours' button.\n5. Fill in weekly hours and weekly overtime worked.\n6. Click 'Calculate Income' button.\n7. Click 'Save Income' button to save employee income.");
	}

	private: System::Void ButtonFindEmployee_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ enteredId;

		if ((System::Text::RegularExpressions::Regex::IsMatch(textBoxEmployeeID->Text, "^[0-9]"))) {

			enteredId = textBoxEmployeeID->Text;

			if (isIdExisting(enteredId) == true) {
				// show employee if his ID is found, hide button buttonFindEmployee
				groupBoxEmployee->Visible = true;
				buttonFindEmployee->Enabled = false;
				textBoxEmployeeID->Enabled = false;

				// display name and surname with this Id
				labelEmployeeNameSurname->Text = registeredEmployee->getFirstName() + " " + registeredEmployee->getLastName();
				labelEmployeeRole->Text = registeredEmployee->getRole();
			}
			else
			{
				// display error
				MessageBox::Show("Invalid user Id.");
			}
		}
		else {
			MessageBox::Show("This is not employee ID.");
		}
	}

	private: System::Void ButtonAddHours_Click(System::Object^ sender, System::EventArgs^ e) {
		// check if the week is selected (comboBoxWeekSelect) if not selected display error
		if (this->comboBoxWeekSelect->SelectedIndex == -1) {
			MessageBox::Show("Please select working week.");
		}
		else
		{
			// make input for working hours visible (groupBoxHoursWorked)
			groupBoxHoursWorked->Visible = true;
			// disable add hours button
			buttonAddHours->Enabled = false;
			// disable comboBox
			comboBoxWeekSelect->Enabled = false;
		}
	}

	private: System::Void ButtonCalculateIncome_Click(System::Object^ sender, System::EventArgs^ e) {

		if (textBoxWorkingHours->TextLength == 0 || textBoxOvertimeHours->TextLength == 0) {
			MessageBox::Show("Please fill in the working hours.");
		}
		else {
			// Calculation
			if ((System::Text::RegularExpressions::Regex::IsMatch(textBoxWorkingHours->Text, "^[0-9]")) &&
				(System::Text::RegularExpressions::Regex::IsMatch(textBoxOvertimeHours->Text, "^[0-9]"))) {

				enteredHours = Convert::ToDouble(textBoxWorkingHours->Text);
				enteredOvertime = Convert::ToDouble(textBoxOvertimeHours->Text);

				gross = (enteredHours * registeredEmployee->getRate()) + (enteredOvertime * (registeredEmployee->getRate() * 1.5));
				//gross = (enteredHours * 19.55) + (enteredOvertime * 29.325);
				tax = gross * 0.23;
				net = gross - tax;
				roundedGross = floor((gross * 100) + 0.5) / 100;
				roundedNet = floor((net * 100) + 0.5) / 100;
				roundedTax = floor((tax * 100) + 0.5) / 100;
				// display rounded gross, net and tax paid
				labelPaidGross->Text = roundedGross.ToString();
				labelPaidNet->Text = roundedNet.ToString();
				labelPaidTax->Text = roundedTax.ToString();

				// make Income visible and display gross, net and tax paid (groupBoxIncome)
				groupBoxIncome->Visible = true;
				// disable two textboxes for input and button for calulating hours
				textBoxWorkingHours->Enabled = false;
				textBoxOvertimeHours->Enabled = false;
				buttonCalculateIncome->Enabled = false;
			}
			else {
				MessageBox::Show("This is not a valid number of hours");
				textBoxWorkingHours->Text = "";
				textBoxOvertimeHours->Text = "";
			}
		}
	}

	private: System::Void ButtonSaveIncome_Click(System::Object ^ sender, System::EventArgs ^ e) {

		// Weekly Hours,Week Number,Weekly Overtime,Weekly Gross,Weekly Net,Weekly Tax
		registeredEmployee->setHours(Double::Parse(textBoxWorkingHours->Text));
		registeredEmployee->setWeekNumber(int::Parse(comboBoxWeekSelect->SelectedItem->ToString()));
		registeredEmployee->setOvertime(Double::Parse(textBoxOvertimeHours->Text));
		registeredEmployee->setGross(roundedGross);
		registeredEmployee->setNet(roundedNet);
		registeredEmployee->setWeeklyTax(roundedTax);

		// save values to the csv file for selected employee
		CSVManipulator manipulator;
		manipulator.SaveData(registeredEmployee);

		// hide groupBoxEmployee, groupBoxHoursWorked, groupBoxIncome
		groupBoxEmployee->Visible = false;
		groupBoxHoursWorked->Visible = false;
		groupBoxIncome->Visible = false;

		// enable all buttons, clear values and enable all textboxes
		buttonAddHours->Enabled = true;
		buttonFindEmployee->Enabled = true;
		buttonCalculateIncome->Enabled = true;
		textBoxEmployeeID->Text = "";
		textBoxWorkingHours->Text = "";
		textBoxOvertimeHours->Text = "";
		textBoxEmployeeID->Enabled = true;
		textBoxWorkingHours->Enabled = true;
		textBoxOvertimeHours->Enabled = true;
		comboBoxWeekSelect->SelectedIndex = -1;
		comboBoxWeekSelect->Enabled = true;

		// display success dialog
		MessageBox::Show("Employee income saved successfuly");
	}

			 bool isIdExisting(String ^ number) {

				 for each (Employee ^ var in employees)
				 {
					 if (var->getId() == number) {
						 registeredEmployee = var;

						 return true;
					 }
				 }

				 return false;
			 }

	}; // class end Payroll

}// namespace end PawelPayroll