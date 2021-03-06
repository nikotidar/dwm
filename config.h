/*
� * pacthes
 */

#include "restart.c"
#include "moveresize.c"

// Appearance
static const char font[]            		= "tewi:size=9";

static const char normbordercolor[] 		= "#2b3135";
static const char selbordercolor[]  		= "#4c5356";

static const char normbgcolor[]     		= "#121417";
static const char selbgcolor[]      		= "#2B3135";

static const char normfgcolor[]     		= "#DEDED6";
static const char selfgcolor[]      		= "#DEDED6";

static const unsigned int borderpx  		= 1;
static const unsigned int snap      		= 5;
static const unsigned int barpadding		= 10;
static const unsigned int gappx     		= 1;
static const Bool showbar           		= True;
static const Bool topbar            		= True;

// Tags
static const char *tags[] = { " main ", " dev ", " chat ", " media ", " misc "};

static const Rule rules[] = {
	// class       instance      title     tags mask     isfloating    monitor
	{ "Gcolor2",     NULL,       NULL,       0,            True,        -1 },
  { "Thunar",      NULL,       NULL,       0,            True,        -1 },
	{ "Viewnior",    NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",     NULL,       NULL,       1,            False,       -1 },
};

// Layouts
static const float mfact      = 0.55;
static const int nmaster      = 1;
static const Bool resizehints = False;

static const Layout layouts[] = {
	{ " [T] ",  tile },
	{ " [M] ",  monocle },
	{ " [F] ",  NULL },
	{ " |M| ",      centeredmaster },
	{ " >M> ",      centeredfloatingmaster },
};

// Key Definitions
#define MODKEY Mod4Mask
#define WINKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

// helper
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// commands
//static const char *runcmd = { "dmenu2_run", "-i", "-b", "-h", "20", "-class", "dmenu", -p "'FreeBSD > '", NULL };
//static const char *termcmd = { "urxvtc", NULL };

static Key keys[] = {
//	{ MODKEY,						XK_d, 			spawn,				{.v = runcmd } },
//	{ MODKEY|ShiftMask,				XK_Return,		spawn,				{.v = termcmd } },
	{ MODKEY,                       XK_t,           setlayout,      	{.v = &layouts[0]} },
	{ MODKEY,                       XK_m,           setlayout,      	{.v = &layouts[1]} },
	{ MODKEY,                       XK_f,     		setlayout,      	{.v = &layouts[2]} },
	{ MODKEY,                       XK_u,           setlayout,          {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,           setlayout,          {.v = &layouts[4]} },
	{ MODKEY,                       XK_equal,       incnmaster,     	{.i = +1 } },
	{ MODKEY,                       XK_minus,       incnmaster,     	{.i = -1 } },
	{ MODKEY,                       XK_Return, 		zoom,           	{0} },
	{ MODKEY,                       XK_h,           setmfact,       	{.f = -0.02} },
	{ MODKEY,                       XK_l,           setmfact,       	{.f = +0.02} },
	{ MODKEY,			            XK_space,       togglefloating, 	{0} },
	{ MODKEY,                       XK_b,           togglebar,      	{0} },
	{ MODKEY,                       XK_Tab,         focusstack,     	{.i = +1 } },
	{ MODKEY|ShiftMask,		        XK_c,          	killclient,     	{0} },
	TAGKEYS(                        XK_1,                            	0)
	TAGKEYS(                        XK_2,                            	1)
	TAGKEYS(                        XK_3,                            	2)
	TAGKEYS(                        XK_4,                            	3)
	TAGKEYS(						XK_5,								4)
	{ MODKEY|ShiftMask,             XK_q,           quit,           	{0} },
	{ MODKEY|ShiftMask, 			XK_r, 			restart, 			{0} },

    /* Move */
    { MODKEY,                       XK_Down,        moveresize,         {.v = "0x 25y 0w 0h"}},
    { MODKEY,                       XK_Up,          moveresize,         {.v = "0x -2y 0w 0h"}},
    { MODKEY,                       XK_Right,       moveresize,         {.v = "25x 0y 0w 0h"}},
    { MODKEY,                       XK_Left,        moveresize,         {.v = "-25x 0y 0w 0h"}},

    /* resize */
    { MODKEY|ShiftMask,             XK_Down,        moveresize,         {.v = "0x 0y 0w 25h"}},
    { MODKEY|ShiftMask,             XK_Up,          moveresize,         {.v = "0x 0y 0w -25h"}},
    { MODKEY|ShiftMask,             XK_Right,       moveresize,         {.v = "0x 0y 25w 0h"}},
    { MODKEY|ShiftMask,             XK_Left,        moveresize,         {.v = "0x 0y -25w 0h"}},
};

// Button Definitions
static Button buttons[] = {
	// click                event mask      button          function        argument
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};
