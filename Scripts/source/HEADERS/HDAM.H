/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef HDAM_H
#define HDAM_H

#define CC_ARREST_TACTIC_COMBAT         (1)
#define CC_ARREST_TACTIC_DIPLO          (2)
#define CC_ARREST_TACTIC_STEALTH        (3)

// timer event paramaters
#define timed_event_float                             (0)
#define float_param                                   (1)
#define timed_event_get_high                          (2)
#define timed_event_off_crazy_rant                    (3)
#define timed_event_wander                            (4)
#define control_boxers_param                          (25)
#define change_round_param                            (26)
#define punch_thrown_param                            (27)
#define new_round_param                               (28)
#define other_boxer_down_param                        (29)
#define other_boxer_up_param                          (30)
#define fight_over_param                              (34)
#define knockout_param                                (41)
#define round_over_param                              (42)
#define slot_win_param                                (43)
#define no_whore_floats_param                         (45)
#define start_fight_param                             (46)
#define check_ui_param                                (48)

#define player_bites_masticator_ear_bit               bit_1
#define ui_should_be_disabled_bit                     bit_2
#define boxer_resting_bit                             bit_3
#define boxer_killed_bit                              bit_4
#define frieda_dead_bit                               bit_5
#define pablo_dead_bit                                bit_6
#define dusty_dead_bit                                bit_7
#define enzo_dead_bit                                 bit_8
#define guido_dead_bit                                bit_9
#define mckneely_dead_bit                             bit_10
#define holyfeld_dead_bit                             bit_11
#define masticator_dead_bit                           bit_12
#define fighting_main_boxer_bit                       bit_13
#define killed_opponent_bit                           bit_14
#define ginger_dead_bit                               bit_15
#define milko_dead_bit                                bit_16
#define ailis_dead_bit                                bit_17
#define major_dead_bit                                bit_18
#define crius_dead_bit                                bit_19
#define crazy_addict_bit                              bit_20
#define safe_code_3s_bit                              bit_21
#define safe_code_cc_bit                              bit_22
#define knows_mizaru_bit                              bit_23
#define knows_kikazaru_bit                            bit_24
#define knows_iwazaru_bit                             bit_25
#define fight_is_on_bit                               bit_30
#define no_whore_floats_bit                           bit_31
#define masticator_bit_ear_bit                        bit_32

#define enclave_destroyed                             Fallout2_enclave_destroyed

variable last_timed_obj;
variable last_timed_param;
#define nr_add_timer_event_tic(obj, ticks, param)     last_timed_obj := obj;                 \
                                                      last_timed_param := last_timed_param;  \
                                                      rm_fixed_timer_event(obj, param);      \
                                                      add_timer_event(obj, ticks, param)
#define nr_add_timer_event(obj, sec, param)           nr_add_timer_event_tic(obj, game_ticks(sec), param)
#define nr_add_timer_event_rand(obj, x, y, param)     nr_add_timer_event_tic(obj, game_ticks(x) + random(0, game_ticks((y) - (x))), param)

#define set_new_reno_flag_on(x,n)                     set_gvar_bit_on(GVAR_HOOVER_DAM_FLAG_##n, x)
#define set_new_reno_flag_off(x,n)                    set_gvar_bit_off(GVAR_HOOVER_DAM_FLAG_##n, x)
#define get_new_reno_flag(x,n)                        gvar_bit(GVAR_HOOVER_DAM_FLAG_##n, x)

#define tell_anouncer_to_switch_ui                    if (cur_map_index == MAP_HOOVER_DAM_NCR_ARMY_GYM) then begin                \
															if (announcer_obj != 0) then begin                          \
															nr_add_timer_event(announcer_obj, 0, check_ui_param);    \
															end                                                         \
														end
#define ui_should_be_disabled                         get_new_reno_flag(ui_should_be_disabled_bit, 4)
#define set_ui_should_be_disabled                     tell_anouncer_to_switch_ui                               \
 set_new_reno_flag_on(ui_should_be_disabled_bit, 4)
#define off_ui_should_be_disabled                     tell_anouncer_to_switch_ui                               \
 set_new_reno_flag_off(ui_should_be_disabled_bit, 4)

#ifndef tile_in_box
#define tile_in_box(x, ul, ur, lr, ll)                tile_in_tile_rect(ul, ur, ll, lr, x)
#endif

#define obj_in_loc(obj, ul, ur, lr, ll, map, elev)    ((tile_in_box(tile_num(obj), ul, ur, lr, ll)) and (cur_map_index == map) and ((elevation(obj) == elev) or (-1 == elev)))

#define tile_boxing_gym_ring(x)                       (tile_in_box(x, 21722, 21714, 23514, 23322))
#define random_tile_in_gym                            random_tile_in_box(21722, 21714, 23514, 233229)

#define no_whore_floats                               get_new_reno_flag(no_whore_floats_bit, 2)
#define set_no_whore_floats                           set_new_reno_flag_on(no_whore_floats_bit, 2)
#define off_no_whore_floats                           set_new_reno_flag_off(no_whore_floats_bit, 2)


// get the property that critter is on
#define get_self_family(the_result)                   the_result := family_none;                                  \
                                                      if (obj_on_salvatore(self_obj)) then begin                  \
                                                         the_result := family_salvatore;                          \
                                                      end else if (obj_on_bishop(self_obj)) then begin            \
                                                         the_result := family_bishop;                             \
                                                      end else if (obj_on_mordino(self_obj)) then begin           \
                                                         the_result := family_mordino;                            \
                                                      end else if (obj_on_wright(self_obj)) then begin            \
                                                         the_result := family_wright;                             \
                                                      end                                                         \
                                                      debug_msg("" + the_result)
// setting the correct team based on the family
#define set_family_team(the_family)                   if (the_family == family_salvatore) then begin                                         \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_SALVATORE);   \
                                                      end else if (the_family == family_bishop) then begin                                   \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_BISHOP);      \
                                                      end else if (the_family == family_mordino) then begin                                  \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_MORDINO);     \
                                                      end else if (the_family == family_wright) then begin                                   \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_WRIGHT);      \
                                                      end                                                                                    \
                                                      debug_msg("")
#define get_and_set_family(temp)                      get_self_family(temp);           \
                                                      set_family_team(temp)
