#ifndef SIMU_REPAIR_NODE_HH
#define SIMU_REPAIR_NODE_HH
#define CHUNK_SIZE 4194304
#include "sockpp/tcp_connector.h"
#include "address_handler.hh"

#include <string>
#include <thread>

class RepairNode {
private:
    std::unique_ptr<sockpp::tcp_connector *[]> conns;
    std::unique_ptr<std::thread[]> get_threads;
    std::string result_addr;
    std::string ip_addr;
public:
    RepairNode(std::unique_ptr<node_address[]> node_addresses);
    ~RepairNode();

    void repair();
};

#endif