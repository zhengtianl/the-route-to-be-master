#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_function(void *arg) {
  printf("hello, world\n");
  sleep(10);
}

int main() {
  pthread_t thread;

  pthread_create(&thread, NULL, thread_function, NULL);
  pthread_join(thread, NULL);
} 
