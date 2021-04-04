int fib(int n) {
    if(n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int recFactorial(int n) {
    if (n <= 0)
        return 1;

    return n * recFactorial(n - 1);
}

int iterFactorial(int n) {
    if (n < 0)
        return -1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
