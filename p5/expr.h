class Expr
{
    public:
        Expr(int value);
        Expr(double value);
        Expr(string value);
        Expr(Operator_type type, Expr *newlhs, Expr *newrhs) // for the operators
        Expr(Operator_type type, Expr *newlhs);
        Expr(Variable* value);
        int eval_int();
        double eval_double();
        string eval_string();
        
    private:
        string type;
        string kind;
        Expr* lhs;
        Expr* rhs;
}
