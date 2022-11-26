using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_5
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void classBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            classBindingSource.RemoveCurrent();
            classBindingSource.EndEdit();
            this.Validate();
            this.classBindingSource.EndEdit();
            this.classTableAdapter.Adapter.Update(this.masterDataSet);
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "masterDataSet.Class". При необходимости она может быть перемещена или удалена.
            this.classTableAdapter.Fill(this.masterDataSet.Class);

        }

        private void классLabel_Click(object sender, EventArgs e)
        {

        }

        private void часов_в_неделюTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void предметTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void классTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form5 Fr5 = new Form5();
            Fr5.Show();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form8 Fr8 = new Form8();
            Fr8.Show();
        }
    }
}
