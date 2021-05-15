#include "addService.hpp"
#include <iostream>

namespace core {
    AddService::AddService() {
        std::cout <<"Add Service Created!" <<std::endl;
    }

    AddService::AddService(MovieCatalog* movieCatalg,UserManager* userManager) {
        m_userManager = userManager;
        m_movieCatalg = movieCatalg;
        std::cout <<"Add Service Created!" <<std::endl;
    }

    void AddService::addUser(std::string name) {
        m_userManager->addUser(name);
    }

    void AddService::delUser(std::string name) {
        m_userManager->delUser(name);
    }

    void AddService::addMovie(std::string name,std::string genre,int year) {
        m_movieCatalg->addMovie(name,genre,year);
    }

    void AddService::delMovie(std::string name,std::string genre,int year) {
        std::cout <<"Warning ! Feature not supported!" << std::endl;
    }
}
