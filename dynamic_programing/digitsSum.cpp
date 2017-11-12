//
//  main.cpp
//  Problems:
//  Given two integers ‘n’ and ‘sum’, find count of all n digit numbers
//	with sum of digits as ‘sum’. Leading 0’s are not counted as digits.
//	1 <= n <= 100 and 1 <= sum <= 500
//
//  Created by Johann on 9/11/17.
//  Copyright © 2017 Johann. All rights reserved.
//

#include <iostream>

using namespace std;
const int N = 100;
const int M = 500;

long long findSumOfDigits(int n, int sum, long long lookup[N][M])
{
	if (n == 1)
	{
		if (sum >= 0 && sum <= 9)
			return 1;
		else
			return 0;
	}
	
	long long result = 0;
	
	if (lookup[n][sum] != -1)
		return lookup[n][sum];
	
	for (int i = 0; i <= 9; i++)
	{
		if (sum - i >= 0)
		{
			result += findSumOfDigits(n - 1, sum - i, lookup);
		}
	}
	
	lookup[n][sum] = result;
	
	return result;
}
int main(int argc, const char * argv[]) {
	// insert code here...
	int n, sum;
	cout << "Enter n and sum: " << endl;
	cin >> n;
	cin >> sum;
	
	long long lookup[N][M];
	long long result = 0;
	memset(lookup, -1, sizeof(lookup[0][0]) * N * M);
	for (int i = 1; i <= 9; i++)
	{
		if (sum - i >= 0)
		{
			result += findSumOfDigits(n - 1, sum - i, lookup);
		}
	}
	
	cout << "result: " << result << endl;
	return 0;
}
