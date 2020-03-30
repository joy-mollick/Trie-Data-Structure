#include <bits/stdc++.h>
    using namespace std;

    const int ALPHABET_SIZE = 26;

    // trie node
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        string s;/// take desired string of gicen prefix 
        int mx_tms;/// it will keep track of maximum time of string 
    };

    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
        pNode->mx_tms=0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    void insert(struct TrieNode *root, string key,int times)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
            if(pCrawl->mx_tms<times)
            {
                pCrawl->mx_tms=times;
                pCrawl->s=key;
            }
            else if(pCrawl->mx_tms==times)
            {
                pCrawl->s=min(pCrawl->s,key);
            }
        }
    }


    string search(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if(!pCrawl->children[index]) {return "0";}
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl->s);
    }

    /*
    void delet(struct TrieNode *root)
    {
         for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->children[i])
            delet(root->children[i]);
    }
       delete (root);
    }
    */

    // Driver
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        struct TrieNode *root = getNode();
        int n;
        cin >> n;
        string s;
        unordered_map<string,int>mp;/// very fast than normal map 
        while(n--)
        {
            cin>>s;
            mp[s]++;
            int tms=mp[s];
            insert(root,s,tms);
        }
        cin>>n;
        string pref;
        int caso=0;
        while(n--)
        {
            caso++;
            cin>>pref;
            string ans=search(root,pref);
            if(ans=="0") cout<<"Case "<<caso<<": -1";
            else
            cout<<"Case "<<caso<<": "<<ans<<" "<<mp[ans];
            cout<<'\n';
        }
        return 0;
    }
