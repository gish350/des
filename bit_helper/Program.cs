using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bit_helper
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                int n;
                string x = "1";
                n = Convert.ToInt32(Console.ReadLine());
                string str = "0000000000000000000000000000000000000000000000000000000000000000";
                str = str.Substring(n + 1);
                Console.WriteLine(x + str);
            }
        }
    }
}
