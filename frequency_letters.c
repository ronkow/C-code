/*
frequency_letters.c
-------------------
freq(s) prints the number of occurrences of each letter in the string s.
Upper and lower case letters are equivalent and all non-letters are ignored.
*/

#include <stdio.h>

void freq(char *s) 
{   int a1=0, b1=0, c1=0, d1=0, e1=0, f1=0, g1=0, h1=0, i1=0, 
        j1=0, k1=0, l1=0, m1=0, n1=0, o1=0, p1=0, q1=0, r1=0, 
        s1=0, t1=0, u1=0, v1=0, w1=0, x1=0, y1=0, z1=0;
    
    for (int i=0; s[i] != '\0'; ++i)
    {   if (s[i]=='A' || s[i]=='a')
            ++a1;
        else if (s[i]=='B' || s[i]=='b')
            ++b1;
        else if (s[i]=='C' || s[i]=='c')
            ++c1;
        else if (s[i]=='D' || s[i]=='d')
            ++d1;
        else if (s[i]=='E' || s[i]=='e')
            ++e1;
        else if (s[i]=='F' || s[i]=='f')
            ++f1;
        else if (s[i]=='G' || s[i]=='g')
            ++g1;
        else if (s[i]=='H' || s[i]=='h')
            ++h1;
        else if (s[i]=='I' || s[i]=='i')
            ++i1;
        else if (s[i]=='J' || s[i]=='j')
            ++j1;
        else if (s[i]=='K' || s[i]=='k')
            ++k1;
        else if (s[i]=='L' || s[i]=='l')
            ++l1;
        else if (s[i]=='M' || s[i]=='m')
            ++m1;
        else if (s[i]=='N' || s[i]=='n')
            ++n1;
        else if (s[i]=='O' || s[i]=='o')
            ++o1;
        else if (s[i]=='P' || s[i]=='p')
            ++p1;
        else if (s[i]=='Q' || s[i]=='q')
            ++q1;
        else if (s[i]=='R' || s[i]=='r')
            ++r1;
        else if (s[i]=='S' || s[i]=='s')
            ++s1;
        else if (s[i]=='T' || s[i]=='t')
            ++t1;
        else if (s[i]=='U' || s[i]=='u')
            ++u1;
        else if (s[i]=='V' || s[i]=='v')
            ++v1;
        else if (s[i]=='W' || s[i]=='w')
            ++w1;
        else if (s[i]=='X' || s[i]=='x')
            ++x1;
        else if (s[i]=='Y' || s[i]=='y')
            ++y1;
        else if (s[i]=='Z' || s[i]=='z')
            ++z1;
    }
    printf("a:%d b:%d c:%d d:%d e:%d f:%d g:%d h:%d i:%d j:%d k:%d l:%d m:%d n:%d o:%d p:%d q:%d r:%d s:%d t:%d u:%d v:%d w:%d x:%d y:%d z:%d",
    a1,b1,c1,d1,e1,f1,g1,h1,i1,j1,k1,l1,m1,n1,o1,p1,q1,r1,s1,t1,u1,v1,w1,x1,y1,z1);
}

int main(void)
{   // Edit the text to test
    char text[] = "The quick brown fox jumps over the lazy dog!";
    freq(text);
    return 0;
}
