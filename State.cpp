//
// Created by david on 1/8/19.
//

#include "State.h"

State::State(string state) // CTOR
{
    this.state = state;
}

bool State::Equals(object obj)
{
    return state.Equals((obj as State).state);
}
