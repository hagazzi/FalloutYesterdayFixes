/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef PARTY_H
#define PARTY_H

/***************************************************************
    The following contain all of the Party information and
    commands for Fallout 2
***************************************************************/

variable How_Many_Party_Members_Are_Injured;
variable How_Many_Party_Members_Armed;

#define FOLLOW_DISTANCE_CLOSE               (3)
#define FOLLOW_DISTANCE_MEDIUM              (6)
#define FOLLOW_DISTANCE_FAR                 (9)

#define obj_in_party(x)                     (party_member_obj(obj_pid(x)) != 0)
// Pointers to the Party Members
#define Hanged_Man_Ptr                      party_member_obj(PID_HANGED_MAN)
#define Otto_Ptr                            party_member_obj(PID_OTTO)
#define Marcus_Ptr                          party_member_obj(PID_MARCUS)
#define Alexandra_Ptr                       party_member_obj(PID_ALEXANDRA)
#define Sulik_Ptr                           party_member_obj(PID_SULIK)
#define Lenny_Ptr                           party_member_obj(PID_LENNY)
#define Cyberdog_Ptr                        party_member_obj(PID_CYBERDOG)
#define Doc_Ptr                             party_member_obj(PID_DOC)
#define Beatrice_Ptr                        party_member_obj(PID_BEATRICE)
#define Miria_Ptr                           party_member_obj(PID_MIRIA)
#define Robobrain_Ptr                       party_member_obj(PID_BRAINBOT)
#define Trunk_Ptr                           party_member_obj(PID_CAR_TRUNK)
#define Dogmeat_Ptr                         party_member_obj(PID_DOGMEAT)
#define Pariah_Dog_Ptr                      party_member_obj(PID_PARIAH_DOG) // temp
#define K9_Ptr                              party_member_obj(PID_K9)
#define Robobrain_Human_Ptr                 party_member_obj(PID_ROBOBRAIN_HUMAN)
#define Robobrain_Abnormal_Ptr              party_member_obj(PID_ROBOBRAIN_ABNORMAL)
#define Robobrain_Chimp_Ptr                 party_member_obj(PID_ROBOBRAIN_CHIMP)
#define Mark_Ptr                            party_member_obj(PID_MARK_GANNON)
// temporary/invisible party members
#define Laddie_Ptr                          party_member_obj(PID_LADDIE)
#define Chicken_Ptr                         party_member_obj(PID_CHICKEN)
#define Karl_Ptr                            party_member_obj(PID_KARL)
#define Jonny_Ptr                           party_member_obj(PID_JONNY)
#define Lloyd_Ptr                           party_member_obj(PID_LLOYD)
#define CopTrunk_Ptr                        party_member_obj(PID_COP_CAR_TRUNK)
#define DuneBuggyTrunk_Ptr                  party_member_obj(PID_DUNE_BUGGY_TRUNK)
#define SemiTruckTrunk_Ptr                  party_member_obj(PID_SEMI_TRUCK_TRUNK)
#define TrainTrunk_Ptr                      party_member_obj(PID_TRAIN_TRUNK)

// Is this person in my party
#define Hanged_Man_In_Party                 (Hanged_Man_Ptr != 0)
#define Otto_In_Party                       (Otto_Ptr != 0)
#define Marcus_In_Party                     (Marcus_Ptr != 0)
#define Alexandra_In_Party                  (Alexandra_Ptr != 0)
#define Sulik_In_Party                      (Sulik_Ptr != 0)
#define Lenny_In_Party                      (Lenny_Ptr != 0)
#define Cyberdog_In_Party                   (Cyberdog_Ptr != 0)
#define Doc_In_Party                        (Doc_Ptr != 0)
#define Beatrice_In_Party                   (Beatrice_Ptr != 0)
#define Miria_In_Party                      (Miria_Ptr != 0)
#define Robobrain_In_Party                  (Robobrain_Ptr != 0)
#define Dogmeat_In_Party                    (Dogmeat_Ptr != 0)
#define Pariah_Dog_In_Party                 (Pariah_Dog_Ptr != 0)
#define K9_In_Party                         (K9_Ptr != 0)
#define Robobrain_Human_In_Party            (Robobrain_Human_Ptr != 0)
#define Robobrain_Abnormal_In_Party         (Robobrain_Abnormal_Ptr != 0)
#define Robobrain_Chimp_In_Party            (Robobrain_Chimp_Ptr != 0)
#define Mark_In_Party                       (Mark_Ptr != 0)
// temporary/invisible party members
#define Laddie_In_Party                     (Laddie_Ptr != 0)
#define Chicken_In_Party                    (Chicken_Ptr != 0)
#define Karl_In_Party                       (Karl_Ptr != 0)
#define Jonny_In_Party                      (Jonny_Ptr != 0)
#define Lloyd_In_Party                      (Lloyd_Ptr != 0)

// Party Size Information
// TODO check for vehicle trunks
#define party_size                          (party_member_count(DONT_LIST_HIDDEN_MEMBERS) - global_var(GVAR_PLAYER_GOT_CAR))
#define true_party_size                     (party_size - 1)
#define party_max_formula                   (floor(dude_charisma / 2) + (has_trait(TRAIT_PERK, dude_obj, PERK_magnetic_personality_perk) - has_fake_trait(TRAIT_feral_kid)))
#define dude_at_max_party_size              ((true_party_size >= (party_max_formula)) or (true_party_size >= 5))
#define party_size_humans                   (Alexandra_In_Party+Mark_In_Party)
#define party_size_male                     (Otto_In_Party+Marcus_In_Party+Mark_In_Party)
#define party_size_female                   (Beatrice_In_Party+Alexandra_In_Party)
#define party_size_strange                  (Otto_In_Party+Marcus_In_Party+Beatrice_In_Party)
#define party_size_biped                    (party_size_male + party_size_female)

