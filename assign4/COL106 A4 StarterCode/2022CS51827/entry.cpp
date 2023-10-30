/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "entry.h"

SymEntry::SymEntry(){
    left = NULL;
    right = NULL;
    key = "";
    val = new UnlimitedRational();
};
SymEntry::SymEntry(string k, UnlimitedRational* v){
    left = NULL;
    right = NULL;
    key = k;
    val = new UnlimitedRational(v->get_p(), v->get_q());
};

SymEntry::~SymEntry(){
    left = NULL;
    right = NULL;
    key = "";
    delete val;
};