#include <bits/stdc++.h>

    using namespace std;


    char good[26];
   struct TrieNode
   {
       struct TrieNode *children[26];
   };
   struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;

        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;

        return pNode;
    }
    int main()
    {
        struct TrieNode *root=getNode();
        char s[1500];
        scanf("%s",s);
        scanf("%s",good);
        int k;scanf("%d",&k);
        int len=strlen(s);
        int ans=0;
        int pref=0;
        for(int i=0;i<len;i++)
        {
            int occur=0;
            struct TrieNode *curr=root;/// every time from root , new string will start 
            for(int j=i;j<len;j++)
            {
                if(good[s[j]-'a']=='0') occur++;
                if(occur>k) {break;}/// bad characters exceed k
                if(!curr->children[s[j]-'a'])/// if there is no children , make it 
                {
                    pref++;/// number of distinct prefix of substrings 
                    curr->children[s[j]-'a']=getNode();
                    curr=curr->children[s[j]-'a'];
                }
                else
                {
                    curr=curr->children[s[j]-'a'];
                }
            }
        }
        printf("%d\n",pref);
        return 0;
    }
