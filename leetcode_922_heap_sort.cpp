class Solution {
public:
    void max_heapify(int i, int k, vector<int>& nums){
        int l=2*i+1, r=l+1, big=i;
        if(l<k && nums[l]>nums[big]){
            big=l;
        }
        if(r<k && nums[r]>nums[big]){
            big=r;
        }
        if(big!=i){
            swap(nums[i], nums[big]);
            max_heapify(big, k, nums);
        }
    }
    void build_max_heap(int k, vector<int>& nums){
        for(int i=k/2-1; i>=0; i--){
            max_heapify(i, k, nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int k=nums.size();
        build_max_heap(k, nums);
        while(k--){
          swap(nums[k], nums[0]);
          max_heapify(0, k, nums);
        }
        return nums;
    }
};
