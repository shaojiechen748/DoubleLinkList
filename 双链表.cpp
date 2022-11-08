#include<stdio.h>
#include<stdlib.h>
//双链表结构
typedef struct LNode {
	int val;
	LNode* next;
	LNode* prior;
}LNode,*Linklist;

//尾插建表
void CreateLinkList(Linklist& L) {
	L = new LNode;
	L->next = L;
	L->prior = L;
	LNode* p = L;
	int a;
	printf("请输入表的数据:\n");
	scanf_s("%d", &a);
	while (a!=9999) {
		LNode* s = new LNode;
		s->val = a;
		s->next = p->next;
		p->next->prior = s;
		p->next = s;
		s->prior = p;
		p = p->next;
		scanf_s("%d", &a);
	}
	
}
//打印链表
void ShowList(Linklist L) {
	LNode* p = L->next;
	while (p != L) {
		printf("%d\t", p->val);
		p = p->next;
	}
}
//判断对称
bool IsSym(Linklist L) {
	LNode* p = L->next, * r = L->prior;
	while (p != r) {
		if (p->val != r->val) {
			return false;
		}
		else {
			p = p->next;
			r = r->prior;
		}
	}
	return p == r;
}
void CirlistAandB(Linklist &L1,Linklist L2) {
	LNode* p1 = L1, * p2 = L2;
	while (p1->next!= L1) {
		p1 = p1->next;
	}
	while (p2->next != L2) {
		p2 = p2->next;
	}
	p1->next = L2->next;
	p2->next = L1;
}
void main() {
	Linklist L,L1; int a,b;
	printf("1.判断对称\n2.链接两表\n");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
		CreateLinkList(L);
		b = IsSym(L);
		printf("%d", b);
	case 2:
		printf("请输入表1：\n");
		CreateLinkList(L);
		printf("请输入表2：\n");
		CreateLinkList(L1);
		CirlistAandB(L, L1);
		printf("合并后的表：\n");
		ShowList(L);
	default:
		break;
	}
	
}
