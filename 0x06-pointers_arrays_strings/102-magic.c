#include <stdio.h>

int main(void)
{
  int n;
  int a[5];
  int *p;

  a[2] = 1024;
  p = &n;
  /**
   * write your line of code here...
   * Remember:
   * - you are not allowed to use a
   * - you are not allowed to modify p
   * - only one statement
   * - you are not allowed to code anything else than this line of code
   * - adding a code to print "a[2] = 98" at output
  */
  p[5] = 98;

  printf("a[2] = %d\n", a[2]); //Prints a[2] = 98
  return (0);
 
}
