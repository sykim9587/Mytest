#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 100
#define NAME_SIZE 20

void * send_msg(void * arg);
void error_handling(char *message);

char name[NAME_SIZE]="[DEFAULT]";
char msg[BUF_SIZE];

int main(int argc, char *argv[])
{

	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread;
	void * thread_return;

	if(argc!=4) {
		printf("Usage : %s <IP> <port> <name>\n", argv[0]);
		exit(1);
	 }
	sprintf(name, "[%s]", argv[3]); //
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]); //IP
	serv_addr.sin_port = htons(atoi(argv[2])); //port number

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))== -1)
		error_handling("connect() error!");

	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);

	pthread_join(snd_thread, &thread_return);

	close(sock);
	return 0;
}

void * send_msg(void * arg)   // send thread main
{
	int sock=*((int*)arg);

	while(1)
	{

		memset(msg, 0, sizeof(BUF_SIZE));
		fgets(msg, BUF_SIZE, stdin);
		if(!strcmp(msg,"q\n")||!strcmp(msg,"Q\n"))
		{
			close(sock);
			exit(0);
		}
		write(sock, msg, strlen(msg));
	}
	return NULL;
}


void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
