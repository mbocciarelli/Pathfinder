#include "IState.h"
#include "../Scene.hpp"

class RunState : public IState {
public:
    IState* handleInput(const Input& input) const override;

    void UpdateTile(Tile& tile) const override;
};

