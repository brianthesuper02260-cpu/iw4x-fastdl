#define WHITE						1 1 1
#define BLACK						0 0 0
#define EXISTS( var )				localVarString( var ) != ""
#define LOCALISE( string )			"@" + string
#define true						1
#define false						0
#define REDUX_STRINGIFY_INNER( value )	#value
#define REDUX_STRINGIFY( value )		REDUX_STRINGIFY_INNER( value )

#define CHOICE_GAMEPAD_Y			10
#define CHOICE_X_START				160
#define CHOICE_Y_START				112
#define CHOICE_X_SIZE				320
#define CHOICE_Y_SIZE				22
#define CHOICE_X_SPACING			( CHOICE_X_SIZE + 12 )
#define CHOICE_Y_SPACING			( CHOICE_Y_SIZE + 2 )
#define CHOICE_ROW( idx )			( ( idx - 0 ) % 24 )
#define CHOICE_COL( idx )			( ( idx - 0 - ( ( idx - 0 ) % 24 ) ) / 24 )
#define CHOICE_Y_TEXTALIGN			0
#define REDUX_TITLE_TEXTSCALE		0.56
#define REDUX_OPTION_TEXTSCALE		0.285
#define REDUX_FEEDBACK_TEXTSCALE	0.275
#define REDUX_TEXTSTYLE			3
#define REDUX_PANEL_DARK			0 0 0 0
#define REDUX_PANEL_EDGE			0.90 0.63 0.20 0.00
#define REDUX_TITLE_COLOR			1.00 0.70 0.28 1
#define REDUX_TITLE_GLOW			1.00 0.70 0.28 0.16
#define REDUX_TEXT_COLOR			0.90 0.90 0.90 0.98
#define REDUX_TEXT_FOCUS			1 1 1 1
#define REDUX_TEXT_DISABLED		0.52 0.52 0.52 0.46
#define REDUX_OUTLINE_COLOR		0 0 0 0.24
#define REDUX_GLOW_IDLE			1.00 0.70 0.28 0
#define REDUX_GLOW_FOCUS			1.00 0.74 0.32 0.32
#define REDUX_BUTTON_FILL			0 0 0 0.40
#define REDUX_BUTTON_FILL_FOCUS		1.00 0.70 0.28 0.92
#define REDUX_BUTTON_EDGE			1.00 0.70 0.28 0.14
#define REDUX_BUTTON_EDGE_FOCUS		1.00 0.76 0.36 1
#define REDUX_BUTTON_EDGE_HIDDEN	1.00 0.70 0.28 0
#define REDUX_BUTTON_BAR			0 0 0 0
#define REDUX_BUTTON_GLOW			1.00 0.70 0.28 0
#define REDUX_BUTTON_GLOW_FOCUS		1.00 0.70 0.28 0.20
#define REDUX_BUTTON_SIDE_INSET		8
#define REDUX_BUTTON_EDGE_FADE		24
#define REDUX_BUTTON_BORDER_WIDTH	1
#define REDUX_BUTTON_WIDTH			( CHOICE_X_SIZE - ( REDUX_BUTTON_SIDE_INSET * 2 ) )
#define REDUX_BUTTON_CENTER_WIDTH	( REDUX_BUTTON_WIDTH - ( REDUX_BUTTON_EDGE_FADE * 2 ) )
#define REDUX_BUTTON_RIGHT_FADE_WIDTH	( REDUX_BUTTON_EDGE_FADE * 2 )
#define REDUX_BUTTON_GLOW_LINE_HEIGHT	1

#define CHOICE_X( idx ) 			( CHOICE_X_START + CHOICE_X_SPACING * CHOICE_COL( idx ) )
#define CHOICE_Y( idx ) 			( CHOICE_Y_START + CHOICE_Y_SPACING * CHOICE_ROW( idx ) )
#define CHOICE_ORIGIN( idx )		CHOICE_X( idx ) CHOICE_Y( idx )
#define CHOICE_RECT( idx )			CHOICE_ORIGIN( idx ) CHOICE_X_SIZE CHOICE_Y_SIZE 1 1

