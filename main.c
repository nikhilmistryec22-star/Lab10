#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		// Fork failed
		perror("fork");
		return 1;
	}
	printf("Nikhil Mistry\n");
	printf("After 5 iteration The parent will be terminated\n");
	int count = 0;
	while (1) {
		if (pid == 0) {
			// Child process
			printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
			sleep(1);
			// Child can continue running or exit after parent terminates
		} else {
			// Parent process
			printf("Parent: PID = %d, Parent PID = %d\n", getpid(), getppid());
			sleep(1);
			count++;
			if (count >= 5) {
				exit(0);
			}
		}
	}

	return 0;
}

