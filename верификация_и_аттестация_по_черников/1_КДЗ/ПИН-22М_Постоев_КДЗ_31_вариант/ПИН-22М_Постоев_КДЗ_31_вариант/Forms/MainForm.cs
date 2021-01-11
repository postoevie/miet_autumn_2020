using System;
using System.Drawing;
using System.Windows.Forms;

namespace ПИН_22М_Постоев_КДЗ_31_вариант 
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            ConfigureUIElements();
        }

        private void ConfigureUIElements()
        {
            FormBorderStyle = FormBorderStyle.FixedDialog;
            labelIntro.Text = "ПИН-22М Постоев И.Е. КДЗ Вариант 31";
            labelIntro.Font = new Font(labelIntro.Font.Name, AppConstants.mainFontSize);

            buttonLCD.Text = "Задание 1";
            buttonLCD.Font = new Font(buttonLCD.Font.Name, AppConstants.mainFontSize);
            buttonLCD.Click += new EventHandler(OnButtonLCD_Click);

            buttonMinMax.Text = "Задание 2";
            buttonMinMax.Font = new Font(buttonMinMax.Font.Name, AppConstants.mainFontSize);
            buttonMinMax.Click += new EventHandler(OnButtonMinMax_Click);

            buttonExit.Text = "Выход";
            buttonExit.Font = new Font(buttonExit.Font.Name, AppConstants.mainFontSize);
            buttonExit.Click += new EventHandler(OnButtonExit_Click);
        }

        private void OnButtonLCD_Click(Object sender, EventArgs e)
        {
            Hide();
            var lcdForm = new LCDForm(this);
            lcdForm.ShowDialog();
        }

        private void OnButtonMinMax_Click(Object sender, EventArgs e)
        {
            Hide();
            var minMaxForm = new MinMaxForm(this);
            minMaxForm.ShowDialog();
        }

        private void OnButtonExit_Click(Object sender, EventArgs e)
        {
            Close();
        }
    }
}
