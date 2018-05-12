#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int c, n, m;
int grid[25][1005];
int dp[2][1005];

int main(){
    scanf("%d", &c);
    while(c--){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                scanf("%d", &grid[i][j]);
            }
        }

        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                dp[i%2][j] = -40000000;
            }
            for (int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[0][0];
                    continue;
                }

                int up = -40000000, lft = -40000000;
                if(i != 0){
                    up = dp[(i+1)%2][j] + grid[i][j];
                }
                if(j != 0){
                    lft = dp[i%2][j-1] + grid[i][j];
                }

                dp[i%2][j] = max(dp[i%2][j], max(up, lft));

                for(int k = 2; k <= j+1; k++){
                    if((j+1) % k == 0){
                        dp[i%2][j] = max(dp[i%2][j], dp[i%2][((j+1)/k)-1] + grid[i][j]);
                    }
                }
            }
        }
        printf("%d\n", dp[(n+1)%2][m-1]);
    }
    return 0;
}
