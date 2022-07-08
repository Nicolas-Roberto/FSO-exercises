#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

char c[30];

void sigPrintUSR1(int s){
	if(scanf("%s", c) == EOF) exit(0);
    	if(strncmp("Igor3k", c, 4) == 0) printf("Certo\n");
    	else printf("Erro\n");
}

void sigPrintINT(int s){
	if(scanf("%s", c) == EOF) exit(0);
	if(strcmp("Con1", c) == 0) printf("Certo\n");
    	else printf("Erro\n");
}
void sigPrintUSR2(int s){
	if(scanf("%s", c) == EOF) exit(0);
        if(strcmp("Monark", c) == 0) printf("Certo\n");
    	else printf("Erro\n");
}
void sigPrintTERM(int s){
	if(scanf("%s", c) == EOF) exit(0);
	if(strcmp("Con2", c) == 0) printf("Certo\n");
    	else printf("Erro\n");
}

void sigPrintALRM(int s){
	if(scanf("%s", c) == EOF) exit(0);
	if(strcmp("Silencio",c) == 0) printf("Certo\n");
	else printf("Erro\n");
}

int main()
{
       signal(SIGINT, sigPrintINT);
       signal(SIGTERM, sigPrintTERM);
       signal(SIGUSR1, sigPrintUSR1);
       signal(SIGUSR2, sigPrintUSR2);
       signal(SIGALRM, sigPrintALRM);
       
    while(1)
    {
    	wait(NULL);
    }

    return 0;
}


