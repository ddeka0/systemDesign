#pragma once
#include <string>
#include "user.hpp"
#include "movie.hpp"

namespace model {
    class Review {
        public:
            Review();
            Review(std::string userName,std::string movieName,int rating);
            std::string getReviewerName();
            std::string getMovieName();
            int getRating();
        private:
            std::string m_reviewerName;
            std::string m_movieName;
            int m_rating;
    };
}