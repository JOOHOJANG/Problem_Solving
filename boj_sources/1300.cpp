#include <stdio.h>
​
int main(void)
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int left = 1, right = k;
    int result = -1;
    while (left <= right)
    {
        int cnt = 0;
        int mid = (left + right) / 2;
        for (int i = 1; i <= n; i++){
            if ((mid / i) <= n)
                cnt += mid/i;
            else cnt += n;
        }
        if (cnt < k)
            left = mid + 1;
        else
        {
            result = mid;
            right = mid - 1;
        }
    }
    printf("%d", result);
    return 0;
}
