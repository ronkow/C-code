/*
frequency_letters.c
-------------------
freq(s) prints the number of occurrences of each letter in the string s.
Upper and lower case letters are equivalent and all non-letters are ignored.
*/

#include <stdio.h>

void freq(char *s)
{   char letter[27]={'a','b','c','d','e','f','g','h','i','j',
                    'k','l','m','n','o','p','q','r','s','t',
                    'u','v','w','x','y','z'};
    int letter_freq[26]={0};
     
    for (int i=0; s[i]!='\0'; ++i)
    {   if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))  // If character is a letter
        {   for (int j=0; j<=25; ++j)                              // Scan through letter[] array to find a match
            {   if (s[i]==letter[j] || (s[i] + 32)==letter[j])     // If match between lowercase s[i] and letter[j] is found, exit loop 
                {   letter_freq[j] += 1;
                    break;
                }
            }
        }
    }
    for (int j=0; letter[j]!='\0'; ++j)
    {   printf("%c:%d ",letter[j],letter_freq[j]);
    }
}

int main(void)
{   // Edit the text to test
    char text[] = "The quick brown fox jumps over the lazy dog!";
    freq(text);
    return 0;
}
