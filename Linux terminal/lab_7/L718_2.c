#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <math.h>

int main(){
	char name1[]="/s1";
	char name2[]="/s2";
	char nk1[]="/k1";
	char nk2[]="/k2";
	int kat1=0,kat2=0,g1=0,g2=0,gg=0;
	float gip=0;
	sem_t *s1 = sem_open(name1, O_CREAT, 0777, 0);
	sem_t *s2 = sem_open(name2, O_CREAT, 0777, 0);
	sem_t *k1 = sem_open(nk1, O_CREAT, 0777, 0);
	sem_t *k2 = sem_open(nk2, O_CREAT, 0777, 0);
	
	sem_init(s2,1, 0);
	
	while(1){
	
		sem_wait(s2);
		sem_getvalue(k1,&kat1);
		sem_getvalue(k2,&kat2);
		printf("Катет 1 - %d\n",kat1);
		printf("Катет 2 - %d\n",kat2);
		gip=sqrt(kat1*kat1+kat2*kat2);
		gg=gip*100;
		g1=gg/100;
		g2=gg%100;
		printf("Гипотенуза - %f\n",gip);
		/*printf("- %f\n",gip);
		printf(" - %d\n",g1);
		printf(" - %d\n",g2);*/
		for(int i=0;i<(kat1);i++){
			sem_wait(k1);
		}
		for(int i=0;i<(kat2);i++){
			sem_wait(k2);
		}
		for(int i=0;i<(g1);i++){
			sem_post(k1);
		}
		for(int i=0;i<(g2);i++){
			sem_post(k2);
		}
		sleep(2);
		sem_post(s1);
	}
	sem_close(s1);
	sem_close(s2);
	sem_close(k1);
	sem_close(k2);
	return 0;
}
