#include "Binary_Search_Tree.h"

using namespace std;

vector<int> 
BinarySearchTree::BSTPostorderFromPreorder(vector<int> &pre)
{
    vector<int> postorder;
    int preIndex = 0;

    BSTPostorderFromPreorderUtil(pre, preIndex, INT_MIN, INT_MAX, postorder);
    return postorder;
}
    
void 
BinarySearchTree::BSTPostorderFromPreorderUtil(vector<int> &pre, int &preIndex,
                                               int rangeStart, int rangeEnd, vector<int> &post)
{
    if(preIndex == pre.size())
        return;
        
    if(pre[preIndex] < rangeStart || pre[preIndex] > rangeEnd)
        return;
        
    int key = pre[preIndex];
    preIndex++;

    BSTPostorderFromPreorderUtil(pre, preIndex, rangeStart, key, post);
    BSTPostorderFromPreorderUtil(pre, preIndex, key, rangeEnd, post);
    post.push_back(key);
}