/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef COMMAND_H
#define COMMAND_H

//Did the above so I could include it in define.h without inheritance problems

/*********************************************************
 define file for commands dealing with the dude.

 Contents of the File:
        I.      Flee from Player
        II.     Player Information
        III.    Dialogue Information
*********************************************************/

// include files that are needed after other declarations are made.
#include "..\headers\reppoint.h"
#include "..\headers\define_extra.h"
#include "..\headers\lib.arrays.h"

/*********************************************************
 General interaction dealing with the dude
 should he attack people in a community
*********************************************************/
variable global_temp;

#define Get_Rotation_Away_From_Dude(x)      rotation_to_tile(tile_num(dude_obj),tile_num(x))

#define Run_Away_From_Dude_Dir              Get_Rotation_Away_From_Dude(self_obj)
#define run_away_from_dist                  random(3, 10)
#define push_away_from_dist                 random(2, 5)

#define run_away_tile_dir(x)                tile_num_in_direction(tile_num(self_obj), x, run_away_from_dist)
#define Run_Away_From_Dude_Tile             run_away_tile_dir(Run_Away_From_Dude_Dir)

#define Current_Distance_From_Obj(the_obj)  tile_distance_objs(self_obj,the_obj)
#define Current_Distance_From_Dude          Current_Distance_From_Obj(dude_obj)

#define Future_Distance_From_Obj(x, y)      tile_num_in_direction(tile_num(x), ((has_trait(TRAIT_OBJECT,x,OBJECT_CUR_ROT) + 3)%6), y)
#define Future_Distance_From_Dude(x)        Future_Distance_From_Obj(dude_obj, x)

#define away_from_tile_type(x, type, dist)  if (anim_busy(self_obj) == false) then begin                                                             \
                                               global_temp := rotation_to_tile(x, self_tile);                                                        \
                                               animate_##type##_to_tile(tile_num_in_direction(self_tile, global_temp, dist));                        \
                                               global_temp := (global_temp + 1) % 6;                                                                 \
                                               while ((anim_busy(self_obj) == false) and (global_temp != rotation_to_tile(x, self_tile))) do begin   \
                                                  debug_msg("flee loop: rot == "+global_temp);                                                       \
                                                  animate_##type##_to_tile(tile_num_in_direction(self_tile, global_temp, dist));                     \
                                                  global_temp := (global_temp + 1) % 6;                                                              \
                                               end                                                                                                   \
                                            end

#define simulate_push(x)                    away_from_tile_type(tile_num_in_direction(self_tile, rotation_to_tile(x, self_tile), 1), move, push_away_from_dist)
#define flee_from_tile(x)                   away_from_tile_type(x, run, run_away_from_dist)
#define Flee_From_Dude                      if ((Current_Distance_From_Dude < 8) or (self_can_see_dude) or (self_can_hear_dude)) then begin  \
                                               flee_from_tile(dude_tile)                                             \
                                            end

#define Flee_From_Dude_Force                if ((Current_Distance_From_Dude < 8) or (self_can_see_dude) or (self_can_hear_dude)) then begin  \
                                                animate_run_to_tile_force(Run_Away_From_Dude_Tile);                  \
                                            end

#define Follow_Dude(X,Y)                    if (Current_Distance_From_Dude > X) then begin                  \
                                               if (Current_Distance_From_Dude > X*2) then begin             \
                                                  animate_run_to_tile(Future_Distance_From_Dude(Y));        \
                                               end else begin                                               \
                                                  animate_move_to_tile(Future_Distance_From_Dude(Y));       \
                                               end                                                          \
                                            end

#define get_follow_point_dist(the_obj)      ((tile_distance_objs(the_obj, self_obj) / 5) + 1)
#define follow_obj_point(the_range, the_dist, the_obj)                                                            \
                                            if (Current_Distance_From_Dude > the_range) then begin                \
                                                if (Current_Distance_From_Dude > (the_range * 2)) then begin    \
                                                   anim_run_to_point_rate(tile_num_in_direction(tile_num(the_obj), rotation_to_tile(tile_num(the_obj), self_tile), the_dist), get_follow_point_dist(the_obj))   \
                                                end else begin                                                  \
                                                   anim_move_to_point_rate(tile_num_in_direction(tile_num(the_obj), rotation_to_tile(tile_num(the_obj), self_tile), the_dist), get_follow_point_dist(the_obj))  \
                                                end                                                             \
                                            end
#define party_follow_dude_point(the_range, the_dist)                                                              \
                                            if (Current_Distance_From_Dude > the_range) then begin                \
                                                if (anim_busy(self_obj) == false) then begin                      \
                                                   dest_tile := tile_num_in_direction(tile_num_in_direction(dude_tile, Run_Away_From_Dude_Dir, the_dist), random(0, 5), random(0, 2)); \
                                                   if (Current_Distance_From_Dude > (the_range * 2)) then begin   \
                                                      animate_run_to_tile(dest_tile);                             \
                                                   end else begin                                                 \
                                                      animate_move_to_tile(dest_tile);                            \
                                                   end                                                            \
                                                end else if (self_distance_from_dude < tile_distance(self_tile, dest_tile)) then begin  \
                                                   reg_anim_clear(self_obj);                                      \
                                                end                                                               \
                                            end
#define follow_dude_point(the_range, the_dist)     follow_obj_point(the_range, the_dist, dude_obj)

#define Follow_Dude_Run_Only(X,Y)           if (Current_Distance_From_Dude > X) then begin                  \
                                               animate_run_to_tile(Future_Distance_From_Dude(Y));           \
                                            end

#define Follow_Obj_Run_Only(O,X,Y)          if (tile_distance_objs(self_obj,O) > X) then begin              \
                                               animate_run_to_tile(Future_Distance_From_Obj(O, Y));         \
                                            end
#define Get_In_Obj_Face(the_obj)            if (tile_distance_objs(self_obj, the_obj) > 1) then begin                                                              \
                                               animate_move_to_tile(tile_num_in_direction(tile_num(the_obj), has_trait(TRAIT_OBJECT,the_obj,OBJECT_CUR_ROT), 1));  \
                                            end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin                        \
                                               if (anim_busy(self_obj) == false) then begin                                                                        \
                                                  Face_Critter(the_obj, self_obj);                                                                                 \
                                               end                                                                                                                 \
                                            end
#define Get_In_Face_Run_Dist(the_obj,dist)  if (tile_distance_objs(self_obj, the_obj) > 1) then begin                                                              \
                                               animate_run_to_tile(tile_num_in_direction(tile_num(the_obj), has_trait(TRAIT_OBJECT,the_obj,OBJECT_CUR_ROT), dist));\
                                            end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin                        \
                                               if (anim_busy(self_obj) == false) then begin                                                                        \
                                                  Face_Critter(the_obj, self_obj);                                                                                 \
                                               end                                                                                                                 \
                                            end

#define next_and_face_obj(the_obj, the_type, the_rate)                                                                                                                       \
                                             if (tile_distance_objs(self_obj, the_obj) > 1) then begin                                                             \
                                                the_type(tile_num_in_direction(tile_num(the_obj), rotation_to_tile(tile_num(the_obj),tile_num(self_obj)), 1)); /* Seraph's Fix: 'the_type' only takes one argument. Thanks Rob! */\
                                             end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin                       \
                                                if (anim_busy(self_obj) == false) then begin                                                                       \
                                                   Face_Critter(the_obj, self_obj);                                                                                \
                                                end                                                                                                                \
                                             end

#define point_next_and_face_obj(the_obj, the_type, the_rate)                                                                                                                 \
                                             if (tile_distance_objs(self_obj, the_obj) > 1) then begin                                                             \
                                                the_type(tile_num_in_direction(tile_num(the_obj), rotation_to_tile(tile_num(the_obj),tile_num(self_obj)), 1)) /* Seraph's Fix: 'the_type' only takes one argument. Thanks Rob! */\
                                             end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin                       \
                                                if (anim_busy(self_obj) == false) then begin                                                                       \
                                                   Face_Critter(the_obj, self_obj);                                                                                \
                                                end                                                                                                                \
                                             end

#define Get_Next_To_Obj_And_Face_Rate(the_obj, x)     next_and_face_obj(the_obj, animate_move_to_tile, x)
#define Get_Next_To_Obj_And_Face(the_obj)             next_and_face_obj(the_obj, animate_move_to_tile, 1)
#define Run_Next_To_Obj_And_Face_Rate(the_obj, x)     next_and_face_obj(the_obj, animate_run_to_tile, x)
#define Run_Next_To_Obj_And_Face(the_obj)             next_and_face_obj(the_obj, animate_run_to_tile, 1)
#define point_move_next_and_face_Rate(the_obj, x)     point_next_and_face_obj(the_obj, anim_move_to_point, x)
#define point_move_next_and_face(the_obj)             point_next_and_face_obj(the_obj, anim_move_to_point, 1)
#define point_run_next_and_face_Rate(the_obj, x)      point_next_and_face_obj(the_obj, anim_run_to_point, x)
#define point_run_next_and_face(the_obj)              point_next_and_face_obj(the_obj, anim_run_to_point, 1)

// the Z is a variable LOCAL variable that stores the tile where the dude was last time it was told to follow
//    this will keep the animation for the follow clean

#define closest_clear_tile(obj, the_tile, x)       x := the_tile;                                                                   \
                                                   while ((x != tile_num(obj)) and (tile_is_blocked(x, elevation(obj)))) do begin   \
                                                      x := tile_num_in_direction(x, rotation_to_tile(x, tile_num(obj)), 1);         \
                                                   end
// this is like the above but uses to regular variables instead of local vars
// this steps like the old step macro, but it's faster and better
//
variable dest_tile;
variable step_tile;
#define FAIL_STEP_ACTION                           if (tile_get_next_critter(tile_num_in_direction(self_tile, self_cur_rot, 1), self_elevation, 0) != 0) then begin \
                                                      simulate_push(tile_num_in_direction(self_tile, self_cur_rot, 1))                                                                                                 \
                                                   end else step_tile := -10;
//#define FAIL_STEP_ACTION                           step_tile := -5;
#define move_to_point(the_tile, move_type, x)                                                                                                                                    \
                                                   if ((self_tile != the_tile) and (the_tile != 0)) then begin                                                                                  \
                                                      if ((dest_tile == the_tile) and (step_tile < 0)) then begin                                                                               \
                                                         step_tile += 1;                                                                                                                        \
						        						 debug_msg("step_tile: " + step_tile); \
                                                      end else if (anim_busy(self_obj) == false) then begin                                                                                     \
                                                         dest_tile := the_tile;                                                                                                                 \
                                                         step_tile := the_tile;                                                                                                                 \
                                                         animate_##move_type##_to_tile(step_tile);                                                                                              \
                                                         while ((anim_busy(self_obj) == false) and (((tile_distance(self_tile, the_tile)) >= (tile_distance(step_tile, the_tile))))) do begin   \
							    							debug_msg("rot: " + rotation_to_tile(step_tile, self_tile)); \
                                                            step_tile := tile_num_in_direction(step_tile, rotation_to_tile(step_tile, self_tile), (x % tile_distance(step_tile, self_tile)));   \
							    							debug_msg("step_var: " + step_tile); \
                                                            animate_##move_type##_to_tile(step_tile);                                                                                           \
                                                         end                                                                                                                                    \
                                                         if (anim_busy(self_obj) == false) then begin                                                                                           \
                                                            FAIL_STEP_ACTION                                                                                                                    \
                                                         end                                                                                                                                    \
                                                      end else if ((tile_distance(self_tile, the_tile)) < (tile_distance(dest_tile, the_tile))) then begin                                        \
                                                         reg_anim_clear(self_obj);                                                                                                              \
                                                      end                                                                                                                                       \
                                                   end

#define anim_move_to_point_rate(the_tile, x)       move_to_point(the_tile, move, x)
#define anim_move_to_point(the_tile)               anim_move_to_point_rate(the_tile, 1)
#define anim_run_to_point_rate(the_tile, x)        move_to_point(the_tile, run, x)
#define anim_run_to_point(the_tile)                anim_run_to_point_rate(the_tile, 1)


// map variables that share the same number throught the maps are listed here

#define critter_is_armed(x)                 (((obj_item_subtype(critter_inven_obj(x,INVEN_TYPE_RIGHT_HAND))) == item_type_weapon) or \
                                             ((obj_item_subtype(critter_inven_obj(x,INVEN_TYPE_LEFT_HAND))) == item_type_weapon))
