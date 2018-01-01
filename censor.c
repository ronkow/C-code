/*
censor.c
-----------
<censor> takes as input a FILE stream <input> and two strings, <match> and <replace>. 
It writes the input text in a new file <censored.txt> with all occurrences of <match> replaced with <replace>.
It then prints to stdout the censored text.
The function allows any lengths of <match> and <replace>.
*/

#include <stdio.h>
#include <string.h>

void to_lower(char *s2)
{   for (int i=0; s2[i]!='\0'; i++)
    {   if (s2[i]>='A' && s2[i]<='Z')	
            s2[i] = s2[i]+32;
    }
    s2[strlen(s2)]='\0';
}

void censor(FILE *input, char *match, const char *replace) 
{   char s1[100];	// Assume each word in the text file is at most 100 characters		
    char s1temp[100];
    char compare[100];
    char tail[100];
    int c;
    int i, j, k;
	
    FILE *fp1;
    fp1 = fopen("censored.txt","w");
	
    to_lower(match); 

    while((fscanf(input,"%s",s1))!= EOF)	// Read word by word
    {  	strcpy(s1temp,s1);
	to_lower(s1temp); 
		
	if (strcmp(s1temp,match)==0)
	    strcpy(s1,replace);
	else 
	{   for (i=0; s1[i]!='\0'; i++)    	
	    {   if (s1[i]==match[0])		// If the first character matches
		{   for (j=0; j<strlen(match); j++)                     
			compare[j] = s1[i+j];
				
		    compare[j]='\0';
            
		    if (strcmp(compare,match)==0)                  
		    {	s1temp[i]='\0';
			strcat(s1temp,replace);                                                        
		
			for (k=0; k<strlen(s1)-i-strlen(match); k++)
			    tail[k] = s1[i+strlen(match) + k];
						
			tail[k]='\0';			
			strcat(s1temp,tail);   
			strcpy(s1,s1temp);						
		    }
		}	
	    }
	}
		
	for(int i=0; s1[i]!='\0'; i++)           
	    putc(s1[i], fp1);
		
	putc(' ', fp1);
			
	if (fgetc(input)=='\n')
	    putc('\n',fp1);	
    }
    fclose(fp1);
	
    fp1 = fopen("censored.txt","r");
    while((c=fgetc(fp1))!=EOF)          
        putc(c, stdout);
    fclose(fp1);
}

int main(void)
{   FILE *fp;
    fp = fopen("filename.txt","r");
    char s1[]="dog";   // Text string <match>
    char s2[]="*";    // Text string <replace>
    censor(fp,s1,s2);
    fclose(fp);
    return 0;
}

/*
filename.txt
------------
Dog the dog in his dog-house dogged a hotdog.
How undogmatic!

censored.txt
------------
* the * in his *-house *ged a hot*.
How un*matic!
*/
