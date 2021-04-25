#include <iostream>
#include "angler.h"

using namespace std;

void AnglerEnor::next()
{
    if( !(_end = _tt.end()) ){
        _cur.competitor = _tt.current().competitor;
        _cur.catfish_lover = true;
        for( ; !_tt.end() && _tt.current().competitor == _cur.competitor; _tt.next() ){
            _cur.catfish_lover = _cur.catfish_lover && (_tt.current().count_of_catfishes > 0);
        }
    }
}
