#pragma once

class PortalNode : public Node {
public:
    PortalNode() :
        Node()
    {
        this->cost = 0;
    };

    PortalNode(int _column, int _line, int _type) : 
        Node(_column, _line, _type) 
    {};
    ~PortalNode() = default;

    void SetDestination(PortalNode* node) {
        destination = node;
    }

    std::vector<Node*> GetNeighbours() const override {
        return destination->neighbours;
    }

private:
	PortalNode* destination;
};