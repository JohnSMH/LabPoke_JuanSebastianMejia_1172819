#pragma once
#include "Pokemon.h"
#include "PokePrueba.h"


namespace LabPokeJuanSebastianMejia1172819 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Obtener Pokemones";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(145, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(295, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Funciona con la estructura \"Nombre,National,Generacion,...\"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(457, 261);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamReader^ streamReader = gcnew StreamReader("pokes.txt");
		String^ texto = streamReader->ReadToEnd();
		//array<PokePrueba^>^ cols = gcnew array<PokePrueba^>(10);
		String^ llenado;
		int its=1;
		int i=0;
		int gen;
		int num;
		int j;
		String^nombre;
		List<PokePrueba^>^ cols2 = gcnew List<PokePrueba^>();

		while (texto->Length>0)
		{
			switch (its)
			{
			case 1:
			j = 0;
			llenado = "";
				while (texto[j] != ',')
				{
					llenado += texto[j];
					j++;
				}
				nombre = llenado;
				
				its++;
				texto = texto->Remove(0, j + 1);
				break;
			case 2:
				llenado = "";
				 j = 0;

				while (texto[j] != ',')
				{
					llenado += texto[j];
					j++;
				}

				gen = Convert::ToInt32(llenado);

				texto = texto->Remove(0, j + 1);
				its++;
				break;
			case 3:
				 j = 0;
				llenado = "";

				while (texto[j] != ',')
				{
					llenado += texto[j];
					j++;
				}

				num = Convert::ToInt32(llenado);

				texto = texto->Remove(0, j + 1);
				//cols[i] = gcnew PokePrueba(nombre,gen,num);
				cols2->Add(gcnew PokePrueba(nombre, gen, num));

				its = 1;
				i++;
				break;
			default:
				break;
			}
			
		}
		
		for each (PokePrueba^var in cols2)
		{
			label1->Text += var->Nombre + " " + var->natnum + " " + var->gennum + "\n";
		}

		//for (int i = 0; i < 2; i++)
		//{
		//	label1->Text += cols[i]->Nombre+" "+cols[i]->natnum+" "+cols[i]->gennum+"\n";

		//}

		
	}
	};
}
