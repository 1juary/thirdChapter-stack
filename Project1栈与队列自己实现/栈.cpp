#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack &S) {
	S.top = -1;//代表栈为空
}
//判断栈是否为空
bool StackEmpty(SqStack& S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}

//入栈
bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize - 1) {
		return false;
	}
	S.data[++S.top] = x;;//入栈后，栈顶加一
	return true;
}
//出栈
bool Pop(SqStack& S, ElemType &x) {
	if ( -1 == S.top) {
		return false;
	}
	x = S.data[--S.top];
	return true;
}
int main() {
	SqStack S;//先进后出 FILO  LIFO
	bool flag;
	ElemType m;//用来存放拿出的元素
	InitStack(S);//初始化

}