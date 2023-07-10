//a program to convert numbers from any base to any base (without Hexa decimal)
#include<iostream>
#include<math.h>
using namespace std ;
int main ()
{
 int num ;
 int sum =0 ;
 int i =0;
 int base ;
 int base2 ;
 cout <<"enter the base of the number which you are giving input  : "<<endl;
 cin >> base ;
  cout <<"enter the base in which you want to convert in : "<<endl;
 cin >>base2 ;
 cout <<"enter number before the decimal point : "<<endl;
 cin>> num ;
  //we're separating the digits by dividing by 10. we're taking the remainder and multiplying with base to the power i.where i depends on the position of the digit
 while (num>0)
 {
     sum = sum + (num%10)*pow(base,i);
     num=num/10;
// as num is an intiger type variable it will only take the numbers which are before the decimal point.
     i++;
 }
 int num2 ;
 int sum2 = 0 ;
 cout << "enter number after decimal point : "<< endl;
 cin>> num2 ;
 // we're reversing the number for easier operation.
 while (num2 > 0)
 {
   sum2 = sum2*10 + num2 %10 ;
   num2 = num2 /10;
 }
 int num3 = sum2 ;
 float sum3 =0 ;
 int i2 = -1 ;
  //we're now multiplying the reversed number with base to the power i2.where i2 is negative and depends on the position of the digit
 while (num3 > 0)
 {
   sum3 = (float)sum3 + (num3 % 10)*pow((float)base,i2);
   num3 = num3 /10 ;
   i2 -- ;
 }
 if(base2 == 10)
 {
 cout<<"decimal number is : "<< sum+sum3 <<endl ;
 }
 // any base to decimal is completed here. now we'll do decimal to any base
else
{
 int sumPrime =0;
 int quotient ;
 int remainder ;
 // for the digits before decimal point we're doing this operation .
 while(sum > 0)
 {
quotient =sum / base2 ;
remainder = sum % base2 ;
sumPrime = sumPrime  * 10 + remainder;
sum = quotient ;
 }
 int reverse = 0 ;
 // we're reversing the number because the MSB(Most Significant Bit) is the last digit and LSB(Least Significant Bit ) is the 1st digit.
 while ( sumPrime >0)
 {
     reverse = reverse *10 + sumPrime%10 ;
     sumPrime = sumPrime/10 ;
 }
int sumQuotient = 0;
int  product ;
int finalNum = (sum3*10)+1 ;
   // as finalNum is an integer type variable and it can't detect the digits after decimal point, we're multiplying it with 10.
   //we're adding 1 because if we multiply a number with 10 which has decimal point, it shows the answer where 1 is deducted. for example: if we multiply 0.7 with 10, it shows the answer =6 instead of 7.
int quotient2 ;
int n;
cout<<"how many digits you want to see after decimal point?? "<<endl;
cin>>n ;
// for digits after decimal point we're doing this operation. As it continues to infinity we're asking the user to put the value of n.
for (int i =1;i<=n;i++)
{
    product =finalNum * base2;
    quotient2 = product / 10;
    sumQuotient = sumQuotient *10 + quotient2  ;
    finalNum = product % 10 ;
}

 cout << "the converted number "<< reverse << "."<< sumQuotient<<endl;
 }
 return 0 ;
}

