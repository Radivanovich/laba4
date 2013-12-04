#ifndef TREE_H
#define TREE_H

struct Node;

class Set
{
private:
    class Tree;
    Tree *pimpl;
    Set(const Tree &other);
public:
    Set();
    Set(int t);
    ~Set();
    void push(int data);
    void show();
    int quantity() const;
    bool is_empty();
    bool check(int key);
    Set& operator = (const Set &ob);
    void nextDatum(int *datum) const;
    void nextDatum_right(int *datum) const;
};

#endif // TREE_H
