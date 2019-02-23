 #include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>

int main()
{
  int fd[2];

  pipe(fd);

  pid_t pid = fork();

  if (pid == -1)  
    return -1;  

  if (pid == 0)  
  {  
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    execlp("ls", "ls", NULL);
  }

  else
  {
    close(fd[1]);
   dup2(fd[0], STDIN_FILENO);
   close(fd[0]);
   execlp("cat", "cat", NULL);
  }
}