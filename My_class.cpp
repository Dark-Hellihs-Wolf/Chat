#include "My_class.h"
/////////////////////////////////////����������� ������������///////////////////////////////////////////////
User_registration :: User_registration ( )
{}
User_registration :: User_registration ( string _name_user, unsigned int _password, unsigned int _id_user ) : _Name_user ( _name_user ), _Password_user ( _password ), _ID_user ( _id_user )
{}
User_registration :: ~User_registration ( )
{}
bool User_registration :: set_Registration ( void ) // ���� ��������������� ������ ������������
{
	cout << "���� ����� "; cin >> _Name_user; 
	try
	{
		cout << "���� ������ "; cin >> _Password_user;
		if ( _Password_user >= 0x0001 && _Password_user <= 0xFFFF )
		{
			cout << "���� ID "; cin >> _ID_user;
			if ( _ID_user >= 0x0001 && _ID_user <= 0xFFFF )
			{
				
				return 1;
			}
			else
			{
				cout << "������ ����� ��� ID ����������� 65535! " << endl;
				throw	Bad_Length_0();
				return 0;
			}	
		}
		else
		{
			cout << "������ ����� ��� ������ ����������� 65535! " << endl;
			throw	Bad_Length_0();
			return 0;
		}
	}
	catch ( Bad_Length_0 & a )
	{
		cout << a.what() << endl;
	}
}
void User_registration :: get_Show ( bool a ) // ����� ������ ������������
{
	if (a == 1)
	{
		cout << "����������� ������������ �������! " << endl;
	}
	else
	{
		cout << "����������� ������ �� �������!" << endl;
	}
}
//////////////////////////////////////������ � �������������///////////////////////////////////////////////
Users :: Users ()
{}
Users :: Users ( string user_name, unsigned int password_user, unsigned int id ) : _Name_user ( user_name ), _Password_user ( password_user ), _ID ( id )
{}
Users :: ~Users ()
{}
bool Users :: set_Entrance ( void ) // ���� ������������ 
{
	cout << "��� ����� ������� ��� � ������ " << endl;
	cout << "������� ��� "; cin >> _User;
	cout << "������� ������ "; cin >> _Password;
	if ( _User == _Name_user && _Password == _Password_user ) // �������� ������������ ����� ������ � ��� ������������
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool Users :: set_Show1 ( bool a ) // ������������� ����� ������������ 
{
	if (a == 1)
	{
		cout << " ����� " << endl;
		return 1;
	}
	else
	{
		cout << " ������� "  << endl;
		return 0;
	}
}
string Users :: set_Sending_message ( bool a ) // ����� ��� �������� ��������� 
{
	if ( a == 1 ) // ���� ������ �� ���������� ���������� ��������� 
	{
		cout << "������� ��������� ��� ��������: "; cin >> _Message; // ���� ��������� 
	}
	return _Message;
}
////////////////////////////////////����� ��������� ������������////////////////////////////////////
Message :: Message () // ����������� �� ���������
{}
Message :: Message ( unsigned int id_user, bool selected_user, string message ) : _id_user ( id_user ), _select_user ( selected_user ), _Message ( message ) // ��������� ����������� �������������
{}
Message :: ~Message () // ����������
{}
 void Message :: get_Message_user ( void ) // ���� ���������
{
	 unsigned short id = 0; // ��������������� ���������� ��� �������� id 
		 if (_select_user == 1)
		 {
			 cout << "������� ID ������������ "; cin >> id;
			 if ( _id_user == id )
			 {
				 cout << "���������: " << _Message << endl;
				 cout << "��� ������������ � ID: " << id << endl;
			 }
			 else
			 {
				 cout << "�������� ID ������������!!! ";
			 }
		 }
		 else
		 {
			 cout << _Message;
		 }
}
