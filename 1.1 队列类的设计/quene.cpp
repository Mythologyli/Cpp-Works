/*
quene.cpp
*/


#include "quene.h"


int Quene::CurrentLength(void) //返回当前队列长度
{
	return current_length;
}


bool Quene::IsFull(void) //判断队列是否已满
{
	if (current_length == MAX_LENGTH)
		return true;
	else return false;
}


bool Quene::IsEmpty(void) //判断队列是否为空
{
	if (current_length == 0)
		return true;
	else return false;
}


int Quene::In(int num) //入队。若入队前队列已满，返回0
{
	if (current_length == MAX_LENGTH) //队列已满，返回0
		return 0;

	Node* new_end = new Node; //为新的队尾分配结点空间
	new_end->member = num;
	new_end->next = nullptr;

	if (current_length == 0) //队列为空，设置 front 和 end 均为 new_end
	{
		front = end = new_end;
	}
	else //队列非空
	{
		end->next = new_end; //原队尾指向新队尾
		end = new_end; //变更队尾
	}

	current_length++;

	return 1;
}


int Quene::Out(void) //出队。若出队前队列已空，返回0
{
	if (current_length == 0) //队列已空，返回0
		return 0;

	Node* old_front = front;
	front = old_front->next; //变更队首
	delete old_front; //删除原队首

	current_length--;

	return 1;
}


int Quene::FrontMember(void) //返回队首元素。若队列已空，返回0。请结合 IsEmpty 函数使用
{
	if (current_length == 0) //队列已空，返回0
		return 0;
	
	return front->member;
}


int Quene::EndMember(void) //返回队尾元素。若队列已空，返回0。请结合 IsEmpty 函数使用
{
	if (current_length == 0) //队列已空，返回0
		return 0;

	return end->member;
}