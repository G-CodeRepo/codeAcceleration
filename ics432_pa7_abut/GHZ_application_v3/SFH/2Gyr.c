#include <math.h> 

/*--------------------------------------------------------------*/
double SFR_2Gyr(double x)
/*--------------------------------------------------------------*
   TableCurve Function: F:\\BACKUP\\Documents\\!SCHOOL\\Masters\\SFH- inside out formation\\2Gyr.c Dec 7, 2010 5:58:31 PM 
   C:\\Program Files\\TableCurve2Dv5.01\\CLIPBRD.PRN 
   X= Radius 
   Y= SFR 
   Eqn# 7922  y=(a+cx^2)/(1+bx^2+dx^4) [NL] 
   r2=0.9999998696288206 
   r2adj=0.9999994785152824 
   StdErr=0.09286835249103432 
   Fstat=2556801.982062238 
   a= 299.9999903717304 
   b= 0.9100794373644826 
   c= -11.67989551825468 
   d= 1.293472026912637 
 *--------------------------------------------------------------*/
{
  double y;
  x=x*x;
  y=(299.9999903717304+x*-11.67989551825468)/
    (1.0+x*(0.9100794373644826+x*1.293472026912637));
  return(y);
}
 
