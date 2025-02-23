/*
Factors of a Number


int n;
cin >> n;
vector<int> factors;
for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        factors.push_back(i);
        if (i != n / i) factors.push_back(n / i);
    }
}

*/

/*
Prime Factors of a Number


int n;
cin >> n;
vector<int> prime_factors;
for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
        while (n % i == 0) {
            n /= i;
            prime_factors.push_back(i);
        }
    }
}
if (n > 1) {
    prime_factors.push_back(n);
}

*/

/*
Sieve of Eratosthenes

bool isPrime[n + 1];
for (int i = 0; i <= n; i++) {
    isPrime[i] = true;
}
isPrime[0] = isPrime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
}

*/

/*
Smallest Prime Factor (SPF)

for (int i = 0; i < N; i++) {
    spf[i] = i;
}
for (int i = 2; i * i < N; i++) {
    if (spf[i] == i) {
        for (int j = i * i; j < N; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }
}


*/

/*
SPF+PrimeFactorization count

for (int i = 0; i < N; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

vector<int> prime_factors;
    while (n > 1)
    {
        prime_factors.push_back(spf[n]);
        n /= spf[n];
    }
*/

/*
Doubt: why in spf solve() function spf[i] = i;

vector<pair<int, int>> primeFactorization(int x, vector<int>& spf){
    vector<pair<int, int>> ans;
    while(x != 1){
        int prime = spf[x];
        int cnt = 0;
        while(x % prime == 0){
            cnt++;
            x = x / prime;
        }
        ans.push_back({prime, cnt});
    }
    return ans;
}

void solve(){
    int maxN = 1e6;
    vector<bool> isPrime(maxN, true);
    vector<int> spf(1e6, 1e9);
    for(long long i = 2; i < maxN; i++){
        if(isPrime[i]){
            spf[i] = i;
            for(long long j = i * i; j < maxN; j += i){
                isPrime[j] = false;
                spf[j] = min(spf[j], (int)i);
            }
        }
    }
}

vector<pair<int, int>> primeF = primeFactorization(36, spf);
*/