/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef MAPS_H
#define MAPS_H

/*****************************************************************
   Filename: Maps.h

   Purpose: This file is used to store the defines pertaining
            to the maps. All defines from define.h have been
            placed in here for ease of reading and finding
            the the proper defines.

   Contents: The file is broken down in the following manner:
            I.      Map name Defines.
            II.     Map Entrance Points
            III.    Elevator Defines
            IV.     Random Encounter Defines
*****************************************************************/

/*****************************************************************
********************       Area Names       ***********************
*****************************************************************/

#define AREA_TIBBETS                 (0)
#define AREA_BOULDER_DOME                    (1)
#define AREA_DOGTOWN                (2)
#define AREA_CIRCLE_JUNCTION                  (3)
#define AREA_FORT_ABANDON             (4)
#define AREA_BLACKFOOT                  (5)
#define AREA_MESA_VERDE           (6)
#define AREA_TWIN_MOTHERS               (7)
#define AREA_BROTHERHOOD_OF_STEEL       (8)
#define AREA_HOOVER_DAM               (9)
#define AREA_OUROBOROS                    (10)
#define AREA_THE_RESERVATION               (11)
#define AREA_BURHAM_SPRINGS          (12)
#define AREA_THE_NURSERY                (13)
#define AREA_BLOOMFIELD          (14)
#define AREA_THE_GRAND_CANYON                (15)
#define AREA_JERICHO            (16)
#define AREA_NEW_CANAAN                  (17)
#define AREA_HANGDOGS        (18)
#define AREA_BLOOMFIELD_NUKED                    (19)
#define AREA_MOTORCYCLE_ABANDONED             (20)
#define AREA_VEHICLE_OUTTA_GAS          (21)
#define AREA_THE_CRATER       (22)
#define AREA_DUNE_BUGGY_ABANDONED    (23)
#define AREA_SLAVE_RUN          (24)
#define AREA_MOLETOWN                (25)
#define AREA_RND_DESERT             (26)
#define AREA_RND_MOUNTAIN           (27)
#define AREA_RND_CITY               (28)
#define AREA_RND_COAST              (29)
#define AREA_BOMB_001               (30)
#define AREA_COP_CAR_ABANDONED      (31)
#define AREA_BICYCLE_ABANDONED   (32)
#define AREA_SPECIAL_RND_GROVE        (33)
#define AREA_SPECIAL_RND_PULOWSKIS    (34)
#define AREA_SPECIAL_RND_TENTACLES   (35)
#define AREA_BLACKFOOT_NUKED     (36)
#define AREA_SPECIAL_RND_LAMP       (37)
#define AREA_SPECIAL_RND_CAR_MART      (38)
#define AREA_FORT_DESOLATION      (39)
#define AREA_SPECIAL_RND_GUARDIAN   (40)
#define AREA_SPECIAL_RND_CASINO      (41)
#define AREA_HOOVER_DAM_NUKED     (42)
#define AREA_LANDING_SITE    (43)
#define AREA_SEMI_TRUCK_ABANDONED      (44)
#define AREA_SPECIAL_RND_CRANIUM_RATS         (45)
#define AREA_SPECIAL_RND_CARIB         (46)
#define AREA_SHADOW_MAPS            (47)
#define AREA_VACCS           (48)
#define AREA_HIGHWAYMAN_ABANDONED           (49)
#define AREA_SPECIAL_RND_POSTMAN           (50)
#define AREA_SPECIAL_RND_PET_CEMETERY           (51)
#define AREA_CIRCLE_OF_STEEL           (52)
#define AREA_SCAVEN_PICKER_CAMP           (53)
#define AREA_NETHER_REALM   (54)
#define AREA_SPECIAL_RND_EDDIE   (55)
#define AREA_TIBBETS_CRATER   (56)
#define AREA_HOOVER_DAM_SHADOW_MAPS   (57)
#define AREA_DOGTOWN_NUKED                (58)
#define AREA_CIRCLE_JUNCTION_NUKED                  (59)
#define AREA_FORT_ABANDON_NUKED             (60)
#define AREA_MESA_VERDE_NUKED           (61)
#define AREA_TWIN_MOTHERS_NUKED               (62)
#define AREA_BROTHERHOOD_OF_STEEL_NUKED       (63)
#define AREA_OUROBOROS_NUKED                    (64)
#define AREA_THE_RESERVATION_NUKED               (65)
#define AREA_BURHAM_SPRINGS_NUKED          (66)
#define AREA_THE_NURSERY_NUKED                (67)
#define AREA_JERICHO_NUKED            (68)
#define AREA_NEW_CANAAN_NUKED                  (69)
#define AREA_BOULDER_DOME_NUKED                    (70)
#define AREA_SPECIAL_RND_VAULT69                    (71)
#define AREA_SPECIAL_RND_CAMP_SITE                    (72)
#define AREA_SPECIAL_RND_THUNDERBIRD                    (73)
#define AREA_MESA_VERDE_SHADOW_MAPS                    (74)

/*****************************************************************
********************       Map Names       ***********************
*****************************************************************/

