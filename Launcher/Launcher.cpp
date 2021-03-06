#include <Windows.h>
#include <wchar.h>
#include <Shlwapi.h>
#include <Shlobj.h>

#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib,"Shell32.lib")

int WINAPI  wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPreInst,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow
	)
{
	WCHAR LauncherAppPath[32 * 1024 - 1] = { 0 };
	WCHAR LauncherAppDirectory[32 * 1024 - 1] = { 0 };
	WCHAR Home[260] = { 0 };
	WCHAR ifile[32 * 1024 - 1] = { 0 };
	GetModuleFileName(hInstance, ifile, 32 * 1024 - 1);
	(wcsrchr(ifile, L'.'))[1] = 0;
	wcscat_s(ifile, L"ini");

	SHGetSpecialFolderPath(NULL, Home, CSIDL_PERSONAL, FALSE);
	(wcsrchr(Home, L'\\'))[0] = 0;
	//MessageBox(NULL, Home, L"CSIDL_PERSONAL", MB_OK);
	GetPrivateProfileString(L"Launcher", L"LauncherAppPath", L"LauncherApp.exe", LauncherAppPath, 32 * 1024 - 1, ifile);
	GetPrivateProfileString(L"Launcher", L"LauncherAppDirectory", Home, LauncherAppDirectory, 32 * 1024 - 1, ifile);
	ShellExecute(NULL, L"runas", LauncherAppPath, NULL, LauncherAppDirectory, SW_NORMAL);
	return 0;
}