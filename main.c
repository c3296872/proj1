#include <stdio.h>
/*
int RotationEncryption(void);
int RotationDecryption(void);
int SubEncrypt(void);

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

/*
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

*/


// int SubEncrypt(void)
int main()
{
    char text[] = "The 5 Quick Brown Fox's Winter Coats are coming in!"; //array stores input
    char rotated[200];   // array stores encyrpted text
    int n = 0;  // n + 1 = size of string
    char key[] = "TBIMREZNVFSGQAUKJXWLPHCYDO"; //Subsitution encryption key (1st letter = A, 2nd = B, etc)
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    printf("Text to be Encrypted: %s\n", text); // prints text to be encrypted
        for(int x = 0; text[x] != 0; x++) //for loop encrypts text
        {
            switch(text[x]) //switch statement returns value from key to encrypted array
            {
                case 65: rotated[x] = key[0]; //Any A's in text are encrypted to first character in Key
                    break;
                case 66: rotated[x] = key[1]; //Any B's in text are encrypted to second character in Key
                    break;
                case 67: rotated[x] = key[2]; // etc...
                    break;
                case 68: rotated[x] = key[3];
                    break;
                case 69: rotated[x] = key[4];
                    break;
                case 70: rotated[x] = key[5];
                    break;
                case 71: rotated[x] = key[6];
                    break;
                case 72: rotated[x] = key[7];
                    break;
                case 73: rotated[x] = key[8];
                    break;
                case 74: rotated[x] = key[9];
                    break;
                case 75: rotated[x] = key[10];
                    break;
                case 76: rotated[x] = key[11];
                    break;
                case 77: rotated[x] = key[12];
                    break;
                case 78: rotated[x] = key[13];
                    break;
                case 79: rotated[x] = key[14];
                    break;
                case 80: rotated[x] = key[15];
                    break;
                case 81: rotated[x] = key[16];
                    break;
                case 82: rotated[x] = key[17];
                    break;
                case 83: rotated[x] = key[18];
                    break;
                case 84: rotated[x] = key[19];
                    break;
                case 85: rotated[x] = key[20];
                    break;
                case 86: rotated[x] = key[21];
                    break;
                case 87: rotated[x] = key[22];
                    break;
                case 88: rotated[x] = key[23];
                    break;
                case 89: rotated[x] = key[24];
                    break;
                case 90: rotated[x] = key[25];
                    break;
                default: rotated[x] = text[x]; //any non letter characters are not encrypted
            }
        }
        printf("Encrypted Text: %s\n", rotated);

}


//LNR 5 JPVIS BXUCA EUY'W CVALRX IUTLW TXR IUQVAZ VA!






