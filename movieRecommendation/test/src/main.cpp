#include "publicApi.hpp"
#include <iostream>
using namespace api;

int main() {
    
    Api apiInstance;
    
    apiInstance.addMovie("DON","Action",2002);
    apiInstance.addMovie("Tiger","Drama",2008);
    apiInstance.addMovie("Padmaavat","Comedy",2002);
    apiInstance.addMovie("Lunchbox-2","Drama",2002);
    apiInstance.addMovie("Guru","Drama",2002);
    apiInstance.addMovie("Metro","Romance",2006);

    apiInstance.addUser("SRK");
    apiInstance.addUser("Salman");
    apiInstance.addUser("Deepika");

    apiInstance.addReview("SRK","DON",2);
    apiInstance.addReview("SRK","Padmaavat",8);
    apiInstance.addReview("Salman","DON",5);
    apiInstance.addReview("Deepika","DON",9);
    apiInstance.addReview("Deepika","Guru",6);
    apiInstance.addReview("SRK","DON",10);
    apiInstance.addReview("Deepika","Lunchbox",2);
    apiInstance.addReview("SRK","Tiger",5);
    apiInstance.addReview("SRK","Metro",7);

    auto&& ans = apiInstance.getTopMoviesByYear(2002,"viewer",2);

    std::cout <<"[";
    for(auto&& x : ans) {
        std::cout << x <<",";
    }
    std::cout <<"]"<< std::endl;   
}