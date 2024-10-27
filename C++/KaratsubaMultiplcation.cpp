#include <iostream>
#include <algorithm>
#include <cstring>
#include<math.h>

using namespace std;

long long karatsuba(long long a, long long b)
{
    // Base case: return a*b if a or b is less than 10
    if (a < 10 || b < 10)
        return a*b;

    int n = max(to_string(a).length(), to_string(b).length());

    int n2 = n / 2;

    // Split the numbers into high and low digits
    // x and z are the high digits, y and w are the low digits
    long long x = a / (long long)pow(10, n2);
    long long y = a % (long long)pow(10, n2);
    long long z = b / (long long)pow(10, n2);
    long long w = b % (long long)pow(10, n2);

    // Recursively compute p, q, and r
    long long p = karatsuba(x, z);
    long long q = karatsuba(x + y, z + w);
    long long r = karatsuba(y, w);

    // Return the final result using the Karatsuba formula
    return (long long)pow(10, 2 * n2) * p + (long long)pow(10, n2) * (q - p - r) + r;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << karatsuba(a, b) << endl;
    return 0;
}
