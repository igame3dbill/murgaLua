
	//Some C Stuff
	
	#include <string.h>
	FILE *gParserOutput;
	int pureText=0;
	int brackLevel=0;
	int brackStart=0;
	char widgetIdentifier[65]="";
	char widgetIdentifier2[65]="";
	char widgetType[65]="";
	char crazyParms[256]="";
	char tempStr[256]="";
	char attribData[1024]="";
	int ignoreType=0;
	int breakOnWhiteSpace=0;
	int rectx,recty,recth,rectw;
	#define YY_SKIP_YYWRAP
	int yywrap(void){return 1;}
	
	void yyerror(char *str){}

	#include "y.tab.c"

comment	#.+
identifier	[a-zA-z_][a-zA-Z0-9_]*
integer		\-?[0-9]+
nonEOL	.+
nonCurly	[^\{\}]
float		\-?[0-9]+\.[0-9]+

%%
{comment} if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(COMMENT);}
version{nonEOL} if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(VERSION);}
header_name{nonEOL} if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(HEADER_NAME);}
code_name{nonEOL} if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(CODE_NAME);}
Function if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FUNCTION);}
open if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(OPEN);}
selected if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(SELECTED);}
type if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(TYPE);}
callback if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(CALLBACKF);}
visible if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(VISIBLE);}
xywh if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(XYWH);}

maximum if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(MAXIMUM);}
minimum if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(MINIMUM);}
step if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(STEP);}
value if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(VALUE);}
down\_box if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(DOWN_BOX);}
box if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(BOX);}
labelsize if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(LABELSIZE);}
textsize if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(TEXTSIZE);}
align if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(ALIGN);}
when if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(WHEN);}
resizable if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(RESIZABLE);}
size\_range if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(SIZE_RANGE);}
textfont if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(TEXTFONT);}
labeltype if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(LABELTYPE);}
labelfont if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(LABELFONT);}
labelcolor if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(LABELCOLOR);}
selection\_color if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(SELECTION_COLOR);}
textcolor if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(TEXTCOLOR);}
color if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(COLOR);}


code[0123]\ \{ if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{pureText=1;brackStart=brackLevel-1;return(CODE0);}
code[0123]\  if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{breakOnWhiteSpace=1;pureText=1;return(CODE0);}
code if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{pureText=1;brackStart=brackLevel;return(CODE);}
label\ \{ if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{pureText=1;brackStart=brackLevel-1;return(LABEL);}
label\  if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{breakOnWhiteSpace=1;pureText=1;return(LABEL);}
tooltip\ \{ if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{pureText=1;brackStart=brackLevel-1;return(TOOLTIP);}
tooltip\  if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{breakOnWhiteSpace=1;pureText=1;return(TOOLTIP);}

Fl\_Window if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_WINDOW);}
Fl\_Button if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_BUTTON);}
Fl\_Value_Input if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_VALUE_INPUT);}
Fl\_Browser if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_BROWSER);}
Fl\_Input if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_INPUT);}
Fl\_Check_Button if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_CHECK_BUTTON);}
Fl\_Text\_Display if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_TEXT_DISPLAY);}
Fl\_Output if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_OUTPUT);}
Fl\_Group if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FL_GROUP);}

{identifier} if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(IDENTIFIER);}
{integer} if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(INTEGER);}
{float} if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(FLOATR);}
\{ brackLevel++;if (pureText && brackLevel>brackStart+1){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(LCUR);}
\} brackLevel--;if (pureText && brackLevel==brackStart){pureText=0;};if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(RCUR);}
\( if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(LBRA);}
\) if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{return(RBRA);}
\n if (breakOnWhiteSpace){pureText=0;breakOnWhiteSpace=0;return(RCUR);}if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{}
\  if (breakOnWhiteSpace){pureText=0;breakOnWhiteSpace=0;return(RCUR);}if (pureText && brackLevel>=brackStart+1){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{}
\t if (pureText){fprintf(gParserOutput,yytext);return(NON_CURLY);}else{}
\\\#   fprintf(gParserOutput,"#");
\\\\  fprintf(gParserOutput,"\\");
{nonCurly} fprintf(gParserOutput,yytext);return(NON_CURLY);
%%
void ig3d_ParseFluid(char *fileIn, char *fileOut)
{
	yyin = fopen( fileIn, "r" );
	gParserOutput=fopen(fileOut, "w");
	
	#ifndef IG3D_EMBEDDED_PARSER
	fprintf(gParserOutput, "FLUID_Normal=0\nFLUID_Vertical=0\nFLUID_Dot=0\nFLUID_Integer=0\nFLUID_normal=0\nFLUID_No_Select=0\nFLUID_BOTH=0\nFLUID_Toggle=1\nFLUID_Horizontal=1\nFLUID_Simple=1\nFLUID_Line=1\nFLUID_Float=1\nFLUID_popup1=1\nFLUID_Select=1\nFLUID_HORIZONTAL=1\nFLUID_Vert_Fill=2\nFLUID_Fill=2\nFLUID_Int=2\nFLUID_popup2=2\nFLUID_Hold=2\nFLUID_VERTICAL=2\nFLUID_Horz_Fill=3\nFLUID_popup3=3\nFLUID_Multi=3\nFLUID_Vert_Knob=4\nFLUID_Multiline=4\nFLUID_popup12=4\nFLUID_Horz_Knob=5\nFLUID_Secret=5\nFLUID_popup23=5\nFLUID_HORIZONTAL_ALWAYS=5\nFLUID_popup13=6\nFLUID_VERTICAL_ALWAYS=6\nFLUID_popup123=7\nFLUID_BOTH_ALWAYS=7\nFLUID_Radio=102\n\n");
	#endif
	
	yyparse();
	
	fclose(gParserOutput);
}

#ifndef IG3D_EMBEDDED_PARSER
int main( int argc, char **argv )
    {
    ig3d_ParseFluid(argv[1], argv[2]);
	return 0;
    }
#endif




