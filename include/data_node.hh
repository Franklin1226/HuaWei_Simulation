#ifndef SIMU_DATA_NODE_HH
#define SIMU_DATA_NODE_HH
#define CHUNK_SIZE 4194304
#include "socket_solver.hh"
#include "sockpp/tcp_acceptor.h"
struct data_chunk
{
  uint16_t chunk_id;
  ssize_t size;
  char* buf;

  data_piece(uint16_t _chunk_id, ssize_t _size, char* _buf)
      : chunk_id(_chunk_id), size(_size), buf(_buf){};
  data_piece() : data_piece(0, 0, nullptr){};
};

class DataNode {
private:
    socketapp::tcp_acceptor acc;
    sockpp::tcp_socket sock;
    uint16_t tid;
    std::string data_addr;
public:
    DataNode(int &id, std::string &_data_addr);
    DataNode();
    ~DataNode();
    void read(void* buf, ssize_t size);
    void send_data();
    void write(void* buf, ssize_t size);
}

#endif