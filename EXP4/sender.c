#include "commonHeader.h"

char input[SHM_SIZE];
char *shmAddr;
sem_t *s,*r;
void Init()
{
	int shmId=getSHMId(KEY);
	semInit();
	shmAddr=shmat(shmId,NULL,0);//获取共享内存地址
	s=sem_open(senderMutex,O_CREAT);
	r=sem_open(receiverMutex,O_CREAT);
}

void sendMessage()
{
	p(s);
	strcpy(shmAddr,input);
	v(s);
	v(r);
}

int getMessage()
{
	p(s);
	strcpy(input,shmAddr);
        v(s);
	if(strcmp(input,"over"))
	  return 1;
	else 
	{
	  printf("over\n");
	  return 0;
	}
}
int main(int argc,char const *argv[])
{
	Init();
	printf("please input messages:");
	scanf("%s",input);
	sendMessage();
	while(getMessage())
	{
	 sleep(3);
	}
	semDelete();
	return 0;
}
