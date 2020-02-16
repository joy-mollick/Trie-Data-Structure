#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node each node contains a boolean and 26 nodes address
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

//inserting as prefix based
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();}// if not previously added , then added .

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;//last node as marked as End of Word 
}

// start from root node and searching
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            return false;} 

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

  int main()

  {
      int t,n;
      cin>>t;
      string s;
      while(t--)
      {
          cin>>n;
          string arr[n];
          struct TrieNode *root=getNode();
          for(int i=0;i<n;i++)
          {
              cin>>arr[i];
              insert(root,arr[i]);
          }
          cin>>s;
          if(search(root,s)) cout<<"1"<<'\n';
          else cout<<"0"<<'\n';
      }
      return 0;
  }
