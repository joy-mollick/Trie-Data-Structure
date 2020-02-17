#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

vector<char>xtra;
string s;
// trie node each node contains a boolean and 26 nodes address
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int count;
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

        pNode->count=0;

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
            }// if not previously added , then added .
        pCrawl->count++;
        pCrawl = pCrawl->children[index];
    }
    pCrawl->count++;
    pCrawl->isEndOfWord = true;//last node as marked as End of Word
}

/*
void print(struct TrieNode *root,string s)
{
    struct TrieNode *pCrawl=root;
    if(pCrawl->isEndOfWord&&xtra.size()) {
            cout<<s;
            for(int l=0;l<xtra.size();l++) cout<<xtra[l];
            cout<<endl;
    }
    for(int i=0;i<26;i++)
    {
        if(pCrawl->children[i]) {
            char c=i+'a';
            xtra.push_back(c);
            print(pCrawl->children[i],s);
            xtra.pop_back();
        }
    }
    return ;
}
*/

// start from root node and searching
int search(struct TrieNode *root,string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            return 0;}

        pCrawl = pCrawl->children[index];
    }
    return pCrawl->count;
}


  int main()

  {
          ios_base::sync_with_stdio(false);
          int tc;
          cin>>tc;
          while(tc--)
          {
              struct TrieNode *root =  getNode();
              int n;
              cin>>n;
              string s;
              string arr[n];
              for(int i=0;i<n;i++)
              {
                  cin>>arr[i];
              }
              sort(arr,arr+n);
              bool consistent=false;
              for(int i=n-1;i>=0;i--)
              {
                  insert(root,arr[i]);
                  if(search(root,arr[i])>1) {consistent=true;break;}
              }
              if(consistent) cout<<"NO"<<'\n';
              else cout<<"YES"<<'\n';
              //delete root;
          }

          return 0;
  }
