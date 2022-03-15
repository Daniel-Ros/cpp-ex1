#include <vector>

struct Invoice{
    int rows,columns;   // the size of the mat
    char sym1,sym2;     // the symbols of the mat
};

enum STATE{
    ADD = 1,
    VIEW = 2,
    EXIT = 3
};

class App
{
private:
    std::vector<Invoice> invoices;

    void showAddScreen();
    void showViewScreen();
public:
    void showScreen();
};