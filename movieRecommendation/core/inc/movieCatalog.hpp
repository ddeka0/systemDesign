#pragma once
#include "user.hpp"
#include "movie.hpp"
#include <vector>

namespace core {
    class MovieCatalog {
        public:
            MovieCatalog();
            ~MovieCatalog();
            void addMovie(std::string movieName,std::string genre,int year);
            model::Movie* getMovie(std::string movieName);
            std::vector<model::Movie*> getMovieListByGenre(std::string genre);
            std::vector<model::Movie*> getMovieListByName(std::string name);
            std::vector<model::Movie*> getMovieListByReleaseYear(int year);
        private:
            std::vector<model::Movie*> m_movieList;
    };
}
