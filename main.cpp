#include <iostream>
#include <ctime>


int main(int argc, char *argv[]){

    if(argc < 4){
        std::cout<<"Usage: "<<argv[0]<<" <hours> <minutes> <seconds> <command for timeout>"<<std::endl;
        std::exit(0);
    }
    time_t t;
    auto time1 = std::time(&t);
    auto time2 = std::time(&t);
    auto hours = std::atoi(argv[1])*3600;
    auto minutes = std::atoi(argv[2])*60;
    auto seconds = std::atoi(argv[3]);
    auto userTime = hours + minutes + seconds;
    auto timerTime = time2 - time1;
    auto deltaTime = timerTime - 1;

    while(timerTime < userTime){
        time2 = std::time(&t);
        timerTime = time2 - time1;
        auto remaring = userTime - timerTime;
        if(deltaTime != timerTime){
            std::cout<<remaring<<std::endl;
            deltaTime = timerTime;
        }
    }

    std::cout<<"Running: "<<argv[4]<<"..."<<std::endl;;
    system(argv[4]);

    return 0;
}