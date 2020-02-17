#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 3;//only a,b,c will be occured
string s;
// trie node each node contains a boolean and 3 nodes address
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
    pCrawl->isEndOfWord = true;//last node as marked as End of Word,leaf node
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
bool search(struct TrieNode *root,int pos_of_s,int not_match)
{
    //struct TrieNode *root=root;

    int index=s[pos_of_s]-'a';

    if(root->isEndOfWord && pos_of_s==s.size()&& not_match==1) {return true;}

    else if(pos_of_s>=s.size()|| not_match>1) {return false;}

    if(root->children[index]) // matches
    {
        if(search(root->children[index],pos_of_s+1,not_match)) {return true;}
    }
    // so. mismatch
    for(int i=0;i<3;i++)
    {
        if(i==index) {continue;}
        else if(root->children[i])
        {
            if(search(root->children[i],pos_of_s+1,not_match+1)) return true;
        }
    }
   return false;
}


  int main()

  {
          ios_base::sync_with_stdio(false);
              struct TrieNode *root =  getNode();
              int n,k;
              cin>>n>>k;
              for(int i=0;i<n;i++)
              {
                  cin>>s;
                  insert(root,s);
              }
              while(k--)
              {
                  cin>>s;
                  if(search(root,0,0)) {cout<<"YES"<<endl;}
                  else cout<<"NO"<<endl;
              }
              //delete root;

          return 0;
  }
