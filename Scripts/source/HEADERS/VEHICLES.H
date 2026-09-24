// Fallout Yesterday Vehicles Subsystem by PJ Hexer

#ifndef VEHICLES_H
#define VEHICLES_H

#define vehicle_upgrade_fast                bit_1
#define vehicle_upgrade_faster              bit_2
#define vehicle_upgrade_wtf                 bit_3

#define set_vehicle_flag_on(x,gv)           set_gvar_bit_on(gv, x)
#define set_vehicle_flag_off(x,gv)          set_gvar_bit_off(gv, x)
#define get_vehicle_flag(x,gv)              gvar_bit(gv, x)

#define VEHICLE_SPEED_NORMAL                (1)  // 400% walking speed
#define VEHICLE_SPEED_FAST                  (2)  // 500% walking speed GVAR_NEW_RENO_CAR_UPGRADE
#define VEHICLE_SPEED_FASTER                (3)  // 600% walking speed GVAR_CAR_BLOWER
#define VEHICLE_SPEED_WTF                   (4)  // 900% walking speed GVAR_NEW_RENO_SUPER_CAR

#define VEHICLE_TYPE_MOTORCYCLE             (1) // Default Location: Reservation
#define VEHICLE_TYPE_DUNE_BUGGY             (2) // Default Location: Bloomfield
#define VEHICLE_TYPE_COP_CAR                (3) // Default Location: Dogtown
#define VEHICLE_TYPE_SEMI_TRUCK             (4) // Default Location: Ouroboros
#define VEHICLE_TYPE_TRAIN                  (5) // Default Locations: Circle Junction (Lucky 17)
#define VEHICLE_TYPE_HIGHWAYMAN             (6) // Default Location: Special Encounter
#define VEHICLE_TYPE_BICYCLE                (7) // Default Location: Grand Canyon

#define VEHICLE_PASSENGERS_MOTORCYCLE       (2 + motorcycle_has_sidecar)
#define VEHICLE_PASSENGERS_DUNE_BUGGY       (6)
#define VEHICLE_PASSENGERS_COP_CAR          (5)
#define VEHICLE_PASSENGERS_SEMI_TRUCK       (7 + (semi_truck_has_trailer * 7))
#define VEHICLE_PASSENGERS_TRAIN            (100)
#define VEHICLE_PASSENGERS_HIGHWAYMAN       (6)
#define VEHICLE_PASSENGERS_BICYCLE          (2)

#define VEHICLE_DEFAULT_SPEED_MOTORCYCLE        (VEHICLE_SPEED_FAST)
#define VEHICLE_DEFAULT_SPEED_DUNE_BUGGY        (VEHICLE_SPEED_NORMAL)
#define VEHICLE_DEFAULT_SPEED_COP_CAR           (VEHICLE_SPEED_FAST)
#define VEHICLE_DEFAULT_SPEED_SEMI_TRUCK        (VEHICLE_SPEED_NORMAL)
#define VEHICLE_DEFAULT_SPEED_TRAIN             (VEHICLE_SPEED_NORMAL)
#define VEHICLE_DEFAULT_SPEED_HIGHWAYMAN        (VEHICLE_SPEED_NORMAL)
#define VEHICLE_DEFAULT_SPEED_BICYCLE           (VEHICLE_SPEED_NORMAL)

#define TOWN_CIRCLE_LARGE                       (50)
#define TOWN_CIRCLE_MEDIUM                      (22)
#define TOWN_CIRCLE_SMALL                       (11)

#define dude_has_motorcycle                         (global_var(GVAR_PLAYER_GOT_MOTORCYCLE))
#define dude_has_dune_buggy                         (global_var(GVAR_PLAYER_GOT_DUNE_BUGGY))
#define dude_has_cop_car                         (global_var(GVAR_PLAYER_GOT_COP_CAR))
#define dude_has_semi_truck                         (global_var(GVAR_PLAYER_GOT_SEMI_TRUCK))
#define dude_has_train                         (global_var(GVAR_PLAYER_GOT_TRAIN))
#define dude_has_car                         (global_var(GVAR_PLAYER_GOT_HIGHWAYMAN))
#define dude_has_bicycle                         (global_var(GVAR_PLAYER_GOT_BICYCLE))

#define dude_has_vehicle                        (dude_has_motorcycle or dude_has_dune_buggy or dude_has_cop_car or dude_has_semi_truck or dude_has_train or dude_has_car or dude_has_bicycle)

#define current_vehicle_type                (global_var(GVAR_VEHICLE_TYPE))
#define abandoned_current_vehicle           (global_var(GVAR_ABANDONED_CURRENT_VEHICLE))
#define motorcycle_has_sidecar              (global_var(GVAR_MOTORCYCLE_HAS_SIDECAR))
#define semi_truck_has_trailer              (global_var(GVAR_SCIENCE_LAB))

#define max_gas_amount                      (80000)
// Don't divide by large numbers, the engine doesn't like it.
#define gas_pct(gas_amount)                 (gas_amount / (max_gas_amount / 100))

#define self_is_motorcycle                  (self_pid == PID_DRIVABLE_MOTORCYCLE)
#define self_is_car                         (self_pid == PID_DRIVABLE_CAR)
#define self_is_dune_buggy                  (self_pid == PID_DRIVABLE_BUGGY)
#define self_is_cop_car                     (self_pid == PID_DRIVABLE_COP_CAR)
#define self_is_semi_truck                  (self_pid == PID_DRIVABLE_SEMI_TRUCK)
#define self_is_train                       (self_pid == PID_DRIVABLE_TRAIN)
#define self_is_bicycle                     (self_pid == PID_DRIVABLE_BICYCLE)

#define self_is_car_trunk                         (self_pid == PID_CAR_TRUNK)
#define self_is_dune_buggy_trunk                  (self_pid == PID_DUNE_BUGGY_TRUNK)
#define self_is_cop_car_trunk                     (self_pid == PID_COP_CAR_TRUNK)
#define self_is_semi_truck_trunk                  (self_pid == PID_SEMI_TRUCK_TRUNK)
#define self_is_train_trunk                       (self_pid == PID_TRAIN_TRUNK)

procedure DestroyVehicle(variable type);
procedure AbandonCurrentVehicle(variable on_world_map);
procedure RecoverVehicle(variable type);
procedure CheckOuttaGasOnTown;
procedure GiveFuelBrick(variable pid, variable fuel_amount);

