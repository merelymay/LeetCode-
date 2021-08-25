#include "pub_head.h"
using namespace std;


int main() {
    int N;
    while (cin >> N) {
        string a;
        int b;
        vector<int> indegree(N, 0);
        vector<vector<int>> edges(N, vector<int>());
        vector<int> cost(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> a >> b;
            int s = 0;
            for (int j = 0; j < a.size(); ++j) {
                if (a[j] == ',') {
                    int tmp = stoi(a.substr(s, j-s+1));
                    edges[tmp].push_back(i);
                    indegree[i]++;
                    s = j+1;
                }
                if (s < a.size()) {
                    int tmp = stoi(a.substr(s, a.size()-s));
                    if (tmp == -1) {
                        break;
                    }
                    edges[tmp].push_back(i);
                    indegree[i]++;
                }
            }
            cost[i] = b;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            int mt = 0;
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                mt = max(mt, cost[node]);
                for (int num : edges[node]) {
                    indegree[num]--;
                    if (indegree[num] == 0) {
                        q.push(num);
                    }
                }
            }
            res += mt;
        }
        for (int i = 0; i < N; ++i) {
            if (indegree[i] != 0) {
                res = -1;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}