/*
#include <vector>

enum NodeType {
    Start, Wall, End, Ground
};

template<typename T>
class Node {
public:

    using NodeSource = Node<T>;

    NodeSource* parent = nullptr;
    int x, y = 0;
    int G = 0;
    int H = -1;
    int W = H + G;
    std::vector<NodeSource*> vecNeighbours;
    bool visited = false;
    int finalWayID = -1;
    

    Node(int x, int y, NodeType type) :x(x), y(y), mType(type) {};
    ~Node() = default;
    int getDistanceG() { return G; };
    int getHeuristic() { return H; };
    int getWeight() { return W; };
    void setNodeType(NodeType Type) { mType = Type; };
    void setParent(NodeSource* nodeparent) { parent = nodeparent; };
    NodeSource& getParent() { return *parent; };
    NodeType mType;
    //A remplacer par vector2
    int getX() { return xNode; };
    int getY() { return yNode; };

    bool Equals(Node* _n) {
        return _n->y == y && _n->x == x;
    }
};

*/

#pragma once
class Node
{
public:
    int column;
    int line;
    int type;
    int heuristic;
    int cost;

    Node* parent;

    bool visited = false;
    int finalWayID = -1;

    Node(): column(0),line(0),type(0),heuristic(-1),cost(0){};
    Node(int _column, int _line, int _type) :column(_column),line(_line),type(_type){};
    ~Node();

    bool Equals(Node* _n) {
        return _n->column == column && _n->line == line;
    }
};