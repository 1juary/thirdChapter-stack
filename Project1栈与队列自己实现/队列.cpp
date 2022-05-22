#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef int ElemType;
typedef struct {//队列
	ElemType data[MaxSize];
	int front, rear;//队列头、队列尾
}SqQueue;//队列别名

//初始化队列
void InitQueue(SqQueue& sq) {//队头队尾相等
	sq.front = sq.rear = 0;
}
//是否为空
bool isEmpty(SqQueue& sq)
{
	if (sq.rear == sq.front)//不需要为零
		return true;
	else
		return false;
}
//入队
bool EnQueue(SqQueue& sq, ElemType x) {
	if ((sq.rear + 1) % MaxSize == sq.front)// 判断是否
		return false;
	sq.data[sq.rear] = x;
	sq.rear = (sq.rear + 1) % MaxSize;//循环队列
	return true;
}
//出队
bool DeQueue(SqQueue& sq, ElemType& x) {
	if (sq.front == sq.rear)
		return false;//MaxSize 的队列，只能存储MaxSize-1个元素
	x = sq.data[sq.front];
	sq.front = (sq.front + 1) % MaxSize;
	return true;
}

int main() {
	SqQueue sq;
	bool ret;
	ElemType elem;
	InitQueue(sq);
	printf("初始化成功\n");
	ret = EnQueue(sq, 3);
	ret = EnQueue(sq, 4);
	ret = EnQueue(sq, 5);
	ret = EnQueue(sq, 6);
	ret = EnQueue(sq, 7);//MaxSize 的队列，只能存储MaxSize-1个元素，不能成功入队
	if (ret)
	{
		printf("入队成功\n");
	}
	else {
		printf("入队失败\n");
	}
	ret = DeQueue(sq, elem);
	if (ret)
	{
		printf("出队成功,元素值为 %d\n", elem);
	}
	else {
		printf("出队失败\n");
	}
	ret = EnQueue(sq, 8);




}
