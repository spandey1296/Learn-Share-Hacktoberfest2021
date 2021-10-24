/*  C Program to check triangle is a equilateral, isosceles or scalene  */

#include<stdio.h>
#include<conio.h>

int main()
{
  int x,y,z;
  printf("Enter the sides of a triangle(x,y,z):: \n");
  scanf("%d %d %d",&x,&y,&z);
  if((x==y) && (y==z))
  {
  printf("\nThe triangle is equilateral.");
  }
  else if((x==z) || (y==z) || (x==y))
  {
  printf("\nThe triangle is isoseles.");
  }
  else
  {
  printf("\nThe triangle is scalene.");
  }
return 0;
}
