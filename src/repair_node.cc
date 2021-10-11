#include "../include/repair_node.hh"

#include <thread>

RepairNode::RepairNode(std::unique_ptr<node_address[]> node_addresses, int k, int m) {
    conns = std::unique_ptr<sockpp::tcp_connector []>(new sockpp::tcp_connector [k+m]);
    get_threads = std::unique_ptr<std::thread[]>(new std::thread[k+m]);
    for(uint16_t i = 0; i < k + m) {
        const std::string &host = node_addresses[i].host;
        int16_t port = node_addresses[i].port;
        while(!conns[i].connect(sockpp::inet_address(host, post))) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}

RepairNode::~RepairNode() {
    for(uint16_t i = 0; i < k + m; ++i) {
        conns[i].close();
    }
}

void RepairNode::repair(int k, int m) {
    for(uint16_t i = 0; i < k + m; ++i) {
        get_threads[i] = std::thread([&] {
            char buf[CHUNK_SIZE];
            uint32_t total_size = 0;
            conns[i].read(&total_size, sizeof(total_size));
            while(total_size != 0) {
                if(total_size > CHUNK_SIZE) {
                    conns[i].read(buf, CHUNK_SIZE);
                    total_size -= CHUNK_SIZE;
                } else {
                    conns[i].read(buf, total_size);
                    total_size = 0;
                }
            }
            delete[] buf;
        });
    }
}