#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "user.hpp"
#include "movie.hpp"
#include "review.hpp"
#include "movieCatalog.hpp"

namespace core {
    class ReviewService {
        public:
            ReviewService();
            ~ReviewService();
            ReviewService(MovieCatalog* movieCatalog);
            void addReview(model::User* reviewer,model::Movie* movie,int rating);
            std::vector<model::Movie*> getTopMovies(int year, std::string genre,int userLevel,int howMany);
            int getAverageReviewScore(int year,std::string genre);
        private:
            struct UserCtx {
                int noOfReviews;
                int currLevel;
            };
            void updateLevel(model::User* reviewer);
            MovieCatalog* m_movieCatalog;
            std::unordered_map<std::string,UserCtx> m_userContext;
            std::unordered_map<std::string,std::vector<model::Review*>> m_movieReview;
    };
}