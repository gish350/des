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
                {
                    Console.WriteLine();
                    Console.WriteLine("==================================================");
                    
                    Console.Write("Введите номер бита (от 0 до 63, где 0 - старший бит): ");
                    int bitPosition;

                    // Проверка корректности ввода
                    if (!int.TryParse(Console.ReadLine(), out bitPosition) || bitPosition < 0 || bitPosition > 63)
                    {
                        Console.WriteLine("Ошибка: введите число от 0 до 63.");
                        return;
                    }

                    // Установка бита в единицу
                    ulong number = 0;
                    number |= (1UL << (63 - bitPosition)); // Установка указанного бита в единицу

                    // Вычисление количества бит, на которое нужно сместить вправо, чтобы получить 1
                    int shiftCount = 63 - bitPosition;

                    // Вывод результата в шестнадцатеричном формате
                    Console.WriteLine($"Результат: {number:X}");
                    Console.WriteLine($"Количество бит для сдвига вправо, чтобы получить 1: {shiftCount}");
                    Console.WriteLine("==================================================");
                    Console.WriteLine();
                    
                }
            }
        }

    }
}
