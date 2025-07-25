# `EmulateGetWindowBand` function

Emulates the functionality of the `GetWindowBand` function found in later builds of Windows.

## Syntax

```cpp
DWORD WINAPI EmulateGetWindowBand(
    HWND hWnd
);
```

## Parameters

`hWnd` - A window handle.

## Return value

If successful, the specified window's [window band](./ZBID.md) is returned; otherwise, `ZBID_DEFAULT` is returned.

If the function fails, call `GetLastError` to get extended error information.

## Remarks

If the `hWnd` parameter is not a valid window handle, the function will fail, setting the last error code to `ERROR_INVALID_HANDLE`.

If the specified window does not have a window band set, `ZBID_UIACCESS` is returned.
