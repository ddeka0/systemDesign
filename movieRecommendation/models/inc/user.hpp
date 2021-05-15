#pragma once
#include <string>

namespace model {
    class User {
        public:
            User();
            User(std::string name);
            std::string getName();
            int getLevel();
            void setName(std::string name);
            void setLevel(int newLevel);
        private:
            std::string m_name;
            int m_level;
    };
}


