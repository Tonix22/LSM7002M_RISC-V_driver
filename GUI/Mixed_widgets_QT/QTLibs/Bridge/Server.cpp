#include "bridge.h"
#include "windows.h"
#include "Server.h"


void Server_socket::read_client()
{
    char szBuffer[BUFFER_SIZE];
    DWORD cbBytes;
    //Read client message
    BOOL bResult = ReadFile( 
        hPipe,                // handle to pipe 
        szBuffer,             // buffer to receive data 
        sizeof(szBuffer),     // size of buffer 
        &cbBytes,             // number of bytes read 
        NULL);                // not overlapped I/O 

    if ( (!bResult) || (0 == cbBytes)) 
    {
        printf("\nError occurred while reading " 
                "from the client: %d", GetLastError()); 
        CloseHandle(hPipe);
    }
    else
    {
        printf("ReadFile() was successful.");
    }

    printf("\nClient sent the following message: %s", szBuffer);
    strcpy(szBuffer, ACK_MESG_RECV);
}

Server_socket::Server_socket()
{
    hPipe = CreateNamedPipe( 
        TEXT(g_szPipeName),       // pipe name 
        PIPE_ACCESS_DUPLEX,       // read/write access 
        PIPE_TYPE_MESSAGE |       // message type pipe 
        PIPE_READMODE_MESSAGE |   // message-read mode 
        PIPE_WAIT,                // blocking mode 
        PIPE_UNLIMITED_INSTANCES, // max. instances  
        BUFFER_SIZE,              // output buffer size 
        BUFFER_SIZE,              // input buffer size 
        NMPWAIT_USE_DEFAULT_WAIT, // client time-out 
        NULL);                    // default security attribute 

    if (INVALID_HANDLE_VALUE == hPipe) 
    {
        printf("\nError occurred while " 
                "creating the pipe: %d\r\n", GetLastError());
    }
    else
    {
        printf("\nCreateNamedPipe() was successful.\r\n");
    }
    
    printf("Waiting for client connection...\r\n");
     
    //Wait for the client to connect
    BOOL bClientConnected = ConnectNamedPipe(hPipe, NULL);

    if (FALSE == bClientConnected)
    {
        printf("\nError occurred while connecting" 
                " to the client: %d", GetLastError()); 
        CloseHandle(hPipe);
    }
    else
    {
        printf("ConnectNamedPipe() was successful\r\n");
    }
}
Server_socket::~Server_socket()
{
    CloseHandle(hPipe);
}