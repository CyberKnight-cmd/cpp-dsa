#include<stdio.h>

typedef struct
{
    int first;
    int second;
} Pair;


int main(){
    Pair p = {5, 3};
    printf("%d, %d", p.first, p.second);
    return 0;
}