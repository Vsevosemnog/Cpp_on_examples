#include "TCPServer.h"

TCPServer tcp;

void* loop(void* m)
{
    pthread_detach(pthread_self());
    while(true)
    {
        srand(time(NULL));
        char ch = 'a' + rand() % 26;
        std::string s(1,ch);
        std::string str = tcp.getMessage();
        if(str !="")
        {
            std::cout << "Message:"<<str<<std::endl;
            tcp.Send("\t[client message]: " + str + " " + s);
            tcp.clean();
        }
        usleep(1000);
    }
    tcp.detach();
}

int main()
{
    pthread_t msg;
    tcp.setup(11999);
    if(pthread_create(&msg,NULL,loop,(void*)0) == 0)
    {
        tcp.receive();
    }
    return 0;
}