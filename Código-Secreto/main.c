#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void sigPrintINT(int);
void sigPrintUSR1(int);
void sigPrintUSR2(int);
void sigPrintTERM(int);
int x=0;

int main()
{
       signal(SIGINT, sigPrintINT);
       signal(SIGTERM, sigPrintTERM);
       signal(SIGUSR1, sigPrintUSR1);
       signal(SIGUSR2, sigPrintUSR2);

    while(x!=4){}

    return 0;
}

void sigPrintUSR1(int s){
    	printf("Recebi %d\n", s);
        //sigusr1
            if(x==3) {printf("Tchau");}
            if(x==3) exit(0);
            	else x=0;

}

void sigPrintINT(int s){
    	printf("Recebi %d\n", s);
        //sigint
        x=1;

}
void sigPrintUSR2(int s){
    	printf("Recebi %d\n", s);
        //sigusr2
            if(x==1) x+=1;
            	else x=0;
}
void sigPrintTERM(int s){
    	printf("Recebi %d\n", s);

    	if(x==2) { printf("Senha acionada\n"); }
	    if(x==2) { x+=1; }
            else x=0;

}
