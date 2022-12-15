
#include <SFML/Window/Keyboard.hpp>
#include "IState.h"

class EndState : public IState {
public:
    EndState()
    {
        m_tileType = TileType::End;
    }
    ~EndState() override = default;

    IState* handleInput(IState* currentState, const sf::Keyboard::Key& input) const override;
};