#define MAP_RND_DESERT_1     (0)
#define MAP_RND_DESERT_2     (1)
#define MAP_RND_DESERT_3     (2)
#define MAP_TIBBETS_CELL_BLOCK_13  (3)
#define MAP_RND_CITY_9    (4)
#define MAP_RND_CITY_10    (5)
#define MAP_TIBBETS_CELL_BLOCK_14     (6)
#define MAP_TIBBETS_CELL_BLOCK_15     (7)
#define MAP_TIBBETS_CELL_BLOCK_16    (8)
#define MAP_TIBBETS_CELL_BLOCK_17      (9)
#define MAP_TIBBETS_CELL_BLOCK_18     (10)
#define MAP_TIBBETS_SECURITY_HUB   (11)
#define MAP_TIBBETS_SERVICE_LEVEL_WEST   (12)
#define MAP_TIBBETS_SERVICE_LEVEL_EAST   (13)
#define MAP_TIBBETS_COURTROOM    (14)
#define MAP_TIBBETS_BREACH_VALKYRIE  (15)
#define MAP_TIBBETS_BREACH   (16)
#define MAP_TIBBETS_CELL_BLOCK_19   (17)
#define MAP_TIBBETS_CELL_BLOCK_20   (18)
#define MAP_TIBBETS_CELL_BLOCK_21  (19)
#define MAP_TIBBETS_CELL_BLOCK_22  (20)
#define MAP_TIBBETS_CELL_BLOCK_23     (21)
#define MAP_TIBBETS_CELL_BLOCK_24  (22)
#define MAP_TIBBETS_CELL_BLOCK_25     (23)
#define MAP_TIBBETS_CELL_BLOCK_26     (24)
#define MAP_TIBBETS_CELL_BLOCK_27     (25)
#define MAP_TIBBETS_CELL_BLOCK_28     (26)
#define MAP_TIBBETS_CELL_BLOCK_29    (27)
#define MAP_TIBBETS_CELL_BLOCK_30     (28)
#define MAP_SPECIAL_RND_CAR_MART      (29)
#define MAP_SPECIAL_RND_CARIB   (30)
#define MAP_BOMBED_OUT_CITY   (31)
#define MAP_VAULT_8   (32)
#define MAP_TIBBETS_MEDICAL_TREATMENT_AREA_LEVEL_1    (33)
#define MAP_TIBBETS_ASYLUM_HOSPITAL  (34)
#define MAP_TIBBETS_ASYLUM_UNDERGROUND_GARAGE   (35)
#define MAP_VACCS_8_ENTRANCE      (36)
#define MAP_VACCS_8     (37)
#define MAP_TIBBETS_MEDICAL_TREATMENT_AREA_LEVEL_2     (38)
#define MAP_TIBBETS_MEDICAL_TREATMENT_AREA_LEVEL_3 (39)
#define MAP_ASYLUM_MOUNTAIN_ENTRANCE_TRAM_STATION      (40)
#define MAP_TIBBETS_MEDICAL_TREATMENT_AREA_TRAM_STATION   (41)
#define MAP_ASYLUM_TRAM_STATION     (42)
#define MAP_DEN_OF_LOST_LUCK     (43)
#define MAP_HOOVER_DAM_MORGUE   (44)
#define MAP_SPECIAL_RND_THUNDERBIRD   (45)
#define MAP_SPECIAL_RND_LAMP     (46)
#define MAP_BICYCLE_DESERT     (47)
#define MAP_SPECIAL_RND_PET_CEMETERY    (48)
#define MAP_SPECIAL_ENCOUNTER_TEMPLE_COAST   (49)
#define MAP_BLOOMFIELD_NUKED   (50)
#define MAP_SPECIAL_ENCOUNTER_TEMPLE (51)
#define MAP_SLAVE_RUN    (52)
#define MAP_VEHICLE_OUTTA_GAS     (53)
#define MAP_SPECIAL_RND_POSTMAN     (54)
#define MAP_SPECIAL_RND_CRANIUM_RATS     (55)
#define MAP_BOS_CLIFF     (56)
#define MAP_MAXSON_BUNKER_DOOR     (57)
#define MAP_MAXSON_BUNKER   (58)
#define MAP_PLACEHOLDER   (59)
#define MAP_CIRCLE_OF_STEEL   (60)
#define MAP_BOS_DEAD    (61)
#define MAP_FORT_ABANDON_COURTYARD  (62)
#define MAP_FORT_ABANDON_ISLE  (63)
#define MAP_FORT_ABANDON_FARM   (64)
#define MAP_FORT_ABANDON_PARKING   (65)
#define MAP_FORT_ABANDON_OIL_REFINERY  (66)
#define MAP_THE_RESERVATION_GATE  (67)
#define MAP_RND_CITY1      (68)
#define MAP_RND_CAVERN0     (69)
#define MAP_RND_CAVERN1     (70)
#define MAP_RND_CAVERN2     (71)
#define MAP_RND_CAVERN3     (72)
#define MAP_RND_CAVERN4     (73)
#define MAP_RND_MOUNTAIN1    (74)
#define MAP_RND_MOUNTAIN2    (75)
#define MAP_RND_COAST1     (76)
#define MAP_RND_COAST2     (77)
#define MAP_THE_RESERVATION_TRADING_POST    (78)
#define MAP_SCAVEN_PICKER_CAMP    (79)
#define MAP_RND_CAVERN5     (80)
#define MAP_RND_DESERT4     (81)
#define MAP_RND_DESERT5     (82)
#define MAP_RND_DESERT6     (83)
#define MAP_RND_DESERT7     (84)
#define MAP_RND_COAST3     (85)
#define MAP_RND_COAST4     (86)
#define MAP_RND_COAST5     (87)
#define MAP_RND_COAST6     (88)
#define MAP_RND_COAST7     (89)
#define MAP_RND_COAST8     (90)
#define MAP_RND_COAST9     (91)
#define MAP_RND_DESERT_14    (92)
#define MAP_HOOVER_DAM_SOUTH_GATE    (93)
#define MAP_BOULDER_DOME_TRAIN_STATION    (94)
#define MAP_DOGTOWN_OLD_CAMP    (95)
#define MAP_CIRCLE_JUNCTION_ROUNDABOUT   (96)
#define MAP_BLACKFOOT_VILLAGE  (97)
#define MAP_MESA_VERDE_CANYON_WEST   (98)
#define MAP_TWIN_MOTHERS_FIELDS  (99)
#define MAP_OUROBOROS_NORTH  (100)
#define MAP_BURHAM_SPRINGS_TOWN_WEST   (101)
#define MAP_NURSERY_SPILLWAY   (102)
#define MAP_BLOOMFIELD_COLLAPSED_PARKING   (103)
#define MAP_JERICHO_TOWN_EAST   (104)
#define MAP_SPECIAL_RND_GUARDIAN_REDSHIRTS  (105)
#define MAP_SPECIAL_RND_LIBRARY   (106)
#define MAP_NEW_CANAAN_OUTSKIRTS   (107)
#define MAP_HANGDOGS_HOME  (108)
#define MAP_PLACEHOLDER2   (109)
#define MAP_RND_COAST_10     (110)
#define MAP_RND_COAST_11     (111)
#define MAP_RND_COAST_12     (112)
#define MAP_RND_DESERT_8     (113)
#define MAP_RND_DESERT_9     (114)
#define MAP_RND_DESERT_10    (115)
#define MAP_RND_DESERT_11    (116)
#define MAP_RND_DESERT_12    (117)
#define MAP_RND_DESERT_13     (118)
#define MAP_BLACKFOOT_NUKED     (119)
#define MAP_THE_CRATER_ENTRANCE     (120)
#define MAP_RND_MOUNTAIN_3    (121)
#define MAP_RND_MOUNTAIN_4    (122)
#define MAP_RND_MOUNTAIN_5    (123)
#define MAP_RND_MOUNTAIN_6    (124)
#define MAP_RND_CITY_2     (125)
#define MAP_COP_CAR_DESERT    (126)
#define MAP_MOLETOWN_ENTRANCE   (127)
#define MAP_BOMB_001      (128)
#define MAP_HIGHWAYMAN_DESERT   (129)
#define MAP_SPECIAL_RND_PULOWSKIS   (130)
#define MAP_NETHER_REALM   (131)
#define MAP_SPECIAL_RND_COPS   (132)
#define MAP_LANDING_SITE     (133)
#define MAP_BOULDER_DOME_RUINS_SOUTH   (134)
#define MAP_HOOVER_DAM_NUKED    (135)
#define MAP_THE_CRATER_TUNNEL    (136)
#define MAP_GRAND_CANYON_SOUTH   (137)
#define MAP_FORT_ABANDON_WEST   (138)
#define MAP_RESERVATION_TOWN_SOUTH   (139)
#define MAP_RESERVATION_TOWN_NORTH   (140)
#define MAP_RND_CITY_3     (141)
#define MAP_RND_CITY_4     (142)
#define MAP_RND_CITY_5     (143)
#define MAP_RND_CITY_6     (144)
#define MAP_RND_CITY_7     (145)
#define MAP_RND_CITY_8     (146)
#define MAP_RESERVATION_SUB_LEVELS     (147)
#define MAP_HOOVER_DAM_RIM     (148)
#define MAP_IN_GAME_MOVIE1    (149)
#define MAP_DOGTOWN_UNION_STATION (150)
#define MAP_DOGTOWN_THE_BOX (151)
#define MAP_KARLSTOWN (152)
#define MAP_MESA_VERDE_CANYON_ENTRANCE (153)
#define MAP_DOGTOWN_THE_BOX_GROUND_LEVEL (154)
#define MAP_DOGTOWN_THE_BOX_LEVELS_234 (155)
#define MAP_PLACEHOLDER4    (156)
#define MAP_DOGTOWN_SKYSCRAPER (157)
#define MAP_DOGTOWN_NEW_CAMP_EAST_SKYSCRAPER_EXTERIOR (158)
#define MAP_DOGTOWN_NEW_CAMP_WEST_SKYSCRAPER_EXTERIOR (159)
#define MAP_DOGTOWN_NEW_CAMP_EAST_SKYSCRAPER_INTERIOR (160)
#define MAP_DOGTOWN_NEW_CAMP_WEST_SKYSCRAPER_INTERIOR (161)
#define MAP_HANGDOGS_NEW_VILLAGE (162)
#define MAP_MESA_VERDE_HOUNDS_CAMP (163)
#define MAP_MESA_VERDE_CANYON_CENTER (164)
#define MAP_MESA_VERDE_VILLAGE_EAST  (165)
#define MAP_MESA_VERDE_BRIDGE (166)
#define MAP_MESA_VERDE_VILLAGE_WEST (167)
#define MAP_MESA_VERDE_VILLAGE_NORTH (168)
#define MAP_MESA_VERDE_BRIDGE_NORTH (169)
#define MAP_MESA_VERDE_TOP (170)
#define MAP_HOOVER_DAM_NCR_ARMY_HQ (171)
#define MAP_DOGTOWN_BOMBAY_JACK_CANYON (172)
#define MAP_MESA_VERDE_CANYON_SOUTH (173)
#define MAP_MESA_VERDE_CANYON_SOUTH_CAVE (174)
#define MAP_SPECIAL_ROBOT_WARDEN (175)
#define MAP_DOGTOWN_NUKED    (176)
#define MAP_PLACEHOLDER3 (177)
#define MAP_HANGDOGS_NEW_VILLAGE_EAST (178)
#define MAP_HANGDOGS_NEW_VILLAGE_WEST (179)
#define MAP_HANGDOGS_NEW_VILLAGE_NORTH (180)
#define MAP_HANGDOGS_NEW_VILLAGE_SOUTH (181)
#define MAP_BLACKFOOT_MINE_SMALL_ENTRANCE (182)
#define MAP_BLACKFOOT_MINE_SMALL (183)
#define MAP_BLACKFOOT_MINE_BIG_ENTRANCE (184)
#define MAP_BLACKFOOT_MINE_BIG (185)
#define MAP_BLACKFOOT_SPELUNKING_CAVE (186)
#define MAP_BLACKFOOT_SPELUNKING_TUNNELS (187)
#define MAP_DOGTOWN_THE_BOX_SEWERS (188)
#define MAP_DOGTOWN_CAESARS_LEGION (189)
#define MAP_DOGTOWN_CAESARS_LEGION_BASEMENT (190)
#define MAP_DOGTOWN_RIVAL_CAMP (191)
#define MAP_DOGTOWN_BREWERY (192)
#define MAP_DOGTOWN_NEW_CAMP_SOUTH (193)
#define MAP_DOGTOWN_POLICE_HQ    (194)
#define MAP_DOGTOWN_QUARANTINE_AREA (195)
#define MAP_DOGTOWN_QUARANTINE_CENTER (196)
#define MAP_DOGTOWN_HOSPITAL (197)
#define MAP_RESERVATION_HANGAR_A (198)
#define MAP_RESERVATION_HANGAR_B (199)
#define MAP_GRAND_CANYON_NORTH_LODGE (200)
#define MAP_GRAND_CANYON_MACHINERY (201)
#define MAP_GRAND_CANYON_DEATHCLAW_UP (202)
#define MAP_GRAND_CANYON_DEATHCLAW_WEST (203)
#define MAP_GRAND_CANYON_DEATHCLAW_EAST (204)
#define MAP_GRAND_CANYON_DEATHCLAW_EXIT (205)
#define MAP_GRAND_CANYON_GHOST_TOWN (206)
#define MAP_JERICHO_MORMONS (207)
#define MAP_JERICHO_TOWN_WEST (208)
#define MAP_JERICHO_TRAIN_STATION (209)
#define MAP_BLACKFOOT_CELLAR (210)
#define MAP_DOGTOWN_PRIVATE_SHELTER_EXTERIOR (211)
#define MAP_DOGTOWN_PRIVATE_SHELTER_INTERIOR (212)
#define MAP_MOLETOWN_WEST_TUNNELS (213)
#define MAP_MOLETOWN_EAST_TUNNELS (214)
#define MAP_BOULDER_DOME_LEVEL_1 (215)
#define MAP_BOULDER_DOME_LEVEL_2 (216)
#define MAP_BOULDER_DOME_TUNNELS (217)
#define MAP_BOULDER_DOME_ZAX (218)
#define MAP_BOULDER_DOME_SECRET_TUNNEL (219)
#define MAP_JACKALS_CAMP (220)
#define MAP_BOULDER_DOME_WATER_PUMP (221)
#define MAP_BAGGERS_CAMP (222)
#define MAP_TIBBETS_WASTE_DISPOSAL (223)
#define MAP_BOULDER_DOME_SECRET_TUNNELS_ENTRANCE (224)
#define MAP_DEAD_GHOUL_GRAVEYARD (224)
#define MAP_KARLTOWN_MARKET (225)
#define MAP_KARLTOWN_GATE (226)
#define MAP_TIBBETS_CHEMICAL_TREATMENT (227)
#define MAP_TIBBETS_MECHANICS_AND_ROBOT_MAINTENANCE_BAY_AND_ARSENAL (228)
#define MAP_TIBBETS_SERVICE_AND_VEHICLE_DEPOT_AREAS_LEVEL_1 (229)
#define MAP_TIBBETS_SERVICE_AND_VEHICLE_DEPOT_AREAS_LEVEL_2 (230)
#define MAP_TIBBETS_SERVICE_AND_VEHICLE_DEPOT_AREAS_LEVEL_3 (231)
#define MAP_TIBBETS_SERVICE_AND_VEHICLE_DEPOT_AREAS_CAFE (232)
#define MAP_NY_EAST (233)
#define MAP_TIBBETS_DEFENSE_TUNNELS (234)
#define MAP_TIBBETS_CRYOGENIC_CELL_BLOCK_0_ODYSSEUS_COMPUTER_CORE (235)
#define MAP_TIBBETS_TRAIN_STATION (236)
#define MAP_TWIN_MOTHERS_VILLAGE (237)
#define MAP_TWIN_MOTHERS_SATELLITE_DISH (238)
#define MAP_TWIN_MOTHERS_MYSTERY_CAVES (239)
#define MAP_TWIN_MOTHERS_FORBIDDEN_LANDS (240)
#define MAP_VAULT_29 (241)
#define MAP_THE_CRATER_LEVELS_1_3 (242)
#define MAP_THE_CRATER_LEVELS_4_6 (243)
#define MAP_THE_CRATER_LEVELS_7_9 (244)
#define MAP_BLACKFOOT_FURNACE_CAVE_ENTRANCE (245)
#define MAP_BLACKFOOT_FURNACE_CAVE (246)
#define MAP_BURHAM_SPRINGS_TOWN_EAST (247)
#define MAP_BURHAM_SPRINGS_MINE (248)
#define MAP_FORT_ABANDON_FARM_UNDERGROUND (249)
#define MAP_OUROBOROS_GATE   (250)
#define MAP_FORT_ABANDON_ISLE_UNDERGROUND (251)
#define MAP_OUROBOROS_JUNKYARD   (252)
#define MAP_OUROBOROS_PYRAMID (253)
#define MAP_OUROBOROS_VILLAGE_EAST (254)
#define MAP_OUROBOROS_VILLAGE_SOUTH (255)
#define MAP_OUROBOROS_VILLAGE_WEST (256)
#define MAP_OUROBOROS_VILLAGE (257)
#define MAP_OUROBOROS_SECRET_TUNNEL (258)
#define MAP_NEW_CANAAN_TRAIN_STATION (259)
#define MAP_TIBBETS_CRATER   (260)
#define MAP_HOOVER_DAM_BASELINE (261)
#define MAP_HOOVER_DAM_SCUM_PITS  (262)
#define MAP_HOOVER_DAM_DOWNTOWN_NORTHEAST  (263)
#define MAP_HOOVER_DAM_DOWNTOWN_SOUTHEAST  (264)
#define MAP_HOOVER_DAM_DOWNTOWN_NORTHWEST  (265)
#define MAP_HOOVER_DAM_DOWNTOWN_SOUTH_WEST_FIELDS (266)
#define MAP_HOOVER_DAM_DOWNTOWN_SOUTH_WEST_FARM (267)
#define MAP_BLOOMFIELD_SPACE_MUSEUM_ENTRANCE (268)
#define MAP_BLOOMFIELD_SPACE_MUSEUM (269)
#define MAP_BLOOMFIELD_CONTROL_CENTER_SOUTH (270)
#define MAP_BLOOMFIELD_CONTROL_CENTER_NORTH  (271)
#define MAP_BLOOMFIELD_CONTROL_CENTER_EAST (272)
#define MAP_BLOOMFIELD_EAST (273)
#define MAP_BLOOMFIELD_FUEL_TANKS     (274)
#define MAP_BLOOMFIELD_LAUNCH_PAD (275)
#define MAP_BLOOMFIELD_BOMB_003 (276)
#define MAP_BLOOMFIELD_SUB_REACTOR (277)
#define MAP_JERICHO_SEWERS (278)
#define MAP_JERICHO_FALLOUT_SHELTER (279)
#define MAP_GRAND_CANYON_MINE_1 (280)
#define MAP_GRAND_CANYON_MINE_2 (281)
#define MAP_GRAND_CANYON_MINE_3 (282)
#define MAP_GRAND_CANYON_URANIUM_MINE_1 (283)
#define MAP_GRAND_CANYON_URANIUM_MINE_2 (284)
#define MAP_GRAND_CANYON_OFFICE_1 (285)
#define MAP_GRAND_CANYON_OFFICE_2 (286)
#define MAP_GRAND_CANYON_OFFICE_3 (287)
#define MAP_GRAND_CANYON_OFFICE_4 (288)
#define MAP_GRAND_CANYON_DOCKS (289)
#define MAP_GRAND_CANYON_GLOWING_SEA (290)
#define MAP_GRAND_CANYON_BOMB_002_EXTERIOR (291)
#define MAP_GRAND_CANYON_BOMB_002_INTERIOR (292)
#define MAP_GRAND_CANYON_MOLDER_FORTESC (293)
#define MAP_GRAND_CANYON_MOLDER_BARLOWS (294)
#define MAP_GRAND_CANYON_MOLDER_LOGANS (295)
#define MAP_GRAND_CANYON_MOLDER (296)
#define MAP_NURSERY_ENTRANCE     (297)
#define MAP_NURSERY_VALLEY_LAKE (298)
#define MAP_NURSERY_VALLEY_GARDENS (299)
#define MAP_NURSERY_FILTRATION_PLANT (300)
#define MAP_NURSERY_FACTORY_EXTERIOR (301)
#define MAP_NURSERY_FACTORY_INTERIOR (302)
#define MAP_NURSERY_CONTROL_FACILITY_REPOSITORY (303)
#define MAP_NURSERY_CONTROL_FACILITY_MAZE (304)
#define MAP_NURSERY_CONTROL_FACILITY_CONTROL_TOWER (305)
#define MAP_NURSERY_CONTROL_FACILITY_HELIPAD (306)
#define MAP_CIRCLE_JUNCTION_WAREHOUSES_SOUTH_EAST (307)
#define MAP_CIRCLE_JUNCTION_WAREHOUSES_SOUTH_WEST (308)
#define MAP_CIRCLE_JUNCTION_BIG_HOUSE (309)
#define MAP_SPECIAL_RND_VAULT69     (310)
#define MAP_NEW_CANAAN_NUKED     (311)
#define MAP_BOULDER_DOME_NUKED    (312)
#define MAP_SPECIAL_RND_CAMP_SITE   (313)
#define MAP_MESA_VERDE_CAVES    (314)
#define MAP_BLOOMFIELD_CONTROL_CENTER (316)
#define MAP_CIRCLE_JUNCTION_NUKED   (317)
#define MAP_FORT_ABANDON_NUKED    (318)
#define MAP_MESA_VERDE_NUKED    (319)
#define MAP_NY_WEST       (320)
#define MAP_SCRAPHEAP       (321)
#define MAP_CRATER_ARCHIVES_LEVEL_1 (322)
#define MAP_CRATER_ARCHIVES_LEVEL_2 (323)
#define MAP_FORT_DESOLATION    (324)
#define MAP_TWIN_MOTHERS_NUKED    (325)
#define MAP_MAXSON_BUNKER_NUKED   (326)
#define MAP_OUROBOROS_NUKED    (327)
#define MAP_RESERVATION_NUKED    (328)
#define MAP_BURHAM_SPRINGS_NUKED    (329)
#define MAP_NURSERY_NUKED     (330)
#define MAP_HOOVER_DAM_CATWALK    (331)
#define MAP_HOOVER_DAM_S1C    (332)
#define MAP_HOOVER_DAM_NCR_ARMY_GYM    (333)
#define MAP_JERICHO_NUKED     (334)
#define MAP_MOTORCYCLE_DESERT  (335)
#define MAP_DUNE_BUGGY_DESERT  (336)
#define MAP_SEMI_TRUCK_DESERT  (337)
#define MAP_JACKALS_CAMP_2 (338)
#define MAP_JACKALS_CAMP_3 (339)
#define MAP_BATTALION_BASE_LEVEL_1_2 (340)
#define MAP_BATTALION_BASE_LEVEL_3_4 (341)
#define MAP_FORT_ABANDON_TOWN (342)
#define MAP_BATTALION_BASE_ENTRANCE (343)
#define MAP_NY_FARM      (344)
#define MAP_NY_LIBRARY_EXTERIOR  (345)
#define MAP_NY_LIBRARY_INTERIOR  (346)
#define MAP_NY_POWERPLANT    (347)
#define MAP_GRAND_CANYON_MINER_TOWN_OLD (348)
#define MAP_JERICHO_SOUTH (349)
#define MAP_BOULDER_DOME_RUINS_NORTH (350)
#define MAP_HOOVER_DAM_NORTH_GATE    (351)
#define MAP_SPECIAL_RND_EDDIE    (352)
#define MAP_KARLTOWN_JAIL (353)
#define MAP_KARLTOWN_FARM (354)
#define MAP_KARLTOWN_FARM_2 (355)
#define MAP_KARLTOWN_GECKOS (356)
#define MAP_KARLTOWN_TOXIC_POND (357)
#define MAP_KARLTOWN_HANGING_BRIDGE (358)
#define MAP_KARLTOWN_CAVE (359)
#define MAP_SALT_LAKE_CITY_SEWERS (360)
#define MAP_VAULT_70 (361)
#define MAP_IN_GAME_MOVIE_0 (362)

