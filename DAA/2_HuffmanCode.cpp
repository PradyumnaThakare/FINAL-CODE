#include<iostream>
#include<queue>
using namespace std;

//Node 
struct Node{
    char data;
    int freq;
    Node *left;
    Node *right;
    
    Node(char data,int freq){
        this->data=data;
        this->freq=freq;
        left=NULL;
        right=NULL;
    }
};

//Compare
struct Compare{
    bool operator()(Node*a,Node*b){
        return a->freq>b->freq;
    }
};

//print
void printCode(Node*root,string str){
    if(root==NULL){
        return;
    }
    
    if(root->data!='$'){
        cout<<root->data<<" : "<<str<<endl;
    }
    printCode(root->left,str+"0");
    printCode(root->right,str+"1");
}


//humman

void huffmanCode(char data[],int freq[],int size){
    
  priority_queue<Node*,vector<Node*>,Compare>pq;
  
  for(int i=0;i<size;i++){
      Node*temp=new Node(data[i],freq[i]);
      pq.push(temp);
  }
  
  while(pq.size()!=1){
      Node*left=pq.top();
      pq.pop();
      
      Node*right=pq.top();
      pq.pop();
      
      Node*temp=new Node('$',left->freq+right->freq);
      temp->left=left;
      temp->right=right;
      pq.push(temp);
  }
  printCode(pq.top(),"");
}

//main
int main(){
    char data[]={'A', 'B', 'C', 'D'};
    int freq[]={23,12,34,10};
    huffmanCode(data, freq, 4);
	return 0;
}
/*
Huffman Coding :
Time complexity: O(nlogn) where n is the number of unique characters.
If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calls minHeapify(). So, overall complexity is O(nlogn).
*/