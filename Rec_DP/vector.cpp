#include<iostream>
using namespace std;
int main(){
   string digits = {"23"};
   cout << digits[1] <<  endl;
   int number0 = digits[0] - '0';
   int number1 = digits[1] - '0';
   cout << number0 <<  endl << number1 << endl;
}