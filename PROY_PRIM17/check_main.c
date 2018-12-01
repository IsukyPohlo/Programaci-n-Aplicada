#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "strct.h"

gboolean cerrarVent (GtkWidget *widget, GdkEvent *event, gpointer info);
void salir (GtkWidget *widget, gpointer info);

extern void tabtab(GtkWidget *widget, gpointer info);
extern void colorines(gpointer info);

int main(gint argc, gchar **argv){

	GtkWidget *ventana, *vbox, *imagen, *boton;

	DATA *d;

	//--

	d = malloc (sizeof (DATA));

	//-------  1  ----------	
	
	gtk_init (&argc,&argv);

	//-------  2  ----------
		// a

	colorines(d);
	
	ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	vbox = gtk_vbox_new (FALSE, 5);

	boton = gtk_button_new_with_label ("Iniciar");

	imagen = gtk_image_new_from_file ("1.jpg");
		// b
	
	gtk_window_set_title(GTK_WINDOW(ventana), "Proyecto Final");

	//-------  3  ----------

	g_signal_connect(G_OBJECT(ventana), "destroy", G_CALLBACK(salir),NULL);

	g_signal_connect(G_OBJECT(ventana), "delete-event",G_CALLBACK(cerrarVent), NULL);

	g_signal_connect(G_OBJECT(boton), "clicked",G_CALLBACK(tabtab), d);

	//-------- 4 ------------

	gtk_box_pack_start_defaults (GTK_BOX(vbox), imagen);

	gtk_box_pack_start_defaults (GTK_BOX(vbox), boton);

	gtk_container_add(GTK_CONTAINER(ventana),vbox);

	// 5
	
	gtk_widget_show_all(ventana);
	d->w.ante = ventana;

	// 6
	
	gtk_main();
	
	return 0;

}

gboolean cerrarVent (GtkWidget *widget, GdkEvent *event, gpointer info)
{
	g_print ("Sale bay");
	return FALSE;
//FALSE -> Destroy
}


void salir (GtkWidget *widget, gpointer info)
{
	gtk_main_quit();	
}


