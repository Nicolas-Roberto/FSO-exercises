#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int x=0;

void handler_sig(int s)
{
	if(s == 10)
	{
		printf("SIGUSR1 eh para aproveitar mais um pouco\n");	
	}
	
	if(s == 14)
	{
		x++;
		if(x<3)
		{
			printf("Ai que sono, quero dormir mais um pouco\n"); 			
		} else {
			printf("os incomodados que se mudem, tchau"); 
			exit(0);		
		}
	
	}
}



int main()
{
       signal(SIGUSR1, handler_sig);
       signal(SIGALRM, handler_sig);
       
    while(1)
    {

    }

    return 0;
}