#define critter_weight(x)                   (100 + ((get_critter_stat(x,STAT_gender) == GENDER_MALE) * 50) + (get_critter_stat(x,STAT_st) * 5) - ((get_critter_stat(x,STAT_ag) + get_critter_stat(x,STAT_en))/3))
#define critter_wearing_armor(x)            (obj_item_subtype(critter_inven_obj(x,INVEN_TYPE_WORN)) == item_type_armor)

#define dude_is_stupid                      (dude_iq <= 3)
#define dude_is_smart                       (dude_iq >= 7)
#define dude_is_genius                      (dude_iq >= 9)
#define dude_is_idiot_savant                (has_fake_trait(TRAIT_idiot_savant) or has_fake_trait(TRAIT_frankenstein_monster) or has_fake_trait(TRAIT_bride_of_frankenstein))
#define dude_name                           (obj_name(dude_obj))
#define dude_gender                         (get_critter_stat(dude_obj, STAT_gender))
#define dude_strength                       (get_critter_stat(dude_obj, STAT_st))
#define dude_perception                     (get_critter_stat(dude_obj, STAT_pe))
#define dude_endurance                      (get_critter_stat(dude_obj, STAT_en))
#define dude_charisma                       (get_critter_stat(dude_obj, STAT_ch))
#define dude_iq                             (get_critter_stat(dude_obj, STAT_iq))
#define dude_agility                        (get_critter_stat(dude_obj, STAT_ag))
#define dude_luck                           (get_critter_stat(dude_obj, STAT_lu))
#define dude_level                          (get_pc_stat(PCSTAT_level))
#define dude_age                            (get_critter_stat(dude_obj, STAT_age))
#define dude_weight                         (critter_weight(dude_obj) * (1 + (3 * dude_is_super_mutant)) - (50 * dude_is_ghoul))

#define dude_is_vegetable            (dude_iq <= 1)

#define dude_moron_not_vegetable            (dude_iq == 2)

#define dude_is_human                        (get_sfall_global_int("HAp_Race") == 0)
#define dude_is_super_mutant                  (get_sfall_global_int("HAp_Race") == 1)
#define dude_is_ghoul                        (get_sfall_global_int("HAp_Race") == 2)
#define dude_is_mutant                       (dude_is_super_mutant or dude_is_ghoul or has_fake_trait(TRAIT_mutation_acid_blood) or has_fake_trait(TRAIT_mutation_bloody_talons) or has_fake_trait(TRAIT_mutation_scaly_hide) or has_fake_trait(TRAIT_mutation_night_child) or has_fake_trait(TRAIT_mutation_beast_of_burden) or has_fake_trait(TRAIT_mutation_chameleon) or has_fake_trait(TRAIT_mutation_eagle_eye) or has_fake_trait(TRAIT_mutation_elephant_hide) or has_fake_trait(TRAIT_mutation_monkey_brains) or has_fake_trait(TRAIT_mutation_fervor) or has_fake_trait(TRAIT_mutation_regeneration) or has_fake_trait(TRAIT_mutation_tusks) or has_fake_trait(TRAIT_mutation_fur_hide) or has_fake_trait(TRAIT_mutation_skin_of_thorns) or has_fake_trait(TRAIT_mutation_bullet_storm))

// male
#define dude_light_black_buzz                (get_sfall_global_int("HApStyle") == 0)
#define dude_light_long_hair                (get_sfall_global_int("HApStyle") == 1)
#define dude_light_bald                      (get_sfall_global_int("HApStyle") == 2)
#define dude_dark_dreadlocks                (get_sfall_global_int("HApStyle") == 3)
#define dude_dark_black_buzz                ((get_sfall_global_int("HApStyle") == 4) or (get_sfall_global_int("HApStyle") == 5))
// female
#define dude_light_black_bob                (get_sfall_global_int("HApStyle") == 0)
#define dude_light_blonde                (get_sfall_global_int("HApStyle") == 1)
#define dude_light_redhead                (get_sfall_global_int("HApStyle") == 2)
#define dude_light_punk                   (get_sfall_global_int("HApStyle") == 3)

#define dude_is_male                        (dude_gender == GENDER_MALE)
#define dude_is_female                      (dude_gender == GENDER_FEMALE)
#define dude_is_armed                       critter_is_armed(dude_obj)
#define dude_wearing_armor                  critter_wearing_armor(dude_obj)

#define dude_has_power_armor                (((obj_is_carrying_obj_pid(dude_obj, PID_POWERED_ARMOR)) +            \
                                              (obj_is_carrying_obj_pid(dude_obj, PID_ADVANCED_POWER_ARMOR)) +     \
                                              (obj_is_carrying_obj_pid(dude_obj, PID_ATHENA_POWER_ARMOR)) +     \
                                              (obj_is_carrying_obj_pid(dude_obj, PID_ADVANCED_POWER_ARMOR_MK2)) + \
                                              (obj_is_carrying_obj_pid(dude_obj, PID_HARDENED_POWER_ARMOR))) > 0)

#define dude_wielding_knife                 ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_KNIFE) or                \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_THROWING_KNIFE) or       \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_RIPPER) or               \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_SWITCHBLADE) or               \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_WAKIZASHI_BLADE) or               \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_SHIV) or               \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_COMBAT_KNIFE) or         \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_KNIFE) or                 \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_THROWING_KNIFE) or        \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_RIPPER) or                \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_SWITCHBLADE) or               \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_WAKIZASHI_BLADE) or               \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_SHIV) or                \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_COMBAT_KNIFE))

#define dude_wearing_power_armor            (dude_wearing_armor and ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_POWERED_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_ADVANCED_POWER_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_ADVANCED_POWER_ARMOR_MK2) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_ATHENA_POWER_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_HARDENED_POWER_ARMOR)))

#define dude_wearing_leather_armor          (dude_wearing_armor and ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_JACKET) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_ARMOR_MK_II) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_SCAV_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_POLICE_JACKET) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_ARMOR_MK_III) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_WAR_JACKET) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_CURED_LEATHER_ARMOR)))

#define dude_wearing_combat_armor           (dude_wearing_armor and ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_COMBAT_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_BROTHERHOOD_COMBAT_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_NCR_RANGER_COMBAT_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_NCR_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_HERMES_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_HERMES_ARMOR_MK_II) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_COMBAT_ARMOR_MK_III) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_COMBAT_ARMOR_MK_II)))

#define dude_wearing_metal_armor            (dude_wearing_armor and ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_METAL_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_TESLA_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_METAL_ARMOR_MK_III) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_METAL_ARMOR_MK_II)))

#define dude_wearing_environmental_armor     (dude_wearing_armor and ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_UAF_ENVIRONMENTAL_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_HEI_GUI_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_HAZMAT_SUIT)))

#define dude_wearing_space_suit              (dude_wearing_armor and (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_SPACE_SUIT))

#define dude_looks_like_daughter_of_hecate   (dude_is_human and dude_is_female and dude_wearing_armor and (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_BLACK_ROBES))

#define dude_immune_to_radiation             (dude_wearing_power_armor or dude_wearing_environmental_armor or dude_wearing_space_suit or not(dude_is_human))

#define dude_wearing_vault_suit             (not(dude_wearing_armor) or (dude_wearing_armor and (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_ARMORED_CB13_JUMPSUIT)))

#define dude_looks_like_bos                 (dude_wearing_power_armor or (dude_wearing_armor and (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_BROTHERHOOD_COMBAT_ARMOR)))
#define dude_looks_like_ncr                 (dude_wearing_armor and ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_NCR_RANGER_COMBAT_ARMOR) or (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_NCR_ARMOR)))

#define dude_has_gambling_skills            ((dude_iq > 3) and (has_skill(dude_obj, SKILL_GAMBLING) >= 25))

#define dude_is_sneaking                    (using_skill(dude_obj,SKILL_SNEAK))
#define dude_is_walking                     (art_anim(obj_art_fid(dude_obj)) == ANIM_walk)
#define dude_is_running                     (art_anim(obj_art_fid(dude_obj)) == ANIM_running)
#define dude_is_poisoned                    (get_poison(dude_obj))
#define dude_is_irradiated                  (get_critter_stat(dude_obj, STAT_current_rad))
#define dude_is_crippled                    ((critter_state(dude_obj) bwand DAM_CRIP_LEG_LEFT)  or \
                                             (critter_state(dude_obj) bwand DAM_CRIP_LEG_RIGHT) or \
                                             (critter_state(dude_obj) bwand DAM_CRIP_ARM_LEFT)  or \
                                             (critter_state(dude_obj) bwand DAM_CRIP_ARM_RIGHT))

#define dude_cur_rot                        (has_trait(TRAIT_OBJECT,dude_obj,OBJECT_CUR_ROT))
#define dude_inv_rot                        ((dude_cur_rot + 3)%6)
#define dude_tile                           (tile_num(dude_obj))
#define dude_elevation                      (elevation(dude_obj))
#define dude_skill(x)                       (has_skill(dude_obj, x))

#define tile_behind_obj(who)                (tile_num_in_direction(tile_num(who),((has_trait(TRAIT_OBJECT,who,OBJECT_CUR_ROT) + 3) % 6), 1))
#define tile_behind_obj_rng(who, rng)       (tile_num_in_direction(tile_num(who),((has_trait(TRAIT_OBJECT,who,OBJECT_CUR_ROT) + 3) % 6), rng))

#define cur_hits(who)                       (get_critter_stat(who,STAT_current_hp))
#define max_hits(who)                       (get_critter_stat(who,STAT_max_hp))

#define dude_cur_hits                       (cur_hits(dude_obj))
#define dude_max_hits                       (max_hits(dude_obj))

#define dude_mental_block                   (has_trait(TRAIT_PERK,dude_obj,PERK_mental_block))
#define dude_presence                       (has_trait(TRAIT_PERK,dude_obj,PERK_presence))
#define dude_awareness                      (has_trait(TRAIT_PERK,dude_obj,PERK_bonus_awareness))
#define dude_fortune_finder                 (has_trait(TRAIT_PERK,dude_obj,PERK_fortune_finder))
#define dude_smooth_talker                  (has_trait(TRAIT_PERK,dude_obj,PERK_smooth_talker))

#define dude_caps                           (item_caps_total(dude_obj))

#define dude_is_pornstar                    dude_has_porn_star_rep
#define dude_is_high                        drug_influence(dude_obj)
#define dude_found_geck                     global_var(GVAR_VAULT13_FOUND_GECK)

#define dude_stat_win(X,Y)                  ((do_check(dude_obj,X,Y)) > (do_check(self_obj,X,0)))
#define dude_stat_lose(X,Y)                 ((do_check(dude_obj,X,Y)) < (do_check(self_obj,X,0)))
#define dude_stat_tie(X,Y)                  ((do_check(dude_obj,X,Y)) == (do_check(self_obj,X,0)))

#define dude_item(x)                        obj_carrying_pid_obj(dude_obj, x)
#define dude_item_count(x)                  obj_is_carrying_obj_pid(dude_obj, x)

#define dude_is_chem_reliant                (has_trait(TRAIT_TRAIT, dude_obj, TRAIT_drug_addict))

#define dude_is_addicted                    (is_iface_tag_active(iface_tag_addict))
#define dude_is_addicted_to_jet             (dude_is_addicted and (global_var(GVAR_ADDICT_JET) != 0))
#define dude_is_addicted_to_smooch          (dude_is_addicted and (global_var(GVAR_SMOOCH_ADDICT) != 0))
#define dude_is_addicted_to_nuka_cola       (dude_is_addicted and (global_var(GVAR_NUKA_COLA_ADDICT) != 0))
#define dude_is_addicted_to_buffout         (dude_is_addicted and (global_var(GVAR_BUFF_OUT_ADDICT) != 0))
#define dude_is_addicted_to_mentats         (dude_is_addicted and (global_var(GVAR_MENTATS_ADDICT) != 0))
#define dude_is_addicted_to_psycho          (dude_is_addicted and (global_var(GVAR_PSYCHO_ADDICT) != 0))
#define dude_is_addicted_to_radaway         (dude_is_addicted and (global_var(GVAR_RADAWAY_ADDICT) != 0))
#define dude_is_addicted_to_alcohol         (dude_is_addicted and (global_var(GVAR_ALCOHOL_ADDICT) != 0))
#define dude_is_addicted_to_tragic          (dude_is_addicted and (global_var(GVAR_ADDICT_TRAGIC) != 0))

// perks and traits
#define get_perk(cr,perk)                   has_trait(TRAIT_PERK,cr,perk)
#define dude_perk(perk)                     get_perk(dude_obj,perk)
#define self_perk(perk)                     get_perk(self_obj,perk)
#define get_trait(cr,trait)                 has_trait(TRAIT_TRAIT,cr,trait)
#define dude_trait(trait)                   get_trait(dude_obj,trait)
#define self_trait(trait)                   get_trait(self_obj,trait)

