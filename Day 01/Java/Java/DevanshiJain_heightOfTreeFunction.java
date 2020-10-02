import java.lang.*;
class Node{
    int data;
    Node left;
    Node right;
    //Constructor
    Node(int x){
        this.data = x;
        right = left = null;
    }
}

//Function to find the height of a binary tree, pass the root node while calling the height function.
int height(Node root){
    if(root==null){
        return 0;
    }
    return (1+Math.max(height(root.right),height(root.left));
}