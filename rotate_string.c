/*
rotate_string.c
---------------
*rotate(s, n) takes a string s and shifts the characters of s by n places, 
causing the characters to wrap around the string. 
For example, for "Hello World!" , a shift of n = 2 will result in "llo World!He" . 
The first two characters to be appended to the end of the string. 
Positive n will shift the characters to the left.
Negative n will shift the characters to the right.
If n is larger than the length of the string, the rotation will wrap around as many times as required.
*/

#include <stdio.h>
#include <string.h>

char *rotate(char *s, int n) 
{   int length = (int)strlen(s);    // Find length of s
    char temp[length+1];            // Temporary array to store rotated string
    
    n %= length;                    // If n is larger than length, use the modulo

    for (int i=0; s[i]!='\0'; ++i)   // Can also use 0 instead of '\0'
    {   temp[i] = s[(i + n + length) % length]; // for negative n, (i+n+length) >= 0
    }
                                    // can also use memcpy(s, temp, length)                                
    for (int i=0; s[i]!='\0'; ++i)  // Copy from temp to s
    {   s[i] = temp[i];             
    }
    return s;
}

int main(void) 
{   // Edit the text to test
    char text[] = "The quick brown fox jumps over the lazy dog!";
    printf("%s\n", rotate(text, 2));
    printf("%s\n", rotate(text, -2));
    return 0;
}
