#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;


struct infofbooks
{
	string udk;
	string pa;
	string name;
	int year;
	int num;

};

int getValueyear(infofbooks& x)
{
	while (true) // цикл працює, поки користувач не введе правильне (числове) значення
	{
		cout << "Введіть рік видання: " << endl;
		cin >> x.year;

		if (cin.fail()) // якщо введене значення неправильне
		{
			cin.clear(); // то повертаємо cin в звичайний режим (чистимо) роботи
			cin.ignore(32767, '\n'); // і видаляємо значення попереднього значення із вхідного буферу
		}
		else // якщо все правильно, по повертаємо значення
			return x.year;
	}
}

int getValuenum(infofbooks& x)
{
	while (true) // цикл працює, поки користувач не введе правильне (числове) значення
	{
		cout << "Введіть кількість примірників книги в бібліотеці" << endl;
		cin >> x.num;

		if (cin.fail()) // якщо введене значення неправильне
		{
			cin.clear(); // то повертаємо cin в звичайний режим (чистимо) роботи
			cin.ignore(32767, '\n'); // і видаляємо значення попереднього значення із вхідного буферу
		}
		else // якщо все правильно, по повертаємо значення
			return x.num;
	}
}

void fillb(infofbooks& x)  // заповлення структури
{
	cin.ignore();
	cout << "Введіть номер УДК: " << endl;
	getline(cin, x.udk);
	cout << "Введіть прізвище автора: " << endl;
	getline(cin, x.pa);
	cout << "Введіть назву книги: " << endl;
	getline(cin, x.name);
	getValueyear(x);
	getValuenum(x);
}

void outb(list <infofbooks> ::iterator iter,list <infofbooks> list) // вивід вмісту вектора на екран
{
	for (iter = list.begin(); iter != list.end(); iter++)
	{
		cout << iter->udk << '\t' << '\t';
		cout << iter->pa << '\t' << '\t';
		cout << iter->name << '\t' << '\t';
		cout << iter->year << '\t' << '\t';
		cout << iter->num << '\t' << '\t';
		cout << endl;
	}

	if (list.empty())
	{
		cout << "Книг у бібліотечному фонді немає" << endl;
	}

}

void menu()  // меню програми
{
	cout << " Що ви хочете зробити" << endl;
	cout << " 1. Додати дані про книги, що надходять у бібліотеку" << endl;
	cout << " 2. Видалити дані про книги, що списуються (по коду УДК);" << endl;
	cout << " 3. Вивести дані про бібліотечний фонд (всі наявні книги)" << endl;
	cout << " 4. Вивести дані про книги по року видання" << endl;
	cout << " 5. Вихід" << endl;
	cout << ">";
}

void addbook(infofbooks& x, list <infofbooks> &list, bool b, char c) // процедура для додавання книг
{
	fillb(x);  // заповнюємо структуру
	list.push_back(x);  // додаємо заповнену структуру у вектор
	cout << "Якщо хочете додати книгу, натисніть +, якщо хочете повернутися до головного меню натисніть - " << endl;
	cin >> c;


	while (b == true)  // цикл для того, щоб вводити ще книги, якщо того хоче користувач
	{
		if (c == '+')
		{
			fillb(x);
			list.push_back(x);
			cout << "Якщо хочете додати книгу, натисніть +, якщо хочете повернутися до головного меню натисніть - " << endl;
			cin >> c;  // знову запитуємо чого хоче користувач
			continue;
		}

		if (c == '-')
		{
			break;
		}
	}
}

void deletebook(string f, list <infofbooks> ::iterator iter, list <infofbooks>& list, bool b, char c)  // процедура для видалення книг по УДК
{
	cout << "Введіть номер УДК книги, яку потрібно списати: " << endl;
	cin.ignore();
	getline(cin, f);

	for (iter = list.begin(); iter != list.end(); iter++)
	{
		if (iter->udk == f)
		{
			list.erase(iter); // якщо знаходимо таке УДК,  то видаляємо всі дані про книгу
			break;
		}
	}

		cout << "Якщо хочете списати книгу, натисніть +, якщо хочете повернутися до головного меню натисніть - " << endl;
		b = true;
		cin >> c;

		while (b == true)
		{
			if (c == '+')
			{
				cout << "Введіть номер УДК книги, яку потрібно списати: " << endl;
				cin.ignore();
				getline(cin, f);

				for (iter = list.begin(); iter != list.end(); iter++)
				{
					if (iter->udk == f)
					{
						list.erase(iter); // якщо знаходимо таке УДК,  то видаляємо всі дані про книгу
						break;
					}
				}
				cout << "Якщо хочете списати книгу, натисніть +, якщо хочете повернутися до головного меню натисніть - " << endl;
				cin >> c;
				continue;
			}

			if (c == '-')
			{
				break;
			}
		}
}

void outbookyear(int y, list <infofbooks> ::iterator iter, list <infofbooks>& list, int a)   // процедура для виводу книг за певним роком видачі
{
	cout << " Введіть рік видачі книг, які вас цікавлять" << endl;
	cin >> y;


	for (iter = list.begin(); iter != list.end(); iter++)
	{
		if (iter->year == y)
		{
			a++;
			cout << iter->udk << '\t';
			cout << iter->pa << '\t' ;
			cout << iter->name << '\t';
			cout << iter->year << '\t' ;
			cout << iter->num << '\t';
			cout << endl;
		}
	}


	if (a == 0)
	{
		cout << "Книги такого року видачі відсутні у бібліотечному фонді";
		cout << endl;
	}
}




int main()
{
	system("chcp 1251");

	infofbooks object;
	list <infofbooks> books;
	list <infofbooks> ::iterator it;

	int write;  // змінна для оператора switch
	bool run = true;
	string find;
	int a = 0, y = 0;
	char ch = ' ';


	do // заносимо switch в do&while для того, щоб програма проводилася не один раз, а скільки, скільки потрібно користувачу
	{
		menu();
		cin >> write;

		switch (write)
		{
		case 1:
			addbook(object, books, run, ch);
			break;
		case 2:
			deletebook(find,it, books, run, ch);
			break;
		case 3:
			outb(it, books);
			break;
		case 4:
			outbookyear(y, it, books, a);
			break;
		case 5:
			break;
		}

	} while (write != 5);

}



