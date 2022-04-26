#include <unistd.h>
int main(void)
{
    pid_t pid;
    pid = fork();
    // After the command above, now we have two processes
    // that share the same code and keeps running under this line
    
    //so is this the child process or parent
    if(pid == 0){
        //this is child
        printf("Child>>Hi, I am child with pid=%d\n", getpid() );
        sleep(3);
        printf("Child>>Ok I am done..\n");
    }
    
    if(pid > 0){
        //this is parent
        printf("I am parent and will wait until that bastard %d finishes\n", pid);
        int status;
        wait(&status);
        //that status code carries the real return code but it
        //starts from the 8th bit of status value
        //so we must shift it to right 8 times
        printf("Finally, the child died %d", status>>8);         
    }
    //well right now the parent and child uses the same exit code
    exit(50);
}
