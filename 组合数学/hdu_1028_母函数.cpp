#include <cstdio>
#include <cstring>

using namespace std;

int n;
int num1[125];
int num2[125];

int main(){
    memset(num1, 0, sizeof num1);
    memset(num2, 0, sizeof num2);
    for(int i = 0; i < 125; i++){
        num1[i] = 1;
    }
    for(int i = 2; i <= 120; i++){
        for(int j = 0; j <= 120; j++){
            for (int k = 0; k+j <= 120; k += i){
                num2[k+j] += num1[j];
            }
        }
        for(int j = 0; j <= 120; j++){
            num1[j] = num2[j];
            num2[j] = 0;
        }
    }
    while(~scanf("%d", &n)){
        printf("%d\n", num1[n]);
    }
}
