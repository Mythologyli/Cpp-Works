/*
queue.h
*/


#ifndef QUENE_H
#define QUENE_H


#define MAX_LENGTH 10


struct Node //队列链表结点
{
	int member;
	Node* next;
};


class Queue //队列类
{
private:
	Node* front; //队列头指针
	Node* end; //队列尾指针

	int current_length; //当前队列长度。为保护 current_length 变量，仅能使用 CurrentLength 函数获取当前队列长度

public:
	Queue(void); //构造函数，用于初始化变量
	int CurrentLength(void); //返回当前队列长度
	bool IsFull(void); //判断队列是否已满
	bool IsEmpty(void); //判断队列是否为空
	int In(int num); //入队。若入队前队列已满，返回0
	int Out(void); //出队。若出队前队列已空，返回0
	int FrontMember(void); //返回队首元素。若队列已空，返回0。请结合 IsEmpty 函数使用
	int EndMember(void); //返回队尾元素。若队列已空，返回0。请结合 IsEmpty 函数使用
	~Queue(void); //析构函数，用于释放分配的空间
};


#endif