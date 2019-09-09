#include <iostream>
#include <string>
#include <vector>
#include <random>

int getRand(){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 0x100);
    return dis(gen);
}

#define ELEM_NUM(a) sizeof((a))/sizeof((a)[0])
#define RAND_FROM(x) (x)[getRand()%ELEM_NUM((x))]

class generator{
public:
    virtual ~generator()=default;
    virtual std::string generate()=0;
};

class table{
private:
    std::string table_name;
    std::vector<std::string> columes;
public:
    table(std::string & tname, std::vector<std::string> & col):
        table_name(tname),columes(col){}
    virtual ~table()= default;
};

const char* transition_type[]={
        "DEFERRED","IMMEDIATE","EXCLUSIVE",
};

const char* if_transition[]={
        "",
        "TRANSACTION"
};

const char* if_save_point[]={
        nullptr,
        "SAVEPOINT"
};

const char* if_to[]={
        "",
        "TO"
};

const char* commit_type[]={
        "COMMIT",
        "END"
};

inline void append_word(std::string & sql, const char* word){
    sql+=word;
    sql+=" ";
}

inline void finish_stmt(std::string & sql){
    sql+=" ; ";
}
class begin_transition_stmt_generator:generator{
public:
    explicit begin_transition_stmt_generator(std::shared_ptr<table> tb):table(std::move(tb)){}
    ~begin_transition_stmt_generator()override = default;
    std::string generate() override {
        return nullptr;
    }
    std::string generate_begin_stmt(){
        std::string sql;
        append_word(sql,"begin");
        append_word(sql,RAND_FROM(transition_type));
        append_word(sql,RAND_FROM(if_transition));
        finish_stmt(sql);
        return sql;
    }

    std::string generate_commit_stmt(){
        std::string sql;
        append_word(sql,RAND_FROM(commit_type));
        append_word(sql,RAND_FROM(if_transition));
        finish_stmt(sql);
        return sql;
    }

    std::string generate_rollback_stmt(){
        std::string sql;
        append_word(sql, "rollback");
        append_word(sql, RAND_FROM(if_transition));
        const char* to =RAND_FROM(if_to);
        if(to){
            append_word(sql,to);
            const char* savepoint=RAND_FROM(if_save_point);
            if(savepoint){
                append_word(sql,savepoint);
            }
            append_word(sql,save_point_name);
        }
        finish_stmt(sql);
        return sql;
    }

private:
    std::string sql_clause;
    const char* save_point_name="savepoint-";
    std::shared_ptr<table> table;
};

class create_table_stmt_generator:generator{
public:
    explicit create_table_stmt_generator(std::shared_ptr<table> tb):table(std::move(tb)){}
    ~create_table_stmt_generator() override = default;
    std::string generate() override {
        sql_clause+="create";

        return sql_clause;
    }
private:
    std::string sql_clause;
    std::shared_ptr<table> table;
};

class sql_stmt_generator:generator{
public:
    explicit sql_stmt_generator(std::shared_ptr<table> tb):table(std::move(tb)){
        table_generator =  std::make_shared<create_table_stmt_generator>(table);
    }

public:
    std::string generate() override {
        sql_clause+=table_generator->generate();
        return sql_clause;
    }

private:

    std::string sql_clause;
    std::shared_ptr<table> table;
    std::shared_ptr<create_table_stmt_generator> table_generator;
};

const char* conflict_result[]={
    "ROLLBACK",
    "ABORT",
    "FAIL",
    "IGNORE",
    "REPLACE"
};

class on_conflict_generator:generator{
public:
    on_conflict_generator() = default;
    std::string generate() override {
        std::string sql;
        append_word(sql,"on");
        append_word(sql,"conflict");
        append_word(sql,RAND_FROM(conflict_result));
        return sql;
    }
private:
    std::string sql_clause;

};

class window_generator : generator{

};

void debug_print(const std::string & s){
    std::cout << s << std::endl;
}

int main() {
    std::string name="test-table";
    std::vector<std::string> cols{"col_1","col_2","col_3"};
    auto tb = std::make_shared<table> (name,cols);
    //sql_stmt_generator generator(tb);
    //std::cout << generator.generate() << std::endl;
    begin_transition_stmt_generator tran(tb);

    for(int i=0;i<6;i++){
        debug_print(tran.generate_begin_stmt());
        debug_print(tran.generate_commit_stmt());
        debug_print(tran.generate_rollback_stmt());
    }
    on_conflict_generator on;
    debug_print(on.generate());

    return 0;
}