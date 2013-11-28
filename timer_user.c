#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
    

# define false 0
# define true 1
# define DUREE_TOMATE_EN_MINUTES 10


static int continuer = true;

static struct itimerval vieilleValeurTimer;
    
void set_timer(int minutes)
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
    continuer = false;
    printf("Fin d'une tomate de %d minutes.\n", 
                    DUREE_TOMATE_EN_MINUTES);
}
      
int main()
{
    signal(SIGALRM, signal_handler); 

    
    set_timer(DUREE_TOMATE_EN_MINUTES); 

    while(continuer == true);
    
    exit(0);
    return 0;
} 
