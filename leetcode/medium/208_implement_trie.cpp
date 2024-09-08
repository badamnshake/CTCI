#include <string>
#include <map>
using namespace std;
class Trie
{

    map<char, Trie *> nextChars;
    bool endWord = false;

public:
    Trie()
    {
    }

    void insert(string word)
    {
        Trie *curr = this;
        for (char c : word)
        {
            if (curr->nextChars.find(c) == curr->nextChars.end())
            {
                curr->nextChars[c] = new Trie();
            }
            curr = curr->nextChars[c];
        }
        curr->endWord = true;
    }

    bool search(string word)
    {
        Trie *curr = this;
        for (auto c : word)
        {

            if (curr->nextChars.find(c) == curr->nextChars.end())
                return false;

            curr = curr->nextChars[c];
        }
        return curr->endWord;
    }

    bool startsWith(string prefix)
    {

        Trie *curr = this;
        for (auto c : prefix)
        {

            if (curr->nextChars.find(c) == curr->nextChars.end())
                return false;

            curr = curr->nextChars[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */