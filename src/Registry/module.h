//
// Created by FlifeX on 3/30/25.
//

#ifndef MODULE_H
#define MODULE_H
#include <string>

namespace fck {
    class module {
    public:
        std::string name;
        module();
        ~module();

    private:
        int id;

    };
}

#endif //MODULE_H
