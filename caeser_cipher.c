/*
cipher.c
---------
In cryptography, a cipher is an algorithm for performing encryption or decryption.

A Caeser Cipher is also known as a shift cipher. 
In Caeser Cipher, the letters in the text is shifted by some fixed number. 
For example, if the shift is 3, then the following substitution scheme will be used, 
where the letters in the top row will be replaced by the corresponding letter in the bottom row:
a b c d e f g h i j k l m n o p q r s t u v w x y z
d e f g h i j k l m n o p q r s t u v w x y z a b c
A Caeser Cipher is easily cracked because there are only 26 possible shifts.

shift_char(c, n) shifts a character c by n characters to the right (positive n) or the left (negative n).

*/

#include <stdio.h>

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

char *caeser(char *s, int n) 
{   int length = (int)strlen(s);
    char temp[length+1];

    for (int i=0; s[i] != '\0'; ++i)
        temp[i] = shift_char(s[i], n);
    
    for (int i=0; s[i] != '\0'; ++i)
        s[i] = temp[i];
   
    return s;
}

int main(void) 
{   // Edit the text and the shift number to test
    char text[] = "The quick brown fox jumps over the lazy dog!";
    printf("%s\n", caeser(text), 3);
    printf("%s\n", caeser(text), -3);
    return 0;
}
