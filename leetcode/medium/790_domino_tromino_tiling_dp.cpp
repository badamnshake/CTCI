int numTilings(int n)
{
    const unsigned int M = 1000000007;
    unsigned int i = 1;
    unsigned int j = 2;
    unsigned int k = 5;
    unsigned int t;
    if (n == 1)
        return i;
    if (n == 2)
        return j;
    if (n == 3)
        return k;

    n -= 3;
    while (n > 0)
    {
        t = k;
        k = i + (k * 2) % M;
        i = j % M;
        j = t % M;
        n--;
    }
    return k % M;
}