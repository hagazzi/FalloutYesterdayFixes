// Fallout Yesterday Footsteps SFX Subsystem by PJ Hexer

#ifndef FOOTSTEPS_H
#define FOOTSTEPS_H

// How often do we play the footsteps SFX?
#define WALKING_TICKS_DEFAULT                    (4) // Default walk
#define WALKING_TICKS_SLOWER                     (5) // Super mutants walk slower
#define WALKING_TICKS_VERY_SLOW                  (6) // 3-Headed Rattlesnakes
#define RUNNING_TICKS_DEFAULT                    (3) // Default run

#define WALKING_TIMED_EVENT_ID              (10000)
#define RUNNING_TIMED_EVENT_ID              (10001)

#define SFX_FOOTSTEP_NONE                   ""
#define SFX_FOOTSTEP_SOFT_BAREFOOT          "barefoot\\soft"
#define SFX_FOOTSTEP_MEDIUM_BAREFOOT        "barefoot\\medium"
#define SFX_FOOTSTEP_HARD_BAREFOOT          "barefoot\\hard"
#define SFX_FOOTSTEP_SOFT_SHOE              "shoe\\soft"            // Jumpsuit, Robe, Leather
#define SFX_FOOTSTEP_MEDIUM_SHOE            "shoe\\medium"          // Metal, Combat
#define SFX_FOOTSTEP_HARD_SHOE              "shoe\\hard"            // Power Armor

#define SFX_FOOTSTEP_SURFACE_NONE           ""
#define SFX_FOOTSTEP_SURFACE_WOOD           "Wood"
#define SFX_FOOTSTEP_SURFACE_GRASS          "Grass"
#define SFX_FOOTSTEP_SURFACE_GRAVEL         "Gravel"
#define SFX_FOOTSTEP_SURFACE_METAL          "Metal"
#define SFX_FOOTSTEP_SURFACE_RUG            "Rug"
#define SFX_FOOTSTEP_SURFACE_SAND           "Sand"
#define SFX_FOOTSTEP_SURFACE_SNOW           "Snow"
#define SFX_FOOTSTEP_SURFACE_STONE          "Stone"
#define SFX_FOOTSTEP_SURFACE_WATER          "Water"

#define dude_footsteps_are_soft             (not(dude_is_super_mutant) and not(dude_wearing_metal_armor) and not() and not(dude_wearing_combat_armor) and not(dude_wearing_power_armor))
#define dude_footsteps_are_medium           (dude_wearing_metal_armor or dude_wearing_combat_armor)
#define dude_footsteps_are_hard             (dude_is_super_mutant or dude_wearing_power_armor)

#define crit_is_walking(critter_obj) (art_anim(obj_art_fid(critter_obj)) == ANIM_walk)
#define crit_is_running(critter_obj) (art_anim(obj_art_fid(critter_obj)) == ANIM_running)
#define crit_is_moving(critter_obj)   (crit_is_walking(critter_obj) or crit_is_running(critter_obj))

procedure tile_sfx_is_wood(variable tile_fid);
procedure tile_sfx_is_grass(variable tile_fid);
procedure tile_sfx_is_gravel(variable tile_fid);
procedure tile_sfx_is_rug(variable tile_fid);
procedure tile_sfx_is_snow(variable tile_fid);
procedure tile_sfx_is_water(variable tile_fid);
procedure tile_sfx(variable tile);

procedure play_footsteps_sfx(variable footsteps_type, variable tile) begin
    if (global_var(GVAR_MAX_FOOTSTEPS) == 0) then begin
        set_global_var(GVAR_MAX_FOOTSTEPS, 1);
    end
    else if (global_var(GVAR_MAX_FOOTSTEPS) == 1) then begin
        set_global_var(GVAR_MAX_FOOTSTEPS, 2);
    end
    variable footsteps_sfx := play_sfall_sound("data\\sound\\SFX\\Footsteps\\" + tile_sfx(tile) + "\\" + footsteps_type + random(1, 5) + ".wav", 0);
end

procedure dude_footsteps_sfx begin
    if (dude_footsteps_are_medium) then begin
        return SFX_FOOTSTEP_MEDIUM_SHOE;
    end
    else if (dude_footsteps_are_hard) then begin
        return SFX_FOOTSTEP_HARD_SHOE;
    end

    return SFX_FOOTSTEP_SOFT_SHOE;
