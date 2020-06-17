#pragma once
#include <windows.h>
#include <tlhelp32.h>
#define HYPERTEST_SCORE_ADDR 0xDBE18
#define HYPERTEST_COUNTDOWN_ADDR 0xDB050

public class MemPatcher {
	public: static DWORD GetProcId(const wchar_t* procName);
			static uintptr_t GetModuleBaseAddress(DWORD dwProcID, wchar_t* szModuleName);
};