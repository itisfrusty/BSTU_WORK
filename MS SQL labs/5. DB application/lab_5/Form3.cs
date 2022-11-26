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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void class_for_teacherBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.class_for_teacherBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.masterDataSet);

        }

        private void Form3_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "masterDataSet.Class_for_teacher". При необходимости она может быть перемещена или удалена.
            this.class_for_teacherTableAdapter.Fill(this.masterDataSet.Class_for_teacher);

        }

        private void классLabel_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form6 Fr6 = new Form6();
            Fr6.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form9 Fr9 = new Form9();
            Fr9.Show();
        }
    }
}
