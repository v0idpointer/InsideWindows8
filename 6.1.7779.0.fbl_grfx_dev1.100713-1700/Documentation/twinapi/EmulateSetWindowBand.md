# `EmulateSetWindowBand` function

Emulates the functionality of the `SetWindowBand` function found in later builds of Windows.

## Syntax

```cpp
BOOL WINAPI EmulateSetWindowBand(
    HWND hWnd,
    HWND hWndInsertAfter,
    DWORD dwBand
);
```

## Parameters

`hWnd` - A window handle.

`hWndInsertAfter` - This parameter is not used. It's safe to set it to `NULL`.

`dwBand` - A value from the [ZBID](./ZBID.md) enum.

## Return value

If successful, returns `TRUE`; otherwise, `FALSE`.

If the function fails, call `GetLastError` to get extended error information.