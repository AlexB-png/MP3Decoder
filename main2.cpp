#include "gtkmm/enums.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <iostream>

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv);

    Gtk::Window window;

    Gtk::Button button("Play Music");
    Gtk::Button button2("Pause!");

    Gtk::Box horizonbox(Gtk::ORIENTATION_HORIZONTAL, 5); // 5px spacing
    horizonbox.pack_start(button);
    horizonbox.pack_start(button2);

    window.add(horizonbox);

    window.set_default_size(300, 100);
    window.show_all();

    return app->run(window);
}
