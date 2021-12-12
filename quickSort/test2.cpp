#include <stdio.h>
void quickSort(int * a, int low, int high);
int partition(int * a, int low, int high);

void quick_sort(int q[], int l, int r) 
{
    if (l >= r) return;
    int x = q[l];
    int i = l - 1;
    int j = r + 1;
    while (i < j)
    {
        do i++ while(q[i] < x);
        do j-- while(q[j] > x);
        if (i < j)
        {
            swap(q[i], q[j]);
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
    
}

int main(void) 
{

    int a[6] = {2, 1, 0, 5, 4, 3};

    quickSort(a, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");


    return 0;

}


void quickSort(int * a, int low, int high) 
{
    int pos;

    if (low < high)
    {
        pos = partition(a, low, high);
        quickSort(a, low, pos - 1);
        quickSort(a, pos + 1, high);
    }
    

}

int partition(int * a, int low, int high)
{
    int val = a[low];

    while (low < high) 
    {
        
        while (low < high && a[high] >= val)
        {
            high--;
        }
        a[low] = a[high];

        while (low < high && a[low] <= val)
        {
            low++;
        }
        a[high] = a[low];    
    }
    a[low] = val;

    return low;
    
}