// spouse related
#define spouse_none                       (0)
#define spouse_female                     (1)
#define spouse_male                       (2)
#define dude_spouse_is_male               (global_var(GVAR_PLAYER_MARRIED) == spouse_male)
#define dude_spouse_is_female             (global_var(GVAR_PLAYER_MARRIED) == spouse_female)
#define dude_is_married                   (global_var(GVAR_PLAYER_MARRIED) != spouse_none)
#define set_dude_married                  if ((dude_is_married == false) and (dude_was_married == false)) then begin    \
                                             if (NAME == SCRIPT_MCDAVIN) then begin                                     \
                                                set_global_var(GVAR_PLAYER_MARRIED, spouse_male);                       \
                                             end else if (NAME == SCRIPT_MCMIRIA) then begin                                                             \
                                                set_global_var(GVAR_PLAYER_MARRIED, spouse_female);                     \
                                             end                                                                        \
                                          end                                                                           \
                                          debug_msg("set_dude_married")
#define dude_spouse_was_male              (global_var(GVAR_PLAYER_WAS_MARRIED) == spouse_male)
#define dude_spouse_was_female            (global_var(GVAR_PLAYER_WAS_MARRIED) == spouse_female)
#define dude_was_married                  (global_var(GVAR_PLAYER_WAS_MARRIED) != 0)
#define set_dude_was_married              debug_msg("start: set_dude_was_married");                                     \
                                          if ((dude_is_married) and (dude_was_married == false)) then begin             \
                                             debug_msg("   GVAR_PLAYER_WAS_MARRIED before == " + global_var(GVAR_PLAYER_WAS_MARRIED)); \
                                             set_global_var(GVAR_PLAYER_WAS_MARRIED, global_var(GVAR_PLAYER_MARRIED));  \
                                             debug_msg("   GVAR_PLAYER_WAS_MARRIED after == " + global_var(GVAR_PLAYER_WAS_MARRIED));  \
                                             set_global_var(GVAR_PLAYER_MARRIED, spouse_none);                          \
                                          end                                                                           \
                                          debug_msg("finished: set_dude_was_married")

#define dude_looking_for_escaped_prisoners   ((global_var(GVAR_ACT) == 1) and (global_var(GVAR_QUEST_FIND_PRISONERS) == 1))

/*********************************************************
 General information dealing with a critter script
*********************************************************/
#define self_attack_dude                    if (critter_is_fleeing(self_obj)) then begin        \
                                               if (anim_busy(self_obj) == false) then begin     \
                                                  Flee_From_Dude                                \
                                               end                                              \
                                            end else attack(dude_obj)

#define self_name                           (obj_name(self_obj))
#define self_gender                         (get_critter_stat(self_obj,STAT_gender))
#define self_strength                       (get_critter_stat(self_obj,STAT_st))
#define self_perception                     (get_critter_stat(self_obj,STAT_pe))
#define self_endurance                      (get_critter_stat(self_obj,STAT_en))
#define self_charisma                       (get_critter_stat(self_obj,STAT_ch))
#define self_iq                             (get_critter_stat(self_obj,STAT_iq))
#define self_agility                        (get_critter_stat(self_obj,STAT_ag))
#define self_luck                           (get_critter_stat(self_obj,STAT_lu))

#define self_is_male                        (self_gender == GENDER_MALE)
#define self_is_female                      (self_gender == GENDER_FEMALE)
#define self_is_armed                       critter_is_armed(self_obj)
#define self_wearing_armor                  critter_wearing_armor(self_obj)

#define self_carrying_laser_pistol          ((obj_pid(critter_inven_obj(self_obj,INVEN_TYPE_LEFT_HAND)) == PID_LASER_PISTOL) or \
                                             (obj_pid(critter_inven_obj(self_obj,INVEN_TYPE_RIGHT_HAND)) == PID_LASER_PISTOL))

#define self_is_sneaking                    (using_skill(self_obj,SKILL_SNEAK))
#define self_is_walking                     (art_anim(self_fid) == ANIM_walk)
#define self_is_running                     (art_anim(self_fid) == ANIM_running)
#define self_is_poisoned                    (get_poison(self_obj))
#define self_is_irradiated                  (get_critter_stat(self_obj, STAT_current_rad))
#define self_is_crippled                    ((critter_state(self_obj) bwand DAM_CRIP_LEG_LEFT)  or \
                                            (critter_state(self_obj) bwand DAM_CRIP_LEG_RIGHT) or \
                                            (critter_state(self_obj) bwand DAM_CRIP_ARM_LEFT)  or \
                                            (critter_state(self_obj) bwand DAM_CRIP_ARM_RIGHT))

#define self_cur_rot                        (has_trait(TRAIT_OBJECT,self_obj,OBJECT_CUR_ROT))
#define self_inv_rot                        ((self_cur_rot + 3)%6)
#define self_tile                           (tile_num(self_obj))
#define self_elevation                      (elevation(self_obj))

#define self_pid                            (obj_pid(self_obj))
#define self_team                           has_trait(TRAIT_OBJECT,self_obj,OBJECT_TEAM_NUM)
#define self_ai                             has_trait(TRAIT_OBJECT,self_obj,OBJECT_AI_PACKET)
#define self_visible                        obj_is_visible_flag(self_obj)

// team
#define get_team(cr)                        has_trait(TRAIT_OBJECT,cr,OBJECT_TEAM_NUM)
#define set_team(cr,team)                   critter_add_trait(cr,TRAIT_OBJECT,OBJECT_TEAM_NUM,team)
#define set_self_team(team)                 set_team(self_obj,team)

#define self_cur_hits                       (get_critter_stat(self_obj,STAT_current_hp))
#define self_max_hits                       (get_critter_stat(self_obj,STAT_max_hp))

#define self_mental_block                   (has_trait(TRAIT_PERK,self_obj,PERK_mental_block))
#define self_presence                       (has_trait(TRAIT_PERK,self_obj,PERK_presence))
#define self_awareness                      (has_trait(TRAIT_PERK,self_obj,PERK_bonus_awareness))
#define self_fortune_finder                 (has_trait(TRAIT_PERK,self_obj,PERK_fortune_finder))

#define self_caps                           (item_caps_total(self_obj))
#define self_fid                            (obj_art_fid(self_obj))

#define skill_success(x,y,z)                (is_success(roll_vs_skill(x,y,z)))
#define stat_success(x,y,z)                 (is_success(do_check(x,y,z)))

#define self_can_see_dude                   obj_can_see_obj(self_obj,dude_obj) and ((critter_state(self_obj) bwand DAM_KNOCKED_OUT) == false)
#define self_can_hear_dude                  obj_can_hear_obj(self_obj, dude_obj) and ((critter_state(self_obj) bwand DAM_KNOCKED_OUT) == false)
#define self_distance_from_dude             tile_distance(self_tile, dude_tile)
#define self_is_high                        drug_influence(self_obj)

#define self_item(x)                        obj_carrying_pid_obj(self_obj, x)
#define self_item_count(x)                  obj_is_carrying_obj_pid(self_obj, x)

#define self_wearing_power_armor            ((obj_pid(critter_inven_obj(self_obj, INVEN_TYPE_WORN)) == PID_POWERED_ARMOR) or \
                                             (obj_pid(critter_inven_obj(self_obj, INVEN_TYPE_WORN)) == PID_ADVANCED_POWER_ARMOR) or \
                                             (obj_pid(critter_inven_obj(self_obj, INVEN_TYPE_WORN)) == PID_ADVANCED_POWER_ARMOR_MK2) or \
                                             (obj_pid(critter_inven_obj(self_obj, INVEN_TYPE_WORN)) == PID_HARDENED_POWER_ARMOR))

#define self_wearing_environmental_armor     ((obj_pid(critter_inven_obj(self_obj, INVEN_TYPE_WORN)) == PID_METAL_ARMOR) or \
                                             (obj_pid(critter_inven_obj(self_obj, INVEN_TYPE_WORN)) == PID_METAL_ARMOR_MK_II))

// some timer event macros
#define check_set_obj_visibility(the_obj, x)       if (obj_is_visible_flag(the_obj) == x) then set_obj_visibility(the_obj, x)

#define flush_add_timer_event(obj, time, param)    rm_fixed_timer_event(obj, param);               \
                                                   add_timer_event(obj, time, param)
#define flush_add_timer_event_sec(obj, sec, param) flush_add_timer_event(obj, game_ticks(sec), param)

/******************************************************************
 General commands getting information about time
******************************************************************/

#define morning                             ((game_time_hour >= 600) and  (game_time_hour < 700))
#ifndef day
#define day                                 ((game_time_hour >= 700) and  (game_time_hour < 1800))
#endif
#define evening                             ((game_time_hour >= 1800) and (game_time_hour < 1900))
#ifndef night
#define night                               ((game_time_hour >= 1900) or  (game_time_hour < 600))
#endif

#define GAME_TIME_SUBSECOND_RESOLUTION  (10)
#define SECONDS_PER_MINUTE              (60)
#define MINUTES_PER_HOUR                (60)
#define HOURS_PER_DAY                   (24)
#define DAYS_PER_YEAR                   (365)
                                // Seconds Minutes Hours Days Months ==> Year
#define GAME_TIME_IN_YEARS   (game_time / (GAME_TIME_SUBSECOND_RESOLUTION * SECONDS_PER_MINUTE * MINUTES_PER_HOUR * HOURS_PER_DAY * DAYS_PER_YEAR))
#define GAME_TIME_IN_DAYS    (game_time / (GAME_TIME_SUBSECOND_RESOLUTION * 60 * 60 * 24))
#define GAME_TIME_IN_HOURS   (game_time / (GAME_TIME_SUBSECOND_RESOLUTION * SECONDS_PER_MINUTE * MINUTES_PER_HOUR))
#define GAME_TIME_IN_MINUTES (game_time / (GAME_TIME_SUBSECOND_RESOLUTION * SECONDS_PER_MINUTE))
#define GAME_TIME_IN_SECONDS (game_time / GAME_TIME_SUBSECOND_RESOLUTION)


#define ticks_til_hour(x)                 ((ONE_GAME_DAY * (game_time_hour > (x))) + ((((x)/100) - (game_time_hour/100)) * ONE_GAME_HOUR) + ((((x)%100) - (game_time_hour%100)) * ONE_GAME_MINUTE))
#define game_time_advance_hour(x)         game_time_advance(ticks_til_hour(x))

// use times in define.h for passed_time(example: ONE_GAME_DAY)
#define time_has_passed(old_time, passed_time)      ((passed_time + old_time) <= game_time)
// get the actual amout of time that has passed
#define amt_time_has_passed(old_time, time_unit)  ((game_time - old_time) / time_unit)

#define one_second_passed(old_time)       time_has_passed(old_time,ONE_GAME_SECOND)
#define one_minute_passed(old_time)       time_has_passed(old_time,ONE_GAME_MINUTE)
#define one_hour_passed(old_time)         time_has_passed(old_time,ONE_GAME_HOUR)
#define one_day_passed(old_time)          time_has_passed(old_time,ONE_GAME_DAY)
#define one_week_passed(old_time)         time_has_passed(old_time,ONE_GAME_WEEK)
#define one_month_passed(old_time)        time_has_passed(old_time,ONE_GAME_MONTH)

/***************************************************************
****************  Dialogue Information   ***********************
***************************************************************/
#ifndef floater
   #define floater(x)           float_msg(self_obj, message_str(NAME,x), FLOAT_COLOR_NORMAL)
#endif
#define floater_rand(x,y)       floater(random(x,y))

#define dude_floater(x)         float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_NORMAL)
#define dude_floater_rand(x,y)  dude_floater(random(x,y))
#define dude_floater_bad(x)     float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_BAD)
#define dude_floater_sick(x)    float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_SICK)

#define dude_floater_bad_rand(x,y)    dude_floater_bad(random(x,y))
#define dude_floater_sick_rand(x,y)    dude_floater_sick(random(x,y))

#define dude_floater_afraid(x)           float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_AFRAID)
#define dude_floater_afraid_rand(x,y)    dude_floater_afraid(random(x,y))
#define dude_floater_high(x)             float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_HIGH)
#define dude_floater_high_rand(x,y)      dude_floater_high(random(x,y))
#define dude_floater_good(x)             float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_GOOD)
#define dude_floater_good_rand(x,y)      dude_floater_good(random(x,y))
#define dude_floater_whisper(x)          float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_WHISPER)
#define dude_floater_whisper_rand(x,y)   dude_floater_whisper(random(x,y))
#define dude_floater_sad(x)              float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_SAD)
#define dude_floater_sad_rand(x,y)       dude_floater_sad(random(x,y))
#define dude_floater_pain(x)             float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_PAIN)
#define dude_floater_pain_rand(x,y)      dude_floater_pain(random(x,y))

