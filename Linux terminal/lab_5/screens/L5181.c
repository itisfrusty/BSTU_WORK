#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 0x100
int main()
{
 char buf[BUFFER_SIZE];
 char temp;
 int fp1;
 int k=0;
 int  asd=1,end;
 char sep [10]=" ";
 char *istr;
 while(asd){
 end=read(0, &temp, 1);
 buf[k++]=temp;
 if(end==0){
 	asd--;
 	break;
 }
 if(temp=='\n'){
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
 }
 k=0;
 memset(buf, 0, sizeof(buf));
 
 }

 
 }
}
