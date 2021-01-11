using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;


namespace ПИН_22М_Постоев_КДЗ_23_вариант.practical_tasks
{
    class HW_Complexity2
    {
        class Task1
        {
            static void NoMain(string[] args)
            {
                double x, y = 0;// аргумент и значение функции.
                char rep;// признак повтора.
                string str; //Строка для ввода и вывода данных.
            Metka://Начало программы.
                Console.Clear();// Очистка экрана
                Console.ForegroundColor = ConsoleColor.Yellow;//Задание тексту желтого цвета.
                Console.WriteLine("Введите аргумент x");// Ввод и считывание 
                str = Console.ReadLine();// аргумента.
                x = double.Parse(str);
                if (x < -1 || x > 1) y = 1;// Задание условия.
                if (x >= -1 && x < 0) y = 0.3;
                if (x >= 0 && x <= 1) y = x * x;
                str = "F(" + x + ")=" + y;//Формирование строки.
                Console.WriteLine(str);//Вывод строки
                Console.Beep(1600, 999);
                Console.Write("Для повтора вычисления нажмите клавишу k:");//Повторное вычисление при нажатии клавиши k.
                rep = char.Parse(Console.ReadLine());
                if (rep == 'k' || rep == 'K') goto Metka;
            }
        }
    }

    class Task2
    {
        static void NoMain(string[] args)
        {
            double a,
                   b,
                   c,
                   d,
                   min,
                   max,
                   raz;
            char str;
            do
            {
                min = 0;
                max = 0;
                Console.Clear();
                Console.WriteLine("Введите значение переменной a");
                a = double.Parse(Console.ReadLine());
                Console.WriteLine("Введите значение переменной b");
                b = double.Parse(Console.ReadLine());
                Console.WriteLine("Введите значение переменной c");
                c = double.Parse(Console.ReadLine());
                Console.WriteLine("Введите значение переменной d");
                d = double.Parse(Console.ReadLine());
                min = a;
                if (b < min) min = b;

                if (c < min) min = c;

                if (d < min) min = c;
                max = a;
                if (b > max) max = b;
                if (c > max) max = c;
                if (d > max) max = d;
                raz = max - min;

                Console.WriteLine("Минимальное число" + min);

                Console.WriteLine("Максимальное число" + max);

                Console.WriteLine("Разность максимального и минимального значения" + raz);
                Console.WriteLine("Для повторного вычисления нажмите Y || y");
                str = char.Parse(Console.ReadLine());
            }

            while (str == 'Y' || str == 'y');
        }
    }

    class Task3
    {
        class Method
        {
            public double[,] Заполнение(int n, int m)
            {
                double[,] a = new double[n, m];
                int i, j;
                Random gen = new Random();
                for (i = 0; i < n; i++)
                    for (j = 0; j < m; j++)
                        a[i, j] = gen.NextDouble() * (21.7 - (-12.4)) + (-12.4);
                return a;


            }
            public void Вывод(double[,] a, int n, int m)
            {
                int i, j;
                for (i = 0; i < n; i++, Console.WriteLine())
                    for (j = 0; j < m; j++)
                        Console.Write("{0,7:f1} ", a[i, j]);

            }

            public ArrayList Копирование(double[,] a, int n, int m)
            {
                int i, j;
                ArrayList b = new ArrayList();
                for (i = 0; i < n; i++)
                    for (j = 0; j < m; j++)
                        if (a[i, j] < 0)
                            b.Add(a[i, j]);
                return b;
            }
            public void Вывод1(ArrayList b)
            {
                int i;
                for (i = 0; i < b.Count; i++)
                    Console.Write("{0,2:f1} ", b[i]);
            }

        }

        static void NoMain(string[] args)
        {
            int n, m;

            Console.WriteLine("Введите кол-во строк в массиве: ");
            n = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите кол-во столбцов в массиве: ");
            m = int.Parse(Console.ReadLine());

            double[,] a = new double[n, m];

            Method obj1 = new Method();
            Method obj2 = new Method();
            Method obj3 = new Method();
            Method obj4 = new Method();
            obj1.Вывод(obj2.Заполнение(n, m), n, m);
            obj4.Вывод1(obj3.Копирование(obj2.Заполнение(n, m), n, m));

            Console.ReadLine();
        }
    }
}
