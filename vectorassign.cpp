// vector assign
#include <iostream>
#include <vector>
using namespace std ;
int main ()
{
  vector<float> first;
  vector<float> second;
  vector<float> third;

  first.assign (7.0,100.0);             // 7 ints with a value of 100

  vector<float>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776.0,70.0,4.0};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
  return 0;
}