/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Milad Khodabandeh $
   $Notice: (C) Copyright 2024 by Milad Khodabandeh. All Rights Reserved. $
   ======================================================================== */

#define UNICODE


#include <strsafe.h>
#include <Windows.h>
#include "win32_cursor.h"
#include <shellapi.h>


LRESULT CALLBACK MainWindowCallback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR lpCmdLine, int nCmdShow)
{
    //check if another instance is running, if yes, quit, show a dialog and return 0
    
    HANDLE InstanceMutexHandle;
    
    CreateMutexW(nullptr,
                 TRUE,
                 TEXT("ChaseTheCursorSingletonMutex")
                 );
    
    if(GetLastError() == ERROR_ALREADY_EXISTS )
    {
        MessageBox(
                   nullptr,
                   TEXT("Another instance of this program is already running!"),
                   nullptr,
                   MB_OK
                   );
        return 0;
    }
    
    WNDCLASSEX WindowClass {};
    WindowClass.style = CS_OWNDC;
    WindowClass.lpfnWndProc = MainWindowCallback;
    WindowClass.lpszClassName = TEXT("ChaseTheCursorWindowClass");
    WindowClass.cbSize = sizeof(WNDCLASSEX);
    
    RegisterClassEx(&WindowClass);
    
    HWND WindowHandle = CreateWindowEx(
                                       0,                              // Optional window styles.
                                       WindowClass.lpszClassName,      // Window class
                                       TEXT("ChaseTheCursor"),         // Window text
                                       0,                              // Window style
                                       // Size and position
                                       0, 0, 0, 0,
                                       
                                       HWND_MESSAGE,  // Parent window    
                                       nullptr,       // Menu
                                       hInstance,     // Instance handle
                                       nullptr        // Additional application data
                                       );
    
    if (WindowHandle == nullptr)
    {
        return 0;
    }
    
    // {8EA2A47B-F95F-42CF-9CF5-B952DD57E661}
    static const GUID TrayIconGUID = 
    { 0x8ea2a47b, 0xf95f, 0x42cf, { 0x9c, 0xf5, 0xb9, 0x52, 0xdd, 0x57, 0xe6, 0x61 } };
    
    NOTIFYICONDATAW Nid {};
    Nid.hWnd = WindowHandle;
    Nid.guidItem = TrayIconGUID;
    Nid.cbSize = sizeof(NOTIFYICONDATA);
    Nid.uFlags = NIF_GUID | NIF_MESSAGE;
    Nid.uCallbackMessage = WM_USER + 100;
    
    if(Shell_NotifyIcon(NIM_ADD, &Nid))
    {
        
        NOTIFYICONIDENTIFIER Nii {};
        
        Nii.cbSize = sizeof(NOTIFYICONIDENTIFIER);
        Nii.hWnd = WindowHandle;
        Nii.guidItem = TrayIconGUID;
        
        RECT TrayIconLocation {};
        
        if(SUCCEEDED(Shell_NotifyIconGetRect(&Nii,&TrayIconLocation)))
        {
            
        }
    }
    
    
    //sizeof(WNDCLASSEX);
    
}
