#ifndef PERKS_H
#define PERKS_H

procedure add_grace_under_fire_bonus begin
    critter_mod_skill(dude_obj, SKILL_SMALL_GUNS, 15);
    critter_mod_skill(dude_obj, SKILL_BIG_GUNS, 15);
    critter_mod_skill(dude_obj, SKILL_ENERGY_WEAPONS, 15);
    critter_mod_skill(dude_obj, SKILL_THROWING, 15);
    call set_dude_attr(STAT_pe, get_pc_base_stat(STAT_pe) + 1);
    set_global_var(GVAR_TRAIT_GRACE_UNDER_FIRE_BONUS, 1);
end

procedure remove_grace_under_fire_bonus begin
    critter_mod_skill(dude_obj, SKILL_SMALL_GUNS, -15);
    critter_mod_skill(dude_obj, SKILL_BIG_GUNS, -15);
    critter_mod_skill(dude_obj, SKILL_ENERGY_WEAPONS, -15);
    critter_mod_skill(dude_obj, SKILL_THROWING, -15);
    call set_dude_attr(STAT_pe, get_pc_base_stat(STAT_pe) - 1);
    set_global_var(GVAR_TRAIT_GRACE_UNDER_FIRE_BONUS, 0);
end

procedure Check_Set_Grace_Under_Fire begin
    if (combat_is_initialized) then begin
        variable dude_hp_pct = (get_critter_stat(dude_obj, STAT_current_hp) / (get_critter_stat(dude_obj, STAT_max_hit_points) / 100));

        if ((global_var(GVAR_TRAIT_GRACE_UNDER_FIRE_BONUS) == 0) and (dude_hp_pct < 40)) then begin
            call add_grace_under_fire_bonus;
        end
        else if ((global_var(GVAR_TRAIT_GRACE_UNDER_FIRE_BONUS) == 1) and (dude_hp_pct >= 40)) then begin
            call remove_grace_under_fire_bonus;
        end
    end
end

#endif // PERKS_H
