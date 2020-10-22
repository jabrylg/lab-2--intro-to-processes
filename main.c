#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int status;
    int child;
    int pid;

    pid = fork();
  
    if (0 == pid)
    {
        int x;//the child is put to sleep for a random amount of time
        
        for (x = 0; x < (rand() % 30 + 1); x++)
        {
            printf("Child Pid = %d is going to sleep\n", getpid());
            sleep(rand() % 10 + 1);
        }

        printf("Child Pid = %d is up! Where is my parent = %d?\n", getpid(), getppid());
        exit(0);
        // break;
    }
    if (pid == -1){}
    else
    {
        wait(&status);
        printf("Child = %d has finished\n", getpid() + 1);
    }
    printf("Exit/terminating \n");
    return 0;
}