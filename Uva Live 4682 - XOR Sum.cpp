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

    // Driver
    int main()
    {
        ///ios_base::sync_with_stdio(false);
        ///cin.tie(NULL);
        int tc;
        scanf("%d",&tc);
        for(int caso=1;caso<=tc;caso++)
        {
        struct TrieNode *root = getNode();
        int mx=0;
        int prefix_xor=0;
        int n,a;
        insert(root,0);/// here we have to check first ,that's why we have created a root node first
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&a);
            prefix_xor^=a;
            mx=max(mx,max_query(prefix_xor,root));
            insert(root,prefix_xor);
        }
        printf("%d\n",mx);
        ///delet(root);
        }
        return 0;
    }
