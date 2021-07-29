#include "client.h"

Client_socket::Client_socket()
{
    //Initialize the QT process
    starQTProcess(TEXT(QT_PROC_START));// L"string path"
    Sleep(1000);
    //Connect to the server pipe using CreateFile()
    hPipe = CreateFile( 
        TEXT(g_szPipeName),   // pipe name 
        GENERIC_READ |  // read and write access 
        GENERIC_WRITE, 
        0,              // no sharing 
        NULL,           // default security attributes
        OPEN_EXISTING,  // opens existing pipe 
        0,              // default attributes 
        NULL);          // no template file 
    if (INVALID_HANDLE_VALUE == hPipe) 
    {
        printf("\nError occurred while connecting" 
                " to the server: %d", GetLastError()); 
    }
    else
    {
        printf("\nCreateFile() was successful.");
    }
}

void Client_socket::starQTProcess(LPCTSTR lpApplicationName)
{
    // additional information
    STARTUPINFO si;     
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // start the program up
    CreateProcess( lpApplicationName,   // the path
        NULL,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
        );
        // Close process and thread handles. 
        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
}
void Client_socket::sent_message_to_server(std::string msg)
{
    char szBuffer[]="server init\r\n";
    DWORD cbBytes;
    BOOL bResult = WriteFile( 
        hPipe,                // handle to pipe 
        szBuffer,             // buffer to write from 
        strlen(szBuffer)+1,   // number of bytes to write, include the NULL
        &cbBytes,             // number of bytes written 
        NULL);                // not overlapped I/O 
    
    if ( (!bResult) || (strlen(szBuffer)+1 != cbBytes))
    {
        printf("\nError occurred while writing" 
                " to the server: %d", GetLastError()); 
        CloseHandle(hPipe);
    }
    else
    {
        printf("\nWriteFile() was successful.");
    }
}

Client_socket::~Client_socket()
{
    CloseHandle(hPipe);
}
