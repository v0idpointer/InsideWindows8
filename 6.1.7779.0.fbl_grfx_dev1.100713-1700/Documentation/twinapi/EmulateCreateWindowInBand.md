# `EmulateCreateWindowInBand` function

Emulates the functionality of the `CreateWindowInBand` function found in later builds of Windows.

## Syntax

```cpp
HWND WINAPI EmulateCreateWindowInBand(
    DWORD dwExStyle,
    LPCWSTR lpClassName,
    LPCWSTR lpWindowName,
    DWORD dwStyle,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    HWND hWndParent,
    HMENU hMenu,
    HINSTANCE hInstance,
    LPVOID lpParam,
    DWORD dwBand
);
```

## Parameters

`dwExStyle` - The extended window style.

`lpClassName` - The window class name or class atom.

`lpWindowName` - The window name.

`dwStyle` - The window style.

`X` - The X coordinate of the window's top-left corner.

`Y` - The Y coordinate of the window's top-left corner.

`nWidth` - The width of the window.

`nHeight` - The height of the window.

`hWndParent` - A handle to the parent window.

`hMenu` - A handle to a menu, or a child window identifier.

`hInstance` - An instance handle of the module associated with the window.

`lpParam` - Pointer to data to be passed to the window through the `CREATESTRUCT` structure.

`dwBand` - A value from the [ZBID](./ZBID.md) enum.

## Return value

If successful, a handle to the newly created window is returned; otherwise, `NULL` is returned. 

If the function fails, call `GetLastError` to get extended error information.

## Remarks

If the `hWndParent` parameter is not `NULL`, the `dwBand` parameter is not `ZBID_DESKTOP` and `dwBand` is not equal to the parent window's window band, the function will fail, setting the last error code to `ERROR_INVALID_PARAMETER`.
