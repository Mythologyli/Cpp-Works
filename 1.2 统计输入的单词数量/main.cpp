/*
设计一个循环程序，读取用户输入的单词并存入 char 数组（数组可重复利用），直到用户输入 end 为止。统计用户一共输入了多少个单词。
*/


#include <iostream>
#include <cstring>


using namespace std;


#define MAX_WORD_LENGTH 10 //接受字符串的最大长度为 10


class Word
{
private:
	char current_word[MAX_WORD_LENGTH + 1]; //字符数组，存放输入的当前字符串
	int amount; //累计输入的合法字符串的数量。使用 private 属性保护该变量

public:
	Word(void); //构造函数，用于初始化变量
	int InputWord(const char* str); //输入合法字符串，若输入 end 则返回 0。使用 InputWord 时，必须保证字符串不超过最大长度
	int GetAmount(void); //返回累计输入的合法字符串的数量
};


Word::Word(void) //构造函数，用于初始化变量
{
	current_word[0] = 0;
	amount = 0;
}


int Word::InputWord(const char* str) //输入合法字符串，若输入 end 则返回 0。使用 InputWord 时，必须保证字符串不超过最大长度
{
	strcpy_s(current_word, str);
	amount++;

	if (!strcmp(current_word, "end")) //若输入 end 则返回 0
		return 0;

	return 1;
}


int Word::GetAmount(void) //返回累计输入的合法字符串的数量
{
	return amount;
}


int main()
{
	cout << "本程序用于统计用户一共输入了多少个单词" << endl;
	cout << "输入 end 结束输入过程。统计的单词数量包括 end" << endl;
	cout << "输入字符串的最大长度为 10" << endl;
	cout << "作者：Peisheng Li  日期：2020/11/26" << endl;
	
	Word word;

	string input_word; //为防止用户输入过长的字符串导致溢出，这里采用 string 类的实现方法

	while (1) //循环输入。使用 break 跳出
	{
		cout << "请输入单词：";
		cin >> input_word;

		if (input_word.size() > MAX_WORD_LENGTH) //调用 InputWord 前判断字符串是否过长，避免在 word 内的 char 数组溢出
		{
			cout << "输入的字符串过长！请重新输入" << endl;
			continue;
		}

		if (!word.InputWord(input_word.c_str())) //若 InputWord 返回 0，说明输入为 end
		{
			cout << "输入结束。共计输入单词数为：" << word.GetAmount() << endl;
			break;
		}
		else
		{
			cout << "输入成功！" << endl;
		}
	}


	return 1;
}