procedure vehicle_passengers begin
    if (current_vehicle_type == VEHICLE_TYPE_MOTORCYCLE) then begin
        return VEHICLE_PASSENGERS_MOTORCYCLE;
    end else if (current_vehicle_type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        return VEHICLE_PASSENGERS_DUNE_BUGGY;
    end else if (current_vehicle_type == VEHICLE_TYPE_COP_CAR) then begin
        return VEHICLE_PASSENGERS_COP_CAR;
    end else if (current_vehicle_type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        return VEHICLE_PASSENGERS_SEMI_TRUCK;
    end else if (current_vehicle_type == VEHICLE_TYPE_TRAIN) then begin
        return VEHICLE_PASSENGERS_TRAIN;
    end else if (current_vehicle_type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        return VEHICLE_PASSENGERS_HIGHWAYMAN;
    end else if (current_vehicle_type == VEHICLE_TYPE_BICYCLE) then begin
        return VEHICLE_PASSENGERS_BICYCLE;
    end
end

#define passengers_have_enough_room         (party_size <= vehicle_passengers)

procedure VehicleName(variable type) begin
    if (type == VEHICLE_TYPE_MOTORCYCLE) then begin
        return "bike";
    end
    else if (type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        return "dune buggy";
    end
    else if (type == VEHICLE_TYPE_COP_CAR) then begin
        return "cop car";
    end
    else if (type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        return "truck";
    end
    else if (type == VEHICLE_TYPE_TRAIN) then begin
        return "train";
    end
    else if (type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        return "car";
    end
    else if (type == VEHICLE_TYPE_BICYCLE) then begin
        return "bicycle";
    end
end

procedure VehicleEngineSFX(variable type) begin
    if (type == VEHICLE_TYPE_MOTORCYCLE) then begin
        return "MOTOSTRT";
    end
    else if (type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        return "DUNESTRT";
    end
    else if (type == VEHICLE_TYPE_COP_CAR) then begin
        return "COPSTART";
    end
    else if (type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        return "TRCKSTRT";
    end
    else if (type == VEHICLE_TYPE_TRAIN) then begin
        return "STARDIS1";
    end
    else if (type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        return "carstart";
    end
    else if (type == VEHICLE_TYPE_BICYCLE) then begin
        return "BICLSTRT";
    end
end

procedure VehicleAbandonedArea(variable type) begin
    if (type == VEHICLE_TYPE_MOTORCYCLE) then begin
        return AREA_MOTORCYCLE_ABANDONED;
    end
    else if (type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        return AREA_DUNE_BUGGY_ABANDONED;
    end
    else if (type == VEHICLE_TYPE_COP_CAR) then begin
        return AREA_COP_CAR_ABANDONED;
    end
    else if (type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        return AREA_SEMI_TRUCK_ABANDONED;
    end
    else if (type == VEHICLE_TYPE_TRAIN) then begin
        return -1;
    end
    else if (type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        return AREA_HIGHWAYMAN_ABANDONED;
    end
    else if (type == VEHICLE_TYPE_BICYCLE) then begin
        return AREA_BICYCLE_ABANDONED;
    end
end

procedure SwitchVehicle(variable new_vehicle_type) begin

    variable current_vehicle, current_gas, new_gas, current_town;
    current_vehicle = current_vehicle_type;
    current_gas = car_gas_amount;
    current_town = car_current_town;

    // Save old gas amount and town
    if (current_vehicle == VEHICLE_TYPE_MOTORCYCLE) then begin
        set_global_var(GVAR_VEHICLE_GAS_MOTORCYCLE, current_gas);
        set_global_var(GVAR_VEHICLE_TOWN_MOTORCYCLE, current_town);
    end
    else if (current_vehicle == VEHICLE_TYPE_DUNE_BUGGY) then begin
        set_global_var(GVAR_VEHICLE_GAS_DUNE_BUGGY, current_gas);
        set_global_var(GVAR_VEHICLE_TOWN_DUNE_BUGGY, current_town);
    end
    else if (current_vehicle == VEHICLE_TYPE_COP_CAR) then begin
        set_global_var(GVAR_VEHICLE_GAS_COP_CAR, current_gas);
        set_global_var(GVAR_VEHICLE_TOWN_COP_CAR, current_town);
    end
    else if (current_vehicle == VEHICLE_TYPE_SEMI_TRUCK) then begin
        set_global_var(GVAR_VEHICLE_GAS_SEMI_TRUCK, current_gas);
        set_global_var(GVAR_VEHICLE_TOWN_SEMI_TRUCK, current_town);
    end
    else if (current_vehicle == VEHICLE_TYPE_TRAIN) then begin
        set_global_var(GVAR_VEHICLE_GAS_TRAIN, current_gas);
        set_global_var(GVAR_VEHICLE_TOWN_TRAIN, current_town);
    end
    else if (current_vehicle == VEHICLE_TYPE_HIGHWAYMAN) then begin
        set_global_var(GVAR_VEHICLE_GAS_HIGHWAYMAN, current_gas);
        set_global_var(GVAR_VEHICLE_TOWN_HIGHWAYMAN, current_town);
    end
    else if (current_vehicle == VEHICLE_TYPE_BICYCLE) then begin
        set_global_var(GVAR_VEHICLE_GAS_BICYCLE, current_gas);
        set_global_var(GVAR_VEHICLE_TOWN_BICYCLE, current_town);
    end

    // We need to swap the "outta gas" area. This code needs to run after we save current town because otherwise the current vehicle will remain on new vehicle's outta gas area
    if (
        (current_town == AREA_VEHICLE_OUTTA_GAS) or
        ((current_town == VehicleAbandonedArea(new_vehicle_type)) and (VehicleAbandonedArea(new_vehicle_type) != -1))
        ) then begin
        call AbandonCurrentVehicle(true);
    end

    // Load new gas amount and set town
    if (new_vehicle_type == VEHICLE_TYPE_MOTORCYCLE) then begin
        new_gas = global_var(GVAR_VEHICLE_GAS_MOTORCYCLE);
    end
    else if (new_vehicle_type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        new_gas = global_var(GVAR_VEHICLE_GAS_DUNE_BUGGY);
    end
    else if (new_vehicle_type == VEHICLE_TYPE_COP_CAR) then begin
        new_gas = global_var(GVAR_VEHICLE_GAS_COP_CAR);
    end
    else if (new_vehicle_type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        new_gas = global_var(GVAR_VEHICLE_GAS_SEMI_TRUCK);
    end
    else if (new_vehicle_type == VEHICLE_TYPE_TRAIN) then begin
        new_gas = global_var(GVAR_VEHICLE_GAS_TRAIN);
    end
    else if (new_vehicle_type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        new_gas = global_var(GVAR_VEHICLE_GAS_HIGHWAYMAN);
    end
    else if (new_vehicle_type == VEHICLE_TYPE_BICYCLE) then begin
        new_gas = global_var(GVAR_VEHICLE_GAS_BICYCLE);
    end

    // Set gas to 0 first
    car_give_gas(-current_gas);
    // Set new values
    car_give_gas(new_gas);
    set_car_current_town(cur_town);
end

procedure SetupCurrentVehicleType begin
    variable type, wm_art;
    type = 0;
    wm_art = 433;

    //debug("vehicle pid " + self_pid)

    if (self_is_motorcycle) then begin
        type = VEHICLE_TYPE_MOTORCYCLE;
        wm_art = 695;
        //debug("Setting motorcycle")
    end
    else if (self_is_dune_buggy) then begin
        type = VEHICLE_TYPE_DUNE_BUGGY;
        wm_art = 696;
        //debug("Setting dune buggy")
    end
    else if (self_is_cop_car) then begin
        type = VEHICLE_TYPE_COP_CAR;
        wm_art = 697;
        //debug("Setting cop car")
    end
    else if (self_is_semi_truck) then begin
        type = VEHICLE_TYPE_SEMI_TRUCK;
        wm_art = 698;
        //debug("Setting semi-truck")
    end
    else if (self_is_train) then begin
        type = VEHICLE_TYPE_TRAIN;
        //debug("Setting train")
    end
    else if (self_is_car) then begin
        type = VEHICLE_TYPE_HIGHWAYMAN;
        //debug("Setting car")
    end
    else if (self_is_bicycle) then begin
        type = VEHICLE_TYPE_BICYCLE;
        wm_art = 699;
        //debug("Setting bicycle")
    end

    // We need to save the previous vehicle's status
    if ((current_vehicle_type != 0) and (type != current_vehicle_type)) then begin
        //debug("Switching vehicle from " + current_vehicle_type + " to " + type)
        call SwitchVehicle(type);
    end

    set_global_var(GVAR_ABANDONED_CURRENT_VEHICLE, 0);
    set_global_var(GVAR_VEHICLE_TYPE, type);
    set_car_intface_art(wm_art);
end

procedure SetupVehicleSpeed (variable speed) begin

    variable upgrade, blower, super;

    if (speed == VEHICLE_SPEED_NORMAL) then begin
        //debug("SPEED NORMAL")
        upgrade = 0;
        blower = 0;
        super = 0;
    end
    else if (speed == VEHICLE_SPEED_FAST) then begin
        //debug("SPEED FAST")
        upgrade = 1;
        blower = 0;
        super = 0;
    end
    else if (speed == VEHICLE_SPEED_FASTER) then begin
        //debug("SPEED FASTER")
        upgrade = 1;
        blower = 1;
        super = 0;
    end
    else if (speed == VEHICLE_SPEED_WTF) then begin
        //debug("SPEED WTF")
        upgrade = 1;
        blower = 1;
        super = 1;
    end

    set_global_var(GVAR_NEW_RENO_CAR_UPGRADE, upgrade);
    set_global_var(GVAR_CAR_BLOWER, blower);
    set_global_var(GVAR_NEW_RENO_SUPER_CAR, super);
end

procedure SetupVehicleUpgrades (variable type) begin
    if (type == VEHICLE_TYPE_MOTORCYCLE) then begin
        if (get_vehicle_flag(vehicle_upgrade_faster, GVAR_VEHICLE_UPGRADES_MOTORCYCLE)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FASTER);
        end
        else if (get_vehicle_flag(vehicle_upgrade_wtf, GVAR_VEHICLE_UPGRADES_MOTORCYCLE)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_WTF);
        end
        else begin
            call SetupVehicleSpeed(VEHICLE_DEFAULT_SPEED_MOTORCYCLE);
        end
    end
    else if (type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        if (get_vehicle_flag(vehicle_upgrade_fast, GVAR_VEHICLE_UPGRADES_DUNE_BUGGY)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FAST);
        end
        else if (get_vehicle_flag(vehicle_upgrade_faster, GVAR_VEHICLE_UPGRADES_DUNE_BUGGY)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FASTER);
        end
        else begin
            call SetupVehicleSpeed(VEHICLE_DEFAULT_SPEED_DUNE_BUGGY);
        end
    end
    else if (type == VEHICLE_TYPE_COP_CAR) then begin
        if (get_vehicle_flag(vehicle_upgrade_faster, GVAR_VEHICLE_UPGRADES_COP_CAR)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FASTER);
        end
        else if (get_vehicle_flag(vehicle_upgrade_wtf, GVAR_VEHICLE_UPGRADES_COP_CAR)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_WTF);
        end
        else begin
            call SetupVehicleSpeed(VEHICLE_DEFAULT_SPEED_COP_CAR);
        end
    end
    else if (type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        if (get_vehicle_flag(vehicle_upgrade_fast, GVAR_VEHICLE_UPGRADES_SEMI_TRUCK)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FAST);
        end
        else begin
            call SetupVehicleSpeed(VEHICLE_DEFAULT_SPEED_SEMI_TRUCK);
        end
    end
    else if (type == VEHICLE_TYPE_TRAIN) then begin
        if (get_vehicle_flag(vehicle_upgrade_fast, GVAR_VEHICLE_UPGRADES_TRAIN)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FAST);
        end
        else begin
            call SetupVehicleSpeed(VEHICLE_DEFAULT_SPEED_TRAIN);
        end
    end
    else if (type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        if (get_vehicle_flag(vehicle_upgrade_fast, GVAR_VEHICLE_UPGRADES_HIGHWAYMAN)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FAST);
        end
        else if (get_vehicle_flag(vehicle_upgrade_faster, GVAR_VEHICLE_UPGRADES_HIGHWAYMAN)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FASTER);
        end
        else if (get_vehicle_flag(vehicle_upgrade_wtf, GVAR_VEHICLE_UPGRADES_HIGHWAYMAN)) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_WTF);
        end
        else begin
            call SetupVehicleSpeed(VEHICLE_DEFAULT_SPEED_HIGHWAYMAN);
        end
    end
    else if (type == VEHICLE_TYPE_BICYCLE) then begin
        if (dude_strength >= 8) then begin
            call SetupVehicleSpeed(VEHICLE_SPEED_FAST);
        end
        else begin
            call SetupVehicleSpeed(VEHICLE_DEFAULT_SPEED_BICYCLE);
        end
    end
end

procedure SelfGasAmountGVar begin
    if (self_is_motorcycle) then begin
        return GVAR_VEHICLE_GAS_MOTORCYCLE;
    end
    else if (self_is_dune_buggy) then begin
        return GVAR_VEHICLE_GAS_DUNE_BUGGY;
    end
    else if (self_is_cop_car) then begin
        return GVAR_VEHICLE_GAS_COP_CAR;
    end
    else if (self_is_semi_truck) then begin
        return GVAR_VEHICLE_GAS_SEMI_TRUCK;
    end
    else if (self_is_train) then begin
        return GVAR_VEHICLE_GAS_TRAIN;
    end
    else if (self_is_car) then begin
        return GVAR_VEHICLE_GAS_HIGHWAYMAN;
    end
    else if (self_is_bicycle) then begin
        return GVAR_VEHICLE_GAS_BICYCLE;
    end
end

procedure SelfVehicleType begin
    if (self_is_motorcycle) then begin
        return VEHICLE_TYPE_MOTORCYCLE;
    end
    else if (self_is_dune_buggy) then begin
        return VEHICLE_TYPE_DUNE_BUGGY;
    end
    else if (self_is_cop_car) then begin
        return VEHICLE_TYPE_COP_CAR;
    end
    else if (self_is_semi_truck) then begin
        return VEHICLE_TYPE_SEMI_TRUCK;
    end
    else if (self_is_train) then begin
        return VEHICLE_TYPE_TRAIN;
    end
    else if (self_is_car) then begin
        return VEHICLE_TYPE_HIGHWAYMAN;
    end
    else if (self_is_bicycle) then begin
        return VEHICLE_TYPE_BICYCLE;
    end
end

procedure GasAmountInfo begin
    variable type, gas_amount, str;
    type = 0;
    gas_amount = 0;
    str = "";

    type = SelfVehicleType;
    gas_amount = global_var(SelfGasAmountGVar);

    // for the current vehicle, we must return the latest amount, not the one from GVAR
    if (type == current_vehicle_type) then begin
        gas_amount = car_gas_amount;
        //debug("current vehicle gas " + gas_amount)
    end

    str = VehicleName(type);

    if (gas_amount <= 0) then begin
        display_msg(string_format(g_mstr(1114), str, str));
    end else begin
        // Don't divide by large numbers, the engine doesn't like it and returns 0
        display_msg(g_mstr(1111) + " " + str + " " + g_mstr(1112) + " " + gas_pct(gas_amount) + "% " + g_mstr(1113));
    end
end

procedure Drive begin
    // Both our current vehicle and new vehicle are out of gas, don't do anything except inform the player
    if (
        (current_vehicle_type != 0) and
        (current_vehicle_type != SelfVehicleType) and
        (car_gas_amount <= 0) and
        (global_var(SelfGasAmountGVar) <= 0)
    ) then begin
        script_overrides;
        call GasAmountInfo;
    end else begin
        call SetupCurrentVehicleType;

        if (car_out_of_fuel) then begin
            script_overrides;
            call GasAmountInfo;
        end else begin
            //debug("current vehicle type " + current_vehicle_type)
            //debug("party size " + party_size)
            //debug("vehicle passengers " + vehicle_passengers)

            if (passengers_have_enough_room) then begin
                call SetupVehicleUpgrades(current_vehicle_type);
                // We need to remove our vehicle's World Map location
                call RecoverVehicle(current_vehicle_type);
                play_sfx(VehicleEngineSFX(current_vehicle_type));

                car_give_to_party;
            end
            else begin
                display_msg(g_mstr(1115));
            end
        end
    end
end

#define Create_Motorcycle(tile, elev)           if (not (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_MOTORCYCLE) != 0)) then begin                 \
                                                    /*debug("Create_Motorcycle(" + tile + "," + elev + ")")*/                                                                   \
                                                    Scenery_Creation:=create_object_sid(PID_DRIVABLE_MOTORCYCLE, tile, elev, SCRIPT_ZVEHICLE);      \
                                                    Scenery_Creation_Hex:=tile;                                                                   \
                                                    Blocking_Cycle(1,1,elev)                                                                       \
                                                    Blocking_Cycle(2,1,elev)                                                                       \
                                                    Blocking_Cycle(4,2,elev)                                                                       \
                                                    Blocking_Cycle(5,1,elev)                                                                       \
                                                end

#define Destroy_Motorcycle(tile, elev)          /*debug("Destroy_Motorcycle(" + tile + "," + elev + ")")*/                                \
                                                Scenery_Creation_Ptr:=tile_contains_pid_obj(tile, elev, PID_DRIVABLE_MOTORCYCLE);         \
                                                if (Scenery_Creation_Ptr != 0) then begin                                                \
                                                    Scenery_Creation_Hex:=tile;                                                           \
                                                    Dest_Block_Cycle(1,1,elev)                                                                       \
                                                    Dest_Block_Cycle(2,1,elev)                                                                       \
                                                    Dest_Block_Cycle(4,2,elev)                                                                       \
                                                    Dest_Block_Cycle(5,1,elev)                                                                       \
                                                    destroy_object(self_obj);                                                 \
                                                end

#define Create_Dune_Buggy(tile, elev)           if (not (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_BUGGY) != 0)) then begin                 \
                                                    /*debug("Create_Dune_Buggy(" + tile + "," + elev + ")")*/                                               \
                                                    Scenery_Creation:=create_object_sid(PID_DRIVABLE_BUGGY, tile, elev, SCRIPT_ZVEHICLE);      \
                                                    Scenery_Creation_Hex:=tile;                                                                   \
                                                    Blocking_Cycle(2,1,elev)                                                                       \
                                                    Blocking_Cycle(1,2,elev)                                                                       \
                                                    Blocking_Cycle(2,1,elev)                                                                       \
                                                    Blocking_Cycle(5,1,elev)                                                                       \
                                                    Blocking_Cycle(0,1,elev)                                                                       \
                                                    Blocking_Cycle(5,1,elev)                                                                       \
                                                    Blocking_Cycle(4,4,elev)                                                                       \
                                                    Blocking_Cycle(3,1,elev)                                                                       \
                                                    Blocking_Cycle(2,1,elev)                                                                       \
                                                    Blocking_Cycle(0,1,elev)                                                                       \
                                                end

#define Destroy_Dune_Buggy(tile, elev)          debug("Destroy_Dune_Buggy(" + tile + "," + elev + ")")                                \
                                                Scenery_Creation_Ptr:=tile_contains_pid_obj(tile, elev, PID_DRIVABLE_BUGGY);         \
                                                if (Scenery_Creation_Ptr != 0) then begin                                                \
                                                    Scenery_Creation_Hex:=tile;                                                           \
                                                    Dest_Block_Cycle(2,1,elev)                                                                       \
                                                    Dest_Block_Cycle(1,2,elev)                                                                       \
                                                    Dest_Block_Cycle(2,1,elev)                                                                       \
                                                    Dest_Block_Cycle(5,1,elev)                                                                       \
                                                    Dest_Block_Cycle(0,1,elev)                                                                       \
                                                    Dest_Block_Cycle(5,1,elev)                                                                       \
                                                    Dest_Block_Cycle(4,4,elev)                                                                       \
                                                    Dest_Block_Cycle(3,1,elev)                                                                       \
                                                    Dest_Block_Cycle(2,1,elev)                                                                       \
                                                    Dest_Block_Cycle(0,1,elev)                                                                       \
                                                    set_global_var(GVAR_SHOW_DUNE_BUGGY_TRUNK, 0);                                                   \
                                                    destroy_object(self_obj);                                                 \
                                                end

#define Create_Cop_Car(tile, elev)              if (not (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_COP_CAR) != 0)) then begin                 \
                                                    /*debug("Create_Cop_Car(" + tile + "," + elev + ")")*/                                               \
                                                    Scenery_Creation:=create_object_sid(PID_DRIVABLE_COP_CAR, tile, elev, SCRIPT_ZVEHICLE);      \
                                                    Scenery_Creation_Hex:=tile;                                                                   \
                                                    Blocking_Cycle(2,1,elev)                                                                       \
                                                    Blocking_Cycle(1,1,elev)                                                                       \
                                                    Blocking_Cycle(2,1,elev)                                                                       \
                                                    Blocking_Cycle(0,3,elev)                                                                       \
                                                    Blocking_Cycle(5,1,elev)                                                                       \
                                                    Blocking_Cycle(4,1,elev)                                                                       \
                                                    Blocking_Cycle(5,1,elev)                                                                       \
                                                    Blocking_Cycle(4,1,elev)                                                                       \
                                                    Blocking_Cycle(5,1,elev)                                                                       \
                                                    Blocking_Cycle(4,2,elev)                                                                       \
                                                    Blocking_Cycle(3,1,elev)                                                                       \
                                                    Blocking_Cycle(4,1,elev)                                                                       \
                                                    Blocking_Cycle(2,3,elev)                                                                       \
                                                    Blocking_Cycle(1,1,elev)                                                                       \
                                                    if (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_COP_CAR) != 0) then begin \
                                                        set_global_var(GVAR_SHOW_COP_CAR_TRUNK, 1);                         \
                                                        Create_Cop_Car_Trunk(tile, elev)                                       \
                                                     end                                                                       \
                                                end

#define Create_Cop_Car_Trunk(tile, elev)         if (not (tile_contains_pid_obj(tile_num_in_direction(tile_num_in_direction(tile, 0, 1), 5, 3), elev, PID_COP_CAR_TRUNK) != 0)) then begin \
                                                   /*debug("placing cop car trunk:")*/                                                        \
                                                   Scenery_Creation_Ptr := 0;                                                          \
                                                   if (CopTrunk_Ptr != 0) then begin                                                      \
                                                      Scenery_Creation_Ptr := CopTrunk_Ptr;                                               \
                                                   end else begin                                      \
                                                      Scenery_Creation_Ptr := create_object_sid(PID_COP_CAR_TRUNK,0,0,SCRIPT_ZICRTRNK); \
                                                   end                                                                                 \
                                                   if (Scenery_Creation_Ptr != 0) then begin                                           \
                                                        check_set_obj_visibility(Scenery_Creation_Ptr, false);                         \
                                                        Scenery_Creation_Hex := tile_num_in_direction(tile_num_in_direction(tile, 0, 1), 5, 3); \
                                                        move_to(Scenery_Creation_Ptr, Scenery_Creation_Hex, elev);                  \
                                                   end else begin                                                                      \
                                                      /*debug("WE HAD AN ERROR WITH THE COP CAR TRUNK PTR, OHHH FUCK")*/                      \
                                                   end                                                                                 \
                                                end

#define Destroy_Cop_Car(tile, elev)          /*debug("Destroy_Cop_Car(" + tile + "," + elev + ")")*/                                \
                                                Scenery_Creation_Ptr:=tile_contains_pid_obj(tile, elev, PID_DRIVABLE_COP_CAR);         \
                                                if (Scenery_Creation_Ptr != 0) then begin                                                \
                                                    Scenery_Creation_Hex:=tile;                                                           \
                                                    Dest_Block_Cycle(2,1,elev)                                                                       \
                                                    Dest_Block_Cycle(1,1,elev)                                                                       \
                                                    Dest_Block_Cycle(2,1,elev)                                                                       \
                                                    Dest_Block_Cycle(0,3,elev)                                                                       \
                                                    Dest_Block_Cycle(5,1,elev)                                                                       \
                                                    Dest_Block_Cycle(4,1,elev)                                                                       \
                                                    Dest_Block_Cycle(5,1,elev)                                                                       \
                                                    Dest_Block_Cycle(4,1,elev)                                                                       \
                                                    Dest_Block_Cycle(5,1,elev)                                                                       \
                                                    Dest_Block_Cycle(4,2,elev)                                                                       \
                                                    Dest_Block_Cycle(3,1,elev)                                                                       \
                                                    Dest_Block_Cycle(4,1,elev)                                                                       \
                                                    Dest_Block_Cycle(2,3,elev)                                                                       \
                                                    Dest_Block_Cycle(1,1,elev)                                                                       \
                                                    set_global_var(GVAR_SHOW_COP_CAR_TRUNK, 0);                                                      \
                                                    destroy_object(self_obj);                                                 \
                                                end

#define Create_Car(tile, elev)          /*debug_msg("Place_Car(" + tile + "," + elev + ")");*/                                \
                                        if (not (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_CAR) != 0)) then begin \
                                            Scenery_Creation:=create_object_sid(PID_DRIVABLE_CAR,tile,elev, SCRIPT_ZVEHICLE); \
                                            Scenery_Creation_Hex:=tile;                                                      \
                                            Blocking_Cycle(1,2,elev)                                                       \
                                            Blocking_Cycle(2,2,elev)                                                       \
                                            Blocking_Cycle(3,2,elev)                                                       \
                                            Blocking_Cycle(4,2,elev)                                                       \
                                            Blocking_Cycle(5,1,elev)                                                       \
                                            Blocking_Cycle(4,1,elev)                                                       \
                                            Blocking_Cycle(5,1,elev)                                                       \
                                            Blocking_Cycle(4,1,elev)                                                       \
                                            Blocking_Cycle(5,1,elev)                                                       \
                                            Blocking_Cycle(4,1,elev)                                                       \
                                            Blocking_Cycle(0,1,elev)                                                       \
                                            Blocking_Cycle(5,1,elev)                                                       \
                                            Blocking_Cycle(0,2,elev)                                                       \
                                            Blocking_Cycle(1,1,elev)                                                       \
                                            Blocking_Cycle(2,1,elev)                                                       \
                                            if (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_CAR) != 0) then begin \
                                                set_global_var(GVAR_SHOW_HIGHWAYMAN_TRUNK, 1);                         \
                                                Create_Car_Trunk(tile, elev)                                       \
                                             end                                                                       \
                                        end

#define Create_Car_Trunk(tile, elev)        if (not (tile_contains_pid_obj(tile_num_in_direction(tile_num_in_direction(tile, 5, 2), 4, 1), elev, PID_CAR_TRUNK) != 0)) then begin \
                                                /*debug_msg("placing trunk:");*/                                                        \
                                                Scenery_Creation_Ptr := 0;                                                          \
                                                if (Trunk_Ptr != 0) then begin                                                      \
                                                    Scenery_Creation_Ptr := Trunk_Ptr;                                               \
                                                end else begin                                      \
                                                    Scenery_Creation_Ptr := create_object_sid(PID_CAR_TRUNK,0,0,SCRIPT_ZICRTRNK); \
                                                end                                                                                 \
                                                if (Scenery_Creation_Ptr != 0) then begin                                           \
                                                    check_set_obj_visibility(Scenery_Creation_Ptr, false);                         \
                                                    Scenery_Creation_Hex := tile_num_in_direction(tile_num_in_direction(tile, 5, 2), 4, 1); \
                                                    move_to(Scenery_Creation_Ptr, Scenery_Creation_Hex, elev);                  \
                                                    Blocking_Cycle(1,1,elev)                                                    \
                                                    Blocking_Cycle(2,1,elev)                                                    \
                                                end else begin                                                                      \
                                                    /*debug_msg("WE HAD AN ERROR WITH THE TRUNK PTR, OHHH FUCK");*/                      \
                                                end                                                                                 \
                                            end

#define Destroy_Car(tile, elev)             /*debug_msg("Dest_Car_Loc(" + tile + "," + elev + ")");*/                            \
                                            Scenery_Creation_Ptr:=tile_contains_pid_obj(tile,elev,PID_DRIVABLE_CAR);         \
                                            if (Scenery_Creation_Ptr != 0) then begin                                                \
                                                Scenery_Creation_Hex:=tile;                                                        \
                                                Dest_Block_Cycle(1,2,elev)                                                       \
                                                Dest_Block_Cycle(2,2,elev)                                                       \
                                                Dest_Block_Cycle(3,2,elev)                                                       \
                                                Dest_Block_Cycle(4,2,elev)                                                       \
                                                Dest_Block_Cycle(5,1,elev)                                                       \
                                                Dest_Block_Cycle(4,1,elev)                                                       \
                                                Dest_Block_Cycle(5,1,elev)                                                       \
                                                Dest_Block_Cycle(4,1,elev)                                                       \
                                                Dest_Block_Cycle(5,1,elev)                                                       \
                                                Dest_Block_Cycle(4,1,elev)                                                       \
                                                Dest_Block_Cycle(0,1,elev)                                                       \
                                                Dest_Block_Cycle(5,1,elev)                                                       \
                                                Dest_Block_Cycle(0,2,elev)                                                       \
                                                Dest_Block_Cycle(1,1,elev)                                                       \
                                                Dest_Block_Cycle(2,1,elev)                                                       \
                                                Dest_Block_Cycle(1,1,elev)                                                       \
                                                Dest_Block_Cycle(2,1,elev)                                                       \
                                                set_global_var(GVAR_SHOW_HIGHWAYMAN_TRUNK, 0);                         \
                                                destroy_object(self_obj);                                                 \
                                            end

#define Create_Semi_Truck(tile, elev)           if (not (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_SEMI_TRUCK) != 0)) then begin                 \
                                                    /*debug("Create_Semi_Truck(" + tile + "," + elev + ")")*/                                               \
                                                    Scenery_Creation:=create_object_sid(PID_DRIVABLE_SEMI_TRUCK, tile, elev, SCRIPT_ZVEHICLE);      \
                                                    Scenery_Creation_Hex:=tile;                                                                   \
                                                    Blocking_Cycle(0,1,elev)                                                                       \
                                                    Blocking_Cycle(1,1,elev)                                                                       \
                                                    Blocking_Cycle(0,1,elev)                                                                       \
                                                    Blocking_Cycle(1,1,elev)                                                                       \
                                                    Blocking_Cycle(0,1,elev)                                                                       \
                                                    Blocking_Cycle(5,3,elev)                                                                       \
                                                    Blocking_Cycle(4,1,elev)                                                                       \
                                                    Blocking_Cycle(3,1,elev)                                                                       \
                                                    Blocking_Cycle(4,1,elev)                                                                       \
                                                    Blocking_Cycle(3,1,elev)                                                                       \
                                                    Blocking_Cycle(4,1,elev)                                                                       \
                                                    Blocking_Cycle(3,3,elev)                                                                       \
                                                    Blocking_Cycle(2,2,elev)                                                                       \
                                                    Blocking_Cycle(1,1,elev)                                                                       \
                                                    Blocking_Cycle(0,1,elev)                                                                       \
                                                    if (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_SEMI_TRUCK) != 0) then begin \
                                                        set_global_var(GVAR_SHOW_SEMI_TRUCK_TRUNK, 1);                         \
                                                        Create_Semi_Truck_Trunk(tile, elev)                                       \
                                                     end                                                                       \
                                                end

#define Create_Semi_Truck_Trunk(tile, elev)         if (not (tile_contains_pid_obj(tile_num_in_direction(tile_num_in_direction(tile, 0, 4), 1, 1), elev, PID_SEMI_TRUCK_TRUNK) != 0)) then begin \
                                                   /*debug("placing semi-truck trunk:")*/                                                        \
                                                   Scenery_Creation_Ptr := 0;                                                          \
                                                   if (SemiTruckTrunk_Ptr != 0) then begin                                                      \
                                                      Scenery_Creation_Ptr := SemiTruckTrunk_Ptr;                                               \
                                                   end else begin                                      \
                                                      Scenery_Creation_Ptr := create_object_sid(PID_SEMI_TRUCK_TRUNK,0,0,SCRIPT_ZICRTRNK); \
                                                   end                                                                                 \
                                                   if (Scenery_Creation_Ptr != 0) then begin                                           \
                                                        check_set_obj_visibility(Scenery_Creation_Ptr, false);                         \
                                                        Scenery_Creation_Hex := tile_num_in_direction(tile_num_in_direction(tile, 0, 4), 1, 1); \
                                                        move_to(Scenery_Creation_Ptr, Scenery_Creation_Hex, elev);                  \
                                                   end else begin                                                                      \
                                                      /*debug("WE HAD AN ERROR WITH THE SEMI-TRUCK TRUNK PTR, OHHH FUCK")*/                      \
                                                   end                                                                                 \
                                                end


#define Destroy_Semi_Truck(tile, elev)      /*debug("Destroy_Semi_Truck(" + tile + "," + elev + ")")*/                                \
                                            Scenery_Creation_Ptr:=tile_contains_pid_obj(tile, elev, PID_DRIVABLE_SEMI_TRUCK);         \
                                            if (Scenery_Creation_Ptr != 0) then begin                                                \
                                                Scenery_Creation_Hex:=tile;                                                           \
                                                Dest_Block_Cycle(0,1,elev)                                                                  \
                                                Dest_Block_Cycle(1,1,elev)                                                                \
                                                Dest_Block_Cycle(0,1,elev)                                                             \
                                                Dest_Block_Cycle(1,1,elev)                                                              \
                                                Dest_Block_Cycle(0,1,elev)                                                              \
                                                Dest_Block_Cycle(5,3,elev)                                                               \
                                                Dest_Block_Cycle(4,1,elev)                                                                \
                                                Dest_Block_Cycle(3,1,elev)                                                                 \
                                                Dest_Block_Cycle(4,1,elev)                                                                  \
                                                Dest_Block_Cycle(3,1,elev)                                                                  \
                                                Dest_Block_Cycle(4,1,elev)                                                                   \
                                                Dest_Block_Cycle(3,3,elev)                                                                    \
                                                Dest_Block_Cycle(2,2,elev)                                                                   \
                                                Dest_Block_Cycle(1,1,elev)                                                                   \
                                                Dest_Block_Cycle(0,1,elev)                                                                    \
                                                set_global_var(GVAR_SHOW_SEMI_TRUCK_TRUNK, 0);                         \
                                                destroy_object(self_obj);                                                 \
                                            end

#define Create_Bicycle(tile, elev)              if (not (tile_contains_pid_obj(tile, elev, PID_DRIVABLE_BICYCLE) != 0)) then begin                 \
                                                    /*debug("Create_Bicycle(" + tile + "," + elev + ")")*/                                               \
                                                    Scenery_Creation:=create_object_sid(PID_DRIVABLE_BICYCLE, tile, elev, SCRIPT_ZVEHICLE);      \
                                                    Scenery_Creation_Hex:=tile;                                                                   \
                                                    Blocking_Cycle(2,1,elev)                                                                       \
                                                end

#define Destroy_Bicycle(tile, elev)          /*debug("Destroy_Bicycle(" + tile + "," + elev + ")")*/                                \
                                                Scenery_Creation_Ptr:=tile_contains_pid_obj(tile, elev, PID_DRIVABLE_BICYCLE);         \
                                                if (Scenery_Creation_Ptr != 0) then begin                                                \
                                                    Scenery_Creation_Hex:=tile;                                                           \
                                                    Dest_Block_Cycle(2,1,elev)                                                                       \
                                                    destroy_object(self_obj);                                                 \
                                                end

#define GetRandomEncounterTileElev(tile)        if (cur_map_index == MAP_IN_GAME_MOVIE1) then begin                      \
                                                    tile := CAR_GAMMOVIE_HEX;                                             \
                                                end else if (cur_map_index == MAP_RND_DESERT_1) then begin                 \
                                                    tile := CAR_RND_DESERT1_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_DESERT_2) then begin                 \
                                                    tile := CAR_RND_DESERT2_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_DESERT_3) then begin                 \
                                                    tile := CAR_RND_DESERT3_HEX;                                            \
                                                end else if (cur_map_index == MAP_RND_DESERT4) then begin                 \
                                                    tile := CAR_RND_DESERT4_HEX;                                         \
                                                end else if (cur_map_index == MAP_RND_DESERT5) then begin                 \
                                                    tile := CAR_RND_DESERT5_HEX;                                         \
                                                end else if (cur_map_index == MAP_RND_DESERT6) then begin                 \
                                                    tile := CAR_RND_DESERT6_HEX;                                         \
                                                end else if (cur_map_index == MAP_RND_DESERT7) then begin                 \
                                                    tile := CAR_RND_DESERT7_HEX;                                        \
                                                end else if (cur_map_index == MAP_RND_DESERT_8) then begin                 \
                                                    tile := CAR_RND_DESERT8_HEX;                                          \
                                                end else if (cur_map_index == MAP_RND_DESERT_9) then begin                 \
                                                    tile := CAR_RND_DESERT9_HEX;                                          \
                                                end else if (cur_map_index == MAP_RND_DESERT_10) then begin                 \
                                                    tile := CAR_RND_DESERT10_HEX;                                        \
                                                end else if (cur_map_index == MAP_RND_DESERT_11) then begin                 \
                                                    tile := CAR_RND_DESERT11_HEX;                                            \
                                                end else if (cur_map_index == MAP_RND_DESERT_12) then begin                 \
                                                    tile := CAR_RND_DESERT12_HEX;                                         \
                                                end else if (cur_map_index == MAP_RND_CITY1) then begin                 \
                                                    tile := CAR_RND_CITY1_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CITY_2) then begin                 \
                                                    tile := CAR_RND_CITY2_HEX;                                            \
                                                end else if (cur_map_index == MAP_RND_CITY_3) then begin                 \
                                                    tile := CAR_RND_CITY3_HEX;                                            \
                                                end else if (cur_map_index == MAP_RND_CITY_4) then begin                 \
                                                    tile := CAR_RND_CITY4_HEX;                                          \
                                                end else if (cur_map_index == MAP_RND_CITY_5) then begin                 \
                                                    tile := CAR_RND_CITY5_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CITY_6) then begin                 \
                                                    tile := CAR_RND_CITY6_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CITY_7) then begin                 \
                                                    tile := CAR_RND_CITY7_HEX;                                         \
                                                end else if (cur_map_index == MAP_RND_CITY_8) then begin                 \
                                                    tile := CAR_RND_CITY8_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CITY_9) then begin                 \
                                                    tile := CAR_RND_CITY9_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CAVERN0) then begin                 \
                                                    tile := CAR_RANDOM_MOUNTAIN_HEX;                                       \
                                                end else if (cur_map_index == MAP_RND_CAVERN1) then begin                 \
                                                    tile := CAR_RND_CAVE1_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CAVERN2) then begin                 \
                                                    tile := CAR_RND_CAVE2_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CAVERN3) then begin                 \
                                                    tile := CAR_RND_CAVE3_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CAVERN4) then begin                 \
                                                    tile := CAR_RND_CAVE4_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_CAVERN5) then begin                 \
                                                    tile := CAR_RND_CAVE5_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_MOUNTAIN1) then begin                 \
                                                    tile := CAR_RND_MOUNTAIN1_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_MOUNTAIN2) then begin                 \
                                                    tile := CAR_RND_MOUNTAIN2_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_MOUNTAIN_3) then begin                 \
                                                    tile := CAR_RND_MOUNTAIN3_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_MOUNTAIN_4) then begin                 \
                                                    tile := CAR_RND_MOUNTAIN4_HEX;                                          \
                                                end else if (cur_map_index == MAP_RND_MOUNTAIN_5) then begin                 \
                                                    tile := CAR_RND_MOUNTAIN5_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_MOUNTAIN_6) then begin                 \
                                                    tile := CAR_RND_MOUNTAIN6_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST1) then begin                 \
                                                    tile := CAR_RND_COAST1_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST2) then begin                 \
                                                    tile := CAR_RND_COAST2_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST3) then begin                 \
                                                    tile := CAR_RND_COAST3_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST4) then begin                 \
                                                    tile := CAR_RND_COAST4_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST5) then begin                 \
                                                    tile := CAR_RND_COAST5_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST6) then begin                 \
                                                    tile := CAR_RND_COAST6_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST7) then begin                 \
                                                    tile := CAR_RND_COAST7_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST8) then begin                 \
                                                    tile := CAR_RND_COAST8_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST9) then begin                 \
                                                    tile := CAR_RND_COAST9_HEX;                                          \
                                                end else if (cur_map_index == MAP_RND_COAST_10) then begin                 \
                                                    tile := CAR_RND_COAST10_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST_11) then begin                 \
                                                    tile := CAR_RND_COAST11_HEX;                                           \
                                                end else if (cur_map_index == MAP_RND_COAST_12) then begin                 \
                                                    tile := CAR_RND_COAST12_HEX;                                           \
                                                end else begin                                                              \
                                                    /*debug("ERROR! Tile not found for " + cur_map_index + "! Picking random")*/        \
                                                    tile := tile_num_in_direction(dude_tile, random(0, 5), random(5, 7));            \
                                                end

