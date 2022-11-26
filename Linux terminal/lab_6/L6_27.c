#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <mqueue.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define QUEUE_NAME  "/my_queueeee"
#define QUEUE_NAME1  "/my_queueee"

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
  pid_t pid;
  int rv;
  mqd_t mq,mqr,mqrr;
  int max=0,min=0;
  int random; /// Переменная хранит случайное число
  int size = sizeof(int);
  srand(time(NULL)); 
    struct mq_attr attr;
    struct mq_attr attrs;
    char buffer[size];
    char temp[8];
    int must_stop = 0;

    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(int);
    attr.mq_curmsgs = 0;
    
    
    
  mq_open( QUEUE_NAME, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG, &attr);
  mq_open( QUEUE_NAME1, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG, &attr);
  switch(pid=fork()) {
  case -1:
          perror("fork"); /* произошла ошибка */
          exit(1); /*выход из родительского процесса*/
  case 0:
  sleep(10);
          printf(" CHILD: Это процесс-потомок!\n");
          printf(" CHILD: Мой PID -- %d\n", getpid());
          printf(" CHILD: PID моего родителя -- %d\n",getppid());
          int temp[5];
          mqr = mq_open(QUEUE_NAME, O_RDONLY );
  		for(int i = 0; i < 5; i++){
  		
			mq_receive(mqr, buffer, size, NULL);
			temp[i]=atoi(buffer);
		printf(" CHILD: получено -- %d\n",temp[i]);	
		}
		int c;
		for(int i = 0; i < 4; i++){
		for(int j = i+1; j< 5; j++){
			if(temp[i]<temp[j]){
			c=temp[i];
			temp[i]=temp[j];
			temp[j]=c;
			}
		}}
		mq_close(mqr);
		printf(" CHILD: Наибольшее и наименьшее найдены!\n");
		
		/*for(int i = 0; i < 5; i++){
		printf(" CHILD: now -- %d\n",temp[i]);	
		}*/
		mqr = mq_open(QUEUE_NAME1, O_WRONLY);
		mq_send(mqr, my_itoa(temp[0], buffer), size, 0);
		
		mq_send(mqr, my_itoa(temp[4], buffer), size, 0);
		mq_close(mqr);
		printf(" CHILD: Отправлено!\n");
          printf(" CHILD: Выход!\n");
          exit(rv);
  default:
  		
          printf("PARENT: Это процесс-родитель!\n");
          printf("PARENT: Мой PID -- %d\n", getpid());
          printf("PARENT: PID моего потомка %d\n",pid);
          mqrr = mq_open(QUEUE_NAME, O_WRONLY);
  		for(int i = 0; i < 5; i++){
			random = 1 + rand() % 30;
			mq_send(mqrr, my_itoa(random, buffer), size, 0);
			printf("PARENT: передано число %d\n", random);
			sleep(1);
		}
		mq_close(mqrr);
          printf("PARENT: Я жду, пока потомокне вызовет exit()...\n");
          wait(&rv);
          mqr = mq_open(QUEUE_NAME1, O_RDONLY);
  		
  		
			
		
		mq_receive(mqr, buffer, size, NULL);
		printf("PARENT: наибольшее -- %d\n",atoi(buffer));
		mq_receive(mqr, buffer, size, NULL);
		printf("PARENT: наименьшее -- %d\n",atoi(buffer));
		mq_close(mqr);
          printf("PARENT: Выход!\n");
  }
  mq_close(mq);
  return 0;
}
