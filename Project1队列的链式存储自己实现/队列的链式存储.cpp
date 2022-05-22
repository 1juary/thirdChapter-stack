#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct  {
	LinkNode* front, * rear;
}LinkQueue;

//��ʼ������
bool InitLinkQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
	return true;
}

//���,β�����뷨
bool EnLinkQueue(LinkQueue& Q,ElemType x) {
	LinkNode* S = (LinkNode*)malloc(sizeof(LinkNode));
	S->data = x;
	S->next = NULL;
	Q.rear->next = S;//һ��ʼ��ͷ�Ͷ�β�غϣ���Ԫ�غ�Ӷ�β���
	Q.rear = S;//Q.rear��Զָ���βԪ��
	return true;
}
//���ӣ�ͷ�����ӷ�
bool DeQueue(LinkQueue& Q, ElemType& X) {
	if (Q.rear == Q.front) {
		return false;
	}
	LinkNode* p = Q.front->next;//ͷ�ڵ�ʲô��û��
	X = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)//ɾ���������һ��Ԫ��
		Q.rear = Q.front;//������Ϊ��
	free(p);
	return true;
}
//�ж��Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	LinkQueue Q;
	bool ret;
	ElemType elem;
	ret = InitLinkQueue(Q);
	if (ret) {
		printf("��ʼ���ɹ�\n");
	}
	else {
		printf("��ʼ��ʧ��\n");
	}
	EnLinkQueue(Q, 1);
	EnLinkQueue(Q, 2);
	EnLinkQueue(Q, 3);
	EnLinkQueue(Q, 4);
	elem = DeQueue(Q, elem);

}