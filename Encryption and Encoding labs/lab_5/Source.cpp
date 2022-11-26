#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    char fname[15]; //имя файла
    char key[10]; //шифр
    char ALF[67]; //русский алфавит

    /*инициализируем алфавит*/
    for (size_t i = 0; i < 6; i++)
    {
        ALF[i] = i + 192;
        ALF[i + 33] = i + 224;
    }
    for (size_t i = 7; i < 33; i++)
    {
        ALF[i] = i + 191;
        ALF[i + 33] = i + 223;
    }
    ALF[6] = 'Ё';
    ALF[39] = 'ё';

    /*Вводим имя файла, который нужно зашифровать*/
    printf("Enter filename: ");
    scanf("%s15", fname);
    FILE* fp = fopen(fname, "r");

    /*определяем имя зашифрованного файла*/
    for (size_t i = strlen(fname); i--;)
        if (fname[i] == '.')
        {
            fname[i] = '\0';
            strcat(fname, "(S).txt");
            break;
        }

    FILE* fp1 = fopen(fname, "w"); //создаём шифрованный файл
    printf("Enter Key: ");
    scanf("%s20", key); //вводим ключ
    int c = 0, //считанный символ
        i = 0, j = 0, k = 0;
    int code = 0;

    while ((c = fgetc(fp)) != EOF) //считываем символы, пока не обнаружится конец файла
    {
        j = 0;
        /*определяем входит ли символ в русский алфавит
        если j = -1, то входит*/
        while (ALF[j] != '\0')
        {
            if (ALF[j] == (char)c)
            {
                j = -1;
                break;
            }
            j++;
        }

        if (j == -1) //если символ является буквой русского алфавита
        {
            j = k = 0;
            while ((char)c != ALF[j]) //пока считаный символ не будет найден в алфавите
                j++; // j - номер символа в русском алфавите
            while (key[i] != ALF[k]) //пока символ из ключа не будет найден в алфавите
                k++; // k - номер i-го символа ключа в алфавите
            code = j + k; //результирующий символ
            if (code > 66) //если код больше длины алфавита начинаем сначала
                code -= 66;
            fprintf(fp1, "%c", ALF[code - 1]);
        }
        else fprintf(fp1, "%c", c);
        /*проверка чтобы под символом переноса строки не подписывался ключ*/

        if (c != 10)
        {
            if (key[i + 1] != '\0')
                i++;
            else if (key[i + 1] == '\0')
                i = 0;
        }
    }
    system("pause");
}
