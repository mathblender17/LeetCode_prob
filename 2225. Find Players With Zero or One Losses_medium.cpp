class Solution {
public:
/**
->mostly deals with maps and how to handle them - logic wise pretty basic
1.2 hash maps for keeping the rercord of wins and losses of the players
2.also keep in mind to have all the elements in both the maps - even if we get 0 loss or 0 wins
3.2 vector for keeping track of noLosses and one loss
*/

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> wins;
        unordered_map<int,int> losses;

        for(const auto& match : matches){
            int winner=match[0];
            int loser=match[1];
            wins[winner]++;
            losses[loser]++;

            if(wins.find(loser) == wins.end()){
                wins[loser]=0;
            }
            if(losses.find(winner) == losses.end()){
                losses[winner]=0;
            }
        }

        vector<int> noLoss;
        vector<int> oneLoss;
        for(auto player : wins){
            int chWin=player.first;
            if(losses[chWin] == 0){
                noLoss.push_back(chWin);
            }
        }
        for(auto player : losses){
            int chWin=player.first;
            if(losses[chWin] == 1){
                oneLoss.push_back(chWin);
            }
        }
        sort(noLoss.begin(),noLoss.end());
        sort(oneLoss.begin(),oneLoss.end());
        return {noLoss,oneLoss};
    }
};