// kill family member
// see some of the macros in command.h
#define set_family_and_name(the_family,the_name)      set_global_var(GVAR_NEW_RENO_MADE_MAN, (the_family * 100) + the_name)
#define set_made_man_rep(the_fam, val)                set_global_var(GVAR_MADE_MAN_SALVATORE + the_fam - 1, val)
#define set_dude_family(x)                            if (x == family_salvatore) then begin                             \
                                                         set_made_man_rep(family_salvatore, 1);                         \
                                                         set_family_and_name(family_salvatore, dude_made_man_number);   \
                                                      end else if (x == family_bishop) then begin                       \
                                                         set_made_man_rep(family_bishop, 1);                            \
                                                         set_family_and_name(family_bishop, dude_made_man_number);      \
                                                      end else if (x == family_mordino) then begin                      \
                                                         set_made_man_rep(family_mordino, 1);                           \
                                                         set_family_and_name(family_mordino, dude_made_man_number);     \
                                                      end else if (x == family_wright) then begin                       \
                                                         set_made_man_rep(family_wright, 1);                            \
                                                         set_family_and_name(family_wright, dude_made_man_number);      \
                                                      end else if (x == family_none) then begin                         \
                                                         set_made_man_rep(family_salvatore, 0);                         \
                                                         set_made_man_rep(family_bishop, 0);                            \
                                                         set_made_man_rep(family_mordino, 0);                           \
                                                         set_made_man_rep(family_wright, 0);                            \
                                                         set_family_and_name(0, 0);                                     \
                                                      end

// attack family
#define clear_family_flags(x)                         if (x == family_salvatore) then begin           \
                                                         off_salvatore_permission                     \
                                                         clear_tribute                                \
                                                         clear_track_lloyd                            \
                                                         clear_guard_assignment                       \
                                                      end else if (x == family_bishop) then begin     \
                                                         off_bishop_permission                        \
                                                         if (global_var(GVAR_MOORE_ACCEPT_DELIVERY) > 0) then begin  \
                                                            set_briefcase_flag(4); /*added by killap - 4 means failed */ \
                                                         end                                          \
                                                         clear_snuff_carlson                          \
                                                         clear_snuff_westin                           \
                                                      end else if (x == family_mordino) then begin    \
                                                         clear_delivery                               \
                                                         clear_extortion                              \
                                                         clear_assassination                          \
                                                      end else if (x == family_wright) then begin     \
                                                         set_sad_nothing;                             \
                                                         clear_mystery                                \
                                                         off_wright_flag(wright_permission_bit);      \
                                                      end
#define attack_family(x)                              clear_family_flags(x)                           \
                                                      set_family_warning_on(warning_attack, x);       \
                                                      if (x != family_none) then begin                \
                                                         if (x == dude_family) then begin             \
                                                            inc_reno_rep(REP_NEW_RENO_KILLED_BOSS);   \
                                                            set_dude_family(family_none)              \
                                                         end                                          \
                                                      end                                             \
                                                      debug_msg("called attack family("+(nr_mstr(200 + x))+")");
// made man end

#define check_companion(x)                            (obj_can_see_obj(self_obj, party_member_obj(x)))

// companions
#define myron_is_dude_companion                       check_companion(PID_MYRON)
#define robobrain_is_dude_companion                   check_companion(PID_BRAINBOT)
#define marcus_is_dude_companion                      check_companion(PID_MARCUS)
#define lenny_is_dude_companion                       check_companion(PID_LENNY)
#define sulik_is_dude_companion                       check_companion(PID_SULIK)
#define robodog_is_dude_companion                     check_companion(PID_CYBERDOG)
#ifndef miria_is_dude_companion
   #define miria_is_dude_companion                    check_companion(PID_MIRIA)
#endif
#define davin_is_dude_companion                       check_companion(PID_DAVIN)
#ifndef vic_is_dude_companion
   #define vic_is_dude_companion                      check_companion(PID_VIC)
#endif
#define macrae_is_dude_companion                      check_companion(PID_JOHN_MACRAE)

// insert message macro
variable floater_patch_msg;
#define floater_rand_with_check(x, y, the_patch, the_adj)                                                                     \
         floater_patch_msg := random(x, y);                                                                                   \
         if (is_insert_message(floater_patch_msg)) then begin                                                                 \
            float_msg(self_obj, mstr(floater_patch_msg) + the_patch + mstr(floater_patch_msg + the_adj), FLOAT_COLOR_NORMAL); \
         end else                                                                                                             \
            floater(floater_patch_msg)

#define set_new_reno_watcher(the_var)                 if ((obj_is_visible_flag(self_obj)) and (self_elevation == dude_elevation)) then begin                                                              \
	if (the_var == 0) then begin                                                                            \
		the_var := self_obj;                                                                                 \
	end else if ((obj_can_see_obj(the_var, dude_obj) == false) or (is_critter_dead(the_var))) then begin    \
		the_var := self_obj;                                                                                 \
	end                                                                                                     \
end


#ifndef mid_tile
	#define mid_tile(x,y)                              temp_tile := x;                                                                    \
													   while (tile_distance(temp_tile, y) > (tile_distance(x,y)/2)) do                    \
														  temp_tile := tile_num_in_direction(temp_tile, rotation_to_tile(temp_tile,y), 1)
#endif

#ifndef random_tile_in_box
	#define random_tile_in_box(ul, ur, lr, ll)         mid_tile(ul,lr);                                                                        \
													   temp_tile := tile_num_in_direction(temp_tile, random(0,5), (tile_distance(ul,lr))/2);   \
													   if (tile_in_box(temp_tile, ul, ur, lr, ll) == false) then temp_tile := 0
 #endif


#define Meet_Obj_Face(the_obj)                        if (tile_distance_objs(self_obj, the_obj) > 1) then begin                          \
	mid_tile(self_tile, tile_num(the_obj));                                         \
	animate_move_to_tile(temp_tile);                                                \
 end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin  \
	Face_Critter(the_obj, self_obj);                                                \
 end

 #define max_names_per_list                            (5)


 variable stored_msg;
 variable stored_node;
 variable top_msg;
 variable var_num;

