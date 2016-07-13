/**********************************************************
Jboy Flaga

Analysis - see notes on printed problem specification

Started:	  July 13, 2016 4:00 PM
Finished:	  July 13, 2016 5:42 PM - first submissions - Time Limit

**********************************************************/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

using namespace std;

/**
 This SegmentTree class is from Competitive Programming 3e
*/
class SegmentTree {         // the segment tree is stored like a heap array
private: vector<long> st, A;            // recall that vi is: typedef vector<int> vi;
  long n;
  long left (long p) { return p << 1; }     // same as binary heap operations
  long right(long p) { return (p << 1) + 1; }

  void build(long p, long L, long R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = L;                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      long p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  } }

  long rmq(long p, long L, long R, long i, long j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    long p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    long p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return (A[p1] <= A[p2]) ? p1 : p2; }          // as as in build routine

  long update_point(long p, long L, long R, long idx, long new_value) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    long i = idx, j = idx;

    // if the current interval does not intersect 
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
      A[i] = new_value; // update the underlying array
      return st[p] = L; // this index
    }

    // compute the minimum pition in the 
    // left and right part of the interval
    long p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    // return the pition where the overall minimum is
    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }

public:
  SegmentTree(const vector<long> &_A) {
    A = _A; n = (long)A.size();              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(1, 0, n - 1);                                  // recursive build
  }

  long rmq(long i, long j) { return rmq(1, 0, n - 1, i, j); }   // overloading

  long update_point(long idx, long new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
};

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);    
    //freopen("test.err", "w", stderr);

    while(true)
    {
        long numOfIntegers;
        cin >> numOfIntegers;
        if(numOfIntegers == 0) { break; } // there are no more test cases

        long numOfQueries;
        cin >> numOfQueries;

        long theNumbers[numOfIntegers + 1]; // "+ 1" because we will not start from zero but from one
        for(long n = 1; n < numOfIntegers + 1; n++)
        {
            cin >> theNumbers[n];
        }

        long rangeLeft, rangeRight;
        // foreach query
        for(long q = 0; q < numOfQueries; q++)
        {
            cin >> rangeLeft >> rangeRight;

            //cerr << "for range " << rangeLeft << " " << rangeRight << endl;

            bool isOnlyOneValue = rangeLeft == rangeRight;
            if(isOnlyOneValue)
            {
                cout << "1" << endl;
            }
            else
            {                
                // create vector that contains the counter of the number of occurrences (see notes on printed problem specification)
                vector<long> vecCounter;
                int counter = 1;
                vecCounter.push_back(counter * -1); // initial counter // multiply it by -1 because we will be using "range minimum query" instead of "Maximum"
                for(long currentPosition = rangeLeft + 1; currentPosition <= rangeRight; currentPosition++)
                {
                    bool isCurrentNumSameAsPreviousOne = theNumbers[currentPosition] == theNumbers[currentPosition - 1];
                    if(isCurrentNumSameAsPreviousOne)	{ counter++; }
                    else                                { counter = 1; }

                    vecCounter.push_back(counter * -1); // multiply it by -1 because we will be using "range minimum query" instead of "Maximum"
                }

                // // print vector 
                // cerr << "     ";
                // std::copy(vecCounter.begin(), vecCounter.end(), std::ostream_iterator<long>(std::cerr, " "));
                // cerr << endl;

                SegmentTree segmentTree(vecCounter);
                long indexOfMinValue = segmentTree.rmq(1, vecCounter.size());            

                //cerr << "    indexOfMinValue = " << indexOfMinValue << endl;

                // output for current query
                cout << (vecCounter[indexOfMinValue] * -1) // we multiply by -1 to make it positive again
                    << endl;
            }

        }
    }
    return 0;
}