#define GetMotorcycleTileElev(tile, elev)   /*debug("GetMotorcycleTileElev cur_map_index " + cur_map_index)*/               \
                                            elev = 0;                                                                    \
                                            if (cur_map_index == MAP_THE_RESERVATION_GATE) then begin                 \
                                                tile = MOTORCYCLE_THE_RESERVATION_HEX;                                  \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_SOUTH_GATE) then begin          \
                                                tile = MOTORCYCLE_HOOVER_DAM_HEX;                                            \
                                            end else if (cur_map_index == MAP_DOGTOWN_BREWERY) then begin                 \
                                                tile = MOTORCYCLE_DOGTOWN_HEX;                                           \
                                            end else if (cur_map_index == MAP_TIBBETS_BREACH) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_HEX;                                             \
                                            end else if (cur_map_index == MAP_BOS_CLIFF) then begin                          \
                                                tile = MOTORCYCLE_MAXSON_BUNKER_HEX;                                          \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_CONTROL_CENTER_NORTH) then begin       \
                                                tile = MOTORCYCLE_BLOOMFIELD_HEX;                                                   \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_TRAIN_STATION) then begin                 \
                                                tile = MOTORCYCLE_BOULDER_DOME_HEX;                                                  \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAR_MART) then begin                       \
                                                tile = MOTORCYCLE_CAR_MART_HEX;                                                    \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_ROUNDABOUT) then begin                 \
                                                tile = MOTORCYCLE_CIRCLE_JUNCTION_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_COURTYARD) then begin                 \
                                                tile = MOTORCYCLE_FORT_ABANDON_HEX;                                             \
                                            end else if (cur_map_index == MAP_BLACKFOOT_VILLAGE) then begin                 \
                                                tile = MOTORCYCLE_BLACKFOOT_HEX;                                              \
                                            end else if (cur_map_index == MAP_NURSERY_ENTRANCE) then begin                 \
                                                tile = MOTORCYCLE_THE_NURSERY_HEX;                                             \
                                            end else if (cur_map_index == MAP_GRAND_CANYON_SOUTH) then begin                 \
                                                tile = MOTORCYCLE_THE_GRAND_CANYON_HEX;                                         \
                                            end else if (cur_map_index == MAP_JERICHO_TRAIN_STATION) then begin                 \
                                                tile = MOTORCYCLE_JERICHO_HEX;                                               \
                                            end else if (cur_map_index == MAP_MOLETOWN_ENTRANCE) then begin                 \
                                                tile = MOTORCYCLE_MOLETOWN_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PULOWSKIS) then begin                 \
                                                tile = MOTORCYCLE_PULOWSKIS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LAMP) then begin                 \
                                                tile = MOTORCYCLE_THE_LAMP_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_DESOLATION) then begin                 \
                                                tile = MOTORCYCLE_FORT_DESOLATION_HEX;                                             \
                                            end else if (cur_map_index == MAP_LANDING_SITE) then begin                 \
                                                tile = MOTORCYCLE_LANDING_HEX;                                            \
                                            end else if (cur_map_index == MAP_VACCS_8_ENTRANCE) then begin                 \
                                                tile = MOTORCYCLE_VACCS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_POSTMAN) then begin                 \
                                                tile = MOTORCYCLE_THE_POSTMAN_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PET_CEMETERY) then begin                 \
                                                tile = MOTORCYCLE_PET_CEMETERY_HEX;                                              \
                                            end else if (cur_map_index == MAP_CIRCLE_OF_STEEL) then begin                 \
                                                tile = MOTORCYCLE_COS_HEX;                                                    \
                                            end else if (cur_map_index == MAP_SCAVEN_PICKER_CAMP) then begin                 \
                                                tile = MOTORCYCLE_SCAVEN_HEX;                                                 \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_EDDIE) then begin                 \
                                                tile = MOTORCYCLE_EDDIE_HEX;                                              \
                                            end else if (cur_map_index == MAP_TIBBETS_CRATER) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLACKFOOT_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_DOGTOWN_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NEW_CANAAN_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MESA_VERDE_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_TWIN_MOTHERS_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MAXSON_BUNKER_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_OUROBOROS_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_RESERVATION_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BURHAM_SPRINGS_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NURSERY_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_JERICHO_NUKED) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_VAULT69) then begin                 \
                                                tile = MOTORCYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_GUARDIAN_REDSHIRTS) then begin                 \
                                                tile = MOTORCYCLE_GUARDIAN_REDSHIRTS_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CARIB) then begin                 \
                                                tile = MOTORCYCLE_CARIB_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LIBRARY) then begin                 \
                                                tile = MOTORCYCLE_LIBRARY_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAMP_SITE) then begin              \
                                                tile = MOTORCYCLE_CAMP_SITE_HEX;                                            \
                                            end else if (cur_map_index == MAP_MESA_VERDE_CANYON_ENTRANCE) then begin              \
                                                tile = MOTORCYCLE_MESA_VERDE_CANYON_ENTRANCE_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_THUNDERBIRD) then begin              \
                                                tile = MOTORCYCLE_THUNDERBIRD_HEX;                                            \
                                            end else if (cur_map_index == MAP_OUROBOROS_GATE) then begin                           \
                                                tile = MOTORCYCLE_OUROBOROS_HEX;                                    \
                                            end else if (cur_map_index == MAP_DEN_OF_LOST_LUCK) then begin                           \
                                                tile = MOTORCYCLE_CASINO_HEX;                                    \
                                            end else if (cur_map_index == MAP_VEHICLE_OUTTA_GAS) then begin                 \
                                                tile = MOTORCYCLE_ABANDONED_HEX;                                      \
                                            end else if (cur_map_index == MAP_MOTORCYCLE_DESERT) then begin                 \
                                                tile = MOTORCYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_DUNE_BUGGY_DESERT) then begin                 \
                                                tile = MOTORCYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_COP_CAR_DESERT) then begin                 \
                                                tile = MOTORCYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_SEMI_TRUCK_DESERT) then begin                 \
                                                tile = MOTORCYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_HIGHWAYMAN_DESERT) then begin                 \
                                                tile = MOTORCYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_BICYCLE_DESERT) then begin                 \
                                                tile = MOTORCYCLE_ABANDONED_HEX;                                            \
                                            end else begin                                                              \
                                                GetRandomEncounterTileElev(tile)                                         \
                                            end

