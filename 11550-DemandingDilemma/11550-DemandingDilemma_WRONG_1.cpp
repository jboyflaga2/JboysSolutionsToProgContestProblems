/**********************************************************
Jeremiah (Jboy) Flaga

Started Analysis:   July 11, 2016 8:20 AM until before 9:30 AM kay naay klase sa Chem1
                    July 11, 2016 about 4:00 PM to about 5:15 PM 
Result of analysis:
    I think we can use an Edge List here. Each edge must have 2 vertices.about
    If it has only one or more than 2 vertices then it is not an incidence matrix of an undirected graph.

Started coding:     July 11, 2016 5:20 PM
Finished:           July 11, 2016 6:24 PM - first submission - Wrong answer (WA)
                        I searched for analysis online and found this: https://uva.onlinejudge.org/board/search.php?keywords=11550
                         - I also need to check if a pair of vertices has two edges (remember that this is an undirected graph)
                        I have to go because muuban ko ila Orland sa Bible study
                        8:53 resumed
                        Found this: https://tausiq.wordpress.com/2011/01/11/uva-11550-demanding-dilemma/
                         - a "simple" graph is unweighted, undirected, no loops or multiple edges
                         - I think I still need to use adjacency list instead of an edge list

**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> ListOfVertices;
const int INCIDENT = 1;

void OutputEdgeListToErrorStream(vector<ListOfVertices> edgeList);

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);    
    freopen("test.err", "w", stderr);

    int numOfTestCases;
    cin >> numOfTestCases;

    vector<ListOfVertices> edgeList;
    int numOfVertices, numOfEdges, currentCellValue;

    for(int n = 0; n < numOfTestCases; n++)
    {
        cin >> numOfVertices >> numOfEdges;
        edgeList.assign(numOfEdges, ListOfVertices());
        
        // row
        for(int currentVertex = 0; currentVertex < numOfVertices; currentVertex++)
        {
            // column
            for(int currentEdge = 0; currentEdge < numOfEdges; currentEdge++)
            {
                cin >> currentCellValue;
                if(currentCellValue == INCIDENT)
                {
                    edgeList[currentEdge].push_back(currentVertex);

                    // you can optimize here
                    //  - you can check here if currentEdge has more than 3 vertices and if that is the case
                    //      break from the loop and display "No" as output
                }
            }
        }

        OutputEdgeListToErrorStream(edgeList);

        // output for current test case
        bool isIncidentMatrix = true;
        vector<ListOfVertices>::const_iterator iter;;
        for(iter = edgeList.begin(); iter != edgeList.end(); iter++)
        {
            ListOfVertices verticesOfCurrentEdge = *iter;
            if(verticesOfCurrentEdge.size() != 2) 
            {
                isIncidentMatrix = false;
                break;
            }
        }

        if(isIncidentMatrix) { cout << "Yes\n"; }
        else { cout << "No\n";}
        
    }

    return 0;
}

void OutputEdgeListToErrorStream(vector<ListOfVertices> edgeList)
{
    for(int i = 0; i < edgeList.size(); i++)
    {
        cerr << i + 1 << ": ";

        ListOfVertices vertices = edgeList[i];
        for(int j = 0; j < vertices.size(); j++)
        {
            cerr << vertices[j] << ' ';
        }
        cerr << endl;
    }
    cerr << endl;
}
