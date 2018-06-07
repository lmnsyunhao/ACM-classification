#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, d;
char str[105];

struct node{
    int idx, num;
    bool operator < (const node& no) const{
        return num > no.num;
    }
};

int main(){
    while(~scanf("%d %d", &n, &d)){
        scanf("%s", str);
        priority_queue<node> q;
        q.push((node){0, 0});
        for (int i = 0; i < n; i++){
            if(str[i] == '1'){
                while(!q.empty() && q.top().idx + d < i){
                    q.pop();
                }
                if(q.empty()){
                    printf("-1\n");
                    break;
                }
                node no = q.top();
                if(i == n-1){
                    printf("%d\n", no.num+1);
                    break;
                }
                q.push((node){i, no.num + 1});
            }
        }
    }
    return 0;
}
