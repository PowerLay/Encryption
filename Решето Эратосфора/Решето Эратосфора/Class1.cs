using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Решето_Эратосфора
{
    class Class1
    {
        public static void Main()
        {
            for (int i = 2; i <= 100; i++)
            {
                if (isSimple(i))
                {
                    Console.WriteLine(i);
                }
            }
            Console.ReadKey();
        }


        private static List<int> Eratos(int n)
        {
            List<int> arr = new List<int>();
            return arr;
        }

        private static bool isSimple(int N)
        {
            bool tf = true;
            for (int i = 2; i < N; i++)
            {
                if (N % i == 0)
                {
                    tf = false;
                    break;
                }
                else
                {
                    tf = true;
                }
            }
            return tf;
        }
    }
}
