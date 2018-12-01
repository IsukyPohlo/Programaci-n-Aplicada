#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <string.h>
#include "strct.h"

extern void fresh (gpointer info);
extern void click (GtkWidget *widget, gpointer info);
extern void entered (GtkWidget *widget, gpointer info);
extern void leaved (GtkWidget *widget, gpointer info);
extern void salir (GtkWidget *widget, gpointer info);
extern void New_game (GtkWidget *widget, gpointer info);

void tabtab (GtkWidget *widget, gpointer info);

void tabtab (GtkWidget *widget, gpointer info){

	GtkWidget *ventana, *vbox, *imagen, *stat, *bg[2], *ibg[2], *gravey[2], *lbl, *vbots;

	GtkWidget *it_juego, *it_herramientas, *it_acercade;

	GtkWidget *it_jugar, *it_guardar, *it_recuperar, *it_tops, *it_terminar;
	GtkWidget *it_undo, *it_redo, *it_ayuda;
	GtkWidget *it_isuky, *it_atortole;

	GtkWidget *menu_herramientas, *menu_jugar, *menu_acercade;

	GtkWidget  *menubar;

	DATA *d = (DATA *) info;

	int i, j, p, q;

	GdkColor color,color1,color2,tab1,tab2;

	const gchar *skins[2][2][13], *splash[5][2][6][13], *name[3];

	char named[5];

	int ta[9][9] =	{	{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 , 0 ,-4 , 0 ,-3 , 0 ,-2 , 0 ,-1 },
				{ 0 ,-8 , 0 ,-7 , 0 ,-6 , 0 ,-5 , 0 },
				{ 0 , 0 ,-12, 0 ,-11, 0 ,-10, 0 ,-9 },
				{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 , 9 , 0 , 10, 0 , 11, 0 , 12, 0 },
				{ 0 , 0 , 5 , 0 , 6 , 0 , 7 , 0 , 8 },
				{ 0 , 1 , 0 , 2 , 0 , 3 , 0 , 4 , 0 }
			};
	
	/*
	int ta[9][9] ={{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 ,-1 , 0 ,-2 , 0 , 1 , 0 , 2 , 0 },
				{ 0 , 0 , 15, 0 , 0 , 0 ,-15, 0 , 0 },
				{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
				{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
			};
	*/

	//Nombres de archivo para skins

	i=0;
	skins[0][0][i] = "skins/1/ficha_emp.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-1.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-2.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-3.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-4.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-5.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-6.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-7.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-8.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-9.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-10.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-11.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-12.png";i++;
	skins[0][0][i] = "skins/1/ficha_a_-13.png";i++;

	
	splash[0][0][0][0] = "skins/1/empt.png";
	for (i=1;i<=13;i++){
		splash[0][0][0][i] = "skins/1/idle_-0.png";i++;
		splash[0][0][1][i] = "skins/1/mov_-0.png";i++;
		splash[0][0][2][i] = "skins/1/off_-0.png";i++;
		splash[0][0][3][i] = "skins/1/att_-0.png";i++;
		splash[0][0][4][i] = "skins/1/def_-0.png";i++;
	}

	i=0;
	skins[0][0][i] = "skins/1/ficha_emp.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_1.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_2.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_3.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_4.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_5.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_6.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_7.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_8.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_9.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_10.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_11.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_12.png";i++;
	skins[0][1][i] = "skins/1/ficha_a_13.png";i++;


	splash[0][1][0][0] = "skins/1/empt.png";
	for (i=1;i<=13;i++){
		splash[0][1][0][i] = "skins/1/idle_0.png";
		splash[0][1][1][i] = "skins/1/mov_0.png";
		splash[0][1][2][i] = "skins/1/off_0.png";
		splash[0][1][3][i] = "skins/1/att_0.png";
		splash[0][1][4][i] = "skins/1/def_0.png";
	}
	

	p=0;

	//-------- inicializacion variables
	d->turn = 1;
	d->mode = 1;

	d->rage=0;
	
	d->sx = NUL;
	d->sy = NUL;
	
	d->t[NUL][NUL] = NUL;

	d->grac[0] = 0;
	d->grac[1] = 0;
	
	d->boba=0;

	for (i=0;i<=8;i++){
		for (j=0;j<=8;j++){
			d->t[i][j] = ta[i][j];
			d->rag[i][j] = 0;
		}
	}
	
	for (i=0;i<=1;i++){
		for (j=1;j<=12;j++){
			d->gra[i][j] = 0;
		}
	}
	
	strcpy (d->name[0],"Jugador 1");
	strcpy (d->name[1],"Jugador 2");

	/*d->turn = 0;

	d->t[0] ={ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
	d->t[1] ={ 0 , 0 ,-4 , 0 ,-3 , 0 ,-2 , 0 ,-1 };
	d->t[2] ={ 0 ,-8 , 0 ,-7 , 0 ,-6 , 0 ,-5 , 0 };
	d->t[3] ={ 0 , 0 ,-12, 0 ,-11, 0 ,-10, 0 ,-9 };
	d->t[4] ={ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
	d->t[5] ={ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
	d->t[6] ={ 0 , 9 , 0 , 10, 0 , 11, 0 , 12, 0 };
	d->t[7] ={ 0 , 0 , 5 , 0 , 6 , 0 , 7 , 0 , 8 };
	d->t[8] ={ 0 , 1 , 0 , 2 , 0 , 3 , 0 , 4 , 0 };
	*/


	//-------  2  ----------
		// a
	
	ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	vbox = gtk_vbox_new (FALSE, 5);
	vbots = gtk_vbox_new (FALSE, 5);

	d->tab = gtk_table_new (14, 16, TRUE);

	for (i=1;i<=8;i++){
		for (j=1;j<=8;j++){
			d->e[i][j] = gtk_event_box_new();
			d->b[i][j] = gtk_button_new();
		}
	}

	for (i=0;i<=1;i++){
		for (j=1;j<=13;j++){
			d->grave[i][j] = gtk_event_box_new();
			d->grab[i][j] = gtk_button_new();
		}
	}

	bg[0] = gtk_event_box_new();
	bg[1] = gtk_event_box_new();

	d->timeb = gtk_event_box_new();
	
	gravey[0] = gtk_table_new (2, 6, TRUE);
	gravey[1] = gtk_table_new (2, 6, TRUE);

	d->barra = gtk_statusbar_new();

	menubar = gtk_menu_bar_new();

	menu_jugar = gtk_menu_new();
	menu_herramientas = gtk_menu_new();
	menu_acercade = gtk_menu_new();
	
	it_juego = gtk_menu_item_new_with_mnemonic ("Jueg_o");
	it_herramientas = gtk_menu_item_new_with_mnemonic ("_Herramientas");
	it_acercade = gtk_menu_item_new_with_label ("Acerca de...");
	
	it_jugar = gtk_menu_item_new_with_mnemonic ("Jug_ar");
	it_guardar = gtk_menu_item_new_with_mnemonic ("_Guardar");
	it_recuperar = gtk_menu_item_new_with_mnemonic ("_Recuperar");
	it_tops = gtk_menu_item_new_with_mnemonic ("To_ps");
	it_terminar = gtk_menu_item_new_with_mnemonic ("T_erminar");

	it_undo = gtk_menu_item_new_with_mnemonic ("Desha_cer");
	it_redo = gtk_menu_item_new_with_mnemonic ("_Rehacer");
	it_ayuda = gtk_menu_item_new_with_mnemonic ("A_yuda");

	it_isuky = gtk_menu_item_new_with_mnemonic ("_Isuky");
	it_atortole = gtk_menu_item_new_with_mnemonic ("A._Tortolero");
	
	d->names[0] = gtk_label_new (d->name[0]);
	d->names[1] = gtk_label_new (d->name[1]);

	lbl = gtk_label_new ("Tiempo: ");

		// b  propiedades uwu
	//Ventana
	gtk_window_set_title(GTK_WINDOW(ventana), "Damas Inglesas");
	gtk_window_set_resizable(GTK_WINDOW(ventana), FALSE);
	gtk_window_set_position (GTK_WINDOW (ventana),GTK_WIN_POS_CENTER_ALWAYS);	

	for (i=1;i<=8;i++){
		for (j=1;j<=8;j++){

			switch (i){
			case 1:
				strcpy ((char *)name,"1");
			break;
			case 2:
				strcpy ((char *)name,"2");
			break;
			case 3:
				strcpy ((char *)name,"3");
			break;
			case 4:
				strcpy ((char *)name,"4");
			break;
			case 5:
				strcpy ((char *)name,"5");
			break;
			case 6:
				strcpy ((char *)name,"6");
			break;
			case 7:
				strcpy ((char *)name,"7");
			break;
			case 8:
				strcpy ((char *)name,"8");
			break;
			}
			
			switch (j){
			case 1:
				strcat ((char *)name,"1");
			break;
			case 2:
				strcat ((char *)name,"2");
			break;
			case 3:
				strcat ((char *)name,"3");
			break;
			case 4:
				strcat ((char *)name,"4");
			break;
			case 5:
				strcat ((char *)name,"5");
			break;
			case 6:
				strcat ((char *)name,"6");
			break;
			case 7:
				strcat ((char *)name,"7");
			break;
			case 8:
				strcat ((char *)name,"8");
			break;
			}

			gtk_widget_set_name (d->b[i][j],(char *)name);
		}
	}

	//Tooltip
	for (i=1;i<=8;i++)
	{
		for (j=1;j<=8;j++)
		{
			sprintf (named, "[%d,%d]",i,j);
			gtk_widget_set_tooltip_text (GTK_WIDGET (d->b[j][i]), named );
		}
	}

	//INHABILITAR TEJAS BLANCAS Y FONDO DE TEJAS

	//COLORES!! :#3

	for (i=1;i<=8;i++){
		for (j=1;j<=8;j++){
			gtk_widget_modify_bg (GTK_WIDGET(d->b[i][j]), GTK_STATE_NORMAL, &(d->color.blanco) );
			if (  ( (i+j)%2 ) == 1)
				gtk_widget_modify_bg (GTK_WIDGET(d->e[i][j]), GTK_STATE_NORMAL, &(d->color.azul_rey) );
			else{
				gtk_widget_set_sensitive (d->b[i][j], FALSE);
				gtk_widget_modify_bg (GTK_WIDGET(d->e[i][j]), GTK_STATE_NORMAL, &(d->color.azul_cla) );
			}
		}
	}	

	for (j=1;j<=13;j++){
		gtk_widget_modify_bg (GTK_WIDGET(d->grave[0][j]), GTK_STATE_NORMAL, &(d->color.rojo));
	}

	for (j=1;j<=13;j++){
		gtk_widget_modify_bg (GTK_WIDGET(d->grave[1][j]), GTK_STATE_NORMAL, &(d->color.azul));
	}
	
	gtk_widget_modify_bg (GTK_WIDGET(bg[1]), GTK_STATE_NORMAL, &(d->color.rojo));
	gtk_widget_modify_bg (GTK_WIDGET(bg[0]), GTK_STATE_NORMAL, &(d->color.azul));

	gtk_widget_modify_bg (GTK_WIDGET(gravey[1]), GTK_STATE_NORMAL, &(d->color.rojo));
	gtk_widget_modify_bg (GTK_WIDGET(gravey[0]), GTK_STATE_NORMAL, &(d->color.azul));

	//gtk_widget_modify_bg (GTK_WIDGET(d->b[1][2]), GTK_STATE_PRELIGHT, &(d->color.rojo) );
	//gtk_widget_modify_bg (GTK_WIDGET(d->b[2][1]), GTK_STATE_SELECTED, &(d->color.azul) );

	//CAMBIAR EL FONDO DEL BOTON A TRANSPARENTE

	for (i=1;i<=8;i++){
		for (j=1;j<=8;j++){
			gtk_button_set_relief (GTK_BUTTON(d->b[i][j]),  GTK_RELIEF_NONE);
		}
	}
	
	for (i=0;i<=1;i++){
		for (j=1;j<=13;j++){
			gtk_button_set_relief (GTK_BUTTON(d->grab[i][j]),  GTK_RELIEF_NONE);
		}	
	}

		//imagenes
	imagen = gtk_image_new_from_file ("favicon.gif");	

	for (i=1;i<=12;i++){
		d->piece[0][i] = gtk_image_new_from_file (skins[0][0][i]);
		d->piece[1][i] = gtk_image_new_from_file (skins[0][1][i]);

		g_object_ref (d->piece[0][i]);
		g_object_ref (d->piece[1][i]);
		g_object_ref (d->piece[0][i]);
		g_object_ref (d->piece[1][i]);
	}

	//Reinas
	for(i=1;i<=12;i++)
	{
		d->piece[0][12+i] = gtk_image_new_from_file (skins[0][0][13]);
		d->piece[1][12+i] = gtk_image_new_from_file (skins[0][1][13]);

		g_object_ref (d->piece[0][12+i]);
		g_object_ref (d->piece[1][12+i]);
	}	

	for (i=1;i<=13;i++){
		d->blank[0][i] = gtk_image_new_from_file ("skins/1/ficha_emp.png");
		d->blank[1][i] = gtk_image_new_from_file ("skins/1/ficha_emp.png");	
		g_object_ref (d->blank[0][i]);
		g_object_ref (d->blank[1][i]);
	}


	ibg[0] = gtk_image_new_from_file ( splash[0][0][0][1] );
	ibg[1] = gtk_image_new_from_file ( splash[0][1][0][1] );

	for (i=1;i<=8;i++){
		for (j=1;j<=8;j++){
			if (d->t[i][j] > 0){
				gtk_button_set_image(GTK_BUTTON(d->b[i][j]),d->piece[1][ d->t[i][j] ]);
			}
			else if (d->t[i][j] < 0){
				gtk_button_set_image(GTK_BUTTON(d->b[i][j]),d->piece[0][ (d->t[i][j])*(-1) ]);
			}
			d->blanks[i][j] = gtk_image_new_from_file ("skins/1/ficha_emp.png");
			g_object_ref (d->blanks[i][j]);
		}
	}	

	gtk_button_set_image(GTK_BUTTON(d->b[1][1]), imagen);

	d->barra_ID = gtk_statusbar_get_context_id (GTK_STATUSBAR(d->barra), "");
	

	//-------  3  señales :o ----------

	g_signal_connect(G_OBJECT(ventana), "destroy", G_CALLBACK(salir),NULL);
	
	for (i=1;i<=8;i++){
		for (j=1;j<=8;j++){
			g_signal_connect(G_OBJECT(d->b[i][j]), "clicked",G_CALLBACK(click), d);
			g_signal_connect(G_OBJECT(d->b[i][j]), "enter",G_CALLBACK(entered), d);
			g_signal_connect(G_OBJECT(d->b[i][j]), "leave",G_CALLBACK(leaved), d);
		}
	}

	g_signal_connect(G_OBJECT(it_jugar), "activate" ,G_CALLBACK(New_game), d);

	g_object_set_data(G_OBJECT(d->barra), "info", (gpointer) "1");


	//-------- [4] contenedores ------------

	for (j=1;j<=8;j++){
		for (i=1;i<=8;i++){
			gtk_container_add ( GTK_CONTAINER(d->e[i][j]), d->b[i][j] );
		}
	}

	for (j=1;j<=12;j++){
		gtk_container_add ( GTK_CONTAINER(d->grave[0][j]), d->grab[1][j] );
		gtk_container_add ( GTK_CONTAINER(d->grave[1][j]), d->grab[0][j] );
	}

	gtk_box_pack_start_defaults (GTK_BOX(vbots), lbl);

	gtk_container_add ( GTK_CONTAINER(bg[0]), ibg[0]);
	gtk_container_add ( GTK_CONTAINER(bg[1]), ibg[1]);

	gtk_container_add ( GTK_CONTAINER(d->timeb), vbots);
	
	//TABLE
	
	for (j=1;j<=8;j++){
		for (i=1;i<=8;i++){
			gtk_table_attach_defaults ( GTK_TABLE (d->tab), d->e[i][j], 4+j-1, 4+j, 3+i-1, 3+i);
		}
	}

	//GRAVES	
	for (q=0;q<=1;q++){
		p=1;
		for (i=0;i<=1;i++){
			for (j=0;j<=5;j++){
				gtk_table_attach_defaults ( GTK_TABLE (gravey[q]), d->grave[q][p], 0+j, 1+j, i, i+1); p++;
			}
		}
	}

	//Menus
	
	//Menu jugar
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_jugar), it_jugar);
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_jugar), it_guardar);
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_jugar), it_recuperar);
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_jugar), it_tops);
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_jugar), it_terminar);
	
	gtk_menu_item_set_submenu (GTK_MENU_ITEM(it_juego),menu_jugar);

	//Menu herramientas
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_herramientas), it_undo);
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_herramientas), it_redo);
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_herramientas), it_ayuda);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM(it_herramientas),menu_herramientas);

	//Menu acerca de
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_acercade), it_isuky);
	gtk_menu_shell_append (GTK_MENU_SHELL(menu_acercade), it_atortole);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM(it_acercade),menu_acercade);

	//BarraMenu
	gtk_menu_bar_append (menubar,it_juego);
	gtk_menu_bar_append (menubar,it_herramientas);
	gtk_menu_bar_append (menubar,it_acercade);


	gtk_table_attach_defaults ( GTK_TABLE (d->tab), bg[0], 0, 4, 5, 9);
	gtk_table_attach_defaults ( GTK_TABLE (d->tab), bg[1],12,16, 5, 9);

	gtk_table_attach_defaults ( GTK_TABLE (d->tab), d->timeb, 6 ,10 , 0, 2);

	gtk_table_attach_defaults ( GTK_TABLE (d->tab), gravey[0], 1, 7, 12, 14);
	gtk_table_attach_defaults ( GTK_TABLE (d->tab), gravey[1], 9, 15, 12, 14);

	gtk_table_attach_defaults ( GTK_TABLE (d->tab), d->names[0], 0 , 4 , 4, 5);
	gtk_table_attach_defaults ( GTK_TABLE (d->tab), d->names[1], 12 , 16 , 4, 5);
	
	gtk_box_pack_start_defaults (GTK_BOX(vbox), menubar);
	gtk_box_pack_start_defaults (GTK_BOX(vbox), d->tab);
	gtk_box_pack_start_defaults (GTK_BOX(vbox), d->barra);

	gtk_container_add(GTK_CONTAINER(ventana),vbox);

	// 5
	

	gtk_widget_hide_all(d->w.ante);
	gtk_widget_show_all(ventana);

	// 6
	
	fresh(d);

	//gtk_main();
	
}

