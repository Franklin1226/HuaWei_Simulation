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
};

class AddressHandler {
private:
    uint16_t k, m, r;
    std::unique_ptr<node_address[]> node_addresses;
    load_ip();

public:
    AddressHandler(const std::string &_ip_addr);
    AddressHandler();
    ~AddressHandler();
    
    std::unique_ptr<node_address[]> get_node_addresses();
    uint16_t get_k();
    uint16_t get_m();
    uint16_t get_r();
};

#endif