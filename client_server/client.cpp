#include <signal.h>
#include "TCPClient.h"

TCPClient tcp;

void sig_exit(int s)
{
    tcp.exit();
    exit(0);
}

int main(int argc, char* argv[])
{
    signal(SIGINT, sig_exit);

    tcp.setup("127.0.0.1", 11999);
    while(true)
    {
        srand(time(NULL));
        tcp.Send(std::to_string(rand()%25000));

        std::string rec = tcp.receive();
        if(rec != "")
        {
            std::cout << "Server Response: " << rec << std::endl;
        }
        sleep(1);
    }
    return 0;
}