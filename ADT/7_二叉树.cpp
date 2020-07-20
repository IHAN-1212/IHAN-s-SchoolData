#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int TElemType;
typedef int TStatus;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*LinkTree;
typedef struct BiTree{
	LinkTree Root;
}BiTree;
TStatus InitBiTree(BiTree *T){
	T->Root=(LinkTree)malloc(sizeof(BiTNode));
	if(!T->Root){
		exit(OVERFLOW);
	}
	T->Root->lchild=NULL;
	T->Root->rchild=NULL;
	return 0;
}

int main(){
	BiTree T;
	InitBiTree(&T);
	return 0;
}


