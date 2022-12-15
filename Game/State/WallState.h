#include "IState.h"
#include "../Scene.hpp"

class WallState : public IState {
private:
    TileType* m_tileType;
public:
    WallState() {
        m_tileType = new TileType(TileType::Wall);
    }
    ~WallState() override = default;

    IState* handleInput(const Input& input) const override;

};
