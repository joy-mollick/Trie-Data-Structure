  #include <bits/stdc++.h>

    using namespace std;



    bool check(int n,int pos) { return (n>>pos)&1; }

    // trie node
    struct TrieNode
    {
        struct TrieNode *children[2];/// one for one and another for zero
        int cont;
    };

    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
        pNode->cont=0;
        for (int i = 0; i < 2; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    void insert(struct TrieNode *root, int key)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 31; i >=0; i--)
        {
            int index = (int)check(key,i);
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
            pCrawl->cont++;
        }
    }
    int min_query(int key,struct TrieNode *root)
    {
        struct TrieNode* pCrawl=root;
        int mn_val=0;
        for(int i=31;i>=0;i--)
        {
            int index=check(key,i);
            if(pCrawl->children[index]&&pCrawl->children[index]->cont>0)/// when index is 0, then we will choose 1 (0^1)=1 or we will choose 0 when index is 1 (1^1)=0 ,first check count is greater than zero
            {
                pCrawl=pCrawl->children[index];
            }
            else
            {
                  mn_val+=(1<<i);/// here xor will give value 1 so take this one
                 pCrawl=pCrawl->children[index^1];/// the index^1 is null , so we have to index
            }
            (pCrawl->cont)--;/// reduce count, so that second time this number can't be used 
        }
        return (mn_val);
    }

    // Driver
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        struct TrieNode *root = getNode();
        int n;
        cin>>n;
        int arr1[n];
        int x;
        for(int i=0;i<n;i++) cin>>arr1[i];
        for(int i=0;i<n;i++) {cin>>x;insert(root,x);}
        for(int i=0;i<n;i++)
        {
            cout<<min_query(arr1[i],root)<<" ";
        }
    }
