<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="lab_7.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Лабораторная работа No.7</title>
    <style type="text/css">
        .auto-style1 {
            text-align: center;
        }
 p.MsoNormal
	{margin-top:0cm;
	margin-right:0cm;
	margin-bottom:10.0pt;
	margin-left:0cm;
	line-height:115%;
	font-size:11.0pt;
	font-family:"Calibri",sans-serif;
	}
        .новыйСтиль1 {
            font-family: Bahnschrift;
        }
        .новыйСтиль2 {
            font-family: Bahnschrift;
        }
        .auto-style2 {
            font-size: large;
        }
        .новыйСтиль3 {
            font-family: Bahnschrift;
            font-size: medium;
        }
        .новыйСтиль4 {
            font-family: Bahnschrift;
        }
        .новыйСтиль5 {
            font-family: Bahnschrift;
            font-size: medium;
        }
        .новыйСтиль6 {
            font-family: Bahnschrift;
            font-size: medium;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div class="auto-style1">
            <span class="новыйСтиль1"><span class="auto-style2">Лабораторная работа No.7</span><br class="auto-style2" />
            <span class="auto-style2">Создание Web-приложения для работы с БД</span></span></div>
        <span class="новыйСтиль3">Таблица &quot;Класс&quot;<br />
        </span>
        <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="Класс" DataSourceID="SqlDataSource1" EmptyDataText="Нет записей для отображения." ForeColor="#333333" GridLines="None" style="text-align: center" Width="661px">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" ShowSelectButton="True" />
                <asp:BoundField DataField="Класс" HeaderText="Класс" ReadOnly="True" SortExpression="Класс" />
                <asp:BoundField DataField="Предмет" HeaderText="Предмет" SortExpression="Предмет" />
                <asp:BoundField DataField="Часов_в_неделю" HeaderText="Часов_в_неделю" SortExpression="Часов_в_неделю" />
            </Columns>
            <EditRowStyle BackColor="#7C6F57" />
            <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#E3EAEB" />
            <SelectedRowStyle BackColor="#C5BBAF" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#F8FAFA" />
            <SortedAscendingHeaderStyle BackColor="#246B61" />
            <SortedDescendingCellStyle BackColor="#D4DFE1" />
            <SortedDescendingHeaderStyle BackColor="#15524A" />
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:lab_7ConnectionString1 %>" DeleteCommand="DELETE FROM [Класс] WHERE [Класс] = @Класс" InsertCommand="INSERT INTO [Класс] ([Класс], [Предмет], [Часов_в_неделю]) VALUES (@Класс, @Предмет, @Часов_в_неделю)" ProviderName="<%$ ConnectionStrings:lab_7ConnectionString1.ProviderName %>" SelectCommand="SELECT [Класс], [Предмет], [Часов_в_неделю] FROM [Класс]" UpdateCommand="UPDATE [Класс] SET [Предмет] = @Предмет, [Часов_в_неделю] = @Часов_в_неделю WHERE [Класс] = @Класс">
            <DeleteParameters>
                <asp:Parameter Name="Класс" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="Класс" Type="Int32" />
                <asp:Parameter Name="Предмет" Type="String" />
                <asp:Parameter Name="Часов_в_неделю" Type="Int32" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="Предмет" Type="String" />
                <asp:Parameter Name="Часов_в_неделю" Type="Int32" />
                <asp:Parameter Name="Класс" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
        <br />
        <span class="новыйСтиль6">Таблица &quot;Класс-Учитель&quot;<br />
        </span>
        <asp:GridView ID="GridView2" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="Класс" DataSourceID="SqlDataSource2" EmptyDataText="Нет записей для отображения." ForeColor="#333333" GridLines="None" style="text-align: center" Width="698px">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" ShowSelectButton="True" />
                <asp:BoundField DataField="Класс" HeaderText="Класс" ReadOnly="True" SortExpression="Класс" />
                <asp:BoundField DataField="Буква" HeaderText="Буква" SortExpression="Буква" />
                <asp:BoundField DataField="Предмет" HeaderText="Предмет" SortExpression="Предмет" />
                <asp:BoundField DataField="Номер_учителя" HeaderText="Номер_учителя" SortExpression="Номер_учителя" />
            </Columns>
            <EditRowStyle BackColor="#7C6F57" />
            <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#E3EAEB" />
            <SelectedRowStyle BackColor="#C5BBAF" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#F8FAFA" />
            <SortedAscendingHeaderStyle BackColor="#246B61" />
            <SortedDescendingCellStyle BackColor="#D4DFE1" />
            <SortedDescendingHeaderStyle BackColor="#15524A" />
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:lab_7ConnectionString1 %>" DeleteCommand="DELETE FROM [Класс_Учитель] WHERE [Класс] = @Класс" InsertCommand="INSERT INTO [Класс_Учитель] ([Класс], [Буква], [Предмет], [Номер_учителя]) VALUES (@Класс, @Буква, @Предмет, @Номер_учителя)" ProviderName="<%$ ConnectionStrings:lab_7ConnectionString1.ProviderName %>" SelectCommand="SELECT [Класс], [Буква], [Предмет], [Номер_учителя] FROM [Класс_Учитель]" UpdateCommand="UPDATE [Класс_Учитель] SET [Буква] = @Буква, [Предмет] = @Предмет, [Номер_учителя] = @Номер_учителя WHERE [Класс] = @Класс">
            <DeleteParameters>
                <asp:Parameter Name="Класс" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="Класс" Type="Int32" />
                <asp:Parameter Name="Буква" Type="String" />
                <asp:Parameter Name="Предмет" Type="String" />
                <asp:Parameter Name="Номер_учителя" Type="Int32" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="Буква" Type="String" />
                <asp:Parameter Name="Предмет" Type="String" />
                <asp:Parameter Name="Номер_учителя" Type="Int32" />
                <asp:Parameter Name="Класс" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
        <br />
        <span class="новыйСтиль5">Таблица &quot;Учитель&quot;<br />
        </span>
        <asp:GridView ID="GridView3" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="Номер_учителя" DataSourceID="SqlDataSource3" EmptyDataText="Нет записей для отображения." ForeColor="#333333" GridLines="None" style="text-align: center" Width="722px">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" ShowSelectButton="True" />
                <asp:BoundField DataField="Номер_учителя" HeaderText="Номер_учителя" ReadOnly="True" SortExpression="Номер_учителя" />
                <asp:BoundField DataField="ФИО" HeaderText="ФИО" SortExpression="ФИО" />
                <asp:BoundField DataField="Специальность" HeaderText="Специальность" SortExpression="Специальность" />
                <asp:BoundField DataField="Стаж" HeaderText="Стаж" SortExpression="Стаж" />
            </Columns>
            <EditRowStyle BackColor="#7C6F57" />
            <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#E3EAEB" />
            <SelectedRowStyle BackColor="#C5BBAF" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#F8FAFA" />
            <SortedAscendingHeaderStyle BackColor="#246B61" />
            <SortedDescendingCellStyle BackColor="#D4DFE1" />
            <SortedDescendingHeaderStyle BackColor="#15524A" />
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:lab_7ConnectionString1 %>" DeleteCommand="DELETE FROM [Учитель] WHERE [Номер_учителя] = @Номер_учителя" InsertCommand="INSERT INTO [Учитель] ([Номер_учителя], [ФИО], [Специальность], [Стаж]) VALUES (@Номер_учителя, @ФИО, @Специальность, @Стаж)" ProviderName="<%$ ConnectionStrings:lab_7ConnectionString1.ProviderName %>" SelectCommand="SELECT [Номер_учителя], [ФИО], [Специальность], [Стаж] FROM [Учитель]" UpdateCommand="UPDATE [Учитель] SET [ФИО] = @ФИО, [Специальность] = @Специальность, [Стаж] = @Стаж WHERE [Номер_учителя] = @Номер_учителя">
            <DeleteParameters>
                <asp:Parameter Name="Номер_учителя" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="Номер_учителя" Type="Int32" />
                <asp:Parameter Name="ФИО" Type="String" />
                <asp:Parameter Name="Специальность" Type="String" />
                <asp:Parameter Name="Стаж" Type="Int32" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="ФИО" Type="String" />
                <asp:Parameter Name="Специальность" Type="String" />
                <asp:Parameter Name="Стаж" Type="Int32" />
                <asp:Parameter Name="Номер_учителя" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
        <br />
    </form>
</body>
</html>
