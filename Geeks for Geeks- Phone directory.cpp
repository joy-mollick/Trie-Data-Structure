#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
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
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

  void fun(struct TrieNode* pos,string s)
  {
      if (pos->isEndOfWord == true)
    cout << s << " ";
    char ch;
    for (ch = 'a' ; ch <= 'z' ; ch++)
    {
        if (pos->children[ch-'a'])
        fun(pos->children[ch-'a'], s+ch);
    }
  }

void search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
                cout<<"0";
            return;
        }
        pCrawl = pCrawl->children[index];
    }
  fun(pCrawl,key);
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
        string temp="";
        for (i=0;i<s.length();i++)
        {
            temp=temp+s[i];
            search(root, temp);
            cout << endl;
        }
    }
    return 0;
}
