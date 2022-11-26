
namespace lab_5
{
    partial class Form2
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
            System.Windows.Forms.Label предметLabel;
            System.Windows.Forms.Label часов_в_неделюLabel;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form2));
            this.label1 = new System.Windows.Forms.Label();
            this.masterDataSet = new lab_5.masterDataSet();
            this.classBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.classTableAdapter = new lab_5.masterDataSetTableAdapters.ClassTableAdapter();
            this.tableAdapterManager = new lab_5.masterDataSetTableAdapters.TableAdapterManager();
            this.classBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
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
            this.classBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
            this.классTextBox = new System.Windows.Forms.TextBox();
            this.предметTextBox = new System.Windows.Forms.TextBox();
            this.часов_в_неделюTextBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            классLabel = new System.Windows.Forms.Label();
            предметLabel = new System.Windows.Forms.Label();
            часов_в_неделюLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.masterDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.classBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.classBindingNavigator)).BeginInit();
            this.classBindingNavigator.SuspendLayout();
            this.SuspendLayout();
            // 
            // классLabel
            // 
            классLabel.AutoSize = true;
            классLabel.Font = new System.Drawing.Font("Times New Roman", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            классLabel.Location = new System.Drawing.Point(212, 172);
            классLabel.Name = "классLabel";
            классLabel.Size = new System.Drawing.Size(92, 33);
            классLabel.TabIndex = 2;
            классLabel.Text = "Класс:";
            классLabel.Click += new System.EventHandler(this.классLabel_Click);
            // 
            // предметLabel
            // 
            предметLabel.AutoSize = true;
            предметLabel.Font = new System.Drawing.Font("Times New Roman", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            предметLabel.Location = new System.Drawing.Point(184, 240);
            предметLabel.Name = "предметLabel";
            предметLabel.Size = new System.Drawing.Size(124, 33);
            предметLabel.TabIndex = 4;
            предметLabel.Text = "Предмет:";
            // 
            // часов_в_неделюLabel
            // 
            часов_в_неделюLabel.AutoSize = true;
            часов_в_неделюLabel.Font = new System.Drawing.Font("Times New Roman", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            часов_в_неделюLabel.Location = new System.Drawing.Point(97, 312);
            часов_в_неделюLabel.Name = "часов_в_неделюLabel";
            часов_в_неделюLabel.Size = new System.Drawing.Size(207, 33);
            часов_в_неделюLabel.TabIndex = 6;
            часов_в_неделюLabel.Text = "Часов в неделю:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(192, 68);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(405, 57);
            this.label1.TabIndex = 0;
            this.label1.Text = "Таблица \"Класс\"";
            // 
            // masterDataSet
            // 
            this.masterDataSet.DataSetName = "masterDataSet";
            this.masterDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // classBindingSource
            // 
            this.classBindingSource.DataMember = "Class";
            this.classBindingSource.DataSource = this.masterDataSet;
            // 
            // classTableAdapter
            // 
            this.classTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.Class_for_teacherTableAdapter = null;
            this.tableAdapterManager.ClassTableAdapter = this.classTableAdapter;
            this.tableAdapterManager.TeacherTableAdapter = null;
            this.tableAdapterManager.UpdateOrder = lab_5.masterDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // classBindingNavigator
            // 
            this.classBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
            this.classBindingNavigator.BindingSource = this.classBindingSource;
            this.classBindingNavigator.CountItem = this.bindingNavigatorCountItem;
            this.classBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
            this.classBindingNavigator.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.classBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
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
            this.classBindingNavigatorSaveItem});
            this.classBindingNavigator.Location = new System.Drawing.Point(0, 0);
            this.classBindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
            this.classBindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
            this.classBindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
            this.classBindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
            this.classBindingNavigator.Name = "classBindingNavigator";
            this.classBindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
            this.classBindingNavigator.Size = new System.Drawing.Size(750, 27);
            this.classBindingNavigator.TabIndex = 1;
            this.classBindingNavigator.Text = "bindingNavigator1";
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
            // classBindingNavigatorSaveItem
            // 
            this.classBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.classBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("classBindingNavigatorSaveItem.Image")));
            this.classBindingNavigatorSaveItem.Name = "classBindingNavigatorSaveItem";
            this.classBindingNavigatorSaveItem.Size = new System.Drawing.Size(29, 24);
            this.classBindingNavigatorSaveItem.Text = "Сохранить данные";
            this.classBindingNavigatorSaveItem.Click += new System.EventHandler(this.classBindingNavigatorSaveItem_Click);
            // 
            // классTextBox
            // 
            this.классTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.classBindingSource, "Класс", true));
            this.классTextBox.Location = new System.Drawing.Point(321, 180);
            this.классTextBox.Name = "классTextBox";
            this.классTextBox.Size = new System.Drawing.Size(318, 22);
            this.классTextBox.TabIndex = 3;
            this.классTextBox.TextChanged += new System.EventHandler(this.классTextBox_TextChanged);
            // 
            // предметTextBox
            // 
            this.предметTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.classBindingSource, "Предмет", true));
            this.предметTextBox.Location = new System.Drawing.Point(321, 248);
            this.предметTextBox.Name = "предметTextBox";
            this.предметTextBox.Size = new System.Drawing.Size(318, 22);
            this.предметTextBox.TabIndex = 5;
            this.предметTextBox.TextChanged += new System.EventHandler(this.предметTextBox_TextChanged);
            // 
            // часов_в_неделюTextBox
            // 
            this.часов_в_неделюTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.classBindingSource, "Часов_в_неделю", true));
            this.часов_в_неделюTextBox.Location = new System.Drawing.Point(321, 320);
            this.часов_в_неделюTextBox.Name = "часов_в_неделюTextBox";
            this.часов_в_неделюTextBox.Size = new System.Drawing.Size(318, 22);
            this.часов_в_неделюTextBox.TabIndex = 7;
            this.часов_в_неделюTextBox.TextChanged += new System.EventHandler(this.часов_в_неделюTextBox_TextChanged);
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Times New Roman", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button1.Location = new System.Drawing.Point(342, 375);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(127, 42);
            this.button1.TabIndex = 8;
            this.button1.Text = "Таблица";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Times New Roman", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button2.Location = new System.Drawing.Point(490, 375);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(128, 42);
            this.button2.TabIndex = 9;
            this.button2.Text = "Отчёт";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(750, 453);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(часов_в_неделюLabel);
            this.Controls.Add(this.часов_в_неделюTextBox);
            this.Controls.Add(предметLabel);
            this.Controls.Add(this.предметTextBox);
            this.Controls.Add(классLabel);
            this.Controls.Add(this.классTextBox);
            this.Controls.Add(this.classBindingNavigator);
            this.Controls.Add(this.label1);
            this.Name = "Form2";
            this.Text = "Таблица \"Класс\"";
            this.Load += new System.EventHandler(this.Form2_Load);
            ((System.ComponentModel.ISupportInitialize)(this.masterDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.classBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.classBindingNavigator)).EndInit();
            this.classBindingNavigator.ResumeLayout(false);
            this.classBindingNavigator.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private masterDataSet masterDataSet;
        private System.Windows.Forms.BindingSource classBindingSource;
        private masterDataSetTableAdapters.ClassTableAdapter classTableAdapter;
        private masterDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.BindingNavigator classBindingNavigator;
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
        private System.Windows.Forms.ToolStripButton classBindingNavigatorSaveItem;
        private System.Windows.Forms.TextBox классTextBox;
        private System.Windows.Forms.TextBox предметTextBox;
        private System.Windows.Forms.TextBox часов_в_неделюTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}