#ifndef _BAD_LENGTH_H_
#define _BAD_LENGTH_H_
#include <exception>
#include <iostream>
using namespace std;
class Bad_Length_0 : public  exception
{
	public:
		virtual const char* what() const noexcept override
		{
			return "������������ ��������!";
		}
};
class Bad_Length_1 : public exception
{
	public:
		virtual const char* what() const noexcept override
		{
			return "���������� ID �� ���������!";
		}
};
#endif /* _BAD_LENGTH_H_ */