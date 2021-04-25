#ifndef ANGLER_H_INCLUDED
#define ANGLER_H_INCLUDED
#include <string>
#include "Competitors.h"
struct Angler {
   std::string competitor;
    bool catfish_lover;
};


class AnglerEnor{
    private:
        CompetitorsEnor _tt;
        Angler _cur;
        bool _end;
    public:
        AnglerEnor(const std::string &str): _tt(str) { }
        void first() { _tt.first(); next(); }
        void next();
        Angler current() const { return _cur; }
        bool end() const { return _end; }
};


#endif // ANGLER_H_INCLUDED
