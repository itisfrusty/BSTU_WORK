
namespace lab_5
{
    partial class Form3
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.Label классLabel;
            System.Windows.Forms.Label букваLabel;
            System.Windows.Forms.Label предметLabel;
            System.Windows.Forms.Label номер_учителяLabel;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form3));
            this.label1 = new System.Windows.Forms.Label();
            this.masterDataSet = new lab_5.masterDataSet();
            this.class_for_teacherBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.class_for_teacherTableAdapter = new lab_5.masterDataSetTableAdapters.Class_for_teacherTableAdapter();
            this.tableAdapterManager = new lab_5.masterDataSetTableAdapters.TableAdapterManager();
            this.class_for_teacherBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
            this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
            this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
            this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.class_for_teacherBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
            this.классTextBox = new System.Windows.Forms.TextBox();
            this.букваTextBox = new System.Windows.Forms.TextBox();
            this.предметTextBox = new System.Windows.Forms.TextBox();
            this.номер_учителяTextBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            классLabel = new System.Windows.Forms.Label();
            букваLabel = new System.Windows.Forms.Label();
            предметLabel = new System.Windows.Forms.Label();
            номер_учителяLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.masterDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.class_for_teacherBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.class_for_teacherBindingNavigator)).BeginInit();
            this.class_for_teacherBindingNavigator.SuspendLayout();
            this.SuspendLayout();
            // 
            // классLabel
            // 
            классLabel.AutoSize = true;
            классLabel.Font = new System.Drawing.Font("Times New Roman", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            классLabel.Location = new System.Drawing.Point(219, 137);
            классLabel.Name = "классLabel";
            классLabel.Size = new System.Drawing.Size(92, 33);
            классLabel.TabIndex = 2;
            классLabel.Text = "Класс:";
            классLabel.Click += new System.EventHandler(this.классLabel_Click);
            // 
            // букваLabel
            // 
            букваLabel.AutoSize = true;
            букваLabel.Font = new System.Drawing.Font("Times New Roman", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            букваLabel.Location = new System.Drawing.Point(221, 196);
            букваLabel.Name = "букваLabel";
            букваLabel.Size = new System.Drawing.Size(90, 33);
            букваLabel.TabIndex = 4;
            букваLabel.Text = "Буква:";
            // 
            // предметLabel
            // 
            предметLabel.AutoSize = true;
            предметLabel.Font = new System.Drawing.Font("Times New Roman", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            предметLabel.Location = new System.Drawing.Point(187, 261);
            предметLabel.Name = "предметLabel";
            предметLabel.Size = new System.Drawing.Size(124, 33);
            предметLabel.TabIndex = 6;
            предметLabel.Text = "Предмет:";
            // 
            // номер_учителяLabel
            // 
            номер_учителяLabel.AutoSize = true;
            номер_учителяLabel.Font = new System.Drawing.Font("Times New Roman", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            номер_учителяLabel.Location = new System.Drawing.Point(112, 322);
            номер_учителяLabel.Name = "номер_учителяLabel";
            номер_учителяLabel.Size = new System.Drawing.Size(199, 33);
            номер_учителяLabel.TabIndex = 8;
            номер_учителяLabel.Text = "Номер учителя:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(86, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(607, 57);
            this.label1.TabIndex = 0;
            this.label1.Text = "Таблица \"Класс-Учитель\"";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // masterDataSet
            // 
            this.masterDataSet.DataSetName = "masterDataSet";
            this.masterDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // class_for_teacherBindingSource
            // 
            this.class_for_teacherBindingSource.DataMember = "Class_for_teacher";
            this.class_for_teacherBindingSource.DataSource = this.masterDataSet;
            // 
            // class_for_teacherTableAdapter
            // 
            this.class_for_teacherTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.Class_for_teacherTableAdapter = this.class_for_teacherTableAdapter;
            this.tableAdapterManager.ClassTableAdapter = null;
            this.tableAdapterManager.TeacherTableAdapter = null;
            this.tableAdapterManager.UpdateOrder = lab_5.masterDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // class_for_teacherBindingNavigator
            // 
            this.class_for_teacherBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
            this.class_for_teacherBindingNavigator.BindingSource = this.class_for_teacherBindingSource;
            this.class_for_teacherBindingNavigator.CountItem = this.bindingNavigatorCountItem;
            this.class_for_teacherBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
            this.class_for_teacherBindingNavigator.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.class_for_teacherBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem,
            this.class_for_teacherBindingNavigatorSaveItem});
            this.class_for_teacherBindingNavigator.Location = new System.Drawing.Point(0, 0);
            this.class_for_teacherBindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
            this.class_for_teacherBindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
            this.class_for_teacherBindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
            this.class_for_teacherBindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
            this.class_for_teacherBindingNavigator.Name = "class_for_teacherBindingNavigator";
            this.class_for_teacherBindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
            this.class_for_teacherBindingNavigator.Size = new System.Drawing.Size(750, 27);
            this.class_for_teacherBindingNavigator.TabIndex = 1;
            this.class_for_teacherBindingNavigator.Text = "bindingNavigator1";
            // 
            // bindingNavigatorAddNewItem
            // 
            this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
            this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
            this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(29, 24);
            this.bindingNavigatorAddNewItem.Text = "Добавить";
            // 
            // bindingNavigatorCountItem
            // 
            this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
            this.bindingNavigatorCountItem.Size = new System.Drawing.Size(55, 24);
            this.bindingNavigatorCountItem.Text = "для {0}";
            this.bindingNavigatorCountItem.ToolTipText = "Общее число элементов";
            // 
            // bindingNavigatorDeleteItem
            // 
            this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
            this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
            this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(29, 24);
            this.bindingNavigatorDeleteItem.Text = "Удалить";
            // 
            // bindingNavigatorMoveFirstItem
            // 
            this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
            this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
            this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(29, 24);
            this.bindingNavigatorMoveFirstItem.Text = "Переместить в начало";
            // 
            // bindingNavigatorMovePreviousItem
            // 
            this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
            this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
            this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(29, 24);
            this.bindingNavigatorMovePreviousItem.Text = "Переместить назад";
            // 
            // bindingNavigatorSeparator
            // 
            this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 27);
            // 
            // bindingNavigatorPositionItem
            // 
            this.bindingNavigatorPositionItem.AccessibleName = "Положение";
            this.bindingNavigatorPositionItem.AutoSize = false;
            this.bindingNavigatorPositionItem.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
            this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 27);
            this.bindingNavigatorPositionItem.Text = "0";
            this.bindingNavigatorPositionItem.ToolTipText = "Текущее положение";
            // 
            // bindingNavigatorSeparator1
            // 
            this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1";
            this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 27);
            // 
            // bindingNavigatorMoveNextItem
            // 
            this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
            this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
            this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(29, 24);
            this.bindingNavigatorMoveNextItem.Text = "Переместить вперед";
            // 
            // bindingNavigatorMoveLastItem
            // 
            this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
            this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
            this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(29, 24);
            this.bindingNavigatorMoveLastItem.Text = "Переместить в конец";
            // 
            // bindingNavigatorSeparator2
            // 
            this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2";
            this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 27);
            // 
            // class_for_teacherBindingNavigatorSaveItem
            // 
            this.class_for_teacherBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.class_for_teacherBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("class_for_teacherBindingNavigatorSaveItem.Image")));
            this.class_for_teacherBindingNavigatorSaveItem.Name = "class_for_teacherBindingNavigatorSaveItem";
            this.class_for_teacherBindingNavigatorSaveItem.Size = new System.Drawing.Size(29, 24);
            this.class_for_teacherBindingNavigatorSaveItem.Text = "Сохранить данные";
            this.class_for_teacherBindingNavigatorSaveItem.Click += new System.EventHandler(this.class_for_teacherBindingNavigatorSaveItem_Click);
            // 
            // классTextBox
            // 
            this.классTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.class_for_teacherBindingSource, "Класс", true));
            this.классTextBox.Location = new System.Drawing.Point(330, 145);
            this.классTextBox.Name = "классTextBox";
            this.классTextBox.Size = new System.Drawing.Size(336, 22);
            this.классTextBox.TabIndex = 3;
            // 
            // букваTextBox
            // 
            this.букваTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.class_for_teacherBindingSource, "Буква", true));
            this.букваTextBox.Location = new System.Drawing.Point(330, 204);
            this.букваTextBox.Name = "букваTextBox";
            this.букваTextBox.Size = new System.Drawing.Size(336, 22);
            this.букваTextBox.TabIndex = 5;
            // 
            // предметTextBox
            // 
            this.предметTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.class_for_teacherBindingSource, "Предмет", true));
            this.предметTextBox.Location = new System.Drawing.Point(330, 269);
            this.предметTextBox.Name = "предметTextBox";
            this.предметTextBox.Size = new System.Drawing.Size(336, 22);
            this.предметTextBox.TabIndex = 7;
            // 
            // номер_учителяTextBox
            // 
            this.номер_учителяTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.class_for_teacherBindingSource, "Номер_учителя", true));
            this.номер_учителяTextBox.Location = new System.Drawing.Point(330, 330);
            this.номер_учителяTextBox.Name = "номер_учителяTextBox";
            this.номер_учителяTextBox.Size = new System.Drawing.Size(336, 22);
            this.номер_учителяTextBox.TabIndex = 9;
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Times New Roman", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button1.Location = new System.Drawing.Point(356, 379);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(131, 42);
            this.button1.TabIndex = 10;
            this.button1.Text = "Таблица";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Times New Roman", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button2.Location = new System.Drawing.Point(516, 379);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(128, 42);
            this.button2.TabIndex = 11;
            this.button2.Text = "Отчёт";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(750, 453);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(номер_учителяLabel);
            this.Controls.Add(this.номер_учителяTextBox);
            this.Controls.Add(предметLabel);
            this.Controls.Add(this.предметTextBox);
            this.Controls.Add(букваLabel);
            this.Controls.Add(this.букваTextBox);
            this.Controls.Add(классLabel);
            this.Controls.Add(this.классTextBox);
            this.Controls.Add(this.class_for_teacherBindingNavigator);
            this.Controls.Add(this.label1);
            this.Name = "Form3";
            this.Text = "Таблица \"Класс-Учитель\"";
            this.Load += new System.EventHandler(this.Form3_Load);
            ((System.ComponentModel.ISupportInitialize)(this.masterDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.class_for_teacherBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.class_for_teacherBindingNavigator)).EndInit();
            this.class_for_teacherBindingNavigator.ResumeLayout(false);
            this.class_for_teacherBindingNavigator.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private masterDataSet masterDataSet;
        private System.Windows.Forms.BindingSource class_for_teacherBindingSource;
        private masterDataSetTableAdapters.Class_for_teacherTableAdapter class_for_teacherTableAdapter;
        private masterDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.BindingNavigator class_for_teacherBindingNavigator;
        private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
        private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
        private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
        private System.Windows.Forms.ToolStripButton class_for_teacherBindingNavigatorSaveItem;
        private System.Windows.Forms.TextBox классTextBox;
        private System.Windows.Forms.TextBox букваTextBox;
        private System.Windows.Forms.TextBox предметTextBox;
        private System.Windows.Forms.TextBox номер_учителяTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}