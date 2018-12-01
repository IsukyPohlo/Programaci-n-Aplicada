#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <string.h>
#include "strct.h"

void fresh (gpointer info);
extern void showmov(gpointer info);
extern void click (GtkWidget *boton, gpointer info);
extern void entered (GtkWidget *boton, gpointer info);
extern void leaved (GtkWidget *boton, gpointer info);

void click (GtkWidget *boton, gpointer info)
{
	int i,j;

	const gchar *name = gtk_widget_get_name (boton);

	DATA *d = (DATA *) info;

	d->y = name[0] - 48;
	d->x = name[1] - 48;	

	g_print("\n*[%d](%d) %d[%d,%d] %d<%d,%d>",d->mode,d->turn,d->t[d->y][d->x],d->x, d->y,d->t[d->sy][d->sx],d->sx,d->sy);



	//ACTUALIZAR TABLERO

	fresh(info);

	g_print ("\nSHOWMOV\n");

	showmov(info);
	
	g_print ("\nEND_SHOWMOV\n");

	/*
	for (i=1;i<8;i++)
	{
		for (j=1;j<=8;j++)
		{			
			if (d->rag[j][i] == 1){
				g_print ("\ncb%d,%dcb",i,j);
				gtk_widget_modify_bg (GTK_WIDGET(d->b[j][i]), GTK_STATE_NORMAL, &(d->color.negro) );
			}
		}
	}*/
//AGREA
}

void entered (GtkWidget *boton, gpointer info)
{
	const gchar *name = gtk_widget_get_name (boton);
	char named[10];
	
	DATA *d = (DATA *) info;
	
	int y = name[0] - 48;
	int x = name[1] - 48;

	sprintf (named, "%d [%d,%d]",d->t[y][x],x,y);

	gtk_statusbar_push (GTK_STATUSBAR(d->barra),GPOINTER_TO_INT(d->barra_ID),named);
	
}

void leaved (GtkWidget *boton, gpointer info)
{
	
	const gchar *name = gtk_widget_get_name (boton);

	DATA *d = (DATA *) info;

	gtk_statusbar_pop (GTK_STATUSBAR(d->barra), GPOINTER_TO_INT (d->barra_ID));
}

