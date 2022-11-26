<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="lab_7_test.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Лабораторная работа No.7</title>
    <style type="text/css">
        .auto-style1 {
            font-size: large;
        }
        .новыйСтиль1 {
            font-family: Bahnschrift;
        }
        .новыйСтиль2 {
            font-family: Bahnschrift;
        }
        .новыйСтиль3 {
            font-family: Bahnschrift;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div class="auto-style1" style="text-align: center">
            <span class="новыйСтиль1">Лабораторная работа No.7<br />
            &quot;Создание Web-приложения для работы с БД&quot;</span></div>
        Таблица &quot;Класс&quot;<asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="Класс" DataSourceID="SqlDataSource1" EmptyDataText="Нет записей для отображения." ForeColor="#333333" GridLines="None" style="text-align: center" Width="725px">
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
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:masterConnectionString %>" DeleteCommand="DELETE FROM [Class_] WHERE [Класс] = @Класс" InsertCommand="INSERT INTO [Class_] ([Класс], [Предмет], [Часов_в_неделю]) VALUES (@Класс, @Предмет, @Часов_в_неделю)" ProviderName="<%$ ConnectionStrings:masterConnectionString.ProviderName %>" SelectCommand="SELECT [Класс], [Предмет], [Часов_в_неделю] FROM [Class_]" UpdateCommand="UPDATE [Class_] SET [Предмет] = @Предмет, [Часов_в_неделю] = @Часов_в_неделю WHERE [Класс] = @Класс">
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
    </form>
</body>
</html>
