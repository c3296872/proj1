#include <stdio.h>

int RotEncrypt(void);
int RotDecryptKnownKey(void);
int SubEncrypt(void);
int SubDecryptKnownKey(void);
int RotDecryptUnknownKey(void);
//int SubDecryptUknownKey(void);


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
        case 1: return RotEncrypt();
                break;
        case 2: return RotDecryptKnownKey();
                break;
        case 3: return SubEncrypt();
                break;
        case 4: return SubDecryptKnownKey();
                break;
        case 5: return RotDecryptUnknownKey();
                break;
        case 6: printf("This option is still under construction.\n We thank you for your patience\n");
                return 0;
                break;
        default: printf("Invalid Input\n");
        }
    }
    
}


//int main()
int RotEncrypt(void) 
{
    char text[] = "the and for are but not you all any can had her was one our out day get has him his how man new now old see two way who boy did its let put say she too use"; //array stores input
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
 return 1;   
}

int RotDecryptKnownKey(void)
//int main()
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
return 2;
}





//The 5 Quick Brown Fox's Winter Coats are coming in!
int SubEncrypt(void)
//int main()
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
return 3;
}


//LNR 5 JPVIS BXUCA EUY'W CVALRX IUTLW TXR IUQVAZ VA!
int SubDecryptKnownKey(void)
//int main()
//char function(char text[x],char *key);
{
    char text[] = "LnR 5 jPVIS BXUcA EUY'W CVaLRX IUTLw tXR IUQvAZ Va!"; //array stores input
    char decrypted[200];   // array stores decyrpted text
    int n = 0;  // n + 1 = size of string
    char key[] = "TBIMREZNVFSGQAUKJXWLPHCYDO"; //Subsitution decryption key (1st letter = A, 2nd = B, etc)
    //char key1[100];
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    
    printf("Text to be Encrypted: %s\n", text); // prints text to be encrypted
        for(int x = 0; key[x] != 0; x++) //for loop encrypts text
        {
            for(int k = 0; text[k] != 0; k++)
            {
                if(text[k] == key[x])
                {
                    decrypted[k] = x + 65;
                }
            }
        }
        for(int m = 0; text[m] != 0; m++)
        {
            if(text[m] < 65 || text[m] > 90)
            {
                decrypted[m] = text[m];
            }
        }
        printf("Decrypted Text: %s\n", decrypted);
return 4;
}


