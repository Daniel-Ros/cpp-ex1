#include <vector>

struct Carpet{
    int rows,columns;   // the size of the mat
    char sym1,sym2;     // the symbols of the mat
};

enum STATE{
    ADD = 1,
    VIEW = 2,
    EXIT = 3
};
/**
 * @brief This is an appliction instance, It has a simple menu where you can chose to add or view carpets.
 * 
 */
class App
{
private:
    std::vector<Carpet> carpets;  // A priavte list that

    void showAddScreen();
    void showViewScreen();
public:
    void showScreen();
};