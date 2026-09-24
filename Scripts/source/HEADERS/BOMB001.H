/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef BOMB001_H
#define BOMB001_H

 // Map vars for B.O.M.B.-001

 // Comments

//MAP_GLOBAL_VARS:

//GLOBAL                                       NUMBER

//ALL Map Vars needed to start w/ MVAR_
#define MVAR_SecField_down                     (0)
#define MVAR_OdySecField1_down                 (1)
#define MVAR_OdySecField2_down                 (2)

#define BOMB001_MISSILE_LAUNCH_TIME        (2 * ONE_GAME_HOUR)

variable BOMB001_Countdown_Variable;
variable BOMB001_Minute;
variable BOMB001_Second;

#define BOMB001_STRUCTURAL_INTEGRITY_FAIL_TIME        (ONE_GAME_MINUTE)

variable BOMB001_SIF_Countdown_Variable;
variable BOMB001_SIF_Minute;
variable BOMB001_SIF_Second;

#define BOMB001_OVERLOAD_REACTOR_TIME        (10 * ONE_GAME_MINUTE)

variable BOMB001_Overload_Countdown_Variable;
variable BOMB001_Overload_Minute;
variable BOMB001_Overload_Second;

#define BOMB001_BLOW_UP_REACTOR_TIME        (random(5, 10) * ONE_GAME_MINUTE)

variable BOMB001_Blow_Up_Countdown_Variable;
variable BOMB001_Blow_Up_Minute;
variable BOMB001_Blow_Up_Second;

#define Show_Time(x,y)          if (x == 1) then                                                                                \
                                    if (y == 1) then                                                                            \
                                        display_msg(message_str(SCRIPT_BOMB001,111)+x+message_str(SCRIPT_BOMB001,114)+y+message_str(SCRIPT_BOMB001,115));       \
                                    else                                                                                        \
                                        display_msg(message_str(SCRIPT_BOMB001,111)+x+message_str(SCRIPT_BOMB001,114)+y+message_str(SCRIPT_BOMB001,113));       \
                                else if (y == 1) then                                                                           \
                                    display_msg(message_str(SCRIPT_BOMB001,111)+x+message_str(SCRIPT_BOMB001,112)+y+message_str(SCRIPT_BOMB001,115));           \
                                else                                                                                            \
                                    display_msg(message_str(SCRIPT_BOMB001,111)+x+message_str(SCRIPT_BOMB001,112)+y+message_str(SCRIPT_BOMB001,113))

#define Show_SIF_Time(x,y)          if (x == 1) then                                                                                \
                                    if (y == 1) then                                                                            \
                                        display_msg(x+message_str(SCRIPT_BOMB001,114)+y+message_str(SCRIPT_BOMB001,121));       \
                                    else                                                                                        \
                                        display_msg(x+message_str(SCRIPT_BOMB001,114)+y+message_str(SCRIPT_BOMB001,120));       \
                                else if (y == 1) then                                                                           \
                                    display_msg(x+message_str(SCRIPT_BOMB001,112)+y+message_str(SCRIPT_BOMB001,121));           \
                                else                                                                                            \
                                    display_msg(x+message_str(SCRIPT_BOMB001,112)+y+message_str(SCRIPT_BOMB001,120))

#define Show_Overload_Time(x,y)          if (x == 1) then                                                                                \
                                    if (y == 1) then                                                                            \
                                        display_msg(x+message_str(SCRIPT_BOMB001,114)+y+message_str(SCRIPT_BOMB001,141));       \
                                    else                                                                                        \
                                        display_msg(x+message_str(SCRIPT_BOMB001,114)+y+message_str(SCRIPT_BOMB001,140));       \
                                else if (y == 1) then                                                                           \
                                    display_msg(x+message_str(SCRIPT_BOMB001,112)+y+message_str(SCRIPT_BOMB001,141));           \
                                else                                                                                            \
                                    display_msg(x+message_str(SCRIPT_BOMB001,112)+y+message_str(SCRIPT_BOMB001,140))

#define Show_Blow_Up_Time(x,y)          if (x == 1) then                                                                                \
                                    if (y == 1) then                                                                            \
                                        display_msg(x+message_str(SCRIPT_BOMB001,114)+y+message_str(SCRIPT_BOMB001,131));       \
                                    else                                                                                        \
                                        display_msg(x+message_str(SCRIPT_BOMB001,114)+y+message_str(SCRIPT_BOMB001,130));       \
                                else if (y == 1) then                                                                           \
                                    display_msg(x+message_str(SCRIPT_BOMB001,112)+y+message_str(SCRIPT_BOMB001,131));           \
                                else                                                                                            \
                                    display_msg(x+message_str(SCRIPT_BOMB001,112)+y+message_str(SCRIPT_BOMB001,130))

