#include  "commonHeader.h"
//获取共享内存标识符
int getSHMId(key_t key){
	int shmId=shmget(key,SHM_SIZE,IPC_CREAT|0666); 
	if(shmId<0)
	{
	 perror("The Shared Memory isn't allocted");
	 exit(EXIT_FAILURE);//exit_failure在头文件stdlib.h中
	}
	return shmId;
}

void semInit()
{
	if(sem_open(senderMutex,O_CREAT,0644,1)<0)
	{
		perror("sem open error");
		exit(EXIT_FAILURE);
	}	
	
	
	if(sem_open(receiverMutex,O_CREAT,0644,0)<0)
        {
        	perror("sem open error");
        	exit(EXIT_FAILURE);
        }	
}

void semDelete()
{
	sem_t *s = sem_open(senderMutex,O_CREAT);
	sem_t *r = sem_open(receiverMutex,O_CREAT);
	
	sem_close(s);
	sem_unlink(senderMutex);

	sem_close(r);
	sem_unlink(receiverMutex);
}

void p(sem_t *sem)
{
	sem_wait(sem);
}

void v(sem_t *sem)
{
	sem_post(sem);
}
