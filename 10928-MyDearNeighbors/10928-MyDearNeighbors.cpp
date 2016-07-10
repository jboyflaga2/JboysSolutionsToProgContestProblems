/**********************************************************
Jeremiah (Jboy) Flaga
Started:	July 10, 2016 9:15 PM
Finished:   July 10, 2016 10:20 PM - first submission
            July 10, 2016 10:55 PM - fourth submission

Problems encountered:
1. Problem of using getline() after using cin - http://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm
2. first submission - encountered Presentation Error (PE)
3. second submission - encountered Wrong Answer (WA) after I added 
           if(n > 0) { cout << endl; }
   to remove newline at the end of output
   ..because I thought that it is the reason for the Presentation Error in first submission

(maybe the reason is the extra space at the end of each line?)
4. third submission - still Presentation Error
                if(isFirstOutput) 
                {
                    cout  << ' '; 
                    isFirstOutput = false;
                }
                cout << currentPlace + 1;

        The OUPUT is (which should result to a Wrong Answer; but it's a Presentation Error instead... hmmm):
         1
         12
         2
         3

5. fourth submission - Accepted
    SOLUTION:        
                if(!isFirstOutput) { cout  << ' '; }
                cout << currentPlace + 1;
                isFirstOutput = false;

**********************************************************/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void OutputAdjacencyList(vector<vector<int> > adjList)
{
    for(int i = 0; i < adjList.size(); i++)
    {
        cerr << i + 1 << ": ";

        vector<int> neighbors = adjList[i];
        for(int j = 0; j < neighbors.size(); j++)
        {
            cerr << neighbors[j] << ' ';
        }
        cerr << endl;
    }
    cerr << endl;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);    
    //freopen("test.err", "w", stderr);

    int numOfTestCases;

    cin >> numOfTestCases;

    // foreach test case
    for(int n = 0; n < numOfTestCases; n++)
    {
        //if(n > 0) { cout << endl; } // after encountering presentation error in UVA Online Judge

        int numOfPlaces;
        cin >> numOfPlaces;
        cin.ignore(100,'\n');
        
        // assign N number of vector<int> to the adjacencyList
        vector<vector<int> > adjacencyList(numOfPlaces, vector<int>());
        int currentMinimumNumberOfNeighbors = numOfPlaces - 1;

        //foreach place
        for(int currentPlace = 0; currentPlace < numOfPlaces; currentPlace++)
        {
            string strNeighbors;
            getline(cin, strNeighbors);
            stringstream stream(strNeighbors);

            int currentNeighbor;
            int numOfNeighborsInCurrentPlace = 0;
            while(stream >> currentNeighbor)
            {
                adjacencyList[currentPlace].push_back(currentNeighbor);
                numOfNeighborsInCurrentPlace++;
            }

            // update current minimum number of neighbors
            if(numOfNeighborsInCurrentPlace < currentMinimumNumberOfNeighbors)
            {
                currentMinimumNumberOfNeighbors = numOfNeighborsInCurrentPlace;
            }
        }

        //OutputAdjacencyList(adjacencyList);

        // output
        bool isFirstOutput = true;
        for(int currentPlace = 0; currentPlace < numOfPlaces; currentPlace++)
        {
            if(adjacencyList[currentPlace].size() == currentMinimumNumberOfNeighbors)
            {
                if(!isFirstOutput) { cout  << ' '; }
                cout << currentPlace + 1;
                isFirstOutput = false;
            }
        }
        cout << endl;
    }    

    return 0;
}