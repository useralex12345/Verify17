#pragma once

#include "manager.h"

namespace Rails {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormStation
	/// </summary>
	public ref class FormStation : public System::Windows::Forms::Form
	{
		station^ target_station;
	public:
		FormStation(station^ target_station) : target_station(target_station)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormStation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  text_pcoupe;
	protected: 
	private: System::Windows::Forms::TextBox^  text_preserved;
	private: System::Windows::Forms::TextBox^  text_pseat;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  text_profit;
	private: System::Windows::Forms::TextBox^  text_denied;
	private: System::Windows::Forms::TextBox^  text_special;
	private: System::Windows::Forms::TextBox^  text_lcoupe;
	private: System::Windows::Forms::TextBox^  text_lreserved;
	private: System::Windows::Forms::TextBox^  text_lseat;
	private: System::Windows::Forms::TextBox^  text_load;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  text_name;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->text_pcoupe = (gcnew System::Windows::Forms::TextBox());
			this->text_preserved = (gcnew System::Windows::Forms::TextBox());
			this->text_pseat = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->text_profit = (gcnew System::Windows::Forms::TextBox());
			this->text_denied = (gcnew System::Windows::Forms::TextBox());
			this->text_special = (gcnew System::Windows::Forms::TextBox());
			this->text_lcoupe = (gcnew System::Windows::Forms::TextBox());
			this->text_lreserved = (gcnew System::Windows::Forms::TextBox());
			this->text_lseat = (gcnew System::Windows::Forms::TextBox());
			this->text_load = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->text_name = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// text_pcoupe
			// 
			this->text_pcoupe->Location = System::Drawing::Point(127, 189);
			this->text_pcoupe->Name = L"text_pcoupe";
			this->text_pcoupe->ReadOnly = true;
			this->text_pcoupe->Size = System::Drawing::Size(145, 20);
			this->text_pcoupe->TabIndex = 39;
			// 
			// text_preserved
			// 
			this->text_preserved->Location = System::Drawing::Point(127, 167);
			this->text_preserved->Name = L"text_preserved";
			this->text_preserved->ReadOnly = true;
			this->text_preserved->Size = System::Drawing::Size(145, 20);
			this->text_preserved->TabIndex = 38;
			// 
			// text_pseat
			// 
			this->text_pseat->Location = System::Drawing::Point(127, 145);
			this->text_pseat->Name = L"text_pseat";
			this->text_pseat->ReadOnly = true;
			this->text_pseat->Size = System::Drawing::Size(145, 20);
			this->text_pseat->TabIndex = 37;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(13, 189);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 13);
			this->label8->TabIndex = 36;
			this->label8->Text = L" * Купе";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(13, 145);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(59, 13);
			this->label9->TabIndex = 35;
			this->label9->Text = L" * Сидячие";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(13, 167);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(66, 13);
			this->label10->TabIndex = 34;
			this->label10->Text = L" * Плацкарт";
			// 
			// text_profit
			// 
			this->text_profit->Location = System::Drawing::Point(127, 123);
			this->text_profit->Name = L"text_profit";
			this->text_profit->ReadOnly = true;
			this->text_profit->Size = System::Drawing::Size(145, 20);
			this->text_profit->TabIndex = 33;
			// 
			// text_denied
			// 
			this->text_denied->Location = System::Drawing::Point(127, 239);
			this->text_denied->Name = L"text_denied";
			this->text_denied->ReadOnly = true;
			this->text_denied->Size = System::Drawing::Size(145, 20);
			this->text_denied->TabIndex = 32;
			// 
			// text_special
			// 
			this->text_special->Location = System::Drawing::Point(127, 216);
			this->text_special->Name = L"text_special";
			this->text_special->ReadOnly = true;
			this->text_special->Size = System::Drawing::Size(145, 20);
			this->text_special->TabIndex = 31;
			// 
			// text_lcoupe
			// 
			this->text_lcoupe->Location = System::Drawing::Point(127, 95);
			this->text_lcoupe->Name = L"text_lcoupe";
			this->text_lcoupe->ReadOnly = true;
			this->text_lcoupe->Size = System::Drawing::Size(145, 20);
			this->text_lcoupe->TabIndex = 30;
			// 
			// text_lreserved
			// 
			this->text_lreserved->Location = System::Drawing::Point(127, 73);
			this->text_lreserved->Name = L"text_lreserved";
			this->text_lreserved->ReadOnly = true;
			this->text_lreserved->Size = System::Drawing::Size(145, 20);
			this->text_lreserved->TabIndex = 29;
			// 
			// text_lseat
			// 
			this->text_lseat->Location = System::Drawing::Point(127, 51);
			this->text_lseat->Name = L"text_lseat";
			this->text_lseat->ReadOnly = true;
			this->text_lseat->Size = System::Drawing::Size(145, 20);
			this->text_lseat->TabIndex = 28;
			// 
			// text_load
			// 
			this->text_load->Location = System::Drawing::Point(127, 28);
			this->text_load->Name = L"text_load";
			this->text_load->ReadOnly = true;
			this->text_load->Size = System::Drawing::Size(145, 20);
			this->text_load->TabIndex = 27;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 95);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L" * Купе";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 51);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L" * Сидячие";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 73);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L" * Плацкарт";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(13, 212);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 29);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Требующих доп. оборудование";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 241);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Отклонено";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Выручка";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Загруженность";
			// 
			// text_name
			// 
			this->text_name->Location = System::Drawing::Point(16, 5);
			this->text_name->Name = L"text_name";
			this->text_name->ReadOnly = true;
			this->text_name->Size = System::Drawing::Size(256, 20);
			this->text_name->TabIndex = 40;
			this->text_name->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// FormStation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->text_name);
			this->Controls->Add(this->text_pcoupe);
			this->Controls->Add(this->text_preserved);
			this->Controls->Add(this->text_pseat);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->text_profit);
			this->Controls->Add(this->text_denied);
			this->Controls->Add(this->text_special);
			this->Controls->Add(this->text_lcoupe);
			this->Controls->Add(this->text_lreserved);
			this->Controls->Add(this->text_lseat);
			this->Controls->Add(this->text_load);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormStation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Статистика станции";
			this->Load += gcnew System::EventHandler(this, &FormStation::FormStation_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void FormStation_Load(System::Object^ sender, System::EventArgs^ e) {
			int load         = 0;
			int load_max     = 0;
			int seat         = 0;
			int seat_max     = 0;
			int reserved     = 0;
			int reserved_max = 0;
			int coupe        = 0;
			int coupe_max    = 0;

			int profit       = 0;
			int pseat        = 0;
			int preserved    = 0;
			int pcoupe       = 0;
			
			int special      = 0;
			int denied       = 0;

			special += target_station->get_specials();
			denied  += target_station->get_denied();

			for(int j = 0; j < target_station->get_trains()->Count; ++j) {
				train^ target_train = target_station->get_trains()[j];

				for(int k = 0; k < target_train->get_carriages()->Count; ++k) {
					carriage_base^ target_carriage = target_train->get_carriages()[k];

					switch(target_carriage->get_type()) {
					case carriage_type::SEAT:
						{
							passenger_carriage^ tmp = dynamic_cast<passenger_carriage^>(target_carriage);
							seat_max += tmp->get_places();
							seat += tmp->get_buyed();

							load_max += tmp->get_places();
							load += tmp->get_buyed();

							pseat += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
							profit += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
						}
						break;
					case carriage_type::RESERVED:
						{
							passenger_carriage^ tmp = dynamic_cast<passenger_carriage^>(target_carriage);
							reserved_max += tmp->get_places();
							reserved += tmp->get_buyed();

							load_max += tmp->get_places();
							load += tmp->get_buyed();

							preserved += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
							profit += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
						}
						break;
					case carriage_type::COUPE:
						{
							passenger_carriage^ tmp = dynamic_cast<passenger_carriage^>(target_carriage);
							coupe_max += tmp->get_places();
							coupe += tmp->get_buyed();

							load_max += tmp->get_places();
							load += tmp->get_buyed();

							pcoupe += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
							profit += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
						}
						break;
					}
				}
			}

			this->text_name->Text = target_station->get_name();
			this->text_load->Text = String::Format(L"{0}/{1}", load, load_max);
			this->text_lseat->Text = String::Format(L"{0}/{1}", seat, seat_max);
			this->text_lreserved->Text = String::Format(L"{0}/{1}", reserved, reserved_max);
			this->text_lcoupe->Text = String::Format(L"{0}/{1}", coupe, coupe_max);
			this->text_profit->Text = String::Format(L"{0}", profit);
			this->text_pseat->Text = String::Format(L"{0}", pseat);
			this->text_preserved->Text = String::Format(L"{0}", preserved);
			this->text_pcoupe->Text = String::Format(L"{0}", pcoupe);
			this->text_special->Text = String::Format(L"{0}", special);
			this->text_denied->Text = String::Format(L"{0}", denied);
		}
	};
}
