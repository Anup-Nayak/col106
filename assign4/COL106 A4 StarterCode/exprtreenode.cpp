/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

ExprTreeNode::ExprTreeNode(){
    type = "";
    val = new UnlimitedRational();
    evaluated_value = new UnlimitedRational();
    id = "";
    left = NULL;
    right = NULL;
};

ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v){
    type = t;
    if (t == "VAR" || t == "VAL")
    {
        UnlimitedInt *one = new UnlimitedInt(1);
        val = new UnlimitedRational(v, one);
        evaluated_value = val; // temp
        id = t;
    }
    left = NULL;
    right = NULL;
};

ExprTreeNode::ExprTreeNode(string t, UnlimitedRational* v){
    type = t;
    left = NULL;
    right = NULL;
    if (t != "VAR" && t != "VAL")
    {
        val = new UnlimitedRational();
        evaluated_value = val;
        id = "";
    }
    else
    {
        val = new UnlimitedRational(v->get_p(), v->get_q());
        evaluated_value = val; // temp
        id = t;
    }
};

ExprTreeNode::~ExprTreeNode(){
    left = NULL;
    right = NULL;
    delete val;
    delete evaluated_value;
};