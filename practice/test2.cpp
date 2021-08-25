#include "pub_head.h"
using namespace std;

struct node
{
    int key, value;

};


int getTime(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> edges(matrix.size());
    vector<int> indegree(matrix.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            indegree[matrix[i][j]]++;

        }
    }
}

int main() {
    vector<vector<int>> mat = {{-1, 1}, {-1, 2}, {-1, 3}};6 ,  
    int res = getTime(mat);
    cout<<res<<endl;
    return 0;
}