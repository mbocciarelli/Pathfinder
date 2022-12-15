#include <list>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

/*
template<typename World>
class Graph {
private:
    std::list<World> GraphToPathfind;
public:
   Graph(std::list<World> Graph):GraphToPathfind(Graph){};
};
*/

enum class NodeType
{
    Start, Target, Path, Obstacle, None
};


template<typename T>
class Node {
private:
    //A remplacer par vector2
    Node* parent = nullptr;
    T xPosition, yPosition = 0;
    T G = 0;
    T H = 0;
    T F = H + G;
    std::vector<Node*> vecNeighbours;
    NodeType mNodeType;

public:
    Node(const sf::Vector2i& Position, T Heuristic, T DistanceG) :xNode(Position.x), yNode(Position.y), G(0), H(0) {};
    ~Node() = default;
    bool isWall();
    T getDistanceG() { return G; };
    T getHeuristic() { return H; };
    T getWeight() { return F; };
    void setParent(Node* nodeparent) { parent = nodeparent; };
    Node* getParent() { return *parent; };
    //A remplacer par vector2
    T getX() { return xNode; };
    T getY() { return yNode; };
    void setType(NodeType nodetype) { mNodeType = nodetype; };
    NodeType getType() { return NodeType };
};





class AstarSearch {
private:
    std::list<Node> openList;
    std::list<Node> closeList;

public:
    AstarSearch() {};
    ~AstarSearch() = default;
    void addNodeToOpenList() {};
    void addNodeToCloseList() {};
};