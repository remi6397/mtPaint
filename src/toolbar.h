/*	toolbar.h
	Copyright (C) 2006 Mark Tyler

	This file is part of mtPaint.

	mtPaint is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	mtPaint is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with mtPaint in the file COPYING.
*/


#include <gtk/gtk.h>


//	DEFINITIONS


// If this order changes, main_init work on toolbar_menu_widgets will need changing

#define TOOLBAR_MAIN 1
#define TOOLBAR_TOOLS 2
#define TOOLBAR_SETTINGS 3
#define TOOLBAR_PALETTE 4
#define TOOLBAR_STATUS 5

#define TOOLBAR_MAX 6

#define PREVIEW_WIDTH 72
#define PREVIEW_HEIGHT 48


#define TOTAL_CURSORS 14

#define TOTAL_ICONS_MAIN 10


//	Tools toolbar buttons
#define TTB_PAINT    0
#define TTB_SHUFFLE  1
#define TTB_FLOOD    2
#define TTB_LINE     3
#define TTB_SMUDGE   4
#define TTB_CLONE    5
#define TTB_SELECT   6
#define TTB_POLY     7
#define TTB_LASSO    8
#define TTB_TEXT     9
#define TTB_ELLIPSE  10
#define TTB_FELLIPSE 11
#define TTB_OUTLINE  12
#define TTB_FILL     13
#define TTB_SELFV    14
#define TTB_SELFH    15
#define TTB_SELRCW   16
#define TTB_SELRCCW  17

#define DEFAULT_TOOL_ICON TTB_SELECT
#define PAINT_TOOL_ICON TTB_PAINT

#define TTB_0 TOTAL_ICONS_SETTINGS
#define TOTAL_ICONS_TOOLS 18

//	Settings toolbar buttons
#define SETB_CONT 0
#define SETB_OPAC 1
#define SETB_TINT 2
#define SETB_TSUB 3
#define SETB_CSEL 4
#define SETB_MASK 5

#define TOTAL_ICONS_SETTINGS 6

//	GLOBAL VARIABLES


GtkWidget *icon_buttons[TOTAL_ICONS_TOOLS];
GdkCursor *m_cursor[32];		// My mouse cursors
GdkCursor *move_cursor;

gboolean toolbar_status[TOOLBAR_MAX];		// True=show
GtkWidget *toolbar_boxes[TOOLBAR_MAX],		// Used for showing/hiding
	*toolbar_menu_widgets[TOOLBAR_MAX],	// Menu widgets
	*drawing_col_prev;



//	GLOBAL PROCEDURES

void toolbar_init(GtkWidget *vbox_main);	// Set up the widgets to the vbox
void toolbar_palette_init(GtkWidget *box);	// Set up the palette area
void toolbar_exit();				// Remember toolbar settings on program exit
void toolbar_showhide();			// Show/Hide all 4 toolbars
void toolbar_zoom_update();			// Update the zoom combos to reflect current zoom
void toolbar_viewzoom(gboolean visible);	// Show/hide the view zoom combo
void toolbar_update_settings();			// Update details in the settings toolbar

void pressed_toolbar_toggle( GtkMenuItem *menu_item, gpointer user_data, gint item );
						// Menu toggle for toolbars


void toolbar_preview_init();		// Initialize memory for preview area

void mem_set_brush(int val);		// Set brush, update size/flow/preview
void mem_pat_update();			// Update indexed and then RGB pattern preview
void repaint_top_swatch();		// Update selected colours A & B, 



GtkWidget *layer_iconbar(GtkWidget *window, GtkWidget *box, GtkWidget **icons);
	// Create iconbar for layers window


