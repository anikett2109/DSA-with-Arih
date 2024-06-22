class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        st.insert(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int length = q.front().second;
            q.pop();
            if(word == endWord) return length;
            for(int i = 0;i<word.length();i++){
                char original = word[i];
                for(char ch = 'a' ; ch<= 'z' ;ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end() ){
                        st.erase(word);
                        q.push({word, length+1});
                    }
                } 
                word[i] =original;
            }
        }
        return 0;
    }
};