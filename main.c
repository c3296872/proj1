#include <stdio.h>


void main() 
{
char text[200]; //string input
char rotated[200];   // array stores encyrpted text
int n;  // n is size of string
int K = 5; //K is rotation cipher encryption "key"
printf("Enter text to be encrypted: ");
scanf("%s", text);

//printf("\n please enter encryption key: ");
//scanf("%d", K);
for(n = 0; text[n] != NULL; n++)
{
    rotated[n] = text[n] + K;
}
rotated[n+1] = NULL;
printf("%s\n", rotated);

for(n = 0; text[n] != 0; n++)
{
    rotated[n] = rotated[n] - K;
}

printf("%s", rotated);



}
