    #include <bits/stdc++.h>
    using namespace std;

    const int ALPHABET_SIZE = 4;

    int ans;

    // trie node
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        int cont;
    };
    int indexx(char ch)
    {
         if(ch == 'A')
        return 0;

    else if(ch == 'C')
        return 1;

    else if(ch == 'G')
        return 2;

        return 3;
    }
    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
        pNode->cont=0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    void insert(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;
        int i;
        for ( i = 0; i < key.length(); i++)
        {
            int index = indexx(key[i]);
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
            pCrawl->cont++;
        }
    }
    /// use dfs to find maximum ans 
    void dfs(struct TrieNode *root,int lev)
    {
        ans=max(ans,lev*(root->cont));
        for(int i=0;i<ALPHABET_SIZE;i++)
        {
            if(root->children[i]!=NULL)
                dfs(root->children[i],lev+1);
        }
    }
    void delet(struct TrieNode *root)
    {
         for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->children[i])
            delet(root->children[i]);
    }
       delete (root);
    }

    // Driver
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin >> t;
        int caso=0;
        while (t--)
        {
            caso++;
            struct TrieNode *root = getNode();
            int n, i;
            cin >> n;
            string s;
            ans=0;
            for (i=0;i<n;i++)
            {
                cin >> s;
                insert(root, s);
            }
            dfs(root,0);
            delet(root);
            printf("Case %d: %d\n",caso,ans);
        }
        return 0;
    }

