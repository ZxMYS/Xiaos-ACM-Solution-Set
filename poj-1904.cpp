#include <vector>
#include <algorithm>
using namespace std;

const int N = 2010;
int nv, times, sccId;
int go[N], back[N];
int low[N], dfn[N];
int love[N][N];
int scc[N];
bool inS[N];
vector<int> S;

#define Min(a, b) ((a) < (b) ? (a) : (b))

void DFS(int x) {
    int i;
    dfn[x] = ++times;
    S.push_back(x);
    inS[x] = 1;
    int y = back[x], z;
    low[x] = times;

    for(i = 1; i <= love[y][0]; ++i) {
        int j = love[y][i];
        if(j != x) {
            if(dfn[j] == 0) {
                DFS(j);
                low[x] = Min(low[x], low[j]);
            }
            else if(dfn[j] < dfn[x] && inS[j])
                low[x] = Min(low[x], dfn[j]);
        }
    }

    if(low[x] == dfn[x]) {
        do {
            z = S.back();
            scc[z] = sccId;
            inS[z] = false;
            S.pop_back();
        }while(z != x);
        sccId++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    scanf("%d", &nv);
    int i, t, j;
    for(i = 0; i < nv; ++i) {
        scanf("%d", &love[i][0]);
        for(j = 1; j <= love[i][0]; ++j) {
            scanf("%d", &love[i][j]);
            --love[i][j];
        }
    }
    for(i = 0; i < nv; ++i) {
        scanf("%d", &t);
        go[i] = t-1;
        back[t-1] = i;
    }

    times = sccId = 0;
    memset(inS, 0, sizeof(inS));
    memset(dfn, 0, sizeof(dfn));
    for(i = 0; i < nv; ++i) if(dfn[i] == 0) {
        DFS(i);
    }

    for(i = 0; i < nv; ++i) {
        vector<int> ans;
        for(j = 1; j <= love[i][0]; ++j) {
            if(scc[love[i][j]] == scc[go[i]])
                ans.push_back(love[i][j]);
        }
        sort(ans.begin(), ans.end());
        printf("%d", ans.size());
        for(j = 0; j < ans.size(); ++j)
            printf(" %d", ans[j]+1);
        printf("\n");
    }

    return 0;
}
