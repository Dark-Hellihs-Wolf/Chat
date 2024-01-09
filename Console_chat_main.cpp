#include <iostream>
#include <locale>
#include "My_class.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////
void decor ( int a, char simbol ); // Прототип функции для простого графического оформления 
int main(void)
{
	setlocale(LC_ALL, "RU");
	string text , name;
	static bool flag = 0, flag_2 = 0, flag_3 = 0;
	unsigned int users = 0;								// Вспомогательные переменные
	unsigned int  select = 0;
	static unsigned int id = 0;
	unsigned int receiving_message = 0;
	unsigned int select_users = 0;
	char exit = ' ', exit_2 = ' ', exit_3 = ' ';
	decor(60, '-');
	cout << "Консольный чат на 3-и пользователя!" << endl;
	decor(60, '-');
	decor(60, '=');
	cout << "Регестрация пользователей" << endl;
	decor(60, '=');
	// Для регестрации одного пользователя 
	User_registration a("", 0, 0);
	User_registration b("", 0, 0);
	User_registration c("", 0, 0);
	try // Поиск исключение
	{
		cout << "Пользовтель 1 " << endl;
		flag = a.set_Registration(); // Регестрация одного пользователя 
		a.get_Show(flag); // 
		decor(60, '-');

		cout << "Пользователь 2 " << endl;
		flag_2 = b.set_Registration(); // Регестрация второго пользователя 
		b.get_Show(flag_2);
		decor(60, '-');
		cout << "Пользователь 3 " << endl;
		flag_3 = c.set_Registration(); // Регестрация третьего пользователя 
		c.get_Show(flag_3);
		decor(60, '=');
		if (( a._ID_user == b._ID_user ) || ( b._ID_user == c._ID_user ) || ( a._ID_user == c._ID_user ) )
		{
			throw Bad_Length_1(); // Вызов исключение
		}
	}
	catch ( Bad_Length_1 & b )
	{
		cout << b.what() << endl; // Вывод сообщение об исключения
		flag = 0;  // Сброс флагов
		flag_2 = 0;
		flag_3 = 0;
	}
	/////////////////////////////////////////////////////////////////
					// Передача данных Классу Users
		if ( flag == 1 && flag_2 == 1 && flag_3 == 1 ) // Проверка флагов для дальнейшего выполнения
		{
			Users user_1(a._Name_user, a._Password_user, a._ID_user);
			Users user_2(b._Name_user, b._Password_user, b._ID_user); // Передача данных классу
			Users user_3(c._Name_user, c._Password_user, c._ID_user);
			Message user1(0, 0, "");
			Message user2(0, 0, ""); // Инициализация классов
			Message user3(0, 0, "");
			/////////////////////////////////////////////////////////////////	
			while (exit != 'q')
			{
				flag = 0;
				decor(60, '=');
				cout << "Введите имя пользователя!:" << endl;
				cin >> name;
				cout << a._Name_user << endl;
				decor(60, '=');
				if (a._Name_user == name) // Проверка введённого имени с регистрационным
				{
					while (exit_2 != 'q')
					{
						flag = user_1.set_Entrance();	// Ввод данных пользователя для входа
						flag = user_1.set_Show1(flag);	// Подтверждение входа 
						decor(60, '-');
						if (flag == 1) // Проверка флага для дальнейшего выполнения 
						{
							cout << "Отправка сообщение всем пользователям или одному! Для всех 1: для одного 2: для одного введите ID пользователя" << endl;
							cin >> select; // Выбор всем или одному 
							decor(60, '=');
							if (select == 1) // Отправка всем пользователям 
							{
								decor(60, '=');
								cout << "Отправка сообщение всем пользователям" << endl;
								decor(60, '=');
								cout << "Ввод сообщение" << endl;
								decor(60, '-');
								text = user_1.set_Sending_message(flag); // Запись сообщение
							}
							else if (select == 2) // Отправка одному
							{
								decor(60, '=');
								cout << "Отправка одному польователю введите ID пользователя" << endl;
								cin >> id; // Ввод индификационного номера пользователя
								decor(60, '=');
								cout << "Ввод сообщение" << endl;
								decor(60, '-');
								text = user_1.set_Sending_message(flag); // Запись сообщение
								flag_3 = 1;
							}
						}
						cout << "Продолжить или выйти?: n/q" << endl;
						cin >> exit_2;
					}
				}
				if (b._Name_user == name) // Проверка введённого имени с регистрационным
				{
					while (exit_2 != 'q')
					{
						flag = user_2.set_Entrance();	// Ввод данных пользователя для входа
						flag = user_2.set_Show1(flag);	// Подтверждение входа 
						if (flag == 1) // Проверка флага для дальнейшего выполнения 
						{
							decor(60, '=');
							cout << "Отправка сообщение всем пользователям или одному! Для всех 1: для одного 2: для одного введите ID пользователя" << endl;
							decor(60, '-');
							cin >> select; // Выбор всем или одному 
							decor(60, '=');
							if (select == 1) // Отправка всем пользователям 
							{
								decor(60, '=');
								cout << "Отправка сообщение всем пользователям" << endl;
								decor(60, '=');
								cout << "Ввод сообщение" << endl;
								decor(60, '-');
								text = user_1.set_Sending_message(flag); // Запись сообщение
							}
							else if (select == 2) // Отправка одному
							{
								decor(60, '=');
								cout << "Отправка одному польователю введите ID пользователя" << endl;
								cin >> id;
								decor(60, '=');
								cout << "Ввод сообщение" << endl;
								decor(60, '-');
								text = user_2.set_Sending_message(flag); // Запись сообщение
								flag_3 = 1;
							}
							cout << "Продолжить или выйти?: n/q" << endl;
							cin >> exit_2;
						}
					}
				}
				if (c._Name_user == name) // Проверка введённого имени с регистрационным
				{
					while (exit_2 != 'q')
					{
						flag = user_3.set_Entrance();	// Ввод данных пользователя для входа
						flag = user_3.set_Show1(flag);	// Подтверждение входа 
						if (flag == 1) // Проверка флага для дальнейшего выполнения 
						{
							cout << "Отправка сообщение всем пользователям или одному! Для всех 1: для одного 2: для одного введите ID пользователя" << endl;
							cin >> select; // Выбор всем или одному 
							decor(60, '=');
							if (select == 1) // Отправка всем пользователям 
							{
								decor(60, '=');
								cout << "Отправка сообщение всем пользователям" << endl;
								decor(60, '=');
								cout << "Ввод сообщение" << endl;
								decor(60, '=');
								text = user_3.set_Sending_message(flag); // Запись сообщение
							}
							else if (select == 2) // Отправка одному
							{
								decor(60, '=');
								cout << "Отправка одному польователю введите ID пользователя" << endl;
								cin >> id;
								decor(60, '=');
								cout << "Ввод сообщение" << endl;
								decor(60, '=');
								text = user_3.set_Sending_message(flag); // Запись сообщение
								flag_3 = 1;
							}
						}
						cout << "Продолжить или выйти?: n/q" << endl;
						cin >> exit_2;
					}
				}
				cout << a._ID_user << b._ID_user << c._ID_user << id<<  endl;
				if ((a._ID_user == id) || (b._ID_user == id) || (c._ID_user == id)) // Проверка ввдённое id при отправке сообщения с регестрационным
				{
					flag_2 = 1;
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////
				if (flag_2 == 1) // Проверка флага для дальнейшего выполнения 
				{
					while (exit_3 != 'q')
					{
						decor(80, '=');
						cout << "Одного пользователя: 1 / Чтение сообщение для всех пользователей: 2 " << endl;
						decor(80, '-');
						cin >> select; // Выбор
						switch ( select )
						{
							cout << a._ID_user << b._ID_user << c._ID_user << id << endl;
							case 1:
								if (a._ID_user == id) // Проверка введённого имени с регистрационным
								{
									cout << "Пользовтель 1 - ID " << a._ID_user << endl;
									flag = user_1.set_Entrance();	// Ввод данных пользователя для входа
									flag = user_1.set_Show1(flag);	// Подтверждение входа 
									Message user1(user_1._ID, user_1._Set_user, text); // Передача данных
									if (flag == 1) // Проверка флага нужно во избежание вывода сообщение при неправильном вводе данных входа
									{
										user1.get_Message_user(); // Чтение сообщение
										cout << endl;
									}
									else
									{
										cout << "Повторите попытку!" << endl;
									}

								}
								if (b._ID_user == id) // Проверка введённого имени с регистрационным
								{
									cout << "Пользовтель 2 - ID " << b._ID_user << endl;
									flag = user_2.set_Entrance();	// Ввод данных пользователя для входа
									flag = user_2.set_Show1(flag);	// Подтверждение входа 
									Message user2(user_2._ID, user_2._Set_user, text); // Передача данных
									if (flag == 1) // Проверка флага нужно во избежание вывода сообщение при неправильном вводе данных входа
									{
										user2.get_Message_user(); // Чтение сообщение
										cout << endl;
									}
									else
									{
										cout << "Повторите попытку!" << endl;
									}
								}
								if (c._ID_user == id) // Проверка введённого имени с регистрационным
								{
									cout << "Пользовтель 3 - ID " << c._ID_user << endl;
									flag = user_3.set_Entrance();	// Ввод данных пользователя для входа
									flag = user_3.set_Show1(flag);	// Подтверждение входа 
									Message user3(user_3._ID, user_3._Set_user, text); // Передача данных
									if (flag == 1) // Проверка флага нужно во избежание вывода сообщение при неправильном вводе данных входа
									{
										user3.get_Message_user(); // Чтение сообщение
										cout << endl;
									}
									else
									{
									cout << "Повторите попытку!" << endl;
									}	
								}
								cout << "Выполнить выход из пункта чтение сообщение! q/n" << endl;
								cin >> exit_3;

							break;
							case 2:
								cout << "Пользовтель 1 - ID " << a._ID_user << endl;
								flag = user_1.set_Entrance();	// Ввод данных пользователя для входа
								flag = user_1.set_Show1(flag);	// Подтверждение входа 
								Message user1(user_1._ID, user_1._Set_user, text); // Передача данных
								if (flag == 1)
								{
									user1.get_Message_user(); // Чтение сообщение
									cout << endl;
								}
								else
								{
									cout << "Повторите попытку!" << endl;
								}
								cout << "Пользовтель 2 - ID " << b._ID_user << endl;
								flag = user_2.set_Entrance();	// Ввод данных пользователя для входа
								flag = user_2.set_Show1(flag);	// Подтверждение входа 
								Message user2(user_2._ID, user_2._Set_user, text); // Передача данных
								if (flag == 1)
								{
									user2.get_Message_user(); // Чтение сообщение
									cout << endl;
								}
								else
								{
									cout << "Повторите попытку!" << endl;
								}
								flag = user_3.set_Entrance();	// Ввод данных пользователя для входа
								flag = user_3.set_Show1(flag);	// Подтверждение входа 
								Message user3(user_3._ID, user_3._Set_user, text); // Передача данных
								if (flag == 1)
								{
									user3.get_Message_user(); // Чтение сообщение
									cout << endl;
								}
								cout << "Выполнить выход из пункта чтение сообщение! q/n" << endl;
								cin >> exit_3;
							break;
							
							cout << "Выполнить выход из пункта чтение сообщение! q/n" << endl;
							cin >> exit_3;
						}
						flag_2 = 0;
					}
				}
				cout << "Выйти из программы?: n/q" << endl;
				cin >> exit;
			}		
		}											
		else
		{
			cout << " Необходимо заново перегестрироваться!";
		}
	return 0;
}
void decor ( int a, char simbol ) // Объявление функции decor
{
	for (int i = 0; i < a; i++)
	{
		cout << simbol;
	
	}
	cout << endl;
}