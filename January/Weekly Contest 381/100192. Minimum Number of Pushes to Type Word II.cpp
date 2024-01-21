#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(string word) {
       int n = word.size();

        unordered_map<char, int> frequency;

        for (char ch : word) {
            frequency[ch]++;
        }

        vector<pair<int, char>> frequencyList;

        for (const auto& entry : frequency) {
            frequencyList.push_back(make_pair(entry.second, entry.first));
        }

        sort(frequencyList.begin(), frequencyList.end(), greater<pair<int, char>>());

        int pushes = 0;
        int keys = 0;

        for (const auto& entry : frequencyList) {
            keys++;

            if (keys <= 8) {
                pushes += entry.first * 1;
            } else if (keys <= 16) {
                pushes += entry.first * 2;
            } else if (keys <= 24) {
                pushes += entry.first * 3;
            } else {
                pushes += entry.first * 4;
            }
        }

        return pushes;
    }
};

