#include <iostream>

int sum(int n) {
    if (n == 0) 
        return 0;
    else 
        return n + sum(n - 1);
}

int Isum(int n) {
    int s = 0;
    int i;
    
    for(i=1;i<=n;i++){
        s = s+i;
    }return s;
}

int main() {
    int n;

        int s = sum(n);
        std::cout << sum << std::endl;
    

    return 0;
}

