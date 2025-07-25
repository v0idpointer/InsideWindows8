# `IsImmersiveWindow` function

Checks if the specified window is an immersive window.

## Syntax

```cpp
BOOL WINAPI IsImmersiveWindow(
    HWND hWnd
);
```

## Parameters

`hWnd` - A window handle.

## Return value

Returns `TRUE` if the specified window is an immersive window; otherwise, `FALSE`.

## Remarks

If the `hWnd` parameter is not a valid window handle, the function returns `FALSE`.

The window is considered immersive if its [window band](./ZBID.md) is either `ZBID_IMMERSIVE_DOCK`, `ZBID_IMMERSIVE_BACKGROUND`, `ZBID_IMMERSIVE_ALTER_EGO` or `0x0F` (this value is not defined in the `ZBID` enum).
