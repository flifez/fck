#include "main.h"

#include <iostream>

#include "Registry/registry.h"
#include "Components/source.h"
#include "Components/wire.h"
#include "Debug/debug.h"

using namespace fck;

int main () {
    std::shared_ptr<Registry> r = Registry::create();
    r->initialize();

    std::shared_ptr<Source> source = r->create_component<Source>(true);
    std::shared_ptr<Wire> wire0 = r->create_component<Wire>();
    std::shared_ptr<Wire> wire1 = r->create_component<Wire>();
    std::shared_ptr<Wire> wire2 = r->create_component<Wire>();
    std::shared_ptr<Wire> wire3 = r->create_component<Wire>();

    r->connect(wire3, wire0);
    r->connect(wire0, wire1);
    r->connect(wire1, wire2);
    r->connect(wire2, wire3);

    Debug::print_connections(*r);

    return 0;
}