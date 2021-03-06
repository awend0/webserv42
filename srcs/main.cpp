#include "Network/Network.hpp"
#include "Config/Config.hpp"
#include "Config/Parser.hpp"
#include "Handler/Request.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        LOG("Wrong arguments!", ERROR, 0);
        exit(1);
    }
    Config cfg = Parser(argv[1]).getConfig();
    std::cout << cfg;
    Network(cfg).start();
}
