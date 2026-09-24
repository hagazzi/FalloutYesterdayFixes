/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.

TODO

Introduce plans for the player to progress to the position of the caravan master in the future.

bigger stakes and earnings as the player advances to the role of the caravan master

*/

#ifndef CARAVAN_H
#define CARAVAN_H

/**********************************************************
   All thing great and important to know about Caravans
   for travel on the world map and beyond
**********************************************************/


// Set States for the Caravan
#define set_caravan_status(x)               set_global_var(GVAR_CARAVAN_STATUS,x)
#define set_caravan_start(x)                set_global_var(GVAR_CARAVAN_START,x)
#define set_caravan_end(x)                  set_global_var(GVAR_CARAVAN_END,x)

#define set_caravan_masters(x)              set_global_var(GVAR_CARAVAN_MASTERS_TOTAL,x);               \
                                            set_global_var(GVAR_CARAVAN_MASTERS,x)
#define set_caravan_drivers(x)              set_global_var(GVAR_CARAVAN_DRIVERS_TOTAL,x);               \
                                            set_global_var(GVAR_CARAVAN_DRIVERS,x)
#define set_caravan_guards(x)               set_global_var(GVAR_CARAVAN_GUARDS_TOTAL,x);                \
                                            set_global_var(GVAR_CARAVAN_GUARDS,x)
#define set_caravan_brahmin(x)              set_global_var(GVAR_CARAVAN_BRAHMIN_TOTAL,x);               \
                                            set_global_var(GVAR_CARAVAN_BRAHMIN,x)
#define set_caravan_carts(x)                set_global_var(GVAR_CARAVAN_CARTS_TOTAL,x);                 \
                                            set_global_var(GVAR_CARAVAN_CARTS,x)
#define set_caravan_encounters(x)           set_global_var(GVAR_CARAVAN_ENCOUNTERS_TOTAL,x);            \
                                            set_global_var(GVAR_CARAVAN_ENCOUNTERS,x)

// Current Counts for the Caravan
#define caravan_masters_left                global_var(GVAR_CARAVAN_MASTERS)
#define caravan_drivers_left                global_var(GVAR_CARAVAN_DRIVERS)
#define caravan_guards_left                 global_var(GVAR_CARAVAN_GUARDS)
#define caravan_brahmin_left                global_var(GVAR_CARAVAN_BRAHMIN)
#define caravan_carts_left                  global_var(GVAR_CARAVAN_CARTS)
#define encounters_left                     global_var(GVAR_CARAVAN_ENCOUNTERS)
#define caravan_status                      global_var(GVAR_CARAVAN_STATUS)

#define caravan_total_masters               global_var(GVAR_CARAVAN_MASTERS_TOTAL)
#define caravan_total_drivers               global_var(GVAR_CARAVAN_DRIVERS_TOTAL)
#define caravan_total_guards                global_var(GVAR_CARAVAN_GUARDS_TOTAL)
#define caravan_total_brahmin               global_var(GVAR_CARAVAN_BRAHMIN_TOTAL)
#define caravan_total_carts                 global_var(GVAR_CARAVAN_CARTS_TOTAL)

// Set Lost/Destroyed States for Caravan
#define rm_caravan_masters(x)               set_global_var(GVAR_CARAVAN_MASTERS,global_var(GVAR_CARAVAN_MASTERS) - x)
#define rm_caravan_drivers(x)               set_global_var(GVAR_CARAVAN_DRIVERS,global_var(GVAR_CARAVAN_DRIVERS) - x)
#define rm_caravan_guards(x)                set_global_var(GVAR_CARAVAN_GUARDS,global_var(GVAR_CARAVAN_GUARDS) - x)
#define rm_caravan_brahmin(x)               set_global_var(GVAR_CARAVAN_BRAHMIN,global_var(GVAR_CARAVAN_BRAHMIN) - x)
#define rm_caravan_carts(x)                 set_global_var(GVAR_CARAVAN_CARTS,global_var(GVAR_CARAVAN_CARTS) - x)

// Check Killed/Lost States
#define caravan_masters_killed              (global_var(GVAR_CARAVAN_MASTERS_TOTAL) - global_var(GVAR_CARAVAN_MASTERS))
#define caravan_drivers_killed              (global_var(GVAR_CARAVAN_DRIVERS_TOTAL) - global_var(GVAR_CARAVAN_DRIVERS))
#define caravan_guards_killed               (global_var(GVAR_CARAVAN_GUARDS_TOTAL) - global_var(GVAR_CARAVAN_GUARDS))
#define caravan_brahmin_killed              (global_var(GVAR_CARAVAN_BRAHMIN_TOTAL) - global_var(GVAR_CARAVAN_BRAHMIN))
#define caravan_carts_lost                  (global_var(GVAR_CARAVAN_CARTS_TOTAL) - global_var(GVAR_CARAVAN_CARTS))

