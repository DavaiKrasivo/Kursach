#pragma once
#include <conio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	std::ofstream base_out;
	struct house
	{
		int region;
		int room;
		int squareMin;
		int pharmacy;
		int school;
		int Kindergarten;
		int atm;
		int hospital;
		int shop;
		int intercom;
		int centr, kurch, lenin, chtz, sovet, met, kall;
		int room2;
		int squareMin2;
		int squareMax2;
		int pharmacy2;
		int school2;
		int Kindergarten2;
		int atm2;
		int hospital2;
		int shop2;
		int intercom2;
	};
	std::ostream& operator << (std::ostream& os, const house& myList) {
		os << myList.region << " " << myList.room << " " << myList.squareMin
			<< " " << myList.school << " " << myList.pharmacy << " " << myList.Kindergarten
			<< " " << myList.atm << " " << myList.hospital << " " << myList.shop << " " << myList.intercom
			<< " " << myList.met << " " << myList.kurch << " " << myList.kall << " " << myList.chtz << " " << myList.centr
			<< " " << myList.sovet << " " << myList.lenin << " " << myList.room2 << " " << myList.squareMin2 << " " << myList.school2
			<< " " << myList.pharmacy2 << " " << myList.Kindergarten2 << " " << myList.atm2 << " " << myList.hospital2
			<< " " << myList.shop2 << " " << myList.intercom2 << " " << myList.squareMax2 << std::endl;
		return os;
	}
	std::list < struct house> myList;
	house client, buff;
	bool badV(house &tmp, house &cl)
	{
		int flagtime = 0;
		switch (tmp.region)
		{
		case 0: 
			if (tmp.met) 
			{
				flagtime = 1;
			}
		case 1:
			if (tmp.kurch)
			{
				flagtime = 1;
			}
		case 2:
			if (tmp.kall)
			{
				flagtime = 1;
			}
		case 3:
			if (tmp.chtz)
			{
				flagtime = 1;
			}
		case 4:
			if (tmp.centr)
			{
				flagtime = 1;
			}
		case 5:
			if (tmp.sovet)
			{
				flagtime = 1;
			}
		case 6:
			if (tmp.lenin)
			{
				flagtime = 1;
			}
		default:
			break;
		}
		return ((flagtime) & (tmp.room == cl.room2) &(tmp.squareMin <= cl.squareMax2)&
			(tmp.squareMin >= cl.squareMin2) & (tmp.pharmacy == cl.pharmacy2) & (tmp.school == cl.school2)
			&  (tmp.Kindergarten == cl.Kindergarten2) & (tmp.atm == cl.atm2) & (tmp.hospital == cl.hospital2)
			& (tmp.shop == cl.shop2) & (tmp.intercom == cl.intercom2)
			& (tmp.room2 == cl.room) & (tmp.squareMin2 <= cl.squareMin) &(tmp.squareMax2 >= cl.squareMin)
			& (tmp.pharmacy2 == cl.pharmacy) & (tmp.school2 == cl.school) &  (tmp.Kindergarten2 == cl.Kindergarten)
			& (tmp.atm2 == cl.atm) & (tmp.hospital2 == cl.hospital) & (tmp.shop2 == cl.shop)
			& (tmp.intercom2 == cl.intercom));
	}
	int find(std::list<house> &a,house b)
	{
		std::list<house>::iterator iter;
		for (iter = a.begin(); iter != a.end();)
		{
			if (badV(*iter, b)) return 1;
			else ++iter;
		}
		return 0;
	}
	void del(std::list<house> &a, house b)
	{
		std::list<house>::iterator iter;
		for (iter = a.begin(); iter != a.end();)
		{
			if (badV(*iter, b)) { a.erase(iter); break; }
			else ++iter;
		}
	}
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			std::ifstream base;
			base.open("base.txt");
			while (!base.eof())
			{
				base >> buff.region >> buff.room >> buff.squareMin >> buff.school >> buff.pharmacy 
					>> buff.Kindergarten >> buff.atm >> buff.hospital >> buff.shop >> buff.intercom  
					>> buff.met >> buff.kurch >> buff.kall >> buff.chtz >> buff.centr
					>> buff.sovet >> buff.lenin >> buff.room2 >> buff.squareMin2 >> buff.school2 >> buff.pharmacy2
					>> buff.Kindergarten2 >> buff.atm2 >> buff.hospital2 >> buff.shop2 >> buff.intercom2 >> buff.squareMax2;
				myList.push_front(buff);
			}
			base.close();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckedListBox^  etc;
	protected:

	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::ComboBox^  comboBox1;





	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckedListBox^  etc2;


	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;


	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->etc = (gcnew System::Windows::Forms::CheckedListBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->etc2 = (gcnew System::Windows::Forms::CheckedListBox());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->etc);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 35);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(408, 319);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ваша квартира";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 91);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Доп параметры";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(298, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Площадь";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(177, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Кол-во комнат";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Район";
			// 
			// etc
			// 
			this->etc->FormattingEnabled = true;
			this->etc->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Школа", L"Аптека", L"Детский сад", L"Банкомат", L"Больница",
					L"Продуктовый магазин", L"Домофон"
			});
			this->etc->Location = System::Drawing::Point(14, 110);
			this->etc->Name = L"etc";
			this->etc->Size = System::Drawing::Size(158, 109);
			this->etc->TabIndex = 9;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(301, 46);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(77, 20);
			this->numericUpDown2->TabIndex = 8;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(180, 46);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(80, 20);
			this->numericUpDown1->TabIndex = 7;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Металлургический", L"Курчатовский", L"Калининский",
					L"Тракторозаводский", L"Центральный", L"Советский", L"Ленинский"
			});
			this->comboBox1->Location = System::Drawing::Point(13, 46);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(454, 387);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Обмен";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkedListBox1);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->numericUpDown5);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->etc2);
			this->groupBox2->Controls->Add(this->numericUpDown3);
			this->groupBox2->Controls->Add(this->numericUpDown4);
			this->groupBox2->Location = System::Drawing::Point(426, 35);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(408, 319);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Укажите квартиру,которую Вы хотите";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(339, 45);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"—";
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(351, 45);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(45, 20);
			this->numericUpDown5->TabIndex = 14;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(11, 188);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Доп параметры";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(291, 29);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Площадь";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(177, 29);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(81, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Кол-во комнат";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(11, 30);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(38, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Район";
			// 
			// etc2
			// 
			this->etc2->FormattingEnabled = true;
			this->etc2->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Школа", L"Аптека", L"Детский сад", L"Банкомат", L"Больница",
					L"Продуктовый магазин", L"Домофон"
			});
			this->etc2->Location = System::Drawing::Point(14, 204);
			this->etc2->Name = L"etc2";
			this->etc2->Size = System::Drawing::Size(157, 109);
			this->etc2->TabIndex = 9;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(294, 45);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(45, 20);
			this->numericUpDown3->TabIndex = 8;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(180, 46);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(80, 20);
			this->numericUpDown4->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(325, 387);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 14;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Металлургический", L"Курчатовский", L"Калининский",
					L"Тракторозаводский", L"Центральный", L"Советский", L"Ленинский"
			});
			this->checkedListBox1->Location = System::Drawing::Point(14, 46);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(138, 109);
			this->checkedListBox1->TabIndex = 16;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(845, 422);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		client.room = System::Convert::ToInt32(numericUpDown1->Text);
		client.region = System::Convert::ToInt32(comboBox1->SelectedIndex);
		client.squareMin = System::Convert::ToInt32(numericUpDown2->Text);
		if (etc->GetItemChecked(0))
			client.school = 1;
		else client.school = 0;
		if (etc->GetItemChecked(1))
			client.pharmacy = 1;
		else client.pharmacy = 0;
		if (etc->GetItemChecked(2))
			client.Kindergarten = 1;
		else client.Kindergarten = 0;
		if (etc->GetItemChecked(3))
			client.atm = 1;
		else client.atm = 0;
		if (etc->GetItemChecked(4))
			client.hospital = 1;
		else client.hospital = 0;
		if (etc->GetItemChecked(5))
			client.shop = 1;
		else client.shop = 0;
		if (etc->GetItemChecked(6))
			client.intercom = 1;
		else client.intercom = 0;
		client.room2 = System::Convert::ToInt32(numericUpDown4->Text);
		if (checkedListBox1->GetItemChecked(0))
			client.met = 1;
		else client.met = 0;
		if (checkedListBox1->GetItemChecked(1))
			client.kurch = 1;
		else client.kurch = 0;
		if (checkedListBox1->GetItemChecked(2))
			client.kall = 1;
		else client.kall = 0;
		if (checkedListBox1->GetItemChecked(3))
			client.chtz = 1;
		else client.chtz = 0;
		if (checkedListBox1->GetItemChecked(4))
			client.centr = 1;
		else client.centr = 0;
		if (checkedListBox1->GetItemChecked(5))
			client.sovet = 1;
		else client.sovet = 0;
		if (checkedListBox1->GetItemChecked(6))
			client.lenin = 1;
		else client.lenin = 0;
		client.squareMin2 = System::Convert::ToInt32(numericUpDown3->Text);
		client.squareMax2 = System::Convert::ToInt32(numericUpDown5->Text);
		if (etc2->GetItemChecked(0))
			client.school2 = 1;
		else client.school2 = 0;
		if (etc2->GetItemChecked(1))
			client.pharmacy2 = 1;
		else client.pharmacy2 = 0;
		if (etc2->GetItemChecked(2))
			client.Kindergarten2 = 1;
		else client.Kindergarten2 = 0;
		if (etc2->GetItemChecked(3))
			client.atm2 = 1;
		else client.atm2 = 0;
		if (etc2->GetItemChecked(4))
			client.hospital2 = 1;
		else client.hospital2 = 0;
		if (etc2->GetItemChecked(5))
			client.shop2 = 1;
		else client.shop2 = 0;
		if (etc2->GetItemChecked(6))
			client.intercom2 = 1;
		else client.intercom2 = 0;
		
		if (find(myList,client))
		{
			del(myList, client);
			base_out.open("Archive.txt",std::ios::app);
			base_out << client.region << " " << client.room << " " << client.squareMin
				<< " " << client.school << " " << client.pharmacy << " " << client.Kindergarten
				<< " " << client.atm << " " << client.hospital << " " << client.shop << " " << client.intercom
				<< " " << client.met << " " << client.kurch << " " << client.kall << " " << client.chtz << " " << client.centr
				<< " " << client.sovet << " " << client.lenin << " " << client.room2 << " " << client.squareMin2 << " " << client.school2
				<< " " << client.pharmacy2 << " " << client.Kindergarten2 << " " << client.atm2 << " " << client.hospital2
				<< " " << client.shop2 << " " << client.intercom2 << " " << client.squareMax2 << std::endl;
			base_out.close();
			MessageBox::Show("Обмен состоялся", "Результат");
		}
		else
		{
			MessageBox::Show("Извините, но по Вашему запросу ничего не найдено ", "Результат");
		}
		base_out.open("base.txt");
		std::list<struct house>::const_iterator it = myList.begin();
		base_out << *it;
		std::advance(it, 3);
		for (it;it!=myList.end();it++) {
			base_out << *it;
		}
		base_out.close();
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	client.room = System::Convert::ToInt32(numericUpDown1->Text);
	client.region = System::Convert::ToInt32(comboBox1->SelectedIndex);
	client.squareMin = System::Convert::ToInt32(numericUpDown2->Text);
	if (etc->GetItemChecked(0))
		client.school = 1;
	else client.school = 0;
	if (etc->GetItemChecked(1))
		client.pharmacy = 1;
	else client.pharmacy = 0;
	if (etc->GetItemChecked(2))
		client.Kindergarten = 1;
	else client.Kindergarten = 0;
	if (etc->GetItemChecked(3))
		client.atm = 1;
	else client.atm = 0;
	if (etc->GetItemChecked(4))
		client.hospital = 1;
	else client.hospital = 0;
	if (etc->GetItemChecked(5))
		client.shop = 1;
	else client.shop = 0;
	if (etc->GetItemChecked(6))
		client.intercom = 1;
	else client.intercom = 0;
	client.room2 = System::Convert::ToInt32(numericUpDown4->Text);
	if (checkedListBox1->GetItemChecked(0))
		client.met = 1;
	else client.met = 0;
	if (checkedListBox1->GetItemChecked(1))
		client.kurch = 1;
	else client.kurch = 0;
	if (checkedListBox1->GetItemChecked(2))
		client.kall = 1;
	else client.kall = 0;
	if (checkedListBox1->GetItemChecked(3))
		client.chtz = 1;
	else client.chtz = 0;
	if (checkedListBox1->GetItemChecked(4))
		client.centr = 1;
	else client.centr = 0;
	if (checkedListBox1->GetItemChecked(5))
		client.sovet = 1;
	else client.sovet = 0;
	if (checkedListBox1->GetItemChecked(6))
		client.lenin = 1;
	else client.lenin = 0;
	client.squareMin2 = System::Convert::ToInt32(numericUpDown3->Text);
	client.squareMax2 = System::Convert::ToInt32(numericUpDown5->Text);
	if (etc2->GetItemChecked(0))
		client.school2 = 1;
	else client.school2 = 0;
	if (etc2->GetItemChecked(1))
		client.pharmacy2 = 1;
	else client.pharmacy2 = 0;
	if (etc2->GetItemChecked(2))
		client.Kindergarten2 = 1;
	else client.Kindergarten2 = 0;
	if (etc2->GetItemChecked(3))
		client.atm2 = 1;
	else client.atm2 = 0;
	if (etc2->GetItemChecked(4))
		client.hospital2 = 1;
	else client.hospital2 = 0;
	if (etc2->GetItemChecked(5))
		client.shop2 = 1;
	else client.shop2 = 0;
	if (etc2->GetItemChecked(6))
		client.intercom2 = 1;
	else client.intercom2 = 0;
	base_out.open("base.txt", std::ios::app);
	base_out << client.region << " " << client.room << " " << client.squareMin
		<< " " << client.school << " " << client.pharmacy << " " << client.Kindergarten
		<< " " << client.atm << " " << client.hospital << " " << client.shop << " " << client.intercom
		<< " " << client.met << " " << client.kurch << " " << client.kall << " " << client.chtz << " " << client.centr
		<< " " << client.sovet << " " << client.lenin << " " << client.room2 << " " << client.squareMin2 
		<< " " << client.school2
		<< " " << client.pharmacy2 << " " << client.Kindergarten2 << " " << client.atm2 << " " << client.hospital2
		<< " " << client.shop2 << " " << client.intercom2 << " " << client.squareMax2 << std::endl;
	base_out.close();
}
};
}
