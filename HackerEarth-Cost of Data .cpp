#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

int cont;

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

        //pNode->count=0;

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
            pCrawl->children[index] = getNode();
            cont++;
            }// if not previously added , then added .

        //pCrawl->count++;
        pCrawl = pCrawl->children[index];
    }
     //pCrawl->count++;
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

/*
int num_of_prefix(struct TrieNode *root,string key)
{
    struct TrieNode *pCrawl = root;

    int ans=0;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            return 0;}// suffix is not present ,return -1
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->count;
}*/

  int main()

  {
      ios_base::sync_with_stdio(false);
          int t,n,k,w;
          string s;
          cin>>n;
          struct TrieNode *root=getNode();
          for(int i=0;i<n;i++)
          {
              cin>>s;
              insert(root,s);
          }
          cout<<(cont+1)<<endl;
      return 0;
  }
