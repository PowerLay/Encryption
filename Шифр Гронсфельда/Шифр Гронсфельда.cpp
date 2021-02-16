// Шифр Гронсфельда

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

class Crypto
{
public:

	Crypto()
	{
		fillAlphabet();
	}


	//Функция шифрования
	string Encode(string Text, string Key)
	{
		string result;
		int index = 0;
		for (size_t i = 0; i < Text.length(); i++)
		{
			index = Keycode(Text[i]) + Key[i % Key.length()] - '0';
			result += alphabet[index % lenAlphabet];
		}
		return result;
	}

	//Функция дешифрирования
	string Decode(string Text, string Key)
	{
		string result;
		int index = 0;
		for (size_t i = 0; i < Text.length(); i++)
		{
			index = Keycode(Text[i]) - (Key[i % Key.size()] - '0');
			result += alphabet[(index + lenAlphabet) % lenAlphabet];
		}
		return result;
	}

private:
	static const int lenAlphabet = 256;
	string alphabet;

	//Функция получения кода символа
	int Keycode(char s)
	{
		for (int i = 0; i < alphabet.length(); i++)
			if (s == alphabet[i])
				return i;
		return 0;
	}
	//Функция заполнения словаря
	void fillAlphabet()
	{
		alphabet = "";
		for (size_t i = 0; i < lenAlphabet; i++)
		{
			alphabet += (char)i;
		}
	}
};

void inputConsole(string& inputStr, string& key)
{
	cout << "Введите текст> ";
	cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
	getline(cin, inputStr, '\n');

	cout << "Введите ключ> ";
	cin >> key;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string inputStr, key, res, decryptRes;
	Crypto crypto;
	int input;

	while (true)
	{
		cout << "(0)Выход\n";
		cout << "(1)Зашифровать\n";
		cout << "(2)Расшифровать\n";
		cout << "> ";
		cin >> input;
		switch (input)
		{
		case 1://Шифрование
			inputConsole(inputStr, key);

			res = crypto.Encode(inputStr, key);
			cout << "Зашифрованный текст: \"" << res << "\"" << endl;
			break;
		case 2://Дешифрование
			cout << "(0)Выход\n";
			cout << "(1)Дешифровать из новой строки\n";
			cout << "(2)Дешифровать из зашифрованной строки\n";
			cout << "> ";
			cin >> input;
			if (input == 0)
				continue;//Выход из меню дешифрирования
			if (input == 1)
			{
				inputConsole(inputStr, key);

				decryptRes = crypto.Decode(inputStr, key);
			}
			else//Дешифровка с использованием зашифрованной строки.
			{
				decryptRes = crypto.Decode(res, key);
			}
			cout << "Дешифрованный текст: \"" << decryptRes << "\"" << endl;
			break;
		case 0: //Выход из программы
			exit(0);
			break;
		default:
			break;
		}
	}
}