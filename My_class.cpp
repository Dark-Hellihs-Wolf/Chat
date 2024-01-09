#include "My_class.h"
/////////////////////////////////////Регестрация пользователя///////////////////////////////////////////////
User_registration :: User_registration ( )
{}
User_registration :: User_registration ( string _name_user, unsigned int _password, unsigned int _id_user ) : _Name_user ( _name_user ), _Password_user ( _password ), _ID_user ( _id_user )
{}
User_registration :: ~User_registration ( )
{}
bool User_registration :: set_Registration ( void ) // Ввод регистрационных данных пользователя
{
	cout << "Ввод имени "; cin >> _Name_user; 
	try
	{
		cout << "Ввод пароля "; cin >> _Password_user;
		if ( _Password_user >= 0x0001 && _Password_user <= 0xFFFF )
		{
			cout << "Ввод ID "; cin >> _ID_user;
			if ( _ID_user >= 0x0001 && _ID_user <= 0xFFFF )
			{
				
				return 1;
			}
			else
			{
				cout << "Ведено число для ID превышающее 65535! " << endl;
				throw	Bad_Length_0();
				return 0;
			}	
		}
		else
		{
			cout << "Ведено число для пароля превышающее 65535! " << endl;
			throw	Bad_Length_0();
			return 0;
		}
	}
	catch ( Bad_Length_0 & a )
	{
		cout << a.what() << endl;
	}
}
void User_registration :: get_Show ( bool a ) // Вывод данных пользователя
{
	if (a == 1)
	{
		cout << "Регестрация пользователя успешна! " << endl;
	}
	else
	{
		cout << "Регестрация прошла не успешна!" << endl;
	}
}
//////////////////////////////////////Работа с пользователем///////////////////////////////////////////////
Users :: Users ()
{}
Users :: Users ( string user_name, unsigned int password_user, unsigned int id ) : _Name_user ( user_name ), _Password_user ( password_user ), _ID ( id )
{}
Users :: ~Users ()
{}
bool Users :: set_Entrance ( void ) // Вход пользователя 
{
	cout << "Для входа введите имя и пароль " << endl;
	cout << "Введите имя "; cin >> _User;
	cout << "Введите пароль "; cin >> _Password;
	if ( _User == _Name_user && _Password == _Password_user ) // Проверка правильности ввода пароля и имя пользователя
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool Users :: set_Show1 ( bool a ) // Подтверждение входа пользователя 
{
	if (a == 1)
	{
		cout << " Вошли " << endl;
		return 1;
	}
	else
	{
		cout << " Неверно "  << endl;
		return 0;
	}
}
string Users :: set_Sending_message ( bool a ) // Метод для отправки сообщения 
{
	if ( a == 1 ) // Если истина то продолжаем выполнение программы 
	{
		cout << "Введите сообщение для отправки: "; cin >> _Message; // Ввод сообщения 
	}
	return _Message;
}
////////////////////////////////////Вывод сообщений пользователя////////////////////////////////////
Message :: Message () // Конструктор по умолчанию
{}
Message :: Message ( unsigned int id_user, bool selected_user, string message ) : _id_user ( id_user ), _select_user ( selected_user ), _Message ( message ) // Параметры принимаемым конструктором
{}
Message :: ~Message () // Деструктор
{}
 void Message :: get_Message_user ( void ) // Приём сообщения
{
	 unsigned short id = 0; // Вспомагательная переменная для проверки id 
		 if (_select_user == 1)
		 {
			 cout << "Введите ID Пользователя "; cin >> id;
			 if ( _id_user == id )
			 {
				 cout << "Сообщение: " << _Message << endl;
				 cout << "Для пользователя с ID: " << id << endl;
			 }
			 else
			 {
				 cout << "Неверный ID пользователя!!! ";
			 }
		 }
		 else
		 {
			 cout << _Message;
		 }
}