#define caravan_start                       global_var(GVAR_CARAVAN_START)
#define caravan_end                         global_var(GVAR_CARAVAN_END)

#define dude_is_caravan_master              (dude_is_made_man)

#define too_many_carts                      ((caravan_carts_left > ((caravan_brahmin_left/2) + (caravan_brahmin_left % 2))) and (caravan_brahmin_left != 0))

#define give_money(who,amount)              if (dude_fortune_finder) then                               \
                                                item_caps_adjust(who,2*(amount));                       \
                                            else                                                        \
                                                item_caps_adjust(who,(amount))

// ZZZ TODO Keep up-to-date
#define map_is_random_encounter             ((cur_town == -1) or                                             \
                                            (cur_town == AREA_RND_DESERT) or                              \
                                            (cur_town == AREA_RND_MOUNTAIN) or                              \
                                            (cur_town == AREA_RND_CITY) or                              \
                                            (cur_town == AREA_RND_COAST) or                              \
                                            (cur_town == AREA_SPECIAL_RND_GROVE) or                              \
                                            (cur_town == AREA_SPECIAL_RND_PULOWSKIS) or                              \
                                            (cur_town == AREA_SPECIAL_RND_TENTACLES) or                              \
                                            (cur_town == AREA_SPECIAL_RND_LAMP) or                              \
                                            (cur_town == AREA_SPECIAL_RND_CAR_MART) or                              \
                                            (cur_town == AREA_SPECIAL_RND_GUARDIAN) or                              \
                                            (cur_town ==  AREA_SPECIAL_RND_CASINO) or                              \
                                            (cur_town == AREA_LANDING_SITE) or                              \
                                            (cur_town == AREA_SPECIAL_RND_CRANIUM_RATS) or                              \
                                            (cur_town == AREA_SPECIAL_RND_CARIB) or                              \
                                            (cur_town == AREA_SHADOW_MAPS) or                              \
                                            (cur_town == AREA_SPECIAL_RND_VAULT69) or                              \
                                            (cur_town == AREA_SPECIAL_RND_POSTMAN) or                              \
                                            (cur_town == AREA_SPECIAL_RND_PET_CEMETERY) or                              \
                                            (cur_town == AREA_SCAVEN_PICKER_CAMP) or                              \
                                            (cur_town == AREA_SPECIAL_RND_CAMP_SITE) or                          \
                                            (cur_town == AREA_SPECIAL_RND_EDDIE) or                              \
                                            (cur_town == AREA_SPECIAL_RND_THUNDERBIRD))

// Caravan run default lengths in days
#define CARAVAN_RUN_DAYS_HOOVER_DAM_JERICHO          (40)
#define CARAVAN_RUN_DAYS_HOOVER_DAM_BLACKFOOT        (25)

