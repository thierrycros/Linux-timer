#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
    

# define false 0
# define true 1
# define DUREE_TOMATE_EN_MINUTES 25


static struct itimerval vieilleValeurTimer;
static int minutes = 0;
    
void set_timer()
{
    struct itimerval leTimer;

    printf("Début d'une tomate de %d minutes... \n", minutes);

    leTimer.it_interval.tv_sec = minutes * 60;
    leTimer.it_interval.tv_usec = 0;
    leTimer.it_value.tv_sec = minutes * 60;
    leTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &leTimer, &vieilleValeurTimer); 
}
      
void signal_handler(int m)
{
    printf("Fin d'une tomate de %d minutes.\n", 
                    minutes);
}
      
int main(int argc, char * argv[])
{

    if (argc == 2)
        sscanf(argv[1], "%d", &minutes);
    else
        minutes = DUREE_TOMATE_EN_MINUTES;

    signal(SIGALRM, signal_handler); 
    set_timer(minutes); 

    pause();

    exit(0);
    return 0;
} 
