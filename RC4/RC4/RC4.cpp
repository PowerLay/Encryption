// RC4
#include <iostream>
#include <string>

using namespace std;

class Crypto
{
public:
	Crypto()
	{}
	Crypto(string key)
	{
		int len = key.size();
		for (size_t i = 0; i < lenArr; i++)
		{
			S[i] = i;
		}
		int j = 0;
		for (size_t i = 0; i < lenArr; i++)
		{
			j = (j + S[i] + key[i % len]) % lenArr;
			swap(S[i], S[j]); //меняем местами элементы
		}
	}
	~Crypto()
	{	}

	//функция расшифровки. Так как RC4 симметрично используем ту же функцию что и при шифровании.
	string decode(string input, int size)
	{
		return  encode(input, size);
	}

	//Функция шифрования
	string encode(string input, int size)
	{
		string cipher = input;
		size_t i;
		for (i = 0; i < size; i++)
		{
			cipher[i] = (input[i] ^ getKeyItem());
		}
		return cipher;
	}

private:
	static const int lenArr = 256;
	int S[lenArr];
	int x = 0;
	int y = 0;
	//Псевдослучайное число
	int getKeyItem() {
		x = (x + 1) % lenArr;
		y = (y + S[x]) % lenArr;

		swap(S[x], S[y]); //меняем местами элементы
		return S[(S[x] + S[y]) % lenArr];
	}

};

int main()
{
	string inputStr, key, res, decryptRes;
	Crypto crypto, decrypt;
	int input;

	while (true)
	{
		cout << "(0)Exit\n";
		cout << "(1)Encode\n";
		cout << "(2)Decode\n";
		cout << "> ";
		cin >> input;
		switch (input)
		{
		case 1://Шифрование
			cout << "Enter string> ";
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
			getline(cin, inputStr, '\n');

			cout << "Enter key> ";
			cin >> key;

			crypto = Crypto(key);
			res = crypto.encode(inputStr, inputStr.size());
			cout << "Encode string: \"" << res << "\"" << endl;
			break;
		case 2://Дешифрование
			cout << "(0)Exit\n";
			cout << "(1)Input new string\n";
			cout << "(2)Use old string\n";
			cout << "> ";
			cin >> input;
			if (input == 0)
				continue;//Выход из меню дешифрования
			if (input == 1)
			{
				cout << "Enter string> ";
				cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
				getline(cin, inputStr);

				cout << "Enter key> ";
				cin >> key;
				decrypt = Crypto(key);

				decryptRes = decrypt.decode(inputStr, inputStr.size());
			}
			else//Дешифровка с использованием предыдущих значений.
			{
				decrypt = Crypto(key);
				decryptRes = decrypt.decode(res, res.size());
			}
			cout << "Decode string: \"" << decryptRes << "\"" << endl;
			break;
		case 0: //Выход из прогрмамы
			exit(0);
			break;
		default:
			break;
		}
	}

}
