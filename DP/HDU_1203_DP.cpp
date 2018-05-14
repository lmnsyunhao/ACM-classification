#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;
int c[10010];
double p[10010];
double dp[10010];

int main(){
    while(~scanf("%d %d", &n, &m)){
        if(n==0 && m==0) break;
        for(int i = 0; i < m; i++){
            scanf("%d %lf", &c[i], &p[i]);
            p[i] = 1-p[i];
        }

        for(int i = 0; i <= n; i++){
            dp[i] = 1;
        }

        for(int i = 0; i < m; i++){
            for(int j = n; j >= c[i]; j--){
                dp[j] = min(dp[j], dp[j-c[i]]*p[i]);
            }
        }

        double mi = 1;
        for(int i = 0; i <= n; i++){
            if(dp[i] < mi)
                mi = dp[i];
        }
        printf("%.1lf%%\n", (1-mi)*100);
    }
    return 0;
}
