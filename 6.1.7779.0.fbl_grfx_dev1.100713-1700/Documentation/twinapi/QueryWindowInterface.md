# `QueryWindowInterface` function

## Syntax

```cpp
HRESULT WINAPI QueryWindowInterface(
    HWND hWnd,
    REFIID riid,
    void** ppv
);
```

## Parameters

`hWnd` - A handle to the window.

`riid` - A reference to the interface identifier.

`ppv` - An address of a pointer that receives the interface pointer.

## Return value

If successful, `S_OK` is returned.
