#include "publicApi.hpp"
#include <iostream>
#include <map>
#include "utility.hpp"

namespace api {
    std::map<std::string,int> Map = {
        {"viewer",ViewerLevel},
        {"critic",CriticLevel}
    };
    Api::Api() {
        m_movieCatalog = new core::MovieCatalog();
        m_userManager = new core::UserManager();
        m_AddService = new core::AddService(m_movieCatalog,m_userManager);
        m_reviewService = new core::ReviewService();
    }
    Api::~Api() {
        delete m_movieCatalog; m_movieCatalog = nullptr;
        delete m_userManager; m_userManager = nullptr;
        delete m_AddService; m_AddService = nullptr;
        delete m_reviewService; m_reviewService = nullptr;
    }

    void Api::addUser(std::string name) {
        m_userManager->addUser(name);
    }

    void Api::addReview(std::string reviewerName,std::string movieName,int rating) {
        auto user = m_userManager->getUser(reviewerName);
        auto movie = m_movieCatalog->getMovie(movieName);
        if(user != nullptr && movie != nullptr) {
            m_reviewService->addReview(user,movie,rating);
            return;   
        }
        std::cout <<"Error ! No user or movie found!" << std::endl;
    }

    void Api::addMovie(std::string movieName,std::string genre,int year) {
        auto movie = m_movieCatalog->getMovie(movieName);
        if(movie == nullptr) {
            m_movieCatalog->addMovie(movieName,genre,year);
        }
        std::cout <<"Error ! Movie already exists!" << std::endl;
    }
    
    std::vector<std::string> Api::getTopMoviesByYear(int year,std::string typeOfReviewer,int howMany) {
        if(Map.find(typeOfReviewer) != Map.end()) {
            auto listOfMovies = m_reviewService->getTopMovies(year,"",Map[typeOfReviewer],howMany);
            std::vector<std::string> reply;
            for(auto&& movie : listOfMovies) {
                reply.push_back(movie->getName());
            }
            return reply;
        }
        std::cout <<"Error ! Type of user is not known!" << std::endl;
    }

    std::vector<std::string> Api::getTopMoviesByGenre(std::string genre,std::string typeOfReviewer,int howMany) {
         if(Map.find(typeOfReviewer) != Map.end()) {
            auto listOfMovies = m_reviewService->getTopMovies(0,genre,Map[typeOfReviewer],howMany);
            std::vector<std::string> reply;
            for(auto&& movie : listOfMovies) {
                reply.push_back(movie->getName());
            }
            return reply;
        }
        std::cout <<"Error ! Type of user is not known!" << std::endl;       
    }

    int Api::getAverageByYear(int year) {
        return m_reviewService->getAverageReviewScore(year,"");
    }

    int Api::getAverageByGenre(std::string genre) {
        return m_reviewService->getAverageReviewScore(0,genre);
    }

}

