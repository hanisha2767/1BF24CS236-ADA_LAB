#include<stdio.h>
float fractional_knapsack(int W,int n,int weight[],int value[])
{
    int i,j;
    float ratio[n],total_val,fraction;
    for(i=0;i<n;i++){
        ratio[i]=(float)value[i]/weight[i];
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                int temp;
                temp=weight[i];weight[i]=weight[j];weight[j]=temp;
                temp=value[i];value[i]=value[j];value[j]=temp;
                temp=ratio[i];ratio[i]=ratio[j];ratio[j]=temp;
            }
        }
    }
    total_val=0.0;
    for(i=0;i<n;i++){
        if(weight[i]<=W){
            total_val=total_val+value[i];
            W=W-weight[i];
        }
        else{
            fraction=(float)W/weight[i];
            total_val=total_val+((float)value[i]*fraction);
            break;
        }
    }
    return total_val;

}
int main()
{
    int n,W;
    float total_value;
    printf("enter number of items:");
    scanf("%d",&n);
    int weight[n],value[n];
    printf("enter weight and value of items:");
    for(int i=0;i<n;i++){
        scanf("%d %d",&weight[i],&value[i]);
    }
    printf("enter maximum weight of the sack:");
    scanf("%d",&W);
    total_value=fractional_knapsack(W,n,weight,value);
    printf("total sack value:%.2f",total_value);
}