void fresh (gpointer info){
	
	int i, j, p, q;
	
	DATA *d = (DATA *) info;
	
	//TURNO 0
	if (d->mode == 0)
	{
		if (d->turn == 0){
			for (i=1;i<=8;i++){
				for (j=1;j<=8;j++){		
					gtk_widget_modify_bg (GTK_WIDGET(d->b[i][j]), GTK_STATE_NORMAL, &(d->color.blanco) );
					gtk_widget_set_sensitive (d->b[i][j], FALSE);
					gtk_button_set_relief (GTK_BUTTON(d->b[i][j]), GTK_RELIEF_NONE);
				}
			}
		}
	}
	else
	{
		for (i=1;i<=8;i++)
		{
			for (j=1;j<=8;j++)
			{	
				if (  ( (i+j)%2 ) == 1)
				{
						gtk_widget_set_sensitive (d->b[i][j], TRUE);
				}
				else
				{
						gtk_widget_set_sensitive (d->b[i][j], FALSE);
				}
			}
		}
	}


	//CORONAR
	
	for (i=1;i<=8;i++)
	{
		
			if (d->t[1][i] > 0 && d->t[1][i] < 13)
			{	
				g_print("CORONAME :V");
				d->t[1][i] = (d->t[1][i]) + 12;
			}
			if (d->t[8][i] < 0 && d->t[8][i] > -13)
			{
				g_print("CORONAME >:V%d =",d->t[8][i]);
				d->t[8][i] = (d->t[8][i]) -12;
				g_print(" %d\n",d->t[8][i]);
			}
	}
	//TURNO 1-2

	if (d->turn == 1 || d->turn == 2){
		for (i=1;i<=8;i++){
			for (j=1;j<=8;j++){
				gtk_button_set_relief (GTK_BUTTON(d->b[i][j]),  GTK_RELIEF_NONE);
				if (  ( (i+j)%2 ) == 1){
					if ( d->turn == 1){
						if (d->t[i][j] > 0)
							gtk_widget_modify_bg (GTK_WIDGET(d->b[i][j]), GTK_STATE_PRELIGHT, &(d->color.rojo) );
						else if (d->t[i][j] < 0)
							gtk_widget_modify_bg (GTK_WIDGET(d->b[i][j]), GTK_STATE_PRELIGHT, &(d->color.verde) );
						else
							gtk_widget_modify_bg (GTK_WIDGET(d->b[i][j]), GTK_STATE_PRELIGHT, &(d->color.blanco) );
					}
					if ( d->turn == 2){
						if (d->t[i][j] < 0)
							gtk_widget_modify_bg (GTK_WIDGET(d->b[i][j]), GTK_STATE_PRELIGHT, &(d->color.rojo) );
						else if (d->t[i][j] > 0)
							gtk_widget_modify_bg (GTK_WIDGET(d->b[i][j]), GTK_STATE_PRELIGHT, &(d->color.verde) );
						else
							gtk_widget_modify_bg (GTK_WIDGET(d->b[i][j]), GTK_STATE_PRELIGHT, &(d->color.blanco) );
					}
					
				}
			}
		}
	}
	//ACTUALIZAR NOMBRES

	gtk_label_set_text (GTK_LABEL(d->names[0]),d->name[0]);
	gtk_label_set_text (GTK_LABEL(d->names[1]),d->name[1]);

	//ACTUALIZAR TIMEBOX

	if (d->turn == 1)
		gtk_widget_modify_bg (GTK_WIDGET(d->timeb), GTK_STATE_NORMAL, &(d->color.azul));
	else if (d->turn == 2)
		gtk_widget_modify_bg (GTK_WIDGET(d->timeb), GTK_STATE_NORMAL, &(d->color.rojo));
	else
		gtk_widget_modify_bg (GTK_WIDGET(d->timeb), GTK_STATE_NORMAL, &(d->color.blanco));

	//ACTUALIZAR TABLERO
	
	for (i=1;i<=8;i++){
		for (j=1;j<=8;j++){
			if (d->t[i][j] > 0){
				gtk_button_set_image(GTK_BUTTON(d->b[i][j]), (d->blanks[i][j]) );
			}
			else if (d->t[i][j] < 0){
				gtk_button_set_image(GTK_BUTTON(d->b[i][j]), (d->blanks[i][j]) );
			}
		}	
	}
	for (i=1;i<=8;i++){
		for (j=1;j<=8;j++){
			if (  ( (i+j)%2 ) == 1)
			{
				if (d->t[i][j] > 0){
					gtk_button_set_image( GTK_BUTTON(d->b[i][j]) , (d->piece[1][ d->t[i][j] ]) );
				}
				else if (d->t[i][j] < 0){
					gtk_button_set_image(GTK_BUTTON(d->b[i][j]), (d->piece[0][ (d->t[i][j])*(-1) ]) );
				}
				else if (d->t[i][j] == 0) gtk_button_set_image( GTK_BUTTON(d->b[i][j]) , (d->blanks[i][j]) );
			}
		}	
	}

	//ACTUALIZAR CEMENTERIO
	for (j=1;j<=12;j++){
		
		if (d->gra[0][j] != 0){
			gtk_button_set_image( GTK_BUTTON(d->grab[0][j]), (d->piece[0][ (d->gra[0][j])*(-1) ]) );

		}
		if (d->gra[1][j] != 0){
			gtk_button_set_image( GTK_BUTTON(d->grab[1][j]), (d->piece[1][ d->gra[1][j] ]) );
		}
	}
	
	//ACTUALIZAR BOBAS

	for (i=1;i<8;i++)
	{
		for (j=1;j<=8;j++)
		{			
			if (d->rag[j][i] == 1)
			{
				g_print ("OP%d,%dOP\n",i,j);
				gtk_button_set_relief (GTK_BUTTON(d->b[j][i]),  GTK_RELIEF_NORMAL);
				gtk_widget_modify_bg (GTK_WIDGET(d->b[j][i]), GTK_STATE_NORMAL, &(d->color.negro) );
			}
		}
	}
	g_print("\nEnd Fresh\n");
}
