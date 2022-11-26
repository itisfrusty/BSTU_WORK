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
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void classBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.classBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.masterDataSet);

        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            button1.Enabled = true;
        }

        private void Form5_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "masterDataSet.Class". При необходимости она может быть перемещена или удалена.
            this.classTableAdapter.Fill(this.masterDataSet.Class);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            DataGridViewColumn Col = classDataGridView.Columns[0];

            switch (listBox1.SelectedIndex)
            {
                case 0:
                    Col = classDataGridView.Columns[0];
                    break;
                case 1:
                    Col = classDataGridView.Columns[1];
                    break;
                case 2:
                    Col = classDataGridView.Columns[2];
                    break;
            }
            if (this.radioButton1.Checked == true)
                this.classDataGridView.Sort(Col, ListSortDirection.Ascending);
            else
                this.classDataGridView.Sort(Col, ListSortDirection.Descending);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.classBindingSource.Filter = "ФИО = '" + comboBox1.Text + "'";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            classBindingSource.Filter = "";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < classDataGridView.ColumnCount - 1; i++)
                for (int j = 0; j < classDataGridView.RowCount - 1; j++)
                {
                    classDataGridView[i, j].Style.BackColor = Color.White;
                    classDataGridView[i, j].Style.ForeColor = Color.Black;
                }
            for (int i = 0; i < classDataGridView.ColumnCount - 1; i++)
                for (int j = 0; j < classDataGridView.RowCount - 1; j++)
                    if (0 == String.Compare(classDataGridView[i, j].Value.ToString(), textBox1.Text))
                    {
                        classDataGridView[i, j].Style.BackColor = Color.AliceBlue;
                        classDataGridView[i, j].Style.ForeColor = Color.Blue;
                    }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void listBox1_SelectedIndexChanged_1(object sender, EventArgs e)
        {

        }
    }
}
