#include<stdio.h>
int factorial(int n){
  if(n==1)
    return 1;
  else
    return n*factorial(n-1);
}
int main(){
  int n;
  scanf(" %d" ,&n );
  int result = factorial(n);
  printf("Factorial of %d = %d ", n, result);
return 0;
}
