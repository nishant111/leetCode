


class Solution {
private:
    int isP(string s, int left ,int right)
    {
        int i = left;int j = right;
        for(;i<j;i++,j--)
        {
            if(s[i]!=s[j])
                return 0;
        }
    return 1;
    }
    void dfs(string s, int index,vector <string> &part , vector<vector <string>> &res)
    {
        if(index == s.size())
        {
            res.push_back(part);
            return;
        }
        for(int i = index;i<s.size();i++)
        {
            if(isP(s,index,i ))
            {
                part.push_back(s.substr(index, i-index+1));
                dfs(s, i+1, part, res);
                part.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> part;
        vector<vector<string>> res;
        dfs(s,0, part, res);
        return res;
    }
    
};





/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/* C Solution Below :
int isP(char *s, int left ,int right)
{
    int i = left;int j = right;
    for(;i<j;i++,j--)
    {
        if(s[i]!=s[j])
            return 0;
    }
    return 1;
}

void dfs(char* s, char ***part, int partSize, char ****res, int curr, int *rs, int **rcs )
{
    int done = 0;
    if(curr == strlen(s))
    {
        (*rs)++;
        (*res) = realloc(*res, sizeof(char**)*(*rs));
        (*res)[(*rs)-1]= calloc(partSize, sizeof(char*));
        //(*res)[(*rs)-1] = (*part);
        for(int i = 0;i<partSize;i++)
        {
            (*res)[(*rs)-1][i] = calloc(17, sizeof(char));
            strcpy((*res)[(*rs)-1][i],(*part)[i]);
        }
        (*rcs) = realloc(*rcs, sizeof(int) * (*rs)) ;
        (*rcs)[(*rs)-1] = partSize;
        
        return;
    }
    else
    {
        for(int i = curr;i<strlen(s);i++)
        {
            if(isP(s, curr, i))
            {
                (partSize)++;
                (*part) = realloc(*part, sizeof(char*) * (partSize) );
                (*part)[(partSize)-1] = malloc(sizeof(char)* 17); // valid str to be saved
                int j = curr;
                int idx = 0;
                for( ;j<=i;j++,idx++)
                {
                    (*part)[(partSize)-1][idx] = s[j];
                }
                (*part)[(partSize)-1][idx] = '\0';
                //printf("\npartSize is %d",partSize);
                //printf("\nString is %s",(*part)[(partSize)-1]);
                dfs(s, part, partSize, res, i+1, rs, rcs );
                //  once all dfs return , reset part and find new seq;
                //*part = realloc(*part,partSize * sizeof(char*) );
                (partSize--);
                //(*part) = NULL;
            }
        }
    }
}



char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    char **part = calloc(1, sizeof(char*));
    char ***res = calloc(1, sizeof(char**));
    *returnColumnSizes = calloc(1, sizeof(int)*1);
    *returnSize = 0;
    dfs(s, &part,  0, &res, 0, returnSize, returnColumnSizes);
    //  char* s, char ***part, int *partSize, char ****res, int curr, int *rs, int **rcs
    return res;
}*/