#define GetDuneBuggyTileElev(tile, elev)   /*debug("GetDuneBuggyTileElev cur_map_index " + cur_map_index)*/               \
                                            elev = 0;                                                                    \
                                            if (cur_map_index == MAP_THE_RESERVATION_GATE) then begin                 \
                                                tile = DUNE_BUGGY_THE_RESERVATION_HEX;                                  \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_SOUTH_GATE) then begin          \
                                                tile = DUNE_BUGGY_HOOVER_DAM_HEX;                                            \
                                            end else if (cur_map_index == MAP_DOGTOWN_BREWERY) then begin                 \
                                                tile = DUNE_BUGGY_DOGTOWN_HEX;                                           \
                                            end else if (cur_map_index == MAP_TIBBETS_BREACH) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_HEX;                                             \
                                            end else if (cur_map_index == MAP_BOS_CLIFF) then begin                          \
                                                tile = DUNE_BUGGY_MAXSON_BUNKER_HEX;                                          \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_CONTROL_CENTER_NORTH) then begin       \
                                                tile = DUNE_BUGGY_BLOOMFIELD_HEX;                                                   \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_TRAIN_STATION) then begin                 \
                                                tile = DUNE_BUGGY_BOULDER_DOME_HEX;                                                  \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAR_MART) then begin                       \
                                                tile = DUNE_BUGGY_CAR_MART_HEX;                                                    \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_ROUNDABOUT) then begin                 \
                                                tile = DUNE_BUGGY_CIRCLE_JUNCTION_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_COURTYARD) then begin                 \
                                                tile = DUNE_BUGGY_FORT_ABANDON_HEX;                                             \
                                            end else if (cur_map_index == MAP_BLACKFOOT_VILLAGE) then begin                 \
                                                tile = DUNE_BUGGY_BLACKFOOT_HEX;                                              \
                                            end else if (cur_map_index == MAP_NURSERY_ENTRANCE) then begin                 \
                                                tile = DUNE_BUGGY_THE_NURSERY_HEX;                                             \
                                            end else if (cur_map_index == MAP_GRAND_CANYON_SOUTH) then begin                 \
                                                tile = DUNE_BUGGY_THE_GRAND_CANYON_HEX;                                         \
                                            end else if (cur_map_index == MAP_JERICHO_TRAIN_STATION) then begin                 \
                                                tile = DUNE_BUGGY_JERICHO_HEX;                                               \
                                            end else if (cur_map_index == MAP_MOLETOWN_ENTRANCE) then begin                 \
                                                tile = DUNE_BUGGY_MOLETOWN_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PULOWSKIS) then begin                 \
                                                tile = DUNE_BUGGY_PULOWSKIS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LAMP) then begin                 \
                                                tile = DUNE_BUGGY_THE_LAMP_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_DESOLATION) then begin                 \
                                                tile = DUNE_BUGGY_FORT_DESOLATION_HEX;                                             \
                                            end else if (cur_map_index == MAP_LANDING_SITE) then begin                 \
                                                tile = DUNE_BUGGY_LANDING_HEX;                                            \
                                            end else if (cur_map_index == MAP_VACCS_8_ENTRANCE) then begin                 \
                                                tile = DUNE_BUGGY_VACCS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_POSTMAN) then begin                 \
                                                tile = DUNE_BUGGY_THE_POSTMAN_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PET_CEMETERY) then begin                 \
                                                tile = DUNE_BUGGY_PET_CEMETERY_HEX;                                              \
                                            end else if (cur_map_index == MAP_CIRCLE_OF_STEEL) then begin                 \
                                                tile = DUNE_BUGGY_COS_HEX;                                                    \
                                            end else if (cur_map_index == MAP_SCAVEN_PICKER_CAMP) then begin                 \
                                                tile = DUNE_BUGGY_SCAVEN_HEX;                                                 \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_EDDIE) then begin                 \
                                                tile = DUNE_BUGGY_EDDIE_HEX;                                              \
                                            end else if (cur_map_index == MAP_TIBBETS_CRATER) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLACKFOOT_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_DOGTOWN_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NEW_CANAAN_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MESA_VERDE_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_TWIN_MOTHERS_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MAXSON_BUNKER_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_OUROBOROS_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_RESERVATION_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BURHAM_SPRINGS_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NURSERY_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_JERICHO_NUKED) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_VAULT69) then begin                 \
                                                tile = DUNE_BUGGY_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_GUARDIAN_REDSHIRTS) then begin                 \
                                                tile = DUNE_BUGGY_GUARDIAN_REDSHIRTS_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CARIB) then begin                 \
                                                tile = DUNE_BUGGY_CARIB_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LIBRARY) then begin                 \
                                                tile = DUNE_BUGGY_LIBRARY_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAMP_SITE) then begin              \
                                                tile = DUNE_BUGGY_CAMP_SITE_HEX;                                            \
                                            end else if (cur_map_index == MAP_MESA_VERDE_CANYON_ENTRANCE) then begin              \
                                                tile = DUNE_BUGGY_MESA_VERDE_CANYON_ENTRANCE_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_THUNDERBIRD) then begin              \
                                                tile = DUNE_BUGGY_THUNDERBIRD_HEX;                                            \
                                            end else if (cur_map_index == MAP_OUROBOROS_GATE) then begin                           \
                                                tile = DUNE_BUGGY_OUROBOROS_HEX;                                    \
                                            end else if (cur_map_index == MAP_DEN_OF_LOST_LUCK) then begin                           \
                                                tile = DUNE_BUGGY_CASINO_HEX;                                    \
                                            end else if (cur_map_index == MAP_VEHICLE_OUTTA_GAS) then begin                 \
                                                tile = DUNE_BUGGY_ABANDONED_HEX;                                      \
                                            end else if (cur_map_index == MAP_MOTORCYCLE_DESERT) then begin                 \
                                                tile = DUNE_BUGGY_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_DUNE_BUGGY_DESERT) then begin                 \
                                                tile = DUNE_BUGGY_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_COP_CAR_DESERT) then begin                 \
                                                tile = DUNE_BUGGY_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_SEMI_TRUCK_DESERT) then begin                 \
                                                tile = DUNE_BUGGY_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_HIGHWAYMAN_DESERT) then begin                 \
                                                tile = DUNE_BUGGY_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_BICYCLE_DESERT) then begin                 \
                                                tile = DUNE_BUGGY_ABANDONED_HEX;                                            \
                                            end else begin                                                              \
                                                GetRandomEncounterTileElev(tile)                                         \
                                            end

