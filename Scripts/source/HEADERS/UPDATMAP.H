/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef UPDATMAP_H
#define UPDATMAP_H

// Lighting Information
#define BRIGHT_LIGHT                    (100)
#define CAVERN_LIGHT                    (50)
#define DUSK_LIGHT                      (40)
#define TIBBETS_LIGHT                   (60)
#define INDOOR_LIGHT                    (60)
#define BASEMENT_LIGHT                  (50)
#define MILITARY_BASE_LIGHTING          (75)
#define SHADY_LIGHTING                  (60)
// These numbers are equivalent to power percentage of the Space Center's main building. See quest GVAR_QUEST_15_RESTORE_OC_POWER
#define SPACE_CENTER_BROKEN_LIGHT       (45)
#define SPACE_CENTER_REPAIR_LIGHT       (85)
#define SCUM_PITS_LIGHT                 (45)

#define WINTER_MORNING                  (700)
#define SPRING_MORNING                  (600)
#define SUMMER_MORNING                  (500)
#define FALL_MORNING                    (600)

#define WINTER_EVENING                  (1700)
#define SPRING_EVENING                  (1800)
#define SUMMER_EVENING                  (1900)
#define FALL_EVENING                    (1800)

#define season_morning(when)            ((game_time_hour >= (when)) and (game_time_hour < (when + 100)))
#define season_day(sunrise,sunset)      ((game_time_hour >= (sunrise + 100)) and (game_time_hour < sunset))
#define season_evening(when)            ((game_time_hour >= (when)) and (game_time_hour < (when + 100)))

#define Spring_Lighting                 if (season_morning(SPRING_MORNING)) then                                \
                                            set_light_level((game_time_hour - SPRING_MORNING) + DUSK_LIGHT + night_vision_goggles);    \
                                        else if (season_day(SPRING_MORNING,SPRING_EVENING)) then                \
                                            set_light_level(BRIGHT_LIGHT);                                               \
                                        else if (season_evening(SPRING_EVENING)) then                           \
                                            set_light_level(BRIGHT_LIGHT - (game_time_hour - SPRING_EVENING) + night_vision_goggles);  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Summer_Lighting                 if (season_morning(SUMMER_MORNING)) then                                \
                                            set_light_level((game_time_hour - SUMMER_MORNING) + DUSK_LIGHT + night_vision_goggles);    \
                                        else if (season_day(SUMMER_MORNING,SUMMER_EVENING)) then                \
                                            set_light_level(BRIGHT_LIGHT);                                               \
                                        else if (season_evening(SUMMER_EVENING)) then                           \
                                            set_light_level(BRIGHT_LIGHT - (game_time_hour - SUMMER_EVENING) + night_vision_goggles);  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Fall_Lighting                   if (season_morning(FALL_MORNING)) then                                  \
                                            set_light_level((game_time_hour - FALL_MORNING) + DUSK_LIGHT + night_vision_goggles);      \
                                        else if (season_day(FALL_MORNING,FALL_EVENING)) then                    \
                                            set_light_level(BRIGHT_LIGHT);                                               \
                                        else if (season_evening(FALL_EVENING)) then                             \
                                            set_light_level(BRIGHT_LIGHT - (game_time_hour - FALL_EVENING) + night_vision_goggles);    \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Winter_Lighting                 if (season_morning(WINTER_MORNING)) then                                \
                                            set_light_level((game_time_hour - WINTER_MORNING) + DUSK_LIGHT + night_vision_goggles);    \
                                        else if (season_day(WINTER_MORNING,WINTER_EVENING)) then                \
                                            set_light_level(BRIGHT_LIGHT);                                               \
                                        else if (season_evening(WINTER_EVENING)) then                           \
                                            set_light_level(BRIGHT_LIGHT - (game_time_hour - WINTER_EVENING) + night_vision_goggles);  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Lighting                        if ((get_month >= 3) and (get_month < 5)) then                          \
                                            Spring_Lighting;                                                    \
                                        else if ((get_month >= 5) and (get_month < 9)) then                     \
                                            Summer_Lighting;                                                    \
                                        else if ((get_month >= 9) and (get_month < 11)) then                    \
                                            Fall_Lighting;                                                      \
                                        else                                                                    \
                                            Winter_Lighting

