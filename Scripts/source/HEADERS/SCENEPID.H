/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef SCENEPID_H
#define SCENEPID_H

/***********************************************************
   Filename: ScenePid.h

    Purpose: This file stores all of the Pid Numbers for
             scenery objects. All defines within here need
             to be prepended w/ PID_

    Created: December 19, 1997
***********************************************************/

variable Scenery_Creation;
variable Scenery_Creation_Hex;
variable Scenery_Creation_Count;
variable Temp_Scenery_Creation_Hex;
variable Scenery_Creation_Ptr;

#define PID_BLOCKING_HEX                    (33554499) //66
#define PID_BLOWN_ARROYO_CAVE_DOOR          (33555365)
#define PID_ARROYO_CAVE_DOOR                (33555366)
#define PID_TEMPLE_SKULL_POLE               (33555374)

#define PID_BURNING_BARREL                  (33554433)
#define PID_FIREPIT                         (33555632)
#define PID_TIBBETS_FORCE_FIELD             (33556455)

// Weed

#define PID_WEED01                          (33554534)
#define PID_WEED02                          (33554535)
#define PID_WEED03                          (33554536)
#define PID_WEED04                          (33554537)
#define PID_WEED24                          (33554557)
#define PID_WEED25                          (33554558)
#define PID_WEED26                          (33554559)

// Strippers
#define PID_STRIPPER_BRUNETTE               (33558498)
#define PID_STRIPPER_BLACK_HAIR             (33558499)

// V8 Door
#define PID_V8_VAULT_DOOR                   (33556321)

// Navarro Door
#define PID_NS_NAVARRO_BUNKER_DOOR          (33554450)

// Sierra Base Entrance Door
#define PID_SIERRA_ENTRANCE_DOOR            (33555779)
#define PID_SIERRA_ENTRANCE_DOOR_EXP        (33555780)

// Enclave Puzzle Room Doors
#define PID_ENCLAVE_PUZZLE_DOOR_EW          (33556005)
#define PID_ENCLAVE_PUZZLE_DOOR_NS          (33556006)

// Klaxon Light
#define PID_EW_LIGHT                        (33555259)
#define PID_NS_LIGHT                        (33555260)
#define PID_EW_FLASHING_LIGHT               (33555339)
#define PID_NS_FLASHING_LIGHT               (33555340)

// Misc Trap Info
#define PID_CAVE_FLOOR_TRAP_VISIBLE         (33555383)
#define PID_CAVE_FLOOR_TRAP_DISARMED        (33555384)
#define PID_CAVE_FLOOR_TRAP_DEPRESSED       (33555385)

#define PID_METAL_FLOOR_TRAP_VISIBLE        (33555429)
#define PID_METAL_FLOOR_TRAP_DISARMED       (33555430)
#define PID_METAL_FLOOR_TRAP_DEPRESSED      (33555431)

// Mining Carts
#define PID_MINING_CART                     (33555584)
#define PID_MINING_CART_PLANK               (33555585)
#define PID_MINING_CART_EXPLOSIVE           (33555586)
#define PID_MINING_CART_DESTROYED           (33556060)

// military base enterance
#define PID_MB_DESTROYED_ROCKS_1            (33556235)
#define PID_MB_DESTROYED_ROCKS_2            (33556236)
#define PID_MB_DESTROYED_ROCKS_3            (33556237)
#define PID_MB_DESTROYED_ROCKS_4            (33556238)

// Force Fields
#define PID_NS_FORCE_FIELD                  (33554921)
#define PID_EW_FORCE_FIELD                  (33554922)
#define PID_NS_PAIN_FIELD                   (33554923)
#define PID_EW_PAIN_FIELD                   (33554924)
#define PID_EW_ANIM_FIELD                   (33555980)
#define PID_NS_ANIM_FIELD                   (33555981)

// Rocks Info
#define PID_LARGE_BLUE_ROCK_PILE            (33554513)
#define PID_CAVE_IN_ROCKS                   (33554839)
#define PID_CAVE_IN_ROCKS_OUTDOOR           (33554674)

// grave site
#define PID_GRAVE_SITE                      (33555444)
#define PID_GRAVE_HEADSTONE_1               (33555445)
#define PID_GRAVE_HEADSTONE_2               (33555446)
#define PID_GRAVE_HEADSTONE_3               (33555447)
#define PID_GRAVE_HEADSTONE_4               (33555448)

