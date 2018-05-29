#include <stdio.h>
#include <stdarg.h>

double sum_series(int num, ...);


int  main(void)
{
   double d;

   /* d = sum_series(5, 1/5, 1/(5*5), 1/(5*5*5), 1/(5*5*5*5), 1/(5*5*5*5*5) ); */
   d = sum_series(4, 0.5, 0.04, 0.008, 1.0); 

   printf("Sum of series is %f. \n", d);

   return 0; 

}

double sum_series(int num, ...)
{
 
   double sum=0, t;
   va_list argptr;

   /* initialise argptr */
   va_start(argptr, num);

   for ( ; num; num--)
   {
      t = va_arg(argptr, double);  /* get next number */
      sum += t;
   }


   /* do orderly shutdown */
   va_end(argptr);

   return sum;
   
}

