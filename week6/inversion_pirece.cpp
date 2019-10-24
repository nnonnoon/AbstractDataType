#include <iostream>
using namespace std;

long long a[1000010], temp[1000010];
long long nub= 0;

int merge( int s, int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;

    while (i <= mid && j <= e)
    {
        if (a[i] > a[j])
        {
            temp[k++] = temp[j++];
            nub += (mid - i + 1);
        }
        else
        {
            temp[k++] = temp[i++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }

    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
    return nub;
}

int mergesort(int s, int e)
{
    if (s >= e)
    {
        return 0;
    }

    int mid = (s+e)/2;

    mergesort(s, mid);
    mergesort(mid+1, e);

    merge(s, e);
    return nub;
}

int main ()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%llu", &a[i]);
    } 

    for (int i = 0; i < N; i++)
    {
        temp[i] = a[i];
    } 

    mergesort(0, N - 1);
    printf("%lli\n",nub);
    
    return 0;
}