procedure BuildCaravanTeam(variable where_tile) begin
    if(caravan_status == CARAVAN_STATUS_ON_JOB) then begin

        variable Master_Counter:=0;
        variable Caravan_Counter:=0;
        variable Brahmin_Counter:=0;
        variable Driver_Counter:=0;
        variable Guard_Counter:=0;
        variable Critter;
        variable Critter_Tile;
        variable Brahmin_Tile;
        variable Driver_Tile;
        variable Critter_Rotation;
        variable Brahmin_Rotation;
        variable Driver_Rotation;
        variable item;
        variable Weapon_Roll;
        variable val;
        variable Master;
        variable Master_Tile;
        variable Guard;
        variable Guard_Tile;
        variable is_rnd_enc;

        is_rnd_enc := map_is_random_encounter;

        if (is_rnd_enc) then begin

            // Place the Caravan, Driver and Brahmin
            while (too_many_carts) do begin
                rm_caravan_carts(1);
            end

            while (Caravan_Counter < caravan_carts_left) do begin
                Caravan_Counter+=1;

                Critter_Tile:=tile_num_in_direction(where_tile,Critter_Rotation,8);
                closest_clear_multihex_tile(where_tile, Critter_Tile, random(5,6), dude_elevation)

                if (Caravan_Counter % 2 == 0) then begin
                    Create_EW_Red_Caravan(Critter_Tile,0)
                end
                else begin
                    Create_EW_Grey_Caravan(Critter_Tile,0)
                end

                Brahmin_Tile:=tile_num_in_direction(Critter_Tile,0,1);
                Critter:=create_object_sid(PID_BRAHMIN,0,0,SCRIPT_ECCRTBRA);
                critter_attempt_placement(Critter,Brahmin_Tile,0);
                switch_team(Critter, TEAM_PLAYER)
                reg_anim_clear(Critter);
                reg_anim_begin();
                anim(Critter, ANIMATE_ROTATION, 1);
                reg_anim_end();
                Brahmin_Counter+=1;

                if (Brahmin_Counter < caravan_brahmin_left) then begin
                    Brahmin_Tile:=tile_num_in_direction(Critter_Tile,2,2);
                    Critter:=create_object_sid(PID_BRAHMIN,0,0,SCRIPT_ECCRTBRA);
                    critter_attempt_placement(Critter,Brahmin_Tile,0);
                    switch_team(Critter, TEAM_PLAYER)
                    reg_anim_clear(Critter);
                    reg_anim_begin();
                    anim(Critter, ANIMATE_ROTATION, 1);
                    reg_anim_end();
                    Brahmin_Counter+=1;
                end

                if (Driver_Counter < caravan_drivers_left) then begin
                    Driver_Counter+=1;

                    if (Driver_Counter % 2 == 0) then begin
                        Critter:=create_object_sid(PID_BOUNTY_FEMALE_7_12,0,0,SCRIPT_RCCVNDRV);
                    end
                    else begin
                        Critter:=create_object_sid(PID_BOUNTY_MALE_7_12,0,0,SCRIPT_RCCVNDRV);
                    end

                    critter_add_trait(Critter,TRAIT_OBJECT,OBJECT_AI_PACKET,AI_CARAVAN_DRIVER);
                    Driver_Tile:=tile_num_in_direction(Critter_Tile,1,3);
                    if (radius_is_completely_blocked(Driver_Tile, dude_elevation, 1)) then
                        closest_passable_tile(Driver_Tile, Driver_Tile, 1, dude_elevation)
                    critter_attempt_placement(Critter,Driver_Tile,0);
                    switch_team(Critter, TEAM_PLAYER)
                    give_money(Critter,random(5,20));

                    item:=create_object(PID_CATTLE_PROD,0,0);
                    add_obj_to_inven(Critter,item);
                    wield_obj_critter(Critter,item);
                end
            end

            // Place the Brahmin
            Brahmin_Tile:=tile_num_in_direction(where_tile,random(0,5),random(7,10));
            closest_clear_multihex_tile(where_tile, Brahmin_Tile, 2, dude_elevation)

            while (Brahmin_Counter < caravan_brahmin_left) do begin
                Brahmin_Counter+=1;

                Brahmin_Tile:=tile_num_in_direction(Brahmin_Tile,random(0,5),random(2,5));
                Critter:=create_object_sid(PID_BRAHMIN,0,0,SCRIPT_ECCRTBRA);
                critter_add_trait(Critter,TRAIT_OBJECT,OBJECT_AI_PACKET,AI_GENERIC_BRAHMIN);
                critter_attempt_placement(Critter,Brahmin_Tile,0);
                switch_team(Critter, TEAM_PLAYER)
            end
        end

        // Place the Caravan Master
        while (Master_Counter < caravan_masters_left) do begin
            Master_Counter+=1;
            Master_Tile:=tile_num_in_direction(dude_tile,0,1);
            if (radius_is_completely_blocked(Master_Tile, dude_elevation, 1)) then
                closest_passable_tile(Master_Tile, Master_Tile, 1, dude_elevation)

            if (caravan_end == AREA_JERICHO) then
                Master:=create_object_sid(PID_GRAND_MASTER_TRADER_MALE,Master_Tile,dude_elevation,SCRIPT_HDCM);
            else
                Master:=create_object_sid(PID_GRAND_MASTER_TRADER_FEMALE,Master_Tile,dude_elevation,SCRIPT_HDCM);

            add_obj_to_inven(Master, create_object(PID_NEEDLER_PISTOL,0,0));

            switch_team(Master, TEAM_PLAYER)
            critter_add_trait(Master,TRAIT_OBJECT,OBJECT_AI_PACKET,AI_TOUGH_MERCHANT);

            critter_attempt_placement(Master,Master_Tile,dude_elevation);
            give_money(Master,random(10,30));
        end

        if (is_rnd_enc) then begin

            // Place the Caravan Drivers
            Driver_Rotation:=(Critter_Rotation+1) % 6;
            Driver_Tile:=tile_num_in_direction(0,Driver_Rotation,random(7,10));

            while (Driver_Counter < caravan_drivers_left) do begin
                Driver_Counter+=1;
                Driver_Tile:=tile_num_in_direction(dude_tile, random(0,5), random(2,4));
                if (radius_is_completely_blocked(Driver_Tile, dude_elevation, 1)) then
                    closest_passable_tile(Driver_Tile, Driver_Tile, 1, dude_elevation)

                if (Driver_Counter % 2 == 0) then begin
                    Critter:=create_object_sid(PID_BOUNTY_MALE_7_12,Driver_Tile,dude_elevation,SCRIPT_RCCVNDRV);
                end
                else begin
                    Critter:=create_object_sid(PID_BOUNTY_FEMALE_7_12,Driver_Tile,dude_elevation,SCRIPT_RCCVNDRV);
                end

                critter_attempt_placement(Critter,Driver_Tile,0);
                switch_team(Critter, TEAM_PLAYER)
                critter_add_trait(Critter,TRAIT_OBJECT,OBJECT_AI_PACKET,AI_CARAVAN_DRIVER);
                give_money(Critter,random(5,20));
            end

            while (Guard_Counter < caravan_guards_left) do begin
                Guard_Counter+=1;

                Guard_Tile:=tile_num_in_direction(dude_tile,random(0,5),random(2,4));
                if (radius_is_completely_blocked(Guard_Tile, dude_elevation, 1)) then
                    closest_passable_tile(Guard_Tile, Guard_Tile, 1, dude_elevation)

                if (Guard_Counter % 2 == 0) then begin
                    Guard:=create_object_sid(PID_BOUNTY_MALE_7_12,Guard_Tile,dude_elevation,SCRIPT_RCCVNGRD);
                end
                else begin
                    Guard:=create_object_sid(PID_BOUNTY_FEMALE_7_12,Guard_Tile,dude_elevation,SCRIPT_RCCVNGRD);
                end

                critter_attempt_placement(Guard,Guard_Tile,0);

                item:=create_object(pick_one(PID_NEEDLER_PISTOL,PID_ASSAULT_RIFLE_EXT_MAG),0,0);

                give_money(Guard,random(10,20));
                switch_team(Guard, TEAM_PLAYER)
                critter_add_trait(Guard,TRAIT_OBJECT,OBJECT_AI_PACKET,AI_CARAVAN_GUARD);
                add_obj_to_inven(Guard,item);
                wield_obj_critter(Guard,item);

                if (random(1,100) <= 50) then begin
                    give_pid_qty(Guard, PID_STIMPAK, 1)
                end
            end
        end
    end
