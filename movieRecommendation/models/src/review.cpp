#include "review.hpp"
#include <iostream>

namespace model {
    Review::Review() {
        std::cout <<"Review created!" << std::endl;
    }

    Review::Review(std::string userName,std::string movieName,int rating) {
        m_reviewerName = userName;
        m_movieName = movieName;
        m_rating = rating;
        std::cout <<"Review created!" << std::endl;
    }

    std::string Review::getReviewerName() {
        return m_reviewerName;
    }

    std::string Review::getMovieName() {
        return m_movieName;
    }

    int Review::getRating() {
        return m_rating;
    }
}
