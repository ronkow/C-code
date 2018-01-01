/*
frequency_letters.c
-------------------
<freq> prints the number of occurrences of each letter in the string s.
Upper and lower case letters are equivalent and all non-letters are ignored.
*/

#include <stdio.h>

void freq(char *s)
{   int letter_freq[26]={0};
     
    for (int i=0; s[i]!='\0'; ++i)
    {   if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))  
        {   for (int j=0; j<=25; ++j)                              
            {   if (s[i]==j+97 || (s[i] + 32)==j+97)                 
                {   letter_freq[j] += 1;
                    break;
                }
            }
        }
    }
    for (int j=0; j<=25; ++j)
    {   printf("%c:%d ",j+97,letter_freq[j]);
    }
}

int main(void)
{   // Edit the text to test
    char text[] = "The quick brown fox jumps over the lazy dog!";
    freq(text);
    return 0;
}

/*
OUTPUT
------
a:1 b:1 c:1 d:1 e:3 f:1 g:1 h:2 i:1 j:1 k:1 l:1 m:1 n:1 o:4 p:1 q:1 r:2 s:1 t:2 u:2 v:1 w:1 x:1 y:1 z:1
*/