// grave site crosses
#define PID_GRAVE_CROSS_1                   (33555669)
#define PID_GRAVE_CROSS_2                   (33555670)
#define PID_GRAVE_CROSS_3                   (33555671)
#define PID_GRAVE_CROSS_4                   (33555672)
#define PID_GRAVE_CROSS_5                   (33555673)
#define PID_GRAVE_CROSS_6                   (33555674)

#define PID_BUSTED_HIGHWAYMAN                    (33555442)

// Car
#define PID_DRIVABLE_CAR                    (33555441)
#define PID_DRIVABLE_MOTORCYCLE             (33558501)
#define PID_DRIVABLE_BUGGY                  (33554508)
#define PID_DRIVABLE_COP_CAR                (33554646)
#define PID_DRIVABLE_SEMI_TRUCK             (33558502)
#define PID_DRIVABLE_TRAIN                  (-1)
#define PID_DRIVABLE_BICYCLE                (33556351)

// Caravans
#define PID_EW_RED_CARAVAN                  (33554959)
#define PID_EW_GREY_CARAVAN                 (33554960)
#define PID_NS_RED_CARAVAN                  (33554961)
#define PID_RED_CARAVAN_HANDLE              (33554962)
#define PID_NS_GREY_CARAVAN                 (33554963)
#define PID_GREY_CARAVAN_HANDLE             (33554964)

// Broken Brain Bot
#define PID_BROKEN_BRAINBOT                 (33555662)

//VDU Looks like a computer with a lot of monitors
#define PID_VDU_WORKING                     (33554488)
#define PID_VDU_NOT_WORKING                 (33555233)
#define PID_VDU_NOT_WORKING2                (33555232)

// BRAHMIN CHUNKS
#define PID_BRAHMIN_CHUNK_1                 (33555731)
#define PID_BRAHMIN_CHUNK_2                 (33555732)
#define PID_BRAHMIN_CHUNK_3                 (33555733)
#define PID_BRAHMIN_CHUNK_4                 (33555734)
#define PID_BRAHMIN_CHUNK_5                 (33555735)
#define PID_BRAHMIN_CHUNK_6                 (33555736)

// Blood
#define PID_BLOOD_1                         (33555753)   // no bones
#define PID_BLOOD_2                         (33555754)
#define PID_BLOOD_3                         (33555755)
#define PID_BLOOD_4                         (33555756)
#define PID_BLOOD_5                         (33555757)
#define PID_BLOOD_6                         (33555758)
#define PID_BLOOD_7                         (33555759)   // bones
#define PID_BLOOD_8                         (33555760)
#define PID_BLOOD_9                         (33555761)

// Ghost Farm Stakes
#define PID_STAKE_1                         (33555648)   // with body
#define PID_STAKE_2                         (33555649)
#define PID_STAKE_3                         (33555650)
#define PID_STAKE_4                         (33555651)
#define PID_STAKE_5                         (33555652)
#define PID_STAKE_6                         (33555653)
#define PID_STAKE_7                         (33555654)   // with skull
#define PID_STAKE_8                         (33555655)
#define PID_STAKE_9                         (33555656)   // plain stake
#define PID_STAKE_10                        (33555657)
#define PID_STAKE_11                        (33555658)
#define PID_STAKE_12                        (33555659)

// Corn stalks
#define PID_CORN_1                          (33555395)
#define PID_CORN_2                          (33555396)
#define PID_CORN_3                          (33555397)
#define PID_CORN_4                          (33555398)
#define PID_CORN_5                          (33555399)
#define PID_CORN_6                          (33555400)

// small goo
#define PID_SMALL_GOO_1                     (33555178)
#define PID_SMALL_GOO_2                     (33555179)
#define PID_SMALL_GOO_3                     (33555180)

// radioactive goo
#define PID_RAD_GOO_1                       (33555417)
#define PID_RAD_GOO_2                       (33555418)
#define PID_RAD_GOO_3                       (33555419)
#define PID_RAD_GOO_4                       (33555420)

// Doors
#define PID_JAIL_DOOR_N_S                   (33555013)

// Slagged Door
#define PID_SLAGGED_DOOR_BOTTOM             (33555810)
#define PID_SLAGGED_DOOR_TOP                (33555811)

