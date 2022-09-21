/* This Program was written by Anastasia Wickeler.
This program calculates the roots of a 2-equation system using Newton's Method
The two equations used in this system are y[1]=-(x[1]^2)+(x[1]*x[2])-18 and y[2]=-(x[2]+x[2]^2)+(3*x[1]*x[2]^3)-22 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
      void uvfunction(double fxi[2], double xi[2]);      //declaring function that finds f(x1) and f(x2)
      void linsyssolve(double jacobian[2][2], double fxi[2], double deltax[2]);    //solves 2x2 linear system 

int main ()
{
    ofstream fout;
    fout.open("Newton_Method");
    double xi[2], fxi[2], deltax[2], jacobian[2][2], x[2];   //declaring matricies
    double norm, tol;          //declaring normal and tolerence variables
    int i=0;                   //declares counter 
    
    xi[0]=10.0;                //sets initial guesses for x1 and x2
    xi[1]=10.0;
    
    uvfunction(fxi, xi);       //finds f(x1) and f(x2) in uv function subroutine
    
    printf ("\n\n %lf \t %lf \t %lf \t %lf \n\n", xi[0], xi[1], fxi[0], fxi[1]); 
    fout << xi[0] << "  ";
    fout << xi[1] << "  ";
    fout << fxi[0] << "  ";
    fout << fxi[1] << "  ";
    
    printf ("Please enter a value for the tolerance(use at least one decimal place): ");
    fout << "\nPlease enter a value for the tolerace(use at least one decimal place): ";
    scanf ("%lf", &tol);  //allows tolerence value to be set by user
    
    if (fxi[0]==0.0 && fxi[1]==0.0) {
       printf ("The roots have been found, they are %lf and %lf", xi[0], xi[1]);
       fout << "\nThe roots have been found, they are: ";
       fout << xi[0] << "  ";
       fout << xi[1] << "  ";
       }  //if inital guesses are fight for x1 and x2, the problem is solved
       
    norm=pow((pow(fxi[0],2)+pow(fxi[1],2)),(1.0/2.0)); //finding normal residual vector
    
    printf ("Iteration \t x1 \t\t x2 \t\t u \t\t v \t\t norm \n");
    fout << "\nIteration \t x1 \t\t x2 \t\t u \t\t v \t\t norm \n\n";
    printf ("%d \t\t %lf \t %lf \t %lf \t %lf \t %lf \n\n", i, xi[0], xi[1], fxi[0], fxi[1], norm);
    fout << i << " \t ";
    fout << xi[0] << " \t\t ";
    fout << xi[1] << " \t\t ";
    fout << fxi[0] << " \t\t ";
    fout << fxi[1] << " \t\t ";
    fout << norm << " \n ";
    
    /*entering loop 
    Jacobian matrix is declared, then sent to a subroutine which solves the 
    2 by 2 set of linear equations for x1 and x2
    */
    while (norm>tol)
    { 
       i++;
       jacobian[0][0]=2*xi[0]+xi[1];      //Jacobian matrix set
       jacobian[0][1]=xi[0];
       jacobian[1][0]=3*pow(xi[1],3);
       jacobian[1][1]=1+2*xi[1]+9*xi[0]*pow(xi[1],2);  
       
       linsyssolve(jacobian, fxi, deltax);        //jacobian matrix sent to subroutine
        
       xi[0]=xi[0]+deltax[0];     //adds the change in x to the original x
       xi[1]=xi[1]+deltax[1];
       
       uvfunction(fxi, xi);       //finds new f(x) in subroutine
       
       norm=pow((pow(fxi[0],2)+pow(fxi[1],2)),(1.0/2.0));       //calculates normal residual vector
       
       printf ("%d \t\t %lf \t %lf \t %lf \t %lf \t %lf\n\n", i, xi[0], xi[1], fxi[0], fxi[1], norm);
       fout << i << " \t ";
       fout << xi[0] << " \t ";
       fout << xi[1] << " \t ";
       fout << fxi[0] << " \t ";
       fout << fxi[1] << " \t ";
       fout << norm << " \n ";
       
       }

         printf ("\n\nThe final solution is x= %lf and y= %lf; the norm is %lf", xi[0], xi[1], norm);
         fout << "\n\nThe final solution is x=";
         fout << xi[0] << "  ";
         fout << "and y=";
         fout << xi[1] << "  ";
         fout << "; the norm is";
         fout << norm << "  ";
         
         fout.close();
         getchar();
         system ("pause");
         return 1;
         
}

//This function puts x1 and x2 into the equations given at the beginning of the problem
//They find f(x1) and f(x2)
void uvfunction(double fxi[2], double xi[2]) {
      
    fxi[0]=-(pow(xi[0],2)+xi[0]*xi[1]-18);
    fxi[1]=-(xi[1]+pow(xi[1],2)+3*xi[0]*pow(xi[1],3)-22);
    return;
}

//This function solves the linear system of equations in the jacobian matrix
//It finds the change in x1 and x2 that bring the values closer to the values that are being looked for
void linsyssolve(double jacobian[2][2], double fxi[2], double deltax[2]){
       double ainv[2][2], det;
       
       //finds determinant
       det=((jacobian[0][0]*jacobian[1][1])-(jacobian[0][1]*jacobian[1][0]));
       
       //finds inverse matrix
       ainv[0][0]=(jacobian[1][1]/det);
       ainv[0][1]=-(jacobian[0][1]/det);
       ainv[1][0]=-(jacobian[1][0]/det);
       ainv[1][1]=(jacobian[0][0]/det);
       
       deltax[0]=(ainv[0][0]*fxi[0])+(ainv[0][1]*fxi[1]);      //finds changes in x
       deltax[1]=(ainv[1][0]*fxi[0])+(ainv[1][1]*fxi[1]);
       
       return;

}       
