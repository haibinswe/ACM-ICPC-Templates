bool isPrime(long long n)
{
    if (n == 1 || n == 0)
        return false;
    long long r = sqrt(n);
    for (int i = 2; i <= r; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
