#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int QElemType;
typedef int QStatus;
typedef struct{
	QElemType *base;
	int front;
	int rear;	
}SqQueue;
 
QStatus InitQueue(SqQueue *Q){
	Q->base=(QElemType *)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q->base){
		exit(OVERFLOW);
	}	
	Q->front=Q->rear=0;
	return OK;
	
}

QStatus DestroyQueue(SqQueue *Q){
	while(Q->front!=Q->rear){
		free(&Q->base[Q->front]);
		Q->front=(Q->front+1)%MAXSIZE;
	}
	return OK;
}

QStatus ClearQueue(SqQueue *Q){
	Q->front=Q->rear=0;
	return OK;
}

QStatus QueueEmpty(SqQueue *Q){
	if(Q->front==Q->rear){
		return TRUE;
	}else{
		return FALSE;
	}
}

int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

QStatus GetHead(SqQueue *Q,QElemType *e){
	*e=Q->base[Q->front];
	return OK;
}

QStatus EnQueue(SqQueue *Q,QElemType e){
	if((Q->rear+1)%MAXSIZE==Q->front){
		return ERROR;
	}
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return OK;
}

QStatus DeQueue(SqQueue *Q,QElemType *e){
	if(Q->front==Q->rear){
		return ERROR;
	}
	*e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return OK;
}

QStatus QueueTraverse(SqQueue Q){
	int p;
	p=Q.front;
	printf("该队列为:"); 
	while(p!=Q.rear){
		printf("%d ",Q.base[p]);
		p=(p+1)%MAXSIZE;
	}
	printf("\n");
	return OK;
}

int main(){
	return 0;
}

