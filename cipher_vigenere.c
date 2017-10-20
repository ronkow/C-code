/*
cipher_vigenere.c
-----------------
In cryptography, a cipher is an algorithm for performing encryption or decryption.

In a Vigenere Cipher, the same letter can be replaced by different letters at different times during the encryption process.
Instead of a key of letters, the key for a Vigenere cipher is a sequence of integers. 
For example, 7, 5, -6, 22, -13, 6 . 
Each letter in the plain text string will be shifted according to the corresponding number:

L o r e m i p s u m d o l o r s i t
7 5 -6 22 -13 6 7 5 -6 22 -13 6 7 5 -6 22 -13 6 7 5 -6
S t l a z p u m q z k t f k e z n n

The key is repeated as shown in the middle row. 
Each plain text letter in the first row is shifted by the corresponding number in the key to get the encrypted text in the bottom row. 
Punctuation, space and other non-letter characters remain unchanged.

shift_char(c, n) shifts a character c (a to z/A to Z) by n characters to the right (positive n) or the left (negative n).
if a character is shifted beyond Z or before A, it wraps around.

vigenere(s,key) encrypts a string.
unvigenere(s,key) decrypts a string.
*/

#include <stdio.h>
#include <string.h>

char shift_char(char c, int n)
{   int n1 = n%26;
    int c1 = c + n1;
    
    if (c>='A' && c<='Z')  
    {   if (c1>90)
            c = c1 - 26;
        else if (c1<65)
            c = c1 + 26;
        else
            c = c1;
    }
    else if (c>='a' && c<='z')
    {   if (c1>122)
            c = c1 - 26;
        else if (c1<97)
            c = c1 + 26;
        else
            c = c1;
    }
    return c;
}

char *vigenere(char *s, int *key) 
{   int length = (int)strlen(s);
    char temp[length+1];
    
    int length_key=0;

    for (int i=0; key[i] != 0; ++i)
        length_key += 1;
    
    for (int i=0; s[i] != '\0'; ++i)
        temp[i] = shift_char(s[i], key[i%length_key]);
   
    for (int i=0; s[i] != '\0'; ++i)
        s[i] = temp[i];
    
    return s;
}

char *unvigenere(char *s, int *key) 
{   int length = (int)strlen(s);
    char temp[length+1];
    
    int length_key=0;

    for (int i=0; key[i] != 0; ++i)
        length_key += 1;
    
    for (int i=0; s[i] != '\0'; ++i)
        temp[i] = shift_char(s[i], -1*key[i%length_key]);
    
    for (int i=0; s[i] != '\0'; ++i)
        s[i] = temp[i];
    
    return s;
}

int main(void) 
{   // Edit the text and the Vigenere key to test
    char text[] = "The quick brown fox jumps over the lazy dog!";
    int vkey[] = {7, 5, -6, 22, -13, 6, 0};
    printf("%s\n", vigenere(text, vkey));
    printf("%s\n", unvigenere(text, vkey));
    return 0;
}
