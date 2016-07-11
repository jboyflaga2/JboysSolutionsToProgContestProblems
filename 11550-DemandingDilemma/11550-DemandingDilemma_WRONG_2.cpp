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
                        8:58 PM - started coding for new solution (using adjacency list)
                            - na koy lahi gihimo
                        9:29 PM - started coding for new solution (using adjacency list)
                        10:20 PM - I think I will use edge list to determine if an edge has more than 2 vertices 
                                and will use an adjacency list to determine if there are multiple edges for a pair of vertices
                        11:20 PM - AMBOT
                                Naa koy idea unsaon pag solve:
                                    1. i-add ang tanan values sa isa ka column ... if sum is not equal to 2 then output is "No"
                                    2. 
                        11:55 PM - AMBOT... NEXT TIME NA LANG NI.. PAG DAGHAN NA KOG NAHIBAL-AN ABOUT GRAPHS
**********************************************************/

// #include <iostream>
// #include <vector>

// using namespace std;

// typedef vector<int> ListOfVertices;
// typedef vector<int> ListOfNeighboringVertices;
// const int INCIDENT = 1;

// int main()
// {
//     freopen("test.in", "r", stdin);
//     freopen("test.out", "w", stdout);    
//     freopen("test.err", "w", stderr);

//     int numOfTestCases;
//     cin >> numOfTestCases;

//     vector<ListOfVertices> edgeList;
//     vector<ListOfNeighboringVertices> adjacencyList;
//     int numOfVertices, numOfEdges, currentCellValue;

//     for(int n = 0; n < numOfTestCases; n++)
//     {
//         cin >> numOfVertices >> numOfEdges;
//         edgeList.assign(numOfEdges, ListOfVertices());
        
//         int incidenceMatrix[numOfVertices][numOfEdges];
//         // read the incidence matrix
//         for(int row = 0; row < numOfVertices; row++)
//         {
//             for(int col = 0; col < numOfEdges; col++)
//             {
//                 cin >> currentCellValue;
//                 incidenceMatrix[row][col] = currentCellValue;
//             }
//         }
        
//         // row
//         for(int currentVertex = 0; currentVertex < numOfVertices; currentVertex++)
//         {
//             // column
//             for(int currentEdge = 0; currentEdge < numOfEdges; currentEdge++)
//             {
//                 currentCellValue = incidenceMatrix[currentVertex][currentEdge];
//                 if(currentCellValue == INCIDENT)
//                 {
//                     edgeList[currentEdge].push_back(currentVertex);
//                     // you can optimize here
//                     //  - you can check here if currentEdge has more than 3 vertices and if that is the case
//                     //      break from the loop and display "No" as output

//                     //look for the partner vertex of this currentEdge
//                     for(int row = 0; row < numOfVertices; row++)
//                     {
//                         if(incidenceMatrix[row][currentEdge] == INCIDENT)
//                         {
//                         	int partnerVertex = row;
//                             adjacencyList[currentVertex].push_back(partnerVertex);
//                             adjacencyList[partnerVertex].push_back(currentVertex);
//                         }
//                     }
//                 }
//             }
//         }

//         // determine if it is a wrong graph
//         //  - an edge has only one vertex
//         //  - an edge has more than 2 vertices
//         bool isCorrectGraph = true;
//         vector<ListOfVertices>::const_iterator iter;;
//         for(iter = edgeList.begin(); iter != edgeList.end(); iter++)
//         {
//             ListOfVertices verticesOfCurrentEdge = *iter;
//             if(verticesOfCurrentEdge.size() != 2) 
//             {
//                 isCorrectGraph = false;
//                 break;
//             }
//         }

//         // determine if it has multiple edges for a single pair of vertices
//         bool hasNoMultipleEdges = true;
//         if(isCorrectGraph)
//         {            
//             // vector<ListOfNeighboringVertices>::const_iterator vericesIterator;;
//             // for(vericesIterator = adjacencyList.begin(); vericesIterator != adjacencyList.end(); vericesIterator++)
//             // {
//             //     ListOfNeighboringVertices neighboringVertices = *vericesIterator;


//             //     if(verticesOfCurrentEdge.size() != 2) 
//             //     {
//             //         isCorrectGraph = false;
//             //         break;
//             //     }
//             // }

//             for(int v = 0; v < adjacencyList.size();v++)
//             {
//                 ListOfNeighboringVertices neighboringVertices = adjacencyList[v];
//                 for(int n = 0;n < neighboringVertices.size() - 1; n++)
//                 {
//                     int currentVertex = neighboringVertices[n];
//                     int nextVertex = neighboringVertices[n + 1];
//                     if(currentVertex == nextVertex)
//                     {
//                         hasNoMultipleEdges = false;
//                     }
//                 }

//             }

//         }


//         // output for current test case
//         bool isIncidentMatrix = isCorrectGraph && hasNoMultipleEdges;
//         if(isIncidentMatrix) { cout << "Yes\n"; }
//         else { cout << "No\n";}
        
//     }

//     return 0;
// }