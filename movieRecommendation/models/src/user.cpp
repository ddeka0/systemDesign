#include "user.hpp"
#include "utility.hpp"
#include <iostream>

namespace model {

    User::User() {
        std::cout <<"User created!" << std::endl;
    }

    User::User(std::string name) {
        m_name = name;
        m_level = ViewerLevel;
        std::cout <<"User created!" << std::endl;
    }

    std::string User::getName() {
        return m_name;
    }

    int User::getLevel() {
        return m_level;
    }

    void User::setName(std::string name) {
        m_name = name;
    }

    void User::setLevel(int newLevel) {
        m_level = newLevel;
    }
}
