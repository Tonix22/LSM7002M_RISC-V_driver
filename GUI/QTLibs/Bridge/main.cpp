#include "Server.h"
int main(int argc, char const *argv[])
{
    Server_socket pipe = Server_socket();
    pipe.read_client();
    system("pause");
}