#include "IState.h"
#include "Scene.hpp"

class WallState : public IState {
public:
    WallState() = default;
    ~WallState() override = default;

    IState* handleInput(Scene& Scene, const Input& input) const override;
};
