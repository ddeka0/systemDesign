#include "reviewService.hpp"
#include <iostream>

namespace core {
    
    ReviewService::ReviewService() {
        std::cout <<"ReviewService Created!" << std::endl;
    }
    ReviewService::ReviewService(MovieCatalog* movieCatalog) {
        m_movieCatalog = movieCatalog;
        std::cout <<"ReviewService Created!" << std::endl;
    }
    ReviewService::~ReviewService() {
        for(auto&& item : m_movieReview) {
            for(auto && review : item.second) {
                delete review;
            }
            item.second.clear();
        }
        m_movieReview.clear();
    }


    void ReviewService::addReview(model::User* reviewer,model::Movie* movie,int rating) {
        auto newReview = new model::Review(reviewer->getName(),movie->getName(),rating);
        m_movieReview[movie->getName()].push_back(newReview);
        updateLevel(reviewer);
    }

    std::vector<model::Movie*> ReviewService::getTopMovies(int year, std::string genre,int userLevel,int howMany) {
        // check of howmany : do it in the API handler itself
        if(howMany <= 0 ||(year == 0 && genre.empty()) || (year > 0 && !genre.empty())) 
            return std::vector<model::Movie*>{};

        std::vector<model::Movie*> l = m_movieCatalog->getMovieListByReleaseYear(year);
        
        if(year)  l = m_movieCatalog->getMovieListByReleaseYear(year);
        else l = m_movieCatalog->getMovieListByGenre(genre);
        
        return l;

        // int need = howMany;
        // int got = 0;


        // while(got < need) {
        //     // find the next best





        // }

    }
    int ReviewService::getAverageReviewScore(int year,std::string genre) {
        return 5;
        // TODO implement
    }

    void ReviewService::updateLevel(model::User* reviewer) {
        // implement policy here for user update or upgrade
        // currently policies are handcoded here
        auto userRef = m_userContext.find(reviewer->getName());
        if(userRef != m_userContext.end()) {
            userRef->second.noOfReviews += 1;
            if(userRef->second.noOfReviews >= 3) {
                userRef->second.currLevel++;
                reviewer->setLevel(userRef->second.currLevel);
            }
            return;
        }

        m_userContext[reviewer->getName()].currLevel = reviewer->getLevel();
        m_userContext[reviewer->getName()].noOfReviews = 1;
    
    }
}