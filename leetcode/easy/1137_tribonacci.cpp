int tribonacci(int n)
{
    int i = 0;
    long j = 1;
    long k = 1;
    int t;

    while (n > 0)
    {
        t = k;
        k = i + j + k;
        i = j;
        j = t;
        n--;
    }
    return i;
}