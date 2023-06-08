/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(root == NULL)
    return ans;
   queue <Node*> st;
   st.push(root);
   while(!st.empty())
   {
       int n = st.size();
       for(int i = 0; i < n; i++)
       {
           Node * curr = st.front();
           st.pop();
           if(i == 0)
                ans.push_back(curr->data);
           if(curr->left!= NULL)
                st.push(curr->left);
           if(curr->right!= NULL)
                st.push(curr->right);
       }
   }
   return ans;
}
