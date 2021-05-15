#pragma once
#include <string>
#include <vector>

#include "movieCatalog.hpp"
#include "reviewService.hpp"
#include "userManager.hpp"
#include "addService.hpp"

namespace api {
    class Api {
    public:
        Api();
        ~Api();
        void addUser(std::string name);
        void addMovie(std::string movieName,std::string genre,int year);
        void addReview(std::string reviewerName,std::string movieName,int rating);
        std::vector<std::string> getTopMoviesByYear(int year,std::string typeOfReviewer,int howMany);
        std::vector<std::string> getTopMoviesByGenre(std::string genre,std::string typeOfReviewer,int howMany);
        int getAverageByYear(int year);
        int getAverageByGenre(std::string genre);
    private:
        core::MovieCatalog* m_movieCatalog;
        core::ReviewService* m_reviewService;
        core::AddService* m_AddService;
        core::UserManager* m_userManager;
    };
}



