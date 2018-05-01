#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void runshell(char *command, char *addr)
{
        char **Pars = NULL;//will hold array of strings
	char str[1024]="";
	strcpy(str,command);//making copy of the command line
	char *p = strtok(str," ");
	int n=0;
	while(p != NULL)//tokenize the string to create list of words
	{
	Pars = realloc(Pars,sizeof(char *) * ++n);
	if(Pars == NULL)exit(1);//see if error using realloc
	Pars[n-1]=p;
	p=strtok(NULL," ");
	}
	Pars = realloc(Pars,sizeof(char *)*(n+1));// reallocted memory to store null
	Pars[n]=0;//adds null to end to indicate the end of list
	
    pid_t child;
    pid_t c;
    strcat(addr,"/");
    //if user want to use command list or create then we fork a child
    if(strcmp(Pars[0],"list")==0 || strcmp(Pars[0],"create")==0) {
    if((child = fork()) == 0)
    {

            //will call the appropriate program and pass it the arguments
		execvp(strcat(addr,Pars[0]),Pars);
	

	//if we reach this statement that means our exec call failed
        fprintf(stderr, "Child process could not do execvp\n"); exit(1);
    } else{
        if(child == (pid_t)(-1))//error checks to see if fork failed
        {
            fprintf(stderr,"Fork failed.\n");
            exit(1);
        } else{
            c = wait(NULL);//parent process waits for child to finish
           // exit(0);
        }
    }
  }
  else
  {
     if(strcmp(Pars[0],"wd")==0)//if user entered wd 
     {
       char cwd[1024];
	if(getcwd(cwd, sizeof(cwd))!=NULL)//we call getcwd to get the abs addr
	printf("%s\n",cwd);//print the abs addr
	else
	{
	  perror("Error: ");
	}

     }
     else
     if(strcmp(Pars[0],"chwd")==0)//if user entered chwd
     {
	if(chdir(Pars[1]) == -1)//we change our working directory
	perror("Error: ");


      }
     else//prints a statement saying user enters invalid command 
     {
  	fprintf(stderr,"You did not enter a valid command\n");
	
      }

  }

}

