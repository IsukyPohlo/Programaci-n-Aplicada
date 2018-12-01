#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "strct.h"

void colorines(gpointer info);

void colorines(gpointer info){

	DATA *d = (DATA *) info;

	gdk_color_parse ("red", &(d->color.rojo) );
	gdk_color_parse ("#F78181", &(d->color.rojo_cla) );	
	
	gdk_color_parse ("orange", &(d->color.naranja) );
	gdk_color_parse ("blue", &(d->color.azul) );
	gdk_color_parse ("green", &(d->color.verde) );
	gdk_color_parse ("white", &(d->color.blanco) );
	gdk_color_parse ("black", &(d->color.negro) );
	
	gdk_color_parse ("#2E2EFE", &(d->color.azul_rey) );
	gdk_color_parse ("#819FF7", &(d->color.azul_cla) );
	gdk_color_parse ("#81DAF5", &(d->color.azul_ext) ); 

}
