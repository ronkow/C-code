/*
rgb_to_hsl.c
------------
The function rgb_to_hsl takes in 3 integers representing Red, Green and Blue, each on a scale of 0–255. 
The function converts the RGB colours into its closest HSL representation,
where 0 < Hue < 360, and both Saturation and Luminance are on a scale of 0–100. 
All three values are rounded to the nearest integers. 
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct HSL 
{   int hue;
    int sat;
    int lum;
} HSL;

HSL rgb_to_hsl(int red, int green, int blue) 
{   int hue, sat, lum;  
    int max, min;						// max and min of R G B (0 to 255)
    float lum_scaled;						// luminance scaled from 0 to 1.0					
	
	  // Find max and min of RGB
    max = red;
    if (green > max) 
        max = green;
       
    if (blue > max) 
        max = blue;  
        
    min = red;
    if (green < min) 
        min = green;
       
    if (blue < min) 
        min = blue;   
    
	
    // Calculate Luminance
    lum_scaled = (max/255.0 + min/255.0) / 2.0;       // Luminance from 0 to 1.0
    lum = round(lum_scaled * 100.0);                // Luminance in %
    
    if (max == min)                                 // IF R = G + B
    {   hue = 0;
        sat = 0;
    }
    else                                            // IF not all R G B are equal             
    {   // Calculate Saturation
        if (lum_scaled < 0.5)                       // IF Luminance < 50%
            sat = round(((max/1.0 - min/1.0)/(max/1.0 + min/1.0))*100.0);
        else                                   		  // IF Luminance >= 50%
            sat = round (((max/255.0 - min/255.0)/(2.0 - max/255.0 - min/255.0))*100.0);
            
        // Calculate Hue in degrees 
        if (max == red)
            hue = round (((green/1.0 - blue/1.0)/(max/1.0 - min/1.0))*60.0);
        else if (max == green)
            hue = round ((2 + (blue/1.0 - red/1.0)/(max/1.0 - min/1.0))*60.0);
        else                                        // IF (max == blue)						
            hue = round ((4 + (red/1.0 - green/1.0)/(max/1.0 - min/1.0))*60.0);
        
        // If Hue < 0, add 360
        if (hue < 0)
            hue += 360;
    }
    return (HSL){.hue=hue, .sat=sat, .lum=lum};
}

int main(void) 
{   // edit these RGB values to test
    int red = 24;
    int green = 98;
    int blue = 118;
    
    HSL hsl = rgb_to_hsl(red, green, blue);
    printf("The result is Hue:%d, Sat:%d, Lum:%d\n", hsl.hue, hsl.sat, hsl.lum);

    return 0;
}
