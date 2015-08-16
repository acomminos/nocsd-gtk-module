nocsd-gtk-module
================

A simple GTK3 module to eliminate the styling for client-side decorations.

I find this method to be preferable to the LD_PRELOAD approach used by gtk3-nocsd mainly due to not having to worry about ABI compatibility (only theming compatibility).

It plays nicer with GTK2 programs as well; it'll just fail to load as the module links against GTK3.

Usage
-----

`export GTK_MODULES=$GTK_MODULES:<path/to/nocsd-gtk-module.so>`

*(if you're on a recent version of GTK3, you should probably set GTK3_MODULES and not GTK_MODULES)*

This is generally a good thing to put in your WM's environment.
