class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        map<char, int> charFreq;
         vector<int> halfPairs;
        for (const string& word : words){
            halfPairs.push_back(word.size()/2);
            for (char c : word)
                charFreq[c]++;
        }
        int m=0;
        for (const string& word : words)
            for (char c : word)
               m++;
        
        
        int totalHalfPairs = 0, wordIndex = 0;
       
        for (const auto& [character, frequency] : charFreq)
            totalHalfPairs += frequency / 2;
        
        sort(halfPairs.begin(), halfPairs.end());
        for (int halfPair : halfPairs)
            if ((totalHalfPairs -= halfPair) < 0) return wordIndex;
            else wordIndex++;
        
        return halfPairs.size();
    }
};
