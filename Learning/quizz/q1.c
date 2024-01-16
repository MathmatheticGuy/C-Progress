#include<stdio.h>

int main(){
  int a = 1;
  int b = 0;

  b = ++a + ++a + ++a + ++a;  // b = 1 + 2 = 3. addition happened first then a increment later
  
  printf("%d %d",a,b);

  return 0;
}
