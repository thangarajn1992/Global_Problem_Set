/* Leetcode Repo Link
 * https://app.gitbook.com/@thangarajn1992/s/leetcode/v/main/leetcode-medium/leetcode-752-open-the-lock
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define TOTAL_NODES 10000


int openLock(vector<string> deadends, string target);
vector<int> find_neighbors(int value, vector<bool>& visited);

int main() 
{
    int no_of_deadends;
    string target;
    cin >> no_of_deadends;
    vector<string> deadends(no_of_deadends);

    for(int i = 0; i < no_of_deadends; i++)
        cin >> deadends[i];
    cin >> target;

    cout << "No. of Moves to open the Lock is :" << openLock(deadends, target) << endl;
}

int openLock(vector<string> deadends, string target)
{
    vector<bool> visited(TOTAL_NODES, false);
    vector<int> distance(TOTAL_NODES, 0);

    for(int i = 0; i < deadends.size(); i++)
        visited[stoi(deadends[i])] = true;;
        
    if(visited[0])
        return -1;
        
    int search_for = stoi(target);       
    queue<int> q;
        
    q.push(0);        
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == search_for)
            return distance[cur];
        if(visited[cur])
            continue;
        visited[cur] = true;
        int k = distance[cur];
        vector<int> neighbor = find_neighbors(cur, visited);
        for(int i = 0; i < neighbor.size(); i++)
        {
            distance[neighbor[i]] = k+1;
            q.push(neighbor[i]);
        }
    }
    return -1;
}

vector<int> find_neighbors(int value, vector<bool>& visited)
{
    vector<int> next_digit = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> prev_digit = {9, 0, 1, 2, 3 ,4, 5 ,6, 7, 8};
    vector<int> neighbors; 
    int divisor = 1000;
    int temp = value;
        
    while(divisor)
    {
        int digit = temp / divisor;
        int curr = (next_digit[digit]*divisor) + (value - digit*divisor);
        if(!visited[curr]) 
            neighbors.push_back(curr);
            
        curr = (prev_digit[digit]*divisor) + (value - digit*divisor);
        if(!visited[curr])
            neighbors.push_back(curr);
            
        temp = temp % divisor;
        divisor /= 10;
    }
    return neighbors;
}   

/* 
-----------
Testcase 1
-----------
5
0201
0101
0102
1212
2002
0202

Output : 6

-----------
Testcase 2
-----------
8
8887 8889 8878 8898 8788 8988 7888 9888
8888

Output : -1
*/
