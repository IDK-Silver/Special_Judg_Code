#define SPJ_LOG true

// dependent library
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

// solution dependent library
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <cstdio>

enum Status
{
    AC = 0, WA = 1, ERROR = -1
};

bool compare_ans(const std::string& str,  std::unique_ptr<std::ifstream> & stream, const bool & ignore_case = false);
template <class T> bool compare_ans(const T & var,  std::unique_ptr<std::ifstream> & stream);
template <class T> bool compare_ans(const T & var,  std::unique_ptr<std::ifstream> & stream, const T & epsilon);
template <class T, class S> void print_log(const T & var, const S & ans, const bool & equal);

Status solution(std::unique_ptr<std::ifstream> &in, std::unique_ptr<std::ifstream> &ans)
{

    return Status::AC;

}

int main(int argc, char *args[])
{
    // check args is right
    if (argc < 3)
    {
        std::cerr << "args is not right\n";
        exit(Status::ERROR);
    }

    std::unique_ptr<std::ifstream> input_data_file = std::make_unique<std::ifstream>();
    std::unique_ptr<std::ifstream> user_output_file = std::make_unique<std::ifstream>();

    // open file
    input_data_file->open(args[1]);
    user_output_file->open(args[2]);

    // check file is open
    if (input_data_file->fail() || user_output_file->fail())
    {
        std::cerr << "file path is not exist\n";
        exit(Status::ERROR);
    }

    #if SPJ_LOG
        std::cout << std::left << std::setw(8) << "SPJ" << "\t" \
                  << std::left << std::setw(8) << "Solution" << "\t" \
                  << "Equal\n\n";
    #endif

    // run solution
    Status solution_status = solution(input_data_file, user_output_file);

    // close file
    input_data_file->close();
    user_output_file->close();

    // return the status (the ans is right or not)
    return solution_status;
}

template <class T> bool compare_ans(const T & var,  std::unique_ptr<std::ifstream> & stream)
{
    T ans;
    *stream >> ans;

    bool equal = ans == var;

#if SPJ_LOG
    print_log(var, ans, equal);
#endif

    if (not equal)
        exit(Status::WA);

    return true;
}

template <class T> bool compare_ans(const T & var,  std::unique_ptr<std::ifstream> & stream, const T & epsilon)
{
    T ans;
    *stream >> ans;

    bool equal = std::fabs(var - ans) < epsilon;

#if SPJ_LOG
    print_log(var, ans, equal);
#endif

    if (not equal)
        exit(Status::WA);

    return true;
}
bool compare_ans(const std::string& str,  std::unique_ptr<std::ifstream> & stream, const bool & ignore_case)
{

    auto to_upper = [](std::string str) {
        for (auto & c: str) c = toupper(c);
        return str;
    };

    // to split string like cin
    std::stringstream  ss(str);

    // the ans that part of string
    std::string ans;

    // the var that part of string
    std::string var;

    bool equal = false;
    while (ss >> var)
    {
        *stream >> ans;

        if (ignore_case)
        {
            var = to_upper(var);
            ans = to_upper(ans);
        }

        equal =  ans == var;

    #if SPJ_LOG
        print_log(var, ans, equal);
    #endif
    }

    if (not equal)
        exit(Status::WA);

    return true;
}
template <class T, class S> void print_log(const T & var, const S & ans, const bool & equal)
{
    std::cout << std::left << std::setw(8) << var << "\t" << std::setw(8) << ans << "\t" << std::boolalpha \
    << equal << "\n";
}