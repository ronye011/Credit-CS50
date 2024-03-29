#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long security = number;

    int a[16];
    for (int i = 0; i < 16; i++)
    {
        a[i] = number % 10;
        number = number / 10;
    }

    for (int i = 1; i < 16; i += 2)
    {
        a[i] = a[i] * 2;
    }

    int b[9];

    for (int i = 0; i < 9; i++)
    {
        b[i] = 0;
    }

    for (int i = 1; i < 16; i += 2)
    {
        if (a[i] > 9)
        {
            for (int d = 0; d < 9; d++)
            {
                if (b[d] == 0)
                {
                    b[d] = a[i] % 10;
                    a[i] = a[i] / 10;
                    a[i] = a[i] % 10;
                }
            }
        }
    }

    int c = 0;
    for (int i = 0; i < 16; i++)
    {
        c = c + a[i];
    }
    for (int i = 0; i < 9; i++)
    {
        c = c + b[i];
    }
    c = c % 10;

    if (c == 0)
    {
        number = security;
        for (int i = 0; i < 16; i++)
        {
        a[i] = number % 10;
        number = number / 10;
        }
        if (a[15] == 4 || ((a[12] == 4) && (a[13] == 0)))
        {
            printf("VISA\n");
            return 0;
        }
        if (a[14] == 3 && (a[13] == 4 || a[13] == 7))
            {
                printf("AMEX\n");
                return 0;
            }
        if (a[15] == 5 && (a[14] == 1 || a[14] == 2 || a[14] == 3 || a[14] == 4 || a[14] == 5))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (a[0] != (4 | 3 | 5))
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
