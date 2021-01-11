namespace ПИН_22М_Постоев_КДЗ_31_вариант
{
    partial class MainForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuPanel = new System.Windows.Forms.Panel();
            this.buttonExit = new System.Windows.Forms.Button();
            this.labelIntro = new System.Windows.Forms.Label();
            this.buttonMinMax = new System.Windows.Forms.Button();
            this.buttonLCD = new System.Windows.Forms.Button();
            this.menuPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuPanel
            // 
            this.menuPanel.Controls.Add(this.buttonExit);
            this.menuPanel.Controls.Add(this.labelIntro);
            this.menuPanel.Controls.Add(this.buttonMinMax);
            this.menuPanel.Controls.Add(this.buttonLCD);
            this.menuPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.menuPanel.Location = new System.Drawing.Point(0, 0);
            this.menuPanel.Name = "menuPanel";
            this.menuPanel.Size = new System.Drawing.Size(794, 448);
            this.menuPanel.TabIndex = 0;
            // 
            // buttonExit
            // 
            this.buttonExit.Location = new System.Drawing.Point(246, 319);
            this.buttonExit.Name = "buttonExit";
            this.buttonExit.Size = new System.Drawing.Size(292, 90);
            this.buttonExit.TabIndex = 0;
            this.buttonExit.TabStop = false;
            this.buttonExit.Text = "exit";
            this.buttonExit.UseVisualStyleBackColor = true;
            // 
            // labelIntro
            // 
            this.labelIntro.AutoSize = true;
            this.labelIntro.Location = new System.Drawing.Point(12, 9);
            this.labelIntro.Name = "labelIntro";
            this.labelIntro.Size = new System.Drawing.Size(27, 13);
            this.labelIntro.TabIndex = 11;
            this.labelIntro.Text = "intro";
            // 
            // buttonMinMax
            // 
            this.buttonMinMax.Location = new System.Drawing.Point(246, 206);
            this.buttonMinMax.Name = "buttonMinMax";
            this.buttonMinMax.Size = new System.Drawing.Size(292, 90);
            this.buttonMinMax.TabIndex = 0;
            this.buttonMinMax.TabStop = false;
            this.buttonMinMax.Text = "minmax";
            this.buttonMinMax.UseVisualStyleBackColor = true;
            // 
            // buttonLCD
            // 
            this.buttonLCD.Location = new System.Drawing.Point(246, 90);
            this.buttonLCD.Name = "buttonLCD";
            this.buttonLCD.Size = new System.Drawing.Size(292, 90);
            this.buttonLCD.TabIndex = 0;
            this.buttonLCD.TabStop = false;
            this.buttonLCD.Text = "lcd";
            this.buttonLCD.UseVisualStyleBackColor = true;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(794, 448);
            this.Controls.Add(this.menuPanel);
            this.Name = "MainForm";
            this.Text = "ПИН-22М Постоев КДЗ Вариант 31";
            this.menuPanel.ResumeLayout(false);
            this.menuPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel menuPanel;
        private System.Windows.Forms.Button buttonExit;
        private System.Windows.Forms.Label labelIntro;
        private System.Windows.Forms.Button buttonMinMax;
        private System.Windows.Forms.Button buttonLCD;
    }
}

