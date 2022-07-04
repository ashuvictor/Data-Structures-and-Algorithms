



class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDistance(Node* root,int val,int level){
        if(root==NULL)
        return -1;
        if(root->data==val)
        return level;
        int left=findDistance(root->left,val,level+1);
        if(left==-1)
        {
            int right=findDistance(root->right,val,level+1);
            return right;
        }
        return left;
    }
    Node* lca(Node* root,int a,int b){
        if(root==NULL or root->data==a or root->data==b)
        return root;
        Node* l=lca(root->left,a,b);
        Node* r=lca(root->right,a,b);
        if(l==NULL)
        return r;
        else if(r==NULL)
        return l;
        else
        return root;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lc=lca(root,a,b);
        int x=findDistance(lc,a,0);
        int y=findDistance(lc,b,0);
        return x+y;
        
    }
};
