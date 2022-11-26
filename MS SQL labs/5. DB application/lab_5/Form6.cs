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
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            button1.Enabled = true;
        }

        private void class_for_teacherBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.class_for_teacherBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.masterDataSet);

        }

        private void Form6_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "masterDataSet.Class_for_teacher". При необходимости она может быть перемещена или удалена.
            this.class_for_teacherTableAdapter.Fill(this.masterDataSet.Class_for_teacher);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            DataGridViewColumn Col = class_for_teacherDataGridView.Columns[0];

            switch (listBox1.SelectedIndex)
            {
                case 0:
                    Col = class_for_teacherDataGridView.Columns[0];
                    break;
                case 1:
                    Col = class_for_teacherDataGridView.Columns[1];
                    break;
                case 2:
                    Col = class_for_teacherDataGridView.Columns[2];
                    break;
                case 4:
                    Col = class_for_teacherDataGridView.Columns[3];
                    break;
            }
            if (this.radioButton1.Checked == true)
                this.class_for_teacherDataGridView.Sort(Col, ListSortDirection.Ascending);
            else
                this.class_for_teacherDataGridView.Sort(Col, ListSortDirection.Descending);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.class_for_teacherBindingSource.Filter = "Предмет = '" + comboBox1.Text + "'";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            class_for_teacherBindingSource.Filter = "";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < class_for_teacherDataGridView.ColumnCount - 1; i++)
                for (int j = 0; j < class_for_teacherDataGridView.RowCount - 1; j++)
                {
                    class_for_teacherDataGridView[i, j].Style.BackColor = Color.White;
                    class_for_teacherDataGridView[i, j].Style.ForeColor = Color.Black;
                }
            for (int i = 0; i < class_for_teacherDataGridView.ColumnCount - 1; i++)
                for (int j = 0; j < class_for_teacherDataGridView.RowCount - 1; j++)
                    if (0 == String.Compare(class_for_teacherDataGridView[i, j].Value.ToString(), textBox1.Text))
                    {
                        class_for_teacherDataGridView[i, j].Style.BackColor = Color.AliceBlue;
                        class_for_teacherDataGridView[i, j].Style.ForeColor = Color.Blue;
                    }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
