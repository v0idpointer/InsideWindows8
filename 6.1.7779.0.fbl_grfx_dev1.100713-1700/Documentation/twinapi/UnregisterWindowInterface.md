# `UnregisterWindowInterface` function

## Syntax

```cpp
HRESULT WINAPI UnregisterWindowInterface(
    HWND hWnd,
    REFIID riid
);
```

## Parameters

`hWnd` - A handle to the window.

`riid` - A reference to the interface identifier.

## Return value

If successful, `S_OK` is returned.

## Remarks

This function can only be called from the same process and thread that created the window. If the function is called somewhere else, `E_ACCESSDENIED` is returned.
