#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 0x100
int main()
{
 int len;
 char buf[BUFFER_SIZE];
 int i=1; 
 char sep [10]=" ";
 char *istr;
 while(fgets(buf,100,stdin)!=0)
 {
 if(buf[0]=='t'){}else{
 istr = strtok (buf,sep);
 for (int i=0;i<8;i++)
   {
      istr = strtok (NULL,sep);
   }
 if(buf[0]=='d'){
 write(2, istr, strlen(istr));
 }else{
    write(1, istr, strlen(istr));
   
   }
   i++;
 }
 }
}