#define GetCopCarTileElev(tile, elev)       /*debug("GetCopCarTileElev cur_map_index " + cur_map_index)*/               \
                                            elev = 0;                                                                    \
                                            if (cur_map_index == MAP_THE_RESERVATION_GATE) then begin                 \
                                                tile = COP_CAR_THE_RESERVATION_HEX;                                  \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_SOUTH_GATE) then begin          \
                                                tile = COP_CAR_HOOVER_DAM_HEX;                                            \
                                            end else if (cur_map_index == MAP_DOGTOWN_BREWERY) then begin                 \
                                                tile = COP_CAR_DOGTOWN_HEX;                                           \
                                            end else if (cur_map_index == MAP_TIBBETS_BREACH) then begin                 \
                                                tile = COP_CAR_TIBBETS_HEX;                                             \
                                            end else if (cur_map_index == MAP_BOS_CLIFF) then begin                          \
                                                tile = COP_CAR_MAXSON_BUNKER_HEX;                                          \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_CONTROL_CENTER_NORTH) then begin       \
                                                tile = COP_CAR_BLOOMFIELD_HEX;                                                   \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_TRAIN_STATION) then begin                 \
                                                tile = COP_CAR_BOULDER_DOME_HEX;                                                  \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAR_MART) then begin                       \
                                                tile = COP_CAR_CAR_MART_HEX;                                                    \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_ROUNDABOUT) then begin                 \
                                                tile = COP_CAR_CIRCLE_JUNCTION_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_COURTYARD) then begin                 \
                                                tile = COP_CAR_FORT_ABANDON_HEX;                                             \
                                            end else if (cur_map_index == MAP_BLACKFOOT_VILLAGE) then begin                 \
                                                tile = COP_CAR_BLACKFOOT_HEX;                                              \
                                            end else if (cur_map_index == MAP_NURSERY_ENTRANCE) then begin                 \
                                                tile = COP_CAR_THE_NURSERY_HEX;                                             \
                                            end else if (cur_map_index == MAP_GRAND_CANYON_SOUTH) then begin                 \
                                                tile = COP_CAR_THE_GRAND_CANYON_HEX;                                         \
                                            end else if (cur_map_index == MAP_JERICHO_TRAIN_STATION) then begin                 \
                                                tile = COP_CAR_JERICHO_HEX;                                               \
                                            end else if (cur_map_index == MAP_MOLETOWN_ENTRANCE) then begin                 \
                                                tile = COP_CAR_MOLETOWN_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PULOWSKIS) then begin                 \
                                                tile = COP_CAR_PULOWSKIS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LAMP) then begin                 \
                                                tile = COP_CAR_THE_LAMP_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_DESOLATION) then begin                 \
                                                tile = COP_CAR_FORT_DESOLATION_HEX;                                             \
                                            end else if (cur_map_index == MAP_LANDING_SITE) then begin                 \
                                                tile = COP_CAR_LANDING_HEX;                                            \
                                            end else if (cur_map_index == MAP_VACCS_8_ENTRANCE) then begin                 \
                                                tile = COP_CAR_VACCS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_POSTMAN) then begin                 \
                                                tile = COP_CAR_THE_POSTMAN_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PET_CEMETERY) then begin                 \
                                                tile = COP_CAR_PET_CEMETERY_HEX;                                              \
                                            end else if (cur_map_index == MAP_CIRCLE_OF_STEEL) then begin                 \
                                                tile = COP_CAR_COS_HEX;                                                    \
                                            end else if (cur_map_index == MAP_SCAVEN_PICKER_CAMP) then begin                 \
                                                tile = COP_CAR_SCAVEN_HEX;                                                 \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_EDDIE) then begin                 \
                                                tile = COP_CAR_EDDIE_HEX;                                              \
                                            end else if (cur_map_index == MAP_TIBBETS_CRATER) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLACKFOOT_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_DOGTOWN_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NEW_CANAAN_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MESA_VERDE_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_TWIN_MOTHERS_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MAXSON_BUNKER_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_OUROBOROS_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_RESERVATION_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BURHAM_SPRINGS_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NURSERY_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_JERICHO_NUKED) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_VAULT69) then begin                 \
                                                tile = COP_CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_GUARDIAN_REDSHIRTS) then begin                 \
                                                tile = COP_CAR_GUARDIAN_REDSHIRTS_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CARIB) then begin                 \
                                                tile = COP_CAR_CARIB_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LIBRARY) then begin                 \
                                                tile = COP_CAR_LIBRARY_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAMP_SITE) then begin              \
                                                tile = COP_CAR_CAMP_SITE_HEX;                                            \
                                            end else if (cur_map_index == MAP_MESA_VERDE_CANYON_ENTRANCE) then begin              \
                                                tile = COP_CAR_MESA_VERDE_CANYON_ENTRANCE_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_THUNDERBIRD) then begin              \
                                                tile = COP_CAR_THUNDERBIRD_HEX;                                            \
                                            end else if (cur_map_index == MAP_OUROBOROS_GATE) then begin                           \
                                                tile = COP_CAR_OUROBOROS_HEX;                                    \
                                            end else if (cur_map_index == MAP_DEN_OF_LOST_LUCK) then begin                           \
                                                tile = COP_CAR_CASINO_HEX;                                    \
                                            end else if (cur_map_index == MAP_VEHICLE_OUTTA_GAS) then begin                 \
                                                tile = COP_CAR_ABANDONED_HEX;                                      \
                                            end else if (cur_map_index == MAP_MOTORCYCLE_DESERT) then begin                 \
                                                tile = COP_CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_DUNE_BUGGY_DESERT) then begin                 \
                                                tile = COP_CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_COP_CAR_DESERT) then begin                 \
                                                tile = COP_CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_SEMI_TRUCK_DESERT) then begin                 \
                                                tile = COP_CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_HIGHWAYMAN_DESERT) then begin                 \
                                                tile = COP_CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_BICYCLE_DESERT) then begin                 \
                                                tile = COP_CAR_ABANDONED_HEX;                                            \
                                            end else begin                                                              \
                                                GetRandomEncounterTileElev(tile)                                         \
                                            end

#define GetSemiTruckTileElev(tile, elev)    /*debug("GetSemiTruckTileElev cur_map_index " + cur_map_index)*/               \
                                            elev = 0;                                                                    \
                                            if (cur_map_index == MAP_THE_RESERVATION_GATE) then begin                 \
                                                tile = SEMI_TRUCK_THE_RESERVATION_HEX;                                  \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_SOUTH_GATE) then begin          \
                                                tile = SEMI_TRUCK_HOOVER_DAM_HEX;                                            \
                                            end else if (cur_map_index == MAP_DOGTOWN_BREWERY) then begin                 \
                                                tile = SEMI_TRUCK_DOGTOWN_HEX;                                           \
                                            end else if (cur_map_index == MAP_TIBBETS_BREACH) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_HEX;                                             \
                                            end else if (cur_map_index == MAP_BOS_CLIFF) then begin                          \
                                                tile = SEMI_TRUCK_MAXSON_BUNKER_HEX;                                          \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_CONTROL_CENTER_NORTH) then begin       \
                                                tile = SEMI_TRUCK_BLOOMFIELD_HEX;                                                   \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_TRAIN_STATION) then begin                 \
                                                tile = SEMI_TRUCK_BOULDER_DOME_HEX;                                                  \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAR_MART) then begin                       \
                                                tile = SEMI_TRUCK_CAR_MART_HEX;                                                    \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_ROUNDABOUT) then begin                 \
                                                tile = SEMI_TRUCK_CIRCLE_JUNCTION_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_COURTYARD) then begin                 \
                                                tile = SEMI_TRUCK_FORT_ABANDON_HEX;                                             \
                                            end else if (cur_map_index == MAP_BLACKFOOT_VILLAGE) then begin                 \
                                                tile = SEMI_TRUCK_BLACKFOOT_HEX;                                              \
                                            end else if (cur_map_index == MAP_NURSERY_ENTRANCE) then begin                 \
                                                tile = SEMI_TRUCK_THE_NURSERY_HEX;                                             \
                                            end else if (cur_map_index == MAP_GRAND_CANYON_SOUTH) then begin                 \
                                                tile = SEMI_TRUCK_THE_GRAND_CANYON_HEX;                                         \
                                            end else if (cur_map_index == MAP_JERICHO_TRAIN_STATION) then begin                 \
                                                tile = SEMI_TRUCK_JERICHO_HEX;                                               \
                                            end else if (cur_map_index == MAP_MOLETOWN_ENTRANCE) then begin                 \
                                                tile = SEMI_TRUCK_MOLETOWN_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PULOWSKIS) then begin                 \
                                                tile = SEMI_TRUCK_PULOWSKIS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LAMP) then begin                 \
                                                tile = SEMI_TRUCK_THE_LAMP_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_DESOLATION) then begin                 \
                                                tile = SEMI_TRUCK_FORT_DESOLATION_HEX;                                             \
                                            end else if (cur_map_index == MAP_LANDING_SITE) then begin                 \
                                                tile = SEMI_TRUCK_LANDING_HEX;                                            \
                                            end else if (cur_map_index == MAP_VACCS_8_ENTRANCE) then begin                 \
                                                tile = SEMI_TRUCK_VACCS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_POSTMAN) then begin                 \
                                                tile = SEMI_TRUCK_THE_POSTMAN_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PET_CEMETERY) then begin                 \
                                                tile = SEMI_TRUCK_PET_CEMETERY_HEX;                                              \
                                            end else if (cur_map_index == MAP_CIRCLE_OF_STEEL) then begin                 \
                                                tile = SEMI_TRUCK_COS_HEX;                                                    \
                                            end else if (cur_map_index == MAP_SCAVEN_PICKER_CAMP) then begin                 \
                                                tile = SEMI_TRUCK_SCAVEN_HEX;                                                 \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_EDDIE) then begin                 \
                                                tile = SEMI_TRUCK_EDDIE_HEX;                                              \
                                            end else if (cur_map_index == MAP_TIBBETS_CRATER) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLACKFOOT_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_DOGTOWN_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NEW_CANAAN_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MESA_VERDE_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_TWIN_MOTHERS_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MAXSON_BUNKER_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_OUROBOROS_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_RESERVATION_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BURHAM_SPRINGS_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NURSERY_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_JERICHO_NUKED) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_VAULT69) then begin                 \
                                                tile = SEMI_TRUCK_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_GUARDIAN_REDSHIRTS) then begin                 \
                                                tile = SEMI_TRUCK_GUARDIAN_REDSHIRTS_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CARIB) then begin                 \
                                                tile = SEMI_TRUCK_CARIB_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LIBRARY) then begin                 \
                                                tile = SEMI_TRUCK_LIBRARY_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAMP_SITE) then begin              \
                                                tile = SEMI_TRUCK_CAMP_SITE_HEX;                                            \
                                            end else if (cur_map_index == MAP_MESA_VERDE_CANYON_ENTRANCE) then begin              \
                                                tile = SEMI_TRUCK_MESA_VERDE_CANYON_ENTRANCE_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_THUNDERBIRD) then begin              \
                                                tile = SEMI_TRUCK_THUNDERBIRD_HEX;                                            \
                                            end else if (cur_map_index == MAP_OUROBOROS_GATE) then begin                           \
                                                tile = SEMI_TRUCK_OUROBOROS_HEX;                                    \
                                            end else if (cur_map_index == MAP_DEN_OF_LOST_LUCK) then begin                           \
                                                tile = SEMI_TRUCK_CASINO_HEX;                                    \
                                            end else if (cur_map_index == MAP_VEHICLE_OUTTA_GAS) then begin                 \
                                                tile = SEMI_TRUCK_ABANDONED_HEX;                                      \
                                            end else if (cur_map_index == MAP_MOTORCYCLE_DESERT) then begin                 \
                                                tile = SEMI_TRUCK_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_DUNE_BUGGY_DESERT) then begin                 \
                                                tile = SEMI_TRUCK_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_COP_CAR_DESERT) then begin                 \
                                                tile = SEMI_TRUCK_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_SEMI_TRUCK_DESERT) then begin                 \
                                                tile = SEMI_TRUCK_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_HIGHWAYMAN_DESERT) then begin                 \
                                                tile = SEMI_TRUCK_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_BICYCLE_DESERT) then begin                 \
                                                tile = SEMI_TRUCK_ABANDONED_HEX;                                            \
                                            end else begin                                                              \
                                                GetRandomEncounterTileElev(tile)                                         \
                                            end

