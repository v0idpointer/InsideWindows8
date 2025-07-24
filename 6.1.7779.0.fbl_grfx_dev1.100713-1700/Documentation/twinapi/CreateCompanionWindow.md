# `CreateCompanionWindow` function

Creates a "companion" window, an early prototype of the search charm window.

## Syntax

```cpp
HWND WINAPI CreateCompanionWindow(
	DWORD dwExStyle,
	LPCWSTR lpClassName,
	DWORD dwStyle,
	LPCWSTR lpWindowName,
	DWORD unused,
	HINSTANCE hInstance,
	LPVOID lpParam
);
```

## Parameters

`dwExStyle` - The extended window style. 

The following extended window styles can be set:

- `WS_EX_ACCEPTFILES`
- `WS_EX_CONTROLPARENT`
- `WS_EX_LAYOUTRTL`
- `WS_EX_LEFT`
- `WS_EX_LEFTSCROLLBAR`
- `WS_EX_LTRREADING`
- `WS_EX_NOINHERITLAYOUT`
- `WS_EX_RIGHT`
- `WS_EX_RIGHTSCROLLBAR`
- `WS_EX_RTLREADING`

If any other extended window style is set, the function will fail, setting the last error code to `ERROR_INVALID_PARAMETER`.

`lpClassName` - The window class name or class atom.

`dwStyle` - The window style.

This value can be `WS_OVERLAPPED` or `WS_POPUP`. If `WS_POPUP` is set, the following window styles can also be set:

- `WS_CLIPCHILDREN`
- `WS_CLIPSIBLINGS`
- `WS_HSCROLL`
- `WS_VISIBLE`
- `WS_VSCROLL`

If any other window style is set, the function will fail, setting the last error code to `ERROR_INVALID_PARAMETER`.

`lpWindowName` - The window name.

`unused` - This parameter is not used. It's safe to set it to `NULL`.

`hInstance` - An instance handle of the module associated with the window.

`lpParam` - Pointer to data to be passed to the window through the `CREATESTRUCT` structure.

## Return value

If successful, a handle to the newly created companion window is returned; otherwise, `NULL` is returned. 

If the function fails, call `GetLastError` to get extended error information.
