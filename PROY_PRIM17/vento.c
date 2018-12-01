#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <string.h>
#include "strct.h"

extern gboolean cerrarVent (GtkWidget *widget, GdkEvent *event, gpointer info);
extern void fresh (gpointer);

void Ok (GtkWidget *widget, gpointer info);
void Change (GtkWidget *widget, gpointer info);
void New_game (GtkWidget *widget, gpointer info);
void Bya (GtkWidget *widget, gpointer info);
void PvP (GtkWidget *widget, gpointer info);
void PvC (GtkWidget *widget, gpointer info);

void New_game (GtkWidget *widget, gpointer info){

	//-------------------------------------------------------------------------NEWGAME

	GtkWidget *vent, *tabla, *b1, *b2, *b3;

	DATA *d = (DATA *) info;

	//-------  2  ----------
		// a
	
	vent = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	tabla = gtk_table_new ( 6, 9, TRUE);

	b1 = gtk_button_new_with_label ("PvP");
	b2 = gtk_button_new_with_label ("PvC");
	b3 = gtk_button_new_with_label ("Cancelar");

		// b Propiedades
	
	gtk_window_set_title(GTK_WINDOW(vent), "Juego Nuevo");

	//gtk_window_resize (GTK_WINDOW (vent), 600,600);
	gtk_window_set_resizable(GTK_WINDOW(vent), FALSE);
	gtk_window_set_position (GTK_WINDOW (vent),GTK_WIN_POS_CENTER);	

	gtk_widget_modify_bg (GTK_WIDGET(vent), GTK_STATE_NORMAL, &(d->color.azul_rey) );
	
	gtk_widget_modify_bg (GTK_WIDGET(b1), GTK_STATE_NORMAL, &(d->color.naranja) );
	gtk_widget_modify_bg (GTK_WIDGET(b2), GTK_STATE_NORMAL, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(b3), GTK_STATE_NORMAL, &(d->color.azul_ext) );

	//-------  3 Señales ----------

	g_signal_connect(G_OBJECT(b1), "clicked",G_CALLBACK(PvP), d);
	g_signal_connect(G_OBJECT(b2), "clicked",G_CALLBACK(PvC), d);
	g_signal_connect(G_OBJECT(b3), "clicked",G_CALLBACK(Bya), d);
	g_signal_connect(G_OBJECT(vent), "delete-event",G_CALLBACK(cerrarVent), NULL);

	//-------- 4 Contenedores ------------

	gtk_table_attach_defaults ( GTK_TABLE (tabla), b1, 1, 4, 1, 3);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), b2, 5, 8, 1, 3);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), b3, 4, 5, 4, 5);

	gtk_container_add(GTK_CONTAINER(vent),tabla);

	// 5
	
	gtk_widget_show_all(vent);
	d->w.ante = vent;
	// 6
}

void Bya (GtkWidget *widget, gpointer info){

	DATA *d = (DATA *) info;
	
	gtk_widget_hide_all (d->w.ante);
}

