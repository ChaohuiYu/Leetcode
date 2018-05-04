
//Permute
//backtracking, DFS 
//Choose / explore/ unchoose



// the SOP of backtracking!

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited {false};
        vector<int> tmp;
        
        permuteHelper(res, visited, tmp, nums, nums.size() );
        return res;
    }
    
    void permuteHelper(vector<vector<int>> &res, vector<bool>& visited, vector<int>& tmp, vector<int>& nums,int n )
    {
        if(tmp.size()==n)
        {
            res.push_back(tmp);
            return;
        }
        else
        {
            for (int i=0;i<n;++i)
            {
                
                if (!visited[i])
                {   
                    //choose
                    visited[i] = true;
                    tmp.push_back(nums[i]);
                    //explore
                    permuteHelper(res, visited , tmp, nums, n );
                    
                    //un-choose
                    visited[i] = false;
                    tmp.pop_back();
                }
                
                    
            }
        }
    }
    
};



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

		vector<vector<int>> res;        
        permuteHelper(res, 0, nums);
        return res;
    }

    void permuteHelper (vector<vector<int>>& res, int chosen_index, vector<int>& nums)
    {
    	// Stop condition (base) 
	   	if (chosen_index>=nums.size())
    	{
    		res.push_back(nums);
    		return ;
    	}
    	else
    	{	
    		for (int i=chosen_index;i<nums.size();++i)
    		{
    			//choose a number
    			swap(nums[chosen_index],nums[i]);

    			//explore

    			permuteHelper(res, chosen_index+1, nums);

    			//un-choose, reset 

    			swap(nums[chosen_index],nums[i]);
    		}

    	}

    }
};

