#ifndef _MY_CLASS_H_
#define _MY_CLASS_H_
#include <iostream>
#include <string>
#include "Bad_Length.h"
using namespace std; // ���� ���������� ������������ ���!!!!!!!!!!!!!!!!
class User_registration // ����������� ������������� 
{
	public:
		string _Name_user = " "; // ��� ��������������� ������������ 
		unsigned int _Password_user = 0; // ������ ��������������� ������������
		unsigned int _ID_user = 0; // ��������������� �����
		//unsigned short _Quantity; // ���������� �������������� �������������.?
	public:
		User_registration (); 
		~User_registration (); // ����������
		User_registration ( string _name_user, unsigned int _password, unsigned int _id_user ); // �������� ������������ � ����������
		bool set_Registration ( void ); // ����� ( �������� ������� ) ��� ����� ��������������� ������
		void get_Show ( bool a ); // ���� ��� �����
};
class Users : public User_registration // ������������������ ������������
{
	public:
		unsigned int _Password_user = 0; // ��� �������� ������ ����������� ����� ����������� ������������
		unsigned int _Password = 0; // ��� �������� ������ ������������������� ������������
		unsigned int _ID = 0; // ID ������������ 
		bool _Set_user = 0; // ����� �������� ��������� ���� ��� ������ 
		string _Name_user = ""; // ��� �������� ����� ����������� ����� ����������� ������������
		string _Message = ""; // ��������� ��� �������� ������������
		string _User = ""; // ��� �������� ����� ������������������� ������������   
	public:
		Users ( );
		~Users ( );
		Users ( string name_user, unsigned int password_user, unsigned int id ); // ������������������� �����������
		bool set_Entrance ( void ); // ����� ��� ����� � �������� ������������ ����� ������ ��� �����
		bool set_Show1 ( bool a ); // ����� ��� ������ ���������� � ��� ����� ������������ ��� ���
		string set_Sending_message ( bool a ); // ����� ��� �������� ���������
};
class Message : public Users // �������� ��������� 
{
	public:
		unsigned int _id_user = 0; // ���� ��� ��������� ID ������������ ( ���������������� )
		string _Message = ""; // ���� ��� ��������� ��������� ( ���������������� )
		bool _select_user = 0; // ���� ��� ������ �������� ������ ������������ ��� ���� ( ���������������� ) 
	public:
		Message ( ); // ����������� �� ���������
		~Message ( ); // ����������
		Message ( unsigned int id_user, bool selected_user, string massage ); // ����������� � ���������� 
		void get_Message_user ( void ); // ����� ��� ��������� ��������� ������������ 
};
#endif /* _MY_CLASS_H_ */