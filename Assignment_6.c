//Write a C function to comput and without recursion.


#include <stdio.h>

// Function without recursion
int factorial(int n)
{
    int i, fact = 1;

    for(i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Function with recursion
int recursiveFactorial(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("Factorial is not defined for negative numbers.");
    }
    else
    {
        printf("Factorial without recursion = %d\n", factorial(num));
        printf("Factorial with recursion = %d", recursiveFactorial(num));
    }

    return 0;
}