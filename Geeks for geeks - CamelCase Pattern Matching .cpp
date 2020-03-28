#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    vector<string>v;
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        if(islower(key[i])) continue;/// only keeps capital letter ,ignore small letters
        int index = key[i] - 'A';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
    pCrawl->v.push_back(key);/// keep strings with the pattern of capital letters
}

  void fun(struct TrieNode* pos)
  {
      if (pos->isEndOfWord == true)/// print all strings starting with given prefix
    {
        vector<string>::iterator it;
        for(it=pos->v.begin();it!=pos->v.end();it++)
        {
            cout<<(*it)<<" ";
        }
    }
    int ind=0;
    for (ind=0;ind<26;ind++)
    {
        if (pos->children[ind])/// traversing to find all strings with given prefix
        fun(pos->children[ind]);
    }
  }

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'A';/// all letters are in capital letter
        if (!pCrawl->children[index]) {
            return false;
        }
        pCrawl = pCrawl->children[index];
    }
    /// given string key has been found ,go to print mod
  fun(pCrawl);
  return true;
}

// Driver
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        struct TrieNode *root = getNode();
        int n, i;
        cin >> n;
        string s;
        for (i=0;i<n;i++)
        {
            cin >> s;
            insert(root, s);
        }
        cin >> s;
        if(!search(root,s)) cout<<"No match found\n";
        else cout<<"\n";
    }
    return 0;
}
