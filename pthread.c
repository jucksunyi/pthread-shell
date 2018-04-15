#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>  
#include <unistd.h>

void *mythread1(void)  
{  
    while(1)  
    {  
		printf("mythread1\n");
		system("/bin/sh /home/sunyi/test/while");
		sleep(1);
    }  
}  
  
void *mythread2(void)  
{  
	while(1)
    {
		printf("mythread2\n");
		system("bash /home/sunyi/test/test");
		sleep(1);
    }  
}   
  
int main(int argc, const char *argv[])  
{  
    int i = 0;  
    int ret = 0;  
    pthread_t id1,id2;  
  
    ret = pthread_create(&id1, NULL, (void *)mythread1,NULL);  
    if(ret)  
    {  
        printf("Create pthread error!\n");  
        return 1;  
    }  
  
    ret = pthread_create(&id2, NULL, (void *)mythread2,NULL);  
    if(ret)  
    {  
        printf("Create pthread error!\n");  
        return 1;  
    }  
      
	pthread_join(id1,NULL);	 
	pthread_join(id2,NULL);	 
  
    return 0;  
}  

// gcc pthread.c -lpthread -o pthread
