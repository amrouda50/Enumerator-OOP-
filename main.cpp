#include <iostream>
#include <string>
#include "competitors.h"
#include "angler.h"
using namespace std;

int first_search(string filename){
competitors example;
CompetitorsEnor file(filename);
int count_output = 0;
file.first();
while(!file.end()){
    if(file.current().count_of_catfishes > 0){
        count_output++;
    }
    file.next();

}
return count_output;
};

bool second_search(const string &filename , string &competitor){
   Angler elem;
    AnglerEnor t(filename);
    bool l = false;
    for(t.first(); !l && !t.end(); t.next()){
        l = t.current().catfish_lover;
        elem = t.current();
    }
    if (l)
        competitor = elem.competitor;
    return l;

}


//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
cout << "Enter The File's Name:" ;
string filename;
cin >> filename;
try{
cout << "First Task" << endl;
cout << first_search(filename) << endl;
}
catch(CompetitorsEnor::FILEERROR a){

cerr << "File does not exist" << endl;
}
cout << "Second Task" << endl;
try{
        string id;
        if(second_search(filename, id))
        {cout << id << " is a";}
        else cout << "There is no";
        cout << " catfish lover angler.\n";
    }catch(CompetitorsEnor::FILEERROR e)
    {
        cerr<<"Can't find the input file:"<<filename<<endl;
    }
return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("first task empty file", "t0.txt") {
    CHECK_FALSE(first_search("t0.txt"));
}

TEST_CASE("first task 1 catfish_catched, true", "t2.txt") {

    CHECK(first_search("t2.txt"));
}

TEST_CASE("first task 1 catfish_catched, false", "t13.txt") {
    CHECK_FALSE(first_search("t13.txt"));
}
TEST_CASE("first task 1 , unavaiable file", "unavaiablefile") {
    CHECK_THROWS(first_search("doesexist.txt"));
}


TEST_CASE("first task multiple anglers, only one of them meet the requirments(first line)", "tt5.txt") {
    CHECK(first_search("tt5.txt") == 1);

}

TEST_CASE("first task 3 lines , only 3rd angler caught a catfish", "tt3.txt") {
    CHECK(first_search("tt3.txt"));
}
TEST_CASE("first task multiple anglers, last one meets the requirements", "tt6.txt") {
    CHECK(first_search("tt6.txt"));
}

TEST_CASE("first task more anglers, no one meets the requirements", "t6.txt") {
    CHECK_FALSE(first_search("t6.txt"));
}

// counting
//first_search function return the count of lines which have catfish
TEST_CASE("no catch to catfish", "t13.txt") {
    CHECK(first_search("t13.txt") == 0);
}
TEST_CASE("ALL catched  are catfish", "t5.txt") {
    CHECK(first_search("t5.txt") == 4);
}

TEST_CASE("more catches", "t3.txt") {

  CHECK(first_search("t3.txt") == 3);
}

// linear search second part

TEST_CASE("empty file", "t0.txt") {
     string name ;
    CHECK_FALSE(second_search("t0.txt", name));
}

TEST_CASE("1 angler", "t2.txt") {
    string name;
    CHECK(second_search("t2.txt", name));
    CHECK(name=="Peter");
}

TEST_CASE("more angler more contests", "t4.txt") {
    string name;
    CHECK(second_search("t4.txt", name));
    CHECK(name == "Peter");
}

TEST_CASE("first angler is catfish lover", "t4.txt") {
    string name;
    CHECK(second_search("t4.txt", name));
    CHECK(name=="Peter");
}

TEST_CASE("last angler is catfishlover", "t5.txt") {
    string name;
    CHECK(second_search("t5.txt", name));
    CHECK(name=="Bob");
}

TEST_CASE("one catfishlover among anglers ", "t4.txt") {
    string name;
    CHECK(second_search("t4.txt", name));
}

TEST_CASE("no catfishlover anglers more contests ", "t6.txt") {
    string name;
    CHECK_FALSE(second_search("tt3.txt", name));
}

TEST_CASE("more skillful anglers more contests ", "t14.txt") {
    string name;
    CHECK(second_search("t14.txt", name));
    CHECK(name=="Peter");
}

// optimistic linear search

TEST_CASE("no contest", "t1.txt") {
    AnglerEnor t("t1.txt");
    t.first();
    CHECK(t.current().catfish_lover);
}

TEST_CASE("1 angler 1 contest", "t2.txt") {
    AnglerEnor t("t2.txt");
    t.first();
    CHECK(t.current().catfish_lover);
}

TEST_CASE("1 angler more contest", "t3.txt") {
    AnglerEnor t("t3.txt");
    t.first();
    CHECK(t.current().catfish_lover);
}

TEST_CASE("1 angler on his first contest is not a catfish lover ", "t12.txt") {
    AnglerEnor t("t12.txt");
    t.first();
    CHECK_FALSE(t.current().catfish_lover);
}

TEST_CASE("there are more skillful anglers", "t7.txt") {
    AnglerEnor t("t7.txt");
    t.first();
    CHECK(t.current().catfish_lover);
}

TEST_CASE("1 angler on his last contest made him a non catfish lover", "t9.txt") {
    AnglerEnor t("t9.txt");
    t.first();
    CHECK_FALSE(t.current().catfish_lover);
}

TEST_CASE("there is a CATFISH LOVER", "t11.txt") {
    AnglerEnor t("t11.txt");
    t.first();
    CHECK(t.current().catfish_lover);
}

TEST_CASE("no CATFISH lOVER", "t10.txt") {
    AnglerEnor t("t10.txt");
    t.first();
    CHECK_FALSE(t.current().catfish_lover);
}




#endif

