#ifndef __entrydialog_h
#define __entrydialog_h

#include<gtkmm.h>

class EntryDialog : public Gtk::MessageDialog{
	public:
		EntryDialog(Gtk::Window& parent,
								const Glib::ustring& message,
								bool use_markup = flase,
								Gtk::MessageType type=Gtk::MESSAGE_OTHER,
								Gtk::ButtonsType buttons=Gtk::BUTTONS_OK
								bool modal=false);

		void set_text(const Glib::ustring& text);
	private:
		Gtk::Entry* entry;
};

#endif
