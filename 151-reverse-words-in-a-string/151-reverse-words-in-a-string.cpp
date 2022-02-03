#include <bits/stdc++.h>
#include <string.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        deque <string> deck;
        int start=-1;
        int end = -1;
        for(int i = 0;i<s.length();i++)
        {
            if( ((s[i]>='a' && s[i] <='z') || 
                (s[i]>='0' && s[i] <='9') ||
                (s[i]>='A' && s[i]<='Z'))  && start == -1 && end == -1)
            {
                cout <<"marking start at "<< i <<"\n";
                start = i;
                if(s[i+1]==' ' || s[i+1]=='\0')
                    end = i;
            }
            else if( (s[i+1] == ' ' ||s[i+1]=='\0') && start != -1 && end ==-1)
            {
                cout <<"marking end at "<< i <<"\n";
                end = i;
            }
            else if(start == -1 && end ==-1 && s[i] == ' ')
            {
                cout <<"skipping space at "<< i <<"\n";
                continue;
            }
            
            if(start != -1 && end != -1)
            {
                char tmp[100];
                cout <<"Pushing string starting at "<< start <<" to "<<end<<"\n";
                int idx = 0;
                for(int i = start;i<=end;i++)
                {
                    tmp[idx] = s[i];
                    idx++;
                }
                tmp[idx] = '\0';
                cout <<"Pushing string "<<tmp <<"\n";
                deck.push_front(tmp);
                deck.push_front(" ");
                start = -1;
                end = -1;
            }
        }
        string out;
        //popped extra space
        deck.pop_front();
        while (deck.empty()!=true)
        {
            out.append(deck.front());
            deck.pop_front();
        }
        return out;
    }
};