#define can_speak(x)               (not(combat_is_initialized) and not(critter_state(x) bwand (DAM_KNOCKED_OUT bwor DAM_DEAD bwor DAM_ON_FIRE bwor DAM_EXPLODE bwor DAM_DESTROY)) and obj_is_visible_flag(x) and (elevation(x) == dude_elevation))
#define self_can_speak             can_speak(self_obj)
#define dude_can_speak             can_speak(dude_obj)

variable in_dialog;
variable forced_node;
#define start_dialog_at_node(x,head,background)                       if (in_dialog == false) then begin           \
                                                         in_dialog := true;                        \
                                                         start_gdialog(NAME,self_obj,4,head,background);     \
                                                         gSay_Start;                               \
                                                            call x;                                \
                                                         gSay_End;                                 \
                                                         end_dialogue;                             \
                                                         in_dialog := false;                       \
                                                      end else call x

#define force_dialog_start(the_node)            debug_msg("force_dialog_start("+forced_node+"): "+self_name);  \
                                                      forced_node := the_node;                                    \
                                                      dialogue_system_enter

#define check_forced_dialog(head,background)                           if (forced_node != 0) then begin          \
                                                         debug_msg("calling forced dialog: "+forced_node);\
                                                         start_dialog_at_node(forced_node,head,background);     \
                                                         forced_node := 0;                      \
                                                      end

/*
FLOAT_MSG_BLACK
FLOAT_MSG_PURPLE
FLOAT_MSG_NEAR_WHITE
FLOAT_MSG_BLUE
*/
#define FLOAT_COLOR_NORMAL          FLOAT_MSG_YELLOW
#define FLOAT_COLOR_SICK            FLOAT_MSG_GREEN
#define FLOAT_COLOR_BAD             FLOAT_MSG_RED
#define FLOAT_COLOR_GOOD            FLOAT_MSG_WHITE
#define FLOAT_COLOR_SFX             FLOAT_MSG_LIGHT_GREY
#define FLOAT_COLOR_SAD             FLOAT_MSG_GREY
#define FLOAT_COLOR_AFRAID          FLOAT_MSG_LIGHT_RED
#define FLOAT_COLOR_PAIN            FLOAT_MSG_LIGHT_GREY
#define FLOAT_COLOR_HIGH            FLOAT_MSG_PURPLE
#define FLOAT_COLOR_WHISPER         FLOAT_MSG_GREY

#define obj_floater_type(z,x,type)  float_msg(z, x, FLOAT_COLOR_NORMAL + ((type - FLOAT_COLOR_NORMAL) * has_trait(TRAIT_PERK, dude_obj, PERK_empathy)))
#define floater_type_msg(x, type)   obj_floater_type(self_obj, x, type)
#define floater_type(x, type)       floater_type_msg(mstr(x), type)
#define floater_bad(x)              floater_type(x, FLOAT_COLOR_BAD)
#define floater_bad_rand(x,y)       floater_bad(random(x,y))
#define floater_sick(x)             floater_type(x, FLOAT_COLOR_SICK)
#define floater_sick_rand(x,y)      floater_sick(random(x,y))
#define floater_afraid(x)           floater_type(x, FLOAT_COLOR_AFRAID)
#define floater_afraid_rand(x,y)    floater_afraid(random(x,y))
#define floater_high(x)             floater_type(x, FLOAT_COLOR_HIGH)
#define floater_high_rand(x,y)      floater_high(random(x,y))
#define floater_good(x)             floater_type(x, FLOAT_COLOR_GOOD)
#define floater_good_rand(x,y)      floater_good(random(x,y))
#define floater_whisper(x)          floater_type(x, FLOAT_COLOR_WHISPER)
#define floater_whisper_rand(x,y)   floater_whisper(random(x,y))
#define floater_sad(x)              floater_type(x, FLOAT_COLOR_SAD)
#define floater_sad_rand(x,y)       floater_sad(random(x,y))
#define floater_pain(x)             floater_type(x, FLOAT_COLOR_PAIN)
#define floater_pain_rand(x,y)      floater_pain(random(x,y))
#define floater_sfx(x)             floater_type(x, FLOAT_COLOR_SFX)
#define floater_sfx_rand(x,y)      floater_pain(random(x,y))

#define mstr(x)                     message_str(NAME,x)
#define display_mstr(x)             display_msg(mstr(x))
#define g_mstr(x)                   message_str(SCRIPT_GENERIC,x)
#define g_grunt                     g_mstr(random(300,303))
#define g_bye                       g_mstr(random(375,376))

#define LOW_IQ                      (-3)

#define Reply(x)                    gSay_Reply(NAME,x)
#define Reply_Rand(x,y)             Reply(random(x,y))
#define GMessage(x)                 gSay_Message(NAME,x,GOOD_REACTION)
#define NMessage(x)                 gSay_Message(NAME,x,NEUTRAL_REACTION)
#define BMessage(x)                 gSay_Message(NAME,x,BAD_REACTION)

// this converts a number from 0-100 to the text representing the number, ie: 1 -> "one", 40 -> "forty-one"
#define num_to_num_text(x)          g_mstr(2000+x)

// Option(Message Number, Node Number, IQ)         ==>     giQ_Option(IQ, Message Number, Node Number)      -rwh2 (11/12/97)
#define GOption(x,y,z)              giQ_Option(z,NAME,x,y,GOOD_REACTION)
#define NOption(x,y,z)              giQ_Option(z,NAME,x,y,NEUTRAL_REACTION)
#define BOption(x,y,z)              giQ_Option(z,NAME,x,y,BAD_REACTION)
#define GLowOption(x,y)             giQ_Option(LOW_IQ,NAME,x,y,GOOD_REACTION)
#define NLowOption(x,y)             giQ_Option(LOW_IQ,NAME,x,y,NEUTRAL_REACTION)
#define BLowOption(x,y)             giQ_Option(LOW_IQ,NAME,x,y,BAD_REACTION)

#define display_mstr_rand(x,y)      display_msg(mstr(random(x,y)))

/***************************************************************
****************  Global Variable commands *********************
***************************************************************/
#define inc_global_var_amt(x,y)     set_global_var(x,global_var(x)+y)
#define inc_global_var(x)           inc_global_var_amt(x,1)
#define dec_global_var_amt(x,y)     set_global_var(x,global_var(x)-y)
#define dec_global_var(x)           dec_global_var_amt(x,1)

/***************************************************************
****************  map Variable commands ************************
***************************************************************/
#define inc_map_var_amt(x,y)        set_map_var(x,map_var(x)+y)
#define inc_map_var(x)              inc_map_var_amt(x,1)
#define dec_map_var_amt(x,y)        set_map_var(x,map_var(x)-y)
#define dec_map_var(x)              dec_map_var_amt(x,1)

/***************************************************************
****************  Local Variable commands **********************
***************************************************************/
#define inc_local_var_amt(x,y)      set_local_var(x,local_var(x)+y)
#define inc_local_var(x)            inc_local_var_amt(x,1)
#define dec_local_var_amt(x,y)      set_local_var(x,local_var(x)-y)
#define dec_local_var(x)            dec_local_var_amt(x,1)

/***************************************************************
**************** Bit Manipulation Macros ***********************
***************************************************************/
#define MAXINT 4294967295                 //Max int
#define INV(x) (MAXINT - x)               //An inverse function

// get bit state
#define gvar_bit(x, the_bit)                          ((global_var(x) bwand the_bit) != 0)
#define mvar_bit(x, the_bit)                          ((map_var(x) bwand the_bit) != 0)
#define lvar_bit(x, the_bit)                          ((local_var(x) bwand the_bit) != 0)

// switch bit on
#define set_gvar_bit_on(x, the_bit)                   set_global_var(x, global_var(x) bwor the_bit)
#define set_mvar_bit_on(x, the_bit)                   set_map_var(x, map_var(x) bwor the_bit)
#define set_lvar_bit_on(x, the_bit)                   set_local_var(x, local_var(x) bwor the_bit)

// switch bit off
#define set_gvar_bit_off(x, the_bit)                  set_global_var(x, global_var(x) bwand INV(the_bit))
#define set_mvar_bit_off(x, the_bit)                  set_map_var(x, map_var(x) bwand INV(the_bit))
#define set_lvar_bit_off(x, the_bit)                  set_local_var(x, local_var(x) bwand INV(the_bit))

// truncates a number
#define trunc(x)                (x * -(x<1))

/******************************************************************
 General commands getting information about a critter
******************************************************************/
#define critter_is_male         (get_critter_stat(self_obj,STAT_gender) == GENDER_MALE)
#define critter_is_female       (get_critter_stat(self_obj,STAT_gender) == GENDER_FEMALE)

/******************************************************************
 General commands setting and getting the map exit
******************************************************************/
// note set either exit or next to 0 for invalid
#define set_map_exit_tiles(the_exit,the_next)     set_global_var(GVAR_MAP_EXIT_TILE,the_exit);  set_global_var(GVAR_MAP_NEXT_TILE,the_next)
#define map_exit_tile                             (global_var(GVAR_MAP_EXIT_TILE))
#define map_next_tile                             (global_var(GVAR_MAP_NEXT_TILE))

/******************************************************************
 General commands for checking and changing status variables
         note: variable needs to be global for the functions to work
         note: the defines for the status's are in GLOBAL.H
******************************************************************/
#define change_status_on(status_var, which_status)    set_gvar_bit_on(status_var, which_status);
#define change_status_off(status_var, which_status)   set_gvar_bit_off(status_var, which_status);

#define set_status_known(status_var)                  change_status_on(status_var, PERSON_KNOWN)
#define set_status_attacked(status_var)               change_status_on(status_var, PERSON_ATTACKED)
#define set_status_killed(status_var)                 change_status_on(status_var, PERSON_KILLED)
#define set_status_assassinated(status_var)           change_status_on(status_var, PERSON_ASSASSINATED)
#define set_status_dead(status_var)                   change_status_on(status_var, PERSON_DEAD)
#define set_status_spoken_to(status_var)              change_status_on(status_var, PERSON_SPOKEN_TO)
#define set_status_spoken_to_special(status_var)      change_status_on(status_var, PERSON_SPOKEN_TO_SPECIAL)
#define set_status_special(status_var)                change_status_on(status_var, PERSON_SPECIAL)
#define set_status_special_2(status_var)              change_status_on(status_var, PERSON_SPECIAL_2)
#define set_status_in_party(status_var)               change_status_on(status_var, PERSON_IN_PARTY)
#define set_status_not_in_party(status_var)           change_status_off(status_var, PERSON_IN_PARTY)
#define set_status_warned(status_var)                 change_status_on(status_var, PERSON_WARNED)
#define set_status_sex(status_var)                    change_status_on(status_var, PERSON_SEX)

#define status_is(status_var, check_status)           (gvar_bit(status_var, check_status))

#define status_is_known(status_var)                   (status_is(status_var, PERSON_KNOWN))
#define status_is_unknown(status_var)                 (status_is_known(status_var) == false)
#define status_is_attacked(status_var)                (status_is(status_var, PERSON_ATTACKED))
#define status_is_killed(status_var)                  (status_is(status_var, PERSON_KILLED))
#define status_is_assassinated(status_var)            (status_is(status_var, PERSON_ASSASSINATED))
#define status_is_dead(status_var)                    (status_is(status_var, PERSON_DEAD))
#define status_is_spoken_to(status_var)               (status_is(status_var, PERSON_SPOKEN_TO))
#define status_is_spoken_to_special(status_var)       (status_is(status_var, PERSON_SPOKEN_TO_SPECIAL))
#define status_is_special(status_var)                 (status_is(status_var, PERSON_SPECIAL))
#define status_is_special_2(status_var)               (status_is(status_var, PERSON_SPECIAL_2))
#define status_is_in_party(status_var)                (status_is(status_var, PERSON_IN_PARTY))
#define status_is_not_in_party(status_var)            (status_is(status_var, PERSON_IN_PARTY) == false)
#define status_is_warned(status_var)                  (status_is(status_var, PERSON_WARNED))
#define status_is_sex(status_var)                     (status_is(status_var, PERSON_SEX))

#define status_is_alive(status_var)                   (not (status_is_killed(status_var) or status_is_assassinated(status_var) or status_is_dead(status_var)))


