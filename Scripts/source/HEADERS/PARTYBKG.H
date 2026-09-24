/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef PARTYBKG_H
#define PARTYBKG_H

/*****************************************
 Header File for Party Member Backgrounds
*****************************************/

variable PartyMemberBackground := BACKGROUND_WASTELAND;

procedure Check_Fallback;

#define find_party_background       if (cur_town == AREA_TIBBETS) then begin                                                   \
                                        PartyMemberBackground:=BACKGROUND_VAULT_RUSTY;                                         \
                                    end                                                                                        \
                                    else if ((cur_town == AREA_MESA_VERDE) or (cur_town == AREA_MESA_VERDE_SHADOW_MAPS)) then begin     \
                                        PartyMemberBackground:=BACKGROUND_CANYON;                                         \
                                    end                                                                                        \
                                    else if (cur_town == AREA_FORT_ABANDON) then begin                                             \
                                        if (cur_map_index == MAP_FORT_ABANDON_FARM) then                                                \
                                            PartyMemberBackground:=BACKGROUND_JUNKTOWN;                                           \
                                        else if (cur_map_index == MAP_FORT_ABANDON_OIL_REFINERY) then                                                \
                                            PartyMemberBackground:=BACKGROUND_VAULT_RUSTY;                                           \
                                    end                                                                                          \
                                    else if (cur_town == AREA_BOMB_001) then begin                                             \
                                        if (cur_map_index == MAP_BOMB_001) then                                                \
                                            PartyMemberBackground:=BACKGROUND_BOMB001;                                           \
                                        else if (cur_map_index == MAP_NY_WEST) then                                                \
                                            PartyMemberBackground:=BACKGROUND_CITY2;                                           \
                                    end                                                                                          \
                                    else                                                                                       \
                                        Call Check_Fallback



procedure Check_Fallback begin
    if (night) then begin                                                   \
        PartyMemberBackground:=BACKGROUND_WASTELAND_NIGHT;                                         \
    end
end

#endif // PARTYBKG_H
