using System;
using System.Drawing;
using System.Windows.Forms;

namespace ПИН_22М_Постоев_КДЗ_31_вариант
{
    /*
     * Класс для решения Задачи 1
     */
    public partial class LCDForm : Form
    {

        /*
         * Структура, содержащая входные значения
         */
        struct InputNumbers
        {
            public int number1;
            public int number2;
            public int number3;

            public InputNumbers(int number1, int number2, int number3) {
                this.number1 = number1;
                this.number2 = number2;
                this.number3 = number3;
            }
        }

        private MainForm parent;

        public LCDForm(MainForm mainForm)
        {
            parent = mainForm;
            InitializeComponent();
            ConfigureUIElements();
        }
        private void ConfigureUIElements()
        {
            SetupLabelsAppearance();
            SetupTextBoxesAppearance();
            SetupSolveButton();
        }

        /*
         * Настраивает надписи в пользовательском интерфейсе
         */
        private void SetupLabelsAppearance()
        {
            introLabel.Text = "Введите 3 числа для определения их НОД";
            labelNumber1.Text = "Число 1";
            labelNumber2.Text = "Число 2";
            labelNumber3.Text = "Число 3";
            labelResult.Text = "Результат";
            
            introLabel.Font = new Font(introLabel.Font.Name, AppConstants.mainFontSize);
            labelNumber1.Font = new Font(labelNumber1.Font.Name, AppConstants.mainFontSize);
            labelNumber2.Font = new Font(labelNumber2.Font.Name, AppConstants.mainFontSize);
            labelNumber3.Font = new Font(labelNumber3.Font.Name, AppConstants.mainFontSize);
            labelResult.Font = new Font(labelResult.Font.Name, AppConstants.mainFontSize);
        }

        /*
         * Настраивает текстовые поля в пользовательском интерфейсе
         */
        private void SetupTextBoxesAppearance()
        {
            FormBorderStyle = FormBorderStyle.FixedDialog;

            taskText.Multiline = true;
            taskText.BorderStyle = BorderStyle.None;
            taskText.BackColor = DefaultBackColor;
            taskText.ReadOnly = true;
            taskText.Font = new Font(taskText.Font.Name, AppConstants.mainFontSize);
            taskText.Text = "С клавиатуры по запросу программы вводятся три целых числа." +
                "Вывести на экран их наибольший общий делитель, имея в виду, что НОД(a, b, с) = НОД(НОД(a, b), с)." +
                "При отсутствии решения сформировать соответствующее сообщение.";
            taskText.Select(0, 0);

            resultText.ReadOnly = true;
            resultText.Font = new Font(resultText.Font.Name, AppConstants.mainFontSize);
            textNumber1.Font = new Font(textNumber1.Font.Name, AppConstants.mainFontSize);
            textNumber2.Font = new Font(textNumber2.Font.Name, AppConstants.mainFontSize);
            textNumber3.Font = new Font(textNumber3.Font.Name, AppConstants.mainFontSize);
        }

        /*
         * После закрытия текущего окна, отображает главное окно
         */
        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            base.OnFormClosing(e);
            parent.Show();
        }

        /*
         * Настраивает кнопку "Решить"
         */
        private void SetupSolveButton()
        {
            buttonSolve.Text = "Решить";
            buttonSolve.Font = new Font(buttonSolve.Font.Name, AppConstants.mainFontSize);
            buttonSolve.Click += new EventHandler(OnButtonSolve_Click);
        }

        private void OnButtonSolve_Click(Object sender, EventArgs e)
        {
            SolveWithValidation();
        }

        /*
         * Проводит поиск решения с учетом проверки входных значений.
         * Заполняет текстовое поле ответа
         */
        private void SolveWithValidation()
        {
            InputNumbers? numbers = getValidatedInputNumbers();
            if (numbers.HasValue) 
            {
                int result = getResultFor(numbers.Value);
                resultText.Text = result.ToString();
            }
        }

        /*
         * Проверяет применимость входных значений к поиску решения.
         * Возвращает структуру из проверенных входные значений, если каждое из них соответствуют требованиям.
         * Возвращает null, если хотя бы одно не соответствует требованиям.
         * т.е. возвращаемое значение - опциональное(либо действительное значение, либо null в одном представлении)
         */
        private InputNumbers? getValidatedInputNumbers()
        {
            int? input1;
            int? input2;
            int? input3;

            //Получение проверенных значений. 
            try
            {
                input1 = getValidatedInputWith(textNumber1.Text, labelNumber1.Text);
                input2 = getValidatedInputWith(textNumber2.Text, labelNumber2.Text);
                input3 = getValidatedInputWith(textNumber3.Text, labelNumber3.Text);
            }
            catch (Exception e)
            {
                //Обработка исключений: отображение окон соотетствующего ошибке содержания.
                if (e is FormatException)
                {
                    MessageBox.Show("Невозможно преобразовать " + e.Message + " в целочисленное значение");
                }
                else 
                {
                    MessageBox.Show("Ошибка входных данных");
                }
                return null;
            }

            //"Раскрытие" опциональных значений - проверка на содержание действительного значения
            if (!input1.HasValue || !input2.HasValue || !input3.HasValue) 
            {
                return null;
            }

            return new InputNumbers(input1.Value, input2.Value, input3.Value);
        }

        /*
         * Проверка входного значения.
         * Возвращает входное значение в целочисленном формате, либо null, если оно не соответсвует требованиям.
         */
        private int? getValidatedInputWith(String input, String errorSource)  
        {
            int num;
            
            try
            {
                num = Int32.Parse(input);
            } 
            catch
            {
                throw new FormatException(errorSource);
            }

            return num;
        }

        /*
         * Обработка значений для работы с методом поиска НОД
         */
        private int getResultFor(InputNumbers numbers)
        {
            int a = Math.Abs(numbers.number1);
            int b = Math.Abs(numbers.number2);
            int c = Math.Abs(numbers.number3);

            return getLCDFor(a, b, c);
        }

        /*
         * Возвращает НОД трех чисел
         */
        private int getLCDFor(int a, int b, int c)
        {
            return Euqlid(Euqlid(a, b), c);
        }

        /*
         * Возвращает НОД двух чисел
         */
        private int Euqlid(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
            else
            {
                return Euqlid(b, a % b);
            }
        }
    }
}
