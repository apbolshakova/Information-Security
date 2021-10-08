using System;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace lw2_inst
{
    public partial class Form1 : Form
    {
        [DllImport("Kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern bool GetVolumeInformation(string vol, StringBuilder name, int nameSize, out uint serialNum, out uint maxNameLen, out uint flags, StringBuilder fileSysName, int fileSysNameSize);

        public Form1()
        {
            InitializeComponent();
            var initialPath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
            txtReadImage.Text = initialPath;

            comboBox1.DataSource = DriveInfo.GetDrives().ToList();
            comboBox1.DisplayMember = "Name";
        }

        #region Read Form
        private void SelectFileButton_Click(object sender, EventArgs e)
        {
            Install();
            MessageBox.Show("Программа установлена!", "Успех", MessageBoxButtons.OK);
            Application.Exit();
        }

        private void FileChooser2_Click(object sender, EventArgs e)
        {
            using var fileChooserDialog = new OpenFileDialog();
            using var folderBrowserDialog = new FolderBrowserDialog();
            if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
            {
                txtReadImage.Text = folderBrowserDialog.SelectedPath;
            }
        }

        #endregion

        private void TxtReadImage_TextChanged(object sender, EventArgs e)
        {
            selectFileButton.Enabled = !string.IsNullOrWhiteSpace(txtReadImage.Text);
        }

        // Процесс установки
        private void Install()
        {
            var path = txtReadImage.Text + "\\crypto";
            if (Directory.Exists(path))
            {
                Directory.Delete(path, true);
            }
            Directory.CreateDirectory(path);
            File.Copy("lw2.exe", path + "\\start.exe");
            File.Copy("lw2.dll", path + "\\lw2.dll");
            File.Copy("lw2.runtimeconfig.json", path + "\\lw2.runtimeconfig.json");
            File.Copy("bis-lw2.exe", path + "\\bis-lw2.exe");

            Directory.CreateDirectory(path + "\\comp");

            var rootPath = (comboBox1.SelectedItem as DriveInfo)?.Name;
            var fileSystem = new StringBuilder();
            var name = new StringBuilder();

            GetVolumeInformation(rootPath, name, 100, out var serialNum, out _, out _, fileSystem, 100);

            var serial = serialNum.ToString().PadRight(10, '5');

            // Каждую цифру возводим в квадрат и прибавляем 5 =>
            // получаем номер некоторого символа,
            // который далее запишем в сопроводительные файлы
            var result = serial.Aggregate("", (current, t) =>
            {
                var temp = (int)(Math.Pow(t - '0', 2) + 5);

                return current + Convert.ToChar(temp);
            });

            using (var sw = new StreamWriter(path + "\\comp\\def.dll", false, Encoding.UTF8))
                sw.Write(result.Substring(0, 5));
            using (var sw = new StreamWriter(path + "\\comp.log", false, Encoding.UTF8))
                sw.Write(result.Substring(5, 5));
        }
    }
}
