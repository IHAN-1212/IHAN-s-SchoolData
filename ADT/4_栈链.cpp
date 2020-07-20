#include "stdio.h"
#include "stdlib.h"

#define STACK_SIZE 20
#define STACK_INCREMENT 5

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int SElemType;
typedef int SStatus;
typedef struct SNode{
	SElemType date;
	struct SNode *next;
}SNode,*StackPtr;
typedef struct{
	StackPtr top;
	int length;
}LinkStack;

SStatus InitStack(LinkStack *S){
	S->top=(StackPtr)malloc(sizeof(SNode));
	if(!S->top){
		exit(OVERFLOW);
	}
	S->length=0;
	S->top->next=NULL;
	return OK; 
}

SStatus DestroyStack(LinkStack *S){
	StackPtr p;
	while(S->top){
		p=S->top->next;
		free(S->top);
		S->top=p;
	}
	return OK;
}

SStatus ClearStack(LinkStack *S){
	StackPtr p,q;
	p=S->top;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	S->top->next=NULL;
	return OK;
}

SStatus StackEmpty(LinkStack S){
	if(S.top->next==NULL){
		return TRUE;
	}else{
		return FALSE;
	}
}

int StackLength(LinkStack S){
	return S.length;
}

SStatus GetTop(LinkStack S,SElemType *e){
	if(S.top->next==NULL){
		return ERROR;
	}
	*e=S.top->next->date;
	return OK;
}

SStatus Push(LinkStack *S,SElemType e){
	StackPtr p;
	p=(StackPtr)malloc(sizeof(SNode));
	if(!p){
		return ERROR;
	}
	p->date=e;
	p->next=S->top->next;
	S->top->next=p;
	S->length++;
	return OK;
}

SStatus Pop(LinkStack *S,SElemType *e){
	StackPtr p;
	p=S->top->next;
	if(p==NULL){
		return ERROR;
	}
	*e=p->date;
	S->top->next=p->next;
	S->length--;
	return OK;
}

SStatus StackTraverse(LinkStack S){
	StackPtr p,q;
	p=S.top->next;
	while(p!=NULL){
		q=p->next;
		printf("%d\t",p->date);
		p=q;
	}
	printf("\n");
	return OK;
}

int main(){
	return 0;
} 
