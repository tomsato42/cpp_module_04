#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain {
public:
    Brain();
    ~Brain();

    Brain(const Brain&);
    Brain& operator=(const Brain&);
private:
    std::string ideas[100];
};

#endif // BRAIN_H
