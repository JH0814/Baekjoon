#include<stdio.h>
#include<string.h>
void merge(char* a, char* b){
    int p = 0;
    int q = 0;
    while(p != strlen(a) && q != strlen(b)){
        if(a[p] < b[q]){
            printf("%c", a[p++]);
        }
        else{
            printf("%c", b[q++]);
        }
    }
    while(p != strlen(a)){
        printf("%c", a[p++]);
    }
    while(q != strlen(b)){
        printf("%c", b[q++]);
    }
    printf("\n");
}
int main(){
    char str1[101];
    char str2[101];
    scanf("%s", str1);
    scanf("%s", str2);
    merge(str1, str2);
}