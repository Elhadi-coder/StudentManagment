#include <stdio.h>

void Product()
{
    int a, b;
    pritnf("Give Me The First Number :");
    scanf("%d", &a);
    printf("Give Me The Second Number :");
    scanf("%d", &b);
    printf("The Product Of The Two Number Is : %d ", a * b);
}

int main()
{
    Product();

    return 0;
}
