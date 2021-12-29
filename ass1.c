
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void * chield(void * param){
	int id= (int)param;
	printf("thread %i\n",id);
	return (void*)id;
}
int main(void) {
	pthread_t thread[5];
	int r_v[5];
for(int i=0;i<5;i++){
	pthread_create(&thread[i], 0, &chield,(void*)(rand()%10));
}
for(int i=0;i<5;i++){
	pthread_join(thread[i],(void**)&r_v[i]);
	printf("thread %i\n",r_v[i]);
}
}
