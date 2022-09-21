/* This Program was written by Anastasia Wickeler.
This program calculates the roots of a 2-equation system using Gaussian Elimination and Partial Pivoting
The two equations used in this system are y[1]=-(x[1]^2)+(x[1]*x[2])-18 and y[2]=-(x[2]+x[2]^2)+(3*x[1]*x[2]^3)-22 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
      void uvfunction(double fxi[2], double xi[2]);      //declaring function that finds f(x1) and f(x2) 
      void gausselimwpp(double jacobian[2][2], double fxi[2], double deltax[2]);   //solves 2x2 linear system 

int main ()
{
    ofstream fout;
    fout.open("Gaussian_Elimination_and_Partial_Pivoting");
	double xi[2], fxi[2], deltax[2], jacobian[2][2], dx[2], nx[2];   //declaring matricies
    double norm, tol, pf;          //declaring normal and tolerence variables
    int i=0;                   //declares counter 
    
    xi[0]=10.0;                //sets initial guesses for x1 and x2
    xi[1]=10.0;
    pf=pow(10,-10);
    
    uvfunction(fxi, xi);       //finds f(x1) and f(x2) in uv function subroutine
    
    printf ("\n\n %lf \t %lf \t %lf \t %lf \n\n", xi[0], xi[1], fxi[0], fxi[1]); 
    
    printf ("Please enter a value for the tolerance(use at least one decimal place): ");
    scanf ("%lf", &tol);  //allows tolerence value to be set by user
    
    if (fxi[0]==0.0 && fxi[1]==0.0) {
       printf ("The roots have been found, they are %lf and %lf", xi[0], xi[1]);
       }  //if inital guesses are fight for x1 and x2, the problem is solved
       
    norm=pow((pow(fxi[0],2)+pow(fxi[1],2)),(1.0/2.0)); //finding normal residual vector
    
    printf ("Iteration \t x1 \t\t x2 \t\t u \t\t v \t\t norm \n");
    printf ("%d \t\t %lf \t %lf \t %lf \t %lf \t %lf \n\n", i, xi[0], xi[1], fxi[0], fxi[1], norm);
    
    /*entering loop 
    Jacobian matrix is declared, then sent to a subroutine which solves the 
    2 by 2 set of linear equations for x1 and x2
    */
    while (norm>tol)
    { 
       i++;
       
       dx[0]=pf*xi[0];            //finds x*the perturbation factor, giving the
       dx[1]=pf*xi[1];            //change in x
       nx[0]=xi[0]+dx[0];         //adds change in x to x
       nx[1]=xi[1]+dx[1];
       
       jacobian[0][0]=(nx[0]*nx[0]-xi[0]*xi[0]+(nx[0]-xi[0])*xi[1])/dx[0];      //Jacobian matrix set
       jacobian[0][1]=((nx[1]-xi[1])*xi[0])/dx[1];
       jacobian[1][0]=((nx[0]-xi[0])*3*pow(xi[1],3))/dx[0];
       jacobian[1][1]=(nx[1]+pow(nx[1],2)+(pow(nx[1],3)-pow(xi[1],3))*3*xi[0]-xi[1]-pow(xi[1],2))/dx[1];      
        
       gausselimwpp(jacobian, fxi, deltax);       //jacobian matrix sent to subroutine
        
       xi[0]=xi[0]+deltax[0];     //adds the change in x to the original x
       xi[1]=xi[1]+deltax[1];
       
       uvfunction(fxi, xi);       //finds new f(x) in subroutine
       
       norm=pow((pow(fxi[0],2)+pow(fxi[1],2)),(1.0/2.0));       //calculates normal residual vector
       
       printf ("%d \t\t %lf \t %lf \t %lf \t %lf \t %lf\n\n", i, xi[0], xi[1], fxi[0], fxi[1], norm);
       
       }

         printf ("\n\nThe final solution is x= %lf and y= %lf; the norm is %lf", xi[0], xi[1], norm);
         
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

void gausselimwpp(double jacobian[2][2], double fxi[2], double deltax[2]) {
     
     double var;           //this variable will be used during gaussian elimination
     int p, c=0, sx, sa;
     
     //This part of the code does the partial pivoting of th matrix
     if (fabs(jacobian[1][0])>fabs(jacobian[0][0])) {  //comparing absolute values of matrix entries
     //if lower value on matrix is larger the rows get switched
        while (c<=1) {
              sa=jacobian[0][c];  
              jacobian[0][c]=jacobian[1][c];
              jacobian[1][c]=sa;
              c++;
              }
        sx=fxi[0];  //switching rows in b matrix 
        fxi[0]=fxi[1];
        fxi[1]=sx;
        }
     
     var=(jacobian[1][0]/jacobian[0][0]);         //find factor to multyply row one by before subtracting row one from row two
     
        //gaussian elimination
        jacobian[1][0]=jacobian[1][0]-var*jacobian[0][0];
        jacobian[1][1]=jacobian[1][1]-var*jacobian[0][1];
        fxi[1]=fxi[1]-var*fxi[0];
     
         //backward substitution
         deltax[1]=fxi[1]/jacobian[1][1];
         deltax[0]=(fxi[0]-deltax[1]*jacobian[0][1])/jacobian[0][0];
         
         return;
         
}
   
