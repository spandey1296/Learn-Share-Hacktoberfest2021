// importing the required libraries
#include<iostream>
#include<cstdlib>
using namespace std;
// function to find the gcd
int gcd(int a, int b) {
   if (a == 0 || b == 0)
    return 0;
   else if (a == b)
    return a;
   else if (a > b)
    return gcd(a-b, b);
   else 
    return gcd(a, b-a);
}
// initializaing the main method
int main() {
   // local variables
   int max,lcm;
   max = 100;
   srand(time(0));
   // generating the random numbers
   int val1 = rand()%max;
   int val2 = rand()%max;
   // displaying the gcd of two numbers
   cout<<"GCD of "<< val1 <<" and "<< val2 <<" is "<< gcd(val1,val2);
   cout<<"\n";
   // finding lcm
   if(val1>val2)
    lcm = val1;
   else
    lcm = val2;
   // itering over the loop
   while(1) {
      if( lcm%val1==0 && lcm%val2==0 ) {
         // displaying the lcm
         cout<<"The LCM of "<<val1<<" and "<<val2<<" is "<<lcm;
         break;
      }
      lcm++;
   }
}