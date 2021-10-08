using System.DirectoryServices;
using System.Windows.Forms;

namespace lw2
{
    partial class InputForm
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
            this.directoryEntry1 = new System.DirectoryServices.DirectoryEntry();
            this.Read = new System.Windows.Forms.TabPage();
            this.lblSecretInput = new System.Windows.Forms.Label();
            this.txtReadImage = new System.Windows.Forms.TextBox();
            this.btnReadImage = new System.Windows.Forms.Button();
            this.selectFileButton = new System.Windows.Forms.Button();
            this.LSBTab = new System.Windows.Forms.TabControl();
            this.Read.SuspendLayout();
            this.LSBTab.SuspendLayout();
            this.SuspendLayout();
            // 
            // Read
            // 
            this.Read.Controls.Add(this.lblSecretInput);
            this.Read.Controls.Add(this.txtReadImage);
            this.Read.Controls.Add(this.btnReadImage);
            this.Read.Controls.Add(this.selectFileButton);
            this.Read.Location = new System.Drawing.Point(4, 29);
            this.Read.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Read.Name = "Read";
            this.Read.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Read.Size = new System.Drawing.Size(305, 323);
            this.Read.TabIndex = 1;
            this.Read.Text = "Открыть";
            this.Read.UseVisualStyleBackColor = true;
            // 
            // lblSecretInput
            // 
            this.lblSecretInput.AutoSize = true;
            this.lblSecretInput.Location = new System.Drawing.Point(13, 60);
            this.lblSecretInput.Name = "lblSecretInput";
            this.lblSecretInput.Size = new System.Drawing.Size(247, 20);
            this.lblSecretInput.TabIndex = 31;
            this.lblSecretInput.Text = "Выберите файл с криптограммой:";
            // 
            // txtReadImage
            // 
            this.txtReadImage.Location = new System.Drawing.Point(15, 85);
            this.txtReadImage.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txtReadImage.Name = "txtReadImage";
            this.txtReadImage.Size = new System.Drawing.Size(232, 27);
            this.txtReadImage.TabIndex = 11;
            this.txtReadImage.TextChanged += new System.EventHandler(this.txtReadImage_TextChanged);
            // 
            // btnReadImage
            // 
            this.btnReadImage.Location = new System.Drawing.Point(253, 79);
            this.btnReadImage.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnReadImage.Name = "btnReadImage";
            this.btnReadImage.Size = new System.Drawing.Size(40, 38);
            this.btnReadImage.TabIndex = 13;
            this.btnReadImage.Text = "...";
            this.btnReadImage.UseVisualStyleBackColor = true;
            this.btnReadImage.Click += new System.EventHandler(this.fileChooser2_Click);
            // 
            // selectFileButton
            // 
            this.selectFileButton.Enabled = false;
            this.selectFileButton.Location = new System.Drawing.Point(102, 275);
            this.selectFileButton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.selectFileButton.Name = "selectFileButton";
            this.selectFileButton.Size = new System.Drawing.Size(100, 38);
            this.selectFileButton.TabIndex = 12;
            this.selectFileButton.Text = "Открыть";
            this.selectFileButton.UseVisualStyleBackColor = true;
            this.selectFileButton.Click += new System.EventHandler(this.SelectFileButton_Click);
            // 
            // LSBTab
            // 
            this.LSBTab.Controls.Add(this.Read);
            this.LSBTab.Location = new System.Drawing.Point(18, 20);
            this.LSBTab.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.LSBTab.Name = "LSBTab";
            this.LSBTab.SelectedIndex = 0;
            this.LSBTab.Size = new System.Drawing.Size(313, 356);
            this.LSBTab.TabIndex = 0;
            // 
            // InputForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(345, 390);
            this.Controls.Add(this.LSBTab);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "InputForm";
            this.Text = "Криптоаналитика";
            this.Read.ResumeLayout(false);
            this.Read.PerformLayout();
            this.LSBTab.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private DirectoryEntry directoryEntry1;
        private TabPage Read;
        private Label lblSecretInput;
        private TextBox txtReadImage;
        private Button btnReadImage;
        private Button selectFileButton;
        private TabControl LSBTab;
    }
}