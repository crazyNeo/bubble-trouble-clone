//starting.cpp

#include "headers/starting.hpp"
#include "cstring"
char* starting()
{

	//for gui
    gui_fg_color = makecol(0, 0, 0);
	gui_mg_color = makecol(128, 128, 128 );
	gui_bg_color = makecol(230, 220, 210 );
	char ipadd[16] = "";

     DIALOG get_dialog[] =
	{
		// *proc		x	y	w	h	fg	bg	key	flags	    d1	d2	dp						dp2		dp3
		{ d_clear_proc,	0,	0,	0,	0,	0,	0,	0,	0,		    0,	0,	NULL,					NULL,	NULL },
		{ d_button_proc,70,280,120,16,	0,	0,	0,	D_EXIT,		0,	0,	(void*)"Single Player",			NULL,	NULL },
		{ d_text_proc,	80,200,0,	0,	0,	0,	0,	0,			0,	0,	(void*)"Enter Server IP address",	NULL,NULL},
//		{ d_textbox_proc,80,225,100,16,	0,	0,	0,	0,			0,	0,	(void*)"",				NULL,	NULL },
		{ d_shadow_box_proc,80,225,100,16,	0,	0,	0,	0,			0,	0,	(void*)"",				NULL,	NULL },
		{ d_edit_proc,	85,	230,90,16,	0,	0,	0,	D_EXIT,		20,0,	(void*)ipadd,   		NULL,	NULL },
//		{ d_button_proc,90,250,60,16,	0,	0,	0,	D_EXIT,		0,	0,	(void*)"OK",			NULL,	NULL },
		{ d_button_proc,90,300,60,16,	0,	0,	0,	D_EXIT,		0,	0,	(void*)"Server",			NULL,	NULL },
		{ d_button_proc,190,300,60,16,	0,	0,	0,	D_EXIT,		0,	0,	(void*)"Client",			NULL,	NULL },
		{ d_button_proc,100,320,60,16,	0,	0,	0,	D_EXIT,		0,	0,	(void*)"Exit",			NULL,	NULL },
		{ d_yield_proc, 0,	0,	0,	0,	0,	0,	0,	0,			0,	0,	NULL,	       			NULL,	NULL },
		{ NULL,			0,	0,	0,	0,	0,	0,	0,	0,			0,	0,	NULL,					NULL,	NULL },
	};
	bool condt = false;
	do
	{
    	set_dialog_color( get_dialog, gui_fg_color, gui_bg_color );
    	do_dialog(get_dialog,3);
    	
	    if ( get_dialog[7].flags == SELECTED_BEFORE_EXIT )
	    {
            //int a =thr_id[0];
            //if ( a != -1) pthread_cancel( startNetwork );
    		exit( EXIT_SUCCESS );
        }
        else if (get_dialog[1].flags == SELECTED_BEFORE_EXIT )
        {
             return "0";
        }
        else if (get_dialog[4].flags == SELECTED_BEFORE_EXIT )
        {
             
        }
/*    	else if ( strlen(ipadd) <3 )
    	{
             get_dialog[3].flags = D_EXIT;
             get_dialog[4].flags = D_EXIT;
             get_dialog[5].flags = D_EXIT;
             condt = true;
             allegro_message("Username should be atleast 4 characters");
        }*/
    } while ( condt );
	return (ipadd );
}
