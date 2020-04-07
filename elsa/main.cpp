#include "mainwin.h"


int main (int argc, char *argv[]) {

    auto app = Gtk::Application::create(argc, argv, "elsa.test.v0");
    Mainwin win;
    return app->run(win);
}
