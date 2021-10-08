
namespace n_lw2_inst
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.txtReadImage = new System.Windows.Forms.TextBox();
            this.btnReadImage = new System.Windows.Forms.Button();
            this.selectFileButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(242, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Выберите директорию установки";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 103);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(211, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "Выберите диск для привязки";
            // 
            // comboBox1
            // 
            this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(12, 135);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(233, 28);
            this.comboBox1.TabIndex = 4;
            // 
            // txtReadImage
            // 
            this.txtReadImage.Location = new System.Drawing.Point(13, 46);
            this.txtReadImage.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtReadImage.Name = "txtReadImage";
            this.txtReadImage.Size = new System.Drawing.Size(232, 27);
            this.txtReadImage.TabIndex = 14;
            this.txtReadImage.TextChanged += new System.EventHandler(this.TxtReadImage_TextChanged);
            // 
            // btnReadImage
            // 
            this.btnReadImage.Location = new System.Drawing.Point(251, 40);
            this.btnReadImage.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnReadImage.Name = "btnReadImage";
            this.btnReadImage.Size = new System.Drawing.Size(40, 38);
            this.btnReadImage.TabIndex = 15;
            this.btnReadImage.Text = "...";
            this.btnReadImage.UseVisualStyleBackColor = true;
            this.btnReadImage.Click += new System.EventHandler(this.FileChooser2_Click);
            // 
            // selectFileButton
            // 
            this.selectFileButton.Enabled = false;
            this.selectFileButton.Location = new System.Drawing.Point(191, 217);
            this.selectFileButton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.selectFileButton.Name = "selectFileButton";
            this.selectFileButton.Size = new System.Drawing.Size(100, 38);
            this.selectFileButton.TabIndex = 16;
            this.selectFileButton.Text = "Установить";
            this.selectFileButton.UseVisualStyleBackColor = true;
            this.selectFileButton.Click += new System.EventHandler(this.SelectFileButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(308, 269);
            this.Controls.Add(this.selectFileButton);
            this.Controls.Add(this.txtReadImage);
            this.Controls.Add(this.btnReadImage);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Name = "Form1";
            this.Text = "Установщик";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.TextBox txtReadImage;
        private System.Windows.Forms.Button btnReadImage;
        private System.Windows.Forms.Button selectFileButton;
    }
}

