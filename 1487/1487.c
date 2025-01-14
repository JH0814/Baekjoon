#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int price;
    int deli;
} Person;

int cmp(const void* a, const void* b){
    Person* A = (Person*)a;
    Person* B = (Person*)b;
    return A->price - B->price;
}

int main(){
    int N;
    Person arr[51];
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d %d", &arr[i].price, &arr[i].deli);
    }
    qsort(arr, N, sizeof(Person), cmp);
    int maxCost = 0;
    int maxProfit = 0;

    for(int i = 0; i<N; i++){
        int sum = 0;
        for(int j = i; j<N; j++){
            int cur = arr[i].price - arr[j].deli;
            if(cur > 0){
                sum += cur;
            }
        }
        if(maxProfit < sum){
            maxProfit = sum;
            maxCost = arr[i].price;
        }
    }
    printf("%d\n", maxCost);
}