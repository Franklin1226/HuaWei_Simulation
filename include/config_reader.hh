#ifndef SIMU_CONFIG_READER
#define SIMU_CONFIG_READER

#include <string>

class ConfigReader {
private:
    std::string ip_addr;        //ip配置文件路径
    std::string data_addr;      //原始数据存放的节点
    uint32_t total_size;        //数据总大小

public:
    ConfigReader(const std::string &config_addr);
    ConfigReader();
    ~ConfigReader();

    std::string get_ip_addr();
    std::string get_data_addr();
    uint32_t get_total_size();
};

#endif