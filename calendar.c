/*
calendar.c
----------

is_leap_year(year) returns true if the input year is a leap year, false if the input year is not a leap year
days_in_month(month,year) returns the number of days in the input month and year
days_from_epoch(day,month,year) returns the number of days from 1.1.1970 to the input date (positive if after 1.1.1970, negative if before 1.1.1970)
day_of_week(day,month,year) returns the day number, 0 (sunday) to 6 (saturday) for the input date
display_month(month,year) displays the input month and year
*/

#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) 
{
    if ((year%400==0) || (year%4==0 && year%100 != 0))  
    {   return true;
    }
    else
    {   return false; 
	}
}


int days_in_month(int month, int year) 
{
    if (month==2)
	{   if (is_leap_year(year)==1)
		{   return 29;
		}
		else
		{   return 28;
		}
	}
	else if (month==4 || month==6 || month==9 || month==11)
	{   return 30;
	}
	else
	{   return 31;
	}
}


int days_from_epoch(int day, int month, int year) 
{
    int no_days_year = 0;       // Total number of days in full years
    int no_days_month = 0;      // Total number of days in full months during the partial year
    int no_days_day = 0;        // Number of days in partial month
 
    // Find the number of days in the FULL years 
    if (year >= 1971)
    {   for (int full_year = 1970; full_year < year; ++full_year)   // full_year <= year-1
        {   if (is_leap_year(full_year)==1)
            {   no_days_year += 366;
            }
            else
            {   no_days_year += 365;
            }
        }
        no_days_year -= 1;        				// Minus 1 to exclude 1 Jan 1970
    }
    else if (year <= 1968)
    {   for (int full_year = 1969; full_year > year; --full_year)   // full_year >= year+1
        {   if (is_leap_year(full_year)==1)
            {   no_days_year -= 366;
            }
            else
            {   no_days_year -= 365;
            }
        }
    }
    else        			// if year = 1970 or 1969, then there is no FULL year
    {   no_days_year = 0;
    }
	
	
    // Find number of days in the FULL months in the partial year
    if (year >= 1970)
    {   for (int full_month = 1; full_month < month; ++full_month)
        {   no_days_month += days_in_month(full_month, year);
        }
    }
    else    // if year <= 1969
    {   for (int full_month = 12; full_month > month; --full_month)
        {   no_days_month -= days_in_month(full_month, year);
        }
    }
	
	
    // Find number of days in the partial month, subtracting 1 day for 1.1.1970 if year=1970
	if (year == 1970)
	{   no_days_day = day - 1;
	}
	else if (year > 1970)
    {   no_days_day = day;
    }
    else 						// if year <= 1969
    {   no_days_day = day - days_in_month(month, year) - 1;
    }
	
    return no_days_year + no_days_month + no_days_day;
}


int day_of_week(int day, int month, int year) 
{
    int no_days = days_from_epoch(day, month, year);
    int day_number;
    
    if (year >= 1970)
    {   day_number = 4 + no_days%7;         // Thursday + number of days (0 to 6)
    }
    else                                    // year <= 1969
    {   day_number = 4 - (-1*no_days)%7;    // Thursday - number of days (0 to 6)
    }
	
    if (day_number > 6)
    {   return day_number - 7;
    }
    else if (day_number < 0)
    {   return day_number + 7;
    }
    else
    {   return day_number;
    }   
}    



void display_month(int month, int year) 
{
    int first_day = day_of_week(1, month, year);	 // Day of week of 1st of month
      
    printf("  S  M  T  W  T  F  S\n");
	
    for (int i = 1; i <= first_day; ++i)
    {   printf("   ");
    }
    
    for (int i = 1; i <= days_in_month(month, year); ++i)
    {   if ((i+first_day)%7==0)
        {   printf("%3d\n",i);
        }
        else
        {   printf("%3d",i);
        }
    }  
    printf("\n");
}
