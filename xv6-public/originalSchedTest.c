#include "types.h"
#include "stat.h"
#include "user.h"

struct timeVariables {
  int creationTime;
  int terminationTime;
  int sleepingTime;
  int readyTime;
  int runningTime;
};

int main(){
  /*int i1 = fork();
  int i2 = fork();
  int i3 = fork();
  int i4 = fork();
  int i5 = fork();
  int i6 = fork();
  int i7 = fork();
  int i8 = fork();
  int i9 = fork();
  int i10 = fork();

  for(int i=0;i<1000;i++)
  	printf(1, "|%d| : |%d|\n",getpid(),i);

  if(i1 > 0 || i2 > 0 || i3 > 0 || i4 > 0 || i5 > 0 || i6 > 0 || i7 > 0 || i8 > 0 || i9 > 0 || i10 > 0){
  struct timeVariables *t;
  t = malloc(sizeof(struct timeVariables));
  int childpid = waitForChild(t);
  if(childpid != (-1)){
	printf(1, "pid : %d, Turnaround time = %d, CBT = %d, Waiting time = %d\n", childpid, t->terminationTime - t->creationTime,t->runningTime,t->readyTime);
  }
  }
  exit();*/
  changePolicy(1);
  for(int i=0;i<10;i++){
	int pid = fork();
	for(int i=0;i<1000;i++)
  		printf(1, "|%d| : |%d|\n",getpid(),i);
	if(pid > 0){
		struct timeVariables *t;
  		t = malloc(sizeof(struct timeVariables));
  		int childpid = waitForChild(t);
		if(childpid != (-1)){
		printf(1, "pid : %d, Turnaround time = %d, CBT = %d, Waiting time = %d\n", childpid, t->terminationTime - t->creationTime,t->runningTime,t->readyTime);
		exit();
		}
	}
  }
  exit();
  return 0;
}