/*****************************************************************
********************    Map Entrance Points  *********************
*****************************************************************/

#define override_map_start_hex(x,y,z)   override_map_start(x%200,x/200,y,z)

#define DEN_SLAVE_RUN_SUCCESS       (10)

/*****************************************************************
********************       Elevators       ***********************
*****************************************************************/


/*****************************************************************
********************    Random Encounters  ***********************
*****************************************************************/

/* The following define is to force critter X to face critter Y */
#define Face_Critter(Y,X)           anim(X,ANIMATE_ROTATION,rotation_to_tile(tile_num(X),tile_num(Y)))

/* The following define will set a rotation arc for placement
   of critters. */
#define FixRotationArc(X)           while (X < 0) do begin      \
                                        X += 6;                 \
                                    end                         \
                                    if (X > 5) then             \
                                        X := X%6


/* The following define will give you the inverse (Y) of a
   rotation (X) */
#define InvertRotation(X,Y)         X+=3;                       \
                                    FixRotationArc(X)

// Return the regular area or the nuked version of it based on GVARs
procedure AreaNukeStatus(variable area) begin
   if (global_var(GVAR_ACT) == 3) then begin
      if ((area == AREA_THE_RESERVATION) and (global_var(GVAR_BOMB001_M3_TARGET) == AREA_THE_RESERVATION)) then begin
         return AREA_THE_RESERVATION_NUKED;
      end
      else if ((area == AREA_DOGTOWN) and (global_var(GVAR_BOMB001_M6_TARGET) == AREA_DOGTOWN)) then begin
         return AREA_DOGTOWN_NUKED;
      end
      else if ((area == AREA_BOULDER_DOME) and (global_var(GVAR_BOMB001_M6_TARGET) == AREA_BOULDER_DOME)) then begin
         return AREA_BOULDER_DOME_NUKED;
      end
      else if ((area == AREA_BLACKFOOT) and (global_var(GVAR_BOMB001_M1_TARGET) == AREA_BLACKFOOT)) then begin
         return AREA_BLACKFOOT_NUKED;
      end
      else if ((area == AREA_TWIN_MOTHERS) and (global_var(GVAR_BOMB001_M7_TARGET) == AREA_TWIN_MOTHERS)) then begin
         return AREA_TWIN_MOTHERS_NUKED;
      end
      else if ((area == AREA_OUROBOROS) and (global_var(GVAR_BOMB001_M4_TARGET) == AREA_OUROBOROS)) then begin
         return AREA_OUROBOROS_NUKED;
      end
      else if ((area == AREA_MESA_VERDE) and (global_var(GVAR_BOMB001_M7_TARGET) == AREA_MESA_VERDE)) then begin
         return AREA_MESA_VERDE_NUKED;
      end
      else if ((area == AREA_THE_NURSERY) and (global_var(GVAR_BOMB001_M5_TARGET) == AREA_THE_NURSERY)) then begin
         return AREA_THE_NURSERY_NUKED;
      end
      else if ((area == AREA_BROTHERHOOD_OF_STEEL) and (global_var(GVAR_BOMB001_M8_TARGET) == AREA_BROTHERHOOD_OF_STEEL)) then begin
         return AREA_BROTHERHOOD_OF_STEEL_NUKED;
      end
      else if ((area == AREA_NEW_CANAAN) and (global_var(GVAR_BOMB001_M2_TARGET) == AREA_NEW_CANAAN)) then begin
         return AREA_NEW_CANAAN_NUKED;
      end
      else if ((area == AREA_JERICHO) and (global_var(GVAR_BOMB001_M2_TARGET) == AREA_JERICHO)) then begin
         return AREA_JERICHO_NUKED;
      end
      else if ((area == AREA_BURHAM_SPRINGS) and (global_var(GVAR_BOMB001_M2_TARGET) == AREA_BURHAM_SPRINGS)) then begin
         return AREA_BURHAM_SPRINGS_NUKED;
      end
      else if ((area == AREA_HOOVER_DAM) and (global_var(GVAR_BOMB001_M1_TARGET) == AREA_HOOVER_DAM)) then begin
         return AREA_HOOVER_DAM_NUKED;
      end
      else if ((area == AREA_FORT_ABANDON) and (global_var(GVAR_BOMB001_M8_TARGET) == AREA_FORT_ABANDON)) then begin
         return AREA_FORT_ABANDON_NUKED;
      end
      else if ((area == AREA_BLOOMFIELD) and (global_var(GVAR_BOMB001_M1_TARGET) == AREA_BLOOMFIELD)) then begin
         return AREA_BLOOMFIELD_NUKED;
      end
      else if ((area == AREA_CIRCLE_JUNCTION) and (global_var(GVAR_BOMB001_M8_TARGET) == AREA_CIRCLE_JUNCTION)) then begin
         return AREA_CIRCLE_JUNCTION_NUKED;
      end
      else begin
         return area;
      end
   end
   else begin
      return area;
   end
