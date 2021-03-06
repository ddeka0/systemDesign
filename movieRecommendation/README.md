### Movie Recommend System

##### [Project Under Development]

##### How to Run ?
    1. cd movieRecommendation
    2. cmake .
    3. make
    4. ./build/bin/movieRecommend

##### API Uses:

```cpp
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
```
    
##### Generate Documentation
    1. cd movieRecommendation
    2. doxygen Doxyfile
    3. cd ..
    4. Open index.html from html folder
    5. NOTE : Please change the following in the Doxyfile
        OUTPUT_DIRECTORY       = /home/deka/Academic/systemDesign/docs  >> to something else
        INPUT                  = /home/deka/Academic/systemDesign/movieRecommendation   >> to something else

##### Partial Class Diagram (Using Doxygen, no STL container relations are shown)
![class_diagram](https://github.com/ddeka0/systemDesign/blob/dev/movieRecommendation/api_diagram.png)

#### Internal Details of Classes and Functions

For example lets see, api::Api class and its dependencies.

    1. Logical structure and dependency:

![api_class_diagram](https://github.com/ddeka0/systemDesign/blob/main/movieRecommendation/docs/images/apiClass.png)

    2. Physical structure and dependency:
    
![api_phy_diagram](https://github.com/ddeka0/systemDesign/blob/main/movieRecommendation/docs/images/apiPhy.png)



##### Next TODO:
    1. Add design document
    2. Improve design

##### How to improve design
 
 Overall components in our system:
 
 ![component_system_diagram](https://github.com/ddeka0/systemDesign/blob/main/movieRecommendation/docs/images/total.png)
 
 
    As we can there are multiple components or classes interacting with each other. We can improvde upon
    the logic dependency among components so that we have flexible system, which can be maintained whichout
    loosing much performance. 
    

    1. Reduce logical dependency
        => User proper design pattern
    
        => Just an example, we can use facade to have a uniform API across all module
        handlers, like, movieCatalog,UserManager,ReviewService,etc.
        => Basically we need to remove coupling
        by following SRP and OPEN CLOSE principle

        **check SRP principle in depth with examples
        **check open close principle in depth with examples

        ** for example, think of a situation where we want to change the algorithm to get topmovie list.

Please check current code base:

![build_depend_diagram](https://github.com/ddeka0/systemDesign/blob/main/movieRecommendation/docs/images/buildHierar.png)

Question ? Do you want to build this entire chain of files every time when you change something at model header files ?
=> Probably not!!


    2. Reduce physical dependency
        
        => remove build dependency by using pimpl or similar strategy


    3. Refine APIs if required, think how user can exploit or misuse the API which might lead to problem in our syste.
     APIs should be easy to use and hard to misuse.

Pleae check the following call chain (randomly picked from the codebase):

![call_chain_diagram](https://github.com/ddeka0/systemDesign/blob/main/movieRecommendation/docs/images/callChain.png)

Can we ask us the follwoing questions ?

    a. If one of function creates some error or exceptions how it can be handled ? What caller and callee would do ?
    b. What is our Error and Exception handling strategy ? We can adopt Error codes or exception thowing mechanism.
    
    Good Talk: https://www.youtube.com/watch?v=W6jZKibuJpU&ab_channel=CppConCppCon
    
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