#define Shady_Spring_Lighting                 if (season_morning(SPRING_MORNING)) then                                \
                                            set_light_level((game_time_hour - SPRING_MORNING) + DUSK_LIGHT + night_vision_goggles);    \
                                        else if (season_day(SPRING_MORNING,SPRING_EVENING)) then                \
                                            set_light_level(SHADY_LIGHTING + night_vision_goggles);                                               \
                                        else if (season_evening(SPRING_EVENING)) then                           \
                                            set_light_level(SHADY_LIGHTING - (game_time_hour - SPRING_EVENING) + night_vision_goggles);  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Shady_Summer_Lighting                 if (season_morning(SUMMER_MORNING)) then                                \
                                            set_light_level((game_time_hour - SUMMER_MORNING) + DUSK_LIGHT + night_vision_goggles);    \
                                        else if (season_day(SUMMER_MORNING,SUMMER_EVENING)) then                \
                                            set_light_level(SHADY_LIGHTING + night_vision_goggles);                                               \
                                        else if (season_evening(SUMMER_EVENING)) then                           \
                                            set_light_level(SHADY_LIGHTING - (game_time_hour - SUMMER_EVENING) + night_vision_goggles);  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Shady_Fall_Lighting                   if (season_morning(FALL_MORNING)) then                                  \
                                            set_light_level((game_time_hour - FALL_MORNING) + DUSK_LIGHT + night_vision_goggles);      \
                                        else if (season_day(FALL_MORNING,FALL_EVENING)) then                    \
                                            set_light_level(SHADY_LIGHTING + night_vision_goggles);                                               \
                                        else if (season_evening(FALL_EVENING)) then                             \
                                            set_light_level(SHADY_LIGHTING - (game_time_hour - FALL_EVENING) + night_vision_goggles);    \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Shady_Winter_Lighting                 if (season_morning(WINTER_MORNING)) then                                \
                                            set_light_level((game_time_hour - WINTER_MORNING) + DUSK_LIGHT + night_vision_goggles);    \
                                        else if (season_day(WINTER_MORNING,WINTER_EVENING)) then                \
                                            set_light_level(SHADY_LIGHTING + night_vision_goggles);                                               \
                                        else if (season_evening(WINTER_EVENING)) then                           \
                                            set_light_level(SHADY_LIGHTING - (game_time_hour - WINTER_EVENING) + night_vision_goggles);  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Shady_Lighting                   if ((get_month >= 3) and (get_month < 5)) then                          \
                                        Shady_Spring_Lighting;                                                    \
                                        else if ((get_month >= 5) and (get_month < 9)) then                     \
                                        Shady_Summer_Lighting;                                                    \
                                        else if ((get_month >= 9) and (get_month < 11)) then                    \
                                        Shady_Fall_Lighting;                                                      \
                                        else                                                                    \
                                        Shady_Winter_Lighting

#define Darkness                        set_light_level(DUSK_LIGHT + night_vision_goggles)

#define Cavern_Lighting                 set_light_level(CAVERN_LIGHT + night_vision_goggles)

#define Full_Light                      set_light_level(BRIGHT_LIGHT)

#define Tibbets_Lighting                set_light_level(TIBBETS_LIGHT + night_vision_goggles)

#define Indoor_Lighting                 set_light_level(INDOOR_LIGHT + night_vision_goggles)

#define Basement_Lighting               set_light_level(BASEMENT_LIGHT + night_vision_goggles)

#define Military_Base_Lighting          set_light_level(MILITARY_BASE_LIGHTING + night_vision_goggles)

#define Space_Center_Lighting          if (global_var(GVAR_QUEST_15_RESTORE_OC_POWER) == 2) then                   \
                                        set_light_level(SPACE_CENTER_REPAIR_LIGHT + night_vision_goggles);                   \
                                        else                   \
                                        set_light_level(SPACE_CENTER_BROKEN_LIGHT + night_vision_goggles)

#define Scum_Pits_Lighting              set_light_level(SCUM_PITS_LIGHT + night_vision_goggles)

#define set_cur_exit                    wm_area_set_pos(AREA_RND_MOUNTAIN,worldmap_xpos,worldmap_ypos)

#define night_vision_goggles            ((dude_item_count(PID_NIGHT_VISION_GOGGLES) > 0) * 10)

// Vehicle Information
//        City Vehicle is At                Tile Num For Vehicle