// Health of Party Members
#define Is_Injured(Who)                     (get_critter_stat(Who, STAT_current_hp) < get_critter_stat(Who, STAT_max_hit_points))
#define Injured_How_Much(Who)               (get_critter_stat(Who, STAT_max_hit_points) - get_critter_stat(Who, STAT_current_hp))
#define Is_Crippled(Who)                    (critter_state(Who) BWAND (DAM_CRIP_LEG_LEFT BWOR DAM_CRIP_LEG_RIGHT BWOR DAM_CRIP_ARM_LEFT BWOR DAM_CRIP_ARM_RIGHT))
#define Is_Blind(Who)                       (critter_state(Who) BWAND DAM_BLIND)
#define Is_Hurt(Who)                         (Is_Injured(Who) or Is_Crippled(Who) or Is_Blind(Who))
//#define Is_Armed(Who)                       (((obj_item_subtype(critter_inven_obj(Who,INVEN_TYPE_RIGHT_HAND))) == item_type_weapon)       \
//                                            or ((obj_item_subtype(critter_inven_obj(Who,INVEN_TYPE_LEFT_HAND))) == item_type_weapon))
#define Is_Armed(Who)                       (((obj_item_subtype(critter_inven_obj(Who,INVEN_TYPE_RIGHT_HAND))) == item_type_weapon))


#define If_Party_Has_Injured                How_Many_Party_Members_Are_Injured := 0;			\
                                            if (Hanged_Man_In_Party) then                              \
                                                if (Is_Injured(Hanged_Man_Ptr)) then                   \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Otto_In_Party) then                            \
                                                if (Is_Injured(Otto_Ptr)) then                 \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Marcus_In_Party) then                           \
                                                if (Is_Injured(Marcus_Ptr)) then                \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Alexandra_In_Party) then                           \
                                                if (Is_Injured(Alexandra_Ptr)) then                \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Sulik_In_Party) then                            \
                                                if (Is_Injured(Sulik_Ptr)) then                 \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Lenny_In_Party) then                            \
                                                if (Is_Injured(Lenny_Ptr)) then                 \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Cyberdog_In_Party) then                         \
                                                if (Is_Injured(Cyberdog_Ptr)) then              \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Doc_In_Party) then                              \
                                                if (Is_Injured(Doc_Ptr)) then                   \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Beatrice_In_Party) then                            \
                                                if (Is_Injured(Beatrice_Ptr)) then                 \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Miria_In_Party) then                            \
                                                if (Is_Injured(Miria_Ptr)) then                 \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Laddie_In_Party) then                           \
                                                if (Is_Injured(Laddie_Ptr)) then                \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Robobrain_In_Party) then                        \
                                                if (Is_Injured(Robobrain_Ptr)) then             \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (Mark_In_Party) then                             \
                                                if (Is_Injured(Mark_Ptr)) then                  \
                                                    How_Many_Party_Members_Are_Injured+=1;      \
                                            if (How_Many_Party_Members_Are_Injured > 0)


#define If_Party_Is_Armed                   How_Many_Party_Members_Armed := 0;                  \
                                            if (dude_is_armed) then                             \
                                               How_Many_Party_Members_Armed+=1;                 \
                                            if (Hanged_Man_In_Party) then                              \
                                                if (Is_Armed(Hanged_Man_Ptr)) then                     \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Otto_In_Party) then                            \
                                                if (Is_Armed(Otto_Ptr)) then                   \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Marcus_In_Party) then                           \
                                                if (Is_Armed(Marcus_Ptr)) then                  \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Alexandra_In_Party) then                           \
                                                if (Is_Armed(Alexandra_Ptr)) then                  \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Sulik_In_Party) then                            \
                                                if (Is_Armed(Sulik_Ptr)) then                   \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Lenny_In_Party) then                            \
                                                if (Is_Armed(Lenny_Ptr)) then                   \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Cyberdog_In_Party) then                         \
                                                if (Is_Armed(Cyberdog_Ptr)) then                \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Doc_In_Party) then                              \
                                                if (Is_Armed(Doc_Ptr)) then                     \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Miria_In_Party) then                            \
                                                if (Is_Armed(Miria_Ptr)) then                   \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Mark_In_Party) then                           \
                                                if (Is_Armed(Mark_Ptr)) then                  \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Robobrain_In_Party) then                        \
                                                if (Is_Armed(Robobrain_Ptr)) then               \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (Beatrice_In_Party) then                            \
                                                if (Is_Armed(Beatrice_Ptr)) then                   \
                                                    How_Many_Party_Members_Armed+=1;            \
                                            if (How_Many_Party_Members_Armed > 0)

#define Party_Childkiller_Mask              (bit_2 BWOR bit_4 BWOR bit_6 BWOR bit_8 BWOR bit_10 BWOR bit_12 BWOR bit_14 BWOR    \
                                             bit_16 BWOR bit_18 BWOR bit_20 BWOR bit_22 BWOR bit_24 BWOR bit_26 BWOR bit_28     \
                                             BWOR bit_30 BWOR bit_32)

#define attempt_place_party_member(the_obj, the_tile, the_elev)            \
         if (the_obj != 0) then begin                                      \
            if (obj_is_visible_flag(the_obj)) then begin                   \
               critter_attempt_placement(the_obj, the_tile, the_elev);     \
            end                                                            \
         end
