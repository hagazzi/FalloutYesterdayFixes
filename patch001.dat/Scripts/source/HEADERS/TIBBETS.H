/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef TIBBETS_H
#define TIBBETS_H

 // Map vars for Tibbets

 // Comments

//MAP_GLOBAL_VARS:

//GLOBAL                                       NUMBER

//ALL Map Vars needed to start w/ MVAR_
#define MVAR_SecField_down                     (0)
#define MVAR_OdySecField1_down                 (1)
#define MVAR_OdySecField2_down                 (2)

#define TIBBETS_DESTRUCTION_TIME        (5*ONE_GAME_MINUTE)

variable Tibbets_Countdown_Variable;
variable Tibbets_Minute;
variable Tibbets_Second;

#define Show_Time(x,y)          if (x == 1) then                                                                                \
                                    if (y == 1) then                                                                            \
                                        display_msg(x+message_str(SCRIPT_ODYCORE,114)+y+message_str(SCRIPT_ODYCORE,115));       \
                                    else                                                                                        \
                                        display_msg(x+message_str(SCRIPT_ODYCORE,114)+y+message_str(SCRIPT_ODYCORE,113));       \
                                else if (y == 1) then                                                                           \
                                    display_msg(x+message_str(SCRIPT_ODYCORE,112)+y+message_str(SCRIPT_ODYCORE,115));           \
                                else                                                                                            \
                                    display_msg(x+message_str(SCRIPT_ODYCORE,112)+y+message_str(SCRIPT_ODYCORE,113))

#define check_countdown         if (global_var(GVAR_TIBBETS_COUNTDOWN) != 0) then begin                                         \
                                    Tibbets_Countdown_Variable:=game_time - global_var(GVAR_TIBBETS_COUNTDOWN);                 \
                                    if (Tibbets_Countdown_Variable >= TIBBETS_DESTRUCTION_TIME) then begin                      \
                                        signal_end_game;                                                                        \
                                    end                                                                                         \
                                    else begin                                                                                  \
                                        Tibbets_Minute:=(TIBBETS_DESTRUCTION_TIME - Tibbets_Countdown_Variable)/ONE_GAME_MINUTE;\
                                        Tibbets_Second:=((TIBBETS_DESTRUCTION_TIME - Tibbets_Countdown_Variable) % ONE_GAME_MINUTE)/ONE_GAME_SECOND;   \
                                        display_msg(g_mstr(1013));                                                              \
                                        Show_Time(Tibbets_Minute,Tibbets_Second);                                               \
                                    end                                                                                         \
                                end

procedure TibbetsAttack begin

	variable tmp;

	script_overrides;
	game_ui_disable;

	reg_anim_clear(dude_obj);
	fadeout(1);
	reg_anim_begin();
	reg_anim_animate(dude_obj, ANIM_fall_back, -1);
	reg_anim_end();

	tmp := play_sfall_sound("data\\sound\\SFX\\breach.wav", 0);
	game_time_advance(ONE_GAME_MINUTE * (15 - dude_endurance));
	set_global_var(GVAR_TIBBETS_BATTALION_ATTACK, 1);
	game_ui_enable;
	fadein(1);

	if(dude_is_stupid) then begin
		float_msg(dude_obj, g_mstr(922), FLOAT_COLOR_BAD);
	end else begin
		float_msg(dude_obj, g_mstr(921), FLOAT_COLOR_BAD);
	end
	display_msg(g_mstr(920));

end

#endif // TIBBETS_H
