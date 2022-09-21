/* This Program was written by Anastasia Wickeler.
This program is for multiple application trapezoidal rule
The equation for which the integral is being estimated is:
f(x) = 0.2+25*x-200*x^2+675*x^3-900*x^4+400*x^5 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

int main ()
{
    double a, b, n,p, nmax, h, x, fi, osum, fa, fb, I, e, esum;
    int i;
    
     printf ("Please enter an a value (lower interval number):");  //asks user for lower interval value
    scanf ("%lf", &a);       //gets the number inputed by the used and stores it as a
    
    printf ("Please enter a b value (higher interval number):");   //asks user for upper interval number
    scanf ("%lf", &b);      //gets the number inputed by the user and stores it as b
    
    printf ("What is the highest segment application of the 1/3 Simpson's rule that you would like (n) ?");
    scanf ("%lf", &nmax);        //get the value that will be the highest trapezoidal segment application and stored it as nmax
    
    printf ("n \t\t h \t\t I \t\t et% \t\t\n\n");  //prints headings for chart
    
    //entres a into initial function
    fa=0.2+25*a-200*a*a+675*pow(a,3)-900*pow(a,4)+400*pow(a,5);  
    //entres b into initial function
    fb=0.2+25*b-200*b*b+675*pow(b,3)-900*pow(b,4)+400*pow(b,5);
    
    //loop the performs trapezoidal equations and prints out results
    for (n=2; n<=nmax; n++)
    {
        h=(b-a)/n;     //calculates h value
        
        //loop that sums the f(x) with even and odd i values seperately
        for (i=1; i<n; i++)
        {
            p=a+h*i;
            fi=0.2+25*p-200*p*p+675*pow(p,3)-900*pow(p,4)+400*pow(p,5);  //calculation f(x)
            if ((i%2)==0) //checking for an even i 
            esum=esum+fi; //if even, adding f(x) to the sum
            if ((i%2)!=0) //checking for odd i
            osum=osum+fi; //if odd, adding f(x) to the sum
            }
            
        I=(h/3.0)*(fa+(2.0*esum)+(4.0*osum)+fb);   //calculating the integral
        
        e=(1.640533-I)/1.640533*100;  //calculating the error
        
        esum=0;      //setting the even and odd sums to zero to prepare for the next loop
        osum=0;
        
        //printing out n, step size, integral and error
        printf ("%lf \t %lf \t %lf \t %lf \t\n", n, h, I, e); 
        
        }
            
        system ("pause");
        return 1;
        
}

            
            
      
