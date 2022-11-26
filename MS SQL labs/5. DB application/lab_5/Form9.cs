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
    public partial class Form9 : Form
    {
        public Form9()
        {
            InitializeComponent();
        }

        private void Form9_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "masterDataSet.Class_for_teacher". При необходимости она может быть перемещена или удалена.
            this.Class_for_teacherTableAdapter.Fill(this.masterDataSet.Class_for_teacher);

            this.reportViewer1.RefreshReport();
        }
    }
}
