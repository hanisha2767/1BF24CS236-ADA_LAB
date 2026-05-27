#include <stdio.h>

#define L -1
#define R 1

void print(int a[], int n) {
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}

int mobile(int a[], int d[], int n) {
    int m = 0;

    for(int i=0;i<n;i++) {
        if(d[a[i]-1]==L && i>0 && a[i]>a[i-1] && a[i]>m)
            m = a[i];

        if(d[a[i]-1]==R && i<n-1 && a[i]>a[i+1] && a[i]>m)
            m = a[i];
    }

    return m;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    int a[n], d[n];

    for(int i=0;i<n;i++) {
        a[i]=i+1;
        d[i]=L;
    }

    print(a,n);

    while(1) {
        int m = mobile(a,d,n);

        if(m==0) break;

        int pos;

        for(int i=0;i<n;i++)
            if(a[i]==m) pos=i;

        if(d[m-1]==L) {
            int t=a[pos];
            a[pos]=a[pos-1];
            a[pos-1]=t;
            pos--;
        }
        else {
            int t=a[pos];
            a[pos]=a[pos+1];
            a[pos+1]=t;
            pos++;
        }

        for(int i=0;i<n;i++)
            if(a[i]>m)
                d[a[i]-1]*=-1;

        print(a,n);
    }

    return 0;
}
