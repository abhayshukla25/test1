#include<bits/stdc++.h>
using namespace std;

class Node
{
 public:
 int key;
 Node *par;
 bool is_locked;
 int count_desc;
 int count_wait_desc;
 vector<Node *> child;
 Node(int k)
 {
   key=k;
   is_locked=false;
   count_desc=0;
 }
};

class Tree_utility
{ 
 public:
 void createNode(int, Node*);
 bool lock(Node*);
 bool unlock(Node*);
 void wait(Node *);
 void signal(Node *);
};
void Tree_utility::wait(Node *node)
{
  Node * p=node->par;
  while(p!=NULL)
  {  
    p->count_wait_desc++;
    p=p->par;
  }
}
void Tree_utility::signal(Node *node)
{
  Node * p=node->par;
  while(p!=NULL)
  {  
    p->count_wait_desc--;
    p=p->par;
  }
}
void Tree_utility::createNode(int key, Node *parent)
{
  Node * node = new Node(key);
  node->par=parent;
  parent->child.push_back(node);
}

bool Tree_utility::lock(Node *node)
{ 
  if(node==NULL)
  return false;
  if(node->count_desc>0)
  return false;
  if(node->is_locked)
  return true;
  
   //check for ancestor
  wait(node);
  while(node->count_wait_desc);
  Node * p=node->par;
  while(p!=NULL)
  {  
    if(p->is_locked)
    {
    signal(node);
    return false;
    }
    p=p->par;
  }
  
  node->is_locked=true;
  
   //increment count_desc by 1 for all its ancestors
  p=node->par;
  while(p!=NULL)
  {
    p->count_desc++;
    p=p->par;
  }
  signal(node);
  return true;
}

bool Tree_utility::unlock(Node *node)
{  
  if(node==NULL)
  return false;
  if(!node->is_locked)
  return true;
  
   node->is_locked = false;
   
   //decrement count_desc by 1 for all its ancestors
   Node *p = node->par;
   while(p!=NULL)
   {
    p->count_desc--;
    p=p->par;
   }
   return true;
}
