#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;



int main()
{
	string s = "abc";
	sort(s.begin(), s.end());
	
	do
	{
		for (int i = 0; i < s.length(); ++i)
			cout << s[i] << " ";
	} while (next_permutation(s.begin(), s.end()));
	
	return 0;
}


