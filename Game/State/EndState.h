
#include "IState.h"
#include "../Scene.hpp"

class EndState : public IState {
public:
    EndState() = default;
    ~EndState() override = default;

    IState* handleInput(const Input& input) const override;

    void UpdateTile(Tile& tile) const override;

};