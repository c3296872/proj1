#include <stdio.h>
/*
int RotationEncryption(void);
int RotationDecryption(void);

int main()
{
    int input1 = 1;
    if(input1 < 7 && input1 > 0)
    {
        printf("Choose from the following options:\n");
        printf("1. Rotation Encryption\n");
        printf("2. Rotation Decryption with known rotation amount\n");
        printf("3. Substitution Encryption\n");
        printf("4. Substitution Decryption with known substitutions\n");
        printf("5. Rotation Decryption without known roation amount\n");
        printf("6. Substitution Decryption without known substitutions\n");
        //scanf("%d", &input1);
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
*/
/*
int RotationEncryption(void) 

{
    char text[] = "The 5 Quick Brown Fox's Winter Coats are coming in!"; //array stores input
    char rotated[200];   // array stores encyrpted text
    int n = 0;  // n + 1 = size of string
    int K = 5; //K is rotation cipher encryption "key"
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    printf("Text to be encrypted: %s\n", text); // prints text to be encrypted
    for(int x = 0; text[x] != 0; x++) //for loop encrypts text
    {
        if(text[x] > 64 && text[x] < 91) //if statement checks if character is a letter before encrypting
        {
            rotated[x] = text[x] + K; //expression encypts character using key and stores it in encypted text array
            if(rotated[x] > 90) //if statement checks if encrypted character is a letter
            {
                rotated[x] = rotated[x] - 26; //expression converts non-letter characters to correct letter
            }
        }
        else
        {
            rotated[x] = text[x]; //expression copies non-letter characters without encrypting
        }

    }
    rotated[n+1] = 0; //places string termination at correct position in array
    printf("Encrypted text: %s\n", rotated); // prints encrypted text
    
}
*/
//int RotationDecryption(void)
int main()
{
    char text[] = "YMj 5 VZnHP gWTBS kTC'x BnSYJW HtFYX FwJ HtRNSL Ns!"; //array stores input
    char rotated[200];   // array stores decyrpted text
    int n = 0;  // n + 1 = size of string
    int K = 5; //K is rotation cipher encryption "key"
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    printf("Text to be decrypted: %s\n", text); // prints text to be decrypted
    for(int x = 0; text[x] != 0; x++) //for loop decrypts text
    {
        if(text[x] > 64 && text[x] < 91) //if statement checks if character is a letter before encrypting
        {
            rotated[x] = text[x] - K; //expression decrypts character using key and stores it in decrypted text array
            if(rotated[x] < 65) //if statement checks if encrypted character is a letter
            {
                rotated[x] = rotated[x] + 26; //expression converts non-letter characters to correct letter
            }
        }
        else
        {
            rotated[x] = text[x]; //expression copies non-letter characters without decrypting
        }

    }
    printf("Decrypted text: %s", rotated);
}

// YMJ 5 VZNHP GWTBS KTC'X BNSYJW HTFYX FWJ HTRNSL NS!









