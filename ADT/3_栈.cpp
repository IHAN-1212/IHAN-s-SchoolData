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
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

SStatus InitStack(SqStack *S){
	S->base=(SElemType *)malloc(sizeof(SElemType)*STACK_SIZE);
	if(!S->base){
		exit(OVERFLOW);
	}
	S->top=S->base;
	S->stacksize=STACK_SIZE;
	return OK; 
}

SStatus DestroyStack(SqStack *S){
	int *p;
	p=S->top;
	while(S->base!=S->top){
		free(p);
		p--;
	}
	return OK;
}

SStatus ClearStack(SqStack *S){
	S->top=S->base;
	return OK;
}

SStatus StackEmpty(SqStack S){
	if(S.base==S.top){
		return TRUE;
	}else{
		return FALSE;
	}
}

int StackLength(SqStack S){
	int i=0,*p;
	p=S.top;
	while(p!=S.base){
		i++;
		p--;
	}
	return i;
}

SStatus GetTop(SqStack S,SElemType *e){
	if(S.base==S.top){
		return ERROR;
	}
	*e=*(S.top-1);
	return OK;
}

SStatus Push(SqStack *S,SElemType e){
	if(S->top-S->base>=S->stacksize){
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACK_INCREMENT)*sizeof(SElemType));
		if(!S->base){
			exit(OVERFLOW);
		}
		S->top=S->base+S->stacksize;
		S->stacksize+=STACK_INCREMENT;
	}
	*S->top++=e;
	return OK;
}

SStatus Pop(SqStack *S,SElemType *e){
	if(S->base==S->top){
		return ERROR;
	}
	*e=*(--S->top);
	return OK;
}

SStatus StackTraverse(SqStack S){
	if(S.base==S.top){
		return ERROR;
	}
	int *p;
	p=S.top;
	while(p!=S.base){
		p--;
		printf("%d\t",*p);
	}
}

int main(){
	return 0;
} 
