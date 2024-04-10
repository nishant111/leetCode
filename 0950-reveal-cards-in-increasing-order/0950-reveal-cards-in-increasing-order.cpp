class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> sortedDeck = deck;
        queue<int> q;
        for(int i = 0;i<sortedDeck.size();i++){
            q.push(i);
        }
        int take = true;
        vector<int> res(sortedDeck.size());
        int curr = 0;
        while(!q.empty() && curr<sortedDeck.size()){
            if(take){
                res[q.front()]=sortedDeck[curr++];
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop();
            }
            take = !take;
        }
        return res;
    }
};