#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//����
	int top;
}SqStack;

//��ʼ��ջ
void InitStack(SqStack& S) {
	S.top = -1;//����ջΪ��
}
//�ж�ջ�Ƿ�Ϊ��
bool IsStackEmpty(SqStack& S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}

//��ջ
bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize - 1) {
		return false;
	}
	S.data[++S.top] = x;;//��ջ��ջ����һ
	return true;
}
//��ջ
bool Pop(SqStack& S, ElemType& x) {
	if (-1 == S.top) {
		return false;
	}
	x = S.data[S.top--];
	return true;
}
//��ȡջ��Ԫ��
bool GetTop(SqStack& S, ElemType& x) {
	if (-1 == S.top) {
		return false;
	}
	x = S.data[S.top];
	return true;
}
int main() {
	SqStack S;//�Ƚ���� FILO  LIFO
	bool flag;
	ElemType m;//��������ó���Ԫ��
	InitStack(S);//��ʼ��
	flag = IsStackEmpty(S);
	Push(S, 0);
	Push(S, 1);
	Push(S, 2);
	Pop(S, m);
	flag = IsStackEmpty(S);
	if (flag) {
		printf("ջΪ��\n");
	}
	else {
		printf("ջ����%d��Ԫ��\n", S.data[S.top]+1);
		if (m) {
			printf("��ջԪ��%d\n", m);
		}
	}

}