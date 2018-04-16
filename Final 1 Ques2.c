#include<stdio.h>
#include<pthread.h>

void *th_f1();
void *th_f2();
void *th_f3();

int a[10]={12,10,15,23,28};
int b[10]={12,10,15,23,28};
int c[10]={12,10,15,23,28};
pthread_mutex_t l;
int min; int max;
float sum=0;

int main()
  {
	 pthread_mutex_init(&l,NULL);
	 pthread_t th1,th2,th3;
	 pthread_create(&th1, NULL,th_f1, NULL);
     pthread_create(&th2, NULL,th_f2, NULL);
     pthread_create(&th3, NULL,th_f3, NULL);
    
     pthread_join(th1, NULL);
     pthread_join(th2, NULL);
     pthread_join(th3, NULL);
    
     printf("\tAverage from the Array1 %.2f\n \t",sum);
     printf("Minimum Value from the Array2 %d\n \t",min);
     printf("Maximum Value From the Array 3 %d\n \t",max);
    
  }
void *th_f1()
{ 
    int x;
	pthread_mutex_lock(&l);
	for(x=0;x<5;x++)
	{
	  sum=sum+a[x];
    }
	sum=sum/5;
	pthread_mutex_unlock(&l);
}
void *th_f2()
{
	int x;
	pthread_mutex_lock(&l);
	min=b[0];
	for(x=0;x<5;x++)
	{	
		if(b[x]<min)
		{	
			min=b[x];
		}	
	}
	
	pthread_mutex_unlock(&l);
}
void *th_f3()
{
	int x;
	pthread_mutex_lock(&l);
	max=c[0];
	for(x=0;x<5;x++)
	{	if(c[x]>max)
		{	
			max=c[x];
		}	
	}
pthread_mutex_unlock(&l);
}
