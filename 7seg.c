to interface seven segment display (0-9) – Single module
// Code to interface 7 Segment Display 1 module withh 8051 

#include<reg51.h>
void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

void main()
{
    unsigned char to_disp[]={0x3F,0x06,0x5B,0x4F,0x66,        // Array for hex values (0-F) for
			     0x6D,0x7D,0x07,0x7F,0x6F}        // common anode 7 segment
    int k;
    while(1)
    {
        for(k=0;k<10;k++);
        {
         P2=to_disp[k]; 
         msdelay(100);
        }
    }