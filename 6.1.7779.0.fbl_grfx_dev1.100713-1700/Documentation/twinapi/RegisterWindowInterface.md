# `RegisterWindowInterface` function

## Syntax

```cpp
HRESULT WINAPI RegisterWindowInterface(
    HWND hWnd,
    REFIID riid,
    IUnknown* pUnk
);
```

## Parameters

`hWnd` - A handle to the window.

`riid` - A reference to the interface identifier.

`pUnk` - A pointer to the interface to be registered. This interface must be derived from `IUnknown`.

## Return value

If successful, `S_OK` is returned.

## Remarks

This function can only be called from the same process and thread that created the window. If the function is called somewhere else, `E_ACCESSDENIED` is returned.