void PvP (GtkWidget *widget, gpointer info){
	
	//-------------------------------------------------------------------------PVP

	GtkWidget *vent, *tabla, *bok, *lab1, *lab2;

	DATA *d = (DATA *) info;
	
	d->mode = 1;
	d->turn = 1;
	
	//-------  2  ----------
		// a
	
	vent = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	tabla = gtk_table_new ( 6, 10, TRUE);

	d->entry1 = gtk_entry_new();
	d->entry2 = gtk_entry_new();

	lab1 = gtk_label_new ("Nombre:");
	lab2 = gtk_label_new ("Nombre:");

	d->bc1 = gtk_button_new_with_label ("1");
	d->bc2 = gtk_button_new_with_label ("2");
	bok = gtk_button_new_with_label ("Ok");

		// b Propiedades
	
	gtk_window_set_title(GTK_WINDOW(vent), "PvP");
	//gtk_window_resize (GTK_WINDOW (vent), 600,600);
	gtk_window_set_resizable(GTK_WINDOW(vent), FALSE);
	gtk_window_set_position (GTK_WINDOW (vent),GTK_WIN_POS_MOUSE);

	gtk_widget_modify_bg (GTK_WIDGET(vent), GTK_STATE_NORMAL, &(d->color.naranja) );
	
	gtk_widget_modify_bg (GTK_WIDGET(d->bc1), GTK_STATE_NORMAL, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(d->bc2), GTK_STATE_NORMAL, &(d->color.rojo_cla) );

	gtk_widget_modify_bg (GTK_WIDGET(d->entry1), GTK_STATE_NORMAL, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry2), GTK_STATE_NORMAL, &(d->color.rojo) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry1), GTK_STATE_SELECTED, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry2), GTK_STATE_SELECTED, &(d->color.rojo) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry1), GTK_STATE_PRELIGHT, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry2), GTK_STATE_PRELIGHT, &(d->color.rojo) );

	gtk_widget_modify_bg (GTK_WIDGET(bok), GTK_STATE_NORMAL, &(d->color.azul_ext) );

	gtk_widget_modify_fg (GTK_WIDGET(lab1), GTK_STATE_NORMAL, &(d->color.blanco) );
	gtk_widget_modify_fg (GTK_WIDGET(lab2), GTK_STATE_NORMAL, &(d->color.blanco) );

	gtk_widget_modify_fg (GTK_WIDGET(d->bc1), GTK_STATE_NORMAL, &(d->color.blanco) );
	gtk_widget_modify_fg (GTK_WIDGET(d->bc2), GTK_STATE_NORMAL, &(d->color.blanco) );


	//gtk_button_set_relief (GTK_BUTTON(b1), GTK_RELIEF_NONE);
	//gtk_button_set_relief (GTK_BUTTON(b2), GTK_RELIEF_NONE);
	//gtk_button_set_relief (GTK_BUTTON(b3), GTK_RELIEF_NONE);
	
	//-------  3 Señales ----------

	g_signal_connect(G_OBJECT(d->bc1), "clicked",G_CALLBACK(Change), d);
	g_signal_connect(G_OBJECT(d->bc2), "clicked",G_CALLBACK(Change), d);
	g_signal_connect(G_OBJECT(bok), "clicked",G_CALLBACK(Ok), d);
	g_signal_connect(G_OBJECT(vent), "delete-event",G_CALLBACK(cerrarVent), NULL);

	//-------- 4 Contenedores ------------

	gtk_table_attach_defaults ( GTK_TABLE (tabla), lab1, 1, 4, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), d->entry1, 1, 4, 2, 3);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), lab2, 6, 9, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), d->entry2, 6, 9, 2, 3);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), d->bc1, 2, 3, 3, 4);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), d->bc2, 7, 8, 3, 4);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), bok, 4, 6, 4, 5);

	gtk_container_add(GTK_CONTAINER(vent),tabla);

	// 5
	
	gtk_widget_show_all(vent);
	gtk_widget_hide_all (d->w.ante);
	d->w.ante = vent;

	// 6
}



void Change (GtkWidget *widget, gpointer info)
{

	DATA *d = (DATA *) info;

	if (d->turn == 1)
	{
		d->turn = 2;
		gtk_button_set_label(GTK_BUTTON (d->bc1) ,"2");
		gtk_button_set_label(GTK_BUTTON (d->bc2) ,"1");
	}
	else if (d->turn == 2)
	{
		d->turn = 1;
		gtk_button_set_label(GTK_BUTTON (d->bc1),"1");
		gtk_button_set_label(GTK_BUTTON (d->bc2),"2");
		
	}
}


