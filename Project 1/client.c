/*///////////////////////////////////////////////////////////
*
* FILE:		client.c
* AUTHOR:	Jonathan Hernandez
* PROJECT:	CS 3251 Project 1 - Professor Ellen Zegura 
* DESCRIPTION:	Network Client Code
* CREDIT:	Adapted from Professor Traynor
*
*////////////////////////////////////////////////////////////

/* Included libraries */

#include <stdio.h>		    /* for printf() and fprintf() */
#include <sys/socket.h>		    /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>		    /* for sockaddr_in and inet_addr() */
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Constants */
#define RCVBUFSIZE 512		    /* The receive buffer size */
#define SNDBUFSIZE 512		    /* The send buffer size */
#define REPLYLEN 32

/* The main function */
int main(int argc, char *argv[])
{

    char *accountName;		    /* Account Name  */
    char *servIP;		    /* Server IP address  */
    unsigned short servPort;	    /* Server Port number */
    

    char sndBuf[SNDBUFSIZE];	    /* Send Buffer */
    char rcvBuf[RCVBUFSIZE];	    /* Receive Buffer */
    
    int balance;		    /* Account balance */
    char *balCount;

    /* Get the Account Name from the command line */
    if (argc != 4) 
    {
	printf("Incorrect number of arguments. The correct format is:\n\taccountName serverIP serverPort");
	exit(1);
    }
    accountName = argv[1];

    memset(&sndBuf, 0, SNDBUFSIZE);
    memset(&rcvBuf, 0, RCVBUFSIZE);

    /* Get the addditional parameters from the command line */
    /*	    FILL IN	*/
    accountName = argv[2];
    servIP = argv[3];
    servPort = atoi(argv[4]);
    fprint(servPort);


    /* Create a new TCP socket*/
    /*	    FILL IN	*/
    /* int     socket(int domain, int type, int protocol);
     * creates a new socket and assigns it to the client socket
     * if no socket could be created then error message will be
     *printed out to the console to notify the user.   */


    int clientSock;		    /* socket descriptor */
    clientSock = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
    if (clientSock < 0) {
    	perror("Socket error, could not create socket");
    	exit(EXIT_FAILURE);
    }

    /* Construct the server address structure */
    /*	    FILL IN	 */


    struct sockaddr_in serv_addr;   /* server address structure */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(servPort);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    /* Establish connecction to the server */
    /*	    FILL IN	 */
    int connection_stat = connect(clientSock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (connection_stat < 0) {
    	perror("Connection failed, terrminating process");
    	close(clientSock);
    	exit(EXIT_FAILURE);
    }
    /* Send the string to the server */
    /*	    FILL IN	 */

    snprintf(sndBuf, SNDBUFSIZE, "%s %s", balCount, accountName);

    ssize_t numBytes = send(clientSock, sndBuf, SNDBUFSIZE, 0);
    if(numBytes < 0){
        // DieWithSystemMessage("send() failed");
        perror("Send function has failed");
        close(clientSock);
        exit(EXIT_FAILURE);
    }

    /* Receive and print response from the server */
    /*	    FILL IN	 */

    int recvSize = recv(clientSock, rcvBuf, RCVBUFSIZE, 0);
    if(recvSize==-1){
        perror("recv() error");
        exit(1);
    }

    printf("%s\n", accountName);
    printf("Balance is: %i\n", balance);
    close(clientSock);
    return 0;
}