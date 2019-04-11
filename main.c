#include <stdio.h>

char RotationEncryption(void);

int main()
{
    int input1 = 1;
    while(input1 < 7 && input1 > 0)
    {
        printf("Choose from the following options:\n");
        printf("1. Rotation Encryption\n");
        printf("2. Rotation Decryption with known rotation amount\n");
        printf("3. Substitution Encryption\n");
        printf("4. Substitution Decryption with known substitutions\n");
        printf("5. Rotation Decryption without known roation amount\n");
        printf("6. Substitution Decryption without known substitutions\n");
        scanf("%d", &input1);
        //char answer[200];
        switch(input1)
        {
        case 1: return RotationEncryption();
                break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6: printf("This option is still under construction.\n We thank you for your patience\n");
                break;
        default: printf("Invalid Input");
        }
    }
    
}

char RotationEncryption(void) 
{
    char text[200]; //string input
    char rotated[200];   // array stores encyrpted text
    int n;  // n is size of string
    int K = 5; //K is rotation cipher encryption "key"
    printf("Enter text to be encrypted: ");
    scanf("%s", text);
    
    //printf("\n please enter encryption key: ");
    //scanf("%d", K);
    for(n = 0; text[n] != 0; n++)
    {
        rotated[n] = text[n] + K;
    }
    rotated[n+1] = 0;
    printf("%s\n", rotated);
    
    for(n = 0; text[n] != 0; n++)
    {
        rotated[n] = rotated[n] - K;
    }
    
    printf("%s", rotated);
    return 1;
}