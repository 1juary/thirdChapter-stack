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

//初始化队列
bool InitLinkQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
	return true;
}

//入队,尾部插入法
bool EnLinkQueue(LinkQueue& Q,ElemType x) {
	LinkNode* S = (LinkNode*)malloc(sizeof(LinkNode));
	S->data = x;
	S->next = NULL;
	Q.rear->next = S;//一开始队头和队尾重合，有元素后从队尾入队
	Q.rear = S;//Q.rear永远指向队尾元素
	return true;
}
//出队，头部出队法
bool DeQueue(LinkQueue& Q, ElemType& X) {
	if (Q.rear == Q.front) {
		return false;
	}
	LinkNode* p = Q.front->next;//头节点什么都没存
	X = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)//删除的是最后一个元素
		Q.rear = Q.front;//队列置为空
	free(p);
	return true;
}
//判断是否为空
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
		printf("初始化成功\n");
	}
	else {
		printf("初始化失败\n");
	}
	EnLinkQueue(Q, 1);
	EnLinkQueue(Q, 2);
	EnLinkQueue(Q, 3);
	EnLinkQueue(Q, 4);
	elem = DeQueue(Q, elem);

}