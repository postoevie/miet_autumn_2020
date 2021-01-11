using System;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace ПИН_22М_Постоев_КДЗ_31_вариант
{
    /*
     * Структура, содержащая выходные данные программы
     */
    struct Result {
        public string textMaxMin;
        public string textAmplitude;
        public string textArithMean;
        public string textGeoMean;
    }

    /*
     * Класс для решения Задачи 2
     */
    public partial class MinMaxForm : Form
    {
        private const string WHITESPACE_NAME = "пробел";

        private MainForm parent;
    
        public MinMaxForm(MainForm mainForm)
        {
            parent = mainForm;
            InitializeComponent();
            ConfigureUIElements();
        }

        private void ConfigureUIElements()
        {
            SetupTextBoxesAppearance();
            SetupLabelsAppearance();
            SetupSolveButton();
            SetupDividerCheckBox();
        }

        /*
         * Настраивает надписи в пользовательском интерфейсе
         */
        private void SetupLabelsAppearance()
        {
            labelMaxMin.Text = "Первое из min/max";
            labelAmplitude.Text = "Размах";
            labelArithMean.Text = "Арифметическое среднее";
            labelGeoMean.Text = "Геометрическое среднее";
            introLabel.Text = "Введите массив чисел";
            labelResult.Text = "Результат";
            labelDivider.Text = "Разделитель:";

            labelMaxMin.Font = new Font(labelMaxMin.Font.Name, AppConstants.mainFontSize);
            labelAmplitude.Font = new Font(labelAmplitude.Font.Name, AppConstants.mainFontSize);
            labelArithMean.Font = new Font(labelArithMean.Font.Name, AppConstants.mainFontSize);
            labelGeoMean.Font = new Font(labelGeoMean.Font.Name, AppConstants.mainFontSize);
            introLabel.Font = new Font(introLabel.Font.Name, AppConstants.mainFontSize);
            labelResult.Font = new Font(labelResult.Font.Name, AppConstants.mainFontSize);
            labelDivider.Font = new Font(labelDivider.Font.Name, AppConstants.mainFontSize);
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
            taskText.Text = "Условие: с клавиатуры вводится массив целых чисел до нажатия клавиши «Esc». " +
                "Какое число в массиве встретится раньше: максимальное или минимальное? " +
                "Если таких чисел несколько, то должны быть учтены самые первые из них. " +
                "Определить размах значений элементов массива, его среднее арифметическое и среднее геометрическое значение." +
                "Результаты вывести на экран.";
            taskText.Select(0, 0);

            textMaxMin.ReadOnly = true;
            textAmplitude.ReadOnly = true;
            textArithMean.ReadOnly = true;
            textGeoMean.ReadOnly = true;

            textInputNumbers.Font = new Font(textInputNumbers.Font.Name, AppConstants.mainFontSize);
            taskText.Font = new Font(taskText.Font.Name, AppConstants.mainFontSize);
            textMaxMin.Font = new Font(textMaxMin.Font.Name, AppConstants.mainFontSize);
            textAmplitude.Font = new Font(textAmplitude.Font.Name, AppConstants.mainFontSize);
            textArithMean.Font = new Font(textArithMean.Font.Name, AppConstants.mainFontSize);
            textGeoMean.Font = new Font(textGeoMean.Font.Name, AppConstants.mainFontSize);

            textInputNumbers.KeyDown += TextInputNumbers_KeyDown;
        }

        /*
        * Обработчик нажатия "Esc"
        */
        private void TextInputNumbers_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
            {
                SolveWithValidation();
            }
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

        /*
         * Настраивает элемент выбора разделителя
         */
        private void SetupDividerCheckBox() {
            string[] dividers = {WHITESPACE_NAME, ";", ",", ":"};
            comboBoxDivider.Items.AddRange(dividers);
            comboBoxDivider.SelectedIndex = 0;
            comboBoxDivider.Font = new Font(comboBoxDivider.Font.Name, AppConstants.mainFontSize);
        }

        private void OnButtonSolve_Click(Object sender, EventArgs e)
        {
            SolveWithValidation();
        }

        /*
         * Решает задачу с обработкой входных значений
         * Заполняет текстовые поля выходных данных
         */
        private void SolveWithValidation()
        {
            var numbers = GetValidatedInputNumbers();

            // если произошла ошибка валидации или введено малое количество чисел, к решению не приступать
            if (numbers.Length >= 2)
            {
                var result = GetResultFor(numbers);
                textMaxMin.Text = result.textMaxMin;
                textAmplitude.Text = result.textAmplitude;
                textArithMean.Text = result.textArithMean;
                textGeoMean.Text = result.textGeoMean;
            }
        }

        /*
         * Возвращает массив проверенных значений
         * Если возникла ошибка проверки - отображает соответствующее окно и возвращает пустой массив
         */
        private int[] GetValidatedInputNumbers()
        {
            string input = textInputNumbers.Text;
            string selectedState = comboBoxDivider.SelectedItem.ToString();

            char divider;
            if (selectedState.Equals(WHITESPACE_NAME))
            {
                divider = ' ';
            }
            else {
                divider = selectedState.ToCharArray()[0];
            }

            try
            {
                int[] numbers = input.Trim(divider).Split(divider).Select(n => Convert.ToInt32(n)).ToArray();
                return numbers.Length >= 2 ? numbers : new int[0];
            }
            catch (FormatException e)
            {
                MessageBox.Show("Формат ввода: \"a!b!c,...\" где a,b,c - целочисленные значения, ! - разделитель");
                return new int[0];
            }
            catch (Exception)
            {
                MessageBox.Show("Ошибка входных данных");
                return new int[0];
            }
        }

        /*
         * Возвращает подготовленные для отображения выходные данные
         */
        private Result GetResultFor(int[] input) 
        {
            var result = new Result();

            (bool isMax, int index, int value, int amplitude) = GetMinMax(input);
            double arithMean = GetArithmeicMean(input);
            double geoMean = GetGeometricMean(input);

            string textMaxMin = isMax ? "Первое - максимальное" : "Первое - минимальное";
            textMaxMin += Environment.NewLine + "Значение: " + value + 
                Environment.NewLine + "Позиция: " + (index + 1);
            result.textMaxMin = textMaxMin;
            result.textAmplitude = amplitude.ToString();
            result.textArithMean = arithMean.ToString();
            result.textGeoMean = geoMean.ToString();

            return result;
        }

        /*
         * Определяет максимальное/минимальное значения последовательности.
         * Возвращает кортеж из значений:
         * (первый-максимум?, индекс значения, значение, разброс)
         */
        private (bool, int, int, int) GetMinMax(int[] input)
        {
            int minIndex = 0, 
                maxIndex = 0;
            int min = input[0], 
                max = input[0];
            int current = 0;

            for(int i = 0; i < input.Length; i++) {
                current = input[i];
                if (current < min)
                {
                    min = current;
                    minIndex = i;
                }
                else if (current > max)
                {
                    max = current;
                    maxIndex = i;
                }
            }

            if (minIndex < maxIndex)
            {
                return (false, minIndex, min, max - min);
            } 
            else 
            {
                return (true, maxIndex, max, max - min);
            }
        }

        /*
         * Возвращает арифметическое среднее
         */
        private double GetArithmeicMean(int[] input) 
        {
            int sum = input.Sum();
            int length = input.Length;
            return sum / length;
        }

        /*
         * Возвращает геометрическое среднее
         */
        private double GetGeometricMean(int[] input) 
        {
            double multipliedValues = input.Aggregate((x, y) => x * y);
            int length = input.Length;

            return Math.Pow(multipliedValues, 1.0 / length);
        }
    }
}