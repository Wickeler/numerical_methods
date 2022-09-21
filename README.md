# numerical_methods
All codes were written by Anastasia Wickeler and compiled in DevC++
The codes in the folder use numerical methods to solve mathematical problems. 
The functions of the codes are as follows:

Bisection_Method - finds the root of the equation y=(x^3)+(4*x^2)-10 using the bisection method bracketing technique. Bracketing Methods are used to find the root of an equation. These techniques require two initial guesses for the root that bracket (one higher and one lower) than the root.
False_Position_Method - finds the root of the equation y=(x^3)+(4*x^2)-10 using the false-position method bracketing technique.
Secant_Method - finds the root of the equation y=(-2.4*x^3)+(18*x^2)-(21*x)-12 using the Secant method. This is an open method that finds the root of an equation with only a single inital guess value.
Newton_Method - finds the roots of a 2-equation systems using Newton's method. The two equations are y[1]=-(x[1]^2)+(x[1]*x[2])-18 and y[2]=-(x[2]+x[2]^2)+(3*x[1]*x[2]^3)-22.
Multivariable_Modified_Secant_Method - finds the roots of a 2-equation systems using the multivariable modified secant method. The two equations are y[1]=-(x[1]^2)+(x[1]*x[2])-18 and y[2]=-(x[2]+x[2]^2)+(3*x[1]*x[2]^3)-22.
Naive_Gaussian_Elimination - finds the roots of a 2-equation systems using naive Gaussian elimination. The two equations are y[1]=-(x[1]^2)+(x[1]*x[2])-18 and y[2]=-(x[2]+x[2]^2)+(3*x[1]*x[2]^3)-22.
Gaussian_Elimination_and_Partial_Pivoting - finds the roots of a 2-equation systems using Gaussian elimination and partial pivoting. The two equations are y[1]=-(x[1]^2)+(x[1]*x[2])-18 and y[2]=-(x[2]+x[2]^2)+(3*x[1]*x[2]^3)-22.
Gaussian_Elimination_and_Partial_Pivoting_3equ - finds the roots of a 3-equation systems using Gaussian elimination and partial pivoting. The three equations are y[1]=-(x[1]^2)+(x[1]*x[2])+(4*x[2]^2*x[3]^4)-(x[3]^-1)-18, y[2]=-(x[2]*x[3])+(x[2]^2)+(3*x[1]*x[2]^3)-(x[3])-22, and y[3]=-(x[1]*x[2]*x[3])+(x[1]^2*x[3]*x[2]^2)+(2*x[1]*x[2]^3)-(2*x[3])-5.
Multiple_Application_Trapezoidal_rule - finds the estimate of an integral (area under a curve) using the multiple application trapezoidal rule. The equation being integrated is f(x) = 0.2+25*x-200*x^2+675*x^3-900*x^4+400*x^5.
Multiple_Application_Simpson_rule - finds the estimate of an integral (area under a curve) using the multiple application Sompson rule. The equation being integrated is f(x) = 0.2+25*x-200*x^2+675*x^3-900*x^4+400*x^5.
