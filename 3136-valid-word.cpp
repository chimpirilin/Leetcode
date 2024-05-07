// https://leetcode.com/problems/valid-word/
class Solution {
public:

    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    // Do what you're told
    bool isValid(string word) {
        int wordSize = word.size();
        if(wordSize < 3) return false;

        std::unordered_set<char> vowels;
        std::unordered_set<char> consonants;
        
        for(int i = 'a'; i <= 'z'; i++) { 
            if(isVowel(i)) vowels.insert(i);
            else consonants.insert(i);
        }

        for(int i = 'A'; i <= 'Z'; i++) { 
            if(isVowel(i)) vowels.insert(i);
            else consonants.insert(i);
        }

        bool atLeastOneConsonant = false;
        bool atLeastOneVowel = false;
        bool validChar = true;

        for(auto c : word){
            if(vowels.find(c) != vowels.end()) {
                atLeastOneVowel = true;
            }
            if(consonants.find(c) != consonants.end()) {
                atLeastOneConsonant = true;
            }
            if(c == '@'||c == '$'||c == '#') validChar = false;

        }
        return validChar && atLeastOneConsonant && atLeastOneVowel;

    }
};