class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> first;
        unordered_map<char, int> last;

        // first occurence
        for(int i = 0; i < word.size(); i++){
            char letter = word[i];
            if(letter >= 'A' && letter <= 'Z' && !first.count(letter)){
                first[letter] = i;
            }
        }
        for(int i = word.size() - 1; i >= 0; i--){
            char letter = word[i];
            if(letter >= 'a' && letter <= 'z' && !last.count(letter)){
                last[letter] = i;
            }
        }

        int c = 0;
        for(auto &it : first){
            if(!last.count(it.first + ('a' - 'A'))) continue;
            else if(last[it.first + ('a' - 'A')] > first[it.first]) continue;

            c++;
        }

        return c;

    }
};