end


/*****************************************************************
********************    Ambient Tracks  *********************
*****************************************************************/

variable ambient_sfx;

#define AMBIENT_BOMB001                         "bomb001.mp3"
#define AMBIENT_MUTANT_WATERS                   "mutant_waters.mp3"
#define AMBIENT_WIND_IN_THE_GRASS               "wind_in_the_grass.mp3"
#define AMBIENT_WASTELAND                       "wasteland.mp3"
#define AMBIENT_WASTELAND_NIGHT                 "wasteland_night.mp3"
#define AMBIENT_VILLAGE                         "village.mp3"
#define AMBIENT_HIGH_TECH                       "high_tech.mp3"
#define AMBIENT_BEFORE_THE_STORM                "before_the_storm.mp3"
#define AMBIENT_GRAND_CANYON                    "grand_canyon.mp3"
#define AMBIENT_S1C                             "s1c.mp3"
#define AMBIENT_DEN_OF_LOST_LUCK                "den_of_lost_luck.mp3"
#define AMBIENT_POWER_CORE                      "power_core.mp3"
#define AMBIENT_MOUNTAIN_WIND                   "mountain_wind.mp3"
#define AMBIENT_MOUNTAIN_CAVE_WIND              "mountain_cave_wind.mp3"
#define AMBIENT_STRONG_WIND                     "strong_wind.mp3"
#define AMBIENT_MOLECH_TEMPLE                   "molech_temple.mp3"
#define AMBIENT_ABANDONED_WIND                  "abandoned_wind.mp3"
#define AMBIENT_ABANDONED_CRICKETS              "abandoned_crickets.mp3"
#define AMBIENT_SEWERS                          "sewers.mp3"
#define AMBIENT_BURHAM_SPRINGS                  "burham_springs.mp3"
#define AMBIENT_TIBBETS                         "tibbets.mp3"
#define AMBIENT_SLUDGE                          "sludge.mp3"
#define AMBIENT_ASYLUM                          "asylum.mp3"
#define AMBIENT_BLANK                           "blank.mp3"
#define AMBIENT_MIDNIGHT_RUSTLE                 "midnight_rustle.mp3"

