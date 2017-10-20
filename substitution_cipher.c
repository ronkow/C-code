/*
cipher_substitution.c
---------------------
In cryptography, a cipher is an algorithm for performing encryption or decryption.

A Substitution Cipher uses a random replacement key. 
For example, one such key could be:
a b c d e f g h i j k l m n o p q r s t u v w x y z
p h q g i u m e a y l n o f d x j k r c v s t z w b

There are 26! possible permutations of the key, which is quite a lot to crack using brute force.
While it is almost impossible obtain the key for a substitution cipher by trial-and-error, 
it is possible to crack the cipher by analysing the frequency of the letters 
and matching it with the known frequency of the language. 
This is because each letter is always replaced with the same letter.

*/

#include <stdio.h>
#include <string.h>

char *substitute(char *s, char *key) 
{   int length = (int)strlen(s);
    char temp[length+1];
    
    int letter_number = 0;
    
    for (int i=0; s[i] != '\0'; ++i)
    {   if (s[i]>='a' && s[i]<='z')
        {   letter_number = s[i]-97;
            temp[i] = key[letter_number]; 
        }
        else if (s[i]>='A' && s[i]<='Z')
        {   letter_number =s[i]-65;
            temp[i] = key[letter_number] - 32;
        }
        else
            temp[i] = s[i];
    }
    
    for (int i=0; s[i] != '\0'; ++i)
        s[i] = temp[i];
 
    return s;
}


char *unsubstitute(char *s, char *key)
{   int length = (int)strlen(s);
    char temp[length+1];
    
    int letter_number = 0;
    
    for (int i=0; s[i] != '\0'; ++i)
    {   for (int j=0; j<=25; ++j)
        {   if (s[i] == key[j] || s[i] + 32 == key[j])
            {   letter_number = j;
                break;
            }
        }
     
        if (s[i]>='a' && s[i]<='z')
            temp[i] = letter_number + 97; 
        else if (s[i]>='A' && s[i]<='Z')
            temp[i] = letter_number + 65;
        else
            temp[i] = s[i];
    }
    
    for (int i=0; s[i] != '\0'; ++i)
        s[i] = temp[i];
    
    return s;
}

int main(void) 
{   // Edit the text and the substitution key to test
    char text[] = "The quick brown fox jumps over the lazy dog!";
    char key[] = "phqgiumeaylnofdxjkrcvstzwb";
    /*
    a b c d e f g h i j k l m n o p q r s t u v w x y z
    p h q g i u m e a y l n o f d x j k r c v s t z w b
    */
    printf("%s\n", substitute(text, key));
    printf("%s\n", unsubstitute(text, key));
    return 0;
}
