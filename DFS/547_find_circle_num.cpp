#include "../headers.h" // IWYU pragma: keep


/*
 *void dfs(int i, vector<vector<int>>& vec, vector<bool>& visit){
 *    visit[i] = true;
 *    for(uint j = 0; j < vec.size(); ++j){
 *        if(vec[i][j] == 1 && !visit[j])
 *            dfs(j, vec,visit);
 *    }
 *}
 *
 *int findCircleNum(vector<vector<int>>& isConnected) {
 *    int res = 0;
 *    int n = isConnected.size();
 *    vector<bool> visit(n, false);
 *
 *    for(int i = 0; i < n; ++i){
 *        if(!visit[i]){
 *            res++;
 *            dfs(i, isConnected, visit);
 *        }
 *    }
 *
 *    return res;
 *}
 */

/*
 *int find(int x, vector<int>& rel) {
 *    if(rel[x] != x)
 *        rel[x] = find(rel[x], rel);
 *
 *    return rel[x];
 *}
 *
 *int findCircleNum(vector<vector<int>>& isConnected) {
 *    vector<int> rel;
 *    int n = isConnected.size(), res = n;
 *
 *
 *    for(int i = 0; i < n; ++i){
 *        rel.push_back(i);
 *    }
 *
 *    for(int i = 0; i < n; ++i){
 *        for(int j = 0; j < n; ++j){
 *            if(isConnected[i][j] && find(i, rel) != find(j, rel)){
 *                rel[find(i, rel)] = find(j, rel);
 *                res--;
 *            }
 *        }
 *    }
 *
 *    return res;
 *}
 */

int findCircleNum(vector<vector<int>>& isConnected) {
    int res = 0;
    int n = isConnected.size();
    vector<bool> visit(n, false);

    queue<int> que;
    for(int i = 0; i < n; ++i){
        if(!visit[i]){
            res++;
            que.push(i);
            visit[i] = true;
            while(!que.empty()){
                int cur = que.front();
                que.pop();
                for(int j = i; j < n; ++j){
                    if(isConnected[cur][j] && !visit[j]){
                        que.push(j);
                        visit[j] = true;
                    }
                }
            }
        }
    }

    return res;
}
