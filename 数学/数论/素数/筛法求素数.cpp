//一般筛法
const int N = 31700;
int prime[N], primes[N], cnt = 0;
void make_prime()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2;  i < N; i++)
    {
        if (prime[i])
        {
            primes[cnt] = i;
            cnt++;
            for (int k = i * i; k < N; k += i)
                prime[k] = false;
        }
    }
}

//快速线性筛法
const int N = 200000;
int prime[N] = {0};
int isNotPrime[N] = {1, 1}, num_prime = 0;
void make_prime()
{
    for (int i = 2; i < N; i++)
    {
        if (!isNotPrime[i])
        {
            prime[num_prime] = i;
            num_prime++;
        }
        for (int j = 0; j < num_prime && i * prime[j] < N; j++)
        {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j])) break;
        }
    }
}
