#include <bits/stdc++.h>

    using namespace std;



    bool check(int n,int pos) { return (n>>pos)&1; }

    // trie node
    struct TrieNode
    {
        struct TrieNode *zerochild;
        struct TrieNode *onechild;
        int zero_count;
        int one_count;
    };

    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
        pNode->zero_count=0;
        pNode->one_count=0;
        pNode->zerochild=NULL;
        pNode->onechild=NULL;
        return pNode;
    }

    void insert(struct TrieNode *root, int n)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 21; i>=0; i--)
        {
            bool index =check(n,i);
            if(index) /// this bit is on
                {
                    pCrawl->one_count++;
                if (!pCrawl->onechild)
                 pCrawl->onechild= getNode();

                  pCrawl = pCrawl->onechild;
                }

                else /// this bit is zero
                {
                     pCrawl->zero_count++;
                if (!pCrawl->zerochild)
                 pCrawl->zerochild= getNode();

                  pCrawl = pCrawl->zerochild;
                }
        }
    }

    int query_less_than_k(struct TrieNode *root,int x,int k)
    {
        struct TrieNode *cur=root;
        int res=0;/// it will hold result
        for(int i=21;i>=0;i--)
        {
            bool kth=check(k,i);
            bool xth=check(x,i);

            /// Now main game

            if(kth) /// bit is on
            {
                if(xth)
                {
                    res=res+(cur->one_count);/// when xth is on then all number with one child side will be added because it causes zero in this position with x which less than k
                    if(!cur->zerochild)
                        return (res);
                    cur=cur->zerochild;
                }
                else
                {
                    res=res+(cur->zero_count);/// when xth is zero , so add zero_count and go through the onechild
                    if(!cur->onechild)
                        return res;
                    cur=cur->onechild;
                }
            }

            else
            {
                if(xth)/// when xth bit is on , then only go to one child ,otherwise return result
                {
                    if(!cur->onechild)
                        return res;
                    cur=cur->onechild;
                }
                else
                {
                    if(!cur->zerochild)/// when xth bit is zero , then only go to zero child ,otherwise return result
                        return res;
                    cur=cur->zerochild;
                }
            }
        }
        return res;
    }

/*
    void delet(struct TrieNode *root)
    {
         for(int i=0;i<128;i++)
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
        int tc;
        cin>>tc;
        while(tc--)
        {
            struct TrieNode *root=getNode();
            int n,k,x;
            cin>>n>>k;
            insert(root,0);
            long long tot=0;
            int pref_xor=0;
            for(int i=0;i<n;i++)
            {
                cin>>x;
                pref_xor=pref_xor^x;
                tot+=query_less_than_k(root,pref_xor,k);
                insert(root,pref_xor);
            }
            cout<<tot<<endl;
        }
        return 0;
    }
