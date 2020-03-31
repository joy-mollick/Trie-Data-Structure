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
    int max_query(int key,struct TrieNode *root)
    {
        struct TrieNode* pCrawl=root;
        int mx_val=0;
        for(int i=31;i>=0;i--)
        {
            int index=check(key,i);
            if(pCrawl->children[index^1]&&pCrawl->children[index^1]->cont>0)/// when index is 0, then we will choose 1 (0^1)=1 or we will choose 0 when index is 1 (1^1)=0 ,first check count is greater than zero
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

    void erase(struct TrieNode *root,int key)
    {
        struct TrieNode *cur=root;
        for(int i=31;i>=0;i--)
        {
            int indx=check(key,i);
            cur=cur->children[indx];
            cur->cont--;/// it is the way of deleting ,just reduce count ,when count is zero not enter there 
        }
    }


    // Driver
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        struct TrieNode *root = getNode();
        int n;
        cin>>n;
        char ch;
        int x;
        int p_xor=0;
        insert(root,0);
        while(n--)
        {
            cin>>ch>>x;
            if(ch=='+')
            {
                insert(root,x);
            }
            else if(ch=='-')
            {
               erase(root,x);
            }
            else
            {
                int mx=max_query(x,root);
                cout<<mx<<'\n';
            }
        }
        return 0;
    }
