class Binary_Search {
public:
    // Both returns 0 based index
    int find(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m;
        while(l<=r){
            m=l+(r-l)/2;
		    if(nums[m]<target){
			    l=m+1;;
		    }else if(target<nums[m]){
			    r=m-1;
		    }else{
			    return m; 
		    }
        }
    }
    int lower_bound(vector<int>& nums, int target) {
        int l=0, r=nums.size(), m, n=r;
        while(l<r){
            m=l+(r-l)/2;
		    if(nums[m]<target){
			    l=m+1;;
		    }else{
			    r=m;
		    }
        }
        if(l<n && nums[l]<target){
            l++;
        }
        return l;
    }
    int upper_bound(vector<int>& nums, int target) {
        int l=0, r=nums.size(), m, n=r;
        while(l<r){
            m=l+(r-l)/2;
		    if(nums[m]>target){
			    r=m;
		    }else{
			    l=m+1; // upper_bound doesn't contain equal value, so does l=m+1
		    }
        }
        if(l<n && nums[l]<=target){
            l++;
        }
        return l;
    }
};
