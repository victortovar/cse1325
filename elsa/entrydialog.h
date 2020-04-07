#ifndef __entrydialog_h
#define __entrydialog_h

#include<gtkmm.h>

class EntryDialog : public Gtk::MessageDialog{
	public:
		EntryDialog(Gtk::Window& parent,
                const Glib::ustring& message,
                bool use_markup,
                Gtk::MessageType type,
                Gtk::ButtonsType buttons,
                bool modal);

    void set_text(const Glib::ustring& text);
	private:
    Gtk::Entry* entry;
};

#endif
