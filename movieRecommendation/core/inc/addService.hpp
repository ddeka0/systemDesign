#pragma once
#include "movieCatalog.hpp"
#include "userManager.hpp"

namespace core {
    class AddService {
        public:
            AddService();
            AddService(MovieCatalog* movieCatalg,UserManager* userManager);
            void addUser(std::string name);
            void delUser(std::string name);
            void addMovie(std::string name,std::string genre,int year);
            void delMovie(std::string name,std::string genre,int year);
        private:
            MovieCatalog* m_movieCatalg;
            UserManager* m_userManager;
    };
}

