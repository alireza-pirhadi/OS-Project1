#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
	int pid1 = fork();
	int pid2 = fork();
	if(pid1 == 0 && pid2 == 0){	
	printf(1,"pid : %d\n", getpid());
	printf(1,"	ppid : %d\n", getppid());
	printf(1,"	childrens : %d\n\n", getChildren(getppid()));
	exit();	
	}
	else{
	wait();
	printf(1,"pid : %d\n", getpid());
	printf(1,"	ppid : %d\n", getppid());
	printf(1,"	childrens : %d\n\n", getChildren(getppid()));
	exit();
	}
}
