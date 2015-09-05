public static BigInteger quickpow(BigInteger A, BigInteger n, BigInteger m)
{
    BigInteger ret = BigInteger.ONE;
    while (n.compareTo(BigInteger.ZERO) == 1)
    {
        if (n.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE))
            ret = ret.multiply(A).mod(m);
        A = A.multiply(A).mod(m);
        n = n.divide(BigInteger.valueOf(2));
    }
    return ret;
}
