// This guards against including this header in multiple
// files that make up the program along with #endif
#ifndef ANIMAL_H

// Read the following lines once
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
public:
    string name;
    Animal();
    Animal(const Animal& orig);
    virtual ~Animal();
private:

};

#endif /* ANIMAL_H */

