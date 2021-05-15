#include "movie.hpp"
#include <iostream>

namespace model {

    Movie::Movie() {
        std::cout <<"Movie created!" << std::endl;
    }

    std::string Movie::getName() {
        return m_name;
    }

    std::string Movie::getGenre() {
        return m_genre;
    }

    int Movie::getReleaseYear() {
        return m_releaseYear;
    }

    void Movie::setName(std::string name) {
        m_name = name;
    }

    void Movie::setGenre(std::string genre) {
        m_genre = genre;
    }

    void Movie::setReleaseYear(int year) {
        m_releaseYear = year;
    }

}