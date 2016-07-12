# My solutions to some programming problems from UVA Online Judge (and from other related sites)



# Some important things to remember:

0\. BE CAREFUL!

There are times when the reason for a verdict of "Wrong answer (WA)" in UVA Online Judge is only because a newline at the end of your output is missing.

Example problems where this is the case:
 - 793-NetworkConnections.cpp

1\. How to initialize a vector of vectors (used in 10928-MyDearNeighbors.cpp)
``` C++
// assign N number of vector<int> to the adjacencyList
vector<vector<int> > adjacencyList(N, vector<int>());
```
or
``` C++
// quick way to initialize adjacencyList with N entries of vector<int>
adjacencyList.assign(N, vector<int>());
// vector.assign() -> Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly. (from http://www.cplusplus.com/reference/vector/vector/assign/)
```
or
``` C++
typedef vector<int> ListOfNeighboringVertices; // used in 11550-DemandingDilemma.cpp

adjacencyList.assign(N, ListOfNeighboringVertices());
```


2\. Be careful when using `getline()` after using `cin` - http://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm

Use `cin.ignore(100,'\n');` - used in 10928-MyDearNeighbors.cpp