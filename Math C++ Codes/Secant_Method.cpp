/* This Program was written by Anastasia Wickeler.
This program is written to find the root of the given equation using the secant method
The equation of the line in this probem is (-2.4*x^3)+(18*x^2)-(21*x)-12 = y*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
         double equation(double b);

int main ()
{
    ofstream fout;
    fout.open("Secant_Method");
    //declaring variables
    double equation(double b);
    double xu=2.8, xl=2.6, ret, fxu, fxl, x, fx;
    int iter=1;
    
    printf("iter \t xl \t xu \t x \t return \n\n");  //prints headings on screen
    fout << "iter \t xl \t xu \t x \t return \n\n";
    
    for (iter=1; iter<6; iter++)
    {
        fxu=equation(xu);   //finds y value for upper x
        fxl=equation(xl);   //finds y value for lower x
        x=xu-((fxu*(xu-xl))/(fxu-fxl));
        
        cout << iter << "\t";           //prints out the number of iterations, upper, lower and 
        cout << xl << "\t";            //middle x and f(x)
        cout << xu << "\t";
        cout << x << "\t";
        cout << fx << "\t\n";
        fout << iter << "\t";           
        fout << xl << "\t";           
        fout << xu << "\t";
        fout << x << "\t";
        fout << fx << "\t\n";
        
        xl=xu;  //declares the x lower to be x upper
        xu=x;   //declares x upper to be new x
        fx=equation(x);
        
        //This loop end the larger loop when an answer that satisfies the tolerance of 0.000001 is found
        if(-0.000001 < fx && fx < 0.000001){
                   printf("The exact root is: ");
                   fout << "The exact root is: ";
                   cout << x << "  ";
                   fout << x << "  ";
                   printf("The number of iterations used was:  ");      
                   fout << "The number of iterations used was:  ";
                   cout << iter << "  ";
                   fout << iter << "  ";
                   system("pause");
                   break;
                   }
        //This loop ends the program if an acceptable solution is not found within 5 iterations
        if(iter==5){
                    printf("No root can be found. return is %d.", ret);
                    }
        }          
    
    
    fout.close();
    getchar();  
    system("pause"); 
    return 0;
}
    
//this subrouting puts the given x value into the appropriate equation and calculates the respective y value    
double equation(double b)
{
     double y;
     y=-12-(21*b)+(18*b*b)-(2.4*b*b*b);
     return y;
     
}

