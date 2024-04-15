#include <iostream>
#include <queue>
using namespace std;

class node{
  public:
    int data;
    node* left;
    node* right;

    node(int data){
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }    
};

node* buildTree(node* root){
  cout<<"Enter the data: "<<endl;
  int data;
  cin >> data;
  root = new node(data);

  if(data == -1){
    return NULL;
  }
  cout<<"Enter data for inserting at left "<<data<<endl;
  root->left = buildTree(root->left);
  cout<<"Enter data for inserting at right "<<data<<endl;
  root->right = buildTree(root->right);

  return root;
}

void levelOrderTraversal(node* root){
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  
  while(!q.empty()){
    node* temp = q.front();
    
    q.pop();
    if(temp == NULL){
      cout<<endl; // level kahatam
      if(!q.empty()){  // queue mein bhi kuch hai
        q.push(NULL);
      }
    }
    else{
      cout<<temp->data<<" ";
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }
    }
  }
}

void inOrder(node* root){
  // base case
  if(root == NULL){
    return;
  }

  // L, N, R
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void preOrder(node* root){
  // base case
  if(root == NULL){
    return;
  }

  // N, L, R
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(node* root){
  // base case
  if(root == NULL){
    return;
  }

  // L, R, N
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root){
  queue<node*> q;
  cout<<"Enter data for root"<<endl;
  int data;
  cin>>data;
  root = new node(data);
  q.push(root);

  while(!q.empty()){
    node* temp = q.front();
    q.pop();
    cout<<"Enter left node for: "<<temp->data<<endl;
    int leftData;
    cin>>leftData;

    if(leftData != -1){
      temp->left = new node(leftData);
      q.push(temp->left);
    }
    cout<<"Enter right node for: "<<temp->data<<endl;
    int rightData;
    cin>>rightData;

    if(rightData != -1){
      temp->right = new node(rightData);
      q.push(temp->right);
    }
  }
}

int main() {
  node* root = NULL;

  buildFromLevelOrder(root);
  levelOrderTraversal(root);

  /*
  // creating a tree
  root = buildTree(root);
  //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

  // level order traversal
  cout<<"Printing the level order traversal output"<<endl;
  levelOrderTraversal(root);

  // inorder traversal
  cout<<"Printing the inorder traversal output"<<endl;
  inOrder(root);

  // preorder traversal
  cout<<"Printing the preorder traversal output"<<endl;
  preOrder(root);

  // postorder traversal
  cout<<"Printing the postorder traversal output"<<endl;
  postOrder(root);    */
}