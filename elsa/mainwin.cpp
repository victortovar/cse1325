#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>
#include <sstream>

Mainwin::Mainwin() : Store{new Store} {

	set_default_size(900, 700);
	set_title("ELSA");


	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
	add(*vbox);

	//adds menu bar at top of box
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
  vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//adds file menu to the menu bar
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
  menubar->append(*menuitem_file);
  Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
  menuitem_file->set_submenu(*filemenu);

	//adds quit to the file menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
  filemenu->append(*menuitem_quit);

	//adds view menu to the menu bar
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
  menubar->append(*menuitem_view);
  Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
  menuitem_view->set_submenu(*viewmenu);

	//adds customer to view menu
	Gtk::MenuItem *menuitem_view_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
  menuitem_view_customer->signal_activate().connect([this] {this->on_view_customer_click();});
  viewmenu->append(*menuitem_view_customer);


  //adds peripheral to the View menu
  Gtk::MenuItem *menuitem_view_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
  menuitem_view_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
  viewmenu->append(*menuitem_view_peripheral);

  //adds desktop to the View menu
  Gtk::MenuItem *menuitem_view_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
  menuitem_view_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
  viewmenu->append(*menuitem_view_desktop);

	//adds order to the View menu
  Gtk::MenuItem *menuitem_view_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
  menuitem_view_order->signal_activate().connect([this] {this->on_view_order_click();});
  viewmenu->append(*menuitem_view_order);

  // Create a Insert menu and add to the menu bar
  Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
  menubar->append(*menuitem_insert);
  Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
  menuitem_insert->set_submenu(*insertmenu);

  //adds customer to insert menu
  Gtk::MenuItem *menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
  menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
  insertmenu->append(*menuitem_insert_customer);

  //adds peripheral to insert menu
  Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
  menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
  insertmenu->append(*menuitem_insert_peripheral);


  //adds desktop to insert menu
  Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
  menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
  insertmenu->append(*menuitem_insert_desktop);

  //adds order to insert menu
  Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
  menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
  insertmenu->append(*menuitem_insert_order);


  //adds help menu to menu bar
  Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);


  //adds easter egg to help menu
  Gtk::MenuItem *menuitem_easter = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
  menuitem_easter->signal_activate().connect([this] {this->on_easter_egg_click();});
  helpmenu->append(*menuitem_easter);

	//adds an about to help menu
  Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
  menuitem_about->signal_activate().connect([this] {this->on_about_click();});
  helpmenu->append(*menuitem_about);


  // Provide a text entry box to show the remaining sticks
  data = Gtk::manage(new Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START});
  data->set_hexpand();

	Gtk::EventBox *eb = Gtk::manage(new Gtk::EventBox);
  eb->set_hexpand();
  eb->override_background_color(Gdk::RGBA("white"));
  eb->add(*data);
  // PACK_EXPAND_WIDGET tells VBox this widget should be as big as possible
  vbox->pack_start(*eb, Gtk::PACK_EXPAND_WIDGET, 0);

	// Provide a status bar for game messages
  msg = Gtk::manage(new Gtk::Label);
  msg->set_hexpand();
  // PACK_SHRINK tells VBox this widget should be as small as possible
  vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

  // Make the box and everything in it visible
  vbox->show_all();

}

Mainwin::~Mainwin(){}

void Mainwin::on_quit_click(){
	close();
}

void Mainwin::on_view_peripheral_click() { 
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Peripherals</b></big><tt>\n\n";
    for(int i=0; i<store->num_options(); ++i) 
        oss << i << ") " << store->option(i) << "\n";
    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}
void Mainwin::on_view_desktop_click() { 
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Products</b></big><tt>\n\n";
    for(int i=0; i<store->num_desktops(); ++i) 
        oss << i << ") " << store->desktop(i) << "\n";
    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}
void Mainwin::on_view_order_click() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Orders</b></big><tt>\n\n";
    for(int i=0; i<store->num_orders(); ++i) 
        oss << i << ") " << store->order(i) << "\n\n";
    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}
void Mainwin::on_view_customer_click() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Customers</b></big><tt>\n\n";
    for(int i=0; i<store->num_customers(); ++i) 
        oss << i << ") " << store->customer(i) << "\n";
    oss<<"</tt>";
    set_data(oss.str()); 
    set_msg("");
}

//insert new data via dialogs
void Mainwin::on_insert_peripheral_click() { 
    std::string peripheral = get_string("Name of new peripheral?");
    double cost = get_double("Cost?");

    Options option{peripheral, cost};
    store->add_option(option);

    on_view_peripheral_click();
    set_msg("Added peripheral " + peripheral);
}
void Mainwin::on_insert_desktop_click() { 
    on_view_peripheral_click();
    int desktop = store->new_desktop();
    while(true) {
        std::ostringstream oss;
        oss << store->desktop(desktop) << "\n\nAdd which peripheral (-1 when done)? ";
        int option = get_int(oss.str());
        if(option == -1) break;
        try {
            store->add_option(option, desktop);
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "===Option Not Valid===\n\n"}.run();
        }
    }
    on_view_desktop_click();
    set_msg("Added desktop " + std::to_string(desktop));
}
void Mainwin::on_insert_order_click() {
    on_view_customer_click();

    int customer = get_int("Customer?");
    if(customer == -1) return;

    int order = store->new_order(customer);

    on_view_desktop_click();
    while(true) {
        int desktop = get_int("Desktop (-1 when done)?");

        if(desktop == -1) break;
        store->add_desktop(desktop, order);
    }

    on_view_order_click();
    set_msg("Added order " + std::to_string(order) + " for $" + std::to_string(store->order(order).price()));
}
void Mainwin::on_insert_customer_click() {
    std::string name = get_string("Customer name?");
    if(name.size()) {
        std::string phone = get_string("Customer phone (123-456-7890)?");
        std::string email = get_string("Customer email (abc@domain.com)?");

        Customer customer{name, phone, email};
        store->add_customer(customer);
    }
    on_view_customer_click();
    set_msg("Added customer " + name);

}





