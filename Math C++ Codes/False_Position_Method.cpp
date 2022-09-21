/* This Program was written by Anastasia Wickeler.
This program is written to find x on the inital interval [0,9] using the False position method Method
The equation of the line in this probem is (x^3)+(4*x^2)-10 = y*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
         double equation(double b);           //declares subroutine that returns the y for a given x value

int main ()
{
    ofstream fout;
    fout.open("False_Position_Method");
    double xu=9.0, xl=0.0, a, ret, fxu, fxl, xr;          //sets initial values and names for numbers.     
    int iter=1;
    /*xu is the upper limit
    xl is the lower limit
    a is the average between xu and xl
    ret is the value returned from the equation subroutine when a is given
    txl is the value returned from the equation subrouting when xl is the input*/
    
    if ((equation(xu)*equation(xl))>0.0) {      //this loop ends the program if the root is not bracketed by the xu and xl values
       printf("Root is not bracketed. No solution possible. ");
       fout << "Root is not bracketed. No solution possible. ";
       return 0;
       }
    
    printf("iter \t xl \t xu \t xr \t ret. \n\n");     //printing headings for values that are later outputed
    fout << "iter \t xl \t xu \t xr \t ret. \n\n";
    
    //loop that will continue iterations of the false position method until the value is close enough to where y=0 or 50 iterations have been reached
    for (iter=1; iter<=50; iter++)
    {

        fxu=equation(xu);                    //sending x values to the subroutine to get their corresponding y values   
        fxl=equation(xl);
        xr=((xl*fxu)-(xu*fxl))/(fxu-fxl);
        ret=equation(xr);
        cout <<iter << "\t";             //these line print out the number of iterations, lower, upper and returned x and the return
        cout << xl << "\t\t";
        cout << xu << "\t";
        cout << xr << "\t\t";
        cout << ret << "\t\n";
        fout <<iter << "\t";
        fout << xl << "\t\t";
        fout << xu << "\t";
        fout << xr << "\t\t";
        fout << ret << "\t\n";
        
        if(ret<0.0){        //setting x lower to x returned of the return is less than 0
                  xl=xr;
                  }
        
        if(-0.000001 < ret && ret < 0.000001){  //printing out final answer once the return falls within the acceptable tolerance, then ends loop
                   printf("The exact root is: ");
                   fout << "The exact root is: ";
                   cout << xr << "  ";
                   fout << xr << "  ";
                   printf("The number of iterations used was:  ");           
                   fout << "The number of iterations used was:  ";
                   cout << iter << "  ";
                   fout << iter << "  ";

                   break;
                   }
        if(iter==50){      //ends loop if an acceptable solution cannot be found within 50 iterations
                    printf("No root can be found. return is:");
                    fout << "No root can be found. return is: ";
                    cout << ret << "  ";
                    fout << ret << "  ";
                    }
            
    
    }
    
    fout.close();
    getchar();
    system ("pause");
    
    return 0;
}
  
//this function calculates the y value for a given x   
double equation(double b)
{
     double y;
     y=(b*b*b)+(4.0*b*b)-10.0;
     return y;
     
}