procedure AmbientTrack(variable track) begin

   if ((track == AMBIENT_WASTELAND) and night) then begin
      track = AMBIENT_WASTELAND_NIGHT;
   end
   else if ((track == AMBIENT_WIND_IN_THE_GRASS) and night) then begin
      track = AMBIENT_MIDNIGHT_RUSTLE;
   end

   // Should we animate the grass?
   if (
      (track == AMBIENT_WIND_IN_THE_GRASS) or
      (track == AMBIENT_BEFORE_THE_STORM) or
      (track == AMBIENT_GRAND_CANYON) or
      (track == AMBIENT_MOUNTAIN_WIND) or
      (track == AMBIENT_MOUNTAIN_CAVE_WIND) or
      (track == AMBIENT_STRONG_WIND) or
      (track == AMBIENT_ABANDONED_WIND) or
      (track == AMBIENT_MIDNIGHT_RUSTLE)
   ) then begin
      set_global_var(GVAR_ANIMATE_GRASS, 1);
   end
   else begin
      set_global_var(GVAR_ANIMATE_GRASS, 0);
   end

   // Disabled? Keep this below grass code so that the grass gets animated even if the wind is disabled
   if (GetFYConfig("ambient_sfx", 1) == 0) then begin
      track = AMBIENT_BLANK;
   end

   return "data\\sound\\SFX\\Ambient\\" + track;
end

// Fix for crappy cur_town which sometimes returns an incorrect, obsolete value
procedure cur_town_fixed begin
   variable cmi = cur_map_index;




