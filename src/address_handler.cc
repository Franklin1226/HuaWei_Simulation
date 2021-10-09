#include "../include/address_handler.hh"

#include <iostream>
#include <fstream>

AddressHandler::AddressHandler(const std::string &_ip_addr):ip_addr(_ip_addr) {
    load_ip();
}

AddressHandler::load_ip() {
    std::fstream ip_f(_ip_addr);

    if(!ip_f.is_open()) {
        std::cerr << "open ip file fail" << std::endl;
        exit(-1);
    }

    cf >> k >> m >> r;
    node_address = std::unique_ptr<node_address[]>(new node_address[k + m + r]);

    for(uint16_t i = 0; i < k + m + r; i++) {
        ip_f >> node_addresses[i].host >> node_addresses[i].port;
    }

    ip_f.close();
}

AddressHandler::AddressHandler() = default;

AddressHandler::~AddressHandler() = default;

AddressHandler::get_node_addresses() {
    if(node_addresses == nullptr) {
        load_ip();
    }
    std::unique_ptr<node_address[]> naddrs = std::move(node_addresses);
    node_addresses = nullptr;
    return naddrs;
}

AddressHandler::get_k() {
    return k;
}

AddressHandler::get_m() {
    return m;
}

AddressHandler::get_r() {
    return r;
}