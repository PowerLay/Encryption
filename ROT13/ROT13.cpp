// ROT13

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Crypto
{
public:

	Crypto()
	{
		fillAlphabet();
	}


	//Функция шифрования
	string Encode(string Text)
	{
		string result;
		int index = 0;
		for (size_t i = 0; i < Text.length(); i++)
		{
			index = Keycode(Text[i], alphabet);
			if (index < 0)
				result += Text[i];
			else
			result += codeAlphabet[index % lenAlphabet];
		}
		return result;
	}

	//Функция дешифрирования
	string Decode(string Text)
	{
		string result;
		int index = 0;
		for (size_t i = 0; i < Text.length(); i++)
		{
			index = Keycode(Text[i], codeAlphabet);
			if (index < 0)
				result += Text[i];
			else
				result += alphabet[(index + lenAlphabet) % lenAlphabet];
		}
		return result;
	}

private:
	int lenAlphabet = 256;
	string alphabet, codeAlphabet;

	//Функция получения кода символа
	int Keycode(char s, string inputAlphabet)
	{
		for (int i = 0; i < inputAlphabet.length(); i++)
			if (s == inputAlphabet[i])
				return i;
		return -1;
	}

	//Функция заполнения словаря
	void fillAlphabet()
	{
		alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		codeAlphabet = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
		lenAlphabet = alphabet.length();
	}
};

void inputConsole(string& inputStr)
{
	cout << "Введите текст> ";
	cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
	getline(cin, inputStr, '\n');
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
			inputConsole(inputStr);

			res = crypto.Encode(inputStr);
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
				inputConsole(inputStr);

				decryptRes = crypto.Decode(inputStr);
			}
			else//Дешифровка с использованием зашифрованной строки.
			{
				decryptRes = crypto.Decode(res);
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