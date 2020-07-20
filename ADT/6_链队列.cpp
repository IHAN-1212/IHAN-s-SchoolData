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
typedef struct QNode{
	QElemType date;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

QStatus InitQueue(LinkQueue *Q){
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode)); 
	if(!Q->front){
		exit(OVERFLOW);
	}
	Q->front->next=NULL;
	return OK; 
}

QStatus DestroyQueue(LinkQueue *Q){
	while(Q->front){
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
	}
	return OK;
}

QStatus ClearQueue(LinkQueue *Q){

}

QStatus QueueEmpty(LinkQueue Q);

int QueueLength(LinkQueue Q);

QStatus GetHead(LinkQueue Q,QElemType *e){
	*e=Q.front->next->date;
}

QStatus EnQueue(LinkQueue *Q,QElemType e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p){
		exit(OVERFLOW);
	}
	p->date=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}

QStatus DeQueue(LinkQueue *Q,QElemType *e){
	QueuePtr p;
	if(Q->front==Q->rear){
		return ERROR;
	}
	p=Q->front->next;
	*e=p->date;
	Q->front->next=p->next;
	if(Q->rear==p){
		Q->rear=Q->front;
	}
	free(p);
	return OK;
}

QStatus QueueTraverse(LinkQueue Q);

int main(){
	return 0;
}