// Hoover Dam

#define MOTORCYCLE_HOOVER_DAM_HEX                      (30906)
#define DUNE_BUGGY_HOOVER_DAM_HEX                      (31711)
#define COP_CAR_HOOVER_DAM_HEX                      (30529)
#define SEMI_TRUCK_HOOVER_DAM_HEX                      (32302)
#define CAR_HOOVER_DAM_HEX                      (33306)
#define BICYCLE_HOOVER_DAM_HEX                      (29525)

// Dogtown

#define COP_CAR_UNCLAIMED_HEX                   (8930)         // When you don't have the cop car

#define MOTORCYCLE_DOGTOWN_HEX                      (14115)
#define DUNE_BUGGY_DOGTOWN_HEX                      (8901)
#define COP_CAR_DOGTOWN_HEX                      (11302)
#define SEMI_TRUCK_DOGTOWN_HEX                      (12713)
#define CAR_DOGTOWN_HEX                      (9306)
#define BICYCLE_DOGTOWN_HEX                      (14303)

// The Reservation

#define MOTORCYCLE_UNCLAIMED_HEX                   (23067)         // When you don't have the motorcycle

#define MOTORCYCLE_THE_RESERVATION_HEX                      (25504)
#define DUNE_BUGGY_THE_RESERVATION_HEX                      (24142)
#define COP_CAR_THE_RESERVATION_HEX                      (25327)
#define SEMI_TRUCK_THE_RESERVATION_HEX                      (24904)
#define CAR_THE_RESERVATION_HEX                      (24533)
#define BICYCLE_THE_RESERVATION_HEX                      (23737)

// Tibbets

#define MOTORCYCLE_TIBBETS_HEX                      (19523)
#define DUNE_BUGGY_TIBBETS_HEX                      (23928)
#define COP_CAR_TIBBETS_HEX                      (25522)
#define SEMI_TRUCK_TIBBETS_HEX                      (18722)
#define CAR_TIBBETS_HEX                      (24115)
#define BICYCLE_TIBBETS_HEX                      (18312)

// Maxson Bunker

#define MOTORCYCLE_MAXSON_BUNKER_HEX                      (22524)
#define DUNE_BUGGY_MAXSON_BUNKER_HEX                      (21920)
#define COP_CAR_MAXSON_BUNKER_HEX                      (25501)
#define SEMI_TRUCK_MAXSON_BUNKER_HEX                      (22311)
#define CAR_MAXSON_BUNKER_HEX                      (26104)
#define BICYCLE_MAXSON_BUNKER_HEX                      (24311)

// Ouroboros

#define SEMI_TRUCK_UNCLAIMED_HEX                   (27116)         // When you don't have the semi-truck

#define MOTORCYCLE_OUROBOROS_HEX                      (19086)
#define DUNE_BUGGY_OUROBOROS_HEX                      (17300)
#define COP_CAR_OUROBOROS_HEX                      (17300)
#define SEMI_TRUCK_OUROBOROS_HEX                      (17300)
#define CAR_OUROBOROS_HEX                      (17300)
#define BICYCLE_OUROBOROS_HEX                      (17300)

// Bloomfield

#define DUNE_BUGGY_UNCLAIMED_HEX                   (16726)         // When you don't have the dune buggy

#define MOTORCYCLE_BLOOMFIELD_HEX                      (33918)
#define DUNE_BUGGY_BLOOMFIELD_HEX                      (34109)
#define COP_CAR_BLOOMFIELD_HEX                      (35912)
#define SEMI_TRUCK_BLOOMFIELD_HEX                      (31901)
#define CAR_BLOOMFIELD_HEX                      (33501)
#define BICYCLE_BLOOMFIELD_HEX                      (34716)

// Boulder Dome

#define MOTORCYCLE_BOULDER_DOME_HEX                      (20633)
#define DUNE_BUGGY_BOULDER_DOME_HEX                      (14427)
#define COP_CAR_BOULDER_DOME_HEX                      (19632)
#define SEMI_TRUCK_BOULDER_DOME_HEX                      (18627)
#define CAR_BOULDER_DOME_HEX                      (16032)
#define BICYCLE_BOULDER_DOME_HEX                      (15229)

// Special Encounter Car Mart
#define CAR_UNCLAIMED_HEX                   (24701)         // When you don't have the car

