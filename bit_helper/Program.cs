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
                Console.WriteLine("Введите порядковый номер бита (от 0 до 63): ");
                int bitIndex = int.Parse(Console.ReadLine());

                // Проверка на корректность ввода
                if (bitIndex < 0 || bitIndex > 63)
                {
                    Console.WriteLine("Ошибка: введите число от 0 до 63.");
                    return;
                }

                // Создаем число, где только один бит установлен на 1 в указанной позиции
                ulong bitMask = 1UL << bitIndex;

                // Выводим число в шестнадцатеричном формате
                Console.WriteLine($"Число, соответствующее биту {bitIndex}, в шестнадцатеричном формате: {bitMask:X}");
            }
           
            
        }
    }
}
