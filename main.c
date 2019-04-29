/*HOW TO USE THIS CODE
There are 6 functions in this code that each correspond with a task. 
The first line of "input" should be a single digit between 1 - 6 (inclusive) which corresponds to the task you want to complete
    If an invalid character is entered, an error message will be generated and no functions will be called for
If you are choosing a task that requires a known key, it must be placed in line 2 of "input", and the text to be encrypted or decrypted should be placed in line 3
    If you attempt to run a function that requires a known key without supplying the key, a standard key will be used
If you are choosing a task where the key is unknown, the text to be decrypted should be placed in line 2 of "input"
If you are running an ENCRYPTION function, you MUST supply the key on line 2 of "input"
HOW TO FORMAT KEYS IN "input"
    The key for a rotation encryption can be any single integer that fits in an int data type
    the key for a subsitution encryption should be a string of 26 letters ordered A-Z in which the subtitution has already been applied
        i.e. if the Substituion for A is X, the first letter of the key will be X. If the subsitution for B is Q, the second letter of the key will be Q, etc.
        Each letter can only be represneted in the key once and no spaces should appear on the same line as a key
        The key must only contain uppercase letters, only text to be decrypted will be converted*/

#include <stdio.h>

int RotEncrypt(void);
int RotDecryptKnownKey(void);
int SubEncrypt(void);
int SubDecryptKnownKey(void);
int RotDecryptUnknownKey(void);
int SubDecryptUknownKey(void);


int main()
{
    /*FILE *input;
    input = fopen("input.txt", "r");
    if(input == NULL)
    {
        printf("input is empty");
        return 0;
    }*/
    char input[5] = {0};//this is pretty much just a garbage bin for anything in input that I don't want
    int input1 = 4;
    if(input1 < 7 && input1 > 0)
    {
        printf("Choose from the following options:\n");
        printf("1. Rotation Encryption\n");
        printf("2. Rotation Decryption with known rotation amount\n");
        printf("3. Substitution Encryption\n");
        printf("4. Substitution Decryption with known substitutions\n");
        printf("5. Rotation Decryption without known roation amount\n");
        printf("6. Substitution Decryption without known substitutions\n");
        scanf("%d", &input1);
        scanf("%c", &input[0]);//this is just my way of moving the scanf to the next line "enter"
    //    input1 = input1 - 48;
        printf("input = %d\n", input1);
        //char answer[200];
        switch(input1)
        {
        case 1: return RotEncrypt();
        case 2: return RotDecryptKnownKey();
        case 3: return SubEncrypt();
        case 4: return SubDecryptKnownKey();
        case 5: return RotDecryptUnknownKey();
        case 6: return SubDecryptUknownKey();
        default: printf("Invalid Input\n");
        }
    }
    
}

int RotEncrypt(void) 
{
    char text[2000] = {0}; //array stores input
    int p = 0;
    int K; //K is rotation cipher encryption "key"
    char rotated[200] = {0};   // array stores encyrpted text
    int n = 0;  // n + 1 = size of string
    scanf("%d", &K);
    while(K < 0) //if a negative key is given, it is converted to a positive key
    {
        K = K + 26;
    }
    do
    {
            scanf("%c", &text[p]);
            p++;
    }while(text[p - 1] != 0);


    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    printf("The key is:\n%d\n", K);
    printf("Text to be encrypted:\n%s\n", text); // prints text to be encrypted
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
    printf("Encrypted text: \n%s\n", rotated); // prints encrypted text
 return 1;   
}

int RotDecryptKnownKey(void)
{
    char text[1000] = {0}; //array stores input
    char rotated[200] = {0};   // array stores decyrpted text
    int n = 0;  // n + 1 = size of string
    int K = 5; //K is rotation cipher encryption "key"
    int p = 0;
    scanf("%d", &K);
    while(K < 0) //if a negative key is given, it is converted to a positive key
    {
        K = K + 26;
    }
    printf("The key is: %d\n", K);
    do
    {
            scanf("%c", &text[p]);
            p++;
    }while(text[p - 1] != 0);    
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    printf("Text to be decrypted: \n%s\n", text); // prints text to be decrypted
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
    printf("Decrypted text: \n%s", rotated);
return 2;
}





//The 5 Quick Brown Fox's Winter Coats are coming in!
int SubEncrypt(void)
{
    int p = 0;
    char text[2000] = {0}; //array stores input
    char rotated[2000] = {0};   // array stores encyrpted text
    int n = 0;  // n + 1 = size of string
    char key[26] = {0}; //Subsitution encryption key (1st letter = A, 2nd = B, etc)
    scanf("%c", &text[2000]);
    do //do while loop converts input into key[]
    {
            scanf("%c", &key[p]);
            p++;
    }while(key[p - 1] != 13);
    key[p - 1] = 0;
    p = 0;
    scanf("%c", &text[2000]);
    do //do while loop coverts input into text[]
    {
            scanf("%c", &text[p]);
            p++;
    }while(text[p - 1] != 0);
    text[p - 1] = 0;
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    printf("Text to be Encrypted:%s\n", text); // prints text to be encrypted
    printf("The key is: %s\n", key);
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
        printf("Encrypted Text:%s\n", rotated);
return 3;
}


