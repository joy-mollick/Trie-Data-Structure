#include <bits/stdc++.h>

    using namespace std;

    const int ALPHABET_SIZE = 2;

    char good[26];
    int bd=0;

   int trie[1500*1500][26];

    int main()
    {
        char s[1500];
        scanf("%s",s);
        scanf("%s",good);
        int k;scanf("%d",&k);
        int len=strlen(s);
        string temp="";
        int ans=0;
        int pref=1;
        for(int i=0;i<len;i++)
        {
            int occur=0;
            int cur=1;/// start from root =1 node
            for(int j=i;j<len;j++)
            {
                if(good[s[j]-'a']=='0') occur++;
                if(occur>k) {break;}/// bad characters exceed k
                if(!trie[cur][s[j]-'a'])
                {
                    pref++;/// number of prefix increased as well as size of trie
                    trie[cur][s[j]-'a']=pref;
                    cur=pref;/// now every character goes up to this trie indexing pref.
                }
                else
                {
                    cur=trie[cur][s[j]-'a'];
                }
            }
        }
        pref--;/// prefix is one increment for root , so decrease one , it will count now number of distinct substrings 
        printf("%d\n",pref);
        return 0;
    }