int RotDecryptUnknownKey(void)
//int main()
{
    char text[] = "YMJ FSI KTW FWJ GZY STY DTZ FQQ FSD HFS MFI MJW BFX TSJ TZW TZY IFD LJY MFX MNR MNX MTB RFS SJB STB TQI XJJ YBT BFD BMT GTD INI NYX QJY UZY XFD XMJ YTT ZXJ"; //array stores input
    char rotated[200];   // array stores decyrpted text
    int n = 0;  // n + 1 = size of string
    int nk = 0; //nk is number of keys found
    int key = -1; //key to be used from keys array will be stored here
    int keys[50];   //keys[] stores all potential keys found
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case    
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    printf("Text to be decrypted: %s\n", text); // prints text to be decrypted
    
    for(int K = 0; text[K] != 0; K++) 
    {
        //printf("%c\n", text[K]);
        if(text[K] == 32 || K == 0) //if K is a space we will check for another space 4 characters away or if K = 0 we will check for a spcare 3 characters away
        {
            if(((text[K + 4] == 32) || ((text[K + 4]) == 0)) || ((K == 0) && (text[K + 3] == 32))) //if there is another space or a null 4 characters away or 3 characters away for K = 0 (a three letter word is found)
            {
                if(K == 0 && text[0] != 32)//if the first word is a three letter word, first three letters are checked rather than checking from the space behind the word
                {
                    K = -1; //If K is equal to 1 at the end of the switch statement, it is returned to K = 0
                }
                int x = (text[K + 1] - text[K + 2]); //test to be compared to known patterns of commonly used words
                printf("case %d\n", x);
                switch(x)
                {
                    case -25:
                    case 1:     keys[nk] = text[K + 1] - 79; //Case for if "ONE" pattern identified
                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                nk++;
                                break;
                    case -24:
                    case 2:     switch(text[K + 1] - text[K + 3])
                                {
                                    case 13:
                                    case -13:   keys[nk] = text[K + 1] - 71; //Case for if "GET" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case 15:
                                    case -11:   keys[nk] = text[K + 1] - 67; //Case for if "CAN" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case 16:
                                    case -10:   keys[nk] = text[K + 1] - 85; //Case for if "USE" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                }
                                break;
                    case -23:
                    case 3:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -21:
                                    case 5:    keys[nk] = text[K + 1] - 68; //Case for if "DAY" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -15:
                                    case 11:    keys[nk] = text[K + 1] - 79; //Case for if "OLD" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -10:
                                    case 16:    keys[nk] = text[K + 1] - 72; //Case for if "HER" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                }
                                break;
                    case -3:                                 //Case for if "TWO" pattern identified            
                    case 23:                                 //Case for if "TWO" pattern identified            
                    case -21:                                //Case for if "TOO" pattern identified
                    case 5:     keys[nk] = text[K + 1] - 84; //Case for if "TOO" pattern identified
                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                nk++;
                                break;
                    case -19:
                    case 7:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -11:                                //Case for if "HAS" pattern identified
                                    case 15:                                 //Case for if "HAS" pattern identified
                                    case -22:                                //Case for if "HAD" pattern identified
                                    case 4:     keys[nk] = text[K + 1] - 72; //Case for if "HAD" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -18:
                                    case 8:     keys[nk] = text[K + 1] - 66; //Case for if "BUT" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                        
                                    case -8:
                                    case 18:    keys[nk] = text[K + 1] - 76; //Case for if "LET" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                }
                                break;
                    case -17:
                    case 9:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -9:
                                    case 17:    keys[nk] = text[K + 1] - 78; //Case for if "NEW" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -4:
                                    case 22:    keys[nk] = text[K + 1] - 65; //Case for if "ARE" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                }
                                break;
                    case -16:
                    case 10:        keys[nk] = text[K + 1] - 89; //Case for if "YOU" pattern identified
                                    printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                    nk++;
                                    break;
                    case -12:                                    //Case for if "SEE" pattern identified
                    case 14:                                     //Case for if "SEE" pattern identified
                    case -8:                                     //Case for if "SAY" pattern identified
                    case 18:                                     //Case for if "SAY" pattern identified    
                    case -15:                                    //Case for if "SHE" pattern identified
                    case 11:        keys[nk] = text[K + 1] - 83; //Case for if "SHE" pattern identified
                                    printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                    nk++;
                                    break;
                    case -14:
                    case 12:        switch(text[K + 1] - text[K + 3])
                                {
                                    case -11:
                                    case 15:    keys[nk] = text[K + 1] - 84; //Case for if "THE" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -1:
                                    case 25:    keys[nk] = text[K + 1] - 77; //Case for if "MAN" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                }
                                break;
                    case -13:
                    case 13:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -3:                                //Case for if "AND" pattern identified
                                    case 23:                                  //Case for if "AND" pattern identified
                                    case -24:                                //Case for if "ANY" pattern identified
                                    case 2:     keys[nk] = text[K + 1] - 65; //Case for if "ANY" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -23:
                                    case 3:     keys[nk] = text[K + 1] - 66; //Case for if "BOY" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                }
                                break;
                    case -11:
                    case 15:    switch(text[K + 1] - text[K + 3])
                                {
                                    case -18:
                                    case 8:    keys[nk] = text[K + 1] - 87; //Case for if "WHO" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -11:
                                    case 15:    keys[nk] = text[K + 1] - 65; //Case for if "ALL" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -10:
                                    case 16:    keys[nk] = text[K + 1] - 73; //Case for if "ITS" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                }
                                break;    
                    case -9:
                    case 17:        keys[nk] = text[K + 1] - 70; //Case for if "FOR" pattern identified
                                    printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                    nk++;
                                    break;
                    case -7:
                    case 19:        keys[nk] = text[K + 1] - 72; //Case for if "HOW" pattern identified
                                    printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                    nk++;
                                    break;
                    case -6:
                    case 20:        keys[nk] = text[K + 1] - 79; //Case for if "OUR" OR "OUT" pattern identified
                                    printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                    nk++;
                                    break;
                    case -5:
                    case 21:     switch(text[K + 1] - text[K + 3])
                                {
                                    case 0:     keys[nk] = text[K + 1] - 68; //Case for if "DID" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -4:
                                    case 22:    keys[nk] = text[K + 1] - 80; //Case for if "PUT" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                }
                                break;
                    case -4:
                    case 22:    keys[nk] = text[K + 1] - 87; //Case for if "WAS" or "WAY" pattern identified
                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                nk++;
                                break;
                    case -1:
                    case 25:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -9:                                 //Case for if "NOW" pattern identified
                                    case 17:                                 //Case for if "NOW" pattern identified
                                    case -6:                                 //Case for if "NOT" pattern identified
                                    case 20:    keys[nk] = text[K + 1] - 78; //Case for if "NOT" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    case -11:                                //Case for if "HIS" pattern identified   
                                    case 15:                                 //Case for if "HIS" pattern identified
                                    case -5:                                 //Case for if "HIM" pattern identified   
                                    case 21:    keys[nk] = text[K + 1] - 72; //Case for if "HIM" pattern identified
                                                printf("Key found to be: %d on K=%d\n", keys[nk], K);
                                                nk++;
                                                break;
                                    default: break;
                                }
                                break;
                    default: break;
                  
                }
            if(K == -1)
            {
                K = 0;
            }
            }
        }
   // printf("The Key is: %d\n", key);
    }
    for(int x = 0; keys[x] != 0; x++) //for loop converts negative keys to values between 0 and 26. This isn't necessary for decoding to work, but seems to be a specifier in the project outline
    {
        if(keys[x] < 0) //if statement checks if key is negative number
        {
            keys[x] = keys[x] + 26;
        }
    }
    int test = 0;
    int g = 2; //g is the test for if a key is common enough to be used. After each loop, if no key is found that is common enough, g is increased to allow for less common keys to be used
    while(key < 0) //while loop finds the most common key. Once a key is found, loop finishes and exits.
    {
        int tmp = 0; //tmp counts how many other array elements are the same as the one being checked
        for(int x = 0; keys[x] != 0; x++) //for loop checks to see if there is a value that represents over 1/g of all keys found
        {
            if(keys[test] == keys[x])
            tmp++;           
        }
        if((tmp * g) > nk)
        {
            key = keys[test];
        }
        else
        {
            test++;
        }
        if(key < 0 && keys[test] == 0) //if no common key is found, g is increased to search for a less common key
        {
            g++;
        }
    }    
    printf("The most common key found is: %d\n", key);
    for(int x = 0; text[x] != 0; x++) //for loop decrypts text
    {
        if(text[x] > 64 && text[x] < 91) //if statement checks if character is a letter before encrypting
        {
            rotated[x] = text[x] - key; //expression decrypts character using key and stores it in decrypted text array
            if(rotated[x] < 65) //if statement checks if encrypted character is a letter
            {
                rotated[x] = rotated[x] + 26; //expression converts non-letter characters to correct letter
            }
            if(rotated[x] > 90)
            {
                rotated[x] = rotated[x] - 26; //expression converts non-letter characters to correct letter
            }
        }
        else
        {
            rotated[x] = text[x]; //expression copies non-letter characters without decrypting
        }
    }
    printf("Decrypted text: %s\n", rotated);
return 5;   
}

