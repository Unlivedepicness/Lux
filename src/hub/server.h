#ifndef LUX_SERVER_H
#define LUX_SERVER_H

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <map>
#include <list>
#include <set>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "devman/devman.h"
#include "../utils/encode.h"
#include "../utils/Parser.h"

#define PORT 8080
#define LISTEN_QUEUE_SIZE 5
#define MESSAGE_SIZE 1024

using namespace std;

typedef void cmd_func(int client_fd, string message);
typedef map<string, cmd_func*> cmd_map;

extern cmd_map server_commands;//add/remove from this to change the server response to specific commands

void server_start();//starts the server, allowing clients to be connected
int server_connections();//# of connections to this server
int client_fd_by_ip(string ip);//-1 if not found
string client_ip_by_fd(int fd);//empty string if not found
void server_send(int client_fd, string message);//sends the message to the client at client_fd

#endif //LUX_SERVER_H