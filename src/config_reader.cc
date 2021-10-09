#include "../include/config_reader.hh"

#include <iostream>
#include <fstream>

ConfigReader::ConfigReader(const std::string config_addr) {
    std::ifstream cf(config_addr);
    if(!cf.isopen()) {
        std::cerr << "open config file fail" << std::endl;
        exit(-1);
    }

    cf >> ip_addr;
    cf >> data_addr;
    cf >> total_size;

    cf.close();
}

ConfigReader::ConfigReader() = default;

ConfigReader::~ConfigReader() = default;

std::string ConfigReader::get_data_addr() {
    return data_addr;
}

std::string ConfigReader::get_ip_addr() {
    return ip_addr;
}

uint32_t ConfigReader::get_total_size() {
    return total_size;
}