end

procedure critter_setup_footsteps_map_enter(variable critter, variable walking_ticks, variable running_ticks) begin
    // setup walking event
    add_timer_event(critter, walking_ticks, WALKING_TIMED_EVENT_ID);
    // setup running event
    add_timer_event(critter, running_ticks, RUNNING_TIMED_EVENT_ID);
end

procedure critter_setup_footsteps_timed_event(variable critter, variable walking_ticks, variable running_ticks, variable footsteps_type) begin
    variable generate_sfx = true;

    if (global_var(GVAR_INI_SETTING_FOOTSTEPS_SFX) == 0) then begin
        generate_sfx = false;
    end
    else if (self_elevation != dude_elevation) then begin
        generate_sfx = false;
    end
    // Performance cap for non-PCs. Too many footsteps at the same time slows down the game, especially in a party
    else if (global_var(GVAR_MAX_FOOTSTEPS) == 2) and (critter != dude_obj) then begin
        set_global_var(GVAR_MAX_FOOTSTEPS, 1);
        generate_sfx = false;
    end
    else if (self_distance_from_dude > (5 + dude_perception)) then begin
        generate_sfx = false;
    end
    else if ((critter != dude_obj) and not(obj_can_hear_obj(dude_obj, critter))) then begin
        generate_sfx = false;
    end

    if (fixed_param == WALKING_TIMED_EVENT_ID) then begin
        if (generate_sfx and anim_busy(critter) and crit_is_walking(critter)) then begin
            call play_footsteps_sfx(footsteps_type, self_tile);
        end
        add_timer_event(critter, walking_ticks, WALKING_TIMED_EVENT_ID);
    end
    else if (fixed_param == RUNNING_TIMED_EVENT_ID) then begin
        if (generate_sfx and anim_busy(critter) and crit_is_running(critter)) then begin
            call play_footsteps_sfx(footsteps_type, self_tile);
        end
        add_timer_event(critter, running_ticks, RUNNING_TIMED_EVENT_ID);
    end
end

