#include <stdio.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include "dat.h"
#include "fns.h"

void
doAltTab(XEvent *ev)
{
	if (ev->xkey.state & ShiftMask)
		activateprevious();
	else
		activatenext();
}

void
doWorkspaceChange(XEvent *ev)
{
	int n, keysym;
	cmapfocus(0);
	keysym = XLookupKeysym(&(ev->xkey), 0);
	n = keysym & 0x0F;
	if (n == 0)
		n = 10;
	n -= 1;
	b2menu.lasthit = n; // make the menu point to the right place
	if (n > numvirtuals)
		return;
	switch_to(n);
	if (current)
		cmapfocus(current);
}
