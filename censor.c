/*
censor.c
-----------
<censor> takes as input a FILE stream <input> and two strings, <match> and <replace>. 
It prints to stdout the input text with all occurrences of <match> replaced with <replace>.
*/

// char_count counts the number of characters in the text file
int char_count(FILE *input)
{   int c, number_of_c=0;
    while ((c=fgetc(input))!=EOF)       
        number_of_c++;
    return number_of_c;
}

void censor(FILE *input, const char *match, const char *replace) 
{   int max = char_count(input);        // number of characters in the text file + 1
    char s[max];	                      // Array to store the entire text in text file
    int i=0;                            // Array index for entire text (uncensored and censored)
    int c;                              // Character in entire text 
    
    char match_lower[strlen(match)+1];  // Array to store lower case of <match string> (ie, "dog" in test case)
    char compare[strlen(match)+1];      // Array to store string to match with <match string>     
    char temp[max];                     // Array to store entire censored string
    char temp1[max];                    // Array to store the string between two occurences of <match string>
    char tail[max];                     // Array to the string after the last occurence of <match string>

    rewind(input);                      // Go back to the start of the text file
    
    while ((c=fgetc(input))!=EOF)       // Store text in array s[]
	  {	  s[i] = c;
          i++;
    }
    s[i]='\0';

    for (int i=0; match[i]!='\0'; i++)      // If any character in <match> is an uppercase letter, change it to lowercase, store it in <match_lower>
    {   if (match[i]>='A' && match[i]<='Z')
            match_lower[i] = match[i]+32;
        else
            match_lower[i] = match[i];
    }
    match_lower[strlen(match)]='\0';

    
    int j, k, index=0;
    
    for (i=0; s[i]!='\0'; i++)      
    {   if (s[i]==match_lower[0] || s[i]+32==match_lower[0])    // If the first character matches
        {
            for (j=0; j<strlen(match); j++)                     
            {   if (s[i+j]>='A' && s[i+j]<='Z')
                    compare[j] = s[i+j]+32;                     // Store the lowercase character
                else
                    compare[j] = s[i+j];
            }
            compare[j]='\0';
            
            if (strcmp(compare,match_lower)==0)                 // If compare[] and match_lower[] are identical
            {   if (index==0)                                   // First occurence of <match string> in entire text 
                {   for (k=0; k<i; k++)
                        temp[k]=s[index+k];         
                    temp[k]='\0';

                    strcat(temp,replace);                                        
                }        
                else                                            // Subsequent occurences of <match string> in entire text
                {   for (k=0; k<i-index; k++)
                        temp1[k]=s[index+k];         
                    temp1[k]='\0';

                    strcat(temp,temp1);
                    strcat(temp,replace);
                }
                index = i + strlen(match);                      
            }   
        }
    }
    
    for (k=0; k < strlen(s)-index; k++)
        tail[k] = s[index + k];
    tail[k]='\0';

    strcat(temp,tail);                      // Join the last part of the censored string

    input = fopen("censored.txt","w+");     // Open new file to write/read the entire censored string
    
    for(i=0; temp[i]!='\0'; i++)            // Write the string in temp to the new file
        putc(temp[i], input);
        
    rewind(input);                          // Go back to the start of the text file

    while ((c=fgetc(input))!=EOF)          
        putc(c, stdout);                   // Output the censored string
}

int main(void)
{
    FILE *fp;
    fp = fopen("filename.txt","r");
    char s1[]="xxxx";   // Text string <match>
    char s2[]="***";    // Text string <replace>
    censor(fp,s1,s2);
    fclose(fp);
    return 0;
}