#define attempt_place_party(the_tile, the_elev)                                     \
         attempt_place_party_member(Hanged_Man_Ptr, the_tile, the_elev)                    \
         attempt_place_party_member(Otto_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Marcus_Ptr, the_tile, the_elev)                 \
         attempt_place_party_member(Alexandra_Ptr, the_tile, the_elev)                 \
         attempt_place_party_member(Sulik_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Lenny_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Cyberdog_Ptr, the_tile, the_elev)               \
         attempt_place_party_member(Doc_Ptr, the_tile, the_elev)                    \
         attempt_place_party_member(Beatrice_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Miria_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Robobrain_Ptr, the_tile, the_elev)              \
         attempt_place_party_member(Trunk_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Dogmeat_Ptr, the_tile, the_elev)                \
         attempt_place_party_member(Pariah_Dog_Ptr, the_tile, the_elev)             \
         attempt_place_party_member(K9_Ptr, the_tile, the_elev)                     \
         attempt_place_party_member(Robobrain_Human_Ptr, the_tile, the_elev)        \
         attempt_place_party_member(Robobrain_Abnormal_Ptr, the_tile, the_elev)     \
         attempt_place_party_member(Robobrain_Chimp_Ptr, the_tile, the_elev)        \
         attempt_place_party_member(Mark_Ptr, the_tile, the_elev)                 \
         attempt_place_party_member(Chicken_Ptr, the_tile, the_elev)                \
         attempt_place_party_member(Karl_Ptr, the_tile, the_elev)                   \
         attempt_place_party_member(Jonny_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Lloyd_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(CopTrunk_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(DuneBuggyTrunk_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(SemiTruckTrunk_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(TrainTrunk_Ptr, the_tile, the_elev)

//#define Party_Childkiller                   (global_var(GVAR_PARTY_CHILDKILLER) BWAND Party_Childkiller_Mask)

#define Childkiller_Hanged_Man                     ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_2) and (Hanged_Man_Ptr != 0))
#define Childkiller_Myron                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_4) and (Otto_Ptr != 0))
#define Childkiller_Marcus                  ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_6) and (Marcus_Ptr != 0))
#define Childkiller_Alexandra                  ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_8) and (Alexandra_Ptr != 0))
#define Childkiller_Sulik                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_10) and (Sulik_Ptr != 0))
#define Childkiller_Lenny                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_12) and (Lenny_Ptr != 0))
#define Childkiller_Cyberdog                ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_14) and (Cyberdog_Ptr != 0))
#define Childkiller_Doc                     ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_16) and (Doc_Ptr != 0))
#define Childkiller_Beatrice                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_18) and (Beatrice_Ptr != 0))
#define Childkiller_Miria                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_20) and (Miria_Ptr != 0))
#define Childkiller_Laddie                  ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_22) and (Laddie_Ptr != 0))
#define Childkiller_Robobrain               ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_24) and (Robobrain_Ptr != 0))
#define Childkiller_Mark                    ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_26) and (Mark_Ptr != 0))

#define Party_Childkiller                   (Childkiller_Hanged_Man or Childkiller_Myron or Childkiller_Marcus or Childkiller_Alexandra or  \
                                             Childkiller_Sulik or Childkiller_Lenny or Childkiller_Cyberdog or Childkiller_Doc or \
                                             Childkiller_Beatrice or Childkiller_Miria or Childkiller_Laddie or \
                                             Childkiller_Robobrain or Childkiller_Mark)

variable PartyHealingItem;

#define obj_heal_time(x)                     if ((x - (has_fake_perk(PERK_stat) * 20)) > 0) then begin                                    \
                                                game_time_advance(x - (has_fake_perk(PERK_stat) * 20));                                 \
                                             end

#define obj_heal(who)                        if (obj_is_carrying_obj_pid(who,PID_SUPER_STIMPAK)) then begin                     \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                PartyHealingItem:=obj_carrying_pid_obj(who,PID_SUPER_STIMPAK);                  \
                                                use_obj_on_obj(PartyHealingItem,who);                                           \
                                                debug_msg(obj_name(who)+" used super stimpak.");                                \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_STIMPAK)) then begin                      \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_STIMPAK),who);                      \
                                                debug_msg(obj_name(who)+" used stimpak.");                                      \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_HEALING_POWDER)) then begin               \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_HEALING_POWDER),who);               \
                                                debug_msg(obj_name(who)+" used healing powder.");                               \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_DOCTORS_BAG)) then begin                  \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_DOCTORS_BAG),who);                  \
                                                debug_msg(obj_name(who)+" used doctor's bag kit.");                             \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_FIRST_AID_KIT)) then begin                \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_FIRST_AID_KIT),who);                \
                                                debug_msg(obj_name(who)+" used First Aid kit.");                                \
                                             end                                                                                \
                                             else if (has_skill(who,SKILL_DOCTOR) > has_skill(who,SKILL_FIRST_AID)) then begin  \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(ONE_GAME_HOUR)                                                 \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                if (is_success(roll_vs_skill(who,SKILL_DOCTOR,0))) then begin                   \
                                                    critter_heal(who,random(10,25));                                            \
                                                    debug_msg(obj_name(who)+" healed some using doctor skill.");                \
                                                end                                                                             \
                                             end                                                                                \
                                             else begin                                                                         \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(15*ONE_GAME_MINUTE)                                            \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                if (is_success(roll_vs_skill(who,SKILL_FIRST_AID,0))) then begin                \
                                                    critter_heal(who,random(5,15));                                             \
                                                    debug_msg(obj_name(who)+" healed some using first aid skill.");             \
                                                end                                                                             \
                                             end

#define obj_heal_no_skill(who)               if (obj_is_carrying_obj_pid(who,PID_SUPER_STIMPAK)) then begin                     \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                PartyHealingItem:=obj_carrying_pid_obj(who,PID_SUPER_STIMPAK);                  \
                                                use_obj_on_obj(PartyHealingItem,who);                                           \
                                                debug_msg(obj_name(who)+" used super stimpak.");                                \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_STIMPAK)) then begin                      \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_STIMPAK),who);                      \
                                                debug_msg(obj_name(who)+" used stimpak.");                                      \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_HEALING_POWDER)) then begin               \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_HEALING_POWDER),who);               \
                                                debug_msg(obj_name(who)+" used healing powder.");                               \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_DOCTORS_BAG)) then begin                  \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_DOCTORS_BAG),who);                  \
                                                debug_msg(obj_name(who)+" used doctor's bag kit.");                             \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_FIRST_AID_KIT)) then begin                \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_FIRST_AID_KIT),who);                \
                                                debug_msg(obj_name(who)+" used First Aid kit.");                                \
                                             end

