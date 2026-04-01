#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int l, int m, int r)
{
    int i=l, j=m+1, k=l;
    int temp[10000];

    while(i<=m && j<=r)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i<=m)
        temp[k++] = a[i++];

    while(j<=r)
        temp[k++] = a[j++];

    for(int z=l; z<=r; z++)
        a[z] = temp[z];
}

void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main()
{
    int n, a[10000];
    clock_t start,end;

    printf("Enter size of array: ");
    scanf("%d",&n);

    srand(time(0));

    printf("Random numbers generated:\n");
    for(int i=0;i<n;i++)
    {
        a[i] = rand() % 1000;
        printf("%d ",a[i]);
    }

    start = clock();

    mergeSort(a,0,n-1);

    end = clock();

    printf("\n\nSorted array:\n");
    for(int j=0;j<n;j++)
        printf("%d ",a[j]);

    printf("\n\nTime taken: %f seconds",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
