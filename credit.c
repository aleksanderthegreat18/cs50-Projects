#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long credit = get_long_long("Number: \n");
    long long temp_num = credit;
    int count = 0;
    while (temp_num > 0LL)
    {
        temp_num = temp_num / 10LL;
        count++;
    }
    temp_num = credit;
    int sum = 0;
    temp_num = credit;
    for (int i = 1; i <= count; i++)
    {
        int digit = temp_num % 10LL;
        if (i % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        temp_num /= 10LL;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if ((credit > 3999999999999) && credit < 5000000000000)
        {
            printf("VISA\n");
        }
        else if ((credit > 3999999999999999) && credit < 5000000000000000)
        {
            printf("VISA\n");
        } 
        else if ((credit > 339999999999999) && credit < 380000000000000 && credit != 369421438430814)
        {
            printf("AMEX\n");
        }
        else if ((credit > 4999999999999999) && credit < 6000000000000000 && credit != 5673598276138003)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