/******************************************************************
 General commands getting information about cities
******************************************************************/

#define town_visible_on_map(x)              (town_known(x) != MARK_STATE_UNKNOWN)
#define town_visited(x)                     (town_known(x) == MARK_STATE_VISITED)


#define mark_on_map(x)                      if (town_known(x) == MARK_STATE_UNKNOWN) then begin          \
                                               debug_msg("  mark_on_map("+x+")");                        \
                                               mark_area_known(MARK_TYPE_TOWN, x, MARK_STATE_KNOWN);     \
                                            end

#define unmark_on_map(x)                    if (town_known(x) != MARK_STATE_UNKNOWN) then begin          \
                                               debug_msg(" unmark_on_map("+x+")");                       \
                                               mark_area_known(MARK_TYPE_TOWN, x, MARK_STATE_UNKNOWN);   \
                                            end

#define remove_from_map(x)                   if (town_known(x) != MARK_STATE_INVISIBLE) then begin          \
                                                debug_msg(" remove_from_map("+x+")");                       \
                                                mark_area_known(MARK_TYPE_TOWN, x, MARK_STATE_INVISIBLE);   \
                                             end

/******************************************************************
 General commands STOMACH(ha stomach, ha ha ha) info
******************************************************************/
// these are the different amounts food fills the stomach
#define starting_stomach_full          (75)
#define drink_meal                     (5)
#define snack_meal                     (10)
#define light_meal                     (25)
#define medium_meal                    (50)
#define large_meal                     (75)
#define huge_meal                      (90)
// these are macros for dealing with the stomach
#define max_stomach_size               (100 + (2 * (dude_endurance - 10)))
#define dude_stomach_amt               (global_var(GVAR_DUDE_STOMACH))
#define dude_can_eat_food(amt)         ((dude_stomach_amt + amt) <= max_stomach_size)
#define dude_eat_food(amt)             script_overrides;   \
                                       set_global_var(GVAR_LAST_DIGEST_TIME, game_time);  \
                                       inc_global_var_amt(GVAR_DUDE_STOMACH, amt);  \
                                       if ((amt == starting_stomach_full) or (amt < 1)) then  \
                                          global_temp = 0; \
                                       else if (amt == drink_meal) then  \
                                          global_temp = play_sfall_sound("data\\sound\\SFX\\EAT_Swallow_mono.wav", 0);  \
                                       else if (amt == snack_meal) then  \
                                          global_temp = play_sfall_sound("data\\sound\\SFX\\EAT_Cookie_Bite_mono.wav", 0);  \
                                       else   \
                                       global_temp = play_sfall_sound("data\\sound\\SFX\\EAT_Chew_3_Times_mono.wav", 0);  \
                                       if (dude_stomach_amt < 0) then                         \
                                          set_global_var(GVAR_DUDE_STOMACH, 0);                             \
                                       else if (dude_stomach_amt > max_stomach_size) then     \
                                          set_global_var(GVAR_DUDE_STOMACH, max_stomach_size)
#define dude_stomach_percent_full      ((100 * dude_stomach_amt) / max_stomach_size)
#define dude_stomach_full              (dude_stomach_percent_full >= 95)
#define dude_stomach_hungry            (dude_stomach_percent_full <= 5)
#define dude_can_eat(x)                ((dude_stomach_amt + x) <= max_stomach_size)

#define pid_is_alcohol_pid(x)            ((x==PID_BEER) or (x==PID_BOOZE) or (x==PID_GAMMA_GULP_BEER) or (x==PID_ROENTGEN_RUM) or (x==PID_ROT_GUT) or (x==PID_AYAYAY_HOOCH))
// these are so that a pid can be compared to see which food class it is
#define pid_is_drink_pid(x)            ((x==PID_NUKA_COLA) or (x==PID_WATER_FLASK) or (x==PID_HOLY_WATER) or (pid_is_alcohol_pid(x)))
#define pid_is_snack_pid(x)            ((x==PID_IGUANA_ON_A_STICK) or (x==PID_MEAT_ON_A_STICK) or (x==PID_COOKIE) or (x==PID_MEAT_JERKY) or (x==PID_MUTATED_FRUIT) or (x==PID_CHEEZY_POOFS) or (x==PID_CHEESE) or (x==PID_RAT_TAIL_LUCKY_CHARM) or (x==PID_RAT_TAIL) or (x==PID_DEAD_BABY_ROACH) or (x==PID_CHOCOLATE_DEATHCLAW))
#define pid_is_light_meal_pid(x)       ((x==PID_BOX_OF_NOODLES) or (x==PID_SMITTY_MEAL) or (x==PID_MUSHROOM_CLOUDS) or (x==PID_CANNED_FOOD))
#define pid_is_medium_meal(x)          ((x==PID_FIELD_RATION) or (x==PID_GUTS) or (x==PID_LIVER))
#define pid_is_large_meal(x)           ((x==PID_GUTS_STEW) or (x==PID_LIVER_CHOPS) or (x==PID_NUTRIENT_PASTE))
#define pid_is_huge_meal(x)            (x==PID_DESERT_SALAD)
#define dude_has_fast_metabolism       (has_trait(TRAIT_OBJECT,dude_obj,TRAIT_fast_metabolism))
#define amt_food_digested_in_time(x)   (((1 + dude_has_fast_metabolism) * (game_time - x)) / (ONE_GAME_HOUR * 3))

/******************************************************************
 General commands restocking inventory
 note: this is generally placed in the "box" of a merchant to refil it every so once in a while
       only call this when it's time to restock the "box"... see "diTubBox.ssl" for a hint
       but most of all, have fun, remember, fun
******************************************************************/
variable restock_amt;
variable restock_obj;
variable restock_trash;
variable removed_qty;
#define transfer_pid_between_objs(source, target, the_pid, qty)                           \
         restock_amt := qty;                                                              \
         if (obj_is_carrying_obj_pid(source, the_pid) < qty) then begin                   \
            restock_amt := obj_is_carrying_obj_pid(source, the_pid);                      \
         end                                                                              \
         if (restock_amt > 0) then begin                                                  \
            restock_obj := obj_carrying_pid_obj(source, the_pid);                         \
            restock_trash := rm_mult_objs_from_inven(source, restock_obj, restock_amt);   \
            add_mult_objs_to_inven(target, restock_obj, restock_amt);                     \
         end

#define transfer_all_pid_between_objs(source, target, the_pid)                            \
         restock_amt := obj_is_carrying_obj_pid(source, the_pid);                         \
         if (restock_amt > 0) then begin                                                  \
            restock_obj := obj_carrying_pid_obj(source, the_pid);                         \
            restock_trash := rm_mult_objs_from_inven(source, restock_obj, restock_amt);   \
            add_mult_objs_to_inven(target, restock_obj, restock_amt);                     \
         end

#define give_pid_qty(who_obj, the_pid, pid_qty)                                           \
           restock_obj := create_object(the_pid,0,0);                                     \
           add_mult_objs_to_inven(who_obj, restock_obj, (pid_qty));

#define remove_armor(who_obj)                                                                            \
            if (critter_wearing_armor(who_obj)) then begin                                               \
               restock_obj := critter_inven_obj(who_obj,INVEN_TYPE_WORN);                                \
               debug_msg("armour pid == "+obj_pid(restock_obj));                                         \
               rm_obj_from_inven(who_obj, restock_obj);                                                  \
               add_obj_to_inven(who_obj, restock_obj);                                                   \
            end

#define remove_pid_qty(who_obj, the_pid, pid_qty)                                            \
            removed_qty := obj_is_carrying_obj_pid(who_obj,the_pid);                          \
            if ((pid_qty) < removed_qty) then begin                                           \
                removed_qty := pid_qty;                                                        \
            end \
            while (removed_qty) do begin                                                                              \
                restock_obj := obj_carrying_pid_obj(who_obj, the_pid);                         \
                if (obj_type(who_obj) == OBJ_TYPE_CRITTER) then begin                                        \
                    if (critter_inven_obj(who_obj,INVEN_TYPE_WORN) == restock_obj) then begin  \
                       remove_armor(who_obj)                                                    \
                    end else if ((critter_inven_obj(who_obj, INVEN_TYPE_LEFT_HAND) == restock_obj) or (critter_inven_obj(who_obj, INVEN_TYPE_RIGHT_HAND) == restock_obj)) then begin     \
                       inven_unwield(who_obj);                                                  \
                    end                                                                         \
                end                                                                            \
                restock_amt := rm_mult_objs_from_inven(who_obj, restock_obj, removed_qty);     \
                destroy_object(restock_obj);                                                   \
                removed_qty -= restock_amt; \
                restock_obj := 0;                                                                 \
                restock_amt := 0; \
            end

#define stock_pid_qty(who_obj, the_pid, pid_qty)                                                   \
        if (obj_is_carrying_obj_pid(who_obj,the_pid) < pid_qty) then begin                         \
           give_pid_qty(who_obj, the_pid, pid_qty - obj_is_carrying_obj_pid(who_obj,the_pid))     \
        end else if (obj_is_carrying_obj_pid(who_obj,the_pid) > pid_qty) then begin                \
           remove_pid_qty(who_obj, the_pid, (obj_is_carrying_obj_pid(who_obj,the_pid) - pid_qty))  \
        end else begin                                                                             \
           restock_obj := 0;                                                                       \
        end

#define check_restock_item(the_item, min_amt, max_amt, res_perc)                    \
        restock_amt := random(min_amt, max_amt);                                    \
        if (obj_is_carrying_obj_pid(self_obj, the_item) < restock_amt) then begin   \
            if (res_perc >= random(1,100)) then begin                               \
               stock_pid_qty(self_obj, the_item, restock_amt)                       \
            end                                                                     \
        end else begin                                                              \
           stock_pid_qty(self_obj, the_item, restock_amt)                           \
        end
#define check_restock_item_min_limit(the_item, min_amt, max_amt, res_perc)          \
        if (obj_is_carrying_obj_pid(self_obj, the_item) < min_amt) then begin       \
           check_restock_item(the_item, min_amt, max_amt, res_perc)                 \
        end

