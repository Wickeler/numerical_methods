/* This Program was written by Anastasia Wickeler.
This program calculates the roots of a 3-equation system using Gaussian Elimination and Partial Pivoting
The three equations used in this system are: 
y[1]=-(x[1]^2)+(x[1]*x[2])+(4*x[2]^2*x[3]^4)-(x[3]^-1)-18
y[2]=-(x[2]*x[3])+(x[2]^2)+(3*x[1]*x[2]^3)-(x[3])-22
y[3]=-(x[1]*x[2]*x[3])+(x[1]^2*x[3]*x[2]^2)+(2*x[1]*x[2]^3)-(2*x[3])-5*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
      void uvfunction(double fxi[3], double xi[3]);      //declaring function that finds f(x1) and f(x2) 
      void partialpivot( double jacobian[3][3], int k, double fxi[3]);

int main ()
{
	double xi[3], fxi[3], deltax[3], jacobian[3][3], dx[3], nx[3];   //declaring matricies
    double norm, tol, pf, f;          //declaring normal and tolerence variables
    int i, j, k, p;                   //declares counter 
    
    xi[0]=10.0;                //sets initial guesses for x1 and x2
    xi[1]=10.0;
    xi[2]=10.0;
    pf=pow(10,-12);
    
    uvfunction(fxi, xi);       //finds f(x1) and f(x2) in uv function subroutine
    
    printf ("\n\n %lf \t %lf \t %lf \t %lf \t %lf \t %lf \n\n", xi[0], xi[1], xi[2], fxi[0], fxi[1], fxi[2]); 
    
    printf ("Please enter a value for the tolerance(use at least one decimal place): ");
    scanf ("%lf", &tol);  //allows tolerence value to be set by user
    
    if (fxi[0]==0.0 && fxi[1]==0.0 && fxi[2]==0.0) {
       printf ("The roots have been found, they are %lf, %lf and %lf", xi[0], xi[1], xi[2]);
       }  //if inital guesses are fight for x1 and x2, the problem is solved
       
    norm=pow((pow(fxi[0],2)+pow(fxi[1],2)+pow(fxi[2],2)),(1.0/2.0)); //finding normal residual vector
    
    printf ("Iteration \t x \t\t y \t\t  z \t\t  u \t\t v \t\t w \t\t norm \n");
    printf ("%d \t\t %lf \t %lf \t %lf \t %lf \t %lf \n\n", i, xi[0], xi[1], xi[2], fxi[0], fxi[1], fxi[2], norm);

    
    /*entering loop 
    Jacobian matrix is declared, then sent to a subroutine which solves the 
    3 by 3 set of linear equations for x1 and x2
    */
    while (norm>tol)
    { 
       i++;
       
       dx[0]=pf*xi[0];             //finds x*the perturbation factor, giving the
       dx[1]=pf*xi[1];             //change in x
       dx[2]=pf*xi[2];             //adds change in x to x
       nx[0]=xi[0]+dx[0];
       nx[1]=xi[1]+dx[1];
       nx[2]=xi[2]+dx[2];      
       
       jacobian[0][0]=(nx[0]*nx[0]-xi[0]*xi[0]+(nx[0]-xi[0])*xi[1])/dx[0];      //Jacobian matrix set
       jacobian[0][1]=((nx[1]-xi[1])*xi[0])+4*pow(xi[2],4)*(pow(nx[1],2)-pow(xi[1],2))/dx[1];
       jacobian[0][2]=((pow(nx[2],4)-pow(xi[2],4))*4*pow(xi[1],2)-(pow(nx[2],-1)-pow(xi[2],-1)))/dx[2];
       jacobian[1][0]=((nx[0]-xi[0])*3*pow(xi[1],3))/dx[0];
       jacobian[1][1]=((nx[1]-xi[1])*xi[2]+pow(nx[1],2)+(pow(nx[1],3)-pow(xi[1],3))*3*xi[0]-pow(xi[1],2))/dx[1];   
       jacobian[1][2]=((nx[2]-xi[2])*xi[1]-nx[2]+xi[2])/dx[2];
       jacobian[2][0]=((nx[0]-xi[0])*xi[1]*xi[2]+(pow(nx[0],2)-pow(xi[0],2))*xi[2]*pow(xi[1],2)+2*(nx[0]-xi[0])*pow(xi[1],3))/dx[0];
       jacobian[2][1]=(xi[0]*(nx[1]-xi[1])*xi[2]+pow(xi[0],2)*xi[2]*(pow(nx[1],2)-pow(xi[1],2))+2*xi[0]*(pow(nx[1],3)-pow(xi[1],3)))/dx[1];
       jacobian[2][2]=(xi[0]*xi[1]*(nx[2]-xi[2])+pow(xi[0],2)*(nx[2]-xi[2])*pow(xi[1],2)-2*(nx[2]-xi[2]))/dx[2];   
        
       //loop that solves the equations using Gaussian Elimination with a partial pivoting sub routine
       for (k=0; k<2; k++) {
           partialpivot(jacobian, k, fxi);
           for (i=k+1; i<3; i++) {
               f=jacobian[i][k]/jacobian[k][k];
               for (j=k+1; j<3; j++) {
                   jacobian[i][j]=jacobian[i][j]-f*jacobian[k][j];
                   }
                   fxi[i]=fxi[i]-f*fxi[k];
               }
           }
        
       deltax[2]=fxi[2]/jacobian[2][2];              //finds the change in x
       deltax[1]=(fxi[1]-deltax[2]*jacobian[1][2])/jacobian[1][1];
       deltax[3]=(fxi[0]-deltax[1]*jacobian[0][1]-deltax[2]*jacobian[0][2])/jacobian[0][0];                   

       xi[0]=xi[0]+deltax[0];     //adds the change in x to the original x
       xi[1]=xi[1]+deltax[1];
       xi[2]=xi[2]+deltax[2];
       
       uvfunction(fxi, xi);       //finds new f(x) in subroutine
       
       norm=pow((pow(fxi[0],2)+pow(fxi[1],2)+pow(fxi[2],2)),(1.0/2.0));       //calculates normal residual vector
       
       printf ("%d \t\t %lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %lf\n\n", i, xi[0], xi[1], xi[2], fxi[0], fxi[1], fxi[2], norm);
       
       }

         printf ("\n\nThe final solution is x= %lf and y= %lf; the norm is %lf", xi[0], xi[1], norm);
         
         getchar();
         system ("pause");
         return 1;
         
}

