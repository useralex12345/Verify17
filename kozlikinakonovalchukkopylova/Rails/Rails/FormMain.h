#pragma once

#include "manager.h"
#include "FormSummary.h"
#include "FormStation.h"
#include "FormTrain.h"
#include "FormCarriage.h"

namespace Rails {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormMain
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		FormMain(void) : selected_station(nullptr), selected_train(nullptr), selected_carriage(nullptr)
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
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  list_stations;
	protected: 
	private: System::Windows::Forms::Label^  label_stations;
	private: System::Windows::Forms::Label^  label_trains;
	private: System::Windows::Forms::ListBox^  list_trains;
	private: System::Windows::Forms::Label^  label_carriages;
	private: System::Windows::Forms::ListBox^  list_carriages;
	private: System::Windows::Forms::Button^  btn_all;
	private: System::Windows::Forms::Button^  btn_train;
	private: System::Windows::Forms::Button^  btn_carriage;
	private: System::Windows::Forms::Button^  btn_quit;
	private: System::Windows::Forms::Button^  btn_station;
	private: System::Windows::Forms::Button^  btn_refresh;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			this->list_stations = (gcnew System::Windows::Forms::ListBox());
			this->label_stations = (gcnew System::Windows::Forms::Label());
			this->label_trains = (gcnew System::Windows::Forms::Label());
			this->list_trains = (gcnew System::Windows::Forms::ListBox());
			this->label_carriages = (gcnew System::Windows::Forms::Label());
			this->list_carriages = (gcnew System::Windows::Forms::ListBox());
			this->btn_all = (gcnew System::Windows::Forms::Button());
			this->btn_train = (gcnew System::Windows::Forms::Button());
			this->btn_carriage = (gcnew System::Windows::Forms::Button());
			this->btn_quit = (gcnew System::Windows::Forms::Button());
			this->btn_station = (gcnew System::Windows::Forms::Button());
			this->btn_refresh = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// list_stations
			// 
			this->list_stations->FormattingEnabled = true;
			this->list_stations->Location = System::Drawing::Point(13, 39);
			this->list_stations->Name = L"list_stations";
			this->list_stations->Size = System::Drawing::Size(160, 511);
			this->list_stations->TabIndex = 0;
			this->list_stations->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::list_station_Selected);
			// 
			// label_stations
			// 
			this->label_stations->AutoSize = true;
			this->label_stations->Location = System::Drawing::Point(13, 13);
			this->label_stations->Name = L"label_stations";
			this->label_stations->Size = System::Drawing::Size(52, 13);
			this->label_stations->TabIndex = 1;
			this->label_stations->Text = L"Станции:";
			// 
			// label_trains
			// 
			this->label_trains->AutoSize = true;
			this->label_trains->Location = System::Drawing::Point(186, 13);
			this->label_trains->Name = L"label_trains";
			this->label_trains->Size = System::Drawing::Size(48, 13);
			this->label_trains->TabIndex = 2;
			this->label_trains->Text = L"Поезда:";
			// 
			// list_trains
			// 
			this->list_trains->FormattingEnabled = true;
			this->list_trains->Location = System::Drawing::Point(189, 39);
			this->list_trains->Name = L"list_trains";
			this->list_trains->Size = System::Drawing::Size(200, 511);
			this->list_trains->TabIndex = 3;
			this->list_trains->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::list_trains_Selected);
			// 
			// label_carriages
			// 
			this->label_carriages->AutoSize = true;
			this->label_carriages->Location = System::Drawing::Point(403, 13);
			this->label_carriages->Name = L"label_carriages";
			this->label_carriages->Size = System::Drawing::Size(48, 13);
			this->label_carriages->TabIndex = 4;
			this->label_carriages->Text = L"Вагоны:";
			// 
			// list_carriages
			// 
			this->list_carriages->FormattingEnabled = true;
			this->list_carriages->Location = System::Drawing::Point(406, 39);
			this->list_carriages->Name = L"list_carriages";
			this->list_carriages->Size = System::Drawing::Size(160, 511);
			this->list_carriages->TabIndex = 5;
			this->list_carriages->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::list_carriages_Selected);
			// 
			// btn_all
			// 
			this->btn_all->Location = System::Drawing::Point(573, 39);
			this->btn_all->Name = L"btn_all";
			this->btn_all->Size = System::Drawing::Size(199, 23);
			this->btn_all->TabIndex = 6;
			this->btn_all->Text = L"Общая статистика";
			this->btn_all->UseVisualStyleBackColor = true;
			this->btn_all->Click += gcnew System::EventHandler(this, &FormMain::btn_all_Click);
			// 
			// btn_train
			// 
			this->btn_train->Location = System::Drawing::Point(572, 97);
			this->btn_train->Name = L"btn_train";
			this->btn_train->Size = System::Drawing::Size(199, 23);
			this->btn_train->TabIndex = 7;
			this->btn_train->Text = L"Статистика поезда";
			this->btn_train->UseVisualStyleBackColor = true;
			this->btn_train->Click += gcnew System::EventHandler(this, &FormMain::btn_train_Click);
			// 
			// btn_carriage
			// 
			this->btn_carriage->Location = System::Drawing::Point(573, 126);
			this->btn_carriage->Name = L"btn_carriage";
			this->btn_carriage->Size = System::Drawing::Size(199, 23);
			this->btn_carriage->TabIndex = 8;
			this->btn_carriage->Text = L"Статистика вагона";
			this->btn_carriage->UseVisualStyleBackColor = true;
			this->btn_carriage->Click += gcnew System::EventHandler(this, &FormMain::btn_carriage_Click);
			// 
			// btn_quit
			// 
			this->btn_quit->Location = System::Drawing::Point(573, 527);
			this->btn_quit->Name = L"btn_quit";
			this->btn_quit->Size = System::Drawing::Size(199, 23);
			this->btn_quit->TabIndex = 9;
			this->btn_quit->Text = L"Выход";
			this->btn_quit->UseVisualStyleBackColor = true;
			this->btn_quit->Click += gcnew System::EventHandler(this, &FormMain::btn_quit_Click);
			// 
			// btn_station
			// 
			this->btn_station->Location = System::Drawing::Point(572, 68);
			this->btn_station->Name = L"btn_station";
			this->btn_station->Size = System::Drawing::Size(199, 23);
			this->btn_station->TabIndex = 10;
			this->btn_station->Text = L"Статистика станции";
			this->btn_station->UseVisualStyleBackColor = true;
			this->btn_station->Click += gcnew System::EventHandler(this, &FormMain::btn_station_Click);
			// 
			// btn_refresh
			// 
			this->btn_refresh->Location = System::Drawing::Point(572, 498);
			this->btn_refresh->Name = L"btn_refresh";
			this->btn_refresh->Size = System::Drawing::Size(199, 23);
			this->btn_refresh->TabIndex = 11;
			this->btn_refresh->Text = L"Обновить";
			this->btn_refresh->UseVisualStyleBackColor = true;
			this->btn_refresh->Click += gcnew System::EventHandler(this, &FormMain::btn_refresh_Click);
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->btn_refresh);
			this->Controls->Add(this->btn_station);
			this->Controls->Add(this->btn_quit);
			this->Controls->Add(this->btn_carriage);
			this->Controls->Add(this->btn_train);
			this->Controls->Add(this->btn_all);
			this->Controls->Add(this->list_carriages);
			this->Controls->Add(this->label_carriages);
			this->Controls->Add(this->list_trains);
			this->Controls->Add(this->label_trains);
			this->Controls->Add(this->label_stations);
			this->Controls->Add(this->list_stations);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"FormMain";
			this->Text = L"Rails";
			this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		station^       selected_station;
		train^         selected_train;
		carriage_base^ selected_carriage;

		System::Void UpdateManager() {
			manager::instance = gcnew manager();

			this->list_stations->BeginUpdate();
			this->list_stations->Items->Clear();
			this->list_stations->Items->Add(L"(Все станции)");
			for(int i = 0; i < manager::instance->stations->Count; ++i) {
				this->list_stations->Items->Add(manager::instance->stations[i]->get_name());
			}
			this->list_stations->SelectedIndex = 0;
			this->list_stations->EndUpdate();
		}

		System::Void btn_refresh_Click(System::Object^  sender, System::EventArgs^  e) {
			this->UpdateManager();
		}
		System::Void btn_quit_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}
		System::Void btn_all_Click(System::Object^  sender, System::EventArgs^  e) {
			FormSummary^ form = gcnew FormSummary();
			form->ShowDialog(this);
		}
		System::Void btn_station_Click(System::Object^  sender, System::EventArgs^  e) {
			FormStation^ form = gcnew FormStation(selected_station);
			form->ShowDialog(this);
		}
		System::Void btn_train_Click(System::Object^  sender, System::EventArgs^  e) {
			FormTrain^ form = gcnew FormTrain(selected_train);
			form->ShowDialog(this);
		}
		System::Void btn_carriage_Click(System::Object^  sender, System::EventArgs^  e) {
			FormCarriage^ form = gcnew FormCarriage(selected_train, selected_carriage);
			form->ShowDialog(this);
		}

		System::Void FormMain_Load(System::Object^  sender, System::EventArgs^  e) {
			this->UpdateManager();
		}

		System::Void list_station_Selected(System::Object^ sender, System::EventArgs^ e) {
			if(this->list_stations->SelectedIndex > 0) {
				this->btn_station->Enabled = true;
				selected_station = manager::instance->stations[this->list_stations->SelectedIndex - 1];
			}
			else {
				this->btn_station->Enabled = false;
				selected_station = nullptr;
			}

			this->list_trains->BeginUpdate();
			this->list_trains->Items->Clear();

			if(this->list_stations->SelectedIndex > 0) {
				station^ target_station = manager::instance->stations[this->list_stations->SelectedIndex - 1];
				for(int i = 0; i < target_station->get_trains()->Count; ++i) {
					train^ target_train = target_station->get_trains()[i];
					this->list_trains->Items->Add(String::Format(L"№{0} {1} - {2}", target_train->get_number(), target_train->get_stantion_dispatch()->get_name(), target_train->get_stantion_arrival()->get_name()));
				}
			}
			else {
				for(int i = 0; i < manager::instance->stations->Count; ++i) {
					station^ target_station = manager::instance->stations[i];
					for(int j = 0; j < target_station->get_trains()->Count; ++j) {
						train^ target_train = target_station->get_trains()[j];
						this->list_trains->Items->Add(String::Format(L"№{0} {1} - {2}", target_train->get_number(), target_train->get_stantion_dispatch()->get_name(), target_train->get_stantion_arrival()->get_name()));
					}
				}
			}

			this->list_trains->EndUpdate();
			this->list_trains->SelectedIndex = 0;
		}

		System::Void list_trains_Selected(System::Object^ sender, System::EventArgs^ e) {
			if(selected_station) {
				selected_train = selected_station->get_trains()[this->list_trains->SelectedIndex];
			}
			else {
				int train_index = this->list_trains->SelectedIndex;
				int station_index = 0;

				while(train_index >= manager::instance->stations[station_index]->get_trains()->Count) {
					train_index -= manager::instance->stations[station_index++]->get_trains()->Count;
				}

				selected_train = manager::instance->stations[station_index]->get_trains()[train_index];
			}

			this->list_carriages->BeginUpdate();
			this->list_carriages->Items->Clear();

			if(this->list_stations->SelectedIndex > 0) {
				station^ target_station = manager::instance->stations[this->list_stations->SelectedIndex - 1];
				train^   target_train = target_station->get_trains()[this->list_trains->SelectedIndex];

				for(int i = 0; i < target_train->get_carriages()->Count; ++i) {
					carriage_base^ target_carriage = target_train->get_carriages()[i];

					switch(target_carriage->get_type()) {
					case carriage_type::SEAT:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Сидячий"));
						break;
					case carriage_type::RESERVED:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Плацкарт"));
						break;
					case carriage_type::COUPE:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Купе"));
						break;
					case carriage_type::POSTAL:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Почтовый"));
						break;
					case carriage_type::CAFE:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Буфет"));
						break;
					case carriage_type::RESTARAUNT:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Ресторан"));
						break;
					}
				}
			}
			else {
				int train_index = this->list_trains->SelectedIndex;
				int station_index = 0;

				while(train_index >= manager::instance->stations[station_index]->get_trains()->Count) {
					train_index -= manager::instance->stations[station_index++]->get_trains()->Count;
				}

				station^ target_station = manager::instance->stations[station_index];
				train^   target_train   = target_station->get_trains()[train_index];

				for(int i = 0; i < target_train->get_carriages()->Count; ++i) {
					carriage_base^ target_carriage = target_train->get_carriages()[i];

					switch(target_carriage->get_type()) {
					case carriage_type::SEAT:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Сидячий"));
						break;
					case carriage_type::RESERVED:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Плацкарт"));
						break;
					case carriage_type::COUPE:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Купе"));
						break;
					case carriage_type::POSTAL:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Почтовый"));
						break;
					case carriage_type::CAFE:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Буфет"));
						break;
					case carriage_type::RESTARAUNT:
						this->list_carriages->Items->Add(String::Format(L"№{0} {1}", target_carriage->get_number(), L"Ресторан"));
						break;
					}
				}
			}

			this->list_carriages->EndUpdate();
			this->list_carriages->SelectedIndex = 0;
		}

		System::Void list_carriages_Selected(System::Object^ sender, System::EventArgs^ e) {
			selected_carriage = selected_train->get_carriages()[this->list_carriages->SelectedIndex];

			switch(selected_carriage->get_type()) {
			case carriage_type::SEAT:
			case carriage_type::RESERVED:
			case carriage_type::COUPE:
				this->btn_carriage->Enabled = true;
				break;
			default:
				this->btn_carriage->Enabled = false;
				break;
			}
		}
	};
}
