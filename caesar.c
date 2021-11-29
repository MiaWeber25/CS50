#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key = 0;
    if (argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }
    else
    {
        key = atoi(argv[1]);
    }
    string plaintext = get_string("plaintext:");


    for (int i=0; i<strlen(plaintext); i++) //iterate through each element of the string
    {
        if ((plaintext[i] >=65 && plaintext[i] <= 90)) //uppercase letters
        {

             plaintext[i] = ((((plaintext[i] - 65) + key) %26)+65); //take an element in the array, subtract the min ASCII value, add your key to move it, mod 26 to reset it back to 65 so that you don't end up with a number larger than the max ASCII value. Add 65 back so its in range.
        }
        if ((plaintext[i] >= 97 && plaintext[i] <= 122)) { //lowercase letters

             plaintext[i] = ((((plaintext[i] - 97) + key) %26)+97);

        }

       // printf("first:%c\n",plaintext[0]+key);
    }
    printf("ciphertext: %s\n",plaintext);
    //char cyphertext[strlen(plaintext)];

    //strcpy(plaintext,cyphertext);
    //printf("cyphertext:%s",cyphertext);
    //printf("length:%lu\n",strlen(plaintext));
    //printf("first:%c\n",plaintext[0]+key);
    //printf("sample:%c\n",77);
}