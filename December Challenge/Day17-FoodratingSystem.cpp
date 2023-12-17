// Key Note
// set store the pair of negative rating and food, 
// so that in case of rate tie, the lexicographically smaller food is stored first.
// example = (cuisine -> {{-16,shi}, {-16, xyz}, {-15, abs}});

// TC = O(N) for Food Ratings
//      O(1) for both changeRating and highestRated;
// SC = O(N)

class FoodRatings {
public:
    unordered_map<string, pair<string, int>> foodRatings;
    unordered_map<string,set<pair<int, string>>> cuisineMap;
    int n;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for(int i=0;i<n; i++) // O(N)
        {
            foodRatings[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({-1*ratings[i], foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        string cus;
        //cout<<"here"<<endl;
        //cout<<foodRatings[food].second<<endl;
        int oldRating = foodRatings[food].second;
        foodRatings[food].second = newRating;
        //cout<<"new "<< foodRatings[food].second<<endl;

        cus = foodRatings[food].first;

        cuisineMap[cus].erase({-1*oldRating, food});
        cuisineMap[cus].insert({-1*newRating, food});
        
        
    }
    
    string highestRated(string cuisine) {
        return begin(cuisineMap[cuisine])->second; //O(1)
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */