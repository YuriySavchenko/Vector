#include "vector.h"

class User {
    int id;
    static int s_nextId;
public:
    User() :
    id(s_nextId++) {
            std::cout << "User " << id << " constructed." << std::endl;
    }

    ~User() {
        std::cout << "User " << id << " destroyed" << std::endl;
    }
};

int User::s_nextId = 0;

void add_user(Vector<User>& vector) {
    for (int i = 0; i < 2; ++i) {
        User user;
        vector.push_back(user);
    }
}

int main(int argc, char *argv[]) {
    Vector<User> users;
    add_user(users);

    return 0;
}