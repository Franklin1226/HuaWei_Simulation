#include "../include/data_node.hh"

#include <fstream>
#include <iostream>

DataNode::DataNode(uint16_t &id, std::string &_data_addr, uint32_t _data_file_size) : data_addr(_data_addr), data_file_size(_data_file_size){
    acc = sockpp::tcp_acceptor(node_addresses[id].port);
    if (!acc) {
    std::cerr << acc.last_error_str()
              << std::endl;
    exit(-1);
    }
    
    //监听来自目标节点的链接请求
    sock = acc.accept();
}

DataNode::DataNode() = default;

DataNode::~DataNode() {
    acc.close();
}

void DataNode::read(void* buf, sszie_t size) {
    sock.read_n(buf, size);
}

void DataNode::write(void* buf, ssizt_t size) {
    sock.write_n(buf, size);
}

void DataNode::send_data() {
    //TODO()
    write(&data_file_size, sizeof(data_file_size));
    char* buf = new char[CHUNK_SIZE];
    std::fstream in(data_addr, std::ios::in | std::ios::binary);
    if(!in.is_open()) {
        std::cerr << "open data file error" << std::endl;
        exit(-1);
    }
    while(in.read(buf, CHUNK_SIZE)) {
        write(buf, CHUNK_SIZE);
    }
    write(buf, in.gcount());
    in.close();
    delete[] buf;
}