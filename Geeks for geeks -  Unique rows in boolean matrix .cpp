/// function problem 

struct TrieNode
{
    struct TrieNode *children[2];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < 1; i++)
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
    }
 if(pCrawl->isEndOfWord&&pCrawl != NULL) return true;
 else return false;
}
void printMat(int M[MAX][MAX],int row,int col)
{
   struct TrieNode *root=getNode();
   for(int i=0;i<row;i++)
   {
       string s="";
       for(int j=0;j<col;j++)
       {
           if(M[i][j]==1) s=s+'1';
           else s=s+'0';
       }
   if(!search(root,s))
   {
       insert(root,s);
       for(int i=0;i<s.size();i++)
       {
           cout<<s[i]<<" ";
       }
       cout<<"$";
   }
   
   }
   }
