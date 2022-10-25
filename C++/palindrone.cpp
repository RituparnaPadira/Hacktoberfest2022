#include<iostream>
using namespace std;
// Function to check if a number is a palindrome or not.
int Palindrome(int n)
{
// Find reverse of n
int reverse = 0;
for (int i = n; i > 0; i /= 10)
reverse = reverse*10 + i%10;
// To check if they are same
return (n==reverse);
}
//function to prints palindrome between a minimum and maximum number
void countPalindrome(int minimum, int maximum)
{
for (int i = minimum ; i <= maximum; i++)
if (Palindrome(i))
cout << i << " ";
}
// program to test above functionality
int main()
{
countPalindrome(100,2000);
return 0;
}
