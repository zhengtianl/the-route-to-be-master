#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<string> words;
        string word = "";
        for (char c : sentence) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);
        for (int i = 0; i < words.size(); i++) {
            string& word = words[i];
            for (int j = 1; j <= word.length(); j++) {
                if (dict.count(word.substr(0, j))) {
                    word = word.substr(0, j);
                    break;
                }
            }
        }
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        return result;
    }
};
