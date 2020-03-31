  #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    bool check(ll n,int pos) { return (n>>pos)&1; }
    // trie node
    struct TrieNode
    {
        struct TrieNode *children[2];/// one for one (1) and another for zero (0)
    };

    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
        for (int i = 0; i < 2; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    void insert(struct TrieNode *root, ll key)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 50; i >=0; i--)
        {
            int index = (int)check(key,i);
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }
    }
    ll max_query(ll key,struct TrieNode *root)
    {
        struct TrieNode* pCrawl=root;
        ll mx_val=0ll;
        for(int i=50;i>=0;i--)
        {
            int index=check(key,i);
            if(pCrawl->children[index^1])/// when index is 0, then we will choose 1 (0^1)=1 or we will choose 0 when index is 1 (1^1)=0 
            {
                mx_val+=(1ll<<i);/// here xor will give value 1 so take this one
                pCrawl=pCrawl->children[index^1];
            }
            else
            {
                 pCrawl=pCrawl->children[index];/// the index^1 is null , so we have to index
            }
        }
        return (mx_val);
    }


    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        struct TrieNode *root = getNode();
        int n;
        cin>>n;
        char ch;
        ll x;
        ll suff_xor=0;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>x;
            arr[i]=x;
            suff_xor=suff_xor^x;
        }
        ll pref_xor=0;
        ll mxx=0;
        insert(root,0);/// when no prefix taken ,for that case , previously 0 has been taken into trie 
        for(int i=0;i<n;i++)
        {
        suff_xor ^= arr[i];/// now our suffix range xor is from n-1 to i+1 
        pref_xor ^= arr[i];
        insert(root,pref_xor);
        mxx = max(mxx,max_query(suff_xor,root));/// we have to check is there any prefix available for suffix (i+1,n-1) with whom it causes maximum xor 
        }
        cout<<mxx<<endl;
    }
