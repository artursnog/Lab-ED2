#include <stdio.h>

int x(int n){
    if (n <= 1){
        return 1;
    
    }
    return x(n - 1) + x(n - 2);
}

int main(){
    printf("%d\n", x(20));
    return 0;
}