//keep repeating string a in each iteration and keep finding b each time
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string temp="";
        while(temp.length()< (b.length()+a.length()) )
        {
            if(temp.find(b) < temp.length())
            {
               return count;
            }
            else
            {   
                temp= temp.append(a);
                //cout <<"Didnt find, repeated string is now "<<temp<<"\n";
                count++;
            }
        }
        if(temp.find(b) < temp.length())
            return count;
        else
            return -1;
    }
};