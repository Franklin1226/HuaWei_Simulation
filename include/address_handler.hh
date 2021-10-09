#ifndef SIMU_ADDRESS_HANDLER
#define SIMU_ADDRESS_HANDLER

#include <string>
#include <memory>

struct node_address {
    std::string host;
    uint16_t port;

    node_address(std::string &_host, uint16_t _port) :
        host(_host), port(_port) {};
    node_address() = default;
}

#endif