#include "IState.h"

class RunState : public IState {
public:
    RunState() = default;
    ~RunState() override = default;

    IState* handleInput(Scene& Scene, const Input& input) const override;
};

