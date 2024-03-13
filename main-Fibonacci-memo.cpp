/* The Fibonacci sequence is a classic sequence in CS
   This implementaton of the Fibonacci sequence uses memoization
   */

#include <iostream>
#include <vector>
using namespace std;

int fib(int x, vector<bool>& isknown, vector<int>& fibval) {
	/*  The program runs the recursive Fibonacci sequence with memo-ization
		0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 134, ...
		The original was devised by Fibonacci (1170 ad - 1250 ad),
		who used this to model the breeding of pairs of rabbits.

		pre: n is a small positive integoer
		Post: This function uses the following dedinition
		fib(x) = 0 for x <= 0
		fib(1) = 1
		fib(x) = fib(x - 1) + fib(x - 2)  for x >= 2 */

	if (x >= 0) {

		if (isknown[x]) {
			return fibval[x];
		}
		else {
			cout << x << " ";
			isknown[x] = true;

			fibval[x] = (fib(x - 1, isknown, fibval) + fib(x - 2, isknown, fibval));
			return fibval[x];
		}
	}
	else { // x <= 0
		return 0;
	}
}

int main() {

	char stop;
	int n, ans;

	cout << "\nEnter a small positive integer: ";
	cin >> n;

	vector<bool> isknown(n + 1, false); //initialize vector
	vector<int> fibval(n + 1);
	isknown[0] = true;
	isknown[1] = true;
	fibval[0] = 0;
	fibval[1] = 1;

	cout << "Here are the function calls: ";
	ans = fib(n, isknown, fibval);

	cout << "\nFibonacci of " << n << " is " << ans << "." << endl;

	cin >> stop; //to keep window open in certain cases

	return 0;
}