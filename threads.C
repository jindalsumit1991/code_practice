#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>
#include <atomic>

using namespace std;

#define NUM_THREADS 5

static atomic_int sid;
void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   int id=1;
   while(id<=5) {
      cout << "\nHello World! Thread ID, " << tid <<", SID : " <<tid<<"-"<<sid<<endl;
      //sleep(1);
      id++;
      sid++;
   }
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;

   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   int rc;
   int i;

   for( i=0; i < NUM_THREADS; i++ ){
      cout << "\nmain() : creating thread : "<<i<<endl;
      rc = pthread_create(&threads[i], &attr, PrintHello, (void *)(intptr_t)i);
      //rc = pthread_create(&threads, &attr, PrintHello, (void *)(intptr_t)i);

      if (rc){
	 cout << "Error:unable to create thread," << rc << endl;
	 exit(-1);
      }
   }
   cout<<"\nMain Thread is done..\n\n";
   pthread_attr_destroy(&attr);
   //pthread_detach (threads);
   for( i=0; i < NUM_THREADS; i++ ) {
      pthread_join(threads[i], &status);
      cout << "Main: completed thread id :" << i <<endl;
   }

   pthread_exit(NULL);
}
