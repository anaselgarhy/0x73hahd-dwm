#include "layouts.h"

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(CHAIN,KEY,TAG) \
	{ MODKEY,                       CHAIN,    KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           CHAIN,    KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             CHAIN,    KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, CHAIN,    KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char dmenufont[]       = "monospace:size=10";
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "konsole", NULL };


static const Key keys[] = {
		/* modifier                     chain key   key        function        argument */
		{ MODKEY,                       -1,         XK_p,      spawn,          {.v = dmenucmd } },
		{ MODKEY|ShiftMask,             -1,         XK_Return, spawn,          {.v = termcmd } },
		{ MODKEY,                       -1,         XK_b,      togglebar,      {0} },
		{ MODKEY,                       -1,         XK_j,      focusstack,     {.i = +1 } },
		{ MODKEY,                       -1,         XK_k,      focusstack,     {.i = -1 } },
		{ MODKEY,                       -1,         XK_i,      incnmaster,     {.i = +1 } },
		{ MODKEY,                       -1,         XK_d,      incnmaster,     {.i = -1 } },
		{ MODKEY,                       -1,         XK_h,      setmfact,       {.f = -0.05} },
		{ MODKEY,                       -1,         XK_l,      setmfact,       {.f = +0.05} },
		{ MODKEY,                       -1,         XK_Return, zoom,           {0} },
		{ MODKEY,                       -1,         XK_Tab,    view,           {0} },
		{ MODKEY|ShiftMask,             -1,         XK_c,      killclient,     {0} },
		{ MODKEY,                       -1,         XK_t,      setlayout,      {.v = &layouts[0]} },
		{ MODKEY,                       -1,         XK_f,      setlayout,      {.v = &layouts[1]} },
		{ MODKEY,                       -1,         XK_m,      setlayout,      {.v = &layouts[2]} },
		{ MODKEY,                       -1,         XK_space,  setlayout,      {0} },
		{ MODKEY|ShiftMask,             -1,         XK_space,  togglefloating, {0} },
		{ MODKEY,                       -1,         XK_0,      view,           {.ui = ~0 } },
		{ MODKEY|ShiftMask,             -1,         XK_0,      tag,            {.ui = ~0 } },
		{ MODKEY,                       -1,         XK_comma,  focusmon,       {.i = -1 } },
		{ MODKEY,                       -1,         XK_period, focusmon,       {.i = +1 } },
		{ MODKEY|ShiftMask,             -1,         XK_comma,  tagmon,         {.i = -1 } },
		{ MODKEY|ShiftMask,             -1,         XK_period, tagmon,         {.i = +1 } },
		
		TAGKEYS(                        -1,         XK_1,                      0)
		TAGKEYS(                        -1,         XK_2,                      1)
		TAGKEYS(                        -1,         XK_3,                      2)
		TAGKEYS(                        -1,         XK_4,                      3)
		TAGKEYS(                        -1,         XK_5,                      4)
		TAGKEYS(                        -1,         XK_6,                      5)
		TAGKEYS(                        -1,         XK_7,                      6)
		TAGKEYS(                        -1,         XK_8,                      7)
		TAGKEYS(                        -1,         XK_9,                      8)
		
		{ MODKEY|ShiftMask,             -1,         XK_q,      quit,           {0} },
		{ MODKEY,                       XK_a,       XK_d,      spawn,          {.v = dmenucmd } },
		{ MODKEY,                       XK_a,       XK_t,      spawn,          {.v = termcmd } },
	    { MODKEY|ControlMask|ShiftMask, -1,         XK_q,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