#define get_p_hidden_flag_obj(x, the_ptr, the_bit, the_var)             \
         if (x == the_ptr) then begin                                   \
            the_var := gvar_bit(GVAR_PARTY_MEMBERS_HIDDEN, the_bit);    \
         end
#define get_p_hidden_flag(x, hidden)                                                                     \
          get_p_hidden_flag_obj(x, Hanged_Man_Ptr, hidden_hanged_man_bit, hidden)                                      \
          else get_p_hidden_flag_obj(x, Otto_Ptr, hidden_myron_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Marcus_Ptr, hidden_marcus_bit, hidden)                           \
          else get_p_hidden_flag_obj(x, Alexandra_Ptr, hidden_Alexandra_bit, hidden)                           \
          else get_p_hidden_flag_obj(x, Sulik_Ptr, hidden_sulik_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Lenny_Ptr, hidden_lenny_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Cyberdog_Ptr, hidden_cyberdog_bit, hidden)                       \
          else get_p_hidden_flag_obj(x, Doc_Ptr, hidden_doc_bit, hidden)                                 \
          else get_p_hidden_flag_obj(x, Beatrice_Ptr, hidden_beatrice_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Mark_Ptr, hidden_mark_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Miria_Ptr, hidden_miria_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Robobrain_Ptr, hidden_robobrain_bit, hidden)                     \
          else get_p_hidden_flag_obj(x, Dogmeat_Ptr, hidden_dogmeat_bit, hidden)                         \
          else get_p_hidden_flag_obj(x, Pariah_Dog_Ptr, hidden_pariah_dog_bit, hidden)                   \
          else get_p_hidden_flag_obj(x, K9_Ptr, hidden_k9_bit, hidden)                                   \
          else get_p_hidden_flag_obj(x, Robobrain_Human_Ptr, hidden_robobrain_human_bit, hidden)         \
          else get_p_hidden_flag_obj(x, Robobrain_Abnormal_Ptr, hidden_robobrain_abnormal_bit, hidden)   \
          else get_p_hidden_flag_obj(x, Robobrain_Chimp_Ptr, hidden_robobrain_chimp_bit, hidden)
#define party_member_hidden(x, result)                                           \
   if (x) then begin                                                             \
      if (obj_is_visible_flag(x) == 0) then begin                                \
         get_p_hidden_flag(x, result)                                            \
         if (result) then begin                                                  \
            result := 1;                                                         \
         end else begin                                                          \
            result := 0;                                                         \
            debug_msg("PARTY.H:::: party member hidden but not my my macro.. "); \
         end                                                                     \
      end                                                                        \
   end

#define hidden_hanged_man_bit                       bit_1
#define hidden_myron_bit                     bit_2
#define hidden_marcus_bit                    bit_3
#define hidden_Alexandra_bit                    bit_4
#define hidden_sulik_bit                     bit_5
#define hidden_lenny_bit                     bit_6
#define hidden_cyberdog_bit                  bit_7
#define hidden_doc_bit                       bit_8
#define hidden_beatrice_bit                     bit_9
#define hidden_mark_bit                     bit_10
#define hidden_miria_bit                     bit_11
#define hidden_robobrain_bit                 bit_12
#define hidden_dogmeat_bit                   bit_13
#define hidden_pariah_dog_bit                bit_14
#define hidden_k9_bit                        bit_15
#define hidden_robobrain_human_bit           bit_16
#define hidden_robobrain_abnormal_bit        bit_17
#define hidden_robobrain_chimp_bit           bit_18
#define all_hidden_bit                       bit_19

#define party_bit_hidden(x)                  (gvar_bit(GVAR_PARTY_MEMBERS_HIDDEN, x))

#define all_party_hidden                     party_bit_hidden(all_hidden_bit)
#define set_party_bit_hidden(x, member)      set_gvar_bit_on(GVAR_PARTY_MEMBERS_HIDDEN, x); set_obj_visibility(member, 1)
#define party_member_hide(the_obj, the_bit)                                                        \
         if (the_obj) then begin                                                                   \
            if (obj_is_visible_flag(the_obj)) then begin                                           \
               debug_msg("set party member hidden: " + obj_name(the_obj));                         \
               set_party_bit_hidden(the_bit, the_obj);                                             \
            end else begin                                                                         \
               debug_msg("PARTY.H:::: no party member hidden because they already are invisible"); \
            end                                                                                    \
         end
#define party_member_hide_all                                                       \
         set_gvar_bit_on(GVAR_PARTY_MEMBERS_HIDDEN, all_hidden_bit);                \
         party_member_hide(Hanged_Man_Ptr, hidden_hanged_man_bit)                                 \
         party_member_hide(Otto_Ptr, hidden_myron_bit)                             \
         party_member_hide(Marcus_Ptr, hidden_marcus_bit)                           \
         party_member_hide(Alexandra_Ptr, hidden_Alexandra_bit)                           \
         party_member_hide(Sulik_Ptr, hidden_sulik_bit)                             \
         party_member_hide(Lenny_Ptr, hidden_lenny_bit)                             \
         party_member_hide(Cyberdog_Ptr, hidden_cyberdog_bit)                       \
         party_member_hide(Doc_Ptr, hidden_doc_bit)                                 \
         party_member_hide(Beatrice_Ptr, hidden_beatrice_bit)                             \
         party_member_hide(Mark_Ptr, hidden_mark_bit)                             \
         party_member_hide(Miria_Ptr, hidden_miria_bit)                             \
         party_member_hide(Robobrain_Ptr, hidden_robobrain_bit)                     \
         party_member_hide(Dogmeat_Ptr, hidden_dogmeat_bit)                         \
         party_member_hide(Pariah_Dog_Ptr, hidden_pariah_dog_bit)                   \
         party_member_hide(K9_Ptr, hidden_k9_bit)                                   \
         party_member_hide(Robobrain_Human_Ptr, hidden_robobrain_human_bit)         \
         party_member_hide(Robobrain_Abnormal_Ptr, hidden_robobrain_abnormal_bit)   \
         party_member_hide(Robobrain_Chimp_Ptr, hidden_robobrain_chimp_bit)

