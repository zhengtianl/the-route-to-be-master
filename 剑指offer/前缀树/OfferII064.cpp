
#include "string"
#include "vector"
using namespace std;
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    ~MagicDictionary(){}
    
    void buildDict(vector<string> dictionary) {
        words = dictionary;

    }
    bool search(string searchWord) {
        for(auto& word: words)
        {
            if(word.length() != searchWord.length())
            {
                continue;
            }

            int diff = 0;
            for(int i  = 0; i < word.length(); i++)
            {
                if(word[i] != searchWord[i])
                { 
                diff += 1;
                if(diff > 1)
                    break;
                }
            }
            if(diff == 1)
            {
                return true;
            } 
        }
        return false;
    
    }

private:
vector<string> words;

};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */