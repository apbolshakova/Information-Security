using System;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace lw2
{
    public partial class InputForm : Form
    {
        // Импорт функции для получения информации о хранилищах информации
        [DllImport("Kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern bool GetVolumeInformation(string vol, StringBuilder name, int nameSize, out uint serialNum, out uint maxNameLen, out uint flags, StringBuilder fileSysName, int fileSysNameSize);

        public InputForm()
        {
            FormBorderStyle = FormBorderStyle.FixedSingle;
            InitializeComponent();
        }

        // Обработка нажатия кнопки "Открыть"
        private void SelectFileButton_Click(object sender, EventArgs e)
        {
            // Переменная с параметрами процесса для основной программы
            System.Diagnostics.ProcessStartInfo startInfo = new System.Diagnostics.ProcessStartInfo();
            startInfo.FileName = "bis-lw2.exe";
            // Первый аргумент - путь до файла с криптограммой
            startInfo.Arguments = "\"" + txtReadImage.Text + "\"";


            // Не имеющий практического смысла код, добавлен для обфускации
            var lorem = 0;
            for (int ipsum = 0; ipsum < 512; ipsum++) lorem = 4 + 6 - 3 + ipsum;

            // Считывание содержимого файла со второй половиной зашифрованного серийного номера
            string text = File.ReadAllText("comp.log");

            string dolor = "";
            string substring = "";

            // Цикл для каждого подключённого устройства, выход произойдёт если найдётся совпадение
            foreach (var driveInfo in DriveInfo.GetDrives().ToArray())
            {
                var rootPath = driveInfo.Name;
                var fileSystem = new StringBuilder();
                var name = new StringBuilder();

                GetVolumeInformation(rootPath, name, 100, out var serialNum, out _, out _, fileSystem, 100);

                // Обфускация + устойчивость, если возникнет маленький серийный номер 
                var serial = serialNum.ToString().PadRight(10, '5');

                // Преобразование серийного номера текущего проверяемого устройства согласно алгоритму шифрования
                var result = serial.Aggregate("", (current, t) =>
                {
                    var temp = (int)((Math.Pow(t - '0', 2) + 5) % 20 + 'A');

                    return current + Convert.ToChar(temp);
                });

                substring = result.Substring(5, 5);

                // Если вторая половина получившейся строки совпадает с содержимым comp.log
                if (substring.Equals(text))
                {
                    // То добавляем контент в переменную, имитирующую булевый тип
                    dolor += serial[0];
                    // Добавляем в аргументы, которые будут переданы в основную программу,
                    // первую половину серийного номера
                    startInfo.Arguments += " " + serial.Substring(0, 5);
                    // В переменную, с которой будет происходит вторая проверка кладём первую половину
                    // получившейся строки. Одна и та же переменная используется для усложнения кода
                    substring = result.Substring(0, 5);
                    break;
                }
            }

            // Если в строке, имитирующей булевый флаг есть что-то, то произошло совпадение второй половины
            // серийного номера
            if (!string.IsNullOrWhiteSpace(dolor))
            {
                // Проверка первой половины
                text = File.ReadAllText("comp/def.dll");
                if (substring.Equals(text))
                {
                    // Запуск основной программы в случае успеха второй проверки
                    System.Diagnostics.Process.Start(startInfo);
                }

                // Код без практического применения
                startInfo.FileName += lorem;
            }

            // Код без практического применения
            for (int ipsum = 0; ipsum < 512; ipsum++) lorem = 4 + 6 - 3 + ipsum;
        }

        // Обработка нажатия кнопки выбора файла
        private void fileChooser2_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog fileChooserDialog = new OpenFileDialog())
            {
                fileChooserDialog.Filter = "TXT Files (.txt)|*.txt";
                if (fileChooserDialog.ShowDialog() == DialogResult.OK)
                {
                    txtReadImage.Text = fileChooserDialog.FileName;
                }
            }
        }

        // Обработка изменения содержимого поля с выбранным файлом
        private void txtReadImage_TextChanged(object sender, EventArgs e)
        {
            selectFileButton.Enabled = !string.IsNullOrWhiteSpace(txtReadImage.Text);
        }
    }
}