#define all_party_unhidden                   (all_party_hidden == false)
#define set_party_bit_unhidden(x, member)    debug_msg("unhiding party member "+obj_name(member)); set_gvar_bit_off(GVAR_PARTY_MEMBERS_HIDDEN, x); set_obj_visibility(member, 0)
#define party_member_unhide(the_obj, the_bit)                                                   \
         if (the_obj) then begin                                                                \
            if (obj_is_visible_flag(the_obj) == 0) then begin                                   \
               if (party_bit_hidden(the_bit)) then begin                                        \
                  set_party_bit_unhidden(the_bit, the_obj);                                     \
               end else begin                                                                   \
                  debug_msg("PARTY.H:::: party member wasn't hidden by my macro");              \
               end                                                                              \
            end else begin                                                                      \
               set_party_bit_unhidden(the_bit, the_obj);                                        \
               debug_msg("PARTY.H:::: party member wasn't hidden.. clearing my state");         \
            end                                                                                 \
         end
#define party_member_unhide_all                                                        \
         set_gvar_bit_off(GVAR_PARTY_MEMBERS_HIDDEN, all_hidden_bit);                  \
         party_member_unhide(Hanged_Man_Ptr, hidden_hanged_man_bit)                                  \
         party_member_unhide(Otto_Ptr, hidden_myron_bit)                              \
         party_member_unhide(Marcus_Ptr, hidden_marcus_bit)                            \
         party_member_unhide(Alexandra_Ptr, hidden_Alexandra_bit)                            \
         party_member_unhide(Sulik_Ptr, hidden_sulik_bit)                              \
         party_member_unhide(Lenny_Ptr, hidden_lenny_bit)                              \
         party_member_unhide(Cyberdog_Ptr, hidden_cyberdog_bit)                        \
         party_member_unhide(Doc_Ptr, hidden_doc_bit)                                  \
         party_member_unhide(Beatrice_Ptr, hidden_beatrice_bit)                              \
         party_member_unhide(Mark_Ptr, hidden_mark_bit)                              \
         party_member_unhide(Miria_Ptr, hidden_miria_bit)                              \
         party_member_unhide(Robobrain_Ptr, hidden_robobrain_bit)                      \
         party_member_unhide(Dogmeat_Ptr, hidden_dogmeat_bit)                          \
         party_member_unhide(Pariah_Dog_Ptr, hidden_pariah_dog_bit)                    \
         party_member_unhide(K9_Ptr, hidden_k9_bit)                                    \
         party_member_unhide(Robobrain_Human_Ptr, hidden_robobrain_human_bit)          \
         party_member_unhide(Robobrain_Abnormal_Ptr, hidden_robobrain_abnormal_bit)    \
         party_member_unhide(Robobrain_Chimp_Ptr, hidden_robobrain_chimp_bit)
//End hiding party members


// Default
// party member health states
#define party_healed_max                     (self_cur_hits == self_max_hits)
#define party_healed_good                    (((self_cur_hits * 100)/self_max_hits) >= 90)
#define party_healed_hurt                    (((self_cur_hits * 100)/self_max_hits) >= 70)
#define party_healed_bad                     (((self_cur_hits * 100)/self_max_hits) < 70)

// Generic Options for party members
#define def_heal_msg                         g_mstr(10001)
#define def_wait_msg                         g_mstr(10002)
#define def_unarm_msg                        g_mstr(10003)
#define def_close_msg                        g_mstr(10004)
#ifndef def_med_msg
  #define def_med_msg                        g_mstr(10005)
#endif
#ifndef def_far_msg
  #define def_far_msg                        g_mstr(10006)
#endif
#define def_end_msg                          g_mstr(10007)
#ifndef def_follow_msg
  #define def_follow_msg                     g_mstr(10008)
#endif
#define def_gear_msg                         g_mstr(10009)
#define def_ignore_follow_msg                g_mstr(10010)
#define def_ignore_gear_msg                  g_mstr(10011)
#define def_armor_msg                        g_mstr(10012)
#define def_weapon_use_msg                   g_mstr(10013)
#define def_nowait_msg                       g_mstr(10100)
#define def_stupid_msg                       g_mstr(random(300, 303))