end

procedure CalculateCaravanRunSuccessRate(variable caravan) begin
    if (
        (global_var(caravan) != CARAVAN_NONE) and
        (global_var(caravan) != CARAVAN_ABANDONED) and
        (global_var(caravan) != CARAVAN_THEFT)
    ) then begin
        if ((caravan_status == CARAVAN_STATUS_ON_JOB) and (cur_town != caravan_end)) then
            set_global_var(caravan, CARAVAN_ABANDONED);
        else if((global_var(GVAR_CARAVAN_START_TIME) > 0) and (((game_time - global_var(GVAR_CARAVAN_START_TIME)) / ONE_GAME_DAY) >= (global_var(GVAR_CARAVAN_EXPECTED_TIME) * 2))) then
            set_global_var(caravan, CARAVAN_TOTAL_FAILURE);
        else if ((caravan_guards_left < (caravan_total_guards/4)) or (caravan_brahmin_left < ((caravan_total_brahmin*4)/10))) then
            set_global_var(caravan,CARAVAN_TOTAL_FAILURE);
        else if ((caravan_guards_left < (caravan_total_guards/2)) or (caravan_brahmin_left < ((caravan_total_brahmin*6)/10))) then
            set_global_var(caravan, CARAVAN_FAILURE);
        else if((global_var(GVAR_CARAVAN_START_TIME) > 0) and (((game_time - global_var(GVAR_CARAVAN_START_TIME)) / ONE_GAME_DAY) > (global_var(GVAR_CARAVAN_EXPECTED_TIME) + ONE_GAME_WEEK))) then
            set_global_var(caravan, CARAVAN_FAILURE);
        else if ((caravan_guards_left == caravan_total_guards) and (caravan_brahmin_left == caravan_total_brahmin)) then
            set_global_var(caravan,CARAVAN_COMPLETE_SUCCESS);
        else if ((caravan_guards_left >= (caravan_total_guards - 1)) and (caravan_brahmin_left >= (caravan_total_brahmin - 2))) then
            set_global_var(caravan, CARAVAN_AVERAGE_SUCCESS);
        else
            set_global_var(caravan, CARAVAN_AVERAGE_SUCCESS);
    end
end

procedure SetupCurrentCaravanForCaravanMaster begin
    if (caravan_start == AREA_HOOVER_DAM) then begin
        // 3-Some Caravan
        if(caravan_end == AREA_JERICHO) then
           return GVAR_WATER_CARAVAN;
        // Crimson Caravan
        else if(caravan_end == AREA_BLACKFOOT) then
           return GVAR_CHEM_CARAVAN;
     end
end

#endif // CARAVAN_H
