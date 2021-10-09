#ifndef SIMU_REPAIR_NODE_HH
#define SIMU_REPAIR_NODE_HH

#include <string>

class RepairNode {
private:
    std::string result_addr;
    std::string ip_addr;
public:
    RepairNode(std::string _ip_addr);
    ~RepairNode();

    void repair();
};

#endif