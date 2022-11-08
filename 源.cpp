#include<stdio.h>
#include<stdlib.h>
//˫����ṹ
typedef struct LNode {
	int val;
	LNode* next;
	LNode* prior;
}LNode,*Linklist;

//β�彨��
void CreateLinkList(Linklist& L) {
	L = new LNode;
	L->next = L;
	L->prior = L;
	LNode* p = L;
	int a;
	printf("������������:\n");
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
//��ӡ����
void ShowList(Linklist L) {
	LNode* p = L->next;
	while (p != L) {
		printf("%d\t", p->val);
		p = p->next;
	}
}
//�ж϶Գ�
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
	printf("1.�ж϶Գ�\n2.��������\n");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
		CreateLinkList(L);
		b = IsSym(L);
		printf("%d", b);
	case 2:
		printf("�������1��\n");
		CreateLinkList(L);
		printf("�������2��\n");
		CreateLinkList(L1);
		CirlistAandB(L, L1);
		printf("�ϲ���ı�\n");
		ShowList(L);
	default:
		break;
	}
	
}
