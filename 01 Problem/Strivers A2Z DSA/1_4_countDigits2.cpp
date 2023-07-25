#include<bits/stdc++.h>
using namespace std;

const int N = 0;
//compliexity O(1)

int countDigits(int n)
{
	return floor(log10(n)+1);
}
int main()
{
	int n = 1234;
	cout<<countDigits(n)<<'\n';
	return 0;
}