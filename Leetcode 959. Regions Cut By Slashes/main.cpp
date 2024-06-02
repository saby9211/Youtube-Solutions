// DFS Solution

class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vii;
    typedef vector<vii> viii;
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0; // store cnt of regions
        
        viii vis(n, vii(m, vi(4, 0))); // vis vector

        function<void(int, int, int)> dfs = [&] (int row, int col, int type){
            if(row < 0 || row >= n || col < 0 || col >= m || vis[row][col][type]) return;

            vis[row][col][type] = 1;
            // consider edges with adjacent cells
            if(type == 0){
                dfs(row-1, col, 2); // upward edge
            }
            else if(type == 1){
                dfs(row, col+1, 3); // rightward edge
            }
            else if(type == 2){
                dfs(row+1, col, 0); // downward edge
            }
            else if(type == 3){
                dfs(row, col-1, 1); // leftward edge
            }
            // now consider edges within cell
            if(grid[row][col] != '/'){ // 0 & 1 , 2 & 3  are connected respectively
                dfs(row, col, type ^ 1);
            }
            if(grid[row][col] != '\\'){ // 0 & 3, 1 & 2 are connected respectively
                dfs(row, col, type ^ 3);                
            }
        };

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                for(int type = 0; type < 3; type++){
                    if(!vis[row][col][type]){
                        dfs(row, col, type);
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

// DSU Solution
class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vii;
    typedef vector<vii> viii;
    typedef vector<viii> viiii;
    
    map<vi, vi> pa;
    map<vi, int> sz;

    vi get(vi &a){
        if(pa[a] == a){
            return a;
        }
        return pa[a] = get(pa[a]);
    }
    void merge(vi &a, vi&b){
        a = get(a);
        b = get(b);
        if(sz[a] < sz[b]){
            swap(a, b);
        }
        pa[b] = a;
        sz[a] += sz[b];
        sz[b] = sz[a];
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                for(int type =0; type<4; type++){
                    pa[{row, col, type}] = {row, col, type};
                    sz[{row, col, type}] = 1;
                }
            }
        }
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                for(int type=0; type<4; type++){
                    // consider edges with adjacent cells
                    if(type == 0 && row - 1 >= 0){
                        vi a = {row, col, 0}, b = {row-1, col, 2};
                        if(get(a) != get(b)){
                            merge(a, b);
                        }
                    }
                    else if(type == 1 && col + 1 < m){
                        vi a = {row, col, 1}, b = {row, col+1, 3};
                        if(get(a) != get(b)){
                            merge(a, b);
                        }
                    }
                    else if(type == 2 && row + 1 < n){
                        vi a = {row, col, 2}, b = {row+1, col, 0};
                        if(get(a) != get(b)){
                            merge(a, b);
                        }
                    }
                    else if(type == 3 && col-1 >= 0){
                        vi a = {row, col, 3}, b = {row, col-1, 1};
                        if(get(a) != get(b)){
                            merge(a, b);
                        }
                    }

                    // consider edges within cell
                    if(grid[row][col] != '/'){
                        vi a = {row, col, type}, b = {row, col, type ^ 1};
                        if(get(a) != get(b)){
                            merge(a, b);
                        }
                    }
                    if(grid[row][col] != '\\'){
                        vi a = {row, col, type}, b ={row, col, type ^ 3};
                        if(get(a) != get(b)){
                            merge(a, b);
                        }
                    }
                }
            }
        }
        set<vector<int>> st;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                for(int type=0; type<4; type++){
                    vi a = {row, col, type};
                    st.insert(get(a));
                }
            }
        }
        return st.size();
    }
};