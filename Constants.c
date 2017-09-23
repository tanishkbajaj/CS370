#include <stdio.h>

int main()
{
    char line[150];
    int constants=0;

    

    printf("Enter to count constants: ");
    scanf("%[^\n]", line);

    for(int i=0; line[i]!='\0'; ++i)
    {
        if(line[i]!='a' && line[i]!='e' && line[i]!='i' &&
           line[i]!='o' && line[i]!='u' && line[i]!='A' &&
           line[i]!='E' && line[i]!='I' && line[i]!='O' &&
           line[i]!='U')
        {
            ++constants;
        }
        
    }

    printf("The number of constants  is %d \n",constants);
    
    

    return 0;
}
