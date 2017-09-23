#include <stdio.h>

int main()
{
    char line[150];
    int others=0;

    

    printf("Enter to count constants: ");
    scanf("%[^\n]", line);

    for(int i=0; line[i]!='\0'; ++i)
    {
        if(line[i]>=0 && line[i]<=64|| line[i]>=91 && line[i]<=96 || line[i]>=123 && line[i]<=127)
        {
            ++others;
        }
        
    }

    printf("The number of others  is %d \n",others);
    
    

    return 0;
}
