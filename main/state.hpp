//state.hpp

#ifndef STATE_HPP
#define STATE_HPP

#include <string>

enum class State {
    Idle,
    Running,
    Charging,
    Error
  };

inline std::string get_state(State state) {
    switch (state) {
        case State::Idle: return "Idle";
        case State::Running: return "Running";
        case State::Charging: return "Charging";
        case State::Error: return "Error";
        default:           return "Unknown";
      }
  }

#endif // STATE_HPP
