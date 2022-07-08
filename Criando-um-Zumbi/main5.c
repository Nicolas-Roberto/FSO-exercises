#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


int x=0;
void handler_sig(int s)
{
	x=s; 
}



int main()
{

       signal(SIGUSR1, handler_sig);
       signal(SIGUSR2, handler_sig);
	
	pause();
	if(fork()==0) exit(0);
	pause(); 
	wait(NULL);
	pause();
	exit(0);

       
    while(1)
    {

    }

    return 0;
}


