# Leetcode

## Array 

### Dynamic Array
Please refer to: [66](./66_Plus_One/),[724](./724_Find_Pivot_Index/),[747](./747_Largest_Number_At_Least_Twice_of_Others/)
  <br>Most programming languages offer built-in *dynamic array* which is still a random access list data structure but with *variable size*. For example, we have vector in C++ and ArrayList in Java.
 

    //iterate the vector
    cout << "[Version 1] The contents of v4 are:";
    for (int i = 0; i < v4.size(); ++i) {
        cout << " " << v4[i];
    }
    cout << endl;
    cout << "[Version 2] The contents of v4 are:";
    for (int& item : v4) {
        cout << " " << item;
    }
    cout << endl;
    cout << "[Version 3] The contents of v4 are:";
    for (auto item = v4.begin(); item != v4.end(); ++item) {
        cout << " " << *item;
    }

### String 
Please refer to: [67](./67_Add_Binary)
<br> You should be aware of the time complexity of these built-in operations.For instance, if the length of the string is N, the time complexity of both finding operation and substring operation is O(N).

## Tree
### Traverse A Tree
It is worth noting that when you delete nodes in a tree, deletion process will be in post-order. That is to say, when you delete a node, you will delete its left child and its right child before you delete the node itself.

<br> Implement both recursion and iteration solutions and compare the differences between them.
**Recursive algorithms can be very space ineffiecent. Each recursive call adds a new layer to the stack, which means that if my algorithm recurses to a depth of n, it uses at least O(n) memory.**
**ALL recursive algorithms can be implemented iteratively!!**   
<br>[Morris Traversal 中文解析](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html)

####  Level-order Traversal - Introduction
Please refer to: [102](./102_Binary_Tree_Level_Order_Traversal) 
<br>Typically, we use a queue to help us to do BFS. 

### Solve Tree Problems Recursively

#### Top-down solution
Please refer to:[104](./104_Maximum_Depth_of_Binary_Tree)
<br>"Top-down" means that in each recursion level, we will visit the node first to come up with some values, and pass these values to its children when calling the function recursively. So the "top-down" solution can be considered as kind of preorder traversal. 
<br>Example:

        1. return if root is null
        2. if root is a leaf node:
        3.      answer = max(answer, depth)         // update the answer if needed
        4. maximum_depth(root.left, depth + 1)      // call the function recursively for left child
        5. maximum_depth(root.right, depth + 1)     // call the function recursively for right child

#### Bottom-up Solution
<br>"Bottom-up" is another recursion solution. In each recursion level, we will firstly call the functions recursively for all the children nodes and then come up with the answer according to the return values and the value of the root node itself. This process can be regarded as kind of *postorder* traversal. 


## Binary Search

Terminology used in Binary Search:

    Target - the value that you are searching for
    Index - the current location that you are searching
    Left, Right - the indicies from which we use to maintain our search Space
    Mid - the index that we use to apply a condition to determine if we should search left or Right

- 3 Parts of a Successful Binary Search

    Binary Search is generally composed of 3 main sections:
    Pre-processing - Sort if collection is unsorted.
    Binary Search - Using a loop or recursion to divide search space in half after each comparison.
    Post-processing - Determine viable candidates in the remaining space.

### Binary Search Template I
- Template #1 is used to search for an element or condition which can be determined by accessing a single index in the array.
    int binarySearch(vector<int>& nums, int target){
      if(nums.size() == 0)
        return -1;

      int left = 0, right = nums.size() - 1;
      while(left <= right){
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){ return mid; }
        else if(nums[mid] < target) { left = mid + 1; }
        else { right = mid - 1; }
      }

      // End Condition: left > right
      return -1;
     }

### Binary Search Template II
-  It is used to search for an element or condition which requires accessing the current index and its immediate right neighbor's index in the array.
- Post-processing required. Loop/Recursion ends when you have 1 element left. Need to assess if the remaining element meets the condition.

        int binarySearch(vector<int>& nums, int target){
        if(nums.size() == 0)
            return -1;

          int left = 0, right = nums.size();
          while(left < right){
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){ return mid; }
            else if(nums[mid] < target) { left = mid + 1; }
            else { right = mid; }
          }

          // Post-processing:
          // End Condition: left == right
          if(left != nums.size() && nums[left] == target) return left;
          return -1;
        }

###   Binary Search Template III
- Please refer to 278, 162, 153
- Template #3 is another unique form of Binary Search. It is used to search for an element or condition which requires accessing the current index and its immediate left and right neighbor's index in the array.
- Search Condition needs to access element's immediate left and right neighbors.

        int binarySearch(vector<int>& nums, int target){
        if (nums.size() == 0)
            return -1;

        int left = 0, right = nums.size() - 1;
        while (left + 1 < right){
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        // Post-processing:
        // End Condition: left + 1 == right
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        return -1;
        }

###  Binary Search Template Analysis
- Time and Space Complexity: Runtime: O(log n) -- Logorithmic Time
- Space: O(1) -- Constant Space

## Hash Table
- Hash Table is a data structure which organizes data using hash functions in order to support quick insertion and search.
- The Principle of Hash Table: The key idea of Hash Table is to use a hash function to map keys to buckets.

* To record the states using stack or map: [739](./739_Daily_Temperatures)
* 

