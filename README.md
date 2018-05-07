# Leetcode

## Array 

### Dynamic Array
  Most programming languages offer built-in *dynamic array* which is still a random access list data structure but with *variable size*. For example, we have vector in C++ and ArrayList in Java.
  Please refer to: [66](./66_Plus_One/)

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