#define check_countdown         if (global_var(GVAR_BOMB001_COUNTDOWN) != 0) then begin                                         \
                                    BOMB001_Countdown_Variable:=game_time - global_var(GVAR_BOMB001_COUNTDOWN);                 \
                                    if (BOMB001_Countdown_Variable >= BOMB001_MISSILE_LAUNCH_TIME) then begin                      \
                                        if (global_var(GVAR_QUEST_16_MDOORS_DISABLE) >= 5) then begin                              \
                                            if (global_var(GVAR_BOMB001_SIF_COUNTDOWN) == 0) then begin                                \
                                                set_global_var(GVAR_BOMB001_SIF_COUNTDOWN, game_time);                                \
                                                set_map_music(cur_map_index, "56b001");                                               \
                                            end                                                                                       \
                                        end                                                                                           \
                                            check_integrity_countdown                                                               \
                                        else begin                                                                                   \
                                            signal_end_game;                                                                        \
                                        end                                                                                      \
                                    end                                                                                         \
                                    else begin                                                                                  \
                                        BOMB001_Minute:=(BOMB001_MISSILE_LAUNCH_TIME - BOMB001_Countdown_Variable)/ONE_GAME_MINUTE;\
                                        BOMB001_Second:=((BOMB001_MISSILE_LAUNCH_TIME - BOMB001_Countdown_Variable) % ONE_GAME_MINUTE)/ONE_GAME_SECOND;   \
                                        display_msg(g_mstr(1014));                                                              \
                                        Show_Time(BOMB001_Minute,BOMB001_Second);                                               \
                                    end                                                                                         \
                                end

#define check_integrity_countdown         if (global_var(GVAR_BOMB001_SIF_COUNTDOWN) != 0) then begin                                         \
                                        BOMB001_SIF_Countdown_Variable:=game_time - global_var(GVAR_BOMB001_SIF_COUNTDOWN);                 \
                                    if (BOMB001_SIF_Countdown_Variable >= BOMB001_STRUCTURAL_INTEGRITY_FAIL_TIME) then begin                      \
                                        signal_end_game;                                                                        \
                                    end                                                                                         \
                                    else begin                                                                                  \
                                        BOMB001_SIF_Minute:=(BOMB001_STRUCTURAL_INTEGRITY_FAIL_TIME - BOMB001_SIF_Countdown_Variable)/ONE_GAME_MINUTE;\
                                        BOMB001_SIF_Second:=((BOMB001_STRUCTURAL_INTEGRITY_FAIL_TIME - BOMB001_SIF_Countdown_Variable) % ONE_GAME_MINUTE)/ONE_GAME_SECOND;   \
                                        display_msg(g_mstr(1015));                                                              \
                                        Show_SIF_Time(BOMB001_SIF_Minute,BOMB001_SIF_Second);                                               \
                                    end                                                                                         \
                                end

#define check_overload_countdown         if (global_var(GVAR_BOMB001_OVERLOAD_COUNTDOWN) != 0) then begin                                         \
                                    BOMB001_Overload_Countdown_Variable:=game_time - global_var(GVAR_BOMB001_OVERLOAD_COUNTDOWN);                 \
                                if (BOMB001_Overload_Countdown_Variable >= BOMB001_OVERLOAD_REACTOR_TIME) then begin                      \
                                    signal_end_game;                                                                        \
                                end                                                                                         \
                                else begin                                                                                  \
                                    BOMB001_Overload_Minute:=(BOMB001_OVERLOAD_REACTOR_TIME - BOMB001_Overload_Countdown_Variable)/ONE_GAME_MINUTE;\
                                    BOMB001_Overload_Second:=((BOMB001_OVERLOAD_REACTOR_TIME - BOMB001_Overload_Countdown_Variable) % ONE_GAME_MINUTE)/ONE_GAME_SECOND;   \
                                    display_msg(g_mstr(1016));                                                              \
                                    Show_Overload_Time(BOMB001_Overload_Minute,BOMB001_Overload_Second);                                               \
                                end                                                                                         \
                            end

#define check_blow_up_countdown         if (global_var(GVAR_BOMB001_BLOW_UP_COUNTDOWN) != 0) then begin                                         \
                                BOMB001_Blow_Up_Countdown_Variable:=game_time - global_var(GVAR_BOMB001_BLOW_UP_COUNTDOWN);                 \
                            if (BOMB001_Blow_Up_Countdown_Variable >= BOMB001_BLOW_UP_REACTOR_TIME) then begin                      \
                                signal_end_game;                                                                        \
                            end                                                                                         \
                            else begin                                                                                  \
                                BOMB001_Overload_Minute:=(BOMB001_BLOW_UP_REACTOR_TIME - BOMB001_Blow_Up_Countdown_Variable)/ONE_GAME_MINUTE;\
                                BOMB001_Overload_Second:=((BOMB001_BLOW_UP_REACTOR_TIME - BOMB001_Blow_Up_Countdown_Variable) % ONE_GAME_MINUTE)/ONE_GAME_SECOND;   \
                                display_msg(g_mstr(1012));                                                              \
                                Show_Blow_Up_Time(BOMB001_Blow_Up_Minute,BOMB001_Blow_Up_Second);                                               \
                            end                                                                                         \
                        end

#endif // BOMB001_H
