/*
frequency_letters.c
-------------------
freq(s) prints the number of occurrences of each letter in the string s.
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
