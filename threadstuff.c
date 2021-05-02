#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void * foofun(void * arg){
  printf("thread spawned on line\n");
  return NULL;
}


int main(int argc, char ** argv){
       FILE * file;
        if(argc <2){

		printf("pls enter a regular file path\n");
		return 0;
        }
        file = fopen(argv[1],"r");
	size_t size = 0;
        char * line = NULL;
        int threadid = 0;
        int ret = -1;
        pthread_t * thread;
        //spawn a thread per line in file:
        while(getline(&line,&size,file) >0){
          threadid++;
	  thread = malloc(sizeof(pthread_t)*threadid);
          ret = pthread_create(&thread[threadid],NULL,&foofun, NULL);
	  pthread_join(thread[threadid],NULL);
	}

free(line);
return 0;
}