/*

TODO

#define MAP_SPECIAL_RND_COPS   (132)


#define MAP_SPECIAL_ROBOT_WARDEN (175)


#define MAP_DOGTOWN_PRIVATE_SHELTER_EXTERIOR (211)
#define MAP_DOGTOWN_PRIVATE_SHELTER_INTERIOR (212)


#define MAP_KARLSTOWN (152)

#define MAP_KARLTOWN_MARKET (225)
#define MAP_KARLTOWN_GATE (226)



#define MAP_KARLTOWN_JAIL (353)
#define MAP_KARLTOWN_FARM (354)
#define MAP_KARLTOWN_FARM_2 (355)
#define MAP_KARLTOWN_GECKOS (356)
#define MAP_KARLTOWN_TOXIC_POND (357)
#define MAP_KARLTOWN_HANGING_BRIDGE (358)
#define MAP_KARLTOWN_CAVE (359)

#define MAP_SALT_LAKE_CITY_SEWERS (360)
#define MAP_VAULT_70 (361)

*/

   if (
      (cmi == MAP_RND_DESERT_1) or
      (cmi == MAP_RND_DESERT_2) or
      (cmi == MAP_RND_DESERT_3) or
      (cmi == MAP_RND_DESERT4) or
      (cmi == MAP_RND_DESERT5) or
      (cmi == MAP_RND_DESERT6) or
      (cmi == MAP_RND_DESERT7) or
      (cmi == MAP_RND_DESERT_8) or
      (cmi == MAP_RND_DESERT_9) or
      (cmi == MAP_RND_DESERT_10) or
      (cmi == MAP_RND_DESERT_11) or
      (cmi == MAP_RND_DESERT_12) or
      (cmi == MAP_RND_DESERT_13) or
      (cmi == MAP_RND_DESERT_14)
   ) then begin
      return AREA_RND_DESERT;
   end
   else if (
      (cmi == MAP_RND_MOUNTAIN1) or
      (cmi == MAP_RND_CAVERN0) or
      (cmi == MAP_RND_MOUNTAIN2) or
      (cmi == MAP_RND_CAVERN1) or
      (cmi == MAP_RND_CAVERN2) or
      (cmi == MAP_RND_CAVERN3) or
      (cmi == MAP_RND_CAVERN4) or
      (cmi == MAP_RND_CAVERN5) or
      (cmi == MAP_RND_MOUNTAIN_3) or
      (cmi == MAP_RND_MOUNTAIN_4) or
      (cmi == MAP_RND_MOUNTAIN_5) or
      (cmi == MAP_RND_MOUNTAIN_6)
   ) then begin
      return AREA_RND_MOUNTAIN;
   end
   else if (
      (cmi == MAP_RND_CITY1) or
      (cmi == MAP_RND_CITY_2) or
      (cmi == MAP_RND_CITY_3) or
      (cmi == MAP_RND_CITY_4) or
      (cmi == MAP_RND_CITY_5) or
      (cmi == MAP_RND_CITY_6) or
      (cmi == MAP_RND_CITY_7) or
      (cmi == MAP_RND_CITY_8) or
      (cmi == MAP_RND_CITY_9) or
      (cmi == MAP_RND_CITY_10)
   ) then begin
      return AREA_RND_MOUNTAIN;
   end
   else if (
      (cmi == MAP_RND_COAST1) or
      (cmi == MAP_RND_COAST2) or
      (cmi == MAP_RND_COAST3) or
      (cmi == MAP_RND_COAST4) or
      (cmi == MAP_RND_COAST5) or
      (cmi == MAP_RND_COAST6) or
      (cmi == MAP_RND_COAST7) or
      (cmi == MAP_RND_COAST8) or
      (cmi == MAP_RND_COAST9) or
      (cmi == MAP_RND_COAST_10) or
      (cmi == MAP_RND_COAST_11) or
      (cmi == MAP_RND_COAST_12)
   ) then begin
      return AREA_RND_COAST;
   end
   else if (
      (cmi == MAP_THE_RESERVATION_GATE) or
      (cmi == MAP_THE_RESERVATION_TRADING_POST) or
      (cmi == MAP_RESERVATION_HANGAR_A) or
      (cmi == MAP_RESERVATION_HANGAR_B) or
      (cmi == MAP_RESERVATION_SUB_LEVELS) or
      (cmi == MAP_RESERVATION_TOWN_NORTH) or
      (cmi == MAP_RESERVATION_TOWN_SOUTH)
   ) then begin
      return AREA_THE_RESERVATION;
   end
   else if (
      (cmi == MAP_TWIN_MOTHERS_FIELDS) or
      (cmi == MAP_TWIN_MOTHERS_FORBIDDEN_LANDS) or
      (cmi == MAP_TWIN_MOTHERS_MYSTERY_CAVES) or
      (cmi == MAP_TWIN_MOTHERS_SATELLITE_DISH) or
      (cmi == MAP_TWIN_MOTHERS_VILLAGE) or
      (cmi == MAP_VAULT_29)
   ) then begin
      return AREA_TWIN_MOTHERS;
   end
   else if (
      (cmi == MAP_HOOVER_DAM_SOUTH_GATE) or
      (cmi == MAP_HOOVER_DAM_NORTH_GATE) or
      (cmi == MAP_HOOVER_DAM_RIM) or
      (cmi == MAP_HOOVER_DAM_DOWNTOWN_NORTHEAST) or
      (cmi == MAP_HOOVER_DAM_BASELINE) or
      (cmi == MAP_HOOVER_DAM_SCUM_PITS) or
      (cmi == MAP_HOOVER_DAM_S1C)
   ) then begin
      return AREA_HOOVER_DAM;
   end
   else if (
      (cmi == MAP_DOGTOWN_BREWERY) or
      (cmi == MAP_DOGTOWN_THE_BOX) or
      (cmi == MAP_DOGTOWN_THE_BOX_GROUND_LEVEL) or
      (cmi == MAP_DOGTOWN_THE_BOX_SEWERS) or
      (cmi == MAP_DOGTOWN_BOMBAY_JACK_CANYON) or
      (cmi == MAP_DOGTOWN_OLD_CAMP) or
      (cmi == MAP_DOGTOWN_UNION_STATION) or
      (cmi == MAP_DOGTOWN_THE_BOX_LEVELS_234) or
      (cmi == MAP_DOGTOWN_SKYSCRAPER) or
      (cmi == MAP_DOGTOWN_NEW_CAMP_EAST_SKYSCRAPER_EXTERIOR) or
      (cmi == MAP_DOGTOWN_NEW_CAMP_WEST_SKYSCRAPER_EXTERIOR) or
      (cmi == MAP_DOGTOWN_NEW_CAMP_EAST_SKYSCRAPER_INTERIOR) or
      (cmi == MAP_DOGTOWN_NEW_CAMP_WEST_SKYSCRAPER_INTERIOR) or
      (cmi == MAP_DOGTOWN_CAESARS_LEGION) or
      (cmi == MAP_DOGTOWN_CAESARS_LEGION_BASEMENT) or
      (cmi == MAP_DOGTOWN_RIVAL_CAMP) or
      (cmi == MAP_DOGTOWN_NEW_CAMP_SOUTH) or
      (cmi == MAP_DOGTOWN_POLICE_HQ) or
      (cmi == MAP_DOGTOWN_QUARANTINE_AREA) or
      (cmi == MAP_DOGTOWN_QUARANTINE_CENTER) or
      (cmi == MAP_DOGTOWN_HOSPITAL)
   ) then begin
      return AREA_DOGTOWN;
   end
   else if (
      (cmi == MAP_TIBBETS_CELL_BLOCK_13) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_14) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_15) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_16) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_17) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_18) or
      (cmi == MAP_TIBBETS_SECURITY_HUB) or
      (cmi == MAP_TIBBETS_SERVICE_LEVEL_WEST) or
      (cmi == MAP_TIBBETS_SERVICE_LEVEL_EAST) or
      (cmi == MAP_TIBBETS_COURTROOM) or
      (cmi == MAP_TIBBETS_BREACH_VALKYRIE) or
      (cmi == MAP_TIBBETS_BREACH) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_19) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_20) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_21) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_22) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_23) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_24) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_25) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_26) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_27) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_28) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_29) or
      (cmi == MAP_TIBBETS_CELL_BLOCK_30) or
      (cmi == MAP_BOMBED_OUT_CITY) or
      (cmi == MAP_VAULT_8) or
      (cmi == MAP_TIBBETS_MEDICAL_TREATMENT_AREA_LEVEL_1) or
      (cmi == MAP_TIBBETS_ASYLUM_HOSPITAL) or
      (cmi == MAP_TIBBETS_ASYLUM_UNDERGROUND_GARAGE) or
      (cmi == MAP_TIBBETS_MEDICAL_TREATMENT_AREA_LEVEL_2) or
      (cmi == MAP_TIBBETS_MEDICAL_TREATMENT_AREA_LEVEL_3) or
      (cmi == MAP_ASYLUM_MOUNTAIN_ENTRANCE_TRAM_STATION) or
      (cmi == MAP_TIBBETS_MEDICAL_TREATMENT_AREA_TRAM_STATION) or
      (cmi == MAP_ASYLUM_TRAM_STATION) or
      (cmi == MAP_TIBBETS_WASTE_DISPOSAL) or
      (cmi == MAP_TIBBETS_CHEMICAL_TREATMENT) or
      (cmi == MAP_TIBBETS_MECHANICS_AND_ROBOT_MAINTENANCE_BAY_AND_ARSENAL) or
      (cmi == MAP_TIBBETS_SERVICE_AND_VEHICLE_DEPOT_AREAS_LEVEL_1) or
      (cmi == MAP_TIBBETS_SERVICE_AND_VEHICLE_DEPOT_AREAS_LEVEL_2) or
      (cmi == MAP_TIBBETS_SERVICE_AND_VEHICLE_DEPOT_AREAS_LEVEL_3) or
      (cmi == MAP_TIBBETS_SERVICE_AND_VEHICLE_DEPOT_AREAS_CAFE) or
      (cmi == MAP_TIBBETS_DEFENSE_TUNNELS) or
      (cmi == MAP_TIBBETS_CRYOGENIC_CELL_BLOCK_0_ODYSSEUS_COMPUTER_CORE) or
      (cmi == MAP_TIBBETS_TRAIN_STATION) or
      (cmi == MAP_SCRAPHEAP)
   ) then begin
      return AREA_TIBBETS;
   end
   else if (
      (cmi == MAP_BOS_CLIFF) or
      (cmi == MAP_MAXSON_BUNKER) or
      (cmi == MAP_MAXSON_BUNKER_DOOR) or
      (cmi == MAP_BOS_DEAD)
   ) then begin
      return AREA_BROTHERHOOD_OF_STEEL;
   end
   else if (
      (cmi == MAP_BLOOMFIELD_BOMB_003) or
      (cmi == MAP_BLOOMFIELD_COLLAPSED_PARKING) or
      (cmi == MAP_BLOOMFIELD_CONTROL_CENTER) or
      (cmi == MAP_BLOOMFIELD_CONTROL_CENTER_EAST) or
      (cmi == MAP_BLOOMFIELD_CONTROL_CENTER_NORTH) or
      (cmi == MAP_BLOOMFIELD_CONTROL_CENTER_SOUTH) or
      (cmi == MAP_BLOOMFIELD_EAST) or
      (cmi == MAP_BLOOMFIELD_FUEL_TANKS) or
      (cmi == MAP_BLOOMFIELD_LAUNCH_PAD) or
      (cmi == MAP_BLOOMFIELD_SPACE_MUSEUM) or
      (cmi == MAP_BLOOMFIELD_SPACE_MUSEUM_ENTRANCE) or
      (cmi == MAP_BLOOMFIELD_SUB_REACTOR)
   ) then begin
      return AREA_BLOOMFIELD;
   end
   else if (
      (cmi == MAP_BOULDER_DOME_LEVEL_1) or
      (cmi == MAP_BOULDER_DOME_LEVEL_2) or
      (cmi == MAP_BOULDER_DOME_TUNNELS) or
      (cmi == MAP_BOULDER_DOME_ZAX) or
      (cmi == MAP_BOULDER_DOME_SECRET_TUNNEL) or
      (cmi == MAP_JACKALS_CAMP) or
      (cmi == MAP_BOULDER_DOME_WATER_PUMP) or
      (cmi == MAP_BAGGERS_CAMP) or
      (cmi == MAP_BOULDER_DOME_SECRET_TUNNELS_ENTRANCE) or
      (cmi == MAP_DEAD_GHOUL_GRAVEYARD) or
      (cmi == MAP_BOULDER_DOME_TRAIN_STATION) or
      (cmi == MAP_BOULDER_DOME_RUINS_NORTH) or
      (cmi == MAP_BOULDER_DOME_RUINS_SOUTH) or
      (cmi == MAP_JACKALS_CAMP_2) or
      (cmi == MAP_JACKALS_CAMP_3)
   ) then begin
      return AREA_BOULDER_DOME;
   end
   else if (cmi == MAP_SPECIAL_RND_CAR_MART) then begin
      return AREA_SPECIAL_RND_CAR_MART;
   end
   else if (
      (cmi == MAP_CIRCLE_JUNCTION_ROUNDABOUT) or
      (cmi == MAP_CIRCLE_JUNCTION_WAREHOUSES_SOUTH_EAST) or
      (cmi == MAP_CIRCLE_JUNCTION_WAREHOUSES_SOUTH_WEST) or
      (cmi == MAP_CIRCLE_JUNCTION_BIG_HOUSE)
      ) then begin
      return AREA_CIRCLE_JUNCTION;
   end
   else if (
      (cmi == MAP_FORT_ABANDON_COURTYARD) or
      (cmi == MAP_FORT_ABANDON_OIL_REFINERY) or
      (cmi == MAP_FORT_ABANDON_PARKING) or
      (cmi == MAP_FORT_ABANDON_FARM) or
      (cmi == MAP_FORT_ABANDON_FARM_UNDERGROUND) or
      (cmi == MAP_FORT_ABANDON_ISLE) or
      (cmi == MAP_FORT_ABANDON_WEST) or
      (cmi == MAP_FORT_ABANDON_ISLE_UNDERGROUND) or
      (cmi == MAP_FORT_ABANDON_TOWN)
   ) then begin
      return AREA_FORT_ABANDON;
   end
   else if (
      (cmi == MAP_BLACKFOOT_CELLAR) or
      (cmi == MAP_BLACKFOOT_FURNACE_CAVE) or
      (cmi == MAP_BLACKFOOT_FURNACE_CAVE_ENTRANCE) or
      (cmi == MAP_BLACKFOOT_MINE_BIG) or
      (cmi == MAP_BLACKFOOT_MINE_BIG_ENTRANCE) or
      (cmi == MAP_BLACKFOOT_MINE_SMALL) or
      (cmi == MAP_BLACKFOOT_MINE_SMALL_ENTRANCE) or
      (cmi == MAP_BLACKFOOT_SPELUNKING_CAVE) or
      (cmi == MAP_BLACKFOOT_SPELUNKING_TUNNELS) or
      (cmi == MAP_BLACKFOOT_VILLAGE) or
      (cmi == MAP_HANGDOGS_NEW_VILLAGE_EAST) or
      (cmi == MAP_HANGDOGS_NEW_VILLAGE_NORTH) or
      (cmi == MAP_HANGDOGS_NEW_VILLAGE_SOUTH) or
      (cmi == MAP_HANGDOGS_NEW_VILLAGE_WEST) or
      (cmi == MAP_HANGDOGS_NEW_VILLAGE)
   ) then begin
      return AREA_BLACKFOOT;
   end
   else if (
      (cmi == MAP_NURSERY_CONTROL_FACILITY_CONTROL_TOWER) or
      (cmi == MAP_NURSERY_CONTROL_FACILITY_HELIPAD) or
      (cmi == MAP_NURSERY_CONTROL_FACILITY_MAZE) or
      (cmi == MAP_NURSERY_CONTROL_FACILITY_REPOSITORY) or
      (cmi == MAP_NURSERY_ENTRANCE) or
      (cmi == MAP_NURSERY_FACTORY_EXTERIOR) or
      (cmi == MAP_NURSERY_FACTORY_INTERIOR) or
      (cmi == MAP_NURSERY_FILTRATION_PLANT) or
      (cmi == MAP_NURSERY_SPILLWAY) or
      (cmi == MAP_NURSERY_VALLEY_GARDENS) or
      (cmi == MAP_NURSERY_VALLEY_LAKE)
   ) then begin
      return AREA_THE_NURSERY;
   end
   else if (
      (cmi == MAP_GRAND_CANYON_BOMB_002_EXTERIOR) or
      (cmi == MAP_GRAND_CANYON_BOMB_002_INTERIOR) or
      (cmi == MAP_GRAND_CANYON_DEATHCLAW_EAST) or
      (cmi == MAP_GRAND_CANYON_DEATHCLAW_EXIT) or
      (cmi == MAP_GRAND_CANYON_DEATHCLAW_UP) or
      (cmi == MAP_GRAND_CANYON_DEATHCLAW_WEST) or
      (cmi == MAP_GRAND_CANYON_DOCKS) or
      (cmi == MAP_GRAND_CANYON_GHOST_TOWN) or
      (cmi == MAP_GRAND_CANYON_GLOWING_SEA) or
      (cmi == MAP_GRAND_CANYON_MACHINERY) or
      (cmi == MAP_GRAND_CANYON_MINE_1) or
      (cmi == MAP_GRAND_CANYON_MINE_2) or
      (cmi == MAP_GRAND_CANYON_MINE_3) or
      (cmi == MAP_GRAND_CANYON_MINER_TOWN_OLD) or
      (cmi == MAP_GRAND_CANYON_MOLDER) or
      (cmi == MAP_GRAND_CANYON_MOLDER_BARLOWS) or
      (cmi == MAP_GRAND_CANYON_MOLDER_FORTESC) or
      (cmi == MAP_GRAND_CANYON_MOLDER_LOGANS) or
      (cmi == MAP_GRAND_CANYON_NORTH_LODGE) or
      (cmi == MAP_GRAND_CANYON_OFFICE_1) or
      (cmi == MAP_GRAND_CANYON_OFFICE_2) or
      (cmi == MAP_GRAND_CANYON_OFFICE_3) or
      (cmi == MAP_GRAND_CANYON_OFFICE_4) or
      (cmi == MAP_GRAND_CANYON_SOUTH) or
      (cmi == MAP_GRAND_CANYON_URANIUM_MINE_1) or
      (cmi == MAP_GRAND_CANYON_URANIUM_MINE_2)
   ) then begin
      return AREA_THE_GRAND_CANYON;
   end
   else if (
      (cmi == MAP_JERICHO_TRAIN_STATION) or
      (cmi == MAP_JERICHO_TOWN_EAST) or
      (cmi == MAP_JERICHO_MORMONS) or
      (cmi == MAP_JERICHO_TOWN_WEST) or
      (cmi == MAP_JERICHO_SEWERS) or
      (cmi == MAP_JERICHO_FALLOUT_SHELTER) or
      (cmi == MAP_JERICHO_SOUTH)
   ) then begin
      return AREA_JERICHO;
   end
   else if (
      (cmi == MAP_MOLETOWN_ENTRANCE) or
      (cmi == MAP_MOLETOWN_WEST_TUNNELS) or
      (cmi == MAP_MOLETOWN_EAST_TUNNELS)
   ) then begin
      return AREA_MOLETOWN;
   end
   else if (cmi == MAP_SPECIAL_RND_PULOWSKIS) then begin
      return AREA_SPECIAL_RND_PULOWSKIS;
   end else if (cmi == MAP_SPECIAL_RND_LAMP) then begin
      return AREA_SPECIAL_RND_LAMP;
   end else if (cmi == MAP_FORT_DESOLATION) then begin
      return AREA_FORT_DESOLATION;
   end else if (cmi == MAP_LANDING_SITE) then begin
      return AREA_LANDING_SITE;
   end
   else if (
      (cmi == MAP_VACCS_8_ENTRANCE) or
      (cmi == MAP_VACCS_8)
   ) then begin
      return AREA_VACCS;
   end
   else if (cmi == MAP_SPECIAL_RND_POSTMAN) then begin
      return AREA_SPECIAL_RND_POSTMAN;
   end else if (cmi == MAP_SPECIAL_RND_PET_CEMETERY) then begin
      return AREA_SPECIAL_RND_PET_CEMETERY;
   end else if (cmi == MAP_CIRCLE_OF_STEEL) then begin
      return AREA_CIRCLE_OF_STEEL;
   end else if (cmi == MAP_SCAVEN_PICKER_CAMP) then begin
      return AREA_SCAVEN_PICKER_CAMP;
   end else if (cmi == MAP_SPECIAL_RND_EDDIE) then begin
      return AREA_SPECIAL_RND_EDDIE;
   end else if (cmi == MAP_TIBBETS_CRATER) then begin
      return AREA_TIBBETS_CRATER;
   end else if (cmi == MAP_BLOOMFIELD_NUKED) then begin
      return AREA_BLOOMFIELD_NUKED;
   end else if (cmi == MAP_BLACKFOOT_NUKED) then begin
      return AREA_BLACKFOOT_NUKED;
   end else if (cmi == MAP_HOOVER_DAM_NUKED) then begin
      return AREA_HOOVER_DAM_NUKED;
   end else if (cmi == MAP_DOGTOWN_NUKED) then begin
      return AREA_DOGTOWN_NUKED;
   end else if (cmi == MAP_NEW_CANAAN_NUKED) then begin
      return AREA_NEW_CANAAN_NUKED;
   end else if (cmi == MAP_BOULDER_DOME_NUKED) then begin
      return AREA_BOULDER_DOME_NUKED;
   end else if (cmi == MAP_CIRCLE_JUNCTION_NUKED) then begin
      return AREA_CIRCLE_JUNCTION_NUKED;
   end else if (cmi == MAP_FORT_ABANDON_NUKED) then begin
      return AREA_FORT_ABANDON_NUKED;
   end else if (cmi == MAP_MESA_VERDE_NUKED) then begin
      return AREA_MESA_VERDE_NUKED;
   end else if (cmi == MAP_TWIN_MOTHERS_NUKED) then begin
      return AREA_TWIN_MOTHERS_NUKED;
   end else if (cmi == MAP_MAXSON_BUNKER_NUKED) then begin
      return AREA_BROTHERHOOD_OF_STEEL_NUKED;
   end else if (cmi == MAP_OUROBOROS_NUKED) then begin
      return AREA_OUROBOROS_NUKED;
   end else if (cmi == MAP_RESERVATION_NUKED) then begin
      return AREA_THE_RESERVATION_NUKED;
   end else if (cmi == MAP_BURHAM_SPRINGS_NUKED) then begin
      return AREA_BURHAM_SPRINGS_NUKED;
   end else if (cmi == MAP_NURSERY_NUKED) then begin
      return AREA_THE_NURSERY_NUKED;
   end else if (cmi == MAP_JERICHO_NUKED) then begin
      return AREA_JERICHO_NUKED;
   end else if (cmi == MAP_SPECIAL_RND_VAULT69) then begin
      return AREA_SPECIAL_RND_VAULT69;
   end else if (cmi == MAP_SPECIAL_RND_GUARDIAN_REDSHIRTS) then begin
      return AREA_SPECIAL_RND_GUARDIAN;
   end else if (cmi == MAP_SPECIAL_RND_CARIB) then begin
      return AREA_SPECIAL_RND_CARIB;
   end else if (cmi == MAP_SPECIAL_RND_LIBRARY) then begin
      return AREA_SPECIAL_RND_GROVE;
   end
   else if (cmi == MAP_SPECIAL_RND_CAMP_SITE) then begin
      return AREA_SPECIAL_RND_CAMP_SITE;
   end
   else if (
      (cmi == MAP_MESA_VERDE_CANYON_ENTRANCE) or
      (cmi == MAP_MESA_VERDE_VILLAGE_EAST) or
      (cmi == MAP_MESA_VERDE_TOP)
   ) then begin
      return AREA_MESA_VERDE;
   end
   else if (cmi == MAP_SPECIAL_RND_THUNDERBIRD) then begin
      return AREA_SPECIAL_RND_THUNDERBIRD;
   end
   else if (
      (cmi == MAP_OUROBOROS_GATE) or
      (cmi == MAP_OUROBOROS_JUNKYARD) or
      (cmi == MAP_OUROBOROS_NORTH) or
      (cmi == MAP_OUROBOROS_PYRAMID) or
      (cmi == MAP_OUROBOROS_SECRET_TUNNEL) or
      (cmi == MAP_OUROBOROS_VILLAGE) or
      (cmi == MAP_OUROBOROS_VILLAGE_EAST) or
      (cmi == MAP_OUROBOROS_VILLAGE_SOUTH) or
      (cmi == MAP_OUROBOROS_VILLAGE_WEST)
   ) then begin
      return AREA_OUROBOROS;
   end
   else if (cmi == MAP_DEN_OF_LOST_LUCK) then begin
      return AREA_SPECIAL_RND_CASINO;
   end else if (cmi == MAP_VEHICLE_OUTTA_GAS) then begin
      return AREA_VEHICLE_OUTTA_GAS;
   end else if (cmi == MAP_MOTORCYCLE_DESERT) then begin
      return AREA_MOTORCYCLE_ABANDONED;
   end else if (cmi == MAP_DUNE_BUGGY_DESERT) then begin
      return AREA_DUNE_BUGGY_ABANDONED;
   end else if (cmi == MAP_COP_CAR_DESERT) then begin
      return AREA_COP_CAR_ABANDONED;
   end else if (cmi == MAP_SEMI_TRUCK_DESERT) then begin
      return AREA_SEMI_TRUCK_ABANDONED;
   end else if (cmi == MAP_HIGHWAYMAN_DESERT) then begin
      return AREA_HIGHWAYMAN_ABANDONED;
   end
   else if (cmi == MAP_BICYCLE_DESERT) then begin
      return AREA_BICYCLE_ABANDONED;
   end
   else if (
      (cmi == MAP_MESA_VERDE_CANYON_WEST) or
      (cmi == MAP_MESA_VERDE_CANYON_CENTER) or
      (cmi == MAP_MESA_VERDE_HOUNDS_CAMP) or
      (cmi == MAP_MESA_VERDE_BRIDGE) or
      (cmi == MAP_MESA_VERDE_VILLAGE_WEST) or
      (cmi == MAP_MESA_VERDE_VILLAGE_NORTH) or
      (cmi == MAP_MESA_VERDE_BRIDGE_NORTH) or
      (cmi == MAP_MESA_VERDE_CANYON_SOUTH) or
      (cmi == MAP_MESA_VERDE_CANYON_SOUTH_CAVE) or
      (cmi == MAP_MESA_VERDE_CAVES)
   ) then begin
      return AREA_MESA_VERDE_SHADOW_MAPS;
   end
   else if (
      (cmi == MAP_HOOVER_DAM_DOWNTOWN_SOUTH_WEST_FIELDS) or
      (cmi == MAP_HOOVER_DAM_CATWALK) or
      (cmi == MAP_HOOVER_DAM_NCR_ARMY_GYM) or
      (cmi == MAP_HOOVER_DAM_DOWNTOWN_SOUTHEAST) or
      (cmi == MAP_HOOVER_DAM_DOWNTOWN_NORTHWEST) or
      (cmi == MAP_HOOVER_DAM_DOWNTOWN_SOUTH_WEST_FARM) or
      (cmi == MAP_HOOVER_DAM_NCR_ARMY_HQ) or
      (cmi == MAP_HOOVER_DAM_MORGUE)
   ) then begin
      return AREA_HOOVER_DAM_SHADOW_MAPS;
   end
   else if (cmi == MAP_NETHER_REALM) then begin
      return AREA_NETHER_REALM;
   end
   else if (
      (cmi == MAP_IN_GAME_MOVIE_0) or
      (cmi == MAP_IN_GAME_MOVIE1)
   ) then begin
      return AREA_SHADOW_MAPS;
   end
   else if (cmi == MAP_SPECIAL_RND_CRANIUM_RATS) then begin
      return AREA_SPECIAL_RND_CRANIUM_RATS;
   end
   else if (
      (cmi == MAP_SPECIAL_ENCOUNTER_TEMPLE_COAST) or
      (cmi == MAP_SPECIAL_ENCOUNTER_TEMPLE)
   ) then begin
      return AREA_SPECIAL_RND_TENTACLES;
   end
   else if (
      (cmi == MAP_BOMB_001) or
      (cmi == MAP_NY_WEST) or
      (cmi == MAP_NY_EAST) or
      (cmi == MAP_NY_FARM) or
      (cmi == MAP_NY_LIBRARY_EXTERIOR) or
      (cmi == MAP_NY_LIBRARY_INTERIOR) or
      (cmi == MAP_NY_POWERPLANT)
   ) then begin
      return AREA_BOMB_001;
   end
   else if (cmi == MAP_SLAVE_RUN) then begin
      return AREA_SLAVE_RUN;
   end
   else if (
      (cmi == MAP_THE_CRATER_ENTRANCE) or
      (cmi == MAP_THE_CRATER_TUNNEL) or
      (cmi == MAP_THE_CRATER_LEVELS_1_3) or
      (cmi == MAP_THE_CRATER_LEVELS_4_6) or
      (cmi == MAP_THE_CRATER_LEVELS_7_9) or
      (cmi == MAP_CRATER_ARCHIVES_LEVEL_1) or
      (cmi == MAP_CRATER_ARCHIVES_LEVEL_2) or
      (cmi == MAP_BATTALION_BASE_LEVEL_1_2) or
      (cmi == MAP_BATTALION_BASE_LEVEL_3_4) or
      (cmi == MAP_BATTALION_BASE_ENTRANCE)
   ) then begin
      return AREA_THE_CRATER;
   end
   else if (cmi == MAP_HANGDOGS_HOME) then begin
      return AREA_HANGDOGS;
   end
   else if (
      (cmi == MAP_NEW_CANAAN_OUTSKIRTS) or
      (cmi == MAP_NEW_CANAAN_TRAIN_STATION)
   ) then begin
      return AREA_NEW_CANAAN;
   end
   else if (
      (cmi == MAP_BURHAM_SPRINGS_MINE) or
      (cmi == MAP_BURHAM_SPRINGS_TOWN_EAST) or
      (cmi == MAP_BURHAM_SPRINGS_TOWN_WEST)
   ) then begin
      return AREA_BURHAM_SPRINGS;
   end

   // Random encounters, etc.
   return -1;

end

#endif // MAPS_H
