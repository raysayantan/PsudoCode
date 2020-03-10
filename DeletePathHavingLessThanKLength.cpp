/*
Consider the following example Binary Tree

               1
           /      \
         2          3
      /     \         \
    4         5        6
  /                   /
 7                   8 
Input: Root of above Binary Tree
       k = 4

Output: The tree should be changed to following  
           1
        /     \
      2          3
     /             \
   4                 6
 /                  /
7                  8
*/
struct TREE{
  int data;
  struct Tree *left;
  struct Tree *right;
};

TREE* trucTree(Tree *root, int nodeCnt, int k){
    if(root == NULL) return NULL;
    if(nodeCnt >= k) return root;
    if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
    }
    
    if(root->left){
        root->left = trucTree(root->left, nodeCnt+1);
    }
    
    if(root->right){
        root->right = trucTree(root->right, nodeCnt+1);
    }
}
