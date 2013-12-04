#include <iostream>
#include <stdlib.h>
#include "tree.h"

using namespace std;

struct Node
{
    int value;
    Node *left, *right;
    Node(int value): value(value), left(0), right(0) {}
    Node(): value(0), left(0), right(0) {}
    ~Node()
    {
        value = 0;
        left = 0;
        right = 0;
    }
};

class Set::Tree
{
    private:
        Node *root;
        void copy_tree(Node *&root_new, Node *root_old);
        void del_tree(Node *wer);
        void push(Node *&wer, int data);
        int  quantity(Node *root) const;
        bool check(Node *wer, int key);
    public:
        Tree();
        Tree(int t);
        Tree (const Tree &ob);
        ~Tree();
        void push(int data);
        int  quantity() const;
        bool check(int key);
        bool is_empty();
        Tree &operator = (const Tree &ob);
        void nextDatum(int *datum) const;
        void nextDatum_right(int *datum) const;
};

Set &Set::operator= (const Set &ob)
{
    pimpl->operator=(*ob.pimpl);
    return *this;
}

Set::Set(const Tree &other)
{
    pimpl=new Tree(other);
}

bool Set:: check(int key)
{
    return pimpl->check(key);
}

void Set::push(int data)
{
    pimpl->push(data);
}

bool Set::is_empty()
{
    pimpl->is_empty();
    return 0;
}

int Set::quantity() const
{
    return pimpl->quantity();
}

void Set::nextDatum(int *datum) const
{
    return pimpl->nextDatum(datum);
}

void Set::nextDatum_right(int *datum) const
{
    return pimpl->nextDatum_right(datum);
}


Set::Set() : pimpl( new Tree ) {}

Set::Set(int t)
{
    pimpl=new Tree(t);
}

Set::Tree::Tree(int t)
{
    root=0;
    for(int i=0; i<t; i++)
    {
        int k=rand()%100;
        if(check(root, k)==0)
            push(root, k);
        else
            t++;
    }
}

Set::~Set()
{
    delete pimpl;
    pimpl = 0;
}

Set::Tree& Set::Tree::operator=(const Tree &ob)
{
    if(this==&ob)
        return *this;
    del_tree(root);
    copy_tree(root, ob.root);
    return *this;
}

Set::Tree::Tree (const Tree &ob)
{
    if (ob.root==0)
        root=0;
    else
    {
        root=new Node;
        root->value=ob.root->value;
        root->left=0;
        root->right=0;
        copy_tree(root, ob.root);
    }
}

void Set::Tree::copy_tree(Node *&root_new, Node *root_old)
{
    if (root_old->left!=0)
    {
        push(root_new, (root_old->left)->value);
        copy_tree(root_new, root_old->left);
    }
    if (root_old->right!=0)
    {
        push(root_new, (root_old->right)->value);
        copy_tree(root) new, root_old->right);
    }
}
bool Set::Tree::check(int key)
{
    if(root==0)
        return false;
    else
    {
        if(key<root->value)
            return check(root->left,key);
        else
            if(key>root->value)
                return check(root->right,key);
            else
                return true;
    }
}

bool Set::Tree::check(Node *wer, int key)
{
    if(wer==0)
        return false;
    else
        if(key < wer->value)
            return check(wer->left, key);
        else
            if(key > wer->value)
                return check(wer->right, key);
            else
                return true;
}

Set::Tree::Tree()
{
    root=0;
}

Set::Tree::~Tree()
{
    del_tree(root);
}

void Set::Tree::del_tree(Node *wer)
{
    if(wer==0)return;
    else
        if((wer->left==0)&&(wer->right==0))
        {
            if(wer->left!=0)
                del_tree(wer->left);
            if(wer->right!=0)
                del_tree(wer->right);
            delete wer;
        }
}
void Set::Tree::push(Node *&wer, int data)
{
    if(wer==0)
    {
        wer=new Node;
        wer->value=data;
        wer->left=0;
        wer->right=0;
    }
    else
    {
        if(data < wer->value)
            push(wer->left, data);
        else
            if(data > wer->value)
                push(wer->right, data);
    }
}

void Set::Tree::push(int data)
{
    if(root==0)
    {
        root=new Node;
        root->value=data;
        root->left=0;
        root->right=0;
    }
    else
    {
        if(data < root->value)
            push(root->left, data);
        else
            if(data > root->value)
                push(root->right, data);
    }
}

bool Set::Tree::is_empty()
{
    if(root==0)
        return true;
    else
        return false;
}

int Set::Tree::quantity(Node *root) const
{
    if (root==NULL)
        return 0;
    else
        return quantity(root->left) + quantity(root->right)+1;
}

int Set::Tree::quantity() const
{
    return quantity(root);
}

void Set::Tree::nextDatum(int *datum) const
{
    int i=0;
    static Node *cur,*pre;
    cur = root;
    while (cur!=0)
    {
        if(cur->left==0)
        {

            datum[i]=cur->value;
            i++;
            cur=cur->right;
            continue;
        }

        pre = cur->left;
        while (pre->right !=0  && pre->right != cur) pre = pre->right;

        if (pre->right==0)
        {
            pre->right=cur;
            cur=cur->left;
            continue;
        }
        else
        {
            pre->right=0;
            datum[i]=cur->value;
            i++;
            cur=cur->right;
            continue;
        }
    }
}

void Set::Tree::nextDatum_right(int *datum) const
{
    int i=0;
    static Node *cur,*pre;
    cur = root;
    while (cur!=0)
    {
        if(cur->right==0)
        {

            datum[i]=cur->value;
            i++;
            cur=cur->left;
            continue;
        }

        pre = cur->right;
        while (pre->left !=0  && pre->left != cur) pre = pre->left;

        if (pre->left==0)
        {
            pre->left=cur;
            cur=cur->right;
            continue;
        }
        else
        {
            pre->left=0;
            datum[i]=cur->value;
            i++;
            cur=cur->left;
            continue;
        }
    }
}
