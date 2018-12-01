typedef struct datas{
	GtkWidget *entrada;
}ENTRY;

typedef struct data{
	GtkWidget *barra;
	guint ID;
}BARRA;

typedef struct wind{
	GtkWidget *ante;
}VENTO;

typedef struct col{
	GdkColor rojo,
		 rojo_cla,
		 naranja,
		 azul,
		 verde,
		 blanco,
		 azul_rey,
		 azul_cla,
		 azul_ext,
		 negro;
}COL;

typedef struct dat{
	
	int mode;

	int turn;
	int rage;
	int rag[9][9];
	int boba;
	int bmov[5];
	int t[10][10];
	int gra[2][13];
	int grac[2];
	int x,y;
	int sx,sy;
	int ax,ay;
	int ss[2][9];

	char name[2][20];

	GtkWidget *barra;
	guint barra_ID;

	GtkWidget *timeb;
	GtkWidget *tab;
	GtkWidget *b[9][9];
	GtkWidget *e[9][9];
	GtkWidget *piece[2][25];
	GtkWidget *blank[2][14];
	GtkWidget *blanks[9][9];
	GtkWidget *grave[2][14];
	GtkWidget *grab[2][14];
	GtkWidget *names[2];

	GtkWidget *bc1, *bc2;
	GtkWidget *entry1, *entry2;

	VENTO w;

	COL color;
}DATA;

#define NUL 9
   	


	
