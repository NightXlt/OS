#ifndef _COMMONHEADER_H
#define _COMMONHEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

static char *senderMutex="mutex_sneder";
static char *receiverMutex="mutex_receiver";

//定义内存块的大小
#define SHM_SIZE 1024

#define KEY 1000

int getSHMId(key_t key);

void semInit();

void semDelete();

void p(sem_t *sem);

void v(sem_t *sem);
#endif