#define CREATE_SHADER( position, texture, colour ) \
		CREATE_SHADER_VIS( position, texture, colour, 1 )

#define CREATE_SHADER_VIS( position, texture, colour, visibility ) \
		CREATE_SHADER_EX( position, texture, colour, visibility, ; )

#define CREATE_SHADER_EX( position, texture, colour, visibility, extra ) \
		itemDef \
		{ \
			style 			WINDOW_STYLE_SHADER \
			rect 			position; \
			forecolor 		colour \
			exp 			material ( texture ) \
			visible 		when ( visibility ) \
			decoration 		\
			extra			\
		}

#define CREATE_TEXT( position, string, color, visibility, extras ) \
		itemDef \
		{ \
			rect 			position; \
			style 			1 \
			forecolor 		color \
			exp 			text ( string ) \
			visible 		when ( visibility ) \
			textfont		UI_FONT_DEFAULT \
			decoration \
			extras \
		}

#define REDUX_ANIMATE_TEXT \
		itemDef \
		{ \
			rect 			160 34 320 28 1 1; \
			style 			1 \
		    forecolor      	REDUX_TEXT_COLOR \
		    backcolor      	0 0 0 0 \
			border			0 \
			bordersize		0 \
			bordercolor    	0 0 0 0 \
			outlinecolor   	REDUX_OUTLINE_COLOR \
			background white \
			textfont		UI_FONT_DEFAULT \
			textstyle REDUX_TEXTSTYLE \
			textscale REDUX_FEEDBACK_TEXTSCALE \
			textalignx 0 \
			textaligny 15 \
			exp 			text ( dvarstring( "option_completed" ) ) \
			visible 		when ( dvarBool("option_active") ) \
			autowrapped \
			glowColor 		REDUX_GLOW_FOCUS \
			textalign ITEM_ALIGN_MIDDLE_CENTER \
			decoration \
		}

#define REDUX_BACK_WIDGET \
		CREATE_SHADER_VIS( 250 418 140 22 1 1, "white", 0 0 0 0.12, 1 ) \
		CREATE_TEXT( 250 418 140 22 1 1, "ESC Back", REDUX_TEXT_COLOR, 1, textfont 0; textscale 0.22; textstyle 3; outlinecolor REDUX_OUTLINE_COLOR; textalign ITEM_ALIGN_MIDDLE_CENTER )

#define REDUX_ANIMATE_OPEN \
		lerp x "from" -200 "to" 0 "over" 0.1; \
		lerp alpha "from" 0 "to" 1 "over" 0.1;

#define REDUX_ANIMATE_CLOSE \
		lerp alpha "from" 1 "to" 0 "over" 0.1; \
		lerp x "from" 0 "to" -200 "over" 0.1;

#define REDUX_ANIMATE_SUB_OPEN \
		lerp x "from" 200 "to" 0 "over" 0.1; \
		lerp alpha "from" 0 "to" 1 "over" 0.1;

#define REDUX_ANIMATE_SUB_CLOSE \
		lerp alpha "from" 1 "to" 0 "over" 0.1; \
		lerp x "from" 0 "to" 200 "over" 0.1;

