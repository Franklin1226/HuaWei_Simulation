#ifndef SIMU_DATA_NODE_HH
#define SIMU_DATA_NODE_HH
#include "socket_solver.hh"

struct data_chunk
{
  uint16_t chunk_id;
  ssize_t size;
  char* buf;

  data_piece(uint16_t _chunk_id, ssize_t _size, char* _buf)
      : chunk_id(_chunk_id), size(_size), buf(_buf){};
  data_piece() : data_piece(0, 0, nullptr){};
};

class data_node {
private:
    socketapp::tcp_acceptor acc;
    SocketSolver *soket;
    uint16_t tid;
    std::string data_addr;
public:
    SocketSolver(int &id, std::string &_data_addr);
    void read(void* buf, ssize_t size);
    void repair();
    void write(void* buf, ssize_t size);
}

#endif