#define GetBicycleTileElev(tile, elev)      /*debug("GetBicycleTileElev cur_map_index " + cur_map_index)*/               \
                                            elev = 0;                                                                    \
                                            if (cur_map_index == MAP_THE_RESERVATION_GATE) then begin                 \
                                                tile = BICYCLE_THE_RESERVATION_HEX;                                  \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_SOUTH_GATE) then begin          \
                                                tile = BICYCLE_HOOVER_DAM_HEX;                                            \
                                            end else if (cur_map_index == MAP_DOGTOWN_BREWERY) then begin                 \
                                                tile = BICYCLE_DOGTOWN_HEX;                                           \
                                            end else if (cur_map_index == MAP_TIBBETS_BREACH) then begin                 \
                                                tile = BICYCLE_TIBBETS_HEX;                                             \
                                            end else if (cur_map_index == MAP_BOS_CLIFF) then begin                          \
                                                tile = BICYCLE_MAXSON_BUNKER_HEX;                                          \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_CONTROL_CENTER_NORTH) then begin       \
                                                tile = BICYCLE_BLOOMFIELD_HEX;                                                   \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_TRAIN_STATION) then begin                 \
                                                tile = BICYCLE_BOULDER_DOME_HEX;                                                  \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAR_MART) then begin                       \
                                                tile = BICYCLE_CAR_MART_HEX;                                                    \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_ROUNDABOUT) then begin                 \
                                                tile = BICYCLE_CIRCLE_JUNCTION_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_COURTYARD) then begin                 \
                                                tile = BICYCLE_FORT_ABANDON_HEX;                                             \
                                            end else if (cur_map_index == MAP_BLACKFOOT_VILLAGE) then begin                 \
                                                tile = BICYCLE_BLACKFOOT_HEX;                                              \
                                            end else if (cur_map_index == MAP_NURSERY_ENTRANCE) then begin                 \
                                                tile = BICYCLE_THE_NURSERY_HEX;                                             \
                                            end else if (cur_map_index == MAP_GRAND_CANYON_SOUTH) then begin                 \
                                                tile = BICYCLE_THE_GRAND_CANYON_HEX;                                         \
                                            end else if (cur_map_index == MAP_JERICHO_TRAIN_STATION) then begin                 \
                                                tile = BICYCLE_JERICHO_HEX;                                               \
                                            end else if (cur_map_index == MAP_MOLETOWN_ENTRANCE) then begin                 \
                                                tile = BICYCLE_MOLETOWN_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PULOWSKIS) then begin                 \
                                                tile = BICYCLE_PULOWSKIS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LAMP) then begin                 \
                                                tile = BICYCLE_THE_LAMP_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_DESOLATION) then begin                 \
                                                tile = BICYCLE_FORT_DESOLATION_HEX;                                             \
                                            end else if (cur_map_index == MAP_LANDING_SITE) then begin                 \
                                                tile = BICYCLE_LANDING_HEX;                                            \
                                            end else if (cur_map_index == MAP_VACCS_8_ENTRANCE) then begin                 \
                                                tile = BICYCLE_VACCS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_POSTMAN) then begin                 \
                                                tile = BICYCLE_THE_POSTMAN_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PET_CEMETERY) then begin                 \
                                                tile = BICYCLE_PET_CEMETERY_HEX;                                              \
                                            end else if (cur_map_index == MAP_CIRCLE_OF_STEEL) then begin                 \
                                                tile = BICYCLE_COS_HEX;                                                    \
                                            end else if (cur_map_index == MAP_SCAVEN_PICKER_CAMP) then begin                 \
                                                tile = BICYCLE_SCAVEN_HEX;                                                 \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_EDDIE) then begin                 \
                                                tile = BICYCLE_EDDIE_HEX;                                              \
                                            end else if (cur_map_index == MAP_TIBBETS_CRATER) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLACKFOOT_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_DOGTOWN_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NEW_CANAAN_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MESA_VERDE_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_TWIN_MOTHERS_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MAXSON_BUNKER_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_OUROBOROS_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_RESERVATION_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BURHAM_SPRINGS_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NURSERY_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_JERICHO_NUKED) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_VAULT69) then begin                 \
                                                tile = BICYCLE_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_GUARDIAN_REDSHIRTS) then begin                 \
                                                tile = BICYCLE_GUARDIAN_REDSHIRTS_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CARIB) then begin                 \
                                                tile = BICYCLE_CARIB_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LIBRARY) then begin                 \
                                                tile = BICYCLE_LIBRARY_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAMP_SITE) then begin              \
                                                tile = BICYCLE_CAMP_SITE_HEX;                                            \
                                            end else if (cur_map_index == MAP_MESA_VERDE_CANYON_ENTRANCE) then begin              \
                                                tile = BICYCLE_MESA_VERDE_CANYON_ENTRANCE_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_THUNDERBIRD) then begin              \
                                                tile = BICYCLE_THUNDERBIRD_HEX;                                            \
                                            end else if (cur_map_index == MAP_OUROBOROS_GATE) then begin                           \
                                                tile = BICYCLE_OUROBOROS_HEX;                                    \
                                            end else if (cur_map_index == MAP_DEN_OF_LOST_LUCK) then begin                           \
                                                tile = BICYCLE_CASINO_HEX;                                    \
                                            end else if (cur_map_index == MAP_VEHICLE_OUTTA_GAS) then begin                 \
                                                tile = BICYCLE_ABANDONED_HEX;                                      \
                                            end else if (cur_map_index == MAP_MOTORCYCLE_DESERT) then begin                 \
                                                tile = BICYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_DUNE_BUGGY_DESERT) then begin                 \
                                                tile = BICYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_COP_CAR_DESERT) then begin                 \
                                                tile = BICYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_SEMI_TRUCK_DESERT) then begin                 \
                                                tile = BICYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_HIGHWAYMAN_DESERT) then begin                 \
                                                tile = BICYCLE_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_BICYCLE_DESERT) then begin                 \
                                                tile = BICYCLE_ABANDONED_HEX;                                            \
                                            end else begin                                                              \
                                                GetRandomEncounterTileElev(tile)                                         \
                                            end

#define GetCarTileElev(tile, elev)          /*debug("GetCarTileElev cur_map_index " + cur_map_index)*/               \
                                            elev = 0;                                                                    \
                                            if (cur_map_index == MAP_THE_RESERVATION_GATE) then begin                 \
                                                tile = CAR_THE_RESERVATION_HEX;                                  \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_SOUTH_GATE) then begin          \
                                                tile = CAR_HOOVER_DAM_HEX;                                            \
                                            end else if (cur_map_index == MAP_DOGTOWN_BREWERY) then begin                 \
                                                tile = CAR_DOGTOWN_HEX;                                           \
                                            end else if (cur_map_index == MAP_TIBBETS_BREACH) then begin                 \
                                                tile = CAR_TIBBETS_HEX;                                             \
                                            end else if (cur_map_index == MAP_BOS_CLIFF) then begin                          \
                                                tile = CAR_MAXSON_BUNKER_HEX;                                          \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_CONTROL_CENTER_NORTH) then begin       \
                                                tile = CAR_BLOOMFIELD_HEX;                                                   \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_TRAIN_STATION) then begin                 \
                                                tile = CAR_BOULDER_DOME_HEX;                                                  \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAR_MART) then begin                       \
                                                tile = CAR_CAR_MART_HEX;                                                    \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_ROUNDABOUT) then begin                 \
                                                tile = CAR_CIRCLE_JUNCTION_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_COURTYARD) then begin                 \
                                                tile = CAR_FORT_ABANDON_HEX;                                             \
                                            end else if (cur_map_index == MAP_BLACKFOOT_VILLAGE) then begin                 \
                                                tile = CAR_BLACKFOOT_HEX;                                              \
                                            end else if (cur_map_index == MAP_NURSERY_ENTRANCE) then begin                 \
                                                tile = CAR_THE_NURSERY_HEX;                                             \
                                            end else if (cur_map_index == MAP_GRAND_CANYON_SOUTH) then begin                 \
                                                tile = CAR_THE_GRAND_CANYON_HEX;                                         \
                                            end else if (cur_map_index == MAP_JERICHO_TRAIN_STATION) then begin                 \
                                                tile = CAR_JERICHO_HEX;                                               \
                                            end else if (cur_map_index == MAP_MOLETOWN_ENTRANCE) then begin                 \
                                                tile = CAR_MOLETOWN_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PULOWSKIS) then begin                 \
                                                tile = CAR_PULOWSKIS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LAMP) then begin                 \
                                                tile = CAR_THE_LAMP_HEX;                                              \
                                            end else if (cur_map_index == MAP_FORT_DESOLATION) then begin                 \
                                                tile = CAR_FORT_DESOLATION_HEX;                                             \
                                            end else if (cur_map_index == MAP_LANDING_SITE) then begin                 \
                                                tile = CAR_LANDING_HEX;                                            \
                                            end else if (cur_map_index == MAP_VACCS_8_ENTRANCE) then begin                 \
                                                tile = CAR_VACCS_HEX;                                               \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_POSTMAN) then begin                 \
                                                tile = CAR_THE_POSTMAN_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_PET_CEMETERY) then begin                 \
                                                tile = CAR_PET_CEMETERY_HEX;                                              \
                                            end else if (cur_map_index == MAP_CIRCLE_OF_STEEL) then begin                 \
                                                tile = CAR_COS_HEX;                                                    \
                                            end else if (cur_map_index == MAP_SCAVEN_PICKER_CAMP) then begin                 \
                                                tile = CAR_SCAVEN_HEX;                                                 \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_EDDIE) then begin                 \
                                                tile = CAR_EDDIE_HEX;                                              \
                                            end else if (cur_map_index == MAP_TIBBETS_CRATER) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLOOMFIELD_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BLACKFOOT_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_HOOVER_DAM_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_DOGTOWN_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NEW_CANAAN_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BOULDER_DOME_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_CIRCLE_JUNCTION_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_FORT_ABANDON_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MESA_VERDE_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_TWIN_MOTHERS_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_MAXSON_BUNKER_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_OUROBOROS_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_RESERVATION_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_BURHAM_SPRINGS_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_NURSERY_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_JERICHO_NUKED) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_VAULT69) then begin                 \
                                                tile = CAR_TIBBETS_DEAD_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_GUARDIAN_REDSHIRTS) then begin                 \
                                                tile = CAR_GUARDIAN_REDSHIRTS_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CARIB) then begin                 \
                                                tile = CAR_CARIB_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_LIBRARY) then begin                 \
                                                tile = CAR_LIBRARY_HEX;                                      \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_CAMP_SITE) then begin              \
                                                tile = CAR_CAMP_SITE_HEX;                                            \
                                            end else if (cur_map_index == MAP_MESA_VERDE_CANYON_ENTRANCE) then begin              \
                                                tile = CAR_MESA_VERDE_CANYON_ENTRANCE_HEX;                                            \
                                            end else if (cur_map_index == MAP_SPECIAL_RND_THUNDERBIRD) then begin              \
                                                tile = CAR_THUNDERBIRD_HEX;                                            \
                                            end else if (cur_map_index == MAP_OUROBOROS_GATE) then begin                           \
                                                tile = CAR_OUROBOROS_HEX;                                    \
                                            end else if (cur_map_index == MAP_DEN_OF_LOST_LUCK) then begin                           \
                                                tile = CAR_CASINO_HEX;                                    \
                                            end else if (cur_map_index == MAP_VEHICLE_OUTTA_GAS) then begin                 \
                                                tile = CAR_ABANDONED_HEX;                                      \
                                            end else if (cur_map_index == MAP_MOTORCYCLE_DESERT) then begin                 \
                                                tile = CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_DUNE_BUGGY_DESERT) then begin                 \
                                                tile = CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_COP_CAR_DESERT) then begin                 \
                                                tile = CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_SEMI_TRUCK_DESERT) then begin                 \
                                                tile = CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_HIGHWAYMAN_DESERT) then begin                 \
                                                tile = CAR_ABANDONED_HEX;                                            \
                                            end else if (cur_map_index == MAP_BICYCLE_DESERT) then begin                 \
                                                tile = CAR_ABANDONED_HEX;                                            \
                                            end else begin                                                              \
                                                GetRandomEncounterTileElev(tile)                                         \
                                            end