// THESE ARE MORE OR LESS LIBRARY FUNCTIONS TO SET THE NAME OF THE MADE MAN, ETC.
procedure ChooseFromList;
procedure CLICK_PREV  begin
   top_msg -= max_names_per_list;
   call ChooseFromList;
end

#define finalize_option(x)    set_global_var(var_num, ((global_var(var_num)/100)*100) + ((x)%100))

procedure CLICK_0  begin
   finalize_option(top_msg);
   call stored_node;
end
procedure CLICK_1  begin
   finalize_option(top_msg + 1);
   call stored_node;
end
procedure CLICK_2  begin
   finalize_option(top_msg + 2);
   call stored_node;
end
procedure CLICK_3  begin
   finalize_option(top_msg + 3);
   call stored_node;
end
procedure CLICK_4  begin
   finalize_option(top_msg + 4);
   call stored_node;
end
procedure CLICK_MORE  begin
   top_msg += max_names_per_list;
   call ChooseFromList;
end

#define print_option(the_num, print_canceled)                        \
   if (print_canceled == false) then begin                           \
      if (nr_mstr(top_msg + the_num) != "") then begin               \
         NOption(nr_mstr(top_msg + the_num), CLICK_##the_num, 001);  \
      end else begin                                                 \
         print_canceled := true;                                     \
      end                                                            \
   end

procedure ChooseFromList begin
variable do_cancel;
   Reply(stored_msg);
   if (nr_mstr(top_msg - 1) != "") then begin
      NOption(nr_mstr(150), CLICK_PREV, 001);
   end
   print_option(0, do_cancel)
   print_option(1, do_cancel)
   print_option(2, do_cancel)
   print_option(3, do_cancel)
   print_option(4, do_cancel)
   if (do_cancel == false) then begin
      if (nr_mstr(top_msg + max_names_per_list) != "") then begin
         NOption(nr_mstr(151), CLICK_MORE, 001);
      end
   end
end


 #define setup_set_prizefighter_name(the_msg, the_node)                  \
 begin                                                          \
	var_num := GVAR_PRIZEFIGHTER;                      \
	top_msg := prizefighter_msg_start + 1;                      \
	stored_msg := the_msg;                                      \
	stored_node := the_node;                                    \
	call ChooseFromList;                                        \
 end


// boxing start
#define other_boxer_name                              nr_mstr(random(700, 719))
#define vs_boxer_name                                 nr_mstr(700 + (50 * fighting_main_boxer) + fight_level)

#define boxer_resting                                 (get_new_reno_flag(boxer_resting_bit, 3))
#define set_boxer_resting                             set_new_reno_flag_on(boxer_resting_bit, 3)
#define off_boxer_resting                             set_new_reno_flag_off(boxer_resting_bit, 3)

#define killed_opponent                               (get_new_reno_flag(killed_opponent_bit, 3))
#define set_killed_opponent                           set_new_reno_flag_on(killed_opponent_bit, 3)
#define off_killed_opponent                           set_new_reno_flag_off(killed_opponent_bit, 3)

#define boxer_killed                                  (get_new_reno_flag(boxer_killed_bit, 3))
#define set_boxer_killed                              set_new_reno_flag_on(boxer_killed_bit, 3)

#define pablo_dead                                 (get_new_reno_flag(pablo_dead_bit, 3))
#define set_pablo_dead                             set_new_reno_flag_on(pablo_dead_bit, 3)

#define guido_dead                                 (get_new_reno_flag(guido_dead_bit, 3))
#define set_guido_dead                             set_new_reno_flag_on(guido_dead_bit, 3)

#define enzo_dead                                 (get_new_reno_flag(enzo_dead_bit, 3))
#define set_enzo_dead                             set_new_reno_flag_on(enzo_dead_bit, 3)

#define dusty_dead                                 (get_new_reno_flag(dusty_dead_bit, 3))
#define set_dusty_dead                             set_new_reno_flag_on(dusty_dead_bit, 3)

#define frieda_dead                                 (get_new_reno_flag(frieda_dead_bit, 3))
#define set_frieda_dead                             set_new_reno_flag_on(frieda_dead_bit, 3)

#define ginger_dead                                 (get_new_reno_flag(ginger_dead_bit, 3))
#define set_ginger_dead                             set_new_reno_flag_on(ginger_dead_bit, 3)

#define milko_dead                                 (get_new_reno_flag(milko_dead_bit, 3))
#define set_milko_dead                             set_new_reno_flag_on(milko_dead_bit, 3)

#define ailis_dead                                 (get_new_reno_flag(ailis_dead_bit, 3))
#define set_ailis_dead                             set_new_reno_flag_on(ailis_dead_bit, 3)

#define major_dead                                 (get_new_reno_flag(major_dead_bit, 3))
#define set_major_dead                             set_new_reno_flag_on(major_dead_bit, 3)

#define crius_dead                                 (get_new_reno_flag(crius_dead_bit, 3))
#define set_crius_dead                             set_new_reno_flag_on(crius_dead_bit, 3)

#define knows_mizaru                               (get_new_reno_flag(knows_mizaru_bit, 3))
#define set_knows_mizaru                           set_new_reno_flag_on(knows_mizaru_bit, 3)

#define knows_kikazaru                             (get_new_reno_flag(knows_kikazaru_bit, 3))
#define set_knows_kikazaru                         set_new_reno_flag_on(knows_kikazaru_bit, 3)

#define knows_iwazaru                              (get_new_reno_flag(knows_iwazaru_bit, 3))
#define set_knows_iwazaru                          set_new_reno_flag_on(knows_iwazaru_bit, 3)

#define crazy_addict                               (get_new_reno_flag(crazy_addict_bit, 2))
#define set_crazy_addict                           set_new_reno_flag_on(crazy_addict_bit, 2)
#define off_crazy_addict                           set_new_reno_flag_off(crazy_addict_bit, 2)

#define set_knows_3s_code                           set_new_reno_flag_on(safe_code_3s_bit, 3)
#define dude_knows_3s_code                         (get_new_reno_flag(safe_code_3s_bit, 3))

#define set_knows_cc_code                           set_new_reno_flag_on(safe_code_cc_bit, 3)
#define dude_knows_cc_code                         (get_new_reno_flag(safe_code_cc_bit, 3))

#define mckneely_dead                                 (get_new_reno_flag(mckneely_dead_bit, 3))
#define set_mckneely_dead                             set_new_reno_flag_on(mckneely_dead_bit, 3)

#define holyfeld_dead                                 (get_new_reno_flag(holyfeld_dead_bit, 3))
#define set_holyfeld_dead                             set_new_reno_flag_on(holyfeld_dead_bit, 3)

#define masticator_dead                               (get_new_reno_flag(masticator_dead_bit, 3))
#define set_masticator_dead                           set_new_reno_flag_on(masticator_dead_bit, 3)
#define masticator_bit_ear                            (get_new_reno_flag(masticator_bit_ear_bit, 3))
#define set_masticator_bit_ear                        if (masticator_bit_ear == false) then begin           \
                                                         set_critter_stat(dude_obj, STAT_ch, -1);           \
                                                         display_msg(nr_mstr(1600));                        \
                                                         if (dude_dark_dreadlocks or dude_dark_black_buzz) then begin          \
                                                            give_pid_qty(dude_obj, PID_PLAYERS_EAR_DARK_SKIN, 1)         \
                                                         end                                                               \
                                                         else if (dude_is_super_mutant) then begin                          \
                                                            give_pid_qty(dude_obj, PID_PLAYERS_EAR_SUPERMUTANT, 1)         \
                                                         end                                                        \
                                                         else if (dude_is_ghoul) then begin                          \
                                                            give_pid_qty(dude_obj, PID_PLAYERS_EAR_GHOUL, 1)         \
                                                         end                                                  \
                                                         else begin                                           \
                                                            give_pid_qty(dude_obj, PID_PLAYERS_EAR, 1)         \
                                                         end                                                   \
                                                      end                                                   \
                                                      set_new_reno_flag_on(masticator_bit_ear_bit, 3)
#define player_bites_masticator_ear                   (get_new_reno_flag(player_bites_masticator_ear_bit, 4))
#define set_player_bites_masticator_ear               if (player_bites_masticator_ear == false) then begin  \
                                                         display_msg(nr_mstr(1700));                        \
                                                         give_pid_qty(dude_obj, PID_MASTICATORS_EAR, 1)     \
                                                      end                                                   \
                                                      set_new_reno_flag_on(player_bites_masticator_ear_bit, 4)

#define stuart_deal                                   (global_var(GVAR_STUART_DEAL))
#define set_stuart_deal(x)                            set_global_var(GVAR_STUART_DEAL, x)

#define fight_level_done                              (3)
#define fight_level                                   (global_var(GVAR_FIGHT_LEVEL))
#define inc_fight_level                               if (global_var(GVAR_FIGHT_LEVEL) <= fight_level_done) then begin  \
                                                         display_msg(nr_mstr(1400 + fight_level + ( ((fight_level >= 3) and (not(fighting_main_boxer))) * 2 )));                               \
                                                         inc_global_var(GVAR_FIGHT_LEVEL);                              \
                                                         if (fight_level == 1) then begin                                        \
                                                            give_xp(EXP_NEW_RENO_BOXER_LEVEL_1);                                 \
                                                            inc_reno_rep(REP_NEW_RENO_BOXER_LEVEL_1);                            \
                                                         end else if (fight_level == 2) then begin                               \
                                                            give_xp(EXP_NEW_RENO_BOXER_LEVEL_2);                                 \
                                                            inc_reno_rep(REP_NEW_RENO_BOXER_LEVEL_2);                            \
                                                         end else if (fight_level == 3) then begin                               \
                                                            give_xp(EXP_NEW_RENO_BOXER_LEVEL_3);                                 \
                                                            inc_reno_rep(REP_NEW_RENO_BOXER_LEVEL_3);                            \
                                                         end else if (fight_level == 4) then begin                               \
                                                            give_xp(EXP_NEW_RENO_BOXER_LEVEL_4);                                 \
                                                            inc_reno_rep(REP_NEW_RENO_BOXER_LEVEL_4);                            \
                                                            critter_mod_skill(dude_obj, SKILL_UNARMED_COMBAT, 5);                \
                                                            global_temp := get_pc_extra_stat(STAT_dmg_resist) + 5;               \
                                                            set_pc_extra_stat(STAT_dmg_resist, global_temp);                     \
                                                            set_global_var(GVAR_HAS_REP_PRIZEFIGHTER, 1);               \
                                                            display_msg(nr_mstr(1404));                                          \
                                                         end                                                                     \
                                                      end                                                                        \
                                                      debug_msg("inc_fight_level == " + fight_level)

#define split_stuart_deal(x)                          item_caps_adjust(dude_obj, ((100 - stuart_deal) * x)/100);  \
                                                      item_caps_adjust(self_obj, (stuart_deal * x)/100);

#define collect_fight_money                           if (stuart_deal != 0) then begin                      \
                                                         if (fight_level == 2) then begin                   \
                                                            split_stuart_deal(800)                          \
                                                         end else if (fight_level == 3) then begin          \
                                                            split_stuart_deal(2000)                         \
                                                         end else begin                                     \
                                                            split_stuart_deal(100)                          \
                                                         end                                                \
                                                      end

#define fighting_main_boxer                           (get_new_reno_flag(fighting_main_boxer_bit, 3))
#define set_fighting_main_boxer                       set_new_reno_flag_on(fighting_main_boxer_bit, 3)
#define off_fighting_main_boxer                       set_new_reno_flag_off(fighting_main_boxer_bit, 3)

#define fight_is_on                                   get_new_reno_flag(fight_is_on_bit, 3)
#define set_fight_is_on                               set_new_reno_flag_on(fight_is_on_bit, 3)
#define off_fight_is_on                               set_new_reno_flag_off(fight_is_on_bit, 3)
#define create_boxer                                                                                        \
         set_fighting_main_boxer;                                                                           \
         if (fight_level == 1) then begin                                                                   \
            if (mckneely_dead == false) then begin                                                          \
               prize_fighter_obj := PID_MITCH_STILLER;                                                           \
               if (mckneely_obj != 0) then begin                                                            \
                  check_set_obj_visibility(mckneely_obj, true);                                            \
               end                                                                                          \
            end else begin                                                                                  \
               prize_fighter_obj := PID_BOXER;                                                            \
               off_fighting_main_boxer;                                                                     \
            end                                                                                             \
         end else if (fight_level == 2) then begin                                                          \
            if (holyfeld_dead == false) then begin                                                          \
               prize_fighter_obj := PID_VINNIE_GIORDANO;                                                           \
               if (hollyfeld_obj != 0) then begin                                                           \
                  check_set_obj_visibility(hollyfeld_obj, true);                                           \
               end                                                                                          \
            end else begin                                                                                  \
               prize_fighter_obj := PID_BOXER;                                                            \
               off_fighting_main_boxer;                                                                     \
            end                                                                                             \
         end else if (fight_level == 3) then begin                                                          \
            if (masticator_dead == false) then begin                                                        \
               prize_fighter_obj := PID_MALLET_MCBRIDE;                                                         \
            end else begin                                                                                  \
               prize_fighter_obj := PID_BOXER;                                                            \
               off_fighting_main_boxer;                                                                     \
            end                                                                                             \
         end else begin                                                                                     \
            if (milko_dead == false) then begin                                                        \
               prize_fighter_obj := PID_MILKO;                                                               \
            end else begin                                                                                  \
               prize_fighter_obj := PID_BOXER;                                                            \
               off_fighting_main_boxer;                                                                     \
            end                                                                                             \
         end                                                                                                \
         prize_fighter_obj := create_object_sid(prize_fighter_obj, 0, 0, SCRIPT_HDPRZFTR);                  \
         if ((prize_fighter_obj == PID_VINNIE_GIORDANO) or (prize_fighter_obj == PID_MALLET_MCBRIDE)) then begin    \
            give_pid_qty(prize_fighter_obj, PID_PLATED_BOXING_GLOVES, 1)                                       \
         end                                                                                                    \
         else if ((prize_fighter_obj == PID_MITCH_STILLER) or (prize_fighter_obj == PID_MILKO)) then begin                                                     \
            give_pid_qty(prize_fighter_obj, PID_BOXING_GLOVES, 1)                                       \
         end                                                                                           \
         else begin                                                                                            \
            give_pid_qty(prize_fighter_obj, PID_SPECIAL_BOXER_WEAPON, 1)                                       \
         end                                                                                                             \
         switch_team(prize_fighter_obj, TEAM_HOOVER_DAM_FIGHTING_BOXER)   \
         critter_add_trait(prize_fighter_obj, TRAIT_OBJECT, OBJECT_AI_PACKET, AI_BOXER);                    \
         debug_msg("creating boxer")

#define fight_status_fighting                         (0)
#define fight_status_ko                               (1)
#define fight_status_tko                              (2)
#define fight_status_disqualified                     (3)
#define fight_status_decision                         (4)

#define fight_status_raw                              (global_var(GVAR_FIGHT_STATUS))
#define fight_status                                  (fight_status_raw + (-2 * fight_status_raw * (fight_status_raw < 0)))
#define check_fight_status(x)                         (fight_status_raw == x)
#define set_fight_status(x)                           if (x != fight_status_fighting) then begin                                  \
                                                         if (check_fight_status(fight_status_fighting)) then begin                \
                                                            set_global_var(GVAR_FIGHT_STATUS, x);                        \
                                                            nr_add_timer_event(announcer_obj, 5, 200);                            \
                                                         end                                                                      \
                                                      end else set_global_var(GVAR_FIGHT_STATUS, fight_status_fighting); \
                                                      debug_msg("set_fight_status("+x+") == "+fight_status_raw)
#define dude_won_fight                                (fight_status_raw > 0)
#define boxer_won_fight                               (fight_status_raw < 0)

#define dude_punches                                  (local_var(LVAR_Dude_Punches))
#define inc_dude_punches                              inc_local_var(LVAR_Dude_Punches);              \
                                                      debug_msg("total punches dude thrown == " + dude_punches)
#define clear_dude_punches                            set_local_var(LVAR_Dude_Punches, 0)

#define boxer_punches                                 (local_var(LVAR_Self_Punches))
#define inc_boxer_punches                             inc_local_var(LVAR_Self_Punches);              \
                                                      debug_msg("total punches boxer thrown == " + boxer_punches)
#define clear_boxer_punches                           set_local_var(LVAR_Self_Punches, 0)

#define boxer_score                                   (global_var(GVAR_BOXER_SCORE))
#define inc_boxer_score(x)                            inc_global_var_amt(GVAR_BOXER_SCORE, x)
#define clear_boxer_score                             set_global_var(GVAR_BOXER_SCORE, 0)

#define dude_score                                    (global_var(GVAR_DUDE_SCORE))
#define inc_dude_score(x)                             inc_global_var_amt(GVAR_DUDE_SCORE, x)
#define clear_dude_score                              set_global_var(GVAR_DUDE_SCORE, 0)

#define currently_fighting                            (global_var(GVAR_ROUND_TIME) != 0)
#define seconds_til_round_over                        ((global_var(GVAR_ROUND_TIME) - game_time)/10)
#define round_time_over                               ((seconds_til_round_over <= 0) and (currently_fighting))
#define set_new_round_time                            set_global_var(GVAR_ROUND_TIME, game_time + ONE_GAME_MINUTE)

#define move_boxers_to_corners                        debug_msg("move_boxers_to_corners: start");              \
                                                      move_to(dude_obj, 21922, self_elevation);                \
                                                      critter_uninjure(dude_obj, DAM_KNOCKED_DOWN);            \
                                                      if ((prize_fighter_obj != 0) and (killed_opponent == false)) then begin   \
                                                         move_to(prize_fighter_obj, 23514, self_elevation);    \
                                                         animate_stand_obj(prize_fighter_obj);                 \
                                                         critter_uninjure(prize_fighter_obj, DAM_KNOCKED_DOWN);\
                                                         Face_Critter(prize_fighter_obj, dude_obj);            \
                                                         Face_Critter(dude_obj, prize_fighter_obj);            \
                                                      end                                                      \
                                                      animate_stand_obj(dude_obj);                             \
                                                      debug_msg("move_boxers_to_corners: end");
#define start_boxing_match                            debug_msg("start boxing match: start");                  \
                                                      fadeout(ONE_GAME_SECOND);                              \
                                                         set_fight_is_on;                                      \
                                                         set_ui_should_be_disabled;                            \
                                                         reg_anim_clear(dude_obj);                             \
                                                         move_obj_inven_to_obj(dude_obj, generic_temp_box);   \
                                                         clear_dude_score;                                     \
                                                         clear_boxer_score;                                    \
                                                         off_killed_opponent;                                  \
                                                         set_global_var(GVAR_ROUND_TIME, 0);          \
                                                         set_fight_status(fight_status_fighting);              \
                                                         if (game_time_hour < 2100) then begin                 \
                                                            game_time_advance_hour(2100);                      \
                                                         end                                                   \
                                                         set_global_var(GVAR_ROUND_NUMBER, 1);        \
                                                         if (fighting_boxer_1_obj != 0) then begin             \
                                                            check_set_obj_visibility(fighting_boxer_1_obj, true);    \
                                                         end                                                   \
                                                         if (fighting_boxer_2_obj != 0) then begin             \
                                                            check_set_obj_visibility(fighting_boxer_2_obj, true);    \
                                                         end                                                   \
                                                         if (obj_carrying_pid_obj(generic_temp_box, PID_PLATED_BOXING_GLOVES)) then begin    \
                                                            give_pid_qty(dude_obj, PID_SPECIAL_PLATED_BOXING_GLOVES, 1)                      \
                                                            wield_obj_critter(dude_obj, restock_obj);                                \
                                                         end else if (obj_carrying_pid_obj(generic_temp_box, PID_BOXING_GLOVES)) then begin  \
                                                            give_pid_qty(dude_obj, PID_SPECIAL_BOXING_GLOVES, 1)                             \
                                                            wield_obj_critter(dude_obj, restock_obj);          \
                                                         end                                                   \
                                                         move_to(dude_obj, tile_num(announcer_obj), self_elevation); \
                                                         create_boxer;                                         \
                                                         move_boxers_to_corners                                \
                                                         check_set_obj_visibility(announcer_obj, false);      \
                                                         check_set_obj_visibility(ring_girl_obj, false);      \
                                                         if (fight_level == 1) then begin                      \
                                                            if (pablo_dead == false) then begin                \
                                                               check_set_obj_visibility(pablo_obj, false);      \
                                                            end                                                  \
                                                         end                                                   \
                                                         else if (fight_level == 2) then begin                 \
                                                            if (dusty_dead == false) then begin                \
                                                               check_set_obj_visibility(dusty_obj, false);      \
                                                            end                                                  \
                                                            if (enzo_dead == false) then begin                \
                                                               check_set_obj_visibility(enzo_obj, false);      \
                                                            end                                                  \
                                                            if (guido_dead == false) then begin                \
                                                               check_set_obj_visibility(guido_obj, false);      \
                                                            end                                                  \
                                                         end                                                   \
                                                         else if (fight_level == 3) then begin                  \
                                                            if (frieda_dead == false) then begin                \
                                                               check_set_obj_visibility(frieda_obj, false);      \
                                                            end                                                  \
                                                            if ((ginger_dead == false) and (masticator_dead == false)) then begin                \
                                                               check_set_obj_visibility(ginger_obj, false);      \
                                                            end                                                  \
                                                         end                                                    \
                                                         nr_add_timer_event(announcer_obj, 5, 100);            \
                                                      fadein(ONE_GAME_SECOND);                               \
                                                      debug_msg("tile_set_center(tile_num(announcer_obj)): " + tile_set_center(tile_num(announcer_obj))); \
                                                      debug_msg("start boxing match: end")
#define heal_boxer(x)                                 critter_heal(x, get_critter_stat(x, STAT_en))

#define start_boxing_round                            debug_msg("start boxing round: start");                  \
                                                      fadeout(ONE_GAME_SECOND);                              \
                                                         game_time_advance(ONE_GAME_MINUTE);                   \
                                                         check_set_obj_visibility(announcer_obj, true);       \
                                                         check_set_obj_visibility(ring_girl_obj, true);       \
                                                         float_msg(dude_obj, message_str(SCRIPT_HDRNGGRL,100) + global_var(GVAR_ROUND_NUMBER) + message_str(SCRIPT_HDRNGGRL,101), FLOAT_MSG_WARNING); \
                                                         move_boxers_to_corners                                \
                                                         set_new_round_time;                                   \
                                                      fadein(ONE_GAME_SECOND);                               \
                                                      off_ui_should_be_disabled;                               \
                                                      play_sfx("boxbell1");                                     \
                                                      attack_setup(prize_fighter_obj, dude_obj);               \
                                                      debug_msg("start boxing round: end")
#define end_boxing_round                              play_sfx("boxbell2");                                                    \
                                                         terminate_combat;                                                    \
                                                         fadeout(ONE_GAME_SECOND);                                          \
                                                         check_set_obj_visibility(announcer_obj, true);                      \
                                                         check_set_obj_visibility(ring_girl_obj, true);                      \
                                                         debug_msg("end boxing round start");                                 \
                                                         set_ui_should_be_disabled;                                           \
                                                         debug_msg("combat terminated");                                      \
                                                         set_global_var(GVAR_ROUND_TIME, 0);                         \
                                                         inc_global_var(GVAR_ROUND_NUMBER);                          \
                                                         animate_stand_obj(dude_obj);                                         \
                                                         if ((prize_fighter_obj != 0) and (killed_opponent == false)) then begin   \
                                                            animate_stand_obj(prize_fighter_obj);                             \
                                                         end                                                                  \
                                                         if (check_fight_status(fight_status_fighting)) then begin            \
                                                            debug_msg("check_fight_status(fight_status_fighting)");           \
                                                            move_boxers_to_corners                                            \
                                                            inc_dude_score(9);                                                \
                                                            inc_boxer_score(9);                                               \
                                                            if ((dude_punches > boxer_punches) or ((dude_punches == boxer_punches) and (random(0,1)))) then begin  \
                                                               inc_dude_score(1);                                             \
                                                            end else begin                                                    \
                                                               inc_boxer_score(1);                                            \
                                                            end                                                               \
                                                            if (global_var(GVAR_ROUND_NUMBER) <= 12) then begin      \
                                                               heal_boxer(dude_obj);                                          \
                                                               heal_boxer(prize_fighter_obj);                                 \
                                                               clear_dude_punches;                                            \
                                                               clear_boxer_punches;                                           \
                                                               check_set_obj_visibility(ring_girl_obj, false);               \
                                                               nr_add_timer_event(announcer_obj, 5, 110);                     \
                                                            end else begin                                                    \
                                                               if (boxer_score > dude_score) then begin                       \
                                                                  lose_boxing_match(fight_status_decision);                   \
                                                               end else begin                                                 \
                                                                  win_boxing_match(fight_status_decision);                    \
                                                               end                                                            \
                                                            end                                                               \
                                                         end                                                                  \
                                                         set_ui_should_be_disabled;                                           \
                                                      fadein(ONE_GAME_SECOND);                                              \
                                                      debug_msg("end boxing round end")

#define call_fight_over                               debug_msg("call fight over: start");                           \
                                                      fadeout(ONE_GAME_SECOND);                                    \
                                                         set_global_var(GVAR_ROUND_TIME, 0);                \
                                                         set_ui_should_be_disabled;                                  \
                                                         move_to(dude_obj, 22319, self_elevation);                   \
                                                         anim(dude_obj, ANIMATE_ROTATION, 3);                        \
                                                         if (prize_fighter_obj != 0) then begin                      \
                                                            if (killed_opponent) then begin                          \
                                                               check_set_obj_visibility(prize_fighter_obj, true);   \
                                                               prize_fighter_obj := 0;                               \
                                                            end else begin                                           \
                                                               animate_stand_obj(prize_fighter_obj);                 \
                                                               critter_uninjure(prize_fighter_obj, DAM_KNOCKED_DOWN);\
                                                               move_to(prize_fighter_obj, 22917, self_elevation);    \
                                                               anim(prize_fighter_obj, ANIMATE_ROTATION, 3);         \
                                                            end                                                      \
                                                         end                                                         \
                                                         check_set_obj_visibility(ring_girl_obj, true);             \
                                                         check_set_obj_visibility(announcer_obj, false);            \
                                                         set_ui_should_be_disabled;                                  \
                                                      fadein(ONE_GAME_SECOND);                                     \
                                                      debug_msg("call fight over: end")

#define lose_boxing_match(x)                          set_fight_status(-x);            \
                                                      call_fight_over;                 \
                                                      debug_msg("lose boxing match: "+ self_name)
#define win_boxing_match(x)                           set_fight_status(x);             \
                                                      call_fight_over;                 \
                                                      debug_msg("win boxing match: " + self_name)
#define cleanup_boxing_match                          debug_msg("cleanup boxing match: start");                                                                                                                                  \
                                                      fadeout(ONE_GAME_SECOND);                                                                                                                                                \
                                                         set_ui_should_be_disabled;                                                                                                                                              \
                                                         off_fight_is_on;                                                                                                                                                        \
                                                         if (prize_fighter_obj != 0) then begin                                                                                                                                  \
                                                            destroy_object(prize_fighter_obj);                                                                                                                                   \
                                                         end                                                                                                                                                                     \
                                                         check_set_obj_visibility(announcer_obj, true);                                                                                                                         \
                                                         check_set_obj_visibility(frieda_obj, true);             \
                                                         check_set_obj_visibility(enzo_obj, true);             \
                                                         check_set_obj_visibility(guido_obj, true);             \
                                                         check_set_obj_visibility(dusty_obj, true);             \
                                                         check_set_obj_visibility(ginger_obj, true);             \
                                                         check_set_obj_visibility(pablo_obj, true);             \
                                                         remove_pid_qty(dude_obj, PID_SPECIAL_PLATED_BOXING_GLOVES, 1)                                                                                                           \
                                                         remove_pid_qty(dude_obj, PID_SPECIAL_BOXING_GLOVES, 1)                                                                                                                  \
                                                         move_obj_inven_to_obj(generic_temp_box, dude_obj);                                                                                                                     \
                                                         critter_attempt_placement(dude_obj, tile_num_in_direction(tile_num(stuart_little_obj), has_trait(TRAIT_OBJECT,stuart_little_obj,OBJECT_CUR_ROT), 1), self_elevation);   \
                                                         Face_Critter(stuart_little_obj, dude_obj);                                                                                                                              \
                                                         Face_Critter(dude_obj, stuart_little_obj);                                                                                                                              \
                                                         check_set_obj_visibility(ring_girl_obj, true);            \
                                                         check_set_obj_visibility(announcer_obj, true);            \
                                                         nr_add_timer_event(stuart_little_obj, 2, fight_over_param);                                                                                                             \
                                                         game_time_advance(ONE_GAME_MINUTE);                                                                                                                                     \
                                                      debug_msg("cleanup boxing match: end")

#define hidden_for_fight                              lvar_bit(LVAR_Flags, hidden_for_fight_bit)
#define set_hidden_for_fight                          set_lvar_bit_on(LVAR_Flags, hidden_for_fight_bit)
#define off_hidden_for_fight                          set_lvar_bit_off(LVAR_Flags, hidden_for_fight_bit)
#define check_hide_durring_boxing_fight               if (fight_is_on) then begin                                             \
                                                         if (obj_is_visible_flag(self_obj)) then begin                        \
                                                            if (tile_boxing_gym_building(self_tile) == false) then begin      \
                                                               check_set_obj_visibility(self_obj, true);                     \
                                                               set_hidden_for_fight;                                          \
                                                            end                                                               \
                                                         end                                                                  \
                                                      end else if (hidden_for_fight) then begin                               \
                                                         check_set_obj_visibility(self_obj, false);                          \
                                                         off_hidden_for_fight;                                                \
                                                      end
// boxing end

// GVAR_DR_YURI_KNOW_PEOPLE stuff
#define DR_YURI_KNOW_PIERRE           bit_1
#define DR_YURI_KNOW_CANDICE          bit_2
#define DR_YURI_KNOW_GOVERNOR         bit_3

#define get_dr_yuri_know_people_flag(x)    (global_var(GVAR_DR_YURI_KNOW_PEOPLE) bwand x)
#define set_dr_yuri_know_people_flag(x)    set_global_var(GVAR_DR_YURI_KNOW_PEOPLE, global_var(GVAR_DR_YURI_KNOW_PEOPLE) bwor x)

// raiders macros start
#define raiders_dead_bit                              bit_1
#define raiders_marcus_bit                            bit_2
#define raiders_robobrain_bit                         bit_3
#define raiders_bonenose_bit                          bit_4
#define raiders_alarm_bit                             bit_5
#define know_3s_trap_bit                         bit_6
#define raiders_scout_left_bit                        bit_7
#define know_cc_trap_bit                         bit_8


#define raiders_dead                                  gvar_bit(GVAR_HD_SAFE_FLAGS, raiders_dead_bit)
#define set_raiders_dead                              set_gvar_bit_on(GVAR_HD_SAFE_FLAGS, raiders_dead_bit)
#define raiders_marcus                                gvar_bit(GVAR_HD_SAFE_FLAGS, raiders_marcus_bit)
#define set_raiders_marcus                            set_gvar_bit_on(GVAR_HD_SAFE_FLAGS, raiders_marcus_bit)
#define raiders_robobrain                             gvar_bit(GVAR_HD_SAFE_FLAGS, raiders_robobrain_bit)
#define set_raiders_robobrain                         set_gvar_bit_on(GVAR_HD_SAFE_FLAGS, raiders_robobrain_bit)
#define raiders_bonenose                              gvar_bit(GVAR_HD_SAFE_FLAGS, raiders_bonenose_bit)
#define set_raiders_bonenose                          set_gvar_bit_on(GVAR_HD_SAFE_FLAGS, raiders_bonenose_bit)
#define raiders_alarm                                 gvar_bit(GVAR_HD_SAFE_FLAGS, raiders_alarm_bit)
#define set_raiders_alarm                             set_gvar_bit_on(GVAR_HD_SAFE_FLAGS, raiders_alarm_bit)
#define off_raiders_alarm                             set_gvar_bit_off(GVAR_HD_SAFE_FLAGS, raiders_alarm_bit)

#define know_3s_trap                             gvar_bit(GVAR_HD_SAFE_FLAGS, know_3s_trap_bit)
#define set_know_3s_trap                         set_gvar_bit_on(GVAR_HD_SAFE_FLAGS, know_3s_trap_bit)
#define off_know_3s_trap                         set_gvar_bit_off(GVAR_HD_SAFE_FLAGS, know_3s_trap_bit)

#define know_cc_trap                             gvar_bit(GVAR_HD_SAFE_FLAGS, know_cc_trap_bit)
#define set_know_cc_trap                         set_gvar_bit_on(GVAR_HD_SAFE_FLAGS, know_cc_trap_bit)
#define off_know_cc_trap                         set_gvar_bit_off(GVAR_HD_SAFE_FLAGS, know_cc_trap_bit)

// raiders macros end

#define raider_add_timer_event(obj, sec, param)          rm_fixed_timer_event(obj, param);               \
                                                         add_timer_event(obj, game_ticks(sec), param)
#define raider_add_timer_event_rand(obj, x, y, param)    raider_add_timer_event(obj, random(x, y), param)

// TODO ZZZ
#define dude_knows_mary_jo                      (global_var(GVAR_KNOW_MARY_JO) == 1)
#define dude_knows_mary_jo_birthmark            (global_var(GVAR_KNOW_MARY_JO_BIRTHMARK) == 1)

#define cc_dead                                 ((global_var(GVAR_QUEST_ARREST_AILIS) != QUEST_NONE) or ailis_dead)
#define is_3s_dead                              (enzo_dead == true)

#define dusty_desires_bar_fight_on                      (false)

#define dude_chasing_a_bounty ((global_var(GVAR_QUEST_12_CRAIG_BOUNTY) == QUEST_ACCEPTED) or (global_var(GVAR_QUEST_12_MIGUEL_BOUNTY) == QUEST_ACCEPTED) or (global_var(GVAR_QUEST_12_NANCY_BOUNTY) == QUEST_ACCEPTED) or (global_var(GVAR_QUEST_12_INGMAR_BOUNTY) == QUEST_ACCEPTED) or (global_var(GVAR_QUEST_12_KYLE_BOUNTY) == QUEST_ACCEPTED) or (global_var(GVAR_QUEST_12_RYAN_BOUNTY) == QUEST_ACCEPTED))

#define dude_did_all_bounties ((global_var(GVAR_QUEST_12_CRAIG_BOUNTY) == QUEST_COMPLETED) and (global_var(GVAR_QUEST_12_MIGUEL_BOUNTY) == QUEST_COMPLETED) and (global_var(GVAR_QUEST_12_NANCY_BOUNTY) == QUEST_COMPLETED) and (global_var(GVAR_QUEST_12_INGMAR_BOUNTY) == QUEST_COMPLETED) and (global_var(GVAR_QUEST_12_KYLE_BOUNTY) == QUEST_COMPLETED) and (global_var(GVAR_QUEST_12_RYAN_BOUNTY) == QUEST_COMPLETED))

#define check_visible_townsperson                     if (random(1, 10) <= 6 + (night)) then begin \
                                                         check_set_obj_visibility(self_obj, false);      \
                                                      end else begin                               \
                                                         check_set_obj_visibility(self_obj, true);       \
                                                      end

procedure check_watcher_3s(variable watcher, variable intruder) begin
   // Someone is watching this door and we have been caught
   if ((watcher != 0) and (obj_can_see_obj(watcher, intruder) or obj_can_hear_obj(watcher, intruder))) then begin
      if (not(critter_state(watcher) bwand (DAM_KNOCKED_OUT bwor DAM_DEAD bwor DAM_ON_FIRE bwor DAM_EXPLODE bwor DAM_DESTROY)) and obj_is_visible_flag(watcher) and (elevation(watcher) == dude_elevation)) then
          float_msg(watcher, message_str(SCRIPT_GENERIC, random(3325, 3329)), FLOAT_COLOR_BAD);
      if (not(is_critter_dead(watcher))) then begin
         attack_setup(watcher, intruder);
      end
  end
end

#define finish_quest_meet_dodge                    if (global_var(GVAR_QUEST_MEET_DODGE) == 1) then begin  \
                                                      set_global_var(GVAR_QUEST_MEET_DODGE, 2);            \
                                                      give_xp(500);                                               \
                                                      display_msg(g_mstr(1001));             \
                                                   end

#endif // HDAM_H
