#include<bits/stdc++.h>
using namespace std;

const int N = 0;
//complexity O(1)
int coundtDigit(int n)
{
	string s = to_string(n);
	return s.length();
}

int main()
{
	int n = 12345; 
	cout<<coundtDigit(n)<<'\n';
	return 0;
}