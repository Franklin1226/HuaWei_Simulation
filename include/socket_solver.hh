#ifndef FTPR_SOCKET_SOLVER_HH
#define FTPR_SOCKET_SOLVER_HH

#include "sockpp/tcp_acceptor.h"

#include "data_solver_interface.hh"

class SocketSolver
{
private:
  sockpp::tcp_socket sock;

public:
  SocketSolver(sockpp::tcp_socket _sock);
  ~SocketSolver();

  void read(void *buf, ssize_t size);
  void write(void *buf, ssize_t size);
};

#endif