#include <unistd.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char const *argv[]){
	
	int ret = 0;
	int len = strlen(argv[1]);
	for(int i = 0; i < len; i++){
		if(!isalpha(argv[1][i])){
			ret++;
		}
	}
	return ret;
}
