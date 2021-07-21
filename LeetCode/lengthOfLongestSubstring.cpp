// 3. 无重复字符的最长子串
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
#include "pub_head.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, r = 0;
        int res = 0;
        while (r < s.size()) {
            while (st.count(s[l])) {
                st.erase(s[l++]);
            }
            st.insert(s[r++]);
            res = max(res, r-l);
        }
        return res;
    }
};

int main() {
    string s = "abcabcbb";
    Solution solu;
    int res = solu.lengthOfLongestSubstring(s);
    return 0;
}