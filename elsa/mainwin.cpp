#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

Mainwin::Mainwin() : store{new Store} {

  set_default_size(900, 700);
  set_title("ELSA");


  Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
  add(*vbox);

  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
  vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);


  Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
  menubar->append(*menuitem_file);
  Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
  menuitem_file->set_submenu(*filemenu);


  Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
  filemenu->append(*menuitem_quit);

  Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
  menubar->append(*menuitem_view);
  Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
  menuitem_view->set_submenu(*viewmenu);

  Gtk::MenuItem *menuitem_view_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
  menuitem_view_customer->signal_activate().connect([this] {this->on_view_customer_click();});
  viewmenu->append(*menuitem_view_customer);

  Gtk::MenuItem *menuitem_view_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
  menuitem_view_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
  viewmenu->append(*menuitem_view_peripheral);

  Gtk::MenuItem *menuitem_view_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
  menuitem_view_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
  viewmenu->append(*menuitem_view_desktop);

  Gtk::MenuItem *menuitem_view_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
  menuitem_view_order->signal_activate().connect([this] {this->on_view_order_click();});
  viewmenu->append(*menuitem_view_order);

  Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
  menubar->append(*menuitem_insert);
  Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
  menuitem_insert->set_submenu(*insertmenu);

  Gtk::MenuItem *menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
  menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
  insertmenu->append(*menuitem_insert_customer);

  Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
  menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
  insertmenu->append(*menuitem_insert_peripheral);

  Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
  menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
  insertmenu->append(*menuitem_insert_desktop);

  Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
  menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
  insertmenu->append(*menuitem_insert_order);

  Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);

  Gtk::MenuItem *menuitem_easter = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
  menuitem_easter->signal_activate().connect([this] {this->on_easter_egg_click();});
  helpmenu->append(*menuitem_easter);

  Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
  menuitem_about->signal_activate().connect([this] {this->on_about_click();});
  helpmenu->append(*menuitem_about);

  data = Gtk::manage(new Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START});
  data->set_hexpand();

  Gtk::EventBox *eb = Gtk::manage(new Gtk::EventBox);
  eb->set_hexpand();
  eb->override_background_color(Gdk::RGBA("white"));
  eb->add(*data);
  vbox->pack_start(*eb, Gtk::PACK_EXPAND_WIDGET, 0);

  msg = Gtk::manage(new Gtk::Label);
  msg->set_hexpand();
  vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
  vbox->show_all();
  on_new_store_click();

}

Mainwin::~Mainwin(){}

void Mainwin::on_new_store_click() {
    delete store;
    store = new Store;
    filename = "untitled.elsa";
    set_data("");
    set_msg("New store created");
}
    
void Mainwin::on_save_click() {
    try {
      std::ofstream ofs{filename};
      store->save(ofs);
      if(!ofs) throw std::runtime_error{"Error writing file"};
      set_msg("Saved " + filename);
    } catch(std::exception& e) {
            std::string err = "Unable to save store to " + filename;
            set_msg("<b>ERROR:</b> " + err);
            Gtk::MessageDialog{*this, err, false, Gtk::MESSAGE_WARNING}.run();
    }

}

void Mainwin::on_quit_click(){
	close();
}

void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);
    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);
    dialog.set_filename(filename);
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();
    if (result == 1) {
        filename = dialog.get_filename();
        on_save_click();
    }
}

void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            delete store; store = nullptr;
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            store = new Store{ifs};
            if(!ifs) throw std::runtime_error{"Invalid file contents"};
            on_view_customer_click();
            set_msg("Loaded " + filename);
        } catch (std::exception& e) {
            std::string err = "Unable to open store from " + filename + " (" + e.what() + " )";
            on_new_store_click();
            set_msg("<b>ERROR:</b>: " + err);
            Gtk::MessageDialog{*this, err, false, Gtk::MESSAGE_WARNING}.run();
        }
    }
}

void Mainwin::on_view_peripheral_click() { 
    std::ostringstream oss;
  //  oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Peripherals</b></big><tt>\n\n";
    for(int i=0; i<store->num_options(); ++i) 
        oss << i << ") " << store->option(i) << "\n";
    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}