// out of business sighns
#define PID_OUT_OF_BUSINESS_NORTH           (33555587)
#define PID_OUT_OF_BUSINESS_EAST            (33555588)

// slot machines
#define PID_SLOT_FACING_2                   (33554898)
#define PID_SLOT_FACING_3                   (33554897)

// Gas tank
#define PID_GAS_TANK_SCENERY                (33558484)

#define PID_DIRTY_WATER_SMALL_1             (33554649) // 218
#define PID_DIRTY_WATER_SMALL_2             (33554650) // 219
#define PID_DIRTY_WATER_SMALL_3             (33554651) // 220

#define PID_CLEAR_WATER_SCENERY             (33555451) // 1018
#define PID_DIRTY_WATER_SCENERY             (33558384) // 3951

#define PID_CAMPFIRE                        (33557837)

#define PID_CIRCLE_OF_STONES_NORTH          (33558169)
#define PID_CIRCLE_OF_STONES_SOUTH          (33558168)

// Misc Commands

// This will make the cave-in rocks with all the blocking Hexes
#define Create_Cave_In(Hex_Num,Elevation,Cave_In_Type_PID)   Scenery_Creation:=create_object(Cave_In_Type_PID,Hex_Num,Elevation);                   \
                                            Scenery_Creation_Hex:=tile_num_in_direction(Hex_Num,3,1);                               \
                                            Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);       \
                                            Scenery_Creation_Hex:=tile_num_in_direction(Hex_Num,0,1);                               \
                                            Temp_Scenery_Creation_Hex:=Scenery_Creation_Hex;                                        \
                                            Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);       \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 3) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,5,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 2) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,0,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 1) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,5,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 2) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,0,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=1;                                                              \
                                            while (Scenery_Creation_Count < 1) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,1,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 2) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,2,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 1) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,1,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 5) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,2,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Hex:=tile_num_in_direction(Temp_Scenery_Creation_Hex,1,1);             \
                                            Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 2) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,2,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 1) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,1,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end                                                                                     \
                                            Scenery_Creation_Count:=0;                                                              \
                                            while (Scenery_Creation_Count < 4) do begin                                             \
                                                Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,0,1);              \
                                                Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                Scenery_Creation_Count+=1;                                                          \
                                            end


// Blocking Hex Cycle
#define create_blocking_hex(the_tile, the_elev) move_to(create_object(PID_BLOCKING_HEX, the_tile, the_elev), the_tile, the_elev)
#define Blocking_Cycle(Rot,Count,Elevation)     Scenery_Creation_Count:=0;                                                              \
                                                while (Scenery_Creation_Count < Count) do begin                                         \
                                                   Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,Rot,1);            \
                                                   Scenery_Creation:=create_object(PID_BLOCKING_HEX,Scenery_Creation_Hex,Elevation);   \
                                                   Scenery_Creation_Count+=1;                                                          \
                                                end

#define remove_blocking_hex(the_tile, the_elev) destroy_object(tile_contains_pid_obj(the_tile,the_elev,PID_BLOCKING_HEX))
#define Dest_Block_Cycle(Rot,Count,Elevation)   Scenery_Creation_Count:=0;                                                              \
                                                while (Scenery_Creation_Count < Count) do begin                                         \
                                                    Scenery_Creation_Hex:=tile_num_in_direction(Scenery_Creation_Hex,Rot,1);            \
                                                    Scenery_Creation_Ptr:=tile_contains_pid_obj(Scenery_Creation_Hex,Elevation,PID_BLOCKING_HEX);   \
                                                    destroy_object(Scenery_Creation_Ptr);                                               \
                                                    Scenery_Creation_Count+=1;                                                          \
                                                end

