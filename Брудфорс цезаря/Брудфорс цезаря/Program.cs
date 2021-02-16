using System;

namespace Брудфорс_цезаря
{
    internal class Program
    {
        private const int startENA = 65;
        private const int startENa = 97;
        private const int lenEN = 26;
        private const int startRUA = 1040;
        private const int startRUa = 1072;
        private const int lenRU = 32;

        private class Cesar
        {
            private int offset;
            private string inputString;

            public Cesar(string inputString, int offset)
            {
                this.inputString = inputString;
                this.offset = offset;
            }

            private char testChar(char ch, bool decrypt = false)
            {
                int output = ch;


                if (output >= startENA && output < startENA + lenEN) //A..Z
                {
                    output = AddOffset(output, startENA, lenEN, decrypt);
                }
                if (output >= startENa && output < startENa + lenEN) //a..z
                {
                    output = AddOffset(output, startENa, lenEN, decrypt);
                }
                if (output >= startRUA && output < startRUA + lenRU) //А..Я
                {
                    output = AddOffset(output, startRUA, lenRU, decrypt);
                }
                if (output >= startRUa && output < startRUa + lenRU) //а..я
                {
                    output = AddOffset(output, startRUa, lenRU, decrypt);
                }
                return (char)output;
            }

            private int AddOffset(int output, int start, int len, bool decrypt)
            {
                if (decrypt)
                {
                    output -= offset;
                }
                else
                {
                    output += offset;
                }

                while (output < start || output >= start + len)
                {
                    if (output < start)
                        output += len;
                    if (output >= start + len)
                        output -= len;
                }

                return output;
            }

            public string Encrypt()
            {
                string outputString = "";
                for (int i = 0; i < inputString.Length; i++)
                {
                    outputString += testChar(inputString[i]);
                }
                inputString = outputString;
                return outputString;
            }

            public string Decrypt()
            {
                string outputString = "";
                for (int i = 0; i < inputString.Length; i++)
                {
                    outputString += testChar(inputString[i], true);
                }
                inputString = outputString;
                return outputString;
            }

        }

        private static void Main(string[] args)
        {
            Console.WriteLine("Программа для шифрования цезарем и расшифровки подбором смещения");

            Cesar csr;
            bool stay = true;

            while (stay)
            {
                Console.WriteLine("(1) - Шифрование цезарем;");
                Console.WriteLine("(2) - Дешифровка цезаря зная смещение;");
                Console.WriteLine("(3) - Дешифровка цезаря подбором смещения;");
                Console.WriteLine("(0) - Выход;");
                Console.Write("> ");

                int offset;
                string inputString;
                int.TryParse(Console.ReadLine(), out int input);

                switch (input)
                {
                    case 0:
                        stay = false;
                        break;
                    case 1:
                        Console.Write("Введите строку> ");
                        inputString = Console.ReadLine();

                        Console.Write("Введите смещение> ");
                        offset = int.Parse(Console.ReadLine());

                        csr = new Cesar(inputString, offset);
                        Console.WriteLine("Закодированная строка: " + csr.Encrypt());
                        break;
                    case 2:
                        Console.Write("Введите строку> ");
                        inputString = Console.ReadLine();

                        Console.Write("Введите смещение> ");
                        offset = int.Parse(Console.ReadLine());

                        csr = new Cesar(inputString, offset);
                        Console.WriteLine("Расшифрованная строка: " + csr.Decrypt());
                        break;
                    case 3:
                        Console.Write("Введите строку> ");
                        inputString = Console.ReadLine();
                        for (int i = 0; i < lenRU; i++)
                        {
                            csr = new Cesar(inputString, i);
                            Console.WriteLine($"Расшифрованная строка {i}: {csr.Decrypt()};");
                        }
                        break;
                    default:
                        Console.Write("Что-то пошло не так!");
                        break;
                }
            }
        }
    }
}