void Mainwin::on_view_desktop_click() { 
    std::ostringstream oss;
//    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Products</b></big><tt>\n\n";
    for(int i=0; i<store->num_desktops(); ++i) 
        oss << i << ") " << store->desktop(i) << "\n";
    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}
void Mainwin::on_view_order_click() {
    std::ostringstream oss;
 //   oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Orders</b></big><tt>\n\n";
    for(int i=0; i<store->num_orders(); ++i) 
        oss << i << ") " << store->order(i) << "\n\n";
    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}
void Mainwin::on_view_customer_click() {
    std::ostringstream oss;
 //   oss << std::fixed << std::setprecision(2);
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

void Mainwin::on_easter_egg_click() {
    Customer c{"Bugs Bunny", "817-ACA-RROT", "bugs@loony.tunes"};          store->add_customer(c);
    c = Customer{"Elastigirl", "817-STR-ETCH", "helen@incredibles.movie"}; store->add_customer(c);
    c = Customer{"Tuck and Roll", "817-UFI-RED2", "circus@bugs.life"};     store->add_customer(c);
    c = Customer{"Tiana", "817-NOG-RIMM", "princess@lily.pad"};            store->add_customer(c);

    Options o{"CPU: 2.6 GHz Xeon 6126T", 2423.47};         store->add_option(o);
    o = Options{"CPU: 2.4 GHz Core i7-8565U", 388.0};      store->add_option(o);
    o = Options{"CPU: 2.2 GHz AMD Opteron", 37.71};        store->add_option(o);
    o = Options{"CPU: 300 MHz AM3351BZCEA30R ARM", 11.03}; store->add_option(o);
    o = Options{"CPU: 240 MHz ColdFire MCF5", 17.33};      store->add_option(o);

    o = Options{"2 GB RAM", 17.76};                        store->add_option(o);
    o = Options{"4 GB RAM", 22.95};                        store->add_option(o);
    o = Options{"8 GB RAM", 34.99};                        store->add_option(o);
    o = Options{"16 GB RAM", 92.99};                       store->add_option(o);
    o = Options{"32 GB RAM", 134.96};                      store->add_option(o);
    o = Options{"64 GB RAM", 319.99};                      store->add_option(o);

    o = Options{"0.5 TB SSD", 79.99};                      store->add_option(o);
    o = Options{"1 TB SSD", 109.99};                       store->add_option(o);
    o = Options{"2 TB SSD", 229.99};                       store->add_option(o);
    o = Options{"4 TB SSD", 599.99};                       store->add_option(o);

    o = Options{"1 TB PC Disk", 44.83};                    store->add_option(o);
    o = Options{"2 TB Hybrid Disk", 59.99};                store->add_option(o);
    o = Options{"4 TB Hybrid Disk", 93.98};                store->add_option(o);

    int desktop = store->new_desktop();
    store->add_option(0, desktop);
    store->add_option(9, desktop);
    store->add_option(14, desktop);

    desktop = store->new_desktop();
    store->add_option(1, desktop);
    store->add_option(7, desktop);
    store->add_option(17, desktop);

    desktop = store->new_desktop();
    store->add_option(5, desktop);
    store->add_option(7, desktop);
    store->add_option(15, desktop);
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("ELSA");
    auto logo = Gdk::Pixbuf::create_from_file("elsa.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 0.2.0");
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {"Custom logo based on public domain image\nhttps://www.piqsels.com/en/public-domain-photo-ffxdb"};
    dialog.set_artists(artists);
    dialog.run();
    set_msg("");
}

void Mainwin::set_data(std::string s) {data->set_markup(s);}
void Mainwin::set_msg(std::string s) {msg->set_markup(s);}

//reads a string, double, or int
std::string Mainwin::get_string(std::string prompt) {
    EntryDialog newString{*this, prompt};
    newString.run();
    return newString.get_text();
}
double Mainwin::get_double(std::string prompt) {
    try {
        return std::stod(get_string(prompt));
    } catch(std::exception& e) {
        // std::MessageDialog{*this, "ERROR: Invalid double"}.run();
        return -1.0;
    }
}

int Mainwin::get_int(std::string prompt) {
    try {
        return std::stoi(get_string(prompt));
    } catch(std::exception& e) {
        // std::MessageDialog{*this, "ERROR: Invalid int"}.run();
        return -1;
    }
}