#define MOTORCYCLE_CAR_MART_HEX                      (21333)
#define DUNE_BUGGY_CAR_MART_HEX                      (23138)
#define COP_CAR_CAR_MART_HEX                      (23946)
#define SEMI_TRUCK_CAR_MART_HEX                      (21492)
#define CAR_CAR_MART_HEX                      (24701)
#define BICYCLE_CAR_MART_HEX                      (24737)

// Circle Junction

#define MOTORCYCLE_CIRCLE_JUNCTION_HEX                      (23964)
#define DUNE_BUGGY_CIRCLE_JUNCTION_HEX                      (22571)
#define COP_CAR_CIRCLE_JUNCTION_HEX                      (23376)
#define SEMI_TRUCK_CIRCLE_JUNCTION_HEX                      (23362)
#define CAR_CIRCLE_JUNCTION_HEX                      (25169)
#define BICYCLE_CIRCLE_JUNCTION_HEX                      (24580)

// Fort Abandon

#define MOTORCYCLE_FORT_ABANDON_HEX                      (25744)
#define DUNE_BUGGY_FORT_ABANDON_HEX                      (28161)
#define COP_CAR_FORT_ABANDON_HEX                      (27356)
#define SEMI_TRUCK_FORT_ABANDON_HEX                      (29351)
#define CAR_FORT_ABANDON_HEX                      (26948)
#define BICYCLE_FORT_ABANDON_HEX                      (25548)

// Blackfoot

#define MOTORCYCLE_BLACKFOOT_HEX                      (29305)
#define DUNE_BUGGY_BLACKFOOT_HEX                      (28499)
#define COP_CAR_BLACKFOOT_HEX                      (28727)
#define SEMI_TRUCK_BLACKFOOT_HEX                      (28911)
#define CAR_BLACKFOOT_HEX                      (28918)
#define BICYCLE_BLACKFOOT_HEX                      (27720)

// Twin Mothers
// Ouroboros
// Burham Springs

// Mesa Verde

#define MOTORCYCLE_MESA_VERDE_CANYON_ENTRANCE_HEX                      (20711)
#define DUNE_BUGGY_MESA_VERDE_CANYON_ENTRANCE_HEX                      (24693)
#define COP_CAR_MESA_VERDE_CANYON_ENTRANCE_HEX                      (22885)
#define SEMI_TRUCK_MESA_VERDE_CANYON_ENTRANCE_HEX                      (22908)
#define CAR_MESA_VERDE_CANYON_ENTRANCE_HEX                      (20716)
#define BICYCLE_MESA_VERDE_CANYON_ENTRANCE_HEX                      (20897)

// The Nursery

#define MOTORCYCLE_THE_NURSERY_HEX                      (28097)
#define DUNE_BUGGY_THE_NURSERY_HEX                      (24726)
#define COP_CAR_THE_NURSERY_HEX                      (28905)
#define SEMI_TRUCK_THE_NURSERY_HEX                      (25117)
#define CAR_THE_NURSERY_HEX                      (27487)
#define BICYCLE_THE_NURSERY_HEX                      (25929)

// The Grand Canyon

#define BICYCLE_UNCLAIMED_HEX                       (25352)

#define MOTORCYCLE_THE_GRAND_CANYON_HEX                      (35084)
#define DUNE_BUGGY_THE_GRAND_CANYON_HEX                      (33886)
#define COP_CAR_THE_GRAND_CANYON_HEX                      (34891)
#define SEMI_TRUCK_THE_GRAND_CANYON_HEX                      (33496)
#define CAR_THE_GRAND_CANYON_HEX                      (35496)
#define BICYCLE_THE_GRAND_CANYON_HEX                      (36089)

// Jericho

#define MOTORCYCLE_JERICHO_HEX                      (20429)
#define DUNE_BUGGY_JERICHO_HEX                      (14225)
#define COP_CAR_JERICHO_HEX                      (14233)
#define SEMI_TRUCK_JERICHO_HEX                      (19428)
#define CAR_JERICHO_HEX                      (15037)
#define BICYCLE_JERICHO_HEX                      (20033)

// New Canaan
// Hangdogs

// Vehicle Abandoned / Outta Gas

