#pragma once

namespace Rails {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormCarriage
	/// </summary>
	public ref class FormCarriage : public System::Windows::Forms::Form
	{
		train^ target_train;
		carriage_base^ target_carriage;
	public:
		FormCarriage(train^ target_train, carriage_base^ target_carriage) : target_train(target_train), target_carriage(target_carriage)
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
		~FormCarriage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  text_name;
	protected: 






	private: System::Windows::Forms::TextBox^  text_profit;





	private: System::Windows::Forms::TextBox^  text_load;





	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  text_type;
	private: System::Windows::Forms::Label^  label3;

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
			this->text_name = (gcnew System::Windows::Forms::TextBox());
			this->text_profit = (gcnew System::Windows::Forms::TextBox());
			this->text_load = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->text_type = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// text_name
			// 
			this->text_name->Location = System::Drawing::Point(16, 4);
			this->text_name->Name = L"text_name";
			this->text_name->ReadOnly = true;
			this->text_name->Size = System::Drawing::Size(256, 20);
			this->text_name->TabIndex = 61;
			this->text_name->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// text_profit
			// 
			this->text_profit->Location = System::Drawing::Point(127, 87);
			this->text_profit->Name = L"text_profit";
			this->text_profit->ReadOnly = true;
			this->text_profit->Size = System::Drawing::Size(145, 20);
			this->text_profit->TabIndex = 54;
			// 
			// text_load
			// 
			this->text_load->Location = System::Drawing::Point(127, 62);
			this->text_load->Name = L"text_load";
			this->text_load->ReadOnly = true;
			this->text_load->Size = System::Drawing::Size(145, 20);
			this->text_load->TabIndex = 48;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 42;
			this->label2->Text = L"Выручка";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 41;
			this->label1->Text = L"Загруженность";
			// 
			// text_type
			// 
			this->text_type->Location = System::Drawing::Point(127, 37);
			this->text_type->Name = L"text_type";
			this->text_type->ReadOnly = true;
			this->text_type->Size = System::Drawing::Size(145, 20);
			this->text_type->TabIndex = 63;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 13);
			this->label3->TabIndex = 62;
			this->label3->Text = L"Тип";
			// 
			// FormCarriage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->text_type);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->text_name);
			this->Controls->Add(this->text_profit);
			this->Controls->Add(this->text_load);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormCarriage";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Статистика вагона";
			this->Load += gcnew System::EventHandler(this, &FormCarriage::FormCarriage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void FormCarriage_Load(System::Object^  sender, System::EventArgs^  e) {
			int load         = 0;
			int load_max     = 0;
			int profit       = 0;

			switch(target_carriage->get_type()) {
			case carriage_type::SEAT:
				{
					passenger_carriage^ tmp = dynamic_cast<passenger_carriage^>(target_carriage);
					load_max += tmp->get_places();
					load += tmp->get_buyed();

					profit += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
				}
				break;
			case carriage_type::RESERVED:
				{
					passenger_carriage^ tmp = dynamic_cast<passenger_carriage^>(target_carriage);

					load_max += tmp->get_places();
					load += tmp->get_buyed();

					profit += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
				}
				break;
			case carriage_type::COUPE:
				{
					passenger_carriage^ tmp = dynamic_cast<passenger_carriage^>(target_carriage);

					load_max += tmp->get_places();
					load += tmp->get_buyed();

					profit += tmp->get_buyed() * target_train->get_cost(tmp->get_price());
				}
				break;
			}

			this->text_name->Text = String::Format(L"Вагон №{0} (№{1} {2} - {3})", target_carriage->get_number(), target_train->get_number(), target_train->get_stantion_dispatch()->get_name(), target_train->get_stantion_arrival()->get_name());
			switch(target_carriage->get_type()) {
			case carriage_type::SEAT:
				this->text_type->Text = L"Сидячий";
				break;
			case carriage_type::RESERVED:
				this->text_type->Text = L"Плацкарт";
				break;
			case carriage_type::COUPE:
				this->text_type->Text = L"Купе";
				break;
			}
			this->text_load->Text = String::Format(L"{0}/{1}", load, load_max);
			this->text_profit->Text = String::Format(L"{0}", profit);
		 }
	};
}
