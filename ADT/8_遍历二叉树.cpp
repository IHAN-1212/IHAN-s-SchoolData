#include "stdio.h"
#include "stdlib.h" 
typedef struct BiTreeNode{
	char data;
	struct BiTreeNode *Lchild,*Rchild;
}BTNode,*BiTree;
//根据先序遍历创建二叉树
void CreateTreeDLR(BiTree *Tree){
	char ch;
	ch=getchar();
	if(ch=='?'){
		*Tree=NULL;
	}
	else{
		*Tree=(BiTree)malloc(sizeof(BTNode));
		(*Tree)->data=ch;
		CreateTreeDLR(&((*Tree)->Lchild));
		CreateTreeDLR(&((*Tree)->Rchild));
	}
}
//先序遍历
void PreOrderTraverse(BiTree T){
	if(T){
		printf("%c",T->data);
		PreOrderTraverse(T->Lchild);
		PreOrderTraverse(T->Rchild);
	}
}
//中序遍历
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->Lchild);
		printf("%c",T->data);
		InOrderTraverse(T->Rchild);
	}
}
//后序遍历 
void PostOrderTraverse(BiTree T){
	if(T){
		PostOrderTraverse(T->Lchild);
		PostOrderTraverse(T->Rchild);
		printf("%c",T->data);
	}
}
int main(){
	BiTree T=NULL;
	printf("请输入你要创建的二叉树的先序扩展序列（？表示空结点）：");
	CreateTreeDLR(&T);
	printf("\n先序遍历\t");
	PreOrderTraverse(T);
	printf("\n中序遍历\t");
	InOrderTraverse(T);
	printf("\n后序遍历\t");
	PostOrderTraverse(T);
}
