#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int as[2],val,x;
	char ch[150];
	pid_t pid;
	pipe(as);
	pid=fork();
	
	if(pid>0)
	{
		close(as[0]);
		printf("\n \t Passing Hello LPU to child \t \n");
		write(as[1],"Hello LPU",9);
		wait(NULL);
	}
	else
	{
		close(as[x]);
		val=read(as[0],ch,150);
		printf("\n \t Output of the function is: ");
		for(x=0;x<val;x++)
		{
    			if(ch[x] >= 'A' && ch[x] <= 'Z')
    			{
				ch[x]=ch[x]+32;
        			printf("%c \t",ch[x]);
    			}
    			else if(ch[x] >= 'a' && ch[x] <= 'z')
    			{
				ch[x]=ch[x]-32;
        			printf("%c \t",ch[x]);
    			}
			else
			{	
				printf("%c \t",ch[x]);	
			}
		}
	}
	printf("\n \n");
}
