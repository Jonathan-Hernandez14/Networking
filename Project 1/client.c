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

    int clientSock;		    /* socket descriptor */
    struct sockaddr_in serv_addr;   /* server address structure */

    char *accountName;		    /* Account Name  */
    char *servIP;		    /* Server IP address  */
    unsigned short servPort;	    /* Server Port number */
    

    char sndBuf[SNDBUFSIZE];	    /* Send Buffer */
    char rcvBuf[RCVBUFSIZE];	    /* Receive Buffer */
    
    int balance;		    /* Account balance */

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

    /* Create a new TCP socket*/
    /*	    FILL IN	*/
    /* int     socket(int domain, int type, int protocol);
     * creates a new socket and assigns it to the client socket
     * if no socket could be created then error message will be
     *printed out to the console to notify the user.   */

    clientSock = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
    if (clientSock < 0) {
    	perror("socket error could not create socket");
    	exit(EXIT_FAILURE);
    }

    /* Construct the server address structure */
    /*	    FILL IN	 */
    /*
	 *  struct sockaddr_in {
     * 		short            sin_family;   // e.g. AF_INET
     *		unsigned short   sin_port;     // e.g. htons(3490)
     *		struct in_addr   sin_addr;     // see struct in_addr, below
     *		char             sin_zero[8];  // zero this if you want to
	 * };
    */

    serv_addr.sin_family = AF_INET
    serv_addr.sin_port = htons(servPort);
    serv_addr.sin_addr.in_addr = hton1(INADDR_ANY);
    serv_addr -> sin_zero[8] =

    /* Establish connecction to the server */
    /*	    FILL IN	 */

    connect(clientSock, &serv_addr, sizeof(serv_addr));
    if (connect < 0) {
    	perror("connection failed terrminating");
    	exit(EXIT_FAILURE);
    }
    /* Send the string to the server */
    /*	    FILL IN	 */


    /* Receive and print response from the server */
    /*	    FILL IN	 */

    printf("%s\n", accountName);
    printf("Balance is: %i\n", balance);

    return 0;
}