#define DEF_PARTY_HEAL_NODE                  Node1001
#define DEF_PARTY_WAIT_NODE                  Node1002
#define DEF_UNARM_NODE                       Node1003
#define DEF_FOLLOW_CLOSE_NODE                Node1004
#define DEF_FOLLOW_MEDIUM_NODE               Node1005
#define DEF_FOLLOW_FAR_NODE                  Node1006
#define DEF_PARTY_FOLLOW_NODE                Node1007
#define DEF_PARTY_GEAR_NODE                  Node1008
#define DEF_REMOVE_ARMOR_NODE                Node1009
#define DEF_WEAPON_USE_NODE                  Node1010
#define DEF_PARTY_NOWAIT_NODE                Node1100
#define DEF_PARTY_END_NODE                   Node999
#define DEF_PARTY_STUPID_NODE                Node999
#define party_member_options(heal_msg, follow_msg, gear_msg, wait_msg, nowait_msg, end_msg, stupid_msg)  \
                                             if (party_is_waiting == false) then begin                   \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) == 0) then begin     \
                                                   set_follow_medium;                                    \
                                                end                                                      \
                                                if (heal_msg != 0) then begin                            \
                                                   if (self_cur_hits < self_max_hits) then begin         \
                                                      NOption(heal_msg, DEF_PARTY_HEAL_NODE, 004);       \
                                                   end                                                   \
                                                end                                                      \
                                                if (follow_msg != 0) then begin                          \
                                                   NOption(follow_msg, DEF_PARTY_FOLLOW_NODE, 004);      \
                                                end                                                      \
                                                if (gear_msg != 0) then begin                            \
                                                   NOption(gear_msg, DEF_PARTY_GEAR_NODE, 004);          \
                                                end                                                      \
                                                if (wait_msg != 0) then begin                            \
                                                   NOption(wait_msg, DEF_PARTY_WAIT_NODE, 004);          \
                                                end                                                      \
                                             end else if (nowait_msg != 0) then begin                    \
                                                NOption(nowait_msg, DEF_PARTY_NOWAIT_NODE, 004);         \
                                             end                                                         \
                                             if (end_msg != 0) then begin                                \
                                                NOption(end_msg, DEF_PARTY_END_NODE, 004);               \
                                             end                                                         \
                                             if (stupid_msg != 0) then begin                             \
                                                NOption(stupid_msg, DEF_PARTY_STUPID_NODE, -003);        \
                                             end                                                         \
                                             debug_msg("USED PARTY MEMBER OPTIONS")
// this goes into node 1007
#define party_follow_options(close_msg, med_msg, far_msg, follow_ignore_msg)                                                  \
                                             if (close_msg != 0) then begin                                                   \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) != FOLLOW_DISTANCE_CLOSE) then begin      \
                                                   NOption(close_msg, DEF_FOLLOW_CLOSE_NODE, 004);                            \
                                                end                                                                           \
                                             end                                                                              \
                                             if (med_msg != 0) then begin                                                     \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) != FOLLOW_DISTANCE_MEDIUM) then begin     \
                                                   NOption(med_msg, DEF_FOLLOW_MEDIUM_NODE, 004);                             \
                                                end                                                                           \
                                             end                                                                              \
                                             if (far_msg != 0) then begin                                                     \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) != FOLLOW_DISTANCE_FAR) then begin        \
                                                   NOption(far_msg, DEF_FOLLOW_FAR_NODE, 004);                                \
                                                end                                                                           \
                                             end                                                                              \
                                             if (follow_ignore_msg != 0) then begin                                           \
                                                NOption(follow_ignore_msg, PARTY_NODE_X, 004);                                \
                                             end                                                                              \
                                             debug_msg("USED PARTY FOLLOW OPTIONS")

// this goes into node 1008
#define party_gear_options(weapon_use_msg, unarm_msg, armor_msg, gear_ignore_msg)                     \
                                             if (weapon_use_msg != 0) then begin                      \
                                                NOption(weapon_use_msg, DEF_WEAPON_USE_NODE, 004);    \
                                             end                                                      \
                                             if (unarm_msg != 0) then begin                           \
                                                if (self_is_armed) then begin                         \
                                                   NOption(unarm_msg, DEF_UNARM_NODE, 004);           \
                                                end                                                   \
                                             end                                                      \
                                             if (armor_msg != 0) then begin                           \
                                                if (self_wearing_armor) then begin                    \
                                                   NOption(armor_msg, DEF_REMOVE_ARMOR_NODE, 004);    \
                                                end                                                   \
                                             end                                                      \
                                             if (gear_ignore_msg != 0) then begin                     \
                                                NOption(gear_ignore_msg, PARTY_NODE_X, 004);          \
                                             end                                                      \
                                             debug_msg("USED PARTY GEAR OPTIONS")

#define party_member_default_options         party_member_options(def_heal_msg, def_follow_msg, def_gear_msg, def_wait_msg, def_nowait_msg, def_end_msg, def_stupid_msg)
#define party_member_def_follow_options      party_follow_options(def_close_msg, def_med_msg, def_far_msg, def_ignore_follow_msg)
#define party_member_def_gear_options        party_gear_options(def_weapon_use_msg, def_unarm_msg, def_armor_msg, def_ignore_gear_msg)

// party member follow macros
#define party_no_follow_on                   set_global_var(GVAR_PARTY_NO_FOLLOW, 1)
#define party_no_follow_off                  set_global_var(GVAR_PARTY_NO_FOLLOW, 0)
#define party_no_follow                      (global_var(GVAR_PARTY_NO_FOLLOW) != 0)

#define set_follow_close                     set_local_var(LVAR_FOLLOW_DISTANCE, FOLLOW_DISTANCE_CLOSE)
#define set_follow_medium                    set_local_var(LVAR_FOLLOW_DISTANCE, FOLLOW_DISTANCE_MEDIUM)
#define set_follow_far                       set_local_var(LVAR_FOLLOW_DISTANCE, FOLLOW_DISTANCE_FAR)
#define party_member_follow_dude             if ((party_is_waiting == false) and (party_no_follow == false)) then begin                \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) == 0) then begin                                   \
                                                   set_follow_medium;                                                                  \
                                                end                                                                                    \
                                                party_follow_dude_point(((3*local_var(LVAR_FOLLOW_DISTANCE))/2), local_var(LVAR_FOLLOW_DISTANCE))  \
                                             end

// party member team macros
#ifndef set_default_party_follow
  #define set_default_party_follow           set_follow_medium