void PvC (GtkWidget *widget, gpointer info){

		
	//-------------------------------------------------------------------------PVC

	GtkWidget *vent, *tabla, *bok, *lab1, *lab2;

	DATA *d = (DATA *) info;
	
	d->mode = -1;
	d->turn = 1;
	//-------  2  ----------
		// a
	
	vent = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	tabla = gtk_table_new ( 6, 10, TRUE);

	d->entry1 = gtk_entry_new();
	d->entry2 = gtk_entry_new();

	lab1 = gtk_label_new ("Nombre:");
	lab2 = gtk_label_new ("Nombre:");

	d->bc1 = gtk_button_new_with_label ("1");
	d->bc2 = gtk_button_new_with_label ("2");
	bok = gtk_button_new_with_label ("Ok");

		// b Propiedades
	
	gtk_window_set_title(GTK_WINDOW(vent), "PvC");
	gtk_entry_set_text ( GTK_ENTRY (d->entry2), "PC" );
	gtk_widget_set_sensitive (d->entry2, FALSE);
	//gtk_window_resize (GTK_WINDOW (vent), 600,600);
	gtk_window_set_resizable(GTK_WINDOW(vent), FALSE);
	gtk_window_set_position (GTK_WINDOW (vent),GTK_WIN_POS_MOUSE);

	gtk_widget_modify_bg (GTK_WIDGET(vent), GTK_STATE_NORMAL, &(d->color.naranja) );
	
	gtk_widget_modify_bg (GTK_WIDGET(d->bc1), GTK_STATE_NORMAL, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(d->bc2), GTK_STATE_NORMAL, &(d->color.rojo_cla) );

	gtk_widget_modify_bg (GTK_WIDGET(d->entry1), GTK_STATE_NORMAL, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry2), GTK_STATE_NORMAL, &(d->color.rojo) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry1), GTK_STATE_SELECTED, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry2), GTK_STATE_SELECTED, &(d->color.rojo) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry1), GTK_STATE_PRELIGHT, &(d->color.azul_cla) );
	gtk_widget_modify_bg (GTK_WIDGET(d->entry2), GTK_STATE_PRELIGHT, &(d->color.rojo) );

	gtk_widget_modify_bg (GTK_WIDGET(bok), GTK_STATE_NORMAL, &(d->color.azul_ext) );

	gtk_widget_modify_fg (GTK_WIDGET(lab1), GTK_STATE_NORMAL, &(d->color.blanco) );
	gtk_widget_modify_fg (GTK_WIDGET(lab2), GTK_STATE_NORMAL, &(d->color.blanco) );

	gtk_widget_modify_fg (GTK_WIDGET(d->bc1), GTK_STATE_NORMAL, &(d->color.blanco) );
	gtk_widget_modify_fg (GTK_WIDGET(d->bc2), GTK_STATE_NORMAL, &(d->color.blanco) );


	//gtk_button_set_relief (GTK_BUTTON(b1), GTK_RELIEF_NONE);
	//gtk_button_set_relief (GTK_BUTTON(b2), GTK_RELIEF_NONE);
	//gtk_button_set_relief (GTK_BUTTON(b3), GTK_RELIEF_NONE);
	
	//-------  3 Señales ----------

	g_signal_connect(G_OBJECT(d->bc1), "clicked",G_CALLBACK(Change), d);
	g_signal_connect(G_OBJECT(d->bc2), "clicked",G_CALLBACK(Change), d);
	g_signal_connect(G_OBJECT(bok), "clicked",G_CALLBACK(Ok), d);
	g_signal_connect(G_OBJECT(vent), "delete-event",G_CALLBACK(cerrarVent), NULL);

	//-------- 4 Contenedores ------------

	gtk_table_attach_defaults ( GTK_TABLE (tabla), lab1, 1, 4, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), d->entry1, 1, 4, 2, 3);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), lab2, 6, 9, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), d->entry2, 6, 9, 2, 3);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), d->bc1, 2, 3, 3, 4);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), d->bc2, 7, 8, 3, 4);
	gtk_table_attach_defaults ( GTK_TABLE (tabla), bok, 4, 6, 4, 5);

	gtk_container_add(GTK_CONTAINER(vent),tabla);

	// 5
	
	gtk_widget_show_all(vent);
	gtk_widget_hide_all (d->w.ante);
	d->w.ante = vent;

	// 6
}

void Ok (GtkWidget *widget, gpointer info)
{
	DATA *d = (DATA *) info;

	strcpy(d->name[0], (char *)gtk_entry_get_text ( GTK_ENTRY (d->entry1) )  );
	strcpy(d->name[1], (char *)gtk_entry_get_text ( GTK_ENTRY (d->entry2) )  );

	g_print("%s \n%s",d->name[0],d->name[1]);

	fresh(d);
	gtk_widget_hide_all (d->w.ante);
}
