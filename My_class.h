#ifndef _MY_CLASS_H_
#define _MY_CLASS_H_
#include <iostream>
#include <string>
#include "Bad_Length.h"
using namespace std; // Надо перепесать пространство имён!!!!!!!!!!!!!!!!
class User_registration // Регистрация пользователей 
{
	public:
		string _Name_user = " "; // Имя регестрируемого пользователя 
		unsigned int _Password_user = 0; // Пароль регестрируемого пользователя
		unsigned int _ID_user = 0; // Индификационный номер
		//unsigned short _Quantity; // Количество регестрируемых пользователей.?
	public:
		User_registration (); 
		~User_registration (); // Деструктор
		User_registration ( string _name_user, unsigned int _password, unsigned int _id_user ); // Создание конструктора с парметрами
		bool set_Registration ( void ); // Метод ( прототип функции ) для ввода регестрационных данных
		void get_Show ( bool a ); // Пока для теста
};
class Users : public User_registration // Зарегестрированные пользователь
{
	public:
		unsigned int _Password_user = 0; // Для хранения пароля полученного после регистрации пользователя
		unsigned int _Password = 0; // Для проверки пароля зарегестрированного пользователя
		unsigned int _ID = 0; // ID пользователя 
		bool _Set_user = 0; // Выбор отправки сообщение всем или одному 
		string _Name_user = ""; // Для хранения имени полученного после регистрации пользователя
		string _Message = ""; // Сообщение для отправки пользователю
		string _User = ""; // Для проверки имени зарегестрированного пользователя   
	public:
		Users ( );
		~Users ( );
		Users ( string name_user, unsigned int password_user, unsigned int id ); // Параметризированный конструктор
		bool set_Entrance ( void ); // Метод для входа и проверка правильности ввода данных для входа
		bool set_Show1 ( bool a ); // Метод для вывода информации о том вошёл пользователь или нет
		string set_Sending_message ( bool a ); // Метод для отправки сообщения
};
class Message : public Users // Принятия сообщения 
{
	public:
		unsigned int _id_user = 0; // Поле для получение ID пользователя ( инициализируется )
		string _Message = ""; // Поле для получение сообщение ( инициализируется )
		bool _select_user = 0; // Поле для выбора отправки одному пользователю или всем ( инициализируется ) 
	public:
		Message ( ); // Конструктор по умолчанию
		~Message ( ); // Деструктор
		Message ( unsigned int id_user, bool selected_user, string massage ); // Конструктор с праметрами 
		void get_Message_user ( void ); // Метод для получение сообщение пользователя 
};
#endif /* _MY_CLASS_H_ */