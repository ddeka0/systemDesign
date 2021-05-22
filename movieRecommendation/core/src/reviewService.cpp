#include "reviewService.hpp"
#include <iostream>
#include <algorithm>

using namespace model;
namespace core {
    const int nReviewsOnLevel[3] = {3,6,9};
    ReviewService::ReviewService() {
        std::cout <<"ReviewService Created!" << std::endl;
    }
    ReviewService::ReviewService(MovieCatalog* movieCatalog,UserManager* userManager) {
        m_movieCatalog = movieCatalog;
        m_userManager = userManager;
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
        if(reviewer == nullptr || movie == nullptr) return;
        
        auto found = m_movieReview.find(movie->getName());
        
        // TODO optimize
        if(found != m_movieReview.end()) {
            auto&& reviewList = found->second;
            for(auto && review : reviewList) {
                if(review->getReviewerName() == reviewer->getName()) {
                    std::cout <<reviewer->getName() <<" has already reviewd movie : "<<movie->getName() << std::endl;
                    return;
                }
            }
        }

        auto newReview = new model::Review(reviewer->getName(),movie->getName(),rating);
        m_movieReview[movie->getName()].push_back(newReview);
        updateLevel(reviewer);
    }

    std::vector<model::Movie*> ReviewService::getTopMovies(int year, std::string genre,int userLevel,int howMany) {
        // check of howmany : do it in the API handler itself
        if(howMany <= 0 ||(year == 0 && genre.empty()) || (year > 0 && !genre.empty())) 
            return std::vector<model::Movie*>{};

        std::vector<model::Movie*> l;

        if(year)  l = m_movieCatalog->getMovieListByReleaseYear(year);
        else l = m_movieCatalog->getMovieListByGenre(genre);
        
        // we can do insertion sort type method also, but for now just sort it

        std::sort(l.begin(),l.end(),[this,userLevel](model::Movie* x, model::Movie* y) {
            // this lambda is bery expensive at this point
            auto&& reviewListX = this->m_movieReview[x->getName()];
            auto&& reviewListY = this->m_movieReview[y->getName()];
            int XScore = 0,YScore = 0;
            for(auto&& review : reviewListX) {
                auto&& user = this->m_userManager->getUser(review->getReviewerName());
                if(user->getLevel() == userLevel) {
                    XScore++;
                }
            }

            for(auto&& review : reviewListY) {
                auto&& user = this->m_userManager->getUser(review->getReviewerName());
                if(user->getLevel() == userLevel) {
                    YScore++;
                }
            }
            return XScore < YScore;
        });

        std::vector<model::Movie*> ans;

        for(unsigned int i = 0;i<std::min((size_t)howMany,l.size());i++) {
            ans.push_back(l[i]);
        }

        return ans;
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
            if(userRef->second.noOfReviews >= nReviewsOnLevel[userRef->second.currLevel]) {
                userRef->second.currLevel++;
                std::cout << reviewer->getName() <<" is upgraded to "<<userRef->second.currLevel<<std::endl;
                reviewer->setLevel(userRef->second.currLevel);
            }
            return;
        }

        m_userContext[reviewer->getName()].currLevel = reviewer->getLevel();
        m_userContext[reviewer->getName()].noOfReviews = 1;
    
    }
}