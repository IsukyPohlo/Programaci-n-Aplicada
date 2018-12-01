#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <string.h>
#include "strct.h"

void showmov(gpointer info);
extern void fresh (gpointer info);

//	MOSTRAR POSIBLES POSICIONES Y MOVERSE
void showmov(gpointer info){
	
	DATA *d = (DATA *) info;

	int i, j, p ,q;

	//SELECCIONAR
	if (d->t[d->y][d->x] != 0 && ( d->sx == NUL  || d->sy == NUL) )
	{
		
	//g_print ("1 *\n");
	//if ( (d->turn == 1 && d->t[d->y][d->x]<0 ) || (d->turn == 2 && d->t[d->y][d->x]>0 ))
	
		d->sx=d->x;
		d->sy=d->y;

		g_print ("\nd%d,%dd\n",d->sx,d->sy);
	
		for (i=1;i<=8;i++)
		{
			d->ss[0][i] = NUL;
			d->ss[1][i] = NUL;
		}

		d->ax=NUL;
		d->ay=NUL;

		for (i=1;i<=8;i++)
		{
			for (j=1;j<=8;j++)
			{
				if (d->rag[j][i] == 1){
					g_print ("\n%dsb%d,%dsb",d->boba,i,j);
				}
			}
		}
	
		//MAS DE UNA BOBA EN EL ANTERIOR TURNO?
		if (d->boba > 1)
		{
			g_print ("HAY BOBAS");
			//CHECAR CUAL BOBA SE SELECCIONO
			for (i=1;i<=8;i++)
			{
				for (j=1;j<=8;j++)
				{
					if (d->rag[j][i] == 1 &&  (d->sx == i  && d->sy == j) )
					{
						break;
					}
				}
				if (d->rag[j][i] == 1 &&  (d->sx == i  && d->sy == j) )
				{
						//CEMENTERIO 
					if (d->t[d->y][d->x] < 0)
					{
						d->grac[0]++;
						d->gra[0][ d->grac[0] ] = d->t[d->y][d->x]; g_print ("+%dBOBASx%d[%d,%d]\n",d->boba,d->t[d->y][d->x],d->x,d->y);
					}
					if (d->t[d->y][d->x] > 0)
					{
						d->grac[1]++;
						d->gra[1][ d->grac[1] ] = d->t[d->y][d->x]; g_print ("+%dBOBASx%d[%d,%d]\n",d->boba,d->t[d->y][d->x],d->x,d->y);
					}
					
					d->t[d->y][d->x] = 0; g_print ("+BOBASx\n");
					d->boba=0;
					for (q=1;q<=8;q++)
					{
						for (p=1;p<=8;p++)
						{
							d->rag[q][p] = 0;
						}
					}
					
					if (d->turn == 1)
						d->turn = 2;
					else if (d->turn == 2)
						d->turn = 1;
					//MOVERSE
					// Ficha [Posicion final] (0) = Ficha [Posicion inicial] 
					d->t[d->bmov[0]][d->bmov[1]] = d->t[d->bmov[2]][d->bmov[3]];g_print ("MOVEB 1\n");
					//Ficha [Posicion inicial] = 0
					d->t[d->bmov[2]][d->bmov[3]] = 0;	g_print ("MOVEB 2\n");
					g_print("(%d) %dBmov%d\n",d->turn,d->t[d->bmov[0]][d->bmov[1]],d->t[d->bmov[2]][d->bmov[3]]);
					fresh(info);
					break;
				}
			}
			for (q=1;q<=8;q++)
			{
				for (p=1;p<=8;p++)
				{
					d->rag[q][p] = 0;
				}
			}
		}
		else
		{
			//REINICIAR BOBAS
			d->boba=0;
			for (i=1;i<=8;i++)
			{
				for (j=1;j<=8;j++)
				{
					d->rag[j][i] = 0;
				}
			}
		}
		
		g_print ("\n|%d|%d[%d,%d]",d->turn,d->t[d->sy][d->sx],d->sx,d->sy);

		//g_print ("2* \n");

		//ACTUALIZAR COLOR

		if ((d->turn == 1 && d->t[d->sy][d->sx] < 0) || (d->turn == 2 && d->t[d->sy][d->sx] >0) )
		{
			gtk_button_set_relief(GTK_BUTTON(d->b[d->sy][d->sx]),  GTK_RELIEF_NORMAL);
			gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy][d->sx]), GTK_STATE_NORMAL, &(d->color.verde) );
			//g_print ("3* \n");
		}

		//MOSTRAR POSIBLES MOVIMIENTOS, ATAQUES Y BOBAS

		

						
		//abajo ( 1 ) o reina 2
		if (  ( (d->turn==1 && d->t[d->sy][d->sx] < 0) || (d->turn==2 && d->t[d->sy][d->sx] > 12) ) && (d->sy<8))
		{
			g_print("DOWN1\n");
			//BUSCAR BOBAS TURNO 1 NO REINA 2
			for (j=1;j<7;j++)
			{				
				for (i=1;i<7;i++)
				{
					//Buscar Derecha
					if (d->t[j+2][i+2] == 0)
					{
						if ( (d->turn==1 && d->t[j][i]<0 && d->t[j+1][i+1]>0) || (d->turn==2 &&d->t[j][i]>0 && d->t[j+1][i+1]<0) )
						{
							//if (i != d->sx && j != d->sy)
						
							d->rag[j][i] = 1;
							d->boba++;
							g_print ("\nadB%d,%dB",i,j);
							if (d->t[j][i] != d->t[d->sy][d->sx])
								gtk_widget_modify_bg (GTK_WIDGET(d->b[j][i]),  GTK_STATE_PRELIGHT, &(d->color.negro) );
			 			}
					}
				}
				for (i=3;i<=8;i++)
				{
					//Buscar Izquierda
					if (d->t[j+2][i-2] == 0)
					{
						if ( (d->turn==1 && d->t[j][i]<0 && d->t[j+1][i-1]>0) || (d->turn== 2 && d->t[j][i]>0 && d->t[j+1][i-1]<0) )
						{
							//if (i != d->sx && j != d->sy)
							 
							d->rag[j][i] = 1;
							d->boba++;
							g_print ("\naiB%d,%dB",i,j);
							if (d->t[j][i] != d->t[d->sy][d->sx])
								gtk_widget_modify_bg (GTK_WIDGET(d->b[j][i]),  GTK_STATE_PRELIGHT, &(d->color.negro) );
						}
					}
				}

			}
		
		
		
			//MOVEEEEE
			if (d->sy < 8)
			{
				//derecha
				if (d->sx < 8)
				{
					g_print ("\n[>] ?%d,%d?",d->sx+1,d->sy+1);
					if (d->t[d->sy+1][d->sx+1] == 0)
					{
						gtk_button_set_relief (GTK_BUTTON(d->b[d->sy+1][d->sx+1]),  GTK_RELIEF_NORMAL);
						gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy+1][d->sx+1]), GTK_STATE_NORMAL, &(d->color.verde) );
						gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy+1][d->sx+1]), GTK_STATE_PRELIGHT, &(d->color.verde) );
						d->ss[0][1]=d->sx+1;
						d->ss[1][1]=d->sy+1;
			 			g_print (" >\n");
					}
				}
				//izquierda
				if (d->sx > 1)
				{
					g_print ("\n[<] ?%d,%d?",d->sx-1,d->sy+1);
					if (d->t[d->sy+1][d->sx-1] == 0)
					{
						gtk_button_set_relief (GTK_BUTTON(d->b[d->sy+1][d->sx-1]),  GTK_RELIEF_NORMAL);
						gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy+1][d->sx-1]), GTK_STATE_NORMAL, &(d->color.verde) );
						gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy+1][d->sx-1]), GTK_STATE_PRELIGHT, &(d->color.verde) );
						d->ss[0][2]=d->sx-1;
						d->ss[1][2]=d->sy+1;
						g_print (" <\n");
					}
				}
			}
			
			//ATT
			if (d->sy < 7)
			{
				//derecha
				if (d->sx < 7)
				{
					//g_print ("\n[>] ?%d,%d?",d->sx+1,d->sy+1);
					if (d->t[d->sy+2][d->sx+2] == 0)
					{	
						if ((d->t[d->sy][d->sx]<0 && d->t[d->sy+1][d->sx+1]>0) || ((d->t[d->sy][d->sx]>0 && d->t[d->sy+1][d->sx+1]<0)) )
						{
							gtk_button_set_relief (GTK_BUTTON(d->b[d->sy+2][d->sx+2]),  GTK_RELIEF_NORMAL);
							gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy+2][d->sx+2]), GTK_STATE_NORMAL, &(d->color.naranja) );
							gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy+2][d->sx+2]), GTK_STATE_PRELIGHT, &(d->color.naranja) );
							d->ss[0][5]=d->sx+2;
							d->ss[1][5]=d->sy+2;
							d->ax=d->sx+1;
							d->ay=d->sy+1;
							g_print ("ATad\n");
			 			}
					}
				}
				//izquierda
				if (d->sx > 2)
				{
					//g_print ("\n[<] ?%d,%d?",d->sx-1,d->sy+1);
					if (d->t[d->sy+2][d->sx-2] == 0)
					{
						if ((d->t[d->sy][d->sx]<0 && d->t[d->sy+1][d->sx-1]>0) || ((d->t[d->sy][d->sx]>0 && d->t[d->sy+1][d->sx-1]<0)) )
						{
							gtk_button_set_relief (GTK_BUTTON(d->b[d->sy+2][d->sx-2]),  GTK_RELIEF_NORMAL);
							gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy+2][d->sx-2]), GTK_STATE_NORMAL, &(d->color.naranja) );
							gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy+2][d->sx-2]), GTK_STATE_PRELIGHT, &(d->color.naranja) );
							d->ss[0][6]=d->sx-2;
							d->ss[1][6]=d->sy+2;
							d->ax=d->sx-1;
							d->ay=d->sy+1;
							g_print ("ATai\n");
						}
					}
				}
			}
		}
		//arriba ( 2 ) y reina 1
		if (  ( (d->turn == 2 && d->t[d->sy][d->sx] > 0) || (d->turn==1 && d->t[d->sy][d->sx] <- 12) )  &&  (d->sy>1))
		{
		g_print("UP2\n");
			//BUSCAR BOBAS TURNO 2 y REINA 1
			for (j=3;j<=8;j++)
			{				
				for (i=1;i<7;i++)
				{
					//Buscar Derecha
					if (d->t[j-2][i+2] == 0)
					{	
						if ( (d->turn==1 && d->t[j][i]<0 && d->t[j-1][i+1]>0) || (d->turn==2 && d->t[j][i]>0 && d->t[j-1][i+1]<0) )
						{
							d->rag[j][i] = 1;
							d->boba++;
							g_print ("\nAdB%d,%dB",i,j);
							if (d->t[j][i] != d->t[d->sy][d->sx])
								gtk_widget_modify_bg (GTK_WIDGET(d->b[j][i]),  GTK_STATE_PRELIGHT, &(d->color.negro) );
						
			 			}
					}
				
				}
				for (i=3;i<=8;i++)
				{
					//Buscar Izquierda
					if (d->t[j-2][i-2] == 0)
					{
						if ( (d->turn==1 && d->t[j][i]<0 && d->t[j-1][i-1]>0) || (d->turn==2 && d->t[j][i]>0 && d->t[j-1][i-1]<0) )
						{
							//if (i != d->sx && j != d->sy)
							 
							d->rag[j][i] = 1;
							d->boba++;
							g_print ("\nAiB%d,%dB",i,j);
							if (d->t[j][i] != d->t[d->sy][d->sx])
								gtk_widget_modify_bg (GTK_WIDGET(d->b[j][i]),  GTK_STATE_PRELIGHT, &(d->color.negro) );
												
						}	
					}	
				}
			}				
			//MOVEEEEEEEEEEEe
			if (d->sy > 0)
			{
				//derecha
				if (d->sx < 8)
				{
					g_print ("\n[>] ?%d,%d?",d->sx+1,d->sy-1);
					if (d->t[d->sy-1][d->sx+1] == 0)
					{
						gtk_button_set_relief (GTK_BUTTON(d->b[d->sy-1][d->sx+1]),  GTK_RELIEF_NORMAL);
						gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy-1][d->sx+1]), GTK_STATE_NORMAL, &(d->color.verde) );
						gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy-1][d->sx+1]), GTK_STATE_PRELIGHT, &(d->color.verde) );
						d->ss[0][3]=d->sx+1;
						d->ss[1][3]=d->sy-1;
						g_print (">\n");
					}
				}
				//izquierda
				if (d->sx > 1)
				{
					g_print ("\n[<] ?%d,%d?",d->sx-1,d->sy-1);
					if (d->t[d->sy-1][d->sx-1] == 0)
					{
						gtk_button_set_relief (GTK_BUTTON(d->b[d->sy-1][d->sx-1]),  GTK_RELIEF_NORMAL);
						gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy-1][d->sx-1]), GTK_STATE_NORMAL, &(d->color.verde) );
						gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy-1][d->sx-1]), GTK_STATE_PRELIGHT, &(d->color.verde) );
						d->ss[0][4]=d->sx-1;
						d->ss[1][4]=d->sy-1;
						g_print ("<\n");
					}
				}
			}
		
			//ATT
			if (d->sy > 2)
			{
				//derecha
				if (d->sx < 7)
				{
					//g_print ("\n[>] ?%d,%d?",d->sx+1,d->sy+1);
					if (d->t[d->sy-2][d->sx+2] == 0)
					{
						if ((d->t[d->sy][d->sx]<0 && d->t[d->sy-1][d->sx+1]>0) || ((d->t[d->sy][d->sx]>0 && d->t[d->sy-1][d->sx+1]<0)) )
						{
							gtk_button_set_relief (GTK_BUTTON(d->b[d->sy-2][d->sx+2]),  GTK_RELIEF_NORMAL);
							gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy-2][d->sx+2]), GTK_STATE_NORMAL, &(d->color.naranja) );
							gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy-2][d->sx+2]), GTK_STATE_PRELIGHT, &(d->color.naranja) );
							d->ss[0][7]=d->sx+2;
							d->ss[1][7]=d->sy-2;
							d->ax=d->sx+1;
							d->ay=d->sy-1;
							g_print ("ATAd\n");
			 			}
					}
				}
				//izquierda
				if (d->sx > 2)
				{
					//g_print ("\n[<] ?%d,%d?",d->sx-1,d->sy+1);
					if (d->t[d->sy-2][d->sx-2] == 0)
					{
						if ((d->t[d->sy][d->sx]<0 && d->t[d->sy-1][d->sx-1]>0) || ((d->t[d->sy][d->sx]>0 && d->t[d->sy-1][d->sx-1]<0)) )
						{
							gtk_button_set_relief (GTK_BUTTON(d->b[d->sy-2][d->sx-2]),  GTK_RELIEF_NORMAL);
							gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy-2][d->sx-2]), GTK_STATE_NORMAL, &(d->color.naranja) );
							gtk_widget_modify_bg (GTK_WIDGET(d->b[d->sy-2][d->sx-2]), GTK_STATE_PRELIGHT, &(d->color.naranja) );
							d->ss[0][8]=d->sx-2;
							d->ss[1][8]=d->sy-2;
							d->ax=d->sx-1;
							d->ay=d->sy-1;
							g_print ("ATAi\n");
						}
					}
				}
			}
		}//ATT
	}
	else
	{
		//Hay alguna ficha seleccionada?
		if (d->sx != NUL || d->sy != NUL )
		{
			//MOVEEEEEEEEEEEEEEEEEEEEE!
			//Buscar en primeras 4 coordenadas (moverse)
			for (i=1;i<=4;i++)
			{
				//Click en alguna teja que coincide con alguna de las primeras 4 coordenadas (moverse) ? 
				if (d->x == d->ss[0][i] && d->y == d->ss[1][i])
				{	g_print ("Bobas:%d\n",d->boba);				
					g_print ("MOVE\n");
					//Hay mas de alguna boba? 
					if (d->boba > 1)
					{
						//MOSTRAR OPCIONES DE BOBA
						for (q=1;q<=8;q++)
						{
							for (p=1;p<=8;p++)
							{
								if (d->rag[q][p]==1)
								{
									g_print ("OP%d,%dOP\n",p,q);
									gtk_button_set_relief (GTK_BUTTON(d->b[q][p]),  GTK_RELIEF_NORMAL);
									gtk_widget_modify_bg (GTK_WIDGET(d->b[q][p]), GTK_STATE_NORMAL, &(d->color.negro) );
								}
							}
						}
						//VARS PARA BOBMOV
						d->bmov[0]=d->y;
						d->bmov[1]=d->x;
						d->bmov[2]=d->sy;
						d->bmov[3]=d->sx;
						//fresh(info);
					}
					else 
					{
						if (d->boba == 1)
						{
							g_print (" 1 BOBA \n");
						
							//Buscar boba

							for (q=1;q<=8;q++)
							{
								for (p=1;p<=8;p++)
								{
									if (d->rag[p][q] == 1)
									break;
								}
								if (d->rag[p][q] == 1)
								{
									//Eliminar boba / Agregar a cementerio

									g_print ("bobs %d[%d,%d]\n",d->t[p][q],q,p);
	
									if (d->t[p][q] < 0)
									{
										d->grac[0]++;
										d->gra[0][ d->grac[0] ] = d->t[p][q]; g_print ("BOBA %d\n",d->t[p][q]);
									}
									if (d->t[p][q] > 0)
									{
										d->grac[1]++;
										d->gra[1][ d->grac[1] ] = d->t[p][q]; g_print ("BOBA %d\n",d->t[p][q]);
									}
									d->t[p][q] = 0;
									fresh(info);	
									break;
								}
							}
						}
					
						// Ficha [Posicion final] (0) = Ficha [Posicion inicial] 
						d->t[d->y][d->x] = d->t[d->sy][d->sx];g_print ("MOVE 1\n");
						//Ficha [Posicion inicial] = 0
						d->t[d->sy][d->sx] = 0;	g_print ("MOVE 2\n");
						g_print("(%d) %d>%d\n",d->turn,d->t[d->y][d->x],d->t[d->sy][d->sx]);
						fresh(info);
						//Reiniciar bobas
						for (q=1;q<=8;q++)
						{
							for (p=1;p<=8;p++)
							{
								d->rag[p][q]=0;
							}
						}
						if (d->turn == 1)
							d->turn = 2;
						else if (d->turn == 2)
							d->turn = 1;
						fresh(info);
						break;
					}
				}
				
			}
			for (i=5;i<=8;i++)
			{
				g_print ("%d/%d=[%d,%d]x%d.%d (%d)\n",d->ss[0][i],d->ss[1][i],d->x,d->y,d->ax,d->ay,d->t[d->ay][d->ax]);
				//Attack!
				if (d->x==d->ss[0][i] && d->y==d->ss[1][i])
				{					
					g_print ("ATTACK\n");
						d->boba=0;
				
					//Limpiar bobas

					for (q=1;q<=8;q++)
					{
						for (p=1;p<=8;p++)
						{
							d->rag[q][p] = 0;
						}
					}

					g_print("(%d) %d[%d,%d] < %d[%d,%d] x %d[%d,%d]\n",d->turn,d->t[d->y][d->x],d->x,d->y,d->t[d->sy][d->sx],d->sx,d->sy,d->t[d->ay][d->ax],d->ax,d->ay);
					//Movimiento
					d->t[d->y][d->x] = d->t[d->sy][d->sx]; g_print ("ATTACK 1\n");
					//Eliminar ficha / Agregar a cementerio
					if (d->t[d->ay][d->ax] < 0)
					{
						d->grac[0]++;
						d->gra[0][ d->grac[0] ] = d->t[d->ay][d->ax]; g_print ("DEL %d\n",d->t[d->ay][d->ax]);
					}
					if (d->t[d->ay][d->ax] > 0)
					{
						d->grac[1]++;
						d->gra[1][ d->grac[1] ] = d->t[d->ay][d->ax]; g_print ("DEL %d\n",d->t[d->ay][d->ax]);
					}
					
					d->t[d->ay][d->ax] = 0; g_print ("ATTACK 2\n");
					d->t[d->sy][d->sx] = 0;
					
					for (j=1;j<=12;j++)
					{
						g_print ("%d|%d\n",d->gra[0][j],d->gra[1][j]);
					}
					fresh(d);
					
					if (d->turn == 1)
						d->turn = 2;
					else if (d->turn == 2)
						d->turn = 1;
					}
				}
			}
		}
		d->sx=NUL;
		d->sy=NUL;
		
		g_print ("DAMN");
		for (i=1;i<=8;i++)
		{
			d->ss[0][i]=NUL;
			d->ss[0][i]=NUL;
		}
		
	}

	//ACTUALIZAR BOBAS  
	for (i=1;i<=8;i++)
	{
		for (j=1;j<=8;j++)
		{
			if (d->rag[j][i] == 1)
			{
				g_print ("\n%dsb%d,%dsb",d->boba,i,j);
			}
		}
	}

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
				else if (d->t[i][j] == 0){ 
					gtk_button_set_image( GTK_BUTTON(d->b[i][j]) , (d->blanks[i][j]) );
				}
			}
		}	
	}

}
