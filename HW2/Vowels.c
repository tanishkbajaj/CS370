#include <unistd.h>
#include <string.h>
#include <ctype.h>

int isvowel(int ch){
  int c = (int)toupper(ch);
 
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main(int argc, char const *argv[]){
	
	int ret = 0;
	int len = strlen(argv[1]);
	for(int i = 0; i < len; i++){
		if(isvowel(argv[1][i])){
			ret++;
		}
	}
	return ret;
}
