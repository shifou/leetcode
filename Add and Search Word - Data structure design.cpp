struct ok
{
    int end;
    int next[26];
};
ok a[1000005];
int id=1;
class WordDictionary {
public:
WordDictionary()
{
    if(id!=1)
    {
        for(int i=1;i<=id;i++)
        {
            a[i].end=0;
            memset(a[i].next,0,sizeof(a[i].next));
        }
    }
    id=1;
}
    // Adds a word into the data structure.
    void addWord(string word) {
        int cur=1;
        for(int i=0;i<word.size();i++)
        {
            if(!a[cur].next[word[i]-'a'])
            {
                a[cur].next[word[i]-'a']=++id;
            }
            cur=a[cur].next[word[i]-'a'];
        }
        a[cur].end=1;
    }
    bool check(string & word, int pos, int cur)
    {
        for(int i=pos;i<word.size();i++)
        {
            if(word[i]!='.')
            {
                if(!a[cur].next[word[i]-'a'])
                    return false;
                else
                    cur=a[cur].next[word[i]-'a'];
            }
            else
            {
                for(int j=0;j<26;j++)
                {
                     if(a[cur].next[j] && check(word,i+1,a[cur].next[j]))
                        return true;
                }
                return false;
            }
        }
        return a[cur].end;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return check(word,0,1);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");