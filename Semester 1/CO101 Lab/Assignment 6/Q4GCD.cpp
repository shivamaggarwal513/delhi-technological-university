#include <stdio.h>

int hcf(int n1, int n2) 
{
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}

int main() 
{
    int n1, n2, gcd;
    printf("Enter two numbers: ");
    scanf_s("%d %d", &n1, &n2);
    gcd = (n1 > n2) ? hcf(n1, n2) : hcf(n2, n1);
    printf("GCD of %d and %d is %d", n1, n2, gcd);
    return 0;
}