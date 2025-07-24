#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

constexpr const wchar_t* CLASS_NAME = L"CompanionWindowDemoApp";
constexpr const wchar_t* WINDOW_NAME = L"Companion Window Demo";

typedef HWND (WINAPI *CreateCompanionWindow_t)(
	DWORD dwExStyle,
	LPCWSTR lpClassName,
	DWORD dwStyle,
	LPCWSTR lpWindowName,
	DWORD unused,
	HINSTANCE hInstance,
	LPVOID lpParam
);

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	if (msg == WM_CLOSE) {
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int nCmdShow) {

	WNDCLASSEXW wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
	wc.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wc.lpszClassName = CLASS_NAME;
	wc.lpszMenuName = nullptr;
	wc.lpfnWndProc = &WindowProc;
	wc.style = (CS_OWNDC | CS_VREDRAW | CS_HREDRAW);

	if (RegisterClassExW(&wc) == NULL) {
		MessageBoxW(nullptr, L"Failed to register window class.", L"Error", MB_ICONERROR);
		return -1;
	}

	HMODULE hLib = LoadLibraryW(L"twinapi.dll");
	if (hLib == nullptr) {
		MessageBoxW(nullptr, L"Failed to load twinapi.dll", L"Error", MB_ICONERROR);
		return -1;
	}

	CreateCompanionWindow_t pfnCreateCompanionWindow = reinterpret_cast<CreateCompanionWindow_t>(
		GetProcAddress(hLib, "CreateCompanionWindow")
	);

	if (pfnCreateCompanionWindow == nullptr) {
		MessageBoxW(nullptr, L"TWinAPI does not export CreateCompanionWindow function.", L"Error", MB_ICONERROR);
		return -1;
	}

	pfnCreateCompanionWindow(NULL, CLASS_NAME, NULL, WINDOW_NAME, NULL, hInstance, nullptr);

	MSG msg = { 0 };
	while (GetMessageW(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return 0;
}