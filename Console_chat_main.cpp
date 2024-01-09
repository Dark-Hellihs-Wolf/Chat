#include <iostream>
#include <locale>
#include "My_class.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////
void decor ( int a, char simbol ); // �������� ������� ��� �������� ������������ ���������� 
int main(void)
{
	setlocale(LC_ALL, "RU");
	string text , name;
	static bool flag = 0, flag_2 = 0, flag_3 = 0;
	unsigned int users = 0;								// ��������������� ����������
	unsigned int  select = 0;
	static unsigned int id = 0;
	unsigned int receiving_message = 0;
	unsigned int select_users = 0;
	char exit = ' ', exit_2 = ' ', exit_3 = ' ';
	decor(60, '-');
	cout << "���������� ��� �� 3-� ������������!" << endl;
	decor(60, '-');
	decor(60, '=');
	cout << "����������� �������������" << endl;
	decor(60, '=');
	// ��� ����������� ������ ������������ 
	User_registration a("", 0, 0);
	User_registration b("", 0, 0);
	User_registration c("", 0, 0);
	try // ����� ����������
	{
		cout << "����������� 1 " << endl;
		flag = a.set_Registration(); // ����������� ������ ������������ 
		a.get_Show(flag); // 
		decor(60, '-');

		cout << "������������ 2 " << endl;
		flag_2 = b.set_Registration(); // ����������� ������� ������������ 
		b.get_Show(flag_2);
		decor(60, '-');
		cout << "������������ 3 " << endl;
		flag_3 = c.set_Registration(); // ����������� �������� ������������ 
		c.get_Show(flag_3);
		decor(60, '=');
		if (( a._ID_user == b._ID_user ) || ( b._ID_user == c._ID_user ) || ( a._ID_user == c._ID_user ) )
		{
			throw Bad_Length_1(); // ����� ����������
		}
	}
	catch ( Bad_Length_1 & b )
	{
		cout << b.what() << endl; // ����� ��������� �� ����������
		flag = 0;  // ����� ������
		flag_2 = 0;
		flag_3 = 0;
	}
	/////////////////////////////////////////////////////////////////
					// �������� ������ ������ Users
		if ( flag == 1 && flag_2 == 1 && flag_3 == 1 ) // �������� ������ ��� ����������� ����������
		{
			Users user_1(a._Name_user, a._Password_user, a._ID_user);
			Users user_2(b._Name_user, b._Password_user, b._ID_user); // �������� ������ ������
			Users user_3(c._Name_user, c._Password_user, c._ID_user);
			Message user1(0, 0, "");
			Message user2(0, 0, ""); // ������������� �������
			Message user3(0, 0, "");
			/////////////////////////////////////////////////////////////////	
			while (exit != 'q')
			{
				flag = 0;
				decor(60, '=');
				cout << "������� ��� ������������!:" << endl;
				cin >> name;
				cout << a._Name_user << endl;
				decor(60, '=');
				if (a._Name_user == name) // �������� ��������� ����� � ���������������
				{
					while (exit_2 != 'q')
					{
						flag = user_1.set_Entrance();	// ���� ������ ������������ ��� �����
						flag = user_1.set_Show1(flag);	// ������������� ����� 
						decor(60, '-');
						if (flag == 1) // �������� ����� ��� ����������� ���������� 
						{
							cout << "�������� ��������� ���� ������������� ��� ������! ��� ���� 1: ��� ������ 2: ��� ������ ������� ID ������������" << endl;
							cin >> select; // ����� ���� ��� ������ 
							decor(60, '=');
							if (select == 1) // �������� ���� ������������� 
							{
								decor(60, '=');
								cout << "�������� ��������� ���� �������������" << endl;
								decor(60, '=');
								cout << "���� ���������" << endl;
								decor(60, '-');
								text = user_1.set_Sending_message(flag); // ������ ���������
							}
							else if (select == 2) // �������� ������
							{
								decor(60, '=');
								cout << "�������� ������ ����������� ������� ID ������������" << endl;
								cin >> id; // ���� ���������������� ������ ������������
								decor(60, '=');
								cout << "���� ���������" << endl;
								decor(60, '-');
								text = user_1.set_Sending_message(flag); // ������ ���������
								flag_3 = 1;
							}
						}
						cout << "���������� ��� �����?: n/q" << endl;
						cin >> exit_2;
					}
				}
				if (b._Name_user == name) // �������� ��������� ����� � ���������������
				{
					while (exit_2 != 'q')
					{
						flag = user_2.set_Entrance();	// ���� ������ ������������ ��� �����
						flag = user_2.set_Show1(flag);	// ������������� ����� 
						if (flag == 1) // �������� ����� ��� ����������� ���������� 
						{
							decor(60, '=');
							cout << "�������� ��������� ���� ������������� ��� ������! ��� ���� 1: ��� ������ 2: ��� ������ ������� ID ������������" << endl;
							decor(60, '-');
							cin >> select; // ����� ���� ��� ������ 
							decor(60, '=');
							if (select == 1) // �������� ���� ������������� 
							{
								decor(60, '=');
								cout << "�������� ��������� ���� �������������" << endl;
								decor(60, '=');
								cout << "���� ���������" << endl;
								decor(60, '-');
								text = user_1.set_Sending_message(flag); // ������ ���������
							}
							else if (select == 2) // �������� ������
							{
								decor(60, '=');
								cout << "�������� ������ ����������� ������� ID ������������" << endl;
								cin >> id;
								decor(60, '=');
								cout << "���� ���������" << endl;
								decor(60, '-');
								text = user_2.set_Sending_message(flag); // ������ ���������
								flag_3 = 1;
							}
							cout << "���������� ��� �����?: n/q" << endl;
							cin >> exit_2;
						}
					}
				}
				if (c._Name_user == name) // �������� ��������� ����� � ���������������
				{
					while (exit_2 != 'q')
					{
						flag = user_3.set_Entrance();	// ���� ������ ������������ ��� �����
						flag = user_3.set_Show1(flag);	// ������������� ����� 
						if (flag == 1) // �������� ����� ��� ����������� ���������� 
						{
							cout << "�������� ��������� ���� ������������� ��� ������! ��� ���� 1: ��� ������ 2: ��� ������ ������� ID ������������" << endl;
							cin >> select; // ����� ���� ��� ������ 
							decor(60, '=');
							if (select == 1) // �������� ���� ������������� 
							{
								decor(60, '=');
								cout << "�������� ��������� ���� �������������" << endl;
								decor(60, '=');
								cout << "���� ���������" << endl;
								decor(60, '=');
								text = user_3.set_Sending_message(flag); // ������ ���������
							}
							else if (select == 2) // �������� ������
							{
								decor(60, '=');
								cout << "�������� ������ ����������� ������� ID ������������" << endl;
								cin >> id;
								decor(60, '=');
								cout << "���� ���������" << endl;
								decor(60, '=');
								text = user_3.set_Sending_message(flag); // ������ ���������
								flag_3 = 1;
							}
						}
						cout << "���������� ��� �����?: n/q" << endl;
						cin >> exit_2;
					}
				}
				cout << a._ID_user << b._ID_user << c._ID_user << id<<  endl;
				if ((a._ID_user == id) || (b._ID_user == id) || (c._ID_user == id)) // �������� ������� id ��� �������� ��������� � ���������������
				{
					flag_2 = 1;
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////
				if (flag_2 == 1) // �������� ����� ��� ����������� ���������� 
				{
					while (exit_3 != 'q')
					{
						decor(80, '=');
						cout << "������ ������������: 1 / ������ ��������� ��� ���� �������������: 2 " << endl;
						decor(80, '-');
						cin >> select; // �����
						switch ( select )
						{
							cout << a._ID_user << b._ID_user << c._ID_user << id << endl;
							case 1:
								if (a._ID_user == id) // �������� ��������� ����� � ���������������
								{
									cout << "����������� 1 - ID " << a._ID_user << endl;
									flag = user_1.set_Entrance();	// ���� ������ ������������ ��� �����
									flag = user_1.set_Show1(flag);	// ������������� ����� 
									Message user1(user_1._ID, user_1._Set_user, text); // �������� ������
									if (flag == 1) // �������� ����� ����� �� ��������� ������ ��������� ��� ������������ ����� ������ �����
									{
										user1.get_Message_user(); // ������ ���������
										cout << endl;
									}
									else
									{
										cout << "��������� �������!" << endl;
									}

								}
								if (b._ID_user == id) // �������� ��������� ����� � ���������������
								{
									cout << "����������� 2 - ID " << b._ID_user << endl;
									flag = user_2.set_Entrance();	// ���� ������ ������������ ��� �����
									flag = user_2.set_Show1(flag);	// ������������� ����� 
									Message user2(user_2._ID, user_2._Set_user, text); // �������� ������
									if (flag == 1) // �������� ����� ����� �� ��������� ������ ��������� ��� ������������ ����� ������ �����
									{
										user2.get_Message_user(); // ������ ���������
										cout << endl;
									}
									else
									{
										cout << "��������� �������!" << endl;
									}
								}
								if (c._ID_user == id) // �������� ��������� ����� � ���������������
								{
									cout << "����������� 3 - ID " << c._ID_user << endl;
									flag = user_3.set_Entrance();	// ���� ������ ������������ ��� �����
									flag = user_3.set_Show1(flag);	// ������������� ����� 
									Message user3(user_3._ID, user_3._Set_user, text); // �������� ������
									if (flag == 1) // �������� ����� ����� �� ��������� ������ ��������� ��� ������������ ����� ������ �����
									{
										user3.get_Message_user(); // ������ ���������
										cout << endl;
									}
									else
									{
									cout << "��������� �������!" << endl;
									}	
								}
								cout << "��������� ����� �� ������ ������ ���������! q/n" << endl;
								cin >> exit_3;

							break;
							case 2:
								cout << "����������� 1 - ID " << a._ID_user << endl;
								flag = user_1.set_Entrance();	// ���� ������ ������������ ��� �����
								flag = user_1.set_Show1(flag);	// ������������� ����� 
								Message user1(user_1._ID, user_1._Set_user, text); // �������� ������
								if (flag == 1)
								{
									user1.get_Message_user(); // ������ ���������
									cout << endl;
								}
								else
								{
									cout << "��������� �������!" << endl;
								}
								cout << "����������� 2 - ID " << b._ID_user << endl;
								flag = user_2.set_Entrance();	// ���� ������ ������������ ��� �����
								flag = user_2.set_Show1(flag);	// ������������� ����� 
								Message user2(user_2._ID, user_2._Set_user, text); // �������� ������
								if (flag == 1)
								{
									user2.get_Message_user(); // ������ ���������
									cout << endl;
								}
								else
								{
									cout << "��������� �������!" << endl;
								}
								flag = user_3.set_Entrance();	// ���� ������ ������������ ��� �����
								flag = user_3.set_Show1(flag);	// ������������� ����� 
								Message user3(user_3._ID, user_3._Set_user, text); // �������� ������
								if (flag == 1)
								{
									user3.get_Message_user(); // ������ ���������
									cout << endl;
								}
								cout << "��������� ����� �� ������ ������ ���������! q/n" << endl;
								cin >> exit_3;
							break;
							
							cout << "��������� ����� �� ������ ������ ���������! q/n" << endl;
							cin >> exit_3;
						}
						flag_2 = 0;
					}
				}
				cout << "����� �� ���������?: n/q" << endl;
				cin >> exit;
			}		
		}											
		else
		{
			cout << " ���������� ������ ������������������!";
		}
	return 0;
}
void decor ( int a, char simbol ) // ���������� ������� decor
{
	for (int i = 0; i < a; i++)
	{
		cout << simbol;
	
	}
	cout << endl;
}