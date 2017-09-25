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

    struct sockaddr_in changeClntAddr;      /* Client address */
    int clientSock;             /* Client Socket */
    unsigned int clntLen;           /* Length of address data struct */

    unsigned short changeServPort;		/* Server port */
    
    char nameBuf[BUFSIZE];			/* Buff to store account name from client */
    int  balance;				/* Place to record account balance result */

    char sndBuf[SNDBUFSIZE];
    char rcvBuf[RCVBUFSIZE];

    int countSaving = 0;
    int countChecking = 0;
    int countRetirement = 0;
    int countCollege = 0;

    /* Create new TCP Socket for incoming requests*/
    /*	    FILL IN	*/

    int serverSock;             /* Server Socket */
    serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSock < 0) {
        perror("Could not open server socket, Failed to create");
        exit(1);
    }

    /* Construct local address structure*/
    /*	    FILL IN	*/

    struct sockaddr_in changeServAddr;      /* Local address */
    changeServAddr.sin_family = AF_INET;
    changeServAddr.sin_port = htons(changeServPort);
    changeServAddr.sin_addr.s_addr = INADDR_ANY;


    /* Bind to local address structure */
    /*	    FILL IN	*/

    if (bind(serverSock, (struct sockaddr*) &changeServAddr, sizeof(changeServAddr)) < 0) {
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



    clientSock = accept(serverSock, (struct sockaddr*) &changeClntAddr, &clntLen);
    if (clientSock == -1) {
        perror("Client Socket failed to start, Exiting");
        close(serverSock);
        exit(EXIT_FAILURE);
    }
	/* Extract the account name from the packet, store in nameBuf */
	/* Look up account balance, store in balance */
	/*	FILL IN	    */
    int received = recv(clientSock, rcvBuf, RCVBUFSIZE, 0);
    if (clientSock < 0) {
        perror("Client not open currently");
        close(serverSock);
        exit(EXIT_FAILURE);
    }


        if(strcmp("BAL mySavings", rcvBuf)==0){
            countSaving++;
            balance = 2000;
            snprintf(sndBuf, SNDBUFSIZE, "mySavings account BALANCE  %d", balance);

        }
        else if(strcmp("BAL myChecking", rcvBuf)==0){
            countChecking++;
            balance = 2000;
            snprintf(sndBuf, SNDBUFSIZE, "myChecking account BALANCE  %d", balance);
        }        
        else if(strcmp("BAL myRetirement", rcvBuf)==0){
            countRetirement++;
            balance = 3000;
            snprintf(sndBuf, SNDBUFSIZE, "myRetirement account BALANCE  %d", balance);
        }        
        else if(strcmp("BAL myCollege", rcvBuf)==0){
            countCollege++;
            balance = 4000;
            snprintf(sndBuf, SNDBUFSIZE, "myCollege account BALANCE  %d", balance);
        }

        else if(strcmp("COUNT mySavings", rcvBuf)==0){
            snprintf(sndBuf, SNDBUFSIZE, "mySavings COUNT  %d", countSaving);
        }
        else if(strcmp("COUNT myChecking", rcvBuf)==0){
            snprintf(sndBuf, SNDBUFSIZE, "myChecking COUNT  %d", countChecking);
        }        
        else if(strcmp("COUNT myRetirement", rcvBuf)==0){
            snprintf(sndBuf, SNDBUFSIZE, "myRetirement COUNT  %d", countRetirement);
        }        
        else if(strcmp("COUNT myCollege", rcvBuf)==0){
            snprintf(sndBuf, SNDBUFSIZE, "myCollege COUNT  %d", countCollege);
        }
        // else is a BAD COMMAND
        else{
            // perror() -> posted straight to command prompt; not buffered
            snprintf(sndBuf, SNDBUFSIZE, "YOU FAILED TO GIVE CORRECT PROMPT. Please try again.");
        }
	/* Return account balance to client */
	/*	FILL IN	    */

        int sentSize = send(clientSock, sndBuf, SNDBUFSIZE, 0);
        close(clientSock);
    }

}