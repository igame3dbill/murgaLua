
%token COMMENT VERSION HEADER_NAME CODE_NAME FUNCTION IDENTIFIER LBRA RBRA RCUR LCUR OPEN
CODE SELECTED ANYTHING NON_CURLY INTEGER TYPE VISIBLE XYWH LABEL CALLBACKF LABELSIZE TEXTSIZE ALIGN
FLOATR MAXIMUM MINIMUM STEP VALUE BOX DOWN_BOX WHEN RESIZABLE SIZE_RANGE TEXTFONT TOOLTIP CODE0 COLOR LABELCOLOR LABELTYPE SELECTION_COLOR TEXTCOLOR LABELFONT
FL_WINDOW FL_BUTTON FL_INPUT FL_VALUE_INPUT FL_BROWSER FL_CHECK_BUTTON FL_TEXT_DISPLAY FL_OUTPUT FL_GROUP
%%
start	:	COMMENT VERSION HEADER_NAME CODE_NAME function
			;
function : FUNCTION LCUR {fprintf(gParserOutput, "--function ");} IDENTIFIER {fprintf(gParserOutput, yytext);} LBRA RBRA {fprintf(gParserOutput, "()\n");} RCUR LCUR attriblist RCUR LCUR blocklist RCUR {fprintf(gParserOutput, "\n--end\n");}
	;

blocklist	: block {fprintf(gParserOutput, "\n");} blocklist | block;

block	: CODE LCUR non_curly RCUR LCUR attriblist RCUR
		| {ignoreType=0;widgetType[0]='\0';} widget {if (widgetType[0]=='\0'){sprintf(widgetType, yytext);}} name_or_empty {fprintf(gParserOutput, "do %s= fltk:%s(0,0,0,0,\"\")\n", widgetIdentifier, widgetType);} LCUR attriblist RCUR subwidgetlist {fprintf(gParserOutput, "end\n");}
		| {ignoreType=0;widgetType[0]='\0';} FL_GROUP {if (widgetType[0]=='\0'){sprintf(widgetType, yytext);}} name_or_empty {fprintf(gParserOutput, "do %s= fltk:%s(0,0,0,0,\"\")\n", widgetIdentifier, widgetType);} LCUR attriblist RCUR subwidgetlist {fprintf(gParserOutput, "Fl_Group:current(Fl_Group:current():parent())\nend\n");}
		;

number : FLOATR | INTEGER;

subwidgetlist: LCUR RCUR | LCUR blocklist RCUR |  ;

widget	:	FL_WINDOW {ignoreType=1;sprintf(widgetType, "Fl_Double_Window");} | FL_BUTTON | FL_INPUT | FL_VALUE_INPUT | FL_BROWSER | FL_CHECK_BUTTON | FL_TEXT_DISPLAY | FL_OUTPUT | IDENTIFIER ;
		
attriblist	: attrib attriblist |  ;

attrib			: OPEN | SELECTED | xywh | type | visible | label | callbackf | maximum | minimum | step | value | box | down_box | labelsize | textsize | align | when | resizable | size_range | textfont | tooltip | code0 | color | labelcolor | labeltype | textcolor | selection_color | labelfont | IDENTIFIER {fprintf(gParserOutput, "--unknown attribute: %s\n", yytext);} ;

name_or_empty	: IDENTIFIER {sprintf(widgetIdentifier, yytext);} | LCUR RCUR {sprintf(widgetIdentifier, "widget");};

name_or_empty_two	: IDENTIFIER {sprintf(widgetIdentifier2, yytext);} | LCUR RCUR {widgetIdentifier2[0]='\0';};

name_or_empty_three	: non_curly RCUR;

type	: TYPE LCUR IDENTIFIER {if (!ignoreType){fprintf(gParserOutput, "%s:type(FLUID_%s_", widgetIdentifier, yytext);}} IDENTIFIER {if (!ignoreType){fprintf(gParserOutput, "%s)\n", yytext);}} RCUR | TYPE IDENTIFIER {if (!ignoreType){fprintf(gParserOutput, "%s:type(FLUID_%s)\n", widgetIdentifier, yytext);}} ;

label	: LABEL {fprintf(gParserOutput, "%s:label(\"", widgetIdentifier);} name_or_empty_three {fprintf(gParserOutput, "\")\n");}

