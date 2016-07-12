/**********************************************************
Jeremiah (Jboy) Flaga

Analysis: simple application of union-find disjoint set data structure

Started coding:	    July 12, 2016 5:26 PM
                    had a problem with comparing with newline
                    SOLUTION:
                        compare to a string instead because getline() discards newline
Finished coding:    July 12, 2016 7:32 PM - Runtime Error
                    July 12, 2016 8:16 PM
                        - I found out that the UnionFind class below is zero based.
                        TRY THIS INPUT:
                        2
                        q 1 2
                    8:22 - fifth submission - Wrong answer (WA)
                    8:25 - sixth submission - Accepted (AC)
                        - I just put a newline at the end of the output and WA turns into AC
                            - there is something wrong with how the judge checks solution
**********************************************************/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// This UFDS class is from Competitive Programming 3e
// REMEMBER: this UFDS class is zero based
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
	vector<long> parent, rank, setSize;
	long numSets;
  
public:
	UnionFind(long N) {
        setSize.assign(N, 1); 
        numSets = N; 
        rank.assign(N, 0);
        parent.assign(N, 0); 
        for (long i = 0; i < N; i++) { parent[i] = i; }
	}
  
    long findSet(long i) { 
        return (parent[i] == i) ? i : (parent[i] = findSet(parent[i])); 
    }
  
    bool isSameSet(long i, long j) {
        return findSet(i) == findSet(j); 
    }
  
    void unionSet(long i, long j) { 
        if (!isSameSet(i, j)) {
        numSets--; 
        long x = findSet(i), y = findSet(j);
        // rank is used to keep the tree short
        if (rank[x] > rank[y]) { parent[y] = x; setSize[x] += setSize[y]; }
        else                   { parent[x] = y; setSize[y] += setSize[x];
                                if (rank[x] == rank[y]) rank[y]++; } 
        } 
    }
  
  long numDisjointSets() { return numSets; }
  
  long sizeOfSet(long i) { return setSize[findSet(i)]; }
};

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    //freopen("test.err", "w", stderr);

    long numOfTestCases;
    cin >> numOfTestCases;

    for(long n = 0; n < numOfTestCases; n++)
    {
        long numOfComputers;
        cin >> numOfComputers;
        cin.ignore(100, '\n');

        UnionFind unionFind(numOfComputers);
        char command;
        long comp_1, comp_2;
        long numberOfSuccessfulAnswers = 0, numberOfUnsuccessfulAnswers = 0;

        while(true)
        {
            string line;
            getline(cin, line);
            //cout << "line = " << line << endl;
            if(line.compare("") == 0) { break; }

            stringstream strStream(line);
            strStream >> command >> comp_1 >> comp_2;
            
            //cout << "command = " << command << " " << comp_1 << " " << comp_2 << endl;

            if(command == 'c')
            {
                unionFind.unionSet(comp_1 - 1, comp_2 - 1); // we need to do "minus one" because the UFDS class is zero based
            }
            else if(command == 'q')
            {
                //cout << "entered q" << endl;
                bool isSameSet = unionFind.isSameSet(comp_1 - 1, comp_2 - 1);                
                //cout << "after isSameSet" << endl;
                if(isSameSet) 
                    { numberOfSuccessfulAnswers++; }
                else 
                    { numberOfUnsuccessfulAnswers++; }
            }
        }

        // output for current test case
        //cout << "output" << endl;
        if(n > 0) { cout << endl; }
        cout << numberOfSuccessfulAnswers << "," << numberOfUnsuccessfulAnswers  << endl;
    }    

    return 0;
}