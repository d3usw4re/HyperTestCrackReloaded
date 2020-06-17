#pragma once
#include <windows.h>
#include "MemPatcher.h"

namespace HyperTestCrackReloaded {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
		}

	protected:
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  procstatusCaption;
	private: System::Windows::Forms::Label^  procstatusLabel;
	private: System::Windows::Forms::TrackBar^  resultTrackBar;
	private: System::Windows::Forms::Button^  patchMemBtn;
	private: System::Windows::Forms::Button^  hookBtn;
	private: System::ComponentModel::BackgroundWorker^  memPatch;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->procstatusCaption = (gcnew System::Windows::Forms::Label());
			this->procstatusLabel = (gcnew System::Windows::Forms::Label());
			this->resultTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->patchMemBtn = (gcnew System::Windows::Forms::Button());
			this->hookBtn = (gcnew System::Windows::Forms::Button());
			this->memPatch = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// procstatusCaption
			// 
			this->procstatusCaption->AutoSize = true;
			this->procstatusCaption->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->procstatusCaption->Location = System::Drawing::Point(9, 9);
			this->procstatusCaption->Name = L"procstatusCaption";
			this->procstatusCaption->Size = System::Drawing::Size(138, 20);
			this->procstatusCaption->TabIndex = 0;
			this->procstatusCaption->Text = L"Process status: ";
			// 
			// procstatusLabel
			// 
			this->procstatusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->procstatusLabel->ForeColor = System::Drawing::Color::Red;
			this->procstatusLabel->Location = System::Drawing::Point(153, 10);
			this->procstatusLabel->Name = L"procstatusLabel";
			this->procstatusLabel->Size = System::Drawing::Size(124, 20);
			this->procstatusLabel->TabIndex = 1;
			this->procstatusLabel->Text = L"NOT HOOKED";
			this->procstatusLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resultTrackBar
			// 
			this->resultTrackBar->LargeChange = 25;
			this->resultTrackBar->Location = System::Drawing::Point(12, 32);
			this->resultTrackBar->Maximum = 100;
			this->resultTrackBar->Name = L"resultTrackBar";
			this->resultTrackBar->Size = System::Drawing::Size(265, 45);
			this->resultTrackBar->SmallChange = 10;
			this->resultTrackBar->TabIndex = 3;
			this->resultTrackBar->TickFrequency = 10;
			this->resultTrackBar->ValueChanged += gcnew System::EventHandler(this, &MainWindow::resultTrackBar_ValueChanged);
			// 
			// patchMemBtn
			// 
			this->patchMemBtn->Enabled = false;
			this->patchMemBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->patchMemBtn->Location = System::Drawing::Point(13, 122);
			this->patchMemBtn->Name = L"patchMemBtn";
			this->patchMemBtn->Size = System::Drawing::Size(265, 45);
			this->patchMemBtn->TabIndex = 4;
			this->patchMemBtn->Text = L"Patch mem with 0% result";
			this->patchMemBtn->UseVisualStyleBackColor = true;
			this->patchMemBtn->Click += gcnew System::EventHandler(this, &MainWindow::patchMemBtn_Click);
			// 
			// hookBtn
			// 
			this->hookBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->hookBtn->Location = System::Drawing::Point(12, 67);
			this->hookBtn->Name = L"hookBtn";
			this->hookBtn->Size = System::Drawing::Size(265, 45);
			this->hookBtn->TabIndex = 5;
			this->hookBtn->Text = L"Hook to HyperTest";
			this->hookBtn->UseVisualStyleBackColor = true;
			this->hookBtn->Click += gcnew System::EventHandler(this, &MainWindow::hookBtn_Click);
			// 
			// memPatch
			// 
			this->memPatch->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::memPatch_DoWork);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(289, 179);
			this->Controls->Add(this->hookBtn);
			this->Controls->Add(this->patchMemBtn);
			this->Controls->Add(this->resultTrackBar);
			this->Controls->Add(this->procstatusLabel);
			this->Controls->Add(this->procstatusCaption);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HyperTest Crack Reloaded";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultTrackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: DWORD procId = 0;
			 uintptr_t moduleBase = 0;
			 int resultTrackBarValue;

	private: System::Void hookBtn_Click(System::Object^ sender, System::EventArgs^  e) {
		procId = MemPatcher::GetProcId(L"HyperTest.exe");
		moduleBase = MemPatcher::GetModuleBaseAddress(procId, L"HyperTest.exe");
		if (procId == 0 && moduleBase == 0) MessageBoxA(0, "Unable to hook! Check if HyperTest is running", "ERROR", MB_ICONERROR | MB_OK | MB_TOPMOST);
		else {
			hookBtn->Enabled = false;
			procstatusLabel->Text = "HOOKED";
			this->procstatusLabel->ForeColor = System::Drawing::Color::Green;
			patchMemBtn->Enabled = true;
		}
	}
	private: System::Void patchMemBtn_Click(System::Object^ sender, System::EventArgs^  e) {
		resultTrackBarValue = resultTrackBar->Value;
		if(!memPatch->IsBusy) memPatch->RunWorkerAsync();
	}
	private: System::Void resultTrackBar_ValueChanged(System::Object^ sender, System::EventArgs^  e) {
		patchMemBtn->Text = "Patch mem with " + resultTrackBar->Value + "% result";
	}
	private: System::Void memPatch_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		uintptr_t dynamicPtrBaseAddr = moduleBase + HYPERTEST_COUNTDOWN_ADDR;
		int cTimer = 2;
		if (WriteProcessMemory(hProcess, reinterpret_cast<LPVOID>(dynamicPtrBaseAddr), &cTimer, sizeof(cTimer), nullptr) == 0)
			MessageBoxA(0, "Unable to patch memory!", "ERROR", MB_ICONERROR | MB_OK | MB_TOPMOST);
		
		HWND timeIsOutBox = NULL;
		while (timeIsOutBox == NULL) {	
			Sleep(50);
			timeIsOutBox = FindWindowEx(NULL, NULL, L"#32770", L"Time is out");	
		}
		SendMessage(FindWindowEx(timeIsOutBox, NULL, L"Button", NULL), BM_CLICK, NULL, NULL);

		Sleep(50);
		dynamicPtrBaseAddr = moduleBase + HYPERTEST_SCORE_ADDR;
		double newScore = resultTrackBarValue;
		if (WriteProcessMemory(hProcess, reinterpret_cast<LPVOID>(dynamicPtrBaseAddr), &newScore, sizeof(newScore), nullptr) == 0)
			MessageBoxA(0, "Unable to patch memory!", "ERROR", MB_ICONERROR | MB_OK | MB_TOPMOST);
	}
};
}