#endif
#define store_party_team                     if (self_team != TEAM_PLAYER) then begin                 \
                                                set_local_var(LVAR_TEAM, self_team);                  \
                                             end
#define party_add_self                       if (is_critter_dead(self_obj) == false) then begin                            \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) == 0) then begin                       \
                                                   set_default_party_follow;                                               \
                                                end                                                                        \
                                                set_local_var(LVAR_WAITING, 0);                                            \
                                                store_party_team                                                           \
                                                critter_add_trait(self_obj, TRAIT_OBJECT, OBJECT_TEAM_NUM, TEAM_PLAYER);   \
                                                party_add(self_obj);                                                       \
                                             end                                                                           \
                                             debug_msg("join party: " + self_name)
#define party_remove_self                    party_remove(self_obj)

// party member abandons party macros
#define abandoned_party                      (local_var(LVAR_TEAM) == -1)
#define set_self_abandon_party               if (obj_in_party(self_obj)) then begin                                                \
                                                debug_msg("abandon party: " + self_name);                                          \
                                                party_remove_self;                                                                 \
                                             end                                                                                   \
                                             if (self_pid == PID_MIRIA) then begin                    \
                                                set_dude_was_married;                                                              \
                                             end                                                                                   \
                                             if ((local_var(LVAR_TEAM) != -1) and (self_team == false)) then begin                 \
                                                 critter_add_trait(self_obj, TRAIT_OBJECT, OBJECT_TEAM_NUM, local_var(LVAR_TEAM)); \
                                                 set_local_var(LVAR_TEAM, -1);                                                     \
                                             end                                                                                   \
                                             debug_msg("" + obj_name(self_obj) + " has abandoned the party")

// party member waiting macros
#define party_is_waiting                     (local_var(LVAR_WAITING) != 0)
#define set_party_waiting                    set_local_var(LVAR_WAITING, game_time);      \
                                             party_remove_self
#define end_party_waiting                    set_local_var(LVAR_WAITING, 0);              \
                                             party_add_self


/***************************************************************************************
   This is to check to see if there are any party members within range of the door
   so it doesn't close.
****************************************************************************************/

/* How far do party members have to be from the door before it closes */
#define PARTY_CLOSE_DIST                (5)

#define CHECKMEMBERNEARDOOR(inparty, obj)                                           \
         if (inparty) then begin                                                    \
            if (tile_distance_objs(self_obj, obj) <= PARTY_CLOSE_DIST) then begin   \
               return 1;                                                            \
            end                                                                     \
         end

procedure checkPartyMembersNearDoor begin
   CHECKMEMBERNEARDOOR(Hanged_Man_In_Party, Hanged_Man_Ptr)
   CHECKMEMBERNEARDOOR(Otto_In_Party, Otto_Ptr)
   CHECKMEMBERNEARDOOR(Marcus_In_Party, Marcus_Ptr)
   CHECKMEMBERNEARDOOR(Alexandra_In_Party, Alexandra_Ptr)
   CHECKMEMBERNEARDOOR(Sulik_In_Party, Sulik_Ptr)
   CHECKMEMBERNEARDOOR(Lenny_In_Party, Lenny_Ptr)
   CHECKMEMBERNEARDOOR(Cyberdog_In_Party, Cyberdog_Ptr)
   CHECKMEMBERNEARDOOR(Doc_In_Party, Doc_Ptr)
   CHECKMEMBERNEARDOOR(Beatrice_In_Party, Beatrice_Ptr)
   CHECKMEMBERNEARDOOR(Mark_In_Party, Mark_Ptr)
   CHECKMEMBERNEARDOOR(Miria_In_Party, Miria_Ptr)
   CHECKMEMBERNEARDOOR(Robobrain_In_Party, Robobrain_Ptr)
   CHECKMEMBERNEARDOOR(Laddie_In_Party, Laddie_Ptr)
   CHECKMEMBERNEARDOOR(Chicken_In_Party, Chicken_Ptr)
   CHECKMEMBERNEARDOOR(Karl_In_Party, Karl_Ptr)
   CHECKMEMBERNEARDOOR(Jonny_In_Party, Jonny_Ptr)
   CHECKMEMBERNEARDOOR(Lloyd_In_Party, Lloyd_Ptr)
   CHECKMEMBERNEARDOOR(Dogmeat_In_Party, Dogmeat_Ptr)
   CHECKMEMBERNEARDOOR(Pariah_Dog_In_Party, Pariah_Dog_Ptr)
   return 0;
end

#define party_member_map_enter                        if (cur_map_index == MAP_MODOC_BEDNBREAKFAST or cur_map_index == MAP_THE_SQUAT_B) then \
                                                         if ((self_elevation != dude_elevation) and (party_is_waiting)) then move_to(self_obj, self_tile, dude_elevation)