#define MOTORCYCLE_ABANDONED_HEX                      (18493)
#define DUNE_BUGGY_ABANDONED_HEX                      (18503)
#define COP_CAR_ABANDONED_HEX                      (20110)
#define SEMI_TRUCK_ABANDONED_HEX                      (21093)
#define CAR_ABANDONED_HEX                      (21704)
#define BICYCLE_ABANDONED_HEX                      (20298)

// The Crater

#define MOTORCYCLE_THE_CRATER_HEX                      (21324)
#define DUNE_BUGGY_THE_CRATER_HEX                      (25131)
#define COP_CAR_THE_CRATER_HEX                      (26320)
#define SEMI_TRUCK_THE_CRATER_HEX                      (24716)
#define CAR_THE_CRATER_HEX                      (21533)
#define BICYCLE_THE_CRATER_HEX                      (21727)

// Moletown

#define MOTORCYCLE_MOLETOWN_HEX                      (25124)
#define DUNE_BUGGY_MOLETOWN_HEX                      (27496)
#define COP_CAR_MOLETOWN_HEX                      (24124)
#define SEMI_TRUCK_MOLETOWN_HEX                      (25710)
#define CAR_MOLETOWN_HEX                      (24730)
#define BICYCLE_MOLETOWN_HEX                      (26901)


// Special Encounter Thunderbird

#define MOTORCYCLE_THUNDERBIRD_HEX                      (20135)
#define DUNE_BUGGY_THUNDERBIRD_HEX                      (19130)
#define COP_CAR_THUNDERBIRD_HEX                      (23529)
#define SEMI_TRUCK_THUNDERBIRD_HEX                      (17724)
#define CAR_THUNDERBIRD_HEX                      (23919)
#define BICYCLE_THUNDERBIRD_HEX                      (21742)

// Special Encounter Pulowskis

#define MOTORCYCLE_PULOWSKIS_HEX                      (20922)
#define DUNE_BUGGY_PULOWSKIS_HEX                      (18712)
#define COP_CAR_PULOWSKIS_HEX                      (18719)
#define SEMI_TRUCK_PULOWSKIS_HEX                      (20324)
#define CAR_PULOWSKIS_HEX                      (19503)
#define BICYCLE_PULOWSKIS_HEX                      (19515)

// Special Encounter Tentacles

#define MOTORCYCLE_TENTACLES_HEX                      (17479)
#define DUNE_BUGGY_TENTACLES_HEX                      (18891)
#define COP_CAR_TENTACLES_HEX                      (23894)
#define SEMI_TRUCK_TENTACLES_HEX                      (22489)
#define CAR_TENTACLES_HEX                      (20094)
#define BICYCLE_TENTACLES_HEX                      (18883)

// Special Encounter The Lamp

#define MOTORCYCLE_THE_LAMP_HEX                      (24325)
#define DUNE_BUGGY_THE_LAMP_HEX                      (20721)
#define COP_CAR_THE_LAMP_HEX                      (21528)
#define SEMI_TRUCK_THE_LAMP_HEX                      (19320)
#define CAR_THE_LAMP_HEX                      (24319)
#define BICYCLE_THE_LAMP_HEX                      (21922)

// Fort Desolation

#define MOTORCYCLE_FORT_DESOLATION_HEX                      (32114)
#define DUNE_BUGGY_FORT_DESOLATION_HEX                      (32690)
#define COP_CAR_FORT_DESOLATION_HEX                      (32922)
#define SEMI_TRUCK_FORT_DESOLATION_HEX                      (34520)
#define CAR_FORT_DESOLATION_HEX                      (32930)
#define BICYCLE_FORT_DESOLATION_HEX                      (32301)

// Special Encounter Guardian + Redshirts

#define MOTORCYCLE_GUARDIAN_REDSHIRTS_HEX                      (18883)
#define DUNE_BUGGY_GUARDIAN_REDSHIRTS_HEX                      (16511)
#define COP_CAR_GUARDIAN_REDSHIRTS_HEX                      (15106)
#define SEMI_TRUCK_GUARDIAN_REDSHIRTS_HEX                      (17078)
#define CAR_GUARDIAN_REDSHIRTS_HEX                      (17714)
#define BICYCLE_GUARDIAN_REDSHIRTS_HEX                      (19890)

// Special Encounter Camp Site