procedure Check_Create_Vehicle begin
    if (not is_loading_game) then begin

        // We need to fix the potential problem when a "Outta Gas" circle appears over an existing town circle
        call CheckOuttaGasOnTown;

        variable tile, elev;

        // Motorcycle

        if (dude_has_motorcycle) then begin
            variable gen_motorcycle;
            gen_motorcycle = 0;

            if (current_vehicle_type == VEHICLE_TYPE_MOTORCYCLE) then begin

                /*debug("Moto C1 " +
                (not(car_out_of_fuel) and (
                        (global_var(GVAR_VEHICLE_TOWN_MOTORCYCLE) != AREA_MOTORCYCLE_ABANDONED) and
                        not(abandoned_current_vehicle)
                        )
                    )
                )
                debug("Moto C2 " + (not(car_out_of_fuel) and (cur_town == car_current_town) and abandoned_current_vehicle))
                debug("Moto C3 " + (car_out_of_fuel and (cur_town == AREA_VEHICLE_OUTTA_GAS)))
                debug("Moto C4 " + (cur_town == AREA_MOTORCYCLE_ABANDONED))
                debug("Moto C5 " + (car_out_of_fuel and (car_current_town >= 0) and (car_current_town == cur_town)))
				*/

                if (
                    // we have fuel AND we didn't abandon it in desert or town
                    (not(car_out_of_fuel) and (global_var(GVAR_VEHICLE_TOWN_MOTORCYCLE) != AREA_MOTORCYCLE_ABANDONED) and not(abandoned_current_vehicle)) or
                    // we have fuel AND we're at the town where we abandoned it
                    (not(car_out_of_fuel) and (cur_town == car_current_town) and abandoned_current_vehicle) or
                    // we're on the "outta gas" area
                    (car_out_of_fuel and (cur_town == AREA_VEHICLE_OUTTA_GAS)) or
                    // we're at the area where we abandoned it
                    (cur_town == AREA_MOTORCYCLE_ABANDONED) or
                    // we ran out of fuel in this town while we were on a worldmap
                    (car_out_of_fuel and (car_current_town >= 0) and (car_current_town == cur_town))
                ) then begin
                    gen_motorcycle = 1;
                end
            end
            else begin
                if (
                    // we drove on something else but our motorcycle is here
                    (global_var(GVAR_VEHICLE_TOWN_MOTORCYCLE) == cur_town) or
                    // we abandoned the motorcycle here
                    (cur_town == AREA_MOTORCYCLE_ABANDONED)
                ) then begin
                    gen_motorcycle = 1;
                end
            end

            GetMotorcycleTileElev(tile, elev)

            // We drove in on a motorcycle OR we drove in on a different vehicle, but left the motorcycle here
            if (gen_motorcycle == 1) then begin
                Create_Motorcycle(tile, elev)
            end
        end

        // Dune Buggy

        if (dude_has_dune_buggy) then begin
            variable gen_dune_buggy;
            gen_dune_buggy = 0;

            if (current_vehicle_type == VEHICLE_TYPE_DUNE_BUGGY) then begin
                if (
                    // we have fuel AND we didn't abandon it in desert or town
                    (not(car_out_of_fuel) and (global_var(GVAR_VEHICLE_TOWN_DUNE_BUGGY) != AREA_DUNE_BUGGY_ABANDONED) and not(abandoned_current_vehicle)) or
                    // we have fuel AND we're at the town where we abandoned it
                    (not(car_out_of_fuel) and (cur_town == car_current_town) and abandoned_current_vehicle) or
                    // we're on the "outta gas" area
                    (car_out_of_fuel and (cur_town == AREA_VEHICLE_OUTTA_GAS)) or
                    // we're at the area where we abandoned it
                    (cur_town == AREA_DUNE_BUGGY_ABANDONED) or
                    // we ran out of fuel in this town while we were on a worldmap
                    (car_out_of_fuel and (car_current_town >= 0) and (car_current_town == cur_town))
                ) then begin
                    gen_dune_buggy = 1;
                end
            end
            else begin
                if (
                    // we drove on something else but our dune buggy is here
                    (global_var(GVAR_VEHICLE_TOWN_DUNE_BUGGY) == cur_town) or
                    // we abandoned the dune buggy here
                    (cur_town == AREA_DUNE_BUGGY_ABANDONED)
                )
                    then begin
                    gen_dune_buggy = 1;
                end
            end

            GetDuneBuggyTileElev(tile, elev)

            // We drove in on a dune buggy OR we drove in on a different vehicle, but left the dune buggy here
            if (gen_dune_buggy == 1) then begin
                Create_Dune_Buggy(tile, elev)
            end
        end

        // Cop Car

        if (dude_has_cop_car) then begin
            variable gen_cop_car;
            gen_cop_car = 0;

            if (current_vehicle_type == VEHICLE_TYPE_COP_CAR) then begin
                if (
                    // we have fuel AND we didn't abandon it in desert or town
                    (not(car_out_of_fuel) and (global_var(GVAR_VEHICLE_TOWN_COP_CAR) != AREA_COP_CAR_ABANDONED) and not(abandoned_current_vehicle)) or
                    // we have fuel AND we're at the town where we abandoned it
                    (not(car_out_of_fuel) and (cur_town == car_current_town) and abandoned_current_vehicle) or
                    // we're on the "outta gas" area
                    (car_out_of_fuel and (cur_town == AREA_VEHICLE_OUTTA_GAS)) or
                    // we're at the area where we abandoned it
                    (cur_town == AREA_COP_CAR_ABANDONED) or
                    // we ran out of fuel in this town while we were on a worldmap
                    (car_out_of_fuel and (car_current_town >= 0) and (car_current_town == cur_town))
                ) then begin
                    gen_cop_car = 1;
                end
            end
            else begin
                if (
                    // we drove on something else but our cop car is here
                    (global_var(GVAR_VEHICLE_TOWN_COP_CAR) == cur_town) or
                    // we abandoned the cop car here
                    (cur_town == AREA_COP_CAR_ABANDONED)
                    )
                then begin
                    gen_cop_car = 1;
                end
            end

            GetCopCarTileElev(tile, elev)

            // We drove in on a cop car OR we drove in on a different vehicle, but left the cop car here
            if (gen_cop_car == 1) then begin
                Create_Cop_Car(tile, elev)
            end
        end

        // Semi-Truck

        if (dude_has_semi_truck) then begin
            variable gen_semi_truck;
            gen_semi_truck = 0;

            if (current_vehicle_type == VEHICLE_TYPE_SEMI_TRUCK) then begin

                /*debug("Semi C1 " + ((not(car_out_of_fuel) and (global_var(GVAR_VEHICLE_TOWN_SEMI_TRUCK) != AREA_SEMI_TRUCK_ABANDONED)) and not(abandoned_current_vehicle)))
                debug("Semi C2 " + (not(car_out_of_fuel) and (cur_town == car_current_town) and abandoned_current_vehicle))
                debug("Semi C3 " + (car_out_of_fuel and (cur_town == AREA_VEHICLE_OUTTA_GAS)))
                debug("Semi C4 " + (cur_town == AREA_SEMI_TRUCK_ABANDONED))
                debug("Semi C5 " + (car_out_of_fuel and (car_current_town >= 0) and (car_current_town == cur_town)))*/

                if (
                    // we have fuel AND we didn't abandon it in desert or town
                    (not(car_out_of_fuel) and (global_var(GVAR_VEHICLE_TOWN_SEMI_TRUCK) != AREA_SEMI_TRUCK_ABANDONED) and not(abandoned_current_vehicle)) or
                    // we have fuel AND we're at the town where we abandoned it
                    (not(car_out_of_fuel) and (cur_town == car_current_town) and abandoned_current_vehicle) or
                    // we're on the "outta gas" area
                    (car_out_of_fuel and (cur_town == AREA_VEHICLE_OUTTA_GAS)) or
                    // we're at the area where we abandoned it
                    (cur_town == AREA_SEMI_TRUCK_ABANDONED) or
                    // we ran out of fuel in this town while we were on a worldmap
                    (car_out_of_fuel and (car_current_town >= 0) and (car_current_town == cur_town))
                ) then begin
                    gen_semi_truck = 1;
                end
            end
            else begin
                //debug("SEMI AT " + global_var(GVAR_VEHICLE_TOWN_SEMI_TRUCK) + " WHILE CURRENT IS " + cur_town)
                // we drove on something else but our semi truck is here
                if (
                    (global_var(GVAR_VEHICLE_TOWN_SEMI_TRUCK) == cur_town) or
                    // we abandoned the semi-truck here
                    (cur_town == AREA_SEMI_TRUCK_ABANDONED)
                    ) then begin
                    gen_semi_truck = 1;
                end
            end

            GetSemiTruckTileElev(tile, elev)

            // We drove in on a semi-truck OR we drove in on a different vehicle, but left the semi-truck here
            if (gen_semi_truck == 1) then begin
                Create_Semi_Truck(tile, elev)
            end
        end

        // Highwayman

        if (dude_has_car) then begin
            variable gen_car;
            gen_car = 0;

            if (current_vehicle_type == VEHICLE_TYPE_HIGHWAYMAN) then begin
                if (
                    // we have fuel AND we didn't abandon it in desert or town
                    (not(car_out_of_fuel) and (global_var(GVAR_VEHICLE_TOWN_HIGHWAYMAN) != AREA_HIGHWAYMAN_ABANDONED) and not(abandoned_current_vehicle)) or
                    // we have fuel AND we're at the town where we abandoned it
                    (not(car_out_of_fuel) and (cur_town == car_current_town) and abandoned_current_vehicle) or
                    // we're on the "outta gas" area
                    (car_out_of_fuel and (cur_town == AREA_VEHICLE_OUTTA_GAS)) or
                    // we're at the area where we abandoned it
                    (cur_town == AREA_HIGHWAYMAN_ABANDONED) or
                    // we ran out of fuel in this town while we were on a worldmap
                    (car_out_of_fuel and (car_current_town >= 0) and (car_current_town == cur_town))
                ) then begin
                    gen_car = 1;
                end
            end
            else begin
                // we drove on something else but our car is here
                if (
                    (global_var(GVAR_VEHICLE_TOWN_HIGHWAYMAN) == cur_town) or
                    // we abandoned the car here
                    (cur_town == AREA_HIGHWAYMAN_ABANDONED)
                    ) then begin
                    gen_car = 1;
                end
            end

            GetCarTileElev(tile, elev)

            // We drove in on a car OR we drove in on a different vehicle, but left the car here
            if (gen_car == 1) then begin
                Create_Car(tile, elev)
            end
        end

        // Bicycle

        if (dude_has_bicycle) then begin
            variable gen_bicycle;
            gen_bicycle = 0;

            if (current_vehicle_type == VEHICLE_TYPE_BICYCLE) then begin
                if (
                    // we have fuel AND we didn't abandon it in desert or town
                    (not(car_out_of_fuel) and (global_var(GVAR_VEHICLE_TOWN_BICYCLE) != AREA_BICYCLE_ABANDONED) and not(abandoned_current_vehicle)) or
                    // we have fuel AND we're at the town where we abandoned it
                    (not(car_out_of_fuel) and (cur_town == car_current_town) and abandoned_current_vehicle) or
                    // we're on the "outta gas" area
                    (car_out_of_fuel and (cur_town == AREA_VEHICLE_OUTTA_GAS)) or
                    // we're at the area where we abandoned it
                    (cur_town == AREA_BICYCLE_ABANDONED) or
                    // we ran out of fuel in this town while we were on a worldmap
                    (car_out_of_fuel and (car_current_town >= 0) and (car_current_town == cur_town))
                ) then begin
                    gen_bicycle = 1;
                end
            end
            else begin
                // we drove on something else but our bicycle is here
                if (
                    (global_var(GVAR_VEHICLE_TOWN_BICYCLE) == cur_town) or
                    // we abandoned the bicycle here
                    (cur_town == AREA_BICYCLE_ABANDONED)
                    ) then begin
                    gen_bicycle = 1;
                end
            end

            GetBicycleTileElev(tile, elev)

            // We drove in on a bicycle OR we drove in on a different vehicle, but left the bicycle here
            if (gen_bicycle == 1) then begin
                Create_Bicycle(tile, elev)
            end
        end
    end else begin
        //debug("Can't place the vehicle, the game's loading")
    end
end

// Refuel is incremental because we have no idea if the player wants to refuel 100% or less
procedure Refuel(variable fuel) begin
    variable energy_density, capacity, pid, multiplier, pct_before, pct_after, dude_total_fuel, dude_retain_fuel;
    energy_density = 0;
    pid = obj_pid(fuel);

    if (pid == PID_SMALL_ENERGY_CELL) then begin
        energy_density = 16000;
        capacity = 40;
        multiplier = 2;
    end
    else if (pid == PID_MICRO_FUSION_CELL) then begin
        energy_density = 40000;
        capacity = 50;
        multiplier = 1;
    end

    if (energy_density > 0) then begin
        dude_total_fuel = get_weapon_ammo_count(fuel);
        // refueling the current vehicle
        if ((current_vehicle_type != 0) and (current_vehicle_type == SelfVehicleType)) then begin
            if (car_gas_amount < max_gas_amount) then begin
                pct_before = gas_pct(car_gas_amount);
                car_give_gas((dude_total_fuel * energy_density) / capacity);
                // lower the amount of fuel inside the inventory
                pct_after = gas_pct(car_gas_amount);
                dude_retain_fuel = (dude_total_fuel - ((pct_after - pct_before) * multiplier));

                if (dude_retain_fuel >= 1) then begin
                    set_weapon_ammo_count(fuel, dude_retain_fuel);
                end else begin
                    remove_pid_qty(dude_obj, pid, 1)
                end

                display_msg(mstr_proto(595) + VehicleName(SelfVehicleType) + mstr_proto(598));
            end else begin
                display_msg(mstr_proto(596) + VehicleName(SelfVehicleType) + mstr_proto(599));
            end
        end
        // refueling a non-current vehicle
        else begin
            variable gas_gvar;
            gas_gvar = SelfGasAmountGVar;

            if (global_var(gas_gvar) < max_gas_amount) then begin
                pct_before = gas_pct(global_var(gas_gvar));
                inc_global_var_amt(gas_gvar, (dude_total_fuel * energy_density) / capacity);
                // lower the amount of fuel inside the inventory
                pct_after = gas_pct(global_var(gas_gvar));
                dude_retain_fuel = (dude_total_fuel - ((pct_after - pct_before) * multiplier));

                if (dude_retain_fuel >= 1) then begin
                    set_weapon_ammo_count(fuel, dude_retain_fuel);
                end else begin
                    remove_pid_qty(dude_obj, pid, 1)
                end

                display_msg(mstr_proto(595) + VehicleName(SelfVehicleType) + mstr_proto(598));
            end else begin
                display_msg(mstr_proto(596) + VehicleName(SelfVehicleType) + mstr_proto(599));
            end
        end
    end
end