/******************************************************************
 general macros for arming an object
 note: passing 0 through to the special_ammo_pid will give ammo of the lowest possible damage type
******************************************************************/
#define give_obj_weapon(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty, wield_me)       \
        stock_pid_qty(who_obj, weapon_pid, weapon_qty)                                       \
        if (wield_me) then begin                                                             \
           if (obj_is_carrying_obj_pid(who_obj, weapon_pid)) then begin                      \
              wield_obj_critter(who_obj, obj_carrying_pid_obj(who_obj, weapon_pid));         \
           end else begin                                                                    \
              debug_msg("NOT ARMING THE WEAPON!!!");                                         \
           end                                                                               \
        end                                                                                  \
        if (ammo_pid != 0) then begin                                                        \
           stock_pid_qty(who_obj, ammo_pid, ammo_qty)                                        \
        end else begin                                                                       \
           if ((weapon_pid == PID_10MM_PISTOL) or                                            \
               (weapon_pid == PID_ZIP_GUN) or                                                \
               (weapon_pid == PID_10MM_SMG)) then begin                                      \
              stock_pid_qty(who_obj, PID_10MM_JHP, ammo_qty)                                 \
           end else if ((weapon_pid == PID_HUNTING_RIFLE) or                                 \
                        (weapon_pid == PID_BOZAR) or                                         \
                        (weapon_pid == PID_LIGHT_SUPPORT_WEAPON) or                          \
                        (weapon_pid == PID_SNIPER_RIFLE) or                                  \
                        (weapon_pid == PID_223_PISTOL) or                                    \
                        (weapon_pid == PID_SCOPED_HUNTING_RIFLE)) then begin                 \
              stock_pid_qty(who_obj, PID_223_FMJ, ammo_qty)                                  \
           end else if ((weapon_pid == PID_FLAMER) or                                        \
                        (weapon_pid == PID_IMPROVED_FLAMETHROWER)) then begin                \
              stock_pid_qty(who_obj, PID_FLAMETHROWER_FUEL, ammo_qty)                        \
           end else if ((weapon_pid == PID_MINIGUN) or                                       \
                        (weapon_pid == PID_INDEPENDENT) or                                   \
                        (weapon_pid == PID_AVENGER_MINIGUN) or                               \
                        (weapon_pid == PID_ASSAULT_RIFLE_EXT_MAG) or                         \
                        (weapon_pid == PID_ASSAULT_RIFLE)) then begin                        \
              stock_pid_qty(who_obj, PID_5MM_JHP, ammo_qty)                                  \
           end else if (weapon_pid == PID_ROCKET_LAUNCHER) then begin                        \
              stock_pid_qty(who_obj, PID_EXPLOSIVE_ROCKET, ammo_qty)                         \
           end else if ((weapon_pid == PID_PLASMA_RIFLE) or                                  \
                        (weapon_pid == PID_YK42B_PULSE_RIFLE) or                             \
                        (weapon_pid == PID_GATLING_LASER) or                                 \
                        (weapon_pid == PID_LASER_RIFLE) or                                   \
                        (weapon_pid == PID_LASER_RIFLE_EXT_CAP) or                           \
                        (weapon_pid == PID_TURBO_PLASMA_RIFLE)) then begin                   \
              stock_pid_qty(who_obj, PID_MICRO_FUSION_CELL, ammo_qty)                        \
           end else if ((weapon_pid == PID_LASER_PISTOL) or                                  \
                        (weapon_pid == PID_POWER_FIST) or                                    \
                        (weapon_pid == PID_MEGA_POWER_FIST) or                               \
                        (weapon_pid == PID_RIPPER) or                                        \
                        (weapon_pid == PID_CATTLE_PROD) or                                   \
                        (weapon_pid == PID_SUPER_CATTLE_PROD) or                             \
                        (weapon_pid == PID_PLASMA_PISTOL) or                                 \
                        (weapon_pid == PID_PLASMA_PISTOL_EXT_CART) or                        \
                        (weapon_pid == PID_PHAZER) or                                        \
                        (weapon_pid == PID_YK32_PULSE_PISTOL) or                             \
                        (weapon_pid == PID_ALIEN_LASER_PISTOL) or                            \
                        (weapon_pid == PID_MAGNETO_LASER_PISTOL)) then begin                 \
              stock_pid_qty(who_obj, PID_SMALL_ENERGY_CELL, ammo_qty)                        \
           end else if ((weapon_pid == PID_DESERT_EAGLE) or                                  \
                        (weapon_pid == PID_44_MAGNUM_SPEEDLOADER) or                         \
                        (weapon_pid == PID_DESERT_EAGLE_EXT_MAG) or                          \
                        (weapon_pid == PID_44_MAGNUM_REVOLVER)) then begin                   \
              stock_pid_qty(who_obj, PID_44_MAGNUM_JHP, ammo_qty)                            \
           end else if (weapon_pid == PID_14MM_PISTOL) then begin                            \
              stock_pid_qty(who_obj, PID_14MM_AP, ammo_qty)                                  \
           end else if ((weapon_pid == PID_SHOTGUN) or                                       \
                        (weapon_pid == PID_PANCOR_JACKHAMMER) or                             \
                        (weapon_pid == PID_SAWED_OFF_SHOTGUN) or                             \
                        (weapon_pid == PID_COMBAT_SHOTGUN) or                                \
                        (weapon_pid == PID_HK_CAWS)) then begin                              \
              stock_pid_qty(who_obj, PID_SHOTGUN_SHELLS, ammo_qty)                           \
           end else if (weapon_pid == PID_9MM_MAUSER) then begin                             \
              stock_pid_qty(who_obj, PID_9MM_BALL, ammo_qty)                                 \
           end else if (weapon_pid == PID_HK_P90C) then begin                                \
              stock_pid_qty(who_obj, PID_9MM_AMMO, ammo_qty)                                 \
           end else if (weapon_pid == PID_ROBO_ROCKET_LAUNCHER) then begin                   \
              stock_pid_qty(who_obj, PID_ROBO_ROCKET_AMMO, ammo_qty)                         \
           end else if (weapon_pid == PID_SPRINGER_RIFLE) then begin                         \
              stock_pid_qty(who_obj, PID_10MM_JHP, ammo_qty)                                     \
           end else if ((weapon_pid == PID_RED_RYDER_BB_GUN) or                              \
                        (weapon_pid == PID_RED_RYDER_LE_BB_GUN) or                           \
                        (weapon_pid == PID_JONNY_BB_GUN)) then begin                         \
              stock_pid_qty(who_obj, PID_BBS, ammo_qty)                                      \
           end else if ((weapon_pid == PID_TOMMY_GUN) or                                     \
                        (weapon_pid == PID_GREASE_GUN)) then begin                           \
              stock_pid_qty(who_obj, PID_45_CALIBER_AMMO, ammo_qty)                          \
           end else if ((weapon_pid == PID_FN_FAL) or                                        \
                        (weapon_pid == PID_FN_FAL_NIGHT_SCOPE) or                            \
                        (weapon_pid == PID_M60)) then begin                                  \
              stock_pid_qty(who_obj, PID_7_62MM_AMMO, ammo_qty)                              \
           end else if ((weapon_pid == PID_M72_GAUSS_RIFLE) or                               \
                        (weapon_pid == PID_PK12_GAUSS_PISTOL)) then begin                    \
              stock_pid_qty(who_obj, PID_2MM_EC_AMMO, ammo_qty)                              \
           end else if ((weapon_pid == PID_HK_G11) or                                        \
                        (weapon_pid == PID_HK_G11E) or                                       \
                        (weapon_pid == PID_VINDICATOR_MINIGUN)) then begin                   \
              stock_pid_qty(who_obj, PID_4_7MM_CASELESS, ammo_qty)                           \
           end else if (weapon_pid == PID_NEEDLER_PISTOL) then begin                         \
              stock_pid_qty(who_obj, PID_HN_NEEDLER_CARTRIDGE, ammo_qty)                     \
           end                                                                               \
        end

#define arm_obj(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty)                give_obj_weapon(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty, true)
#define stock_weapon_obj(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty)       give_obj_weapon(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty, false)

/******************************************************************
 general macros/defines related to having sex
******************************************************************/
// is_sex_god is temporary for when the player gets the sex perk ***
#define is_sex_god               ((global_var(GVAR_PLAYER_SEX_LEVEL)>=100) or (dude_has_porn_star_rep))
#define have_sex_time_obj(x)     (((get_critter_stat(x,STAT_en)) * random(4,8)) * ONE_GAME_MINUTE)
#define have_quickie_time_obj(x) (((get_critter_stat(x,STAT_en)) * random(2,4)) * ONE_GAME_MINUTE)
#define have_sex_time            have_sex_time_obj(dude_obj)
#define advance_sex_time         game_time_advance(have_sex_time)
// these are to be compared to sex_rating
#define sex_rating_great         (9)
#define sex_rating_good          (7)
#define sex_rating_normal        (5)
#define sex_rating_bad           (3)
#define sex_rating_horrible      (2)
// returns a value between 1 and 10 on how good the sex was
#define obj_sex_rating(x)        ((((get_critter_stat(x,STAT_ch)*50) +                    \
                                    (get_critter_stat(x,STAT_en)*25) +                    \
                                    (get_critter_stat(x,STAT_ag)*13) +                    \
                                    (get_critter_stat(x,STAT_st)*12))/100) +              \
                                    (has_trait(TRAIT_PERK,x,PERK_kama_sutra_perk) * 2) +  \
                                    (has_trait(TRAIT_TRAIT,x,TRAIT_sex_appeal)) +         \
                                    (is_sex_god * 2 * (x == dude_obj)))
#define dude_sex_rating          obj_sex_rating(dude_obj)
#define self_sex_rating          obj_sex_rating(self_obj)
#define up_sex_status_amt(x)     inc_global_var_amt(GVAR_PLAYER_SEX_LEVEL, dude_sex_rating * x);   \
				                     inc_global_var_amt(GVAR_SEX_COUNTER, x);                          \
                                 if (global_var(GVAR_SEX_COUNTER) >= 10) then begin                \
                                    set_global_var(GVAR_GIGOLO, 1);                                \
                                 end                                                               \
                                 if (dude_sex_rating >= sex_rating_great) then begin               \
                                    set_global_var(GVAR_SEXPERT, 1);                               \
                                 end                                                               \
                                 if (global_var(GVAR_DUDE_VIRGIN) == 1) then			               \
				                        set_global_var(GVAR_DUDE_VIRGIN, 0)
#define up_sex_status            up_sex_status_amt(1)
#define do_default_sex           advance_sex_time;    \
                                 up_sex_status

#define dude_is_horny_male                   (dude_is_male and (has_fake_trait(TRAIT_lecherous)))
#define dude_is_horny_female                 (dude_is_female and (has_fake_trait(TRAIT_lecherous)))

#define destroy_obj_inven(obj)                      \
   global_temp := create_object(PID_FOOTLOCKER_CLEAN_LEFT,0,0); \
   move_obj_inven_to_obj(obj, global_temp);                     \
   destroy_object(global_temp)

/*******************************************************************************************************************
********** These represent the players acomplishments through the game *********************************************
********** Note: these reflect the Fallout2 variable designers put in the scripts assuming we were *****************
********** going to have a magic variable to keep track of the player stats throught the game **********************
*******************************************************************************************************************/
#define f2_state_v13_looking                          (0)
#define f2_state_v13_known                            (1)   // set -Chris H
#define f2_state_v13_found                            (2)   // set -Chris H
#define f2_state_v13_entered                          (3)   // set -Chris H
#define f2_state_tribe_kidnapped                      (4)   // ### state not set
#define f2_state_fix_tanker                           (5)   // didn't need to exist
#define f2_state_tanker_fix_known                     (6)   // set -Chris H
#define f2_state_tanker_fixed                         (7)   // set -Chris H
#define f2_state_enclave_destroyed                    (8)   // ### state not set

#define set_f2(x)                                     if (global_var(GVAR_FALLOUT_2) < x) then set_global_var(GVAR_FALLOUT_2, x)
#define force_f2(x)                                   set_global_var(GVAR_FALLOUT_2, x)
#define get_f2(x)                                     (global_var(GVAR_FALLOUT_2) == x)
#define f2_flag_any                                   (global_var(GVAR_FALLOUT_2))

#define Fallout2_vault13_looking                      get_f2(f2_state_v13_looking)
#define Fallout2_vault13_location_known               get_f2(f2_state_v13_known)
#define Fallout2_vault13_found                        get_f2(f2_state_v13_found)
#define Fallout2_vault13_entered                      get_f2(f2_state_v13_entered)
#define Fallout2_tribe_kidnapped                      get_f2(f2_state_tribe_kidnapped)
#define Fallout2_fix_tanker                           get_f2(f2_state_fix_tanker)
#define Fallout2_tanker_known                         get_f2(f2_state_tanker_fix_known)
#define Fallout2_tanker_fixed                         get_f2(f2_state_tanker_fixed)
#define Fallout2_enclave_destroyed                    get_f2(f2_state_enclave_destroyed)


// Info relating to carry weight, how much something costs, and weights
#define pid_weight(x)                                   proto_data(x,it_weight)
#define obj_weight(x)                                   pid_weight(obj_pid(x))
#define pid_cost(x)                                     proto_data(x, it_cost)
#define obj_cost(x)                                     pid_cost(obj_pid(x))

#define amt_cost_barter(who1, who2, x)                  floor(2 * x * ((160.0 + has_skill(who2,SKILL_BARTER)) / (160.0 + has_skill(who1,SKILL_BARTER))))
#define pid_cost_barter(who1, who2, x)                  amt_cost_barter(who1, who2, pid_cost(x))
#define obj_cost_barter(who1, who2, x)                  pid_cost_barter(who1, who2, obj_pid(x))
#define who_max_carry(x)                                get_critter_stat(x,STAT_carry_amt)
#define who_carry_amount(x)                             has_trait(TRAIT_OBJECT, x, OBJECT_CUR_WEIGHT)
#define who_inven_free_amt(x)                           (who_max_carry(x) - who_carry_amount(x))


/********************************************************************
*******************   Game time Limits   ****************************
********************************************************************/

#ifndef TIME_LIMIT_1
#define TIME_LIMIT_1                        (60)
#endif
#ifndef TIME_LIMIT_2
#define TIME_LIMIT_2                        (120)
#endif
#ifndef TIME_LIMIT_3
#define TIME_LIMIT_3                        (180)
#endif
#ifndef TIME_LIMIT_4
#define TIME_LIMIT_4                        (240)
#endif

#define reached_tl_1                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_1)
#define reached_tl_2                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_2)
#define reached_tl_3                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_3)
#define reached_tl_4                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_4)


/********************************************************************
************   These are for cutting down on the lvars   ************
********************************************************************/
// for examples of use, see new reno and raiders
// default bits for character flag
#define herebefore_bit                                bit_1
#define hostile_bit                                   bit_2
#define examined_bit                                  bit_3
#define personal_enemy_bit                            bit_4
#define initialized_bit                               bit_5
#define is_float_bit                                  bit_7
#define destroy_me_bit                                bit_8
#define heard_call_bit                                bit_9