#define MOTORCYCLE_CAMP_SITE_HEX                      (16873)
#define DUNE_BUGGY_CAMP_SITE_HEX                      (18303)
#define COP_CAR_CAMP_SITE_HEX                      (20275)
#define SEMI_TRUCK_CAMP_SITE_HEX                      (17896)
#define CAR_CAMP_SITE_HEX                      (21681)
#define BICYCLE_CAMP_SITE_HEX                      (20486)

// Special Encounter Library

#define MOTORCYCLE_LIBRARY_HEX                      (24515)
#define DUNE_BUGGY_LIBRARY_HEX                      (25695)
#define COP_CAR_LIBRARY_HEX                      (26901)
#define SEMI_TRUCK_LIBRARY_HEX                      (26717)
#define CAR_LIBRARY_HEX                      (23311)
#define BICYCLE_LIBRARY_HEX                      (26707)

// Landing Site

#define MOTORCYCLE_LANDING_HEX                      (22154)
#define DUNE_BUGGY_LANDING_HEX                      (21550)
#define COP_CAR_LANDING_HEX                      (26752)
#define SEMI_TRUCK_LANDING_HEX                      (25346)
#define CAR_LANDING_HEX                      (20542)
#define BICYCLE_LANDING_HEX                      (25353)

// Special Encounter Cranium Rats
// Special Encounter Carib

#define MOTORCYCLE_CARIB_HEX                      (20521)
#define DUNE_BUGGY_CARIB_HEX                      (19308)
#define COP_CAR_CARIB_HEX                      (19916)
#define SEMI_TRUCK_CARIB_HEX                      (22313)
#define CAR_CARIB_HEX                      (22125)
#define BICYCLE_CARIB_HEX                      (21720)

// VACCS

#define MOTORCYCLE_VACCS_HEX                      (28505)
#define DUNE_BUGGY_VACCS_HEX                      (25703)
#define COP_CAR_VACCS_HEX                      (25496)
#define SEMI_TRUCK_VACCS_HEX                      (27302)
#define CAR_VACCS_HEX                      (27709)
#define BICYCLE_VACCS_HEX                      (26308)

// Special Encounter The Postman

#define MOTORCYCLE_THE_POSTMAN_HEX                      (21487)
#define DUNE_BUGGY_THE_POSTMAN_HEX                      (21682)
#define COP_CAR_THE_POSTMAN_HEX                      (20878)
#define SEMI_TRUCK_THE_POSTMAN_HEX                      (20887)
#define CAR_THE_POSTMAN_HEX                      (19473)
#define BICYCLE_THE_POSTMAN_HEX                      (19479)

// Special Pet Cemetery

#define MOTORCYCLE_PET_CEMETERY_HEX                      (29493)
#define DUNE_BUGGY_PET_CEMETERY_HEX                      (28907)
#define COP_CAR_PET_CEMETERY_HEX                      (26687)
#define SEMI_TRUCK_PET_CEMETERY_HEX                      (26707)
#define CAR_PET_CEMETERY_HEX                      (26115)
#define BICYCLE_PET_CEMETERY_HEX                      (29095)

// Circle of Steel

#define MOTORCYCLE_COS_HEX                      (21374)
#define DUNE_BUGGY_COS_HEX                      (24551)
#define COP_CAR_COS_HEX                      (25941)
#define SEMI_TRUCK_COS_HEX                      (20568)
#define CAR_COS_HEX                      (25733)
#define BICYCLE_COS_HEX                      (22177)

// Scaven Picker Camp

#define MOTORCYCLE_SCAVEN_HEX                      (26518)
#define DUNE_BUGGY_SCAVEN_HEX                      (26693)
#define COP_CAR_SCAVEN_HEX                      (27499)
#define SEMI_TRUCK_SCAVEN_HEX                      (26100)
#define CAR_SCAVEN_HEX                      (27322)
#define BICYCLE_SCAVEN_HEX                      (27717)

// Special Casino

#define MOTORCYCLE_CASINO_HEX                      (29311)
#define DUNE_BUGGY_CASINO_HEX                      (28704)
#define COP_CAR_CASINO_HEX                      (28940)
#define SEMI_TRUCK_CASINO_HEX                      (30905)
#define CAR_CASINO_HEX                      (28331)
#define BICYCLE_CASINO_HEX                      (28525)

// Special Eddie

