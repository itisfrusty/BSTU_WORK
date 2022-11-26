#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 0x100
char *my_itoa(int num, char *str)
{
        if(str == NULL)
        {
                return NULL;
        }
        sprintf(str, "%d", num);
        return str;
}
int main()
{
int  fp1,fp2;
 int len;
 char buf[BUFFER_SIZE];
 char temp[BUFFER_SIZE];
 char space[]="   ";
 char ends[]="\n";
 int i=1; 
 char sep [10]=" ";
 char *istr;
 fp1 = open("files.txt", O_WRONLY | O_CREAT, 0666);
 fp2 = open("catalogs.txt", O_WRONLY | O_CREAT, 0666);
/*fp1 = fopen("files.txt", "w");
fp2= fopen("catalogs.txt", "w");*/
 while(fgets(buf,100,stdin)!=0)
 {
 if(buf[0]=='t'){
 i--;
 }else{
 istr = strtok (buf,sep);
 for (int i=0;i<8;i++)
   {
      istr = strtok (NULL,sep);
   }
 my_itoa(i,temp);
 strncat (temp, space,BUFFER_SIZE);
 strncat (temp, istr,BUFFER_SIZE);
 if(buf[0]=='d'){
 write(fp2, temp, strlen(temp));
 }else{
 
   write(fp1, temp, strlen(temp));
   
   
   }
   i++;
   }
 }
 close(fp1);
 close(fp2);
}
