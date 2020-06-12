/*
 *
 * Copyright 2018 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <grpc/support/port_platform.h>

#include "src/core/lib/iomgr/d_tcp_server.h"

d_grpc_tcp_server_vtable* d_grpc_tcp_server_impl;

grpc_error* d_grpc_tcp_server_create(grpc_closure* shutdown_complete,
                                   const grpc_channel_args* args,
                                   grpc_tcp_server** server) {
  return d_grpc_tcp_server_impl->create(shutdown_complete, args, server);
}

void d_grpc_tcp_server_start(d_grpc_tcp_server* server, grpc_pollset** pollsets,
                           size_t pollset_count,
                           d_grpc_tcp_server_cb on_accept_cb, void* cb_arg) {
  d_grpc_tcp_server_impl->start(server, pollsets, pollset_count, on_accept_cb,
                              cb_arg);
}

grpc_error* d_grpc_tcp_server_add_port(d_grpc_tcp_server* s,
                                     const grpc_resolved_address* addr,
                                     int* out_port) {
  return d_grpc_tcp_server_impl->add_port(s, addr, out_port);
}

grpc_core::TcpServerFdHandler* d_grpc_tcp_server_create_fd_handler(
    d_grpc_tcp_server* s) {
  return d_grpc_tcp_server_impl->create_fd_handler(s);
}

unsigned d_grpc_tcp_server_port_fd_count(d_grpc_tcp_server* s,
                                       unsigned port_index) {
  return d_grpc_tcp_server_impl->port_fd_count(s, port_index);
}

int d_grpc_tcp_server_port_fd(d_grpc_tcp_server* s, unsigned port_index,
                            unsigned fd_index) {
  return d_grpc_tcp_server_impl->port_fd(s, port_index, fd_index);
}

d_grpc_tcp_server* d_grpc_tcp_server_ref(grpc_tcp_server* s) {
  return d_grpc_tcp_server_impl->ref(s);
}

void d_grpc_tcp_server_shutdown_starting_add(d_grpc_tcp_server* s,
                                           grpc_closure* shutdown_starting) {
  d_grpc_tcp_server_impl->shutdown_starting_add(s, shutdown_starting);
}

void d_grpc_tcp_server_unref(d_grpc_tcp_server* s) {
  d_grpc_tcp_server_impl->unref(s);
}

void d_grpc_tcp_server_shutdown_listeners(d_grpc_tcp_server* s) {
  d_grpc_tcp_server_impl->shutdown_listeners(s);
}

void d_grpc_set_tcp_server_impl(d_grpc_tcp_server_vtable* impl) {
  d_grpc_tcp_server_impl = impl;
}
