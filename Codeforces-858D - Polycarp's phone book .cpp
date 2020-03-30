#include <bits/stdc++.h>
    using namespace std;

    const int ALPHABET_SIZE = 11;
    unordered_map<string,int>m;/// unordered_map is very fast than normal map 

    // trie node
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        int cont;
    };

    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;

        pNode->cont = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    void insert(struct TrieNode *root, string key,int i)
    {
        struct TrieNode *pCrawl = root;
        bool ok=false;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - '0';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }
         pCrawl->cont++;/// make the last of this word as counter 
    }


    bool search(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - '0';
            pCrawl = pCrawl->children[index];
        }
        if(pCrawl->cont==1){return true;}/// check the last counter 
        else return false;
    }

    // Driver
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        struct TrieNode *root = getNode();
        int n;
        cin >> n;
        int caso=0;
        string ans[n];
        string s;
        for (int k=0;k<n;k++)
        {
            m.clear();
            cin>>s;
            ans[k]=s;
            int len=s.length();
            for(int i=0;i<len;i++)
            {
                string temp="";
                for(int j=i;j<len;j++)
                {
                    temp=temp+s[j];
                    if(m[temp]==0){ /// keep track of subsequence of same string can't be able to make counter increase 
                    insert(root,temp,k);
                    m[temp]++;
                    }
                }
            }
        }
        for(int p=0;p<n;p++)
        {
            s=ans[p];
            string res="9999999999";/// It can be maximum string one 
            int len=s.length();
            for(int i=0;i<len;i++)
            {
                string temp="";
                for(int j=i;j<len;j++)
                {
                    temp=temp+s[j];
                    if(search(root,temp))
                    {
                        if(temp.size()<res.size())
                        {
                            res=temp;
                        }
                    }
                }
            }
            cout<<res<<'\n';
        }
        return 0;
    }
