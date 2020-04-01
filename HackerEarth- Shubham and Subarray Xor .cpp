#include <bits/stdc++.h>
    using namespace std;


/// Here ,for property xor[l,r] = xor[1,l-1]^xor[1,r] so every time when before inserting value [1^r],we have to check with whome xor(1,.....r-1) it's value is maximum

    const int ALPHABET_SIZE = 2;

    bool check(int n,int pos)
    {
        return ((bool)(n & (1<<pos)));
    }

    // trie node
    struct TrieNode
    {
        struct TrieNode *children[2];/// one for one and another for zero
    };

    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
        for (int i = 0; i < 2; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    void insert(struct TrieNode *root, int key)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 31; i >=0; i--)
        {
            int index = (int)check(key,i);/// check ,this bit is on or not if on then go index=1 or go index=0
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }
    }
    int max_query(int key,struct TrieNode *root)
    {
        struct TrieNode* pCrawl=root;
        int mx_val=0;
        for(int i=31;i>=0;i--)
        {
            int index=check(key,i);
            if(pCrawl->children[index^1])/// when index is 0, then we will choose 1 (0^1)=1 or we will choose 0 when index is 1 (1^1)=0
            {
                mx_val+=(1<<i);/// here xor will give value 1 so take this one
                pCrawl=pCrawl->children[index^1];
            }
            else
            {
                 pCrawl=pCrawl->children[index];/// the index^1 is null , so we have to index
            }
        }
        return (mx_val);
    }
    delet(struct TrieNode *root)
    {
        for(int i=0;i<2;i++)
        {
            if(root->children[i])
                delet(root->children[i]);
        }
        delete(root);
    }
    // Driver
    int main()
    {
        ///ios_base::sync_with_stdio(false);
        ///cin.tie(NULL);
        struct TrieNode *root = getNode();
        int mx=0;
        int pref_sum=0;
        int n,a;
        scanf("%d",&n);
        int arr[n];
        int suff[n];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        suff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--) {suff[i]=arr[i];suff[i]+=suff[i+1];}
        insert(root,arr[0]);
        pref_sum+=arr[0];
        for(int i=1;i<n-1;i++)
        {
            pref_sum+=arr[i];
            int suf=suff[i];
            mx=max(mx,max_query(suf,root));
            insert(root,pref_sum);
        }
        printf("%d\n",mx);
        delet(root);
        return 0;
    }
