#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

vector<char>xtra;
string s;
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
            pCrawl->children[index] = getNode();
            }// if not previously added , then added .

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;//last node as marked as End of Word
}

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

// start from root node and searching
void search(struct TrieNode *root,string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
                cout<<"No match."<<'\n';
            return;}

        pCrawl = pCrawl->children[index];
    }
    //cout<<
    print(pCrawl,key);
}


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
          cin>>k;
          int caso=1;
          while(k--)
          {
              cin>>s;
              cout<<"Case #"<<caso<<":\n";
              search(root,s);
              caso++;
          }

      return 0;
  }
