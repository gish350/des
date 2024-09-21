using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace bit_helper
{
    class Program
    {

        static void gen_pc2()
        {
            List<int> nums = new List<int>() { 14,   17,  11,  24,  1,   5,
                                                3,   28,  15,  6,   21,  10,
                                                23,  19,  12,  4 ,  26 , 8,
                                                16,  7,   27,  20,  13,  2,
                                                41,  52,  31,  37,  47,  55,
                                                30,  40,  51,  45,  33,  48,
                                                44,  49,  39,  56,  34,  53,
                                                46,  42,  50,  36,  29,  32};
            int i = 0;
            foreach (int bitPosition in nums)
            {
                ulong number = 0;
                number |= (1UL << (63 -( bitPosition - 1))); // Установка указанного бита в единицу

                // Вычисление количества бит, на которое нужно сместить вправо, чтобы получить 1
                int shiftCount = 63 - (bitPosition - 1);

                // Вывод результата в шестнадцатеричном формате
               
                Console.WriteLine($"*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x{number:X}) >> {shiftCount} - {i} ;			// {bitPosition}");
                i++;
            }
            Console.ReadKey();
        }

        static void make_p()
        {
            List<int> nums = new List<int>() {
                                                16,  7 ,  20,  21 , 29,  12  ,28,  17,
                                                1,   15,  23,  26 , 5  , 18  ,31 , 10,
                                                2,   8,   24,  14,  32  ,27 , 3   ,9,
                                                19,  13,  30,  6,   22  ,11,  4  , 25,

                                                };
            int i = 0;
            foreach (int bitPosition in nums)
            {
                uint number = 0;
                number |= (1U << (31 - (bitPosition - 1))); // Установка указанного бита в единицу

                // Вычисление количества бит, на которое нужно сместить вправо, чтобы получить 1
                int shiftCount = 31 - (bitPosition - 1);

                // Вывод результата в шестнадцатеричном формате
                Console.WriteLine($"p = p | ((h_dash & 0x{number:X}) >> ({shiftCount} - {i}));			// {bitPosition}");
                i++;
            }
            Console.ReadKey();
            
        }

        static void gen_ip()
        {
            List<int> nums = new List<int>() { 58,   50,  42,  34,  26,  18,  10,  2,
                                                60,  52,  44,  36,  28,  20,  12,  4,
                                                62,  54,  46,  38,  30,  22,  14,  6,
                                                64,  56,  48,  40,  32,  24,  16,  8,
                                                57,  49,  41,  33,  25,  17,  9,  1,
                                                59, 51,  43,  35,  27,  19,  11,  3,
                                                61,  53,  45,  37,  29, 21,  13,  5,
                                                63,  55,  47,  39,  31,  23,  15,  7};
            int i = 0;
            foreach (int bitPosition in nums)
            {
                ulong number = 0;
                number |= (1UL << (63 - (bitPosition - 1))); // Установка указанного бита в единицу

                // Вычисление количества бит, на которое нужно сместить вправо, чтобы получить 1
                int shiftCount = 63 - (bitPosition - 1);

                // Вывод результата в шестнадцатеричном формате

               
                Console.WriteLine($"ip = ip | ((*block_64 & 0x{number:X}) >> {shiftCount} - {i}); \t\t\t // {bitPosition}");
                i++;
            }
            Console.ReadKey();
        }

        static void gen_ip1()
        {
            List<int> nums = new List<int>() {40,    8,   48,  16,  56,  24,  64,  32,
                                            39,  7  , 47,  15,  55,  23,  63,  31,
                                            38,  6 ,  46 , 14,  54,  22,  62,  30,
                                            37,  5,   45,  13,  53,  21,  61,  29,
                                            36,  4,   44,  12,  52,  20,  60,  28,
                                            35,  3  , 43,  11,  51,  19,  59,  27,
                                            34,  2 ,  42,  10,  50,  18,  58,  26,
                                            33,  1,   41,  9,   49,  17,  57,  25};
            int i = 0;
            foreach (int bitPosition in nums)
            {
                ulong number = 0;
                number |= (1UL << (63 - (bitPosition - 1))); // Установка указанного бита в единицу

                // Вычисление количества бит, на которое нужно сместить вправо, чтобы получить 1
                int shiftCount = 63 - (bitPosition - 1);

                // Вывод результата в шестнадцатеричном формате


                Console.WriteLine($"ip = ip | ((*block_64 & 0x{number:X}) >> {shiftCount} - {i}); \t\t\t // {bitPosition}");
                i++;
            }
            Console.ReadKey();
        }

        static void gen_e()
        {
            List<int> nums = new List<int>() { 32,   1,   2,   3,   4,   5,
                                               4,    5,   6 ,  7,   8,   9,
                                                8,   9,   10,  11,  12,  13,
                                                12,  13,  14,  15,  16,  17,
                                                16,  17,  18,  19,  20,  21,
                                                20,  21,  22,  23,  24,  25,
                                                24,  25,  26,  27,  28,  29,
                                                28,  29,  30,  31,  32,  1};
            int i = 0;
            foreach (int bitPosition in nums)
            {
                ulong number = 0;
                number |= (1UL << (63 - (bitPosition - 1))); // Установка указанного бита в единицу

                // Вычисление количества бит, на которое нужно сместить вправо, чтобы получить 1
                int shiftCount = 63 - (bitPosition - 1);

                // Вывод результата в шестнадцатеричном формате


               
                Console.WriteLine($"e = e | ((tmp_l & 0x{number:X}) >> {shiftCount} - {i});\t\t\t\t//{bitPosition}");
                i++;
            }
            Console.ReadKey();
        }

        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            if (n == 1)
                gen_pc2();
            else if (n == 2)
                gen_ip();
            else if (n == 3)
                gen_e();
            else if (n ==4)
                make_p();
            else if (n ==5)
                gen_ip1();
            
            else
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
}
