#include "movieCatalog.hpp"
#include <iostream>

namespace core {
    MovieCatalog::MovieCatalog() {
        std::cout <<"MovieCatalog created !" << std::endl;
    }

    MovieCatalog::~MovieCatalog() {
        for(auto iter: m_movieList) {
            delete iter;
        }
        m_movieList.clear();
    }

    void MovieCatalog::addMovie(std::string movieName,std::string genre,int year) {
        auto newMovie = new model::Movie();
        newMovie->setName(movieName);
        newMovie->setGenre(genre);
        newMovie->setReleaseYear(year);
        m_movieList.push_back(newMovie);
    }

    model::Movie* MovieCatalog::getMovie(std::string movieName) {
        for(auto movie : m_movieList) {
            if(movie->getName() == movieName) return movie;
        }
        return nullptr;
    }

    std::vector<model::Movie*> MovieCatalog::getMovieListByGenre(std::string genre) {
        std::vector<model::Movie*> res;
        for(auto movie : m_movieList) {
            if(movie->getGenre() == genre) res.push_back(movie);
        }
        return res;
    }

    std::vector<model::Movie*> MovieCatalog::getMovieListByName(std::string name) {
        std::vector<model::Movie*> res;
        for(auto movie : m_movieList) {
            if(movie->getName() == name) res.push_back(movie);
        }
        return res;
    }

    std::vector<model::Movie*> MovieCatalog::getMovieListByReleaseYear(int year) {
        std::vector<model::Movie*> res;
        for(auto&& movie : m_movieList) {
            if(movie->getReleaseYear() == year) res.push_back(movie);
        }
        return res;
    }
}

