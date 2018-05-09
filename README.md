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
**Recursive algorithms can be very space ineffiecent. Each recursive call adds a new layer to the stack, which means that if my algorithm recurses to a depth of n, it uses at least O(n) memory**
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

