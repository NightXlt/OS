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

void receiveMessage()
{
	p(r);
	p(s);
	strcpy(input,shmAddr);
	strcpy(shmAddr,"over");
	v(s);
}

int main(int argc, char const *argv[])
{
	Init();
	receiveMessage();
	printf("the message is %s\n",input);
	return 0;
}
