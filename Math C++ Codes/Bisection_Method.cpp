/* This Program was written by Anastasia Wickeler.
This program is written to find x on the inital interval [0,9] using the Bisection Method
The equation of the line in this probem is (x^3)+(4*x^2)-10 = y*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
         double equation(double b);            //declares subroutine that returns the y for a given x value

int main ()
{
    ofstream fout;
    fout.open("Bisection_Method");
    double xu=9.0, xl=0.0, a, ret, fxl;   //sets initial values and names for numbers.
    /*
    xu is the upper limit
    xl is the lower limit
    a is the average between xu and xl
    ret is the value returned from the equation subroutine when a is given
    txl is the value returned from the equation subrouting when xl is the input
    */
    int iter=1;  //iter is used to count the number of iteration in the for loop
    
    if ((equation(xu)*equation(xl))>0.0) {          //this loop ends the program if the root is not bracketed by the xu and xl values
       printf("Root is not bracketed. No solution possible. ");
       fout << "Root is not bracketed. No solution possible. ";
       
       return 0;
       }
    
    printf("iteration \t xl \t xu \t a \t ret \n\n");    //this is the heading for the values that will be printed in the upcoming loop
    fout << "iteration \t xl \t xu \t a \t ret \n\n";
    
    for (iter=1; iter<100; iter++)     //this loop does iterations of the bysection method
    {
        a=((xl+xu)/2);                 //averages x upper and x lower
        ret=equation(a);               //gives the average a to the equation subroutine
        fxl=equation(xl);              //gives the x lower to the equation subroutine
        cout <<iter << "\t\t";       //these lines print out the # of iterations, the lower and upper x, the average x and the value returned from the subroutine.
        fout <<iter << "\t\t"; 
        cout << xl << "\t";
        fout << xl << "\t";
        cout << xu << "\t";
        fout << xu << "\t";
        cout << a << "\t";
        fout << a << "\t";
        cout << ret << "\n"; 
        fout << ret << "\n";
        
        if((fxl*ret)<0.0){           //designates the x upper to be the average a if f(xl)*ret is less than 0
                  xu=a;
                  }
        if((fxl*ret)>0.0) {          //designates the x lower to be the average a if f(xl)*ret is greater than 0
                  xl=a;
                  }
        if(-0.000001 < ret & ret < 0.000001){
                   printf("The exact root is: ");
                   fout <<"The exact foot is:  ";
                   cout << a << "  ";
                   fout << a << "  ";
                   printf("The number of iterations used was:  ");  
                   fout <<"The number os iterations used was:  ";         
                   cout << iter << "  ";
                   fout << iter << "  ";
                   //%d. The number of iterations used was: %i", ((xu+xl)/2), iter);
                   break;
                   }
        if(iter==99){
                    printf("No root can be found. return is %d.", ret);
                    fout << "No root can be found. return is ";
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