// here before
#define herebefore                                    lvar_bit(LVAR_Flags, herebefore_bit)
#define set_herebefore                                set_lvar_bit_on(LVAR_Flags, herebefore_bit)
#define off_herebefore                                set_lvar_bit_off(LVAR_Flags, herebefore_bit)
// hostile
#define hostile                                       lvar_bit(LVAR_Flags, hostile_bit)
#define set_hostile                                   set_lvar_bit_on(LVAR_Flags, hostile_bit)
#define off_hostile                                   set_lvar_bit_off(LVAR_Flags, hostile_bit)
// examined
#define examined                                      lvar_bit(LVAR_Flags, examined_bit)
#define set_examined                                  set_lvar_bit_on(LVAR_Flags, examined_bit)
// personal enemy
#define personal_enemy                                lvar_bit(LVAR_Flags, personal_enemy_bit)
#define set_personal_enemy                            set_lvar_bit_on(LVAR_Flags, personal_enemy_bit); set_hostile
// initialized
#define destroy_me                                    lvar_bit(LVAR_Flags, destroy_me_bit)
#define set_destroy_me                                set_lvar_bit_on(LVAR_Flags, destroy_me_bit)
// initialized
#define initialized                                   lvar_bit(LVAR_Flags, initialized_bit)
#define set_initialized                               set_lvar_bit_on(LVAR_Flags, initialized_bit)
// heard_call
#define heard_call                                    lvar_bit(LVAR_Flags, heard_call_bit)
#define set_heard_call                                set_lvar_bit_on(LVAR_Flags, heard_call_bit)
// set message type
#define is_float                                      lvar_bit(LVAR_Flags, is_float_bit)
#define is_click                                      (is_float == false)
#define set_is_float                                  set_lvar_bit_on(LVAR_Flags, is_float_bit)
#define set_is_click                                  set_lvar_bit_off(LVAR_Flags, is_float_bit)
#define create_out_of_business(tile, elev, pid)                                                                                                                       \
         if ((tile_contains_pid_obj(tile, elev, PID_OUT_OF_BUSINESS_NORTH) == 0) and (tile_contains_pid_obj(tile, elev, PID_OUT_OF_BUSINESS_EAST) == 0)) then begin   \
            global_temp := create_object_sid(pid, 0, 0, SCRIPT_ZICLOSED);                                                                                                \
            set_obj_visibility(global_temp,true);                                                                                                                        \
            move_to(global_temp, tile, elev);                                                                                                                            \
         end                                                                                                                                                          \
         debug_msg("created out of business @ tile == " + tile + " / elevation == " + elev)
#define create_north_out_of_business(x, e)            create_out_of_business(x, e, PID_OUT_OF_BUSINESS_NORTH)
#define create_east_out_of_business(x, e)             create_out_of_business(x, e, PID_OUT_OF_BUSINESS_EAST)

/*******************************************************************************************************************
********** These are new reno macros that are used in other scripts ************************************************
*******************************************************************************************************************/
// new reno macros start
#define nr_mstr(x)                                    message_str(SCRIPT_HDNCRGYM,(x))

// porn star start
#define porn_star_msg_start                           (500)
#define dude_has_porn_star_rep                        (global_var(GVAR_PORN_STAR) > 0)
#define dude_porn_star_number                         (global_var(GVAR_PORN_STAR))
#define porn_star_name                                (nr_mstr(porn_star_msg_start + dude_porn_star_number))
// porn star end

// made man start
#define family_name_msg_start                         (200)
#define made_man_msg_start                            (300)
#define dude_is_made_man                              (global_var(GVAR_CARAVAN_MASTER) > 0)
#define family_none                                   (0)
#define family_salvatore                              (1)
#define family_bishop                                 (2)
#define family_mordino                                (3)
#define family_wright                                 (4)
#define dude_family                                   (global_var(GVAR_CARAVAN_MASTER)/100)
#define dude_made_man_number                          (global_var(GVAR_CARAVAN_MASTER)%100)
#define dude_family_name                              (nr_mstr(family_name_msg_start + dude_family))
#define made_man_num_to_name(x)                       (nr_mstr(made_man_msg_start + x))
#define made_man_name                                 made_man_num_to_name(dude_made_man_number)
#define salvatore_power                               (global_var(GVAR_SALVATORE_FAMILY_COUNTER))
#define bishop_power                                  (global_var(GVAR_BISHOP_FAMILY_COUNTER))
#define mordino_power                                 (global_var(GVAR_MORDINO_FAMILY_COUNTER))
#define wright_power                                  (global_var(GVAR_WRIGHT_FAMILY_COUNTER))
#define dec_family_counter_amt(the_family, x)         if (family_crushed(the_family) == false) then begin                        \
                                                         if (the_family == family_salvatore) then begin                          \
                                                            dec_global_var_amt(GVAR_SALVATORE_FAMILY_COUNTER,x);                 \
                                                         end else if (the_family == family_bishop) then begin                    \
                                                            dec_global_var_amt(GVAR_BISHOP_FAMILY_COUNTER,x);                    \
                                                         end else if (the_family == family_mordino) then begin                   \
                                                            dec_global_var_amt(GVAR_MORDINO_FAMILY_COUNTER,x);                   \
                                                         end else if (the_family == family_wright) then begin                    \
                                                            dec_global_var_amt(GVAR_WRIGHT_FAMILY_COUNTER,x);                    \
                                                         end                                                                     \
                                                      end                                                                        \
                                                      debug_msg("\nfamily standings: ");                                         \
                                                      debug_msg("\n  Salvatore == "+global_var(GVAR_SALVATORE_FAMILY_COUNTER));  \
                                                      debug_msg("\n  Bishop == "+global_var(GVAR_BISHOP_FAMILY_COUNTER));        \
                                                      debug_msg("\n  Mordino == "+global_var(GVAR_MORDINO_FAMILY_COUNTER));      \
                                                      debug_msg("\n  Wright == "+global_var(GVAR_WRIGHT_FAMILY_COUNTER))
#define family_crushed(x)                             (((x == family_salvatore) and (global_var(GVAR_SALVATORE_FAMILY_COUNTER) <= -1)) or \
                                                       ((x == family_bishop) and (global_var(GVAR_BISHOP_FAMILY_COUNTER) <= -1)) or       \
                                                       ((x == family_mordino) and (global_var(GVAR_MORDINO_FAMILY_COUNTER) <= -1)) or     \
                                                       ((x == family_wright) and (global_var(GVAR_WRIGHT_FAMILY_COUNTER) <= -1)))
#define set_family_crushed(the_family)                if (the_family == family_salvatore) then begin                             \
                                                         set_global_var(GVAR_SALVATORE_FAMILY_COUNTER, -1);                      \
                                                      end else if (the_family == family_bishop) then begin                       \
                                                         set_global_var(GVAR_BISHOP_FAMILY_COUNTER, -1);                         \
                                                      end else if (the_family == family_mordino) then begin                      \
                                                         set_global_var(GVAR_MORDINO_FAMILY_COUNTER, -1);                        \
                                                      end else if (the_family == family_wright) then begin                       \
                                                         set_global_var(GVAR_WRIGHT_FAMILY_COUNTER, -1);                         \
                                                      end
#define dec_family_counter(the_family)                dec_family_counter_amt(the_family, 1)
// made man end

// prize fighter start
#define prizefighter_msg_start                        (400)
#define dude_is_prizefighter                          (global_var(GVAR_HAS_REP_PRIZEFIGHTER) > 0)
#define dude_prizefighter_number                      (global_var(GVAR_PRIZEFIGHTER))
#define prizefighter_name                             (nr_mstr(prizefighter_msg_start + dude_prizefighter_number))
// prize fighter end

#define ncr_bos_war_ended                             (((global_var(GVAR_QUEST_OPERATION_PEACEMAKER) == QUEST_COMPLETED) and (global_var(GVAR_QUEST_HOOVER_PEACE) == QUEST_COMPLETED)) or ((global_var(GVAR_QUEST_HOOVER_PEACE) == QUEST_COMPLETED) and (global_var(GVAR_BROTHERHOOD_DEAD) == 1)))
#define dude_is_ranger   (global_var(GVAR_NCR_PLAYER_RANGER) == 1)
#define dude_has_ncr_connection                       (has_fake_trait(TRAIT_ncr_background) or (dude_name == "Doctor Xoff") or (global_var(GVAR_DUDE_OWNS_FANCY_PAD) == 1) or(global_var(GVAR_DUDE_OWNS_HUMBLE_PAD) == 1) or dude_is_ranger or ncr_bos_war_ended)

/*
procedure create_and_use_itempid_on(variable target, variable itempid) begin
   variable item;
   item := create_object(itempid, 0, elevation(target));
   set_self(target);
   use_obj_on_obj(item, target);
   set_self(0);
end
*/
procedure is_human(variable who) begin
   variable type;
   type := critter_kill_type(who);
   if ((type == KILL_TYPE_men_kills) or (type == KILL_TYPE_women_kills) or (type == KILL_TYPE_children_kills)) then begin
      return true;
   end else begin
      return false;
   end
end

procedure get_dude_attr(variable stat) begin
   variable value;
   value := get_pc_base_stat(stat);

   if(value > 10) then begin
      value := 10;
   end else if (value < 1) then begin
      value := 1;
   end

   return value;
end

procedure set_dude_attr(variable stat, variable value) begin
   if(value > 10) then begin
      value := 10;
   end else if (value < 1) then begin
      value := 1;
   end
   set_pc_base_stat(stat, value);
end

procedure inc_code(variable value) begin
   variable code;
   code = global_var(GVAR_CODE_STATUS) + value;

   if(code >= 100) then begin
      code := 100;
   end

   set_global_var(GVAR_CODE_STATUS, code);

   if(code == 100) then begin
      gfade_out(1);
      // TODO
      //play_gmovie(CODED_MOVIE);
      endgame_slideshow;
   end
end

procedure pick_one(variable first, variable second)       begin
if(random(1, 100) <= 50) then begin
   return first;
end else begin
   return second;
   end
end

procedure dude_wielding_big_gun begin
   variable l, r, ld, rd;
   l := obj_pid(critter_inven_obj(dude_obj, INVEN_TYPE_LEFT_HAND));
   r := obj_pid(critter_inven_obj(dude_obj, INVEN_TYPE_RIGHT_HAND));

   ld := proto_data(l, it_flags_ext);
   rd := proto_data(r, it_flags_ext);

   if(l and dude_is_armed and (ld bwand WEAPON_BIGGUN)) then
      return true;
   else if(r and dude_is_armed and (rd bwand WEAPON_BIGGUN)) then
      return true;
   else
      return false;
end

procedure new_plague_check(variable who, variable lvar_herebefore) begin
   variable allowplague := get_ini_setting("mods\\FalloutYesterday.ini|FalloutYesterday|allow_plage");
   // Only affects humans and non-mutated animals, those we talked to, not wearing PA or EA
	if (allowplague == 1) then begin   
	   if (
		  ((is_human(who) == true) or (critter_kill_type(who) == KILL_TYPE_dog_kills)) and
		  (local_var(lvar_herebefore) > 0) and
		  ((dude_wearing_power_armor == false) and (dude_wearing_environmental_armor == false) and (self_wearing_power_armor == false) and (self_wearing_environmental_armor == false))
		  ) then begin
			 // 10% - EN chance of dying
			 variable max;
			 max = 10 - get_critter_stat(who, STAT_en);

         // After ACT I, the FoA makes sure people survive
         if (global_var(GVAR_ACT) >= 2) then
            max = round(max / 2);

         if (max > 0) then begin
            if(random(1, 100) <= max) then begin
               set_obj_visibility(who, 1);
               destroy_object(who);
            end
         end
      end
end
end

// can we attack the critter?
procedure critter_attackable (variable critter) begin
   if(
      not(is_critter_dead(critter)) and
      obj_is_visible_flag(critter) and
      (self_team != has_trait(TRAIT_OBJECT, critter, OBJECT_TEAM_NUM)) and
      (critter != self_obj) and
      (obj_can_see_obj(self_obj, critter) or obj_can_hear_obj(self_obj, critter))
      ) then
         return true;
      else
         return false;
end

procedure setup_pipboy begin
   if (obj_is_carrying_obj_pid(dude_obj,PID_LIL_PIP_3000)>0) then begin
      set_pipboy_available(1);
   end else begin
      set_pipboy_available(0);
   end
end