#define REDUX_INGAME_MENU( create_sub ) \
		name 						MENU_NAME \
		rect 						0 0 640 480 4 4; \
		forecolor 					1 1 1 1 \
		focuscolor 					1 1 1 1 \
		blurworld 					0 \
		onOpen \
		{ \
			if ( create_sub ) \
			{ \
				open MENU_NAME"_r"; \
			} \
		} \
		onRequestClose \
		{ \
			if ( create_sub ) \
			{ \
				close MENU_NAME"_r"; \
			} \
		} \
		onClose \
		{ \
			if ( create_sub ) \
			{ \
				close MENU_NAME"_r"; \
			} \
		} \
		CREATE_SHADER_EX( 146 56 348 330 1 1, "white", REDUX_PANEL_DARK, 1, border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		CREATE_TEXT( 140 66 360 22 1 1, MENU_TITLE, REDUX_TITLE_COLOR, 1, textfont 9; textscale REDUX_TITLE_TEXTSCALE; textstyle REDUX_TEXTSTYLE; outlinecolor REDUX_OUTLINE_COLOR; glowColor REDUX_TITLE_GLOW; textalign ITEM_ALIGN_MIDDLE_CENTER ) \
		REDUX_ANIMATE_TEXT

#define REDUX_INGAME_SUB \
		name 						MENU_NAME"_r" \
		rect 						0 0 640 480 4 4; \
		forecolor 					1 1 1 1 \
		visible 					when ( menuisopen( MENU_NAME ) ) \
		decoration \
		onOpen \
		{ \
		} \
		onRequestClose \
		{ \
		} \
		onClose \
		{ \
		} \
		CREATE_SHADER( 0 0 854 480 0 0, "gradient_fadein", 0 0 0 0 )

#define REDUX_BUTTON( idx, string, action_ ) \
		REDUX_BUTTON_VIS( idx, string, action_, 1 )

#define REDUX_BUTTON_VIP( idx, string, action_ ) \
		REDUX_BUTTON_VIS( idx, string, action_, 1 )

#define REDUX_BUTTON_MOD( idx, string, action_ ) \
		REDUX_BUTTON_VIS( idx, string, action_, 1 )

#define REDUX_BUTTON_ADMIN( idx, string, action_ ) \
		REDUX_BUTTON_VIS( idx, string, action_, 1 )

#define REDUX_BUTTON_VIS( idx, string, action_, visibility ) \
		REDUX_BUTTON_ALL( idx, string, action_, visibility, ;, ;, 0 )

#define REDUX_BUTTON_ALL( idx, string, action_, visibility, focus, leavefocus, disable_ ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + REDUX_BUTTON_SIDE_INSET ) ( CHOICE_Y( idx ) - 1 ) REDUX_BUTTON_EDGE_FADE ( CHOICE_Y_SIZE + 2 ) 1 1, "gradient_fadein", REDUX_BUTTON_GLOW, visibility, name "redux_btn_glow_left_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0; origin 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + REDUX_BUTTON_SIDE_INSET + REDUX_BUTTON_EDGE_FADE ) ( CHOICE_Y( idx ) - 1 ) REDUX_BUTTON_CENTER_WIDTH ( CHOICE_Y_SIZE + 2 ) 1 1, "white", REDUX_BUTTON_GLOW, visibility, name "redux_btn_glow_center_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + REDUX_BUTTON_SIDE_INSET + REDUX_BUTTON_WIDTH - REDUX_BUTTON_EDGE_FADE ) ( CHOICE_Y( idx ) - 1 ) ( 0 - REDUX_BUTTON_EDGE_FADE ) ( CHOICE_Y_SIZE + 2 ) 1 1, "gradient_fadein", REDUX_BUTTON_GLOW, visibility, name "redux_btn_glow_right_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + REDUX_BUTTON_SIDE_INSET ) CHOICE_Y( idx ) REDUX_BUTTON_EDGE_FADE CHOICE_Y_SIZE 1 1, "gradient_fadein", REDUX_BUTTON_FILL, visibility, name "redux_btn_bg_left_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0; origin 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + REDUX_BUTTON_SIDE_INSET + REDUX_BUTTON_EDGE_FADE ) CHOICE_Y( idx ) REDUX_BUTTON_CENTER_WIDTH CHOICE_Y_SIZE 1 1, "white", REDUX_BUTTON_FILL, visibility, name "redux_btn_bg_center_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + REDUX_BUTTON_SIDE_INSET + REDUX_BUTTON_WIDTH - REDUX_BUTTON_EDGE_FADE ) CHOICE_Y( idx ) ( 0 - REDUX_BUTTON_EDGE_FADE ) CHOICE_Y_SIZE 1 1, "gradient_fadein", REDUX_BUTTON_FILL, visibility, name "redux_btn_bg_right_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		itemDef \
		{ \
			rect 					( CHOICE_X( idx ) + REDUX_BUTTON_SIDE_INSET ) CHOICE_Y( idx ) REDUX_BUTTON_WIDTH CHOICE_Y_SIZE 1 1 \
			type 					ITEM_TYPE_BUTTON \
			style					WINDOW_STYLE_FILLED \
			background      		"white" \
			visible 				when ( visibility ) \
			border			1 \
			bordersize		REDUX_BUTTON_BORDER_WIDTH \
			bordercolor    	REDUX_BUTTON_EDGE \
		    forecolor      	REDUX_TEXT_COLOR \
		    backcolor      	0 0 0 0 \
		    disablecolor   	REDUX_TEXT_DISABLED \
			outlinecolor   	REDUX_OUTLINE_COLOR \
			textfont 				0 \
			textaligny 				CHOICE_Y_TEXTALIGN \
			textalignx 				0 \
			textscale 				REDUX_OPTION_TEXTSCALE \
			textstyle 				REDUX_TEXTSTYLE \
			glowColor 				REDUX_GLOW_IDLE \
			textalign 				ITEM_ALIGN_MIDDLE_CENTER \
			exp text				( string ) \
			disabled				when ( disable_ ) \
			disablecolor			REDUX_TEXT_DISABLED \
			autowrapped				\
            onFocus \
            { \
		        setItemColor "redux_btn_glow_left_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW_FOCUS; \
		        setItemColor "redux_btn_glow_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW_FOCUS; \
		        setItemColor "redux_btn_glow_right_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW_FOCUS; \
		        setItemColor "redux_btn_bg_left_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL_FOCUS; \
		        setItemColor "redux_btn_bg_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL_FOCUS; \
		        setItemColor "redux_btn_bg_right_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL_FOCUS; \
		        setItemColor self bordercolor REDUX_BUTTON_EDGE_FOCUS; \
		        setItemColor self forecolor REDUX_TEXT_FOCUS; \
		        setItemColor self glowcolor REDUX_GLOW_FOCUS; \
				focus \
                play "mouse_over"; \
            } \
            leaveFocus \
            { \
		        setItemColor "redux_btn_glow_left_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW; \
		        setItemColor "redux_btn_glow_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW; \
		        setItemColor "redux_btn_glow_right_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW; \
		        setItemColor "redux_btn_bg_left_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL; \
		        setItemColor "redux_btn_bg_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL; \
		        setItemColor "redux_btn_bg_right_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL; \
		        setItemColor self bordercolor REDUX_BUTTON_EDGE; \
		        setItemColor self forecolor REDUX_TEXT_COLOR; \
		        setItemColor self glowcolor REDUX_GLOW_IDLE; \
				leavefocus \
            } \
			action \
			{ \
				if ( !( disable_ ) ) \
				{ \
					action_; \
				} \
			} \
		}

#define REDUX_SEPARATOR( idx ) \
		REDUX_SEPARATOR_VIS( idx, 1 )

#define REDUX_SEPARATOR_VIS( idx, visibility ) \
		CREATE_SHADER_VIS( CHOICE_ORIGIN( idx ) CHOICE_X_SIZE 4 1 1, "gradient_center", 1 1 1 0.05; origin 0 0, visibility )

#define REDUX_GENERIC_FEEDER( index, action_, data ) \
		itemDef \
		{ \
			rect 					CHOICE_ORIGIN( 0 ) CHOICE_X_SIZE 400 1 1 \
			visible 				1 \
			forecolor 				WHITE 1 \
			outlinecolor 			1 1 1 0.2 \
			type 					6 \
			textalignx 				6 \
			textscale 				0.275 \
			feeder 					index \
			elementWidth 			CHOICE_X_SIZE \
			elementHeight 			18 \
			data \		
			doubleClick \		
			{ \		
				play 				"mouse_click"; \
				action_; \
			} \
		}

#define INGAME_FACTION_ICON( pos, alpha ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Allies" ), 1 1 1 alpha, localVarString( "ui_team" ) == "marines" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Axis" ), 1 1 1 alpha, localVarString( "ui_team" ) == "opfor" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Allies" ), 1 1 1 alpha, team( "name" ) == "TEAM_FREE" && localVarString( "ui_team" ) == "marines" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Axis" ), 1 1 1 alpha, team( "name" ) == "TEAM_FREE" && localVarString( "ui_team" ) == "opfor" )

#define REDUX_GAME_WIDGET \
		CREATE_SHADER_EX( 156 360 328 2 1 1, "white", 0.90 0.67 0.24 0.10, 1, border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		CREATE_TEXT( 156 370 328 18 1 1, "Mobile inspired IW4x UI", 0.69 0.53 0.24 0.34, 1, textfont 0; textscale 0.22; textstyle 0; outlinecolor 0 0 0 0.18; textalign ITEM_ALIGN_MIDDLE_CENTER )

#define CHANGE_CLASS_ACTION	\
		if ( localVarString( "ui_team" ) == "marines" ) \
		{ \
			scriptmenuresponse "changeclass_marines"; \
		} \
		if ( localVarString( "ui_team" ) == "opfor" ) \
		{ \
			scriptmenuresponse "changeclass_opfor"; \
		}

#define REDUX_BIND( idx, string, bind ) \
		CREATE_SHADER_EX( CHOICE_ORIGIN( idx ) 55 CHOICE_Y_SIZE 1 1, "white", 0 0 0 0, 1, origin 195 0; group idx; exp forecolor r ( 0 ); exp forecolor g ( 0 ); exp forecolor b ( 0 ); ) \
		CREATE_TEXT( CHOICE_RECT( idx ), "KEYBINDING", 1 1 1 0.25, 1, textfont 0; textalignx 8; textaligny 5; textscale 0.2; textstyle 3; textalign ITEM_ALIGN_TOP_LEFT ) \
		CREATE_TEXT( CHOICE_RECT( idx ), string, 1 1 1 1, 1, textfont 0; textalignx 8; textaligny 4.5; textscale 0.275; textstyle 3; textalign ITEM_ALIGN_MIDDLE_LEFT ) \
		itemDef \
		{ \
			rect 					CHOICE_RECT( idx ) \
			type 					ITEM_TYPE_BIND \
			style					WINDOW_STYLE_FILLED \
			background      		"white" \
			border					1 \
			bordercolor				1 1 1 0.05 \
			bordersize				0.25 \
			backcolor				1 1 1 0.01 \
			textfont 				0 \
			textalignx 				-10 \
			textscale 				0.275 \
			textstyle 				3 \
			textalign 				ITEM_ALIGN_MIDDLE_RIGHT \
			dvar					bind \
			visible					1 \
			onFocus \
			{ \
				setItemColor 			self backcolor 1 1 1 0.09; \
				setItemColor 			self bordercolor 1 1 1 0.25; \
				setItemColor 			idx backcolor 0 0 0 0.9; \
				setItemColor 			idx forecolor 1 1 1 1; \
				focus; \
			} \
			leaveFocus \
			{ \
				setItemColor 			self backcolor 1 1 1 0.01; \
				setItemColor 			self bordercolor 1 1 1 0.05; \
				setItemColor 			idx backcolor 0 0 0 0; \
				setItemColor 			idx forecolor 0 0 0 0; \
				leavefocus; \
			} \
		}

#define REDUX_SLIDER( idx, string, dvar, dvar_min, dvar_max, dvar_default, action_, show_value ) \
		CREATE_SHADER_EX( CHOICE_ORIGIN( idx ) 55 CHOICE_Y_SIZE 1 1, "white", 0 0 0 0, 1, origin 195 0 ) \
		CREATE_TEXT( CHOICE_RECT( idx ), "SLIDER", 1 1 1 1, 1, textfont 0; textalignx 8; textaligny 5; textscale 0.2; textstyle 3; textalign ITEM_ALIGN_TOP_LEFT ) \
		CREATE_TEXT( CHOICE_RECT( idx ), string, 1 1 1 1, 1, textfont 0; textalignx 8; textaligny 4.5; textscale 0.275; textstyle 3; textalign ITEM_ALIGN_MIDDLE_LEFT ) \
		CREATE_TEXT( CHOICE_RECT( idx ), dvarInt( dvar ), 1 1 1 0.65, show_value, textalignX -30; textalignY -2; textfont 0; textscale 0.175; textalign ITEM_ALIGN_BOTTOM_RIGHT ) \
		itemDef \
		{ \
			rect 					CHOICE_RECT( idx ) \
			style					WINDOW_STYLE_FILLED \
			background      		"white" \
			border					1 \
			bordercolor				1 1 1 0.05 \
			bordersize				0.25 \
            backcolor      			0.15 0.15 0.15 0.5 \
			visible					1 \
			decoration \
		} \
		itemDef \
		{ \
			rect CHOICE_ORIGIN( idx ) 95.5 12 1 1 \
			origin 126 9 \
			forecolor 1 1 1 1 \
			type ITEM_TYPE_SLIDER \
			dvarFloat dvar dvar_default dvar_min dvar_max \
			visible 1 \
			action \
			{ \
				action_; \
			} \
		}

#define CHOICE_BUTTON( idx, string, action_, visibility ) \
        CHOICE_BUTTON_EX( idx, string, action_, visibility, ; )

#define CHOICE_BUTTON_EX( idx, string, action_, visibility, extra ) \
		CREATE_SHADER_EX( CHOICE_X( idx ) ( CHOICE_Y( idx ) - 1 ) REDUX_BUTTON_EDGE_FADE ( CHOICE_Y_SIZE + 2 ) 1 1, "gradient_fadein", REDUX_BUTTON_GLOW, visibility, name "choice_btn_glow_left_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0; origin 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + REDUX_BUTTON_EDGE_FADE ) ( CHOICE_Y( idx ) - 1 ) ( CHOICE_X_SIZE - ( REDUX_BUTTON_EDGE_FADE * 2 ) ) ( CHOICE_Y_SIZE + 2 ) 1 1, "white", REDUX_BUTTON_GLOW, visibility, name "choice_btn_glow_center_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + CHOICE_X_SIZE - REDUX_BUTTON_EDGE_FADE ) ( CHOICE_Y( idx ) - 1 ) ( 0 - REDUX_BUTTON_EDGE_FADE ) ( CHOICE_Y_SIZE + 2 ) 1 1, "gradient_fadein", REDUX_BUTTON_GLOW, visibility, name "choice_btn_glow_right_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		CREATE_SHADER_EX( CHOICE_X( idx ) CHOICE_Y( idx ) REDUX_BUTTON_EDGE_FADE CHOICE_Y_SIZE 1 1, "gradient_fadein", REDUX_BUTTON_FILL, visibility, name "choice_btn_bg_left_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0; origin 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + REDUX_BUTTON_EDGE_FADE ) CHOICE_Y( idx ) ( CHOICE_X_SIZE - ( REDUX_BUTTON_EDGE_FADE * 2 ) ) CHOICE_Y_SIZE 1 1, "white", REDUX_BUTTON_FILL, visibility, name "choice_btn_bg_center_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
		CREATE_SHADER_EX( ( CHOICE_X( idx ) + CHOICE_X_SIZE - REDUX_BUTTON_EDGE_FADE ) CHOICE_Y( idx ) ( 0 - REDUX_BUTTON_EDGE_FADE ) CHOICE_Y_SIZE 1 1, "gradient_fadein", REDUX_BUTTON_FILL, visibility, name "choice_btn_bg_right_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
        itemDef \
		{ \
			rect 			CHOICE_RECT( idx ) \
			exp				text ( string ) \
            style           WINDOW_STYLE_FILLED \
            type            ITEM_TYPE_BUTTON \
			visible 		when ( visibility ) \
            background      "white" \
			forecolor      	REDUX_TEXT_COLOR \
			backcolor      	0 0 0 0 \
            disablecolor   	0.5 0.5 0.5 0.5 \
			border			1 \
			bordersize		1 \
			bordercolor    	REDUX_BUTTON_EDGE \
			outlinecolor   	REDUX_OUTLINE_COLOR \
            textfont        UI_FONT_DEFAULT \
            textscale       TEXTSIZE_SMALL \
            textstyle       ITEM_TEXTSTYLE_SHADOWED \
            glowColor       REDUX_GLOW_IDLE \
            textalign       ITEM_ALIGN_MIDDLE_CENTER \
            textalignx      0 \
            extra \
            onFocus \
            { \
				setItemColor "choice_btn_glow_left_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW_FOCUS; \
				setItemColor "choice_btn_glow_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW_FOCUS; \
				setItemColor "choice_btn_glow_right_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW_FOCUS; \
				setItemColor "choice_btn_bg_left_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL_FOCUS; \
				setItemColor "choice_btn_bg_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL_FOCUS; \
				setItemColor "choice_btn_bg_right_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL_FOCUS; \
				setItemColor self bordercolor REDUX_BUTTON_EDGE_FOCUS; \
				setItemColor self forecolor REDUX_TEXT_FOCUS; \
				setItemColor self glowcolor REDUX_GLOW_FOCUS; \
                play "mouse_over"; \
            } \
            leaveFocus \
            { \
				setItemColor "choice_btn_glow_left_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW; \
				setItemColor "choice_btn_glow_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW; \
				setItemColor "choice_btn_glow_right_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_GLOW; \
				setItemColor "choice_btn_bg_left_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL; \
				setItemColor "choice_btn_bg_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL; \
				setItemColor "choice_btn_bg_right_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL; \
				setItemColor self bordercolor REDUX_BUTTON_EDGE; \
				setItemColor self forecolor REDUX_TEXT_COLOR; \
				setItemColor self glowcolor REDUX_GLOW_IDLE; \
            } \
			action \
			{ \
				play "mouse_click"; \
                action_; \
            } \
		}

#define CHOICE_BUTTON_OTHER( idx, new_rec, string, action_, visibility ) \
        CHOICE_BUTTON_FUNC( idx, new_rec, string, action_, visibility )

#define CHOICE_BUTTON_FUNC( idx, new_rec, string, action_, visibility ) \
		CREATE_SHADER_EX( new_rec, "white", REDUX_BUTTON_FILL, visibility, name "choice_other_bg_center_" REDUX_STRINGIFY( idx ); border 0; bordersize 0; bordercolor 0 0 0 0 ) \
        itemDef \
		{ \
			rect 			new_rec \
			exp				text ( string ) \
            style           WINDOW_STYLE_FILLED \
            type            ITEM_TYPE_BUTTON \
			visible 		when ( visibility ) \
            background      "white" \
			forecolor      	REDUX_TEXT_COLOR \
			backcolor      	0 0 0 0 \
            disablecolor   	0.5 0.5 0.5 0.5 \
			border			1 \
			bordersize		1 \
			bordercolor    	REDUX_BUTTON_EDGE \
			outlinecolor   	REDUX_OUTLINE_COLOR \
            textfont        UI_FONT_DEFAULT \
            textscale       TEXTSIZE_SMALL \
            textstyle       ITEM_TEXTSTYLE_SHADOWED \
			glowColor       REDUX_GLOW_IDLE \
            textalign       ITEM_ALIGN_MIDDLE_CENTER \
            textalignx      0 \
            onFocus \
            { \
				setItemColor "choice_other_bg_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL_FOCUS; \
				setItemColor self bordercolor REDUX_BUTTON_EDGE_FOCUS; \
				setItemColor self forecolor REDUX_TEXT_FOCUS; \
				setItemColor self glowcolor REDUX_GLOW_FOCUS; \
                play "mouse_over"; \
            } \
            leaveFocus \
            { \
				setItemColor "choice_other_bg_center_" REDUX_STRINGIFY( idx ) forecolor REDUX_BUTTON_FILL; \
				setItemColor self bordercolor REDUX_BUTTON_EDGE; \
				setItemColor self forecolor REDUX_TEXT_COLOR; \
				setItemColor self glowcolor REDUX_GLOW_IDLE; \
            } \
			action \
			{ \
				play "mouse_click"; \
                action_; \
            } \
		}