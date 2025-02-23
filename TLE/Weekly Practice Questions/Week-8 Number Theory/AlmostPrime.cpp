#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

vector<int> generatePrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int countAlmostPrimes(int n)
{
    vector<int> primes = generatePrimes(n);
    int almostPrimeCount = 0;

    for (int num = 1; num <= n; num++)
    {
        int distinctPrimeCount = 0;

        for (int prime : primes)
        {
            if (num % prime == 0)
            {
                distinctPrimeCount++;
            }
            if (distinctPrimeCount > 2)
                break;
        }

        if (distinctPrimeCount == 2)
        {
            almostPrimeCount++;
        }
    }

    return almostPrimeCount;
}

int main()
{
    int n;
    cin >> n;
    cout << countAlmostPrimes(n) << endl;
    return 0;
}
