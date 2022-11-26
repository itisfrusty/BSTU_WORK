#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main(){
	char name1[]="/s1";
	char name2[]="/s2";
	char nk1[]="/k1";
	char nk2[]="/k2";
	int vk1=0,vk2=0,gip=0;
	sem_t *s1 = sem_open(name1, O_CREAT, 0777, 0);
	sem_t *s2 = sem_open(name2, O_CREAT, 0777, 0);
	sem_t *k1 = sem_open(nk1, O_CREAT, 0777, 0);
	sem_t *k2 = sem_open(nk2, O_CREAT, 0777, 0);
	sem_init(s1,1, 0);
	sem_init(k1,1, 0);sem_init(k2,1, 0);
	sem_post(s1);
	while(1)
	{
	
		sem_wait(s1);
		
		vk1 = (random() % 20)+1;
		vk2 = (random() % 20)+1;
		for(int i=0;i<(vk1);i++){
			sem_post(k1);
		}
		for(int i=0;i<(vk2);i++){
			sem_post(k2);
		}
		printf("Катет 1 передан - %d\n",vk1);
		printf("Катет 2 передан - %d\n",vk2);
		sem_post(s2);
		sem_wait(s1);
		sem_getvalue(k1,&vk1);
		sem_getvalue(k2,&vk2);
		if(vk2<10){
		printf("Гипотенуза - %d.0%d\n",vk1,vk2);
		}else{
		printf("Гипотенуза - %d.%d\n",vk1,vk2);
		}
		for(int i=0;i<(vk1);i++){
			sem_wait(k1);
		}
		for(int i=0;i<(vk2);i++){
			sem_wait(k2);
		}
		sem_post(s1);
	}
	sem_close(s1);
	sem_close(s2);
	sem_close(k1);
	sem_close(k2);
	return 0;

}
