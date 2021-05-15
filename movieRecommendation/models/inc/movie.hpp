#pragma once
#include <string>

namespace model {
    class Movie {
        public:
            Movie();
            std::string getName();
            std::string getGenre();
            int getReleaseYear();
            void setName(std::string name);
            void setGenre(std::string genre);
            void setReleaseYear(int year);
        private:
            std::string m_name;
            std::string m_genre;
            int m_releaseYear;
    };
}
