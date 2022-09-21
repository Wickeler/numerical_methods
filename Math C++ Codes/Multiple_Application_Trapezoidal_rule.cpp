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
    double a, b, n, p, nmax, h, x, fi, fsum, fa, fb, i, I, e;
    
    printf ("Please enter an a value (lower interval number):");  //asks user for lower interval value
    scanf ("%lf", &a);       //gets the number inputed by the used and stores it as a
    
    printf ("Please enter a b value (higher interval number):");   //asks user for upper interval number
    scanf ("%lf", &b);      //gets the number inputed by the user and stores it as b
    
    printf ("What is the highest segment application of the trapezoidal that you would like (n) ?");
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
        
        //loop to sum internal f(x) values
        for (i=1; i<n; i++)

        {
            p=a+h*i;
            fi=0.2+25*p-200*p*p+675*pow(p,3)-900*pow(p,4)+400*pow(p,5);  //finds f(x) values
            fsum=fsum+fi;     //sums f(x) values
            }
            
        I=(h/2.0)*(fa+(2.0*fsum)+fb);  //calculates integral
        
        e=(1.640533-I)/1.640533*100;   //calculates error
        
        fsum=0;   //set sum if f(x) values back to zero for next run of the inner loop
        
        //printing out n, step size, integral and error
        printf ("%lf \t %lf \t %lf \t %lf \t\n", n, h, I, e);  
        
        }
            
        system ("pause");
        return 1;
        
}
            
            
            
            
            
            
            
        
