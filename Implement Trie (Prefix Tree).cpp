class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode * next[26];
    bool end;
    TrieNode() {
        end=0;
        memset(next,0,sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *cur=root;
        for(int i=0;i<s.size();i++)
        {
            int pos = s[i]-'a';
            if(!cur->next[pos])
            {
                cur->next[pos] = new TrieNode();
            }    
            cur=cur->next[pos];
        }
        cur->end=1;
    }

    // Returns if the word is in the trie.
    bool search(string s) {
        TrieNode *cur=root;
        for(int i=0;i<s.size();i++)
        {
            int pos = s[i]-'a';
            if(!cur->next[pos])
            {
                return false;
            }    
            cur=cur->next[pos];
        }
        return cur->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string s) {
        TrieNode *cur=root;
        for(int i=0;i<s.size();i++)
        {
            int pos = s[i]-'a';
            if(!cur->next[pos])
            {
                return false;
            }    
            cur=cur->next[pos];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");