### Movie Recommend System

##### [Project Under Development]

##### How to Run ?
    1. cd movieRecommendation
    2. cmake .
    3. make
    4. ./build/bin/movieRecommend

##### Next TODO:
    1. Add Class diagram for all the modules
    2. Improve design

##### How to improve design
    
    1. Reduce logical dependency
        => User proper design pattern
    
        => Just an example, we can use facade to have a uniform API across all module
        handlers, like, movieCatalog,UserManager,ReviewService,etc.
        => Basically we need to remove coupling
        by following SRP and OPEN CLOSE principle

        **check SRP principle in depth with examples
        **check open close principle in depth with examples

        ** for example, think of a situation where we want to change the algorithm to get topmovie list.

    2. Reduce physical dependency
        
        => remove build dependency by using pimpl or similar strategy


    3. Refine APIs if required, think how user can exploit or misuse the API which might lead to problem in our syste.
     APIs should be easy to use and hard to misuse.


    4. Handle Errors (all possible). Exception cases. Need to know (real cases) how exceptions are handles. 
    Does all sustems needs exception handling? (Cost of Exception handling ?)

    5. Provide Debug capability for crash and exceptions. Add global debug variables, so that
    gdb core dump can be analysed. 
    Experimental crash of our code and check the crash dump in some open source tools to find the problem.


    6. Provide uniform log functionality
    so that, by debug or release mode build, we can
    turn ON and OFF some logs

    7. Is this design ok ? should the modules talk to each other by messages instead of function calls ?

    7.1 Learn one build susyem very well, so that the concepts can be used across different build system. This project uses cmake.



    
##### Want to add more feature?
    
    7. Add UNIT Test feature
    Use, existing framework to do this.

    8. Learn about proper versioning and how
    versioning is used in production

    9. Performance tune, profile the code using tools like gprofs or Operf, and optimize

    10. What about memory allocation ?
    Create a mechanism to catch all kinds of memory allocation from all modules of our system.
    If required provide our own allocator.

    11. Can we call our APIs from different language ? For example, node js applicaiton calling our C++ APIs for movie Recommendation.
    In real system, this kind of cross language module communiation happens.

    12. Use smart pointers to manage memory.
    In general use Resource Manager class to handle resources. Learn about RAII in C++.

    13. Make it multi-threaded and thread safe.
