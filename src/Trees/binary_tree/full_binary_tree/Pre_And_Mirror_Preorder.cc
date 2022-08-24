#include "Binary_Tree.h"

using namespace std;

void 
BinaryTree::createFullBTFromPreandMirrorPreorder(vector<int> &pre, vector<int> &preMirror)
{
    int preIndex = 0;
    unordered_map<int,int> preMirrorIndexMap;

    for(int preMirrorIndex = 0; preMirrorIndex < preMirror.size(); preMirrorIndex++)
    {
        preMirrorIndexMap[preMirror[preMirrorIndex]] = preMirrorIndex;
    }

    root = createFullBTFromPreandMirrorPreorderUtil(pre, 
                                                    preMirrorIndexMap,
                                                    preIndex,
                                                    0,
                                                    preMirror.size()-1);
}

BinaryTreeNode* 
BinaryTree::createFullBTFromPreandMirrorPreorderUtil(vector<int> &pre,
                                                             unordered_map<int,int> &preMirrorIndexMap,
                                                             int &preIndex,
                                                             int preMirrorStartIndex,
                                                             int preMirrorEndIndex)
{
    if(preIndex >= pre.size())
        return nullptr;
    
    if(preMirrorStartIndex > preMirrorEndIndex)
        return nullptr;
    
    BinaryTreeNode *node = new BinaryTreeNode(pre[preIndex]);
    preIndex++;

    if(preMirrorStartIndex == preMirrorEndIndex)
        return node;
    
    int preMirrorIndex = preMirrorIndexMap[pre[preIndex]];

    if(preMirrorIndex >= preMirrorStartIndex && preMirrorIndex <= preMirrorEndIndex)
    {
        node->left = createFullBTFromPreandMirrorPreorderUtil(pre, preMirrorIndexMap, preIndex,
                                                              preMirrorIndex, preMirrorEndIndex);

        node->right = createFullBTFromPreandMirrorPreorderUtil(pre, preMirrorIndexMap, preIndex,
                                                               preMirrorStartIndex+1, preMirrorIndex - 1);
    }
    return node;
}