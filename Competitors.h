#ifndef COMPETITORS_H_INCLUDED
#define COMPETITORS_H_INCLUDED
#include <string>
#include <fstream>
#include <string>
#include <vector>
/*struct fishs{
std::vector<std::string>fishname;
std::vector<int> size;
};*/
struct competitors{
std::string competitor;
std::string competitionID;
int count_of_catfishes;
};


class CompetitorsEnor{
    public:
    enum Status{norm,abnorm};
    enum FILEERROR{MissingFileInput};
CompetitorsEnor(const std::string &name) throw (FILEERROR);
void first(){next();}
void next();
competitors current() const {return dx;}
bool end() const{return (sx == abnorm); }
private:
     std::ifstream f;
    competitors dx;
    Status sx;




};


#endif // COMPETITORS_H_INCLUDED
