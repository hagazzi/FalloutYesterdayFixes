#ifndef TRAITS_H
#define TRAITS_H

procedure CountTotalKills begin
    variable kill_type, kills_total;
    kill_type = 0;

    // Rabid Trait total kills counter from kill type 0 to 17
    while (kill_type <= 17) do begin
        kills_total += get_kill_counter(kill_type);
        kill_type ++;
    end

    return kills_total;
end

procedure day_person begin
    if (global_var(GVAR_DAY_PERSON) > 0) then begin
       // 6PM - 6AM
        if ((global_var(GVAR_DAY_PERSON) == 1) and (morning or day)) then begin
            call set_dude_attr(STAT_pe, get_pc_base_stat(STAT_pe) + 2);
            call set_dude_attr(STAT_iq, get_pc_base_stat(STAT_iq) + 2);
            set_global_var(GVAR_DAY_PERSON, 2);
        end
        // 6AM - 6PM
        else if ((global_var(GVAR_DAY_PERSON) == 2) and (evening or night)) then begin
            call set_dude_attr(STAT_pe, get_pc_base_stat(STAT_pe) - 2);
            call set_dude_attr(STAT_iq, get_pc_base_stat(STAT_iq) - 2);
            set_global_var(GVAR_DAY_PERSON, 1);
        end
    end
 end

#endif // TRAITS_H
