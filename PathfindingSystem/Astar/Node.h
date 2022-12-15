#pragma once
class Node
{
public:
    int column;
    int line;
    int type;
    int heuristic;
    int cost;

    std::vector<Node*> neighbours;

    Node* parent = nullptr;

    bool visited = false;
    int finalWayID = -1;
    Node():
          column(0)
        , line(0)
        , type(0)
        , heuristic(-1)
        , cost(1)
    {};

    Node(int _column, int _line, int _type):column(_column),line(_line),type(_type){};
    ~Node() = default;

    void AddNeighbour(Node* node) {
        neighbours.push_back(node);
    }

    virtual std::vector<Node*> GetNeighbours() const {
        return neighbours;
    }

    bool Equals(Node* _n) {
        return _n->column == column && _n->line == line;
    }
};