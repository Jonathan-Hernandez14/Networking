/*///////////////////////////////////////////////////////////
*
* FILE:		server.c
* AUTHOR:	Jonathan Hernandez
* PROJECT:	CS 3251 Project 1 - Professor Ellen Zegura 
* DESCRIPTION:	Network Server Code
* CREDIT:	Adapted from Professor Traynor
*
*////////////////////////////////////////////////////////////

/*Included libraries*/

#include <stdio.h>	  /* for printf() and fprintf() */
#include <sys/socket.h>	  /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>	  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>	  /* supports all sorts of functionality */
#include <unistd.h>	  /* for close() */
#include <string.h>	  /* support any string ops */

#define RCVBUFSIZE 512		/* The receive buffer size */
#define SNDBUFSIZE 512		/* The send buffer size */
#define BUFSIZE 40		/* Your name can be as many as 40 chars*/

/* The main function */
int main(int argc, char *argv[])
{

    int serverSock;				/* Server Socket */
    int clientSock;				/* Client Socket */
    struct sockaddr_in changeServAddr;		/* Local address */
    struct sockaddr_in changeClntAddr;		/* Client address */
    unsigned short changeServPort;		/* Server port */
    unsigned int clntLen;			/* Length of address data struct */

    char nameBuf[BUFSIZE];			/* Buff to store account name from client */
    int  balance;				/* Place to record account balance result */

    char sendBuf[SNDBUFSIZE];
    char receiveBuf[RCVBUFSIZE];

    /* Create new TCP Socket for incoming requests*/
    /*	    FILL IN	*/
    serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSock < 0) {
        perror("Could not open server socket");
        exit(EXIT_FAILURE);
    }

    /* Construct local address structure*/
    /*	    FILL IN	*/
    memset(&changeServAddr, 0, sizeof(changeServAddr));
    changeServAddr.sin_family = AF_INET
    changeServAddr.sin_port = htons(servPort);
    changeServAddr.sin_addr.in_addr = hton1(INADDR_ANY);

    /* Bind to local address structure */
    /*	    FILL IN	*/
    if (bind(serverSock, (struct sockadd*) &changeServAddr, sizeof(changeServAddr)) < 0) {
        perror("binding failed exiting");
        close(serverSock);
        exit(EXIT_FAILURE);
    } 
    /* Listen for incoming connections */
    /*	    FILL IN	*/

    if (listen(serverSock, 5) < 0) {
        perror("listening for outstanding connections");
        close(serverSock);
        exit(EXIT_FAILURE);
    }

    /* Loop server forever*/
    while(1)
    {

	/* Accept incoming connection */
	/*	FILL IN	    */
    unsigned int clientAddLength = sizeof(clntLen)
    clientSock = accept(serverSock, (struct sockadd*) &changeClntAddr, &clientAddLength )
    if (clntSock < 0) {
        perror("Client Socket failed to start, Exiting");
        close(serverSock);
        exit(EXIT_FAILURE);
    }
	/* Extract the account name from the packet, store in nameBuf */
	/* Look up account balance, store in balance */
	/*	FILL IN	    */
    int received = recv(clientSock, receiveBuf, RCVBUFSIZE, 0);
    if (clientSock < 0) {
        perror("Client not open currently");
        close(serverSock);
        exit(EXIT_FAILURE);
    }

	/* Return account balance to client */
	/*	FILL IN	    */


        close(clientSock);
    }

}

