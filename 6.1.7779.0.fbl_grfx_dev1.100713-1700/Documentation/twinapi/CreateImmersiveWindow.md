# `CreateImmersiveWindow` function

Creates an immersive window.

## Syntax

```cpp
HWND WINAPI CreateImmersiveWindow(
    DWORD dwExStyle,
    LPCWSTR lpClassName,
    DWORD dwStyle,
    HWND hWndParent,
    HINSTANCE hInstance,
    LPVOID lpParam
);
```

## Parameters

`dwExStyle` - The extended window style.

The following extended window styles can be set:

- `WS_EX_ACCEPTFILES`
- `WS_EX_COMPOSITED`
- `WS_EX_CONTROLPARENT`
- `WS_EX_LAYERED`
- `WS_EX_LAYOUTRTL`
- `WS_EX_LEFT`
- `WS_EX_LEFTSCROLLBAR`
- `WS_EX_LTRREADING`
- `WS_EX_MDICHILD`
- `WS_EX_NOACTIVATE`
- `WS_EX_NOINHERITLAYOUT`
- `WS_EX_NOPARENTNOTIFY`
- `WS_EX_NOREDIRECTIONBITMAP`
- `WS_EX_RIGHT`
- `WS_EX_RIGHTSCROLLBAR`
- `WS_EX_RTLREADING`
- `WS_EX_TOOLWINDOW`
- `WS_EX_TOPMOST`
- `WS_EX_TRANSPARENT`

If any other extended window style is set, the function will fail, setting the last error code to `ERROR_INVALID_PARAMETER`.

`lpClassName` - The window class name or class atom.

`dwStyle` - The window style. This parameter cannot be `NULL`.

The following window styles can be set:

- `WS_CLIPCHILDREN`
- `WS_CLIPSIBLINGS`
- `WS_DISABLED`
- `WS_HSCROLL`
- `WS_OVERLAPPED`
- `WS_POPUP`
- `WS_VISIBLE`
- `WS_VSCROLL`

If any other window style is set, the function will fail, setting the last error code to `ERROR_INVALID_PARAMETER`.

Since this parameter cannot be set to `NULL`, `WS_OVERLAPPED` alone cannot be used as the window style. This is because `NULL` and `WS_OVERLAPPED` have the same numerical value.

`hWndParent` - A handle to the parent window.

`hInstance` - An instance handle of the module associated with the window.

`lpParam` - Pointer to data to be passed to the window through the `CREATESTRUCT` structure.

## Return value

If successful, a handle to the newly created window is returned; otherwise, `NULL` is returned. 

If the function fails, call `GetLastError` to get extended error information.

## Remarks

The window class used with the function must have its `lpszMenuName` set to `NULL`. If the menu name is not `NULL`, the function will fail, setting the last error code to `ERROR_INVALID_PARAMETER`.

The newly created window will have its [window band](./ZBID.md) set based on the value of the `hWndParent` parameter.  If `hWndParent` is set to `NULL`, `ZBID_IMMERSIVE_ALTER_EGO` is used; otherwise, `ZBID_DESKTOP` is used.
