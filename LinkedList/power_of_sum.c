#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int combinations(int x, int N)
{
    int sum = x;
    int root = sqrt(x), arr[root], count = 0, n = root - 1;
    for (int i = 0; i < root; i++)
        arr[i] = i + 1;

    while (n >= 0)
    {
        if (pow(arr[n], N) == sum)
        {
            count++;
            n--;
        }
        else
        {
            int p = n - 1, sum2 = 0;
            sum2 = pow(arr[n], N);

            while (p >= 0)
            {
                sum2 = sum2 + pow(arr[p], N);  
                if (sum2 == sum)
                {
                    count++;
                    sum2 = sum2 - pow(arr[p], N);
                }
                if (sum2 > sum)
                {
                    sum2 = sum2 - pow(arr[p], N); 
                    p--;
                }
                else
                    p--;
            }
        }
        n--;
    }

    return count;
}

int main()
{
    printf("%d", combinations(100, 2));
    return 0;
}