//LNR 5 JPVIS BXUCA EUY'W CVALRX IUTLW TXR IUQVAZ VA!
int SubDecryptKnownKey(void)
//char function(char text[x],char *key);
{
    int p = 0;
    char text[2000] = {0}; //array stores input
    char decrypted[2000];   // array stores decyrpted text
    int n = 0;  // n + 1 = size of string
    char key[26] = {0}; //Subsitution decryption key (1st letter = A, 2nd = B, etc)
    //char key1[100];
    scanf("%c", &text[2000]);
    do //do while loop converts input into key[]
    {
            scanf("%c", &key[p]);
            p++;
    }while(key[p - 1] != 13);
    key[p - 1] = 0;
    printf("The key is:%s\n", key);
    p = 0;
    scanf("%c", &text[2000]);
    do //do while loop coverts input into text[]
    {
            scanf("%c", &text[p]);
            p++;
    }while(text[p - 1] != 0);
    text[p - 1] = 0;
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    
    printf("Text to be Decrypted: %s\n", text); // prints text to be encrypted
        for(int x = 0; key[x] != 0; x++) //for loop decrypts text
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
{
    int p = 0;
    char text[2000] = {0}; //array stores input
    char rotated[2000];   // array stores decyrpted text
    int n = 0;  // n + 1 = size of string
    int nk = 0; //nk is number of keys found
    int key = -1; //key to be used from keys array will be stored here
    int keys[50];   //keys[] stores all potential keys found
    scanf("%c", &text[2000]);
    do //do while loop coverts input into text[]
    {
            scanf("%c", &text[p]);
            p++;
    }while(text[p - 1] != 0);
    text[p - 1] = 0;
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
                switch(x)
                {
                    case -25:
                    case 1:     keys[nk] = text[K + 1] - 79; //Case for if "ONE" pattern identified
                                nk++;
                                break;
                    case -24:
                    case 2:     switch(text[K + 1] - text[K + 3])
                                {
                                    case 13:
                                    case -13:   keys[nk] = text[K + 1] - 71; //Case for if "GET" pattern identified
                                                nk++;
                                                break;
                                    case 15:
                                    case -11:   keys[nk] = text[K + 1] - 67; //Case for if "CAN" pattern identified
                                                nk++;
                                                break;
                                    case 16:
                                    case -10:   keys[nk] = text[K + 1] - 85; //Case for if "USE" pattern identified
                                                nk++;
                                                break;
                                }
                                break;
                    case -23:
                    case 3:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -21:
                                    case 5:     keys[nk] = text[K + 1] - 68; //Case for if "DAY" pattern identified
                                                nk++;
                                                break;
                                    case -15:
                                    case 11:    keys[nk] = text[K + 1] - 79; //Case for if "OLD" pattern identified
                                                nk++;
                                                break;
                                    case -10:
                                    case 16:    keys[nk] = text[K + 1] - 72; //Case for if "HER" pattern identified
                                                nk++;
                                                break;
                                }
                                break;
                    case -3:                                 //Case for if "TWO" pattern identified            
                    case 23:                                 //Case for if "TWO" pattern identified            
                    case -21:                                //Case for if "TOO" pattern identified
                    case 5:     keys[nk] = text[K + 1] - 84; //Case for if "TOO" pattern identified
                                nk++;
                                break;
                    case -19:
                    case 7:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -11:                                //Case for if "HAS" pattern identified
                                    case 15:                                 //Case for if "HAS" pattern identified
                                    case -22:                                //Case for if "HAD" pattern identified
                                    case 4:     keys[nk] = text[K + 1] - 72; //Case for if "HAD" pattern identified
                                                nk++;
                                                break;
                                    case -18:
                                    case 8:     keys[nk] = text[K + 1] - 66; //Case for if "BUT" pattern identified
                                                nk++;
                                                break;
                                        
                                    case -8:
                                    case 18:    keys[nk] = text[K + 1] - 76; //Case for if "LET" pattern identified
                                                nk++;
                                                break;
                                }
                                break;
                    case -17:
                    case 9:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -9:
                                    case 17:    keys[nk] = text[K + 1] - 78; //Case for if "NEW" pattern identified
                                                nk++;
                                                break;
                                    case -4:
                                    case 22:    keys[nk] = text[K + 1] - 65; //Case for if "ARE" pattern identified
                                                nk++;
                                                break;
                                }
                                break;
                    case -16:
                    case 10:        keys[nk] = text[K + 1] - 89; //Case for if "YOU" pattern identified
                                    nk++;
                                    break;
                    case -12:                                    //Case for if "SEE" pattern identified
                    case 14:                                     //Case for if "SEE" pattern identified
                    case -8:                                     //Case for if "SAY" pattern identified
                    case 18:                                     //Case for if "SAY" pattern identified    
                    case -15:                                    //Case for if "SHE" pattern identified
                    case 11:        keys[nk] = text[K + 1] - 83; //Case for if "SHE" pattern identified
                                    nk++;
                                    break;
                    case -14:
                    case 12:        switch(text[K + 1] - text[K + 3])
                                {
                                    case -11:
                                    case 15:    keys[nk] = text[K + 1] - 84; //Case for if "THE" pattern identified
                                                nk++;
                                                break;
                                    case -1:
                                    case 25:    keys[nk] = text[K + 1] - 77; //Case for if "MAN" pattern identified
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
                                                nk++;
                                                break;
                                    case -23:
                                    case 3:     keys[nk] = text[K + 1] - 66; //Case for if "BOY" pattern identified
                                                nk++;
                                                break;
                                }
                                break;
                    case -11:
                    case 15:    switch(text[K + 1] - text[K + 3])
                                {
                                    case -18:
                                    case 8:    keys[nk] = text[K + 1] - 87; //Case for if "WHO" pattern identified
                                                nk++;
                                                break;
                                    case -11:
                                    case 15:    keys[nk] = text[K + 1] - 65; //Case for if "ALL" pattern identified
                                                nk++;
                                                break;
                                    case -10:
                                    case 16:    keys[nk] = text[K + 1] - 73; //Case for if "ITS" pattern identified
                                                nk++;
                                                break;
                                }
                                break;    
                    case -9:
                    case 17:        keys[nk] = text[K + 1] - 70; //Case for if "FOR" pattern identified
                                    nk++;
                                    break;
                    case -7:
                    case 19:        keys[nk] = text[K + 1] - 72; //Case for if "HOW" pattern identified
                                    nk++;
                                    break;
                    case -6:
                    case 20:        keys[nk] = text[K + 1] - 79; //Case for if "OUR" OR "OUT" pattern identified
                                    nk++;
                                    break;
                    case -5:
                    case 21:     switch(text[K + 1] - text[K + 3])
                                {
                                    case 0:     keys[nk] = text[K + 1] - 68; //Case for if "DID" pattern identified
                                                nk++;
                                                break;
                                    case -4:
                                    case 22:    keys[nk] = text[K + 1] - 80; //Case for if "PUT" pattern identified
                                                nk++;
                                                break;
                                }
                                break;
                    case -4:
                    case 22:    keys[nk] = text[K + 1] - 87; //Case for if "WAS" or "WAY" pattern identified
                                nk++;
                                break;
                    case -1:
                    case 25:     switch(text[K + 1] - text[K + 3])
                                {
                                    case -9:                                 //Case for if "NOW" pattern identified
                                    case 17:                                 //Case for if "NOW" pattern identified
                                    case -6:                                 //Case for if "NOT" pattern identified
                                    case 20:    keys[nk] = text[K + 1] - 78; //Case for if "NOT" pattern identified
                                                nk++;
                                                break;
                                    case -11:                                //Case for if "HIS" pattern identified   
                                    case 15:                                 //Case for if "HIS" pattern identified
                                    case -5:                                 //Case for if "HIM" pattern identified   
                                    case 21:    keys[nk] = text[K + 1] - 72; //Case for if "HIM" pattern identified
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

int SubDecryptUknownKey(void)
{
    int p = 0;
    char text[2000] = {0};
    char decrypted[2000];
    char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //Key is initialised and modified as text is analysed 
    //char tkey[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char commonL[] = "ETAOINSHRDLU"; //List of letters in order of most commonly used in English text according to https://www3.nd.edu/~busiforc/handouts/cryptography/cryptography%20hints.html
    char tally[25] = {0};
    tally[25] = 0;
    char ordered[12] = {0};
    char orderedtally[25] = {0}; 
    int n = 0;
    scanf("%c", &text[2000]);
    do //do while loop coverts input into text[]
    {
            scanf("%c", &text[p]);
            p++;
    }while(text[p - 1] != 0);
    text[p - 1] = 0;
    for(n = 0; text[n] != 0; n++) //for loop converts any lower case to upper case    
    {
        if(text[n] > 96 && text[n] < 123) //if statement checks if character is lower case before converting
        {
            text[n] = text[n] - 32; // expression converts lower case letter to uppercase as per ASCII table
        }
    }
    printf("Text to be decrypted: %s\n", text);
        for(n = 0; text[n] != 0; n++)
    {
        //printf("Case: %d\n", text[n]);
        switch(text[n])
        {
            case 65:    tally[0] = tally[0] + 1;
                        break;
            case 66:    tally[1] = tally[1] + 1;
                        break;
            case 67:    tally[2] = tally[2] + 1;
                        break;
            case 68:    tally[3] = tally[3] + 1;
                        break;
            case 69:    tally[4] = tally[4] + 1;
                        break;
            case 70:    tally[5] = tally[5] + 1;
                        break;
            case 71:    tally[6] = tally[6] + 1;
                        break;
            case 72:    tally[7] = tally[7] + 1;
                        break;
            case 73:    tally[8] = tally[8] + 1;
                        break;
            case 74:    tally[9] = tally[9] + 1;
                        break;
            case 75:    tally[10] = tally[10] + 1;
                        break;
            case 76:    tally[11] = tally[11] + 1;
                        break;
            case 77:    tally[12] = tally[12] + 1;
                        break;
            case 78:    tally[13] = tally[13] + 1;
                        break;
            case 79:    tally[14] = tally[14] + 1;
                        break;
            case 80:    tally[15] = tally[15] + 1;
                        break;
            case 81:    tally[16] = tally[16] + 1;
                        break;
            case 82:    tally[17] = tally[17] + 1;
                        break;
            case 83:    tally[18] = tally[18] + 1;
                        break;
            case 84:    tally[19] = tally[19] + 1;
                        break;
            case 85:    tally[20] = tally[20] + 1;
                        break;
            case 86:    tally[21] = tally[21] + 1;
                        break;
            case 87:    tally[22] = tally[22] + 1;
                        break;
            case 88:    tally[23] = tally[23] + 1;
                        break;
            case 89:    tally[24] = tally[24] + 1;
                        break;
            case 90:    tally[25] = tally[25] + 1;
                        break;
            default:    break;
        }
    }
    int x = 0; 
    int h = 0;
    for(h = 0; h < 12; h++) //to find the 12 most commonly found letters
    {
         for(x = 0; x < 26; x++) //for loop finds the most common letter and puts it in ordered[0] as long as that letters tally has not already been found
        {
           int tmp = 0, y = 11;
           for(y = 11; y >= 0; y--) //for loop flags if a letters tally is already used
           {
               if(tally[x] == orderedtally[y] && ordered[y] == key[x] && tally[x] != 0)
               {
                   tmp++;
                   //printf("tally[x] = %d, orderedtally[y] = %d, ordered[y] = %d, key[x] = %d\n", tally[x], orderedtally[y], ordered[y], key[x]);
               }
           }
            if(tally[x] >= orderedtally[h] && tmp == 0) //if a letter's tally is the highest that hasn't been found, it is found
            {
                ordered[h] = key[x];
                orderedtally[h] = tally[x];
                printf("h = %d, x = %d tally[x] = %d, orderedtally[h] = %d\n", x , h, tally[x], orderedtally[h]);
            }
        }
    } 
    /*
     char Di1[4] = {0}; //where most common digraph is stored. [0 & 1] stores 2 letter combo, [3] stores its frequency with a null in [2] so that array can still be read as string
     char Di2[4] = {0}; //where 2nd most common digraph is stored, etc
     char Di3[4] = {0}; //where 3rd most common digraph is stored
     char Di4[4] = {0}; //where 4th most common digraph is stored
     char Di5[4] = {0}; //where 5th most common digraph is stored
     char Di6[4] = {0}; //where 6th most common digraph is stored
     char Di7[4] = {0}; //where 7th most common digraph is stored
     char Di8[4] = {0}; //where 8th most common digraph is stored    
     char Di9[4] = {0}; //where 9th most common digraph is stored
     char Di10[4] = {0}; //where 10th most common digraph is stored
     char Di11[4] = {0}; //where  common digraph is stored
     char Di12[4] = {0}; //where  common digraph is stored
     char Di13[4] = {0}; //where  common digraph is stored
     char Di14[4] = {0}; //where  common digraph is stored
     char Di15[4] = {0}; //where  common digraph is stored
     char Di16[4] = {0}; //where  common digraph is stored
     char Di17[4] = {0}; //where  common digraph is stored
     char Di18[4] = {0}; //where  common digraph is stored
     char Di19[4] = {0}; //where  common digraph is stored
     char Di20[4] = {0}; //where  common digraph is stored
     char Di21[4] = {0}; //where  common digraph is stored
     char Di22[4] = {0}; //where  common digraph is stored    
     char Di23[4] = {0}; //where  common digraph is stored
     char Di24[4] = {0}; //where  common digraph is stored
     char Di25[4] = {0}; //where  common digraph is stored
     char Di26[4] = {0}; //where  common digraph is stored
     char Di27[4] = {0}; //where  common digraph is stored
     char Di28[4] = {0}; //where  common digraph is stored
     char Di29[4] = {0}; //where  common digraph is stored
     char Di30[4] = {0}; //where  common digraph is stored
     char tmpDi[2] = {0}; //
     int tmp = 0;
     int  DiCount = 0; //counts the number of 2 letter combinations with frequency high enough to be considered
     int f = 0; //counts frquency of detected 2 letter combination
     char CommonDi[] = "TH ER ON AN RE HE IN ED ND HA AT EN ES OF OR NT EA TI TO IT ST IO LE IS OU AR AS DE RT VE";
     for(int x = 0; x < 26; x++) //for loop cycles through every possible value for the first character of the 2 letter combination to be found
     {
         tmpDi[0] = x + 65;
         //printf("tmpDi[0] = %d\n", tmpDi[0]);
         for(int h = 0; h < 26; h++) //for loop cycles through every possible value for the second character of the 2 letter combination to be found
         {
             f = 0;
             tmpDi[1] = h + 65;
             //printf("tmpDi[1] = %d\n", tmpDi[1]);
             for(int K = 0; text[K] != 0; K++) //for loop checks every 2 letter combination and tallies how many times they appear in the text
             {
                 if((text[K] == tmpDi[0]) && (text[K + 1] == tmpDi[1]))
                 {
                     f++;
                 }
             }
             //printf("f = %d\n", f);
             if(f > 5) //if combination appears at least 6 times, it is sorted into list based on how frequently it appears
             {
                tmp = 0;
                DiCount++;
                if(f >= Di1[3]) //if statements check where found combination should reside, based on combinations already found and their frequency
                {
                     tmp = 1;
                }
                else if(f >= Di2[3])
                {
                     tmp = 2;
                }
                else if(f >= Di3[3])
                {
                    tmp = 3;
                }
                else if(f >= Di4[3])
                {
                    tmp = 4;
                }
                else if(f >= Di5[3])
                {
                    tmp = 5;
                }
                else if(f >= Di6[3])
                {
                    tmp = 6;
                }
                else if(f >= Di7[3])
                {
                    tmp = 7;
                }
                else if(f >= Di8[3])
                {
                    tmp = 8;
                }
                else if(f >= Di9[3])
                {
                    tmp = 9;
                }
                else if(f >= Di10[3])
                {
                    tmp = 10;
                }
                else if(f >= Di11[3])
                {
                    tmp = 11;
                }
                else if(f >= Di12[3])
                {
                    tmp = 12;
                }
                else if(f >= Di13[3])
                {
                    tmp = 13;
                }
                else if(f >= Di14[3])
                {
                    tmp = 14;
                }
                else if(f >= Di15[3])
                {
                    tmp = 15;
                }
                else if(f >= Di16[3])
                {
                    tmp = 16;
                }
                else if(f >= Di17[3])
                {
                    tmp = 17;
                }
                else if(f >= Di18[3])
                {
                    tmp = 18;
                }
                else if(f >= Di19[3])
                {
                    tmp = 19;
                }
                else if(f >= Di20[3])
                {
                    tmp = 20;
                }
                else if(f >= Di21[3])
                {
                    tmp = 21;
                }
                else if(f >= Di22[3])
                {
                    tmp = 22;
                }    
                else if(f >= Di23[3])
                {
                    tmp = 23;
                }
                else if(f >= Di24[3])
                {
                    tmp = 24;
                }
                else if(f >= Di25[3])
                {
                    tmp = 25;
                }
                else if(f >= Di26[3])
                {
                    tmp = 26;
                }
                else if(f >= Di27[3])
                {
                    tmp = 27;
                }
                else if(f >= Di28[3])
                {
                    tmp = 28;
                }
                else if(f >= Di29[3])
                {
                    tmp = 29;
                }
                else if(f > Di30[3])
                {
                    tmp = 30;
                }
                //printf("tmp = %d\nDiCount = %d\n", tmp, DiCount);
                switch(DiCount)//switch statement places combination in appropriate spot, and shuffles all less frequent combinations 1 spot to the bottom of list (max 30 combinations to be stored)
                {
                     default:   if(tmp == 0) //switch only breaks on each case if frequency has already been tagged as less than the combinations further up the list
                                {
                                    break;
                                }
                     case 30:   Di30[3] = Di29[3];
                                Di30[0] = Di29[0];
                                Di30[1] = Di29[1];
                                if(tmp == 30)
                                {
                                    Di30[3] = f;
                                    Di30[0] = tmpDi[0];
                                    Di30[1] = tmpDi[1];
                                    break;
                                }
                     case 29:   Di29[3] = Di28[3];
                                Di29[0] = Di28[0];
                                Di29[1] = Di28[1];
                                if(tmp == 29)
                                {
                                    Di29[3] = f;
                                    Di29[0] = tmpDi[0];
                                    Di29[1] = tmpDi[1];
                                    break;
                                }
                     case 28:   Di28[3] = Di27[3];
                                Di28[0] = Di27[0];
                                Di28[1] = Di27[1];
                                if(tmp == 28)
                                {
                                    Di28[3] = f;
                                    Di28[0] = tmpDi[0];
                                    Di28[1] = tmpDi[1];
                                    break;
                                }
                     case 27:   Di27[3] = Di26[3];
                                Di27[0] = Di26[0];
                                Di27[1] = Di26[1];
                                if(tmp == 27)
                                {
                                    Di27[3] = f;
                                    Di27[0] = tmpDi[0];
                                    Di27[1] = tmpDi[1];
                                    break;
                                }
                     case 26:   Di26[3] = Di25[3];
                                Di26[0] = Di25[0];
                                Di26[1] = Di25[1];
                                if(tmp == 26)
                                {
                                    Di26[3] = f;
                                    Di26[0] = tmpDi[0];
                                    Di26[1] = tmpDi[1];
                                    break;
                                }
                     case 25:   Di25[3] = Di24[3];
                                Di25[0] = Di24[0];
                                Di25[1] = Di24[1];
                                if(tmp == 25)
                                {
                                    Di25[3] = f;
                                    Di25[0] = tmpDi[0];
                                    Di25[1] = tmpDi[1];
                                    break;
                                }
                     case 24:   Di24[3] = Di23[3];
                                Di24[0] = Di23[0];
                                Di24[1] = Di23[1];
                                if(tmp == 24)
                                {
                                    Di24[3] = f;
                                    Di24[0] = tmpDi[0];
                                    Di24[1] = tmpDi[1];
                                    break;
                                }
                     case 23:   Di23[3] = Di22[3];
                                Di23[0] = Di22[0];
                                Di23[1] = Di22[1];
                                if(tmp == 23)
                                {
                                    Di23[3] = f;
                                    Di23[0] = tmpDi[0];
                                    Di23[1] = tmpDi[1];
                                    break;
                                }
                     case 22:   Di22[3] = Di21[3];
                                Di22[0] = Di21[0];
                                Di22[1] = Di21[1];
                                if(tmp == 22)
                                {
                                    Di22[3] = f;
                                    Di22[0] = tmpDi[0];
                                    Di22[1] = tmpDi[1];
                                    break;
                                }
                     case 21:   Di21[3] = Di20[3];
                                Di21[0] = Di20[0];
                                Di21[1] = Di20[1];
                                if(tmp == 21)
                                {
                                    Di21[3] = f;
                                    Di21[0] = tmpDi[0];
                                    Di21[1] = tmpDi[1];
                                    break;
                                }
                     case 20:   Di20[3] = Di19[3];
                                Di20[0] = Di19[0];
                                Di20[1] = Di19[1];
                                if(tmp == 20)
                                {
                                    Di20[3] = f;
                                    Di20[0] = tmpDi[0];
                                    Di20[1] = tmpDi[1];
                                    break;
                                }
                     case 19:   Di19[3] = Di18[3];
                                Di19[0] = Di18[0];
                                Di19[1] = Di18[1];
                                if(tmp == 19)
                                {
                                    Di19[3] = f;
                                    Di19[0] = tmpDi[0];
                                    Di19[1] = tmpDi[1];
                                    break;
                                }
                     case 18:   Di18[3] = Di17[3];
                                Di18[0] = Di17[0];
                                Di18[1] = Di17[1];
                                if(tmp == 18)
                                {
                                    Di18[3] = f;
                                    Di18[0] = tmpDi[0];
                                    Di18[1] = tmpDi[1];
                                    break;
                                }
                     case 17:   Di17[3] = Di16[3];
                                Di17[0] = Di16[0];
                                Di17[1] = Di16[1];
                                if(tmp == 17)
                                {
                                    Di17[3] = f;
                                    Di17[0] = tmpDi[0];
                                    Di17[1] = tmpDi[1];
                                    break;
                                }
                     case 16:   Di16[3] = Di15[3];
                                Di16[0] = Di15[0];
                                Di16[1] = Di15[1];
                                if(tmp == 16)
                                {
                                    Di16[3] = f;
                                    Di16[0] = tmpDi[0];
                                    Di16[1] = tmpDi[1];
                                    break;
                                }
                     case 15:   Di15[3] = Di14[3];
                                Di15[0] = Di14[0];
                                Di15[1] = Di14[1];
                                if(tmp == 15)
                                {
                                    Di15[3] = f;
                                    Di15[0] = tmpDi[0];
                                    Di15[1] = tmpDi[1];
                                    break;
                                }
                     case 14:   Di14[3] = Di13[3];
                                Di14[0] = Di13[0];
                                Di14[1] = Di13[1];
                                if(tmp == 14)
                                {
                                    Di14[3] = f;
                                    Di14[0] = tmpDi[0];
                                    Di14[1] = tmpDi[1];
                                    break;
                                }
                     case 13:   Di13[3] = Di12[3];
                                Di13[0] = Di12[0];
                                Di13[1] = Di12[1];
                                if(tmp == 13)
                                {
                                    Di13[3] = f;
                                    Di13[0] = tmpDi[0];
                                    Di13[1] = tmpDi[1];
                                    break;
                                }
                     case 12:   Di12[3] = Di11[3];
                                Di12[0] = Di11[0];
                                Di12[1] = Di11[1];
                                if(tmp == 12)
                                {
                                    Di12[3] = f;
                                    Di12[0] = tmpDi[0];
                                    Di12[1] = tmpDi[1];
                                    break;
                                }
                     case 11:   Di11[3] = Di10[3];
                                Di11[0] = Di10[0];
                                Di11[1] = Di10[1];
                                if(tmp == 11)
                                {
                                    Di11[3] = f;
                                    Di11[0] = tmpDi[0];
                                    Di11[1] = tmpDi[1];
                                    break;
                                }
                     case 10:   Di10[3] = Di9[3];
                                Di10[0] = Di9[0];
                                Di10[1] = Di9[1];
                                if(tmp == 10)
                                {
                                    Di10[3] = f;
                                    Di10[0] = tmpDi[0];
                                    Di10[1] = tmpDi[1];
                                    break;
                                }
                     case 9:    Di9[3] = Di8[3];
                                Di9[0] = Di8[0];
                                Di9[1] = Di8[1];
                                if(tmp == 9)
                                {
                                    Di9[3] = f;
                                    Di9[0] = tmpDi[0];
                                    Di9[1] = tmpDi[1];
                                    break;
                                }
                     case 8:    Di8[3] = Di7[3];
                                Di8[0] = Di7[0];
                                Di8[1] = Di7[1];
                                if(tmp == 8)
                                {
                                    Di8[3] = f;
                                    Di8[0] = tmpDi[0];
                                    Di8[1] = tmpDi[1];
                                    break;
                                }
                     case 7:    Di7[3] = Di6[3];
                                Di7[0] = Di6[0];
                                Di7[1] = Di6[1];
                                if(tmp == 7)
                                {
                                    Di7[3] = f;
                                    Di7[0] = tmpDi[0];
                                    Di7[1] = tmpDi[1];
                                    break;
                                }
                     case 6:    Di6[3] = Di5[3];
                                Di6[0] = Di5[0];
                                Di6[1] = Di5[1];
                                if(tmp == 6)
                                {
                                    Di6[3] = f;
                                    Di6[0] = tmpDi[0];
                                    Di6[1] = tmpDi[1];
                                    break;
                                }
                     case 5:    Di5[3] = Di4[3];
                                Di5[0] = Di4[0];
                                Di5[1] = Di4[1];
                                if(tmp == 5)
                                {
                                    Di5[3] = f;
                                    Di5[0] = tmpDi[0];
                                    Di5[1] = tmpDi[1];
                                    break;
                                }
                     case 4:    Di4[3] = Di3[3];
                                Di4[0] = Di3[0];
                                Di4[1] = Di3[1];
                                if(tmp == 4)
                                {
                                    Di4[3] = f;
                                    Di4[0] = tmpDi[0];
                                    Di4[1] = tmpDi[1];
                                    break;
                                }
                     case 3:    Di3[3] = Di2[3];
                                Di3[0] = Di2[0];
                                Di3[1] = Di2[1];
                                if(tmp == 3)
                                {
                                    Di3[3] = f;
                                    Di3[0] = tmpDi[0];
                                    Di3[1] = tmpDi[1];
                                    break;
                                }                
                     case 2:    Di2[3] = Di1[3];
                                Di2[0] = Di1[0];
                                Di2[1] = Di1[1];
                                if(tmp == 2)
                                {
                                    Di2[3] = f;
                                    Di2[0] = tmpDi[0];
                                    Di2[1] = tmpDi[1];
                                    break;
                                }      
                     case 1:    if(tmp == 1)
                                {
                                    Di1[3] = f;
                                    Di1[0] = tmpDi[0];
                                    Di1[1] = tmpDi[1];
                                    //printf("Di1[3] = %d\nDi1[0] = %d\nDi1[1] = %d\n\n", Di1[3], Di1[0], Di1[1]);
                                    break;
                                }
                                
                }
            
         }
     }


     }
     //printf("DiCount: %d\n", DiCount);
    // printf("CommonDi =%s with 18 = %d\n", CommonDi, CommonDi[18]);
     int tmp2 = 0, tmp3 = 0;
     int tmp1 = 0;
     switch(DiCount)//switch only includes the 2 letter combinations that have been found to have a high enough frequency to modify the key
     {
         default:
         case 30:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(29 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di30[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(29 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di30[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di30[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di30[1];
         case 29:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(28 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di29[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(28 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di29[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di29[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di29[1];
         case 28:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(27 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di28[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(27 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di28[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di28[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di28[1];
         case 27:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(26 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di27[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(26 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di27[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di27[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di27[1];
         case 26:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(25 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di26[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(25 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di26[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di26[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di26[1];
         case 25:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(24 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di25[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(24 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di25[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di25[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di25[1];
         case 24:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(23 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di24[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(23 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di24[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di24[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di24[1];
         case 23:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(22 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di23[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(22 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di23[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di23[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di23[1];
         case 22:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(21 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di22[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(21 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di22[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di22[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di22[1];
         case 21:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(20 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di21[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(20 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di21[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di21[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di21[1];
         case 20:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(19 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di20[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(19 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di20[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di20[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di20[1];
         case 19:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(18 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di19[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(18 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di19[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di19[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di19[1];
         case 18:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(17 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di18[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(17 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di18[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di18[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di18[1];
         case 17:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(16 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di17[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(16 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di17[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di17[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di17[1];
         case 16:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(15 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di16[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(15 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di16[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di16[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di16[1];
         case 15:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(14 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di15[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(14 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di15[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di15[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di15[1];
         case 14:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(13 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di14[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(13 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di14[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di14[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di14[1];
         case 13:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(12 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di13[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(12 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di13[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di13[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di13[1];
         case 12:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(11 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di12[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(11 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di12[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di12[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di12[1];
         case 11:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(10 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di11[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(10 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di11[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di11[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di11[1];
         case 10:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(9 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di10[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(9 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di10[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di10[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di10[1];
         case 9:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(8 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di9[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(8 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di9[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di9[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di9[1];
         case 8:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(7 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di8[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(7 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di8[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di8[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di8[1];
         case 7:   for(h = 0; key[h] != 0; h++)
                    {
                        //printf("CommonDi[18] = %d\n", CommonDi[18]);
                        if(CommonDi[(6 * 3)] == key[h])
                        {
                            tmp = h;
                          //  printf("1h = %d\n", h);
                        }
                        if(Di7[0] == key[h])
                        {
                            tmp1 = h;   
                            //printf("2h = %d\n", h);
                        }
                        if(CommonDi[(6 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                            //printf("3h = %d\n", h);
                        }
                        if(Di7[1] == key[h])
                        {
                            tmp3 = h;  
                            //printf("4h = %d\n\n", h);
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di7[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di7[1];
         case 6:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(5 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di6[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(5 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di6[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di6[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di6[1];
         case 5:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(4 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di5[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(4 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di5[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di5[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di5[1];
         case 4:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(3 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di4[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(3 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di4[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di4[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di4[1];
         case 3:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(2 * 3)] == key[h])
                        {
                            tmp = h;
                            //printf("1h = %d\n", h);
                        }
                        if(Di3[0] == key[h])
                        {
                            tmp1 = h; 
                            //printf("2h = %d\n", h);
                        }
                        if(CommonDi[(2 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                            //printf("3h = %d\n", h);
                        }
                        if(Di3[1] == key[h])
                        {
                            tmp3 = h;     
                            //printf("4h = %d\n\n", h);
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di3[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di3[1];
         case 2:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(1 * 3)] == key[h])
                        {
                            tmp = h;
                           // printf("h = %d\n", h);
                        }
                        if(Di2[0] == key[h])
                        {
                            tmp1 = h;    
                           // printf("h = %d\n", h);
                        }
                        if(CommonDi[(1 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                           // printf("h = %d\n", h);
                        }
                        if(Di2[1] == key[h])
                        {
                            tmp3 = h; 
                          //  printf("h = %d\n\n", h);
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di2[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di2[1];
         case 1:   for(h = 0; key[h] != 0; h++)
                    {
                        if(CommonDi[(0 * 3)] == key[h])
                        {
                            tmp = h;
                        }
                        if(Di1[0] == key[h])
                        {
                            tmp1 = h;             
                        }
                        if(CommonDi[(0 * 3) + 1] == key[h])
                        {
                            tmp2 = h;
                        }
                        if(Di1[1] == key[h])
                        {
                            tmp3 = h;             
                        }
                    }
                     key[tmp1] = key[tmp];
                     key[tmp] = Di1[0];
                     key[tmp3] = key[tmp2];
                     key[tmp2] = Di1[1];    
         case 0:     break;
     } */
     //printf("Based on common 2 letter combinations, key is: %s\n", key);

    for(x = 0; x < 12; x++)//changes to key based on most frequent letters is applied after frequent 2 letter combinations
    {
        int tmp6 = 0;
        int tmp5 = 0;
        for(h = 0; key[h] != 0; h++)
        {
            if(ordered[x] == key[h])
            {
                tmp5 = h;
            }
            if(commonL[x] == key[h])
            {
                tmp6 = h;             
            }
        }
         key[tmp5] = commonL[x];
         key[tmp6] = ordered[x];
     }
     printf("The most common letters are %s\n", ordered);
     printf("Based on most common letters, key is: %s\n", key);
    
        // key is now found, decrption starts
        for(x = 0; key[x] != 0; x++) //for loop decrypts text using found key
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
        
    
    
    
    
    
    //LNR 5 JPVIS BXUCA EUY'W CVALRX IUTLW TXR IUQVAZ VA!
    return 6;
}


