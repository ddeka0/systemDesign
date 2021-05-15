#pragma once
#include <user.hpp>
#include <vector>

namespace core {
    class UserManager {
        public:
            UserManager();
            ~UserManager();
            void addUser(std::string name);
            void delUser(std::string name);
            model::User* getUser(std::string name);
        private:
            std::vector<model::User*> m_userDb;
    };
}