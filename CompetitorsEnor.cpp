#include "Competitors.h"
#include <sstream>
#include <iostream>
using namespace std;
CompetitorsEnor::CompetitorsEnor(const std::string &name) throw (FILEERROR){
f.open(name);
if(f.fail()){
    throw MissingFileInput;
}
}

void CompetitorsEnor::next(){
std::string line;
getline(f,line);
std::string fishname;
int size;
if(!f.fail() && line != ""){
sx = norm;
std::stringstream ss(line);
ss >>  dx.competitor >> dx.competitionID;
dx.count_of_catfishes = 0;
int i = 0;
ss >> fishname >> size;
while(!ss.fail()){
     if(fishname == "catfish"){
       dx.count_of_catfishes++;
     }
     ss >> fishname >> size;
}

}
else{
    sx = abnorm;
}

}


