class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
    
        unordered_map<char, int> d;

        for (char j : word) {
            d[j] = d.find(j) != d.end() ? d[j] + 1 : 1;
        }

        vector<pair<int, char>> a;
        for (const auto& entry : d) {
            a.push_back(std::make_pair(entry.second, entry.first));
        }

        sort(a.begin(), a.end());

        int ans = 0;
        int keys = 0;

        for (const auto& j : a) {
            keys++;

            if (keys < 9) {
                ans += j.first;
            } else if (keys < 17) {
                ans += j.first * 2;
            } else if (keys < 25) {
                ans += j.first * 3;
            } else {
                ans += j.first * 4;
            }
        }

    return ans;
    }
};