#define self_attack_critter(critter)                    if (critter_is_fleeing(self_obj)) then begin        \
                                                         if (anim_busy(self_obj) == false) then begin     \
                                                            Flee_From_Dude                                \
                                                         end                                              \
                                                         end else attack(critter)

#define radius_is_partially_blocked(tile, elev, radius)           ((tile_is_blocked(tile_num_in_direction(tile, 0, radius), elev)) or     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 1, radius), elev)) or     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 2, radius), elev)) or     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 3, radius), elev)) or     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 4, radius), elev)) or     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 5, radius), elev)))

#define closest_clear_multihex_tile(tile, x, distance, elev)          x := tile;                                                                   \
                                                                     if (distance > 1) then                                                        \
                                                                        x := tile_num_in_direction(x, random(0, 5), distance);         \
                                                                     while (radius_is_partially_blocked(x, elev, 1)) do begin   \
                                                                        x := tile_num_in_direction(x, random(0, 5), 1);         \
                                                                     end

#define radius_is_completely_blocked(tile, elev, radius)          ((tile_is_blocked(tile_num_in_direction(tile, 0, radius), elev)) and     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 1, radius), elev)) and     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 2, radius), elev)) and     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 3, radius), elev)) and     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 4, radius), elev)) and     \
                                                                  (tile_is_blocked(tile_num_in_direction(tile, 5, radius), elev)))

#define closest_passable_tile(tile, x, distance, elev)             x := tile;                                                                   \
                                                                  if (distance > 1) then                                                        \
                                                                     x := tile_num_in_direction(x, random(0, 5), distance);         \
                                                                  while (                                               \
                                                                     radius_is_completely_blocked(x, elev, 1) and                 \
                                                                     radius_is_completely_blocked(x, elev, 2) and                  \
                                                                     radius_is_completely_blocked(x, elev, 3)                      \
                                                                  ) do begin   \
                                                                     x := tile_num_in_direction(x, random(0, 5), 1);         \
                                                                  end

#define closest_clear_random_tile(obj, the_tile, x)               x := the_tile;                                                                   \
                                                                  while ((x != tile_num(obj)) and (tile_is_blocked(x, elevation(obj)))) do begin   \
                                                                     x := tile_num_in_direction(x, random(0, 5), 1);         \
                                                                  end

// generic all around functions
#ifndef tile_in_box
#define tile_in_box(x, ul, ur, lr, ll)             tile_in_tile_rect(ul, ur, ll, lr, x)
#endif
#ifndef mid_tile
#define mid_tile(x,y)                              global_temp := x;                                                   \
                                                   while (tile_distance(global_temp, y) > (tile_distance(x,y)/2)) do   \
                                                      global_temp := tile_num_in_direction(global_temp, rotation_to_tile(global_temp,y), 1)
#endif
#ifndef random_tile_in_box
#define random_tile_in_box(ul, ur, lr, ll)         mid_tile(ul,lr);                                                                                   \
                                                   global_temp := tile_num_in_direction(global_temp, random(0,5), random(0, (tile_distance(ul,lr))/2));   \
                                                   if (tile_in_box(global_temp, ul, ur, lr, ll) == false) then global_temp := 0
#endif

#define dude_has_combat_armor             (dude_item(PID_COMBAT_ARMOR) or \
                                          dude_item(PID_BROTHERHOOD_COMBAT_ARMOR) or \
                                          dude_item(PID_HERMES_ARMOR) or \
                                          dude_item(PID_HERMES_ARMOR_MK_II) or \
                                          dude_item(PID_NCR_RANGER_COMBAT_ARMOR) or \
                                          dude_item(PID_NCR_ARMOR) or \
                                          dude_item(PID_COMBAT_ARMOR_MK_II))

// Workaround for a bug where OBJ_DATA_WHO_HIT_ME goes from 0 to -1 on map exit for no obvious reason
#define switch_team(who, team)            if (has_trait(TRAIT_OBJECT, who, OBJECT_TEAM_NUM) != team) then begin     \
                                             if(get_object_data(self_obj, OBJ_DATA_WHO_HIT_ME) == -1) then begin   \
                                                set_object_data(self_obj, OBJ_DATA_WHO_HIT_ME, 0);                 \
                                             end                                                                   \
                                             critter_add_trait(who, TRAIT_OBJECT, OBJECT_TEAM_NUM, team);          \
                                          end

#define debug(str)                        debug_msg("DEBUG: " + str + "\n");         \
                                          if (global_var(GVAR_DEBUG_MODE) == 1) then begin         \
                                             display_msg("DEBUG: " + str + "\n");         \
                                          end

procedure MysteriousStranger begin
   variable Critter, Critter_Tile;

   if (
         dude_trait(PERK_mysterious_stranger) and
         (map_first_run) and
         (not(get_stranger_flag(STRANGER_DEAD))) and
         (random(0, 99) < (30 + (2 * dude_luck)))
         ) then begin
         if (not(get_stranger_flag(STRANGER_GENDER))) then begin
            set_stranger_flag(STRANGER_GENDER);
            debug_msg("Set the Stranger Gender");
            if (random(0, 99) < 50) then
               set_stranger_flag(STRANGER_FEMALE);
      end
      if (get_stranger_flag(STRANGER_FEMALE)) then begin
            if (dude_level > 26) then
               Critter:=create_object_sid(PID_MYST_STRANGER_FEMALE_21,0,0,SCRIPT_ECMSTSTR);
            else if (dude_level > 22) then
               Critter:=create_object_sid(PID_MYST_STRANGER_FEMALE_16_20,0,0,SCRIPT_ECMSTSTR);
            else if (dude_level > 18) then
               Critter:=create_object_sid(PID_MYST_STRANGER_FEMALE_11_15,0,0,SCRIPT_ECMSTSTR);
            else if (dude_level > 14) then
               Critter:=create_object_sid(PID_MYST_STRANGER_FEMALE_5_10,0,0,SCRIPT_ECMSTSTR);
            else
               Critter:=create_object_sid(PID_MYSTERIOUS_STRANGER_FEMALE,0,0,SCRIPT_ECMSTSTR);
      end
      else begin
            if (dude_level > 26) then
               Critter:=create_object_sid(PID_MYST_STRANGER_MALE_21,0,0,SCRIPT_ECMSTSTR);
            else if (dude_level > 22) then
               Critter:=create_object_sid(PID_MYST_STRANGER_MALE_16_20,0,0,SCRIPT_ECMSTSTR);
            else if (dude_level > 18) then
               Critter:=create_object_sid(PID_MYST_STRANGER_MALE_11_15,0,0,SCRIPT_ECMSTSTR);
            else if (dude_level > 14) then
               Critter:=create_object_sid(PID_MYST_STRANGER_MALE_5_10,0,0,SCRIPT_ECMSTSTR);
            else
               Critter:=create_object_sid(PID_MYSTERIOUS_STRANGER_MALE,0,0,SCRIPT_ECMSTSTR);
      end
      Critter_Tile:=tile_num_in_direction(dude_tile,random(0,5),random(5,10));
      critter_attempt_placement(Critter,Critter_Tile,dude_elevation);
  end
end

#define set_self_lootable              if (get_proto_data(self_pid, PROTO_CR_FLAGS) BWAND CFLG_NOSTEAL) then begin         \
                                          set_proto_data(self_pid, PROTO_CR_FLAGS, get_proto_data(self_pid, PROTO_CR_FLAGS) bwand bwnot(CFLG_NOSTEAL)); \
                                       end

procedure MiscLoot begin

   if (random(1,4) == 1) then begin
      destroy_obj_inven(self_obj);
      give_pid_qty(
         self_obj,
         array_random_value([
            PID_MUTATED_FRUIT,
            PID_MEAT_JERKY,
            PID_IGUANA_ON_A_STICK,
            PID_BEER,
            PID_NUKA_COLA,
            PID_CHEEZY_POOFS,
            PID_COOKIE,
            PID_BOX_OF_NOODLES,
            PID_FLOWER,
            PID_POCKET_LINT,
            PID_ROT_GUT,
            PID_CANNED_FOOD,
            PID_CAN,
            PID_CHEESE,
            PID_GUTS_STEW,
            PID_LIVER_CHOPS,
            PID_MUSHROOM_CLOUDS,
            PID_DESERT_SALAD
            ]),
         1)
   end
   else if (random(1,3) == 1) then begin
      destroy_obj_inven(self_obj);
      item_caps_adjust(self_obj, random(1,30));
   end

end

procedure injure_with_skill begin

   variable str_skill_s, str_skill_f, str_skill_e;
   variable body_type = get_proto_data(obj_pid(self_obj), PROTO_CR_BODY_TYPE);
   variable skill = -1;

   if (body_type == CR_BODY_BIPED) then begin
      skill = SKILL_DOCTOR;
      str_skill_s := mstr_skill(615);
      str_skill_f := mstr_skill(617);
      str_skill_e := mstr_skill(616);

   end
   else if (body_type == CR_BODY_QUADRUPED) then begin
      skill = SKILL_SCIENCE;
      str_skill_s := mstr_skill(615);
      str_skill_f := mstr_skill(617);
      str_skill_e := mstr_skill(618);

   end
   else if (body_type == CR_BODY_ROBOTIC) then begin
      skill = SKILL_REPAIR;
      str_skill_s := mstr_skill(603);
      str_skill_f := mstr_skill(604);
      str_skill_e := mstr_skill(605);
   end

   if (
      (skill > -1) and
      (action_being_used == skill) and
      (has_trait(TRAIT_OBJECT, self_obj, OBJECT_TEAM_NUM) != TEAM_PLAYER) and
      (obj_type(self_obj) == OBJ_TYPE_CRITTER) and
      (cur_hits(self_obj) == max_hits(self_obj))
   ) then begin
      script_overrides;
      variable roll := skill_success(source_obj, skill, - (get_critter_stat(self_obj, STAT_en) + cur_hits(self_obj)));
      variable crit_str := "";

      if (roll) then begin
         variable damage;
         damage = critter_skill_level(source_obj, skill);

         give_xp(25);

         if (is_critical(roll)) then begin
            crit_str := mstr_skill(614);
            critter_injure(self_obj, DAM_CRIP_RANDOM);
         end
         else begin
            // Cap non-critical rolls
            if (damage >= 100) then begin
               damage = 99;
            end
         end

         if (tile_distance_objs(source_obj, self_obj) <= 2) then begin
            display_msg(str_skill_s + " " + obj_name(self_obj) + crit_str + " " + str_skill_e);
            critter_dmg(self_obj, damage, DMG_normal_dam);
            attack(source_obj);
         end
      end
      else begin
         display_msg(str_skill_f + " " + obj_name(self_obj) + " " + str_skill_e);
         attack(source_obj);
      end
   end
end

/*
procedure Invasion begin*/

/*   FOLLOWERS_INVADED_DATE    :=90;       //  (148)
   NECROPOLIS_INVADED_DATE   :=110;       //  (149)
   THE_HUB_INVADED_DATE      :=140;       //  (150)
   BROTHERHOOD_INVADED_DATE  :=170;       //  (151)
   JUNKTOWN_INVADED_DATE     :=200;       //  (152)
   SHADY_SANDS_INVADED_DATE  :=230;       //  (153)
   VAULT_13_INVADED_DATE     :=500;       //  (154)
*/
/*
   if (not(global_var(MASTER_BLOWN) == 2)) then begin
      if (global_var(NECROPOLIS_INVADED_DATE) > (game_time / ONE_GAME_DAY)) then begin
         set_global_var(NECROPOLIS_INVADED, 1);
      end
      if (global_var(THE_HUB_INVADED_DATE) > (game_time / ONE_GAME_DAY)) then begin
         set_global_var(HUB_INVADED, 1);
      end
      if (global_var(BROTHERHOOD_INVADED_DATE) > (game_time / ONE_GAME_DAY)) then begin
         set_global_var(BROTHERHOOD_INVADED, 1);
      end
      if (global_var(JUNKTOWN_INVADED_DATE) > (game_time / ONE_GAME_DAY)) then begin
         set_global_var(JUNKTOWN_INVADED, 1);
      end
      if (global_var(SHADY_SANDS_INVADED_DATE) > (game_time / ONE_GAME_DAY)) then begin
         set_global_var(SHADY_SANDS_INVADED, 1);
      end
      if (global_var(VAULT_13_INVADED_DATE) <= 0) then begin
         set_global_var(VAULT_INVADED, 1);
      end
      if (global_var(FOLLOWERS_INVADED_DATE) > (game_time / ONE_GAME_DAY)) then begin
         set_global_var(FOLLOWERS_INVADED, 1);
      end
   end
end
*/

#endif // COMMAND_H
