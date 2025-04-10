//
// Created by FlifeX on 3/30/25.
//

#ifndef MODULE_H
#define MODULE_H
#include <string>
#include <ranges>
#include <unordered_set>

#include "registry.h"

namespace fck {
    class Module : public std::enable_shared_from_this<Module> {
    public:
        std::string name;
        explicit Module(std::string name) : name(std::move(name)), registry(Registry::create()) {
            registry->initialize();
        }

        bool check_loop();
        void add_submodule(const std::shared_ptr<Module>& submodule);
        void remove_submodule(int id);
        std::shared_ptr<Module> clone();

    private:
        std::unordered_map<int, std::shared_ptr<Module>> submodules;
        std::shared_ptr<Registry> registry;
        bool check_loop(const std::shared_ptr<Module>& target) const;
    };
}

#endif //MODULE_H
