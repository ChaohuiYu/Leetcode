
//Permute 
//Choose / explore/ unchoose



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int>> res;        
        permuteHelper(res, 0, nums);
        return res;
    }



    void permuteHelper (vector<vector<int>>& res, int chosen_indext, vector<int> nums)
    {
    	// Stop condition
	   	if (chosen_indext>=nums.size())
    	{
    		res.push_back(nums);
    		return ;
    	}
    	else
    	{	
    		for (int i=0;i<nums.size();++i)
    		{
    			//choose a number
    			swap(nums[chosen_indext],nums[i]);

    			//explore

    			permuteHelper(res, chosen_indext+1, nums);

    			//un-choose

    			swap(nums[chosen_indext],nums[i]);
    		}

    	}

    }
};

