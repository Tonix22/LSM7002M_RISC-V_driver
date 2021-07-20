#include "windows.h"
#include <string>
#ifndef SERVER_H
#define SERVER_H

//Name given to the pipe
#define g_szPipeName "\\\\.\\Pipe\\MyNamedPipe"
//Pipe name format - \\.\pipe\pipename

#define BUFFER_SIZE 1024 //1k
#define ACK_MESG_RECV "Message received successfully"


class Server_socket
{
    HANDLE hPipe;
    public:
    Server_socket();
    ~Server_socket();
    void read_client();

};

#endif