tooltip	: TOOLTIP {fprintf(gParserOutput, "%s:tooltip(\"", widgetIdentifier);} name_or_empty_three {fprintf(gParserOutput, "\")\n");}

callbackf	: CALLBACKF {fprintf(gParserOutput, "%s:callback(", widgetIdentifier);} name_or_empty_two {fprintf(gParserOutput, "%s)\n", widgetIdentifier2);}

xywh		: XYWH LCUR INTEGER {rectx=atoi(yytext);} INTEGER {recty=atoi(yytext);} INTEGER {recth=atoi(yytext);} INTEGER {rectw=atoi(yytext);} RCUR {fprintf(gParserOutput, "%s:resize(%d,%d,%d,%d)\n", widgetIdentifier, rectx,recty,recth,rectw);}

minimum	:	MINIMUM number {fprintf(gParserOutput, "%s:minimum(%s)\n", widgetIdentifier, yytext);} ;

maximum	:	MAXIMUM number {fprintf(gParserOutput, "%s:maximum(%s)\n", widgetIdentifier, yytext);} ;

step	:	STEP number {fprintf(gParserOutput, "%s:step(%s)\n", widgetIdentifier, yytext);} ;

value	:	VALUE number {fprintf(gParserOutput, "%s:value(%s)\n", widgetIdentifier, yytext);} ;

textsize: TEXTSIZE INTEGER {fprintf(gParserOutput, "%s:textsize(%s)\n", widgetIdentifier, yytext);} ;

labelsize: LABELSIZE INTEGER {fprintf(gParserOutput, "%s:labelsize(%s)\n", widgetIdentifier, yytext);} ;

align: ALIGN INTEGER {fprintf(gParserOutput, "%s:align(%s)\n", widgetIdentifier, yytext);} ;

visible: VISIBLE {fprintf(gParserOutput, "--%s:show()\n", widgetIdentifier);} ;

when: WHEN INTEGER {fprintf(gParserOutput, "%s:when(%s)\n", widgetIdentifier, yytext);} ;

resizable: RESIZABLE {fprintf(gParserOutput, "Fl_Group:current():resizable(%s)\n", widgetIdentifier);} ;

size_range		: SIZE_RANGE LCUR INTEGER {rectx=atoi(yytext);} INTEGER {recty=atoi(yytext);} INTEGER {recth=atoi(yytext);} INTEGER {rectw=atoi(yytext);} RCUR {fprintf(gParserOutput, "%s:size_range(%d,%d,%d,%d)\n", widgetIdentifier, rectx,recty,recth,rectw);}

textfont: TEXTFONT INTEGER {fprintf(gParserOutput, "%s:textfont(%s)\n", widgetIdentifier, yytext);} ;

labelfont: LABELFONT INTEGER {fprintf(gParserOutput, "%s:labelfont(%s)\n", widgetIdentifier, yytext);} ;

code0	: CODE0 name_or_empty_three {fprintf(gParserOutput, "\n");}

color:	COLOR INTEGER {fprintf(gParserOutput, "%s:color(%s)\n", widgetIdentifier, yytext);} ;

labelcolor:	LABELCOLOR INTEGER {fprintf(gParserOutput, "%s:labelcolor(%s)\n", widgetIdentifier, yytext);} ;

selection_color:	SELECTION_COLOR INTEGER {fprintf(gParserOutput, "%s:selection_color(%s)\n", widgetIdentifier, yytext);} ;

textcolor:	TEXTCOLOR INTEGER {fprintf(gParserOutput, "%s:textcolor(%s)\n", widgetIdentifier, yytext);} ;

			
non_curly	: NON_CURLY | NON_CURLY non_curly;

down_box	: DOWN_BOX IDENTIFIER {fprintf(gParserOutput, "%s:down_box(fltk.FL_%s)\n", widgetIdentifier, yytext);} ;

box	: BOX IDENTIFIER {fprintf(gParserOutput, "%s:box(fltk.FL_%s)\n", widgetIdentifier, yytext);} ;

labeltype	: LABELTYPE IDENTIFIER {fprintf(gParserOutput, "%s:labeltype(fltk.FL_%s)\n", widgetIdentifier, yytext);} ;
%%