procedure DestroyVehicle(variable type) begin
    if (type == VEHICLE_TYPE_MOTORCYCLE) then begin
        Destroy_Motorcycle(self_tile, self_elevation)
    end
    else if (type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        Destroy_Dune_Buggy(self_tile, self_elevation)
    end
    else if (type == VEHICLE_TYPE_COP_CAR) then begin
        Destroy_Cop_Car(self_tile, self_elevation)
    end
    else if (type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        Destroy_Semi_Truck(self_tile, self_elevation)
    end
    //else if (type == VEHICLE_TYPE_TRAIN) then begin
    //end
    else if (type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        Destroy_Car(self_tile, self_elevation)
    end
    else if (type == VEHICLE_TYPE_BICYCLE) then begin
        Destroy_Bicycle(self_tile, self_elevation)
    end
end

procedure AbandonCurrentVehicle(variable on_world_map) begin
    variable vehicle_area, town_gvar, gas_gvar;
    // We need to mark the abandoned area on the world map
    if (on_world_map) then begin
        vehicle_area = VehicleAbandonedArea(current_vehicle_type);
        //debug("setting vehicle WM area for " + current_vehicle_type)
        wm_area_set_pos(vehicle_area, global_var(GVAR_VEHICLE_LAST_X), global_var(GVAR_VEHICLE_LAST_Y));
        mark_on_map(vehicle_area)
        set_car_current_town(vehicle_area);
    end else begin
        // We're abandoning in a town, just save the current vehicle's town
        vehicle_area = car_current_town;
    end

    if (current_vehicle_type == VEHICLE_TYPE_MOTORCYCLE) then begin
        town_gvar = GVAR_VEHICLE_TOWN_MOTORCYCLE;
        gas_gvar = GVAR_VEHICLE_GAS_MOTORCYCLE;
    end
    else if (current_vehicle_type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        town_gvar = GVAR_VEHICLE_TOWN_DUNE_BUGGY;
        gas_gvar = GVAR_VEHICLE_GAS_DUNE_BUGGY;
    end
    else if (current_vehicle_type == VEHICLE_TYPE_COP_CAR) then begin
        town_gvar = GVAR_VEHICLE_TOWN_COP_CAR;
        gas_gvar = GVAR_VEHICLE_GAS_COP_CAR;
    end
    else if (current_vehicle_type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        town_gvar = GVAR_VEHICLE_TOWN_SEMI_TRUCK;
        gas_gvar = GVAR_VEHICLE_GAS_SEMI_TRUCK;
    end
    else if (current_vehicle_type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        town_gvar = GVAR_VEHICLE_TOWN_HIGHWAYMAN;
        gas_gvar = GVAR_VEHICLE_GAS_HIGHWAYMAN;
    end
    else if (current_vehicle_type == VEHICLE_TYPE_TRAIN) then begin
        town_gvar = GVAR_VEHICLE_TOWN_TRAIN;
        gas_gvar = GVAR_VEHICLE_GAS_TRAIN;
    end
    else if (current_vehicle_type == VEHICLE_TYPE_BICYCLE) then begin
        town_gvar = GVAR_VEHICLE_TOWN_BICYCLE;
        gas_gvar = GVAR_VEHICLE_GAS_BICYCLE;
    end

    set_global_var(town_gvar, vehicle_area);

    // Workaround for an engine bug where your vehicle is still used on a world map after abandoning it on a random encounter map
    if (on_world_map) then begin
        variable current_gas, pid, recovered_fuel_amount, recovered_fuel_obj, multiplier;
        current_gas = car_gas_amount;

        // Recover gas as an inventory item to keep the later logic simpler and also allow the player to reuse vehicle's fuel as ammo
        pid = pick_one(PID_SMALL_ENERGY_CELL, PID_MICRO_FUSION_CELL);
        if (pid == PID_SMALL_ENERGY_CELL) then begin
            multiplier = 2;
        end else if (pid == PID_MICRO_FUSION_CELL) then begin
            multiplier = 1;
        end

        recovered_fuel_amount = (gas_pct(current_gas) * multiplier);

        if (recovered_fuel_amount > 0) then begin
            call GiveFuelBrick(pid, recovered_fuel_amount);
            display_msg(g_mstr(1116) + " " + VehicleName(current_vehicle_type) + ".");
            // Set gas GVAR to 0
            set_global_var(gas_gvar, 0);
            // Bye, bye phantom vehicle
            car_give_gas(-current_gas);
        end
    end
end

procedure RecoverVehicle(variable type) begin
    variable vehicle_area, town_gvar;

    remove_from_map(VehicleAbandonedArea(type))
    set_car_current_town(-1);

    if (type == VEHICLE_TYPE_MOTORCYCLE) then begin
        town_gvar = GVAR_VEHICLE_TOWN_MOTORCYCLE;
    end
    else if (type == VEHICLE_TYPE_DUNE_BUGGY) then begin
        town_gvar = GVAR_VEHICLE_TOWN_DUNE_BUGGY;
    end
    else if (type == VEHICLE_TYPE_COP_CAR) then begin
        town_gvar = GVAR_VEHICLE_TOWN_COP_CAR;
    end
    else if (type == VEHICLE_TYPE_SEMI_TRUCK) then begin
        town_gvar = GVAR_VEHICLE_TOWN_SEMI_TRUCK;
    end
    else if (type == VEHICLE_TYPE_HIGHWAYMAN) then begin
        town_gvar = GVAR_VEHICLE_TOWN_HIGHWAYMAN;
    end
    else if (type == VEHICLE_TYPE_TRAIN) then begin
        town_gvar = GVAR_VEHICLE_TOWN_TRAIN;
    end
    else if (type == VEHICLE_TYPE_BICYCLE) then begin
        town_gvar = GVAR_VEHICLE_TOWN_BICYCLE;
    end

    set_global_var(town_gvar, -1);
end

procedure Check_Create_Trunk begin

    variable ptr, visibility_gvar;

    if (self_is_dune_buggy_trunk) then begin
        ptr = DuneBuggyTrunk_Ptr;
        visibility_gvar = GVAR_SHOW_DUNE_BUGGY_TRUNK;
    end
    else if (self_is_cop_car_trunk) then begin
        ptr = CopTrunk_Ptr;
        visibility_gvar = GVAR_SHOW_COP_CAR_TRUNK;
    end
    else if (self_is_semi_truck_trunk) then begin
        ptr = SemiTruckTrunk_Ptr;
        visibility_gvar = GVAR_SHOW_SEMI_TRUCK_TRUNK;
    end
    else if (self_is_train_trunk) then begin
        ptr = TrainTrunk_Ptr;
        visibility_gvar = GVAR_SHOW_TRAIN_TRUNK;
    end
    else if (self_is_car_trunk) then begin
        ptr = Trunk_Ptr;
        visibility_gvar = GVAR_SHOW_HIGHWAYMAN_TRUNK;
    end
    else begin
        ptr = 0;
        visibility_gvar = -1;
    end

    if (ptr != 0) then begin
        if (global_var(visibility_gvar) == 0) then begin
           //debug("hiding trunk pid " + obj_pid(ptr))
           check_set_obj_visibility(self_obj, true);
        end
        else begin
           //debug("displaying trunk pid " + obj_pid(ptr))
           check_set_obj_visibility(self_obj, false);
        end
     end else begin
        //debug("Adding trunk to party pid " + obj_pid(self_obj))
        party_add(self_obj);
     end

end

procedure CheckOuttaGasOnTown begin

    variable visible_outta_gas, visible_abandoned_vehicle;
    visible_outta_gas = town_visible_on_map(AREA_VEHICLE_OUTTA_GAS);
    // It shouldn't be possible for the player to abandon the current vehicle on a town circle but stranger things have happened. Just in case
    visible_abandoned_vehicle = town_visible_on_map(VehicleAbandonedArea(current_vehicle_type));

    if (visible_outta_gas or visible_abandoned_vehicle) then begin
        variable my_new_town, vehicle_x, vehicle_y;
        my_new_town = -1;
        // Where was the current vehicle last spotted?
        vehicle_x = global_var(GVAR_VEHICLE_LAST_X);
        vehicle_y = global_var(GVAR_VEHICLE_LAST_Y);

        // First, sort out the Large town circles

        // Tibbets
        if ((vehicle_x > 1550) and (vehicle_x <= (1150 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 2000) and (vehicle_y <= (2000 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_TIBBETS);
        end
        // Boulder Dome
        else if ((vehicle_x > 2850) and (vehicle_x <= (2850 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 750) and (vehicle_y <= (750 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_TIBBETS);
        end
        // Dogtown
        else if ((vehicle_x > 3000) and (vehicle_x <= (3000 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 1000) and (vehicle_y <= (1000 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_DOGTOWN);
        end
        // Blackfoot
        else if ((vehicle_x > 1400) and (vehicle_x <= (1400 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 1600) and (vehicle_y <= (1600 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_BLACKFOOT);
        end
        // Mesa Verde
        else if ((vehicle_x > 2250) and (vehicle_x <= (2250 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 1850) and (vehicle_y <= (1850 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_MESA_VERDE);
        end
        // Hoover Dam
        else if ((vehicle_x > 150) and (vehicle_x <= (150 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 2050) and (vehicle_y <= (2050 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_HOOVER_DAM);
        end
        // Ouroboros
        else if ((vehicle_x > 1800) and (vehicle_x <= (1800 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 1150) and (vehicle_y <= (1150 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_HOOVER_DAM);
        end
        // The Reservation
        else if ((vehicle_x > 2650) and (vehicle_x <= (2650 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 2250) and (vehicle_y <= (2250 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_THE_RESERVATION);
        end
        // The Nursery
        else if ((vehicle_x > 2100) and (vehicle_x <= (2100 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 900) and (vehicle_y <= (900 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_THE_NURSERY);
        end
        // Bloomfield
        else if ((vehicle_x > 450) and (vehicle_x <= (450 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 2750) and (vehicle_y <= (2750 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_BLOOMFIELD);
        end
        // The Grand Canyon
        else if ((vehicle_x > 950) and (vehicle_x <= (950 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 2000) and (vehicle_y <= (2000 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AREA_THE_GRAND_CANYON;
        end
        // Jericho
        else if ((vehicle_x > 1200) and (vehicle_x <= (1200 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 300) and (vehicle_y <= (300 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AreaNukeStatus(AREA_JERICHO);
        end
         // The Crater
         else if ((vehicle_x > 3000) and (vehicle_x <= (3000 + TOWN_CIRCLE_LARGE)) and (vehicle_y > 1350) and (vehicle_y <= (1350 + TOWN_CIRCLE_LARGE))) then begin
            my_new_town = AREA_THE_CRATER;
        end

        // Second, sort out the Medium ones

        // Circle Junction
        else if ((vehicle_x > 1762) and (vehicle_x <= (1762 + TOWN_CIRCLE_MEDIUM)) and (vehicle_y > 1861) and (vehicle_y <= (1861 + TOWN_CIRCLE_MEDIUM))) then begin
            my_new_town = AreaNukeStatus(AREA_CIRCLE_JUNCTION);
        end
        // Fort Abandon
        // TODO fix this later when we change the circle to Small and swap with Fort Damnation
        else if ((vehicle_x > 1662) and (vehicle_x <= (1662 + TOWN_CIRCLE_MEDIUM)) and (vehicle_y > 1911) and (vehicle_y <= (1911 + TOWN_CIRCLE_MEDIUM))) then begin
            my_new_town = AreaNukeStatus(AREA_FORT_ABANDON);
        end
        // Twin Mothers
        else if ((vehicle_x > 2612) and (vehicle_x <= (2612 + TOWN_CIRCLE_MEDIUM)) and (vehicle_y > 1811) and (vehicle_y <= (1811 + TOWN_CIRCLE_MEDIUM))) then begin
            my_new_town = AreaNukeStatus(AREA_TWIN_MOTHERS);
        end
        // Brotherhood of Steel
        else if ((vehicle_x > 1362) and (vehicle_x <= (1362 + TOWN_CIRCLE_MEDIUM)) and (vehicle_y > 2311) and (vehicle_y <= (2311 + TOWN_CIRCLE_MEDIUM))) then begin
            my_new_town = AreaNukeStatus(AREA_BROTHERHOOD_OF_STEEL);
        end
        // Burham Springs
        else if ((vehicle_x > 1512) and (vehicle_x <= (1512 + TOWN_CIRCLE_MEDIUM)) and (vehicle_y > 1011) and (vehicle_y <= (1011 + TOWN_CIRCLE_MEDIUM))) then begin
            my_new_town = AreaNukeStatus(AREA_BURHAM_SPRINGS);
        end
        // New Canaan
        else if ((vehicle_x > 1162) and (vehicle_x <= (1162 + TOWN_CIRCLE_MEDIUM)) and (vehicle_y > 261) and (vehicle_y <= (261 + TOWN_CIRCLE_MEDIUM))) then begin
            my_new_town = AreaNukeStatus(AREA_NEW_CANAAN);
        end
        // Moletown
        else if ((vehicle_x > 2212) and (vehicle_x <= (2212 + TOWN_CIRCLE_MEDIUM)) and (vehicle_y > 2511) and (vehicle_y <= (2511 + TOWN_CIRCLE_MEDIUM))) then begin
            my_new_town = AREA_MOLETOWN;
        end
        // VACCS
        else if ((vehicle_x > 62) and (vehicle_x <= (62 + TOWN_CIRCLE_MEDIUM)) and (vehicle_y > 61) and (vehicle_y <= (61 + TOWN_CIRCLE_MEDIUM))) then begin
            my_new_town = AREA_VACCS;
        end

        // Finally, the small town circles
        // Not actually tested but in theory, there is a tiny chance for small circles to 100% overlap; if you click exactly on the middle pixel and the vehicle runs out of gas on that pixel
        // Note: We can't cover special encounters since their coordinates are randomly determined., In that case, loading a save game is the only solution

        // Hangdogs
        else if ((vehicle_x > 3289) and (vehicle_x <= (3289 + TOWN_CIRCLE_SMALL)) and (vehicle_y > 877) and (vehicle_y <= (877 + TOWN_CIRCLE_SMALL))) then begin
            my_new_town = AREA_HANGDOGS;
        end
        // Fort Desolation
        else if ((vehicle_x > 141) and (vehicle_x <= (141 + TOWN_CIRCLE_SMALL)) and (vehicle_y > 1981) and (vehicle_y <= (1981 + TOWN_CIRCLE_SMALL))) then begin
            my_new_town = AREA_FORT_DESOLATION;
        end
        // Landing Site
        else if ((vehicle_x > 109) and (vehicle_x <= (109 + TOWN_CIRCLE_SMALL)) and (vehicle_y > 339) and (vehicle_y <= (339 + TOWN_CIRCLE_SMALL))) then begin
            my_new_town = AREA_LANDING_SITE;
        end
        // Circle of Steel
        else if ((vehicle_x > 1829) and (vehicle_x <= (1829 + TOWN_CIRCLE_SMALL)) and (vehicle_y > 2577) and (vehicle_y <= (2577 + TOWN_CIRCLE_SMALL))) then begin
            my_new_town = AREA_CIRCLE_OF_STEEL;
        end

         // Need to change our town if it's visible
         if ((my_new_town != -1) and town_visible_on_map(my_new_town)) then begin
            //debug("FIXING VEHICLE OUTTA GAS")

            set_car_current_town(my_new_town);
            call AbandonCurrentVehicle(false);
            set_global_var(GVAR_ABANDONED_CURRENT_VEHICLE, 1);
            // Hide the "outta gas" circle
            if (visible_outta_gas) then begin
                remove_from_map(AREA_VEHICLE_OUTTA_GAS)
            end
            // Hide the "abandoned" circle
            else if (visible_abandoned_vehicle) then begin
                remove_from_map(VehicleAbandonedArea(current_vehicle_type))
            end
         end

     end
end

procedure GiveFuelBrick(variable pid, variable fuel_amount) begin
    variable capacity, temp;

    if (pid == PID_SMALL_ENERGY_CELL) then begin
        capacity = 40;
    end else if (pid == PID_MICRO_FUSION_CELL) then begin
        capacity = 50;
    end

    while (fuel_amount > 0) do begin
        // give a full brick
        if (fuel_amount >= capacity) then begin
            give_pid_qty(dude_obj, pid, 1)
        end
        // this one's not full
        else begin
            temp := create_object(pid, 0, 0);
            set_weapon_ammo_count(temp, fuel_amount);
            add_obj_to_inven(dude_obj, temp);
        end
        fuel_amount -= capacity;
    end
end

#endif // VEHICLES_H
