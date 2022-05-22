#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef int ElemType;
typedef struct {//����
	ElemType data[MaxSize];
	int front, rear;//����ͷ������β
}SqQueue;//���б���

//��ʼ������
void InitQueue(SqQueue& sq) {//��ͷ��β���
	sq.front = sq.rear = 0;
}
//�Ƿ�Ϊ��
bool isEmpty(SqQueue& sq)
{
	if (sq.rear == sq.front)//����ҪΪ��
		return true;
	else
		return false;
}
//���
bool EnQueue(SqQueue& sq, ElemType x) {
	if ((sq.rear + 1) % MaxSize == sq.front)// �ж��Ƿ�
		return false;
	sq.data[sq.rear] = x;
	sq.rear = (sq.rear + 1) % MaxSize;//ѭ������
	return true;
}
//����
bool DeQueue(SqQueue& sq, ElemType& x) {
	if (sq.front == sq.rear)
		return false;//MaxSize �Ķ��У�ֻ�ܴ洢MaxSize-1��Ԫ��
	x = sq.data[sq.front];
	sq.front = (sq.front + 1) % MaxSize;
	return true;
}

int main() {
	SqQueue sq;
	bool ret;
	ElemType elem;
	InitQueue(sq);
	printf("��ʼ���ɹ�\n");
	ret = EnQueue(sq, 3);
	ret = EnQueue(sq, 4);
	ret = EnQueue(sq, 5);
	ret = EnQueue(sq, 6);
	ret = EnQueue(sq, 7);//MaxSize �Ķ��У�ֻ�ܴ洢MaxSize-1��Ԫ�أ����ܳɹ����
	if (ret)
	{
		printf("��ӳɹ�\n");
	}
	else {
		printf("���ʧ��\n");
	}
	ret = DeQueue(sq, elem);
	if (ret)
	{
		printf("���ӳɹ�,Ԫ��ֵΪ %d\n", elem);
	}
	else {
		printf("����ʧ��\n");
	}
	ret = EnQueue(sq, 8);




}
