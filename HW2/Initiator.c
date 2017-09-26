#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{

	char * buffer = 0;
	long length;
	FILE * f = fopen ("textfile.txt", "rb");

	if (f){
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = malloc (length);
		if (buffer){
			fread (buffer, 1, length, f);
		}
		fclose (f);
	}

	pid_t child_1, child_2, child_3, child_pid;
	int statval;
	int consonants, vowels, others;
	// child process for Consonants
	child_1 = fork();

	if(child_1 == 0){
		printf("Initiator: forked process with ID %d\n", getpid());
		char *args[] = { "./Vowels", buffer, NULL };
		execve("Vowels", args, NULL);
	}
	else{
		wait(&statval);
		printf("Initiator: waiting for process [%d].\n", child_1);
        if(WIFEXITED(statval))
        	vowels = WEXITSTATUS(statval);
		printf("Initiator: child process %d returned %d.\n", child_1, vowels);

        // child process for Vowels
        child_2 = fork();
		if(child_2 == 0){
			printf("Initiator: forked process with ID %d\n", getpid());
			char *args[] = { "./Consonants", buffer, NULL };
			execve("Consonants", args, NULL);
		}
		else{
			wait(&statval);
			printf("Initiator: waiting for process [%d].\n", child_2);
	        if(WIFEXITED(statval))
	        	consonants = WEXITSTATUS(statval);
	        printf("Initiator: child process %d returned %d.\n", child_2, consonants);
		    
		    // child process for Others 	      	
	    	child_3 = fork();
			if(child_3 == 0){
				child_pid = getpid();
				printf("Initiator: forked process with ID %d\n", getpid());
				char *args[] = { "./Other", buffer, NULL };
				execve("Other", args, NULL);
			}
			else{
				wait(&statval);
				printf("Initiator: waiting for process [%d].\n", child_3);
		        if(WIFEXITED(statval))
		        	others = WEXITSTATUS(statval);
		        printf("Initiator: child process %d returned %d.\n", child_3, others);

	    	}
        }	
    }
    printf("The number of vowels is %d\n", vowels);
    printf("The number of consonants is %d\n", consonants);
    printf("The number of other characters is %d\n", others);
	return 0;
}
