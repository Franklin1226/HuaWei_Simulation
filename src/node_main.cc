//1. Read the Config file
// 
//2. Listen the node reconstruct the failed node
//3. Send the node information to repair node
//4. If the node don't failed, send date it stored to the repair node
// 读取配置文件
// 在节点创建一个随机文件
// 监听修复节点（目标节点）的连接请求
// 如果该节点没有失效，将该节点中储存的数据传输到目标节点
#include "../include/config_reader.hh"
#include "../include/address_handler.hh"
#include "../include/data_node.hh"

#include <iostream>
#include <memory>

int main(int argc, char* argv[]) {
    if(argc != 2 || atoi(argv[1]) < 0) {
        std::cout << "bad args" << std::endl;
        exit(-1);
    }
    
    uint16_t id = atoi(argv[1]);        //节点id号

    //读取配置文件
    std::cout << "Reading Config File......" << std::endl;
    ConfigReader *conf_reader = new ConfigReader("/root/simulation/config/config.txt");

    //生成原始数据文件
    uint32_t data_file_size = conf_reader->get_total_size() / (addr_handler->get_k() + addr_handler->get_m());
    std::string data_generate_cmd = "dd if=/dev/zero of=" + conf_reader->get_data_addr + " count=" + std::to_string(data_file_size) + " bs=1";
    system(data_generate_cmd.c_str());

    if(id < addr_handler->get_k() + addr_handler->get_m()) {
        //数据存储节点，监听目标节点的链接请求
        DataNode *dn = new DataNode(id, conf_reader->get_data_addr(), data_file_size);
        //执行修复操作，发送本节点存放的数据
        dn->send_data();
    } else {
        //读取节点IP地址
        std::cout << "Getting IP Information......" << std::endl;
        AddressHandler *addr_handler = new AddressHandler(conf_reader->get_ip_addr()); 
        //目标节点，负责接受普通节点的数据

    }
}