#define MOTORCYCLE_EDDIE_HEX                      (29700)
#define DUNE_BUGGY_EDDIE_HEX                      (30893)
#define COP_CAR_EDDIE_HEX                      (28920)
#define SEMI_TRUCK_EDDIE_HEX                      (31316)
#define CAR_EDDIE_HEX                      (30122)
#define BICYCLE_EDDIE_HEX                      (29905)

// Tibbets Dead

#define MOTORCYCLE_TIBBETS_DEAD_HEX                      (26091)
#define DUNE_BUGGY_TIBBETS_DEAD_HEX                      (25919)
#define COP_CAR_TIBBETS_DEAD_HEX                      (25314)
#define SEMI_TRUCK_TIBBETS_DEAD_HEX                      (23916)
#define CAR_TIBBETS_DEAD_HEX                      (24688)
#define BICYCLE_TIBBETS_DEAD_HEX                      (18312)

// Slave Run
#define CAR_SLAVE_RUN_HEX               (26514)

// Random

#define CAR_RANDOM_DESERT_HEX               (20106)
#define CAR_RANDOM_COAST_HEX                (20106)
#define CAR_RANDOM_MOUNTAIN_HEX             (18909)

#define CAR_RND_DESERT1_HEX                 (19096)
#define CAR_RND_DESERT2_HEX                 (19094)
#define CAR_RND_DESERT3_HEX                 (18894)
#define CAR_RND_DESERT4_HEX                 (19718)
#define CAR_RND_DESERT5_HEX                 (24112)
#define CAR_RND_DESERT6_HEX                 (18914)
#define CAR_RND_DESERT7_HEX                 (24525)
#define CAR_RND_DESERT8_HEX                 (17890)
#define CAR_RND_DESERT9_HEX                 (22880)
#define CAR_RND_DESERT10_HEX                (22880)
#define CAR_RND_DESERT11_HEX                (20692)
#define CAR_RND_DESERT12_HEX                (21308)
#define CAR_RND_DESERT13_HEX                (17261)

#define CAR_RND_MOUNTAIN1_HEX               (18881)
#define CAR_RND_MOUNTAIN2_HEX               (18276)
#define CAR_RND_MOUNTAIN3_HEX               (19478)
#define CAR_RND_MOUNTAIN4_HEX               (19099)
#define CAR_RND_MOUNTAIN5_HEX               (20877)
#define CAR_RND_MOUNTAIN6_HEX               (20073)

#define CAR_RND_CAVE1_HEX                   (26508)
#define CAR_RND_CAVE2_HEX                   (24706)
#define CAR_RND_CAVE3_HEX                   (24915)
#define CAR_RND_CAVE4_HEX                   (27512)
#define CAR_RND_CAVE5_HEX                   (26292)
#define CAR_RND_CAVE6_HEX                   (21681)
#define CAR_RND_CAVE7_HEX                   (19078)

#define CAR_RND_CITY1_HEX                   (12693)
#define CAR_RND_CITY2_HEX                   (9898)
#define CAR_RND_CITY3_HEX                   (23542)
#define CAR_RND_CITY4_HEX                   (28089)
#define CAR_RND_CITY5_HEX                   (20464)
#define CAR_RND_CITY6_HEX                   (29496)
#define CAR_RND_CITY7_HEX                   (19535)
#define CAR_RND_CITY8_HEX                   (21702)
#define CAR_RND_CITY9_HEX                   (19510)

#define CAR_RND_COAST1_HEX                  (18086)
#define CAR_RND_COAST2_HEX                  (19089)
#define CAR_RND_COAST3_HEX                  (19279)
#define CAR_RND_COAST4_HEX                  (19278)
#define CAR_RND_COAST5_HEX                  (23500)
#define CAR_RND_COAST6_HEX                  (22291)
#define CAR_RND_COAST7_HEX                  (16518)
#define CAR_RND_COAST8_HEX                  (23718)
#define CAR_RND_COAST9_HEX                  (21107)
#define CAR_RND_COAST10_HEX                 (17919)
#define CAR_RND_COAST11_HEX                 (20079)
#define CAR_RND_COAST12_HEX                 (25515)

#define CAR_GAMMOVIE_HEX                    (25724)

//        City Vehicle is At               Elevation For Vehicle
// 0 by default, only define if non-0


#endif // UPDATMAP_H
