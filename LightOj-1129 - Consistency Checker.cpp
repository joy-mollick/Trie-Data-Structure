    #include <bits/stdc++.h>
    using namespace std;

    const int ALPHABET_SIZE = 10;

    // trie node
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

    void insert(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - '0';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }

        pCrawl->isEndOfWord = true;
    }


    bool search(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - '0';
            if (!pCrawl->children[index]) {
                return false;
            }
            pCrawl = pCrawl->children[index];
            if(pCrawl->isEndOfWord) return true;
        }
      return true;
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
            bool ans=false;
            for (i=0;i<n;i++)
            {
                cin >> s;
                /// when ans is true ,then there is no need to check ,it will reduce time and memory complexity 
                if(search(root,s)&&!ans) {ans=true;}
                if(!ans) insert(root, s);
            }
            delet(root);///after every test_case , node should be cleared 
            if(ans) printf("Case %d: NO\n",caso);

            else printf("Case %d: YES\n",caso);

        }
        return 0;
    }