procedure tile_sfx_is_sand(variable tile_fid) begin
    if (
        (tile_fid >= 99 and tile_fid <= 101) or
        (tile_fid >= 172 and tile_fid <= 220) or
        (tile_fid >= 1425 and tile_fid <= 1457) or
        (tile_fid >= 3463 and tile_fid <= 3478)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx_is_stone(variable tile_fid) begin
    if (
        (tile_fid >= 2 and tile_fid <= 17) or
        (tile_fid >= 21 and tile_fid <= 44) or
        (tile_fid >= 69 and tile_fid <= 83) or
        (tile_fid >= 117 and tile_fid <= 135) or
        (tile_fid >= 160 and tile_fid <= 171) or
        (tile_fid >= 236 and tile_fid <= 244) or
        (tile_fid == 660) or
        (tile_fid == 674) or
        (tile_fid == 675) or
        (tile_fid >= 679 and tile_fid <= 713) or
        (tile_fid >= 827 and tile_fid <= 913) or
        (tile_fid >= 470 and tile_fid <= 484) or
        (tile_fid >= 1040 and tile_fid <= 1052) or
        (tile_fid >= 2116 and tile_fid <= 2119) or
        (tile_fid >= 2237 and tile_fid <= 2241) or
        (tile_fid >= 2261 and tile_fid <= 2288) or
        (tile_fid >= 2765 and tile_fid <= 2807) or
        (tile_fid >= 3054 and tile_fid <= 3101) or
        (tile_fid >= 3106 and tile_fid <= 3151) or
        (tile_fid == 3201) or
        (tile_fid == 3202) or
        (tile_fid >= 3370 and tile_fid <= 3403) or
        (tile_fid == 3796) or
        (tile_fid >= 3804 and tile_fid <= 3806) or
        (tile_fid == 3809) or
        (tile_fid >= 3864 and tile_fid <= 3934) or
        (tile_fid >= 4064 and tile_fid <= 4188) or
        (tile_fid >= 4285 and tile_fid <= 4309) or
        (tile_fid >= 4489 and tile_fid <= 4507) or
        (tile_fid >= 4631 and tile_fid <= 4696) or
        (tile_fid >= 4708 and tile_fid <= 4748) or
        (tile_fid == 4755) or
        (tile_fid >= 4930 and tile_fid <= 4978) or
        (tile_fid >= 5140 and tile_fid <= 5153) or
        (tile_fid >= 5179 and tile_fid <= 6489) or
        (tile_fid >= 6639 and tile_fid <= 6641) or
        (tile_fid >= 6784 and tile_fid <= 6990) or
        (tile_fid >= 7061 and tile_fid <= 7884) or
        (tile_fid >= 8060 and tile_fid <= 8074) or
        (tile_fid >= 8089 and tile_fid <= 8100) or
        (tile_fid >= 8107 and tile_fid <= 8112) or
        (tile_fid >= 8117 and tile_fid <= 8123) or
        (tile_fid >= 8130 and tile_fid <= 8132)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx_is_metal(variable tile_fid) begin
    if (
        (tile_fid == 18) or
        (tile_fid == 19) or
        (tile_fid >= 102 and tile_fid <= 116) or
        (tile_fid >= 223 and tile_fid <= 235) or
        (tile_fid >= 275 and tile_fid <= 326) or
        (tile_fid >= 757 and tile_fid <= 801) or
        (tile_fid >= 1081 and tile_fid <= 1095) or
        (tile_fid >= 1228 and tile_fid <= 1374) or
        (tile_fid >= 1389 and tile_fid <= 1424) or
        (tile_fid >= 1458 and tile_fid <= 1499) or
        (tile_fid == 1619) or
        (tile_fid == 1620) or
        (tile_fid >= 1827 and tile_fid <= 1891) or
        (tile_fid >= 2028 and tile_fid <= 2092) or
        (tile_fid >= 2389 and tile_fid <= 2399) or
        (tile_fid >= 2517 and tile_fid <= 2528) or
        (tile_fid == 2764) or
        (tile_fid >= 3102 and tile_fid <= 3105) or
        (tile_fid >= 3152 and tile_fid <= 3155) or
        (tile_fid == 3161) or
        (tile_fid >= 3223 and tile_fid <= 3233) or
        (tile_fid >= 3404 and tile_fid <= 3406) or
        (tile_fid >= 3407 and tile_fid <= 3462) or
        (tile_fid >= 3720 and tile_fid <= 3783) or
        (tile_fid >= 3797 and tile_fid <= 3801) or
        (tile_fid == 3807) or
        (tile_fid == 3808) or
        (tile_fid >= 3810 and tile_fid <= 3863) or
        (tile_fid == 4062) or
        (tile_fid == 4063) or
        (tile_fid >= 4189 and tile_fid <= 4284) or
        (tile_fid >= 4423 and tile_fid <= 4488) or
        (tile_fid >= 4979 and tile_fid <= 5047)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx_is_wood(variable tile_fid) begin
    if (
        (tile_fid >= 84 and tile_fid <= 98) or
        (tile_fid >= 1706 and tile_fid <= 1731) or
        (tile_fid >= 1749 and tile_fid <= 1761) or
        (tile_fid >= 4417 and tile_fid <= 4422) or
        (tile_fid >= 4529 and tile_fid <= 4531) or
        (tile_fid >= 4533 and tile_fid <= 4535) or
        (tile_fid >= 5072 and tile_fid <= 5103)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx_is_grass(variable tile_fid) begin
    if (
        (tile_fid == 2289) or
        (tile_fid == 2290) or
        (tile_fid >= 6490 and tile_fid <= 6638)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx_is_gravel(variable tile_fid) begin
    if (
        (tile_fid >= 45 and tile_fid <= 68) or
        (tile_fid >= 136  and tile_fid <= 159) or
        (tile_fid >= 245 and tile_fid <= 274) or
        (tile_fid >= 715 and tile_fid <= 719) or
        (tile_fid >= 1096 and tile_fid <= 1227) or
        (tile_fid >= 1503 and tile_fid <= 1610) or
        (tile_fid >= 1672 and tile_fid <= 1705) or
        (tile_fid >= 1733 and tile_fid <= 1747) or
        (tile_fid >= 1762 and tile_fid <= 1808) or
        (tile_fid >= 1810 and tile_fid <= 1826) or
        (tile_fid >= 2093 and tile_fid <= 2115) or
        (tile_fid >= 2242 and tile_fid <= 2260) or
        (tile_fid >= 3156 and tile_fid <= 3160) or
        (tile_fid >= 3203 and tile_fid <= 3222) or
        (tile_fid >= 3545 and tile_fid <= 3603) or
        (tile_fid == 3802) or
        (tile_fid == 3803) or
        (tile_fid >= 4749 and tile_fid <= 4754) or
        (tile_fid >= 5154 and tile_fid <= 5178) or
        (tile_fid >= 8075 and tile_fid <= 8088) or
        (tile_fid >= 8101 and tile_fid <= 8106) or
        (tile_fid >= 8113 and tile_fid <= 8116) or
        (tile_fid >= 8124 and tile_fid <= 8129)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx_is_rug(variable tile_fid) begin
    if (
        (tile_fid == 20) or
        (tile_fid >= 661 and tile_fid <= 673) or
        (tile_fid >= 1375 and tile_fid <= 1389) or
        (tile_fid >= 1621 and tile_fid <= 1630) or
        (tile_fid == 4532) or
        (tile_fid >= 4536 and tile_fid <= 4547) or
        (tile_fid >= 7014 and tile_fid <= 7048)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx_is_snow(variable tile_fid) begin
    if (
        (tile_fid >= 3949 and tile_fid <= 3951) or
        (tile_fid >= 6642 and tile_fid <= 6783)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx_is_water(variable tile_fid) begin

    // Blood water goo
    if (
        (tile_fid >= 802 and tile_fid <= 811) or
        (tile_fid >= 1053 and tile_fid <= 1080) or
        (tile_fid >= 2529 and tile_fid <= 2547) or
        (tile_fid >= 4775 and tile_fid <= 4793)
    ) then begin
        return true;
    end

    return false;
end

procedure tile_sfx(variable tile) begin

    variable tile_fid = get_tile_ground_fid(tile, dude_elevation);

    // Do any exceptions first
    if (
        (cur_map_index == MAP_HOOVER_DAM_S1C) or
        ((cur_map_index == MAP_SPECIAL_ENCOUNTER_TEMPLE) and (dude_elevation == 1))
    ) then begin
        return SFX_FOOTSTEP_SURFACE_WATER;
    end
    else if (tile_sfx_is_sand(tile_fid)) then begin
        return SFX_FOOTSTEP_SURFACE_SAND;
    end
    else if (tile_sfx_is_wood(tile_fid)) then begin
        return SFX_FOOTSTEP_SURFACE_WOOD;
    end
    else if (tile_sfx_is_grass(tile_fid)) then begin
        return SFX_FOOTSTEP_SURFACE_GRASS;
    end
    else if (tile_sfx_is_gravel(tile_fid)) then begin
        return SFX_FOOTSTEP_SURFACE_GRAVEL;
    end
    else if (tile_sfx_is_rug(tile_fid)) then begin
        return SFX_FOOTSTEP_SURFACE_RUG;
    end
    else if (tile_sfx_is_snow(tile_fid)) then begin
        return SFX_FOOTSTEP_SURFACE_SNOW;
    end
    else if (
        (tile_sfx_is_water(tile_fid)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_CLEAR_WATER_SCENERY)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_DIRTY_WATER_SCENERY)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_SMALL_GOO_1)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_SMALL_GOO_2)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_SMALL_GOO_3)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_RAD_GOO_1)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_RAD_GOO_2)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_RAD_GOO_3)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_RAD_GOO_4)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_1)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_2)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_3)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_4)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_5)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_6)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_7)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_8)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_BLOOD_9)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_DIRTY_WATER_SMALL_1)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_DIRTY_WATER_SMALL_2)) or
        (tile_contains_obj_pid(tile, dude_elevation, PID_DIRTY_WATER_SMALL_3))
    ) then begin
        return SFX_FOOTSTEP_SURFACE_WATER;
    end
    else if (tile_sfx_is_metal(tile_fid)) then begin
        return SFX_FOOTSTEP_SURFACE_METAL;
    end
    else if (tile_sfx_is_stone(tile_fid)) then begin
        return SFX_FOOTSTEP_SURFACE_STONE;
    end

    return SFX_FOOTSTEP_SURFACE_NONE;
end

#endif // FOOTSTEPS_H
