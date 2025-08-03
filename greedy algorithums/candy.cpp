class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1;
        int i=1;
        int n=ratings.size();

        while(i<n){

            //for flat surface
            if(ratings[i] == ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }

            //for incresing surface
            int peak=1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++; sum+=peak; i++;
            }

            // for decreasing surface
            int down=1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum+=down; down++; i++;
            }

            // for exceptional peak case
            if(down > peak){
                sum += down-peak;
            }

        }
        return sum;
    }
};