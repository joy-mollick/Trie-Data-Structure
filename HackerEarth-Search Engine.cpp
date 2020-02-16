#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node each node contains a boolean and 26 nodes address
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int weight;
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

        pNode->weight=0;

    return pNode;
}

//inserting as prefix based
void insert(struct TrieNode *root, string key,int weight)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();}// if not previously added , then added .

        pCrawl->weight=max(weight,pCrawl->weight);
        pCrawl = pCrawl->children[index];
    }
    pCrawl->weight=max(weight,pCrawl->weight);
    pCrawl->isEndOfWord = true;//last node as marked as End of Word
}

// start from root node and searching
int search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            return false;}

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL || pCrawl->isEndOfWord);
}

int num_of_prefix(struct TrieNode *root,string key)
{
    struct TrieNode *pCrawl = root;

    int ans=0;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            return -1;}// suffix is not present ,return -1
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->weight;
}

  int main()

  {
          int t,n,k,w;
          string s;
          cin>>n>>k;
          struct TrieNode *root=getNode();
          for(int i=0;i<n;i++)
          {
              cin>>s>>w;
              insert(root,s,w);
          }
          while(k--)
          {
              cin>>s;
              cout<<num_of_prefix(root,s)<<endl;
          }
      return 0;
  }
