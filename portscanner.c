/*
TCP Connect Scan
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/signal.h>
#include <errno.h>
#include <netdb.h>

void banner(){
printf("\n-------------------------------------");
printf("\n---TCP CONNECT SCANNER---------------");
printf("\n-----------------------------V.0.1---");

printf("\n[+]fuck u banner");
printf("\n./scanner <host> <port> <port>");
printf("\n That means, like './scanner 192.169.1.1 1 100', will scan the 1 to 100");
}

int main(int argc, char *argv[]){ //argc arguments count, argument vetor
if (argc ==1){
	banner();
	exit (0);
} 
int portstart, portend, i, sock, conexao;
char *endereco; //Variavel que armazena o endereço para conectar
portstart = 1; //Zero is not a port who can be used.
portend   = 65535; //The last port for the life
struct sockaddr_in destino;
if (argv > 1){
	endereco  = argv[1];
	if (argv[2] != 0 ){
	portstart = atoi(argv[2]);
	portend   = atoi(argv[3]);
	}
}else{printf("\n[+]-Error input");}
printf("\n[+]-Start in  %s | Port %d to %d",endereco,  portstart, portend);
for(i=portstart; i<portend; i++){
	sock = socket(AF_INET , SOCK_STREAM , 0);
	destino.sin_family = AF_INET;
	destino.sin_port = htons(i);
	destino.sin_addr.s_addr = inet_addr(endereco);
	bzero(&(destino.sin_zero),8);
	conexao = connect(sock,(struct sockaddr*)&destino, sizeof(destino)); //Abrindo a conexão
	if(conexao < 0 ) {
		close(conexao);
		close(sock);
	}
	else{
		printf("\n[+]-Port %d STATUS:OPEN", i );
		close(conexao);
		close(sock);

	}
 }
	printf("\n[+]-Done\n");
	return (0);
}
