// Math Algorithm
// Armstrong Number of n digits
// To find if the sum of its digits raised to the third power is equal to the number.

#include <bits/stdc++.h>
using namespace std;

int main() {
   int num, originalNum, remainder, n = 0, result = 0, power;
   cout << "Enter the number: ";
   cin >> num;

   originalNum = num;

   while (originalNum != 0) {
      originalNum /= 10;
      ++n;
   }
   originalNum = num;

   while (originalNum != 0) {
      remainder = originalNum % 10;

      // pow() returns a double value
      // round() returns the equivalent int
      power = round(pow(remainder, n));
      result += power;
      originalNum /= 10;
   }

   if (result == num)
      cout << num << " is an Armstrong number.";
   else
      cout << num << " is not an Armstrong number.";
   return 0;
}