#define Check_Create_Car(Hex_Num, Elevation)                                          \
   debug_msg("Check_Create_Car(" + Hex_Num + "," + Elevation + ")");                  \
   if (not is_loading_game) then begin                                                \
      if (dude_has_car != false) then begin                                           \
         debug_msg("car_current_town == " + car_current_town + " / map_get_load_area == " + map_get_load_area); \
         if ((car_current_town == map_get_load_area) or ((AREA_RND_DESERT <= car_current_town) and (car_current_town <= AREA_RND_COAST) and (map_get_load_area == -1))) then begin \
            Create_Car(Hex_Num, Elevation)                                            \
            if (tile_contains_pid_obj(Hex_Num, Elevation, PID_DRIVABLE_CAR) != 0) then begin \
               Create_Trunk(Hex_Num, Elevation)                                       \
            end                                                                       \
         end else if (tile_contains_pid_obj(Hex_Num, Elevation, PID_DRIVABLE_CAR) != 0) then begin \
            Dest_Car(Hex_Num, Elevation)                                              \
         end                                                                          \
      end else begin                                                                  \
         debug_msg("the player hasn't gotten the car, can't place it");               \
      end                                                                             \
   end else begin                                                                     \
      debug_msg("sorry, can't place the car, the game's loading");                    \
   end                                                                                \

// This will make the East-West Caravans
#define Create_EW_Caravan(Pid,Hex_Num,Elevation)    Scenery_Creation:=create_object(Pid,Hex_Num,Elevation);                     \
                                                    Scenery_Creation_Hex:=Hex_Num;                                              \
                                                    Blocking_Cycle(1,1,Elevation)                                              \
                                                    Blocking_Cycle(3,2,Elevation)                                              \
                                                    Blocking_Cycle(4,2,Elevation)                                              \
                                                    Blocking_Cycle(5,1,Elevation)                                              \
                                                    Blocking_Cycle(0,1,Elevation)                                              \
                                                    Blocking_Cycle(5,1,Elevation)                                              \
                                                    Blocking_Cycle(1,2,Elevation)

#define Create_EW_Red_Caravan(Hex_Num,Elevation)    Create_EW_Caravan(PID_EW_RED_CARAVAN,Hex_Num,Elevation)
#define Create_EW_Grey_Caravan(Hex_Num,Elevation)   Create_EW_Caravan(PID_EW_GREY_CARAVAN,Hex_Num,Elevation)

// This will make North-South Caravans
#define Create_NS_Caravan(Pid,Hex_Num,Elevation)    Scenery_Creation:=create_object(Pid,Hex_Num,Elevation);                                          \
                                                    Scenery_Creation_Hex:=tile_num_in_direction(Hex_Num,5,2);                                        \
                                                    if (Pid == PID_NS_RED_CARAVAN) then                                                              \
                                                        Scenery_Creation:=create_object(PID_RED_CARAVAN_HANDLE,Scenery_Creation_Hex,Elevation);      \
                                                    else                                                                                             \
                                                        Scenery_Creation:=create_object(PID_GREY_CARAVAN_HANDLE,Scenery_Creation_Hex,Elevation);     \
                                                    Blocking_Cycle(1,1,Elevation)                                                                   \
                                                    Blocking_Cycle(2,3,Elevation)                                                                   \
                                                    Blocking_Cycle(3,1,Elevation)                                                                   \
                                                    Blocking_Cycle(4,1,Elevation)                                                                   \
                                                    Blocking_Cycle(5,3,Elevation)

#define Create_Slagged_Door(Hex_Num,Elevation)      Scenery_Creation:=create_object(PID_SLAGGED_DOOR_BOTTOM,Hex_Num,Elevation); \
                                                    Scenery_Creation:=create_object(PID_SLAGGED_DOOR_TOP,Hex_Num,Elevation);    \
                                                    Scenery_Creation_Hex:=tile_num_in_direction(Hex_Num,2,1);                   \
                                                    Blocking_Cycle(2,1,Elevation)                                               \
                                                    Blocking_Cycle(4,2,Elevation)                                               \
                                                    Blocking_Cycle(5,4,Elevation)                                               \
                                                    Blocking_Cycle(0,2,Elevation)                                               \
                                                    Blocking_Cycle(5,1,Elevation)                                               \
                                                    Blocking_Cycle(0,1,Elevation)

// This will see if a tile is blocked by a blocking hex
#define tile_is_blocked_hex(tile, elev)        (tile_contains_pid_obj(tile, elev, PID_BLOCKING_HEX) != 0)

#define tile_is_blocked(tile, elev)        ((obj_blocking_tile(tile, elev, BLOCKING_TYPE_BLOCK) != 0) or (obj_blocking_tile(tile, elev, BLOCKING_TYPE_AI)  != 0))

#endif // SCENEPID_H
