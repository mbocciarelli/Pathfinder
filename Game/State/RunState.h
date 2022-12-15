#include "IState.h"
#include "../Scene.hpp"

class RunState : public IState {
public:
private:
    TileType* m_tileType;
public:
    RunState() {
        m_tileType = nullptr;
    }
    ~RunState() override = default;
    IState* handleInput(const Input& input) const override;

};

