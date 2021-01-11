namespace ПИН_22М_Постоев_КДЗ_31_вариант
{
    partial class LCDForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.taskText = new System.Windows.Forms.TextBox();
            this.textNumber1 = new System.Windows.Forms.TextBox();
            this.textNumber2 = new System.Windows.Forms.TextBox();
            this.textNumber3 = new System.Windows.Forms.TextBox();
            this.introLabel = new System.Windows.Forms.Label();
            this.buttonSolve = new System.Windows.Forms.Button();
            this.labelNumber1 = new System.Windows.Forms.Label();
            this.labelNumber2 = new System.Windows.Forms.Label();
            this.labelNumber3 = new System.Windows.Forms.Label();
            this.labelResult = new System.Windows.Forms.Label();
            this.resultText = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // taskText
            // 
            this.taskText.Location = new System.Drawing.Point(13, 13);
            this.taskText.Multiline = true;
            this.taskText.Name = "taskText";
            this.taskText.Size = new System.Drawing.Size(859, 90);
            this.taskText.TabIndex = 0;
            // 
            // textNumber1
            // 
            this.textNumber1.Location = new System.Drawing.Point(225, 201);
            this.textNumber1.Name = "textNumber1";
            this.textNumber1.Size = new System.Drawing.Size(248, 20);
            this.textNumber1.TabIndex = 1;
            // 
            // textNumber2
            // 
            this.textNumber2.Location = new System.Drawing.Point(225, 253);
            this.textNumber2.Name = "textNumber2";
            this.textNumber2.Size = new System.Drawing.Size(248, 20);
            this.textNumber2.TabIndex = 2;
            // 
            // textNumber3
            // 
            this.textNumber3.Location = new System.Drawing.Point(225, 303);
            this.textNumber3.Name = "textNumber3";
            this.textNumber3.Size = new System.Drawing.Size(248, 20);
            this.textNumber3.TabIndex = 3;
            // 
            // introLabel
            // 
            this.introLabel.AutoSize = true;
            this.introLabel.Location = new System.Drawing.Point(17, 155);
            this.introLabel.Name = "introLabel";
            this.introLabel.Size = new System.Drawing.Size(27, 13);
            this.introLabel.TabIndex = 4;
            this.introLabel.Text = "intro";
            // 
            // buttonSolve
            // 
            this.buttonSolve.Location = new System.Drawing.Point(594, 201);
            this.buttonSolve.Name = "buttonSolve";
            this.buttonSolve.Size = new System.Drawing.Size(240, 122);
            this.buttonSolve.TabIndex = 5;
            this.buttonSolve.Text = "buttonSolve";
            this.buttonSolve.UseVisualStyleBackColor = true;
            // 
            // labelNumber1
            // 
            this.labelNumber1.AutoSize = true;
            this.labelNumber1.Location = new System.Drawing.Point(18, 204);
            this.labelNumber1.Name = "labelNumber1";
            this.labelNumber1.Size = new System.Drawing.Size(72, 13);
            this.labelNumber1.TabIndex = 6;
            this.labelNumber1.Text = "labelNumber1";
            // 
            // labelNumber2
            // 
            this.labelNumber2.AutoSize = true;
            this.labelNumber2.Location = new System.Drawing.Point(18, 256);
            this.labelNumber2.Name = "labelNumber2";
            this.labelNumber2.Size = new System.Drawing.Size(72, 13);
            this.labelNumber2.TabIndex = 7;
            this.labelNumber2.Text = "labelNumber2";
            // 
            // labelNumber3
            // 
            this.labelNumber3.AutoSize = true;
            this.labelNumber3.Location = new System.Drawing.Point(18, 306);
            this.labelNumber3.Name = "labelNumber3";
            this.labelNumber3.Size = new System.Drawing.Size(72, 13);
            this.labelNumber3.TabIndex = 8;
            this.labelNumber3.Text = "labelNumber3";
            // 
            // labelResult
            // 
            this.labelResult.AutoSize = true;
            this.labelResult.Location = new System.Drawing.Point(322, 412);
            this.labelResult.Name = "labelResult";
            this.labelResult.Size = new System.Drawing.Size(32, 13);
            this.labelResult.TabIndex = 9;
            this.labelResult.Text = "result";
            // 
            // resultText
            // 
            this.resultText.Location = new System.Drawing.Point(325, 450);
            this.resultText.Name = "resultText";
            this.resultText.Size = new System.Drawing.Size(248, 20);
            this.resultText.TabIndex = 10;
            // 
            // LCDForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(884, 561);
            this.Controls.Add(this.resultText);
            this.Controls.Add(this.labelResult);
            this.Controls.Add(this.labelNumber3);
            this.Controls.Add(this.labelNumber2);
            this.Controls.Add(this.labelNumber1);
            this.Controls.Add(this.buttonSolve);
            this.Controls.Add(this.introLabel);
            this.Controls.Add(this.textNumber3);
            this.Controls.Add(this.textNumber2);
            this.Controls.Add(this.textNumber1);
            this.Controls.Add(this.taskText);
            this.Name = "LCDForm";
            this.Text = "LCDForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox taskText;
        private System.Windows.Forms.TextBox textNumber1;
        private System.Windows.Forms.TextBox textNumber2;
        private System.Windows.Forms.TextBox textNumber3;
        private System.Windows.Forms.Label introLabel;
        private System.Windows.Forms.Button buttonSolve;
        private System.Windows.Forms.Label labelNumber1;
        private System.Windows.Forms.Label labelNumber2;
        private System.Windows.Forms.Label labelNumber3;
        private System.Windows.Forms.Label labelResult;
        private System.Windows.Forms.TextBox resultText;
    }
}