#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	int pid, p1[2], p2[2], nbytes;
	if(pipe(p1) < 0)
		exit(1);
	if(pipe(p2) < 0)
		exit(1);
	pid = fork();	
	if(pid > 0){
		close(p1[0]);
		char res[50];
		int number;
		printf("Enter number : ");
		fflush(stdout);	
		scanf("%d", &number);
		write(p1[1], &number, sizeof(number));
		close(p1[1]);		
		wait(NULL);
		close(p2[1]);
		read(p2[0], res, 50);
		close(p2[0]);		
		printf("%d %s", number, res); 
	}
	else if(pid == 0){
		close(p1[1]);		
		int received_num, sum = 0;
		read(p1[0], &received_num, sizeof(received_num));		
		while(received_num != 0){
			if((received_num % 10) % 2 == 0)
				sum += received_num % 10;
			received_num /= 10;
		}
		char msg[43] = "The sum of even digits in the input number:";
		int strsize = 43,tmp = 1;		
		while(sum / tmp != 0)
			tmp *= 10;
		if(tmp != 1)
			tmp /= 10;
		while(tmp != 0){
			msg[strsize] = (sum / tmp) + 48;
			strsize++;
			sum = sum % tmp;
			tmp /= 10;
		}
		msg[strsize] = '\0';
		close(p1[0]);
		close(p2[0]);
		write(p2[1], msg, strlen(msg)+1);
		close(p2[1]);
		exit(0);
	}
	else{
		printf("couldn't create child process");
	}
	return 0;
}
