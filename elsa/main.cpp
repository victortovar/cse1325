#include "mainwin.h"

int main (int argc, char *argv[]) {
    srand (time(NULL));
    auto app = Gtk::Application::create(argc, argv, "");
    Mainwin win;
    return app->run(win);
}
