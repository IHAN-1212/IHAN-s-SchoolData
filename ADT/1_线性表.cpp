#include "stdio.h" 
#include "stdlib.h"

#define LIST_SIZE 100
#define LIST_INCREMENT 10

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW_ -2

typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;


Status InitList(SqList* L) {
	L->elem = (ElemType*)malloc(sizeof(ElemType) * LIST_SIZE);
	if (!L->elem)
	{
		exit(OVERFLOW_);
	}
	L->length = 0;
	L->listsize = LIST_SIZE;
	return OK;
}
 
Status DestroyList(SqList* L) {
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
	return OK;
}
 
Status ClearList(SqList* L) {
	L->length = 0;
	return OK;
}
 
Status ListEmpty(SqList L) {
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ListLength(SqList L) {
	return L.length;
}

Status GetElem(SqList L, int i, int* e) {
	if (i<1 || i>L.length) {
		return ERROR;
	}
	*e = *(L.elem + i - 1);
	return OK;
}

Status LocateElem(SqList L, int e) {
	int i = 0, f = FALSE;
	while (L.length--) {
		if (L.elem[i] == e) {
			f = TRUE;
			break;
		}
		i++;
	}
	if (f) {
		return i + 1;
	}
	else {
		return FALSE;
	}
}

Status PriorElem(SqList L, int cur_e, int* pre_e) {
	int i;
	int* p = L.elem;
	for (i = 0; i < L.length; i++, p++) {
		if (i == 0 && *p == cur_e) {
			return FALSE;
		}
		if (*p == cur_e) {
			*pre_e = *--p;
			return TRUE;
		}
	}
	return FALSE;
}

Status NextElem(SqList L, int cur_e, int* next_e) {
	int i;
	int* p = L.elem;
	for (i = 0; i < L.length; i++,p++) {
		if (i == L.length - 1 && *p == cur_e){
			return FALSE;
		}	
		if (*p == cur_e) {
			*next_e = *++p;
			return TRUE;
		}
	}
	return FALSE;
}

Status ListInsert(SqList* L, int i, int e) {
	int* p, * q, * newinsert;
	if (L->length >= L->listsize) {
		newinsert = (ElemType*)realloc(L->elem, sizeof(ElemType) * (LIST_SIZE + LIST_INCREMENT));
		if (!newinsert) {
			exit(OVERFLOW_);
		}
		L->elem = newinsert;
		L->listsize = L->listsize + LIST_INCREMENT;
	}
	q = &(L->elem[i - 1]);
	p = &(L->elem[L->length - 1]);
	for (; p >= q; p--) {
		*(p + 1) = *p;
	}
	L->elem[i - 1] = e;
	L->length++;
	return TRUE;
}

Status ListDelete(SqList* L, int i, int* e) {
	int* p;
	if (i<1 || i>L->length) {
		return FALSE;
	}
	p = &(L->elem[i - 1]);
	*e = L->elem[i - 1];
	for (; p <= &(L->elem[L->length + 1]); p++) {
		*p = *(p + 1);
	}
	L->length--;
	return TRUE;
}

Status TravelList(SqList L) {
	int i;
	int* p = L.elem;
	for (i = 0; i < L.length; i++,p++) {
		printf("第%d个元素为:%d\n", i + 1, *p);
	}
	return TRUE;
}


void Union(SqList* La, SqList* Lb) {
	int i, La_len, Lb_len;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(*Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		e = Lb->elem[i - 1];
		if (!LocateElem(*La, e)) {
			ListInsert(La, ++La_len, e);
		}
	}
}

void MergeList(SqList La, SqList Lb, SqList & Lc) {
	int i = 1, j = 1, k = 1;
	int ai, bi;
	while ((i <= La.length) && (j <= Lb.length)) {
		GetElem(La, i, &ai);
		GetElem(Lb, j, &bi);
		if (ai <= bi) {
			ListInsert(&Lc, k++, ai);
			++i;
		}
		else {
			ListInsert(&Lc, k++, bi);
			++j;
		}
	}
	while (i <= La.length) {
		GetElem(La, i++, &ai);
		ListInsert(&Lc, k++, ai);
	}
	while (j <= Lb.length) {
		GetElem(Lb, j++, &bi);
		ListInsert(&Lc, k++, bi);
	}
}

void InPut(SqList* L, int num) {
	int i = 0;
	printf("请输入数据元素:");
	for (; i < num; i++) {
		scanf("%d", &L->elem[i]); 
	}
}

void OutPut(SqList* L) {
	int i;
	printf("该线性表数据元素为:\n");
	for (i = 0; i < L->length; i++) {
		printf("%d\t", L->elem[i]);
	}
	printf("\n");
}

int main(){
	return 0;
} 
