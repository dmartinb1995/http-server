#ifndef HTTPD_H
#define HTTPD_H

#include <string>
#include <stdbool.h>
#include <stdio.h>
#include <sys/socket.h>

using namespace std;

void start_httpd(unsigned short port, string doc_root);


/*****************************************************************************
 *                     HTTPMESSAGE Functions and structs                     *
 *****************************************************************************/
// Handle error with user msg
void DieWithUserMessage(const char *msg, const char *detail);
// Handle error with sys msg
void DieWithSystemMessage(const char *msg);
// Print socket address
void PrintSocketAddress(const struct sockaddr *address, FILE *stream);
// Test socket address equality
bool SockAddrsEqual(const struct sockaddr *addr1, const struct sockaddr *addr2);
// Create, bind, and listen a new TCP server socket
int SetupTCPServerSocket(const char *service);
// Accept a new TCP connection on a server socket
int AcceptTCPConnection(int servSock);
// Handle new TCP client
void HandleTCPClient(int clntSocket);
// Create and connect a new TCP client socket
int SetupTCPClientSocket(const char *server, const char *service);
int check(char c[], size_t s);
enum sizeConstants {
  MAXSTRINGLENGTH = 128,
  BUFSIZE = 512,
};


/*****************************************************************************
 *                     HTTPREQUEST Functions and structs                     *
 *****************************************************************************/


/*****************************************************************************
 *                     HTTPRESPONSE Functions and structs                    *
 *****************************************************************************/
#endif // HTTPD_H
