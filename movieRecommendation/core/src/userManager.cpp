#include "userManager.hpp"
#include <iostream>

namespace core {
    UserManager::UserManager() {
        std::cout <<"UserManager created!" << std::endl;
    }
    UserManager::~UserManager() {
        for(auto user : m_userDb) {
            delete user;
        }
        m_userDb.clear();
    }

    void UserManager::addUser(std::string name) {
        auto newUser = new model::User(name);
        m_userDb.push_back(newUser);
    }

    void UserManager::delUser(std::string name) {
        std::cout <<"Warning ! Feature not supported!" << std::endl;
    }

    model::User* UserManager::getUser(std::string name) {
        for(auto&& user: m_userDb) {
            if(user->getName() == name) return user;
        }
        std::cout <<"Warning ! User not found!" <<std::endl;
        return nullptr;
    }
}