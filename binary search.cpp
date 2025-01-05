class Binary_Search {
public:
    // Both returns 0 based index
    ll find(vector<ll>& nums, ll target) {
        ll l=0, r=nums.size()-1, m;
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
    ll lower_bound(vector<ll>& nums, ll target) {
        ll l=0, r=nums.size(), m, n=r;
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
    ll upper_bound(vector<ll>& nums, ll target) {
        ll l=0, r=nums.size(), m, n=r;
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
	ll findClosestVal(vll &v, ll target){
	    ll ans = v[0], l=0, r=v.sz-1, mid;
	
	    while(l<=r){
	        mid = l + (r-l)/2;
	
	        if(abs(v[mid] - target) <= abs(ans - target)){
	            ans = v[mid];
	        }
	/// If multiple solution occurs, output the greater(amax) or lesser(amin) one
	        // else if(abs(v[mid] - target) == abs(ans - target)){
	        //     amax(ans, v[mid]);
	        // }
	
	        if(v[mid] == target){
	            return v[mid];
	        }else if(v[mid] < target){
	            l = mid + 1;
	        }else{
	            r = mid - 1;
	        }
	    }
	    return ans;
	}
};
