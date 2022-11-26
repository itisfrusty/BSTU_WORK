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
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void teacherBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.teacherBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.masterDataSet);

        }

        private void Form7_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "masterDataSet.Teacher". При необходимости она может быть перемещена или удалена.
            this.teacherTableAdapter.Fill(this.masterDataSet.Teacher);

        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            button1.Enabled = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DataGridViewColumn Col = teacherDataGridView.Columns[0];

            switch (listBox1.SelectedIndex)
            {
                case 0:
                    Col = teacherDataGridView.Columns[0];
                    break;
                case 1:
                    Col = teacherDataGridView.Columns[1];
                    break;
                case 2:
                    Col = teacherDataGridView.Columns[2];
                    break;
                case 4:
                    Col = teacherDataGridView.Columns[3];
                    break;
            }
            if (this.radioButton1.Checked == true)
                this.teacherDataGridView.Sort(Col, ListSortDirection.Ascending);
            else
                this.teacherDataGridView.Sort(Col, ListSortDirection.Descending);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.teacherBindingSource.Filter = "ФИО = '" + comboBox1.Text + "'";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            teacherBindingSource.Filter = "";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < teacherDataGridView.ColumnCount - 1; i++)
                for (int j = 0; j < teacherDataGridView.RowCount - 1; j++)
                {
                    teacherDataGridView[i, j].Style.BackColor = Color.White;
                    teacherDataGridView[i, j].Style.ForeColor = Color.Black;
                }
            for (int i = 0; i < teacherDataGridView.ColumnCount - 1; i++)
                for (int j = 0; j < teacherDataGridView.RowCount - 1; j++)
                    if (0 == String.Compare(teacherDataGridView[i, j].Value.ToString(), textBox1.Text))
                    {
                        teacherDataGridView[i, j].Style.BackColor = Color.AliceBlue;
                        teacherDataGridView[i, j].Style.ForeColor = Color.Blue;
                    }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void teacherBindingNavigator_RefreshItems(object sender, EventArgs e)
        {

        }
    }
}
