/* 4 versions of Euclid's algorithm */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/* Euclid's Algorithm  */
//  Complexity: O(n)
int gcd(int a, int b) 
{ 
    return ( b == 0 ? a : gcd(b, a % b) ); 
}



/* Budd, "Data Structures in C++ using STL, p 55 */
//  Complexity: O(n)
int gcd1(int m, int n)
{
    assert(n>0 && m>0);
    
    while(m!=n)
    {
        if(n>m)
            n=n-m;
        else
            m=m-n;
    }            
    return n;
}

/*

def gcd(a, b, res):
    if a == b:
    return res * a
    elif (a % 2 == 0) and (b % 2 == 0):
    return gcd(a // 2, b // 2, 2 * res)
    elif (a % 2 == 0):
    return gcd(a // 2, b, res)
    elif (b % 2 == 0):
    return gcd(a, b // 2, res)
    elif a > b:
    return gcd(a - b, b, res)
    else:
    return gcd(a, b - a, res)
*/


/*  LCM(a,b) = ab/gcd(a,b)  */
//  Binary gcd - Stein Algorithm
//  Complexity: O(log(n))
unsigned int gcd3(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;
 
    if (u == 0)
        return v;
 
    if (v == 0)
        return u;
 
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd3(u >> 1, v);
        else // both u and v are even
            return gcd3(u >> 1, v >> 1) << 1;
    }
 
    if (~v & 1) // u is odd, v is even
        return gcd3(u, v >> 1);
 
    // reduce larger argument
    if (u > v)
        return gcd3((u - v) >> 1, v);
 
    return gcd3((v - u) >> 1, u);
}



//  Complexity: O(log(n)) - Stein Algorithm
unsigned int gcd4(unsigned int u, unsigned int v)
{
  int shift;
 
  /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
  if (u == 0) return v;
  if (v == 0) return u;
 
  /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }
 
  while ((u & 1) == 0)
    u >>= 1;
 
  /* From here on, u is always odd. */
  do {
       /* remove all factors of 2 in v -- they are not common */
       /*   note: v is not zero, so while will terminate */
       while ((v & 1) == 0)  /* Loop X */
           v >>= 1;
 
       /* Now u and v are both odd. Swap if necessary so u <= v,
          then set v = v - u (which is even). For bignums, the
          swapping is just pointer movement, and the subtraction
          can be done in-place. */
       if (u > v) {
         unsigned int t = v; v = u; u = t;}  // Swap u and v.
       v = v - u;                       // Here v >= u.
     } while (v != 0);
 
  /* restore common factors of 2 */
  return u << shift;
}

int main(int argc, char**argv)
{
    printf("gcd(25,10) = %d\n", gcd(25,10));   
    printf("gcd1(25,10) = %d\n", gcd1(25,10));   
    printf("gcd3(25,10) = %d\n", gcd3(25,10)); 
    printf("gcd4(25,10) = %d\n", gcd4(25,10)); 
    return 0;
}
