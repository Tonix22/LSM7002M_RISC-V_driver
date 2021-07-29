#ifndef CLIENT_H
#define CLIENT_H

#include "windows.h"
#include <string>

//Name given to the pipe
#define g_szPipeName "\\\\.\\Pipe\\MyNamedPipe"
#define QT_PROC_START "Z:\\QTLibs\\build-Bridge-Desktop_Qt_5_15_1_MinGW_64_bit-Debug\\Bridge.exe"
//Pipe name format - \\servername\pipe\pipename
#define BUFFER_SIZE 1024 //1k
#define ACK_MESG_RECV "Message received successfully"

class Client_socket
{
    HANDLE hPipe;
    public:
    Client_socket();
    ~Client_socket();
    void starQTProcess(LPCTSTR lpApplicationName);
    void sent_message_to_server(std::string msg);
};

#endif