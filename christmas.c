/*
christmas.c
-----------
print_song(n) prints the entire lyrics of The Twelve Days of Christmas, depending on the number of days n entered.
The entire lyrics for n = 12 is shown below after the codes.
*/

#include <stdio.h>

void print_song(int n) 
{
    char lyric[12][33]
    = {"and a partridge in a pear tree.\n",
        "two turtle doves,",
        "three French hens,",
        "four calling birds,",
        "five golden rings,",
        "six geese a laying,",
        "seven swans a swimming,",
        "eight maids a milking,",
        "nine ladies dancing,",
        "ten lords a leaping,",
        "eleven pipers piping,",
        "twelve drummers drumming,"};

    char ordinal[12][9] 
    = {"first","second","third","fourth","fifth","sixth",
       "seventh","eighth","ninth","tenth","eleventh","twelfth"};
    
    for (int k=1; k<=n; k++)
    {   printf("On the %s day of Christmas,\n",ordinal[k-1]);
        printf("my true love sent to me,\n");
        
        if (k==1)
            printf("a partridge in a pear tree.\n\n");
        else
        {   for (int i=1; i<=k; i++)
            printf("%s\n",lyric[k-i]);
        }
    }    
}

int main()
{   // Edit the number of days to test
    print_song(12);
    
    return 0;
}
/*
On the first day of Christmas,
my true love sent to me,
a partridge in a pear tree.

On the second day of Christmas,
my true love sent to me,
two turtle doves,
and a partridge in a pear tree.

On the third day of Christmas,
my true love sent to me,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the fourth day of Christmas,
my true love sent to me,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the fifth day of Christmas,
my true love sent to me,
five golden rings,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the sixth day of Christmas,
my true love sent to me,
six geese a laying,
five golden rings,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the seventh day of Christmas,
my true love sent to me,
seven swans a swimming,
six geese a laying,
five golden rings,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the eighth day of Christmas,
my true love sent to me,
eight maids a milking,
seven swans a swimming,
six geese a laying,
five golden rings,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the ninth day of Christmas,
my true love sent to me,
nine ladies dancing,
eight maids a milking,
seven swans a swimming,
six geese a laying,
five golden rings,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the tenth day of Christmas,
my true love sent to me,
ten lords a leaping,
nine ladies dancing,
eight maids a milking,
seven swans a swimming,
six geese a laying,
five golden rings,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the eleventh day of Christmas,
my true love sent to me,
eleven pipers piping,
ten lords a leaping,
nine ladies dancing,
eight maids a milking,
seven swans a swimming,
six geese a laying,
five golden rings,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.

On the twelfth day of Christmas,
my true love sent to me,
twelve drummers drumming,
eleven pipers piping,
ten lords a leaping,
nine ladies dancing,
eight maids a milking,
seven swans a swimming,
six geese a laying,
five golden rings,
four calling birds,
three French hens,
two turtle doves,
and a partridge in a pear tree.
*/
