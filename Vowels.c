#include <stdio.h>

int main()
{
    char line[150];
    int vowels=0;

    

    printf("Enter to count vowels: ");
    scanf("%[^\n]", line);

    for(int i=0; line[i]!='\0'; ++i)
    {
        if(line[i]=='a' || line[i]=='e' || line[i]=='i' ||
           line[i]=='o' || line[i]=='u' || line[i]=='A' ||
           line[i]=='E' || line[i]=='I' || line[i]=='O' ||
           line[i]=='U')
        {
            ++vowels;
        }
        
    }

    printf("The number of vowels  is %d \n",vowels);
    
    

    return 0;
}