//This function puts x1, x2 and x3 into the equations given at the beginning of the problem
//They find f(x1), f(x2) and f(x3)
void uvfunction(double fxi[3], double xi[3]) {
      
    fxi[0]=-(pow(xi[0],2)+xi[0]*xi[1]+4*pow(xi[1],2)*pow(xi[2],4)-pow(xi[2],-1)-18);
    fxi[1]=-(xi[1]*xi[2]+pow(xi[1],2)+3*xi[0]*pow(xi[1],3)-xi[2]-22);
    fxi[2]=-(xi[0]*xi[1]*xi[2]+pow(xi[0],2)*xi[2]*pow(xi[1],2)+2*xi[0]*pow(xi[1],3)-2*xi[2]-5);
    return;
}

//partial pivoting sub routine
void partialpivot(double jacobian[3][3], int k, double fxi[3])
{
     int p=k, ii, jj;
     double initial, lower;
     
     initial=fabs(jacobian[k][k]);       
     
     for (ii=k+1; ii<3; ii++);
     {
         lower=fabs(jacobian[ii][k]);
     //this loops find which row(p) is the largest
     if (lower>initial) 
        {
            lower=initial;
            p=ii;
        }
     }
     
     //if the upper matrix is not the largest then the rows get switched in this loop
     if (p!=k) 
     {
        for (jj=k; jj<3; jj++) 
        {
            lower=jacobian[p][jj];
            jacobian[p][jj]=jacobian[k][jj];
            jacobian[k][jj]=lower;
        }
        //switching b matrix values
        lower=fxi[p];
        fxi[p]=fxi[k];
        fxi[k]=lower;
     }
        
     return;
}