procedure HealParty begin
   critter_heal(dude_obj,dude_max_hits - dude_cur_hits);
   critter_uninjure(dude_obj, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));

   if (Hanged_Man_In_Party) then begin
      if (Is_Injured(Hanged_Man_Ptr) or Is_Crippled(Hanged_Man_Ptr)) then begin
         critter_heal(Hanged_Man_Ptr,Injured_How_Much(Hanged_Man_Ptr));
         critter_uninjure(Hanged_Man_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Otto_In_Party) then begin
      if (Is_Injured(Otto_Ptr) or Is_Crippled(Otto_Ptr)) then begin
         critter_heal(Otto_Ptr,Injured_How_Much(Otto_Ptr));
         critter_uninjure(Otto_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Marcus_In_Party) then begin
      if (Is_Injured(Marcus_Ptr) or Is_Crippled(Marcus_Ptr)) then begin
         critter_heal(Marcus_Ptr,Injured_How_Much(Marcus_Ptr));
         critter_uninjure(Marcus_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Alexandra_In_Party) then begin
      if (Is_Injured(Alexandra_Ptr) or Is_Crippled(Alexandra_Ptr)) then begin
         critter_heal(Alexandra_Ptr,Injured_How_Much(Alexandra_Ptr));
         critter_uninjure(Alexandra_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Sulik_In_Party) then begin
      if (Is_Injured(Sulik_Ptr) or Is_Crippled(Sulik_Ptr)) then begin
         critter_heal(Sulik_Ptr,Injured_How_Much(Sulik_Ptr));
         critter_uninjure(Sulik_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Lenny_In_Party) then begin
      if (Is_Injured(Lenny_Ptr) or Is_Crippled(Lenny_Ptr)) then begin
         critter_heal(Lenny_Ptr,Injured_How_Much(Lenny_Ptr));
         critter_uninjure(Lenny_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Cyberdog_In_Party) then begin
      if (Is_Injured(Cyberdog_Ptr) or Is_Crippled(Cyberdog_Ptr)) then begin
         critter_heal(Cyberdog_Ptr,Injured_How_Much(Cyberdog_Ptr));
         critter_uninjure(Cyberdog_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Doc_In_Party) then begin
      if (Is_Injured(Doc_Ptr) or Is_Crippled(Doc_Ptr)) then begin
         critter_heal(Doc_Ptr,Injured_How_Much(Doc_Ptr));
         critter_uninjure(Doc_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Beatrice_In_Party) then begin
      if (Is_Injured(Beatrice_Ptr) or Is_Crippled(Beatrice_Ptr)) then begin
         critter_heal(Beatrice_Ptr,Injured_How_Much(Beatrice_Ptr));
         critter_uninjure(Beatrice_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Mark_In_Party) then begin
      if (Is_Injured(Mark_Ptr) or Is_Crippled(Mark_Ptr)) then begin
         critter_heal(Mark_Ptr,Injured_How_Much(Mark_Ptr));
         critter_uninjure(Mark_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Miria_In_Party) then begin
      if (Is_Injured(Miria_Ptr) or Is_Crippled(Miria_Ptr)) then begin
         critter_heal(Miria_Ptr,Injured_How_Much(Miria_Ptr));
         critter_uninjure(Miria_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Robobrain_In_Party) then begin
      if (Is_Injured(Robobrain_Ptr) or Is_Crippled(Robobrain_Ptr)) then begin
         critter_heal(Robobrain_Ptr,Injured_How_Much(Robobrain_Ptr));
         critter_uninjure(Robobrain_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   if (Dogmeat_In_Party) then begin
      if (Is_Injured(Dogmeat_Ptr) or Is_Crippled(Dogmeat_Ptr)) then begin
         critter_heal(Dogmeat_Ptr,Injured_How_Much(Dogmeat_Ptr));
         critter_uninjure(Dogmeat_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
   //DAN DON'T worry about Pariah Dog...Chris Holland said to exclude him from healing
   if (K9_In_Party) then begin
      if (Is_Injured(K9_Ptr) or Is_Crippled(K9_Ptr)) then begin
         critter_heal(K9_Ptr,Injured_How_Much(K9_Ptr));
         critter_uninjure(K9_Ptr, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end
end

procedure BeastlordPossess begin
   if(has_fake_trait(TRAIT_beastlord)) then begin

      if (is_success(roll_vs_skill(dude_obj, SKILL_OUTDOORSMAN, -get_critter_stat(self_obj, STAT_current_hp)))) then begin
         switch_team(self_obj, TEAM_PLAYER)
         display_msg(mstr_skill(608) + " " + obj_name(self_obj) + " " + mstr_skill(610));
      end else begin
         display_msg(mstr_skill(609) + " " + obj_name(self_obj) + " " + mstr_skill(610));
         // 50% chance of going berserk
         if((random(1, 2) == 2) and self_can_see_dude) then begin
            self_attack_dude;
         end
      end

   end
end

procedure BeastlordUnpossess(variable team) begin
   if (self_obj and has_trait(TRAIT_OBJECT, self_obj, OBJECT_TEAM_NUM) != team) then begin
      switch_team(self_obj, team)
   end
end

#define HEAL_HURT          (1)
#define HEAL_POISON        (2)
#define HEAL_RADIATION     (3)
#define HEAL_PARTY         (4)
#define HEAL_HP            (5)
#define HEAL_CRIPPLE       (6)

procedure HealPlayer(variable hours, variable cost, variable type, variable fade) begin

   if (fade == 1) then begin
      fadeout(1);
   end

   if(cost != 0) then begin
      item_caps_adjust(dude_obj, cost);
   end

   if(type == HEAL_HURT) then begin
      if (Is_Injured(dude_obj) or Is_Crippled(dude_obj)) then begin
         critter_heal(dude_obj, Injured_How_Much(dude_obj));
         critter_uninjure(dude_obj, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end else if (type == HEAL_POISON) then begin
      if (dude_is_poisoned) then begin
         poison(dude_obj, -get_poison(dude_obj));
      end
   end else if (type == HEAL_RADIATION) then begin
      if(dude_is_irradiated) then begin
         radiation_dec(dude_obj, dude_is_irradiated);
      end
   end else if (type == HEAL_PARTY) then begin
      call HealParty;
   end else if (type == HEAL_HP) then begin
      if (Is_Injured(dude_obj)) then begin
         critter_heal(dude_obj, Injured_How_Much(dude_obj));
      end
   end else if (type == HEAL_CRIPPLE) then begin
      if (dude_is_crippled) then begin
         critter_uninjure(dude_obj, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT));
      end
   end

   if (hours > 0) then begin
      game_time_advance(ONE_GAME_HOUR * hours);
   end

   if (fade == 1) then begin
      fadein(1);
   end

end

#endif // PARTY_H
