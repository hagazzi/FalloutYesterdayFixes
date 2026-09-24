#define GAME_MSG_MR_FIXIT       (0x2000)

procedure atoim(variable ostr, variable bstr) begin
    variable begin
        i;
        str;
        val;
    end
    str:=bstr;
    while (ostr!=str and ostr<=str+":" and ostr>=str+"0") do begin
        while not((ostr>str+i and ostr<str+(i+1)) or ostr==str+i) and i<9 do i+=1;
        str+=i; val:=val*10+i; i:=0;
    end
    return val;
end

#define atoi(x) atoim(x,"")

#define var variable

#define charv(x,y)  else if ostr>=str+x and ostr<str+y then return x
#define charv_(x,y) if ostr>=str+x and ostr<str+y then return x
#define cmp(x)      if ostr<str+x then begin

procedure get_char(var ostr, var str) begin
    if ostr==str then return "";

    cmp("A")
        cmp("1")
            cmp(")")
                cmp("%")
                    cmp("#")
                        charv_(" ","!");
                        charv("!","\"");
                        charv("\"","#");
                    end else begin
                        charv_("#","$");
                        charv("$","%");
                    end
                end else begin
                    charv_("%","&");
                    charv("&","'");
                    charv("'","(");
                    charv("(",")");
                end
            end else cmp("-")
                charv_(")","*");
                charv("*","+");
                charv("+",",");
                charv(",","-");
            end else begin
                charv_("-",".");
                charv(".","/");
                charv("/","0");
                charv("0","1");
            end
        end else cmp("9")
            cmp("5")
                cmp("3")
                    charv_("1","2");
                    charv("2","3");
                end else begin
                    charv_("3","4");
                    charv("4","5");
                end
            end else cmp("7")
                charv_("5","6");
                charv("6","7");
            end else begin
                charv_("7","8");
                charv("8","9");
            end
        end else cmp("=")
            cmp(";")
                charv_("9",":");
                charv(":",";");
            end else begin
                charv_(";","<");
                charv("<","=");
            end
        end else cmp("?")
            charv_("=",">");
            charv(">","?");
        end else begin
            charv_("?","@");
            charv("@","A");
        end
    end else cmp("a")
        cmp("Q")
            cmp("I")
                cmp("E")
                    cmp("C")
                        charv_("A","B");
                        charv("B","C");
                    end else begin
                        charv_("C","D");
                        charv("D","E");
                    end
                end else cmp("G")
                    charv_("E","F");
                    charv("F","G");
                end else begin
                    charv_("G","H");
                    charv("H","I");
                end
            end else cmp("M")
                cmp("K")
                    charv_("I","J");
                    charv("J","K");
                end else begin
                    charv_("K","L");
                    charv("L","M");
                end
            end else cmp("O")
                charv_("M","N");
                charv("N","O");
            end else begin
                charv_("O","P");
                charv("P","Q");
            end
        end else cmp("Y")
            cmp("U")
                cmp("S")
                    charv_("Q","R");
                    charv("R","S");
                end else begin
                    charv_("S","T");
                    charv("T","U");
                end
            end else cmp("W")
                charv_("U","V");
                charv("V","W");
            end else begin
                charv_("W","X");
                charv("X","Y");
            end
        end else cmp("]")
            cmp("[")
                charv_("Y","Z");
                charv("Z","[");
            end else begin
                charv_("[","\\");
                charv("\\","]");
            end
        end else cmp("_")
            charv_("]","^");
            charv("^","_");
        end else begin
            charv_("_","`");
            charv("`","a");
        end
    end else cmp("q")
        cmp("i")
            cmp("e")
                cmp("c")
                    charv_("a","b");
                    charv("b","c");
                end else begin
                    charv_("c","d");
                    charv("d","e");
                end
            end else cmp("g")
                charv_("e","f");
                charv("f","g");
            end else begin
                charv_("g","h");
                charv("h","i");
            end
        end else cmp("m")
            cmp("k")
                charv_("i","j");
                charv("j","k");
            end else begin
                charv_("k","l");
                charv("l","m");
            end
        end else cmp("o")
            charv_("m","n");
            charv("n","o");
        end else begin
            charv_("o","p");
            charv("p","q");
        end
    end else cmp("y")
        cmp("u")
            cmp("s")
                charv_("q","r");
                charv("r","s");
            end else begin
                charv_("s","t");
                charv("t","u");
            end
        end else cmp("w")
            charv_("u","v");
            charv("v","w");
        end else begin
            charv_("w","x");
            charv("x","y");
        end
    end else cmp("{")
        charv_("y","z");
        charv("z","{");
    end else begin
        charv_("{","|");
        charv("|","}");
        charv("}","~");
    end
    return "";
end


procedure wordar(var word, var cell) begin
    var rstr:=""; var str:=""; var c_cell; var tmp;

    while c_cell<cell do begin
        tmp:=get_char(word,str);
        if tmp=="" then return "";
        else begin
            if tmp=="|" then c_cell+=1;
            str+=tmp;
        end
    end

    while 1 do begin
        tmp:=get_char(word,str);
        if tmp=="" or tmp=="|" then return rstr;
        else begin
            rstr+=tmp;
            str+=tmp;
        end
    end

    return "";
end

#define SECTION_START           (500)
#define SECTION_STEP            (25)

#define ITEM_ITEM               "[ITEM]"
#define ITEM_TOOLS              "[TOOLS]"
#define ITEM_SKILLS             "[SKILLS]"
#define ITEM_COMPONENTS         "[COMPONENTS]"

#define ITEM_PID                (1)
#define ITEM_PCX                (2)
#define ITEM_SIZE               (3)
#define ITEM_GVAR               (4)
#define ITEM_TIME               (5)
#define ITEM_UNDO               (6)
#define PARSER_START            (7)

#define ITEMS_PER_SCREEN        (7)

#define WIN_CRAFT_BTN         "helwin"
#define SFX_BUTTON_DOWN       "ib2p1xx1"
#define SFX_BUTTON_UP         "ib2lu1x1"
#define SFX_ERROR             "IISXXXX1"
#define PCX_BUTTON_DOWN       "PCX/MRFDN.PCX"
#define PCX_BUTTON_UP         "PCX/MRFUP.PCX"
#define BUTTON_WIDTH          (19)
#define BUTTON_HEIGHT         (56)
#define BUTTON_BOTTOM_OFFSET  (62)
#define BUTTON_RIGHT_OFFSET   (399)
#define BUTTON_CLICK_LEFT_OFFSET  (2)

variable begin
    mode;

    cur_section_start;
    cur_pos;

    cur_pid;
    cur_pcx;
    cur_size;
    cur_gvar;
    cur_time;
    cur_undo;

    items_avail;
    max;
    max_undo;

    can_batch;
    can_undo;

    start0;
    start1;
    start2;
    start3;
    start4;
    start5;
    start6;

    mrfixit_talk;

    win_x := 0;
    win_y := 0;

    crafting_button_top;

    button_x;
    button_y;
    button_global_x;
    button_global_y;

    button_pressed;

end

#define bstr(x)                 (message_str_game(GAME_MSG_MR_FIXIT, x))
#define field(x)                bstr(cur_section_start + x)
#define skill_name(x)           bstr(1 + x)
#define skill_def(x)            bstr(19 + x)

procedure item_options_0;
procedure item_options_1;
procedure item_options_2;
procedure item_options_3;
procedure item_options_4;
procedure item_options_5;
procedure item_options_6;
procedure display_next_option(variable i);

procedure count_items_avail;
procedure draw_item_properties;
procedure draw_item_pcx;
procedure parse_skill_name(variable s_name);

procedure display_items_list;
procedure display_items_avail;
procedure mf_list_next;
procedure mf_list_back;
procedure display_item_options;
procedure display_batch_ok;
procedure display_undo_ok;

procedure exit_mode;
procedure items_list_mode;
procedure item_options_mode;
procedure batch_ok_mode;
procedure undo_ok_mode;

procedure batch_item(variable num);
procedure undo_batch(variable num);
procedure batch_one_item;
procedure batch_all_items;
procedure undo_one_item;
procedure undo_all_items;

procedure loop_mode;

procedure create_button;
procedure delete_button;

/******************************************************************************/

procedure batch_init begin
    stop_game;
    mode := 1;
    cur_section_start := SECTION_START;
    cur_pos := 0;
    call count_items_avail;

    win_x := (get_screen_width - 640) / 2;
    win_y := (get_screen_height - 380) / 2;
    if (win_y > 100) then win_y := 100; // for some reason, SayOptionWindow can't be lowered after certain Y coordinate

    SetFont(5);
    SetTextColor(0.0, 1.0, 0.0);
    SetHighlightColor(1.0, 1.0, 1.0);
    SetHighlightColor(1.0, 1.0, 0.64);

    SayReplyWindow (win_x + 300, win_y + 1, 340, 179, "PCX/w_rep.pcx");
    SayOptionWindow(win_x + 300, win_y + 180, 340, 199, "PCX/w_opt.pcx");
    SayBorder(25, 25);

    create_win_flag("win_dscr", win_x + 1, win_y + 1, 300, 378, WIN_FLAG_EXCLUSIVE);
    SelectWin("win_dscr");
    Display("PCX/w_dscr.pcx");
    ShowWin;

    call loop_mode;

    DeleteWin("win_dscr");

    resume_game;
end

procedure count_items_avail begin
    variable backup;
    backup := cur_section_start;
    cur_section_start := SECTION_START;
    items_avail := 0;
    while (bstr(cur_section_start) != "Error" and bstr(cur_section_start) == ITEM_ITEM) do begin
        cur_gvar := atoi(field(ITEM_GVAR));
        if (field(ITEM_GVAR) == "" or global_var(cur_gvar)) then items_avail += 1;
        cur_section_start += SECTION_STEP;
    end
    cur_section_start := backup;
end

procedure loop_mode begin
    while (mode != -1) do begin
        if (mode == 1)      then call display_items_list;
        else if (mode == 2) then call display_item_options;
        else if (mode == 3) then call display_batch_ok;
        else if (mode == 4) then call display_undo_ok;
    end
end

procedure exit_mode begin
    variable rnd, sfx;
    mode := -1;
    mrfixit_talk := 0;
    rnd := random(1, 2);

    if(rnd == 1) then begin
        sfx := "pipbye";
    end else begin
        sfx := "piptalk2";
    end

    play_sfx(sfx);
end

procedure items_list_mode begin
    mode := 1;
end

procedure item_options_mode begin
    mode := 2;
end

procedure batch_ok_mode begin
    mode := 3;
end

procedure undo_ok_mode begin
    mode := 4;
end

procedure display_items_list begin
    variable reply, sfx, r, d, m;
    SayStart;

    if(global_var(GVAR_MR_FIXIT_WELCOME) == 0) then begin
        set_global_var(GVAR_MR_FIXIT_WELCOME, 1);
        reply := 200;
        sfx := "pipmrfix";
    end else begin

        r := random(1, 100);
        d := get_day;
        m := get_month;

        if(d + m == 2) then begin
            sfx := "piphnyd";
            reply := 216;
        end else if (d == 14 and m == 2) then begin
            sfx := "piphvd";
            reply := 217;
        end else if (d == 1 and m == 4) then begin
            sfx := "piphafd";
            reply := 218;
        end else if (d == 10 and m == 6) then begin
            sfx := "piphsd";
            reply := 219;
        end else if (d == 4 and m == 7) then begin
            sfx := "piphid";
            reply := 220;
        end else if (d == 31 and m == 10) then begin
            sfx := "piphh";
            reply := 221;
        end else if (d == 26 and m == 11) then begin
            sfx := "piphtd";
            reply := 222;
        end else if (d == 25 and m == 12) then begin
            sfx := "pipmc";
            reply := 223;
        end else begin
            if(dude_is_male) then begin
                if(morning) then begin
                    reply := 207;
                    sfx := "pipgms";
                end else if (evening) then begin
                    reply := 209;
                    sfx := "pipges";
                end else begin
                    if(r >= 1 and r <= 33) then begin
                        reply := 203;
                        sfx := "pipwbsir";
                    end else if(r >= 34 and r <= 66) then begin
                        reply := 204;
                        sfx := "piphs";
                    end else if(r >= 67 and r <= 90) then begin
                        reply := 211;
                        sfx := "pipfixit";
                    end else if(r >= 91 and r <= 95) then begin
                        reply := 213;
                        sfx := "pipdooda";
                    end else if(r >= 96 and r <= 98) then begin
                        reply := 215;
                        sfx := "pipnewtn";
                    end else begin
                        reply := 214;
                        sfx := "piptesla";
                    end
                end
            end else begin
                if(morning) then begin
                    reply := 208;
                    sfx := "pipgmm";
                end else if (evening) then begin
                    reply := 210;
                    sfx := "pipgem";
                end else begin
                    if(r >= 1 and r <= 33) then begin
                        reply := 205;
                        sfx := "pipwbm";
                    end else if(r >= 34 and r <= 66) then begin
                        reply := 206;
                        sfx := "piphm";
                    end else if(r >= 67 and r <= 90) then begin
                        reply := 211;
                        sfx := "pipfixit";
                    end else if(r >= 91 and r <= 95) then begin
                        reply := 213;
                        sfx := "pipdooda";
                    end else if(r >= 96 and r <= 98) then begin
                        reply := 215;
                        sfx := "pipnewtn";
                    end else begin
                        reply := 214;
                        sfx := "piptesla";
                    end
                end
            end
        end
    end

    if(mrfixit_talk == 0) then begin
        mrfixit_talk := 1;
        play_sfx(sfx);
    end
        MouseShape("pcx/st1.pcx", 0, 0);
        SayReply("r_display_list", bstr(reply));
        call display_items_avail;
        SayOption(bstr(101), exit_mode);
    SayEnd;
end

procedure display_item_options begin
    cur_pid := atoi(field(ITEM_PID));
    cur_gvar := atoi(field(ITEM_GVAR));
    max_undo := obj_is_carrying_obj_pid(dude_obj, cur_pid);
    SayStart;
        MouseShape("pcx/st1.pcx", 0, 0);
        SayReply("r_item_options", proto_data(cur_pid, it_description));
        call draw_item_pcx;
        call draw_item_properties;
        if (can_batch and max > 1) then SayOption(bstr(108) + bstr(110) + max + bstr(111), batch_all_items);
        if (can_batch) then SayOption(bstr(103), batch_one_item);
        if (can_undo and max_undo > 1) then SayOption(bstr(109) + bstr(110) + max_undo + bstr(111), undo_all_items);
        if (can_undo) then SayOption(bstr(104), undo_one_item);
        SayOption(bstr(102), items_list_mode);
        SayOption(bstr(101), exit_mode);

        if(cur_gvar == GVAR_CRAFT_SHARP_SPEAR) then begin
            play_sfx("pipsspr");
        end else if(cur_gvar == GVAR_CRAFT_MOLOTOV_COCKTAIL) then begin
            play_sfx("pipmolot");
        end else if(cur_gvar == GVAR_CRAFT_DYNAMITE) then begin
            play_sfx("pipdyna");
        end else if(cur_gvar == GVAR_CRAFT_LEATHER_JACKET) then begin
            play_sfx("pipltjck");
        end else if(cur_gvar == GVAR_CRAFT_LEATHER_ARMOR) then begin
            play_sfx("pipltrar");
        end else if(cur_gvar == GVAR_CRAFT_LEATHER_ARMOR_MKII) then begin
            play_sfx("piplamk2");
        end else if(cur_gvar == GVAR_CRAFT_HEALING_POWDER) then begin
            play_sfx("piphealp");
        end else if(cur_gvar == GVAR_CRAFT_ANTIDOTE) then begin
            play_sfx("pipantid");
        end else if(cur_gvar == GVAR_CRAFT_STIMPAK) then begin
            play_sfx("pipstmpk");
        end else if(cur_gvar == GVAR_CRAFT_SUPER_STIMPAK) then begin
            play_sfx("pipsupst");
        end else if(cur_gvar == GVAR_CRAFT_PSYCHO) then begin
            play_sfx("pippsych");
        end else if(cur_gvar == GVAR_CRAFT_ELECTRONIC_LOCKPICKS) then begin
            play_sfx("pipellck");
        end else if(cur_gvar == GVAR_CRAFT_ELECTRONIC_LOCKPICKS_MKII) then begin
            play_sfx("pipelmk2");
        end else if(cur_gvar == GVAR_CRAFT_COMBAT_LEATHER_JACKET) then begin
            play_sfx("pipcbtj");
        end else if(cur_gvar == GVAR_CRAFT_GREATER_HEALING_POWDER) then begin
            play_sfx("ghp");
        end else if(cur_gvar == GVAR_CRAFT_WOODEN_BRIDGE) then begin
            play_sfx("woodplnk");
        end else if(cur_gvar == GVAR_CRAFT_RAT_TAIL_LUCKY_CHARM) then begin
            play_sfx("piprtlc");
        end else if(cur_gvar == GVAR_CRAFT_POISONED_STIMPAK) then begin
            play_sfx("pipps");
        end else if(cur_gvar == GVAR_CRAFT_POISONED_SUPER_STIMPAK) then begin
            play_sfx("pippss");
        end
    SayEnd;
end

procedure display_batch_ok begin
    SayStart;
        MouseShape("pcx/st1.pcx", 0, 0);
        SayReply("r_batch_item", bstr(201));
        SayOption(bstr(100), item_options_mode);
        SayOption(bstr(101), exit_mode);
    SayEnd;
end

procedure display_undo_ok begin
    SayStart;
        MouseShape("pcx/st1.pcx", 0, 0);
        SayReply("r_undo_batch", bstr(202));
        SayOption(bstr(100), item_options_mode);
        SayOption(bstr(101), exit_mode);
    SayEnd;
end

procedure mf_list_next begin
    cur_pos += ITEMS_PER_SCREEN;
end

procedure mf_list_back begin
    cur_pos -= ITEMS_PER_SCREEN;
end

procedure redraw_win_dscr begin
    DeleteWin("win_dscr");
    create_win_flag("win_dscr", win_x + 1, win_y + 1, 300, 378, WIN_FLAG_EXCLUSIVE);
    SelectWin("win_dscr");
    Display("PCX/w_dscr.pcx");
    ShowWin;
end

procedure redraw_win_idle begin
    DeleteWin("win_dscr");
    create_win_flag("win_dscr", win_x + 1, win_y + 1, 300, 378, WIN_FLAG_EXCLUSIVE);
    SelectWin("win_dscr");
    Display("PCX/w_idle.pcx");
    ShowWin;
end

procedure display_items_avail begin
    variable lines_counter := 0;
    variable skip_counter := 0;
    call redraw_win_idle;
    cur_section_start := SECTION_START;
    if (cur_pos != 0) then SayOption(bstr(106), mf_list_back);
    while (skip_counter < cur_pos) do begin
        cur_gvar := atoi(field(ITEM_GVAR));
        if (field(ITEM_GVAR) == "" or global_var(cur_gvar)) then skip_counter += 1;
        cur_section_start += SECTION_STEP;
    end
    while (lines_counter < ITEMS_PER_SCREEN and bstr(cur_section_start) != "Error" and bstr(cur_section_start) == ITEM_ITEM) do begin
        cur_pid := atoi(field(ITEM_PID));
        cur_gvar := atoi(field(ITEM_GVAR));
        if (field(ITEM_GVAR) == "" or global_var(cur_gvar)) then begin
            call display_next_option(lines_counter);
            lines_counter += 1;
        end
        cur_section_start += SECTION_STEP;
    end
    if (cur_pos + ITEMS_PER_SCREEN < items_avail - 1) then SayOption(bstr(105), mf_list_next);
    if (items_avail == 0) then SayOption(bstr(107), exit_mode);
end

procedure display_next_option(variable i) begin
    if (i == 0) then begin
        start0 := cur_section_start;
        SayOption(proto_data(cur_pid, it_name), item_options_0);
    end
    else if (i == 1) then begin
        start1 := cur_section_start;
        SayOption(proto_data(cur_pid, it_name), item_options_1);
    end
    else if (i == 2) then begin
        start2 := cur_section_start;
        SayOption(proto_data(cur_pid, it_name), item_options_2);
    end
    else if (i == 3) then begin
        start3 := cur_section_start;
        SayOption(proto_data(cur_pid, it_name), item_options_3);
    end
    else if (i == 4) then begin
        start4 := cur_section_start;
        SayOption(proto_data(cur_pid, it_name), item_options_4);
    end
    else if (i == 5) then begin
        start5 := cur_section_start;
        SayOption(proto_data(cur_pid, it_name), item_options_5);
    end
    else if (i == 6) then begin
        start6 := cur_section_start;
        SayOption(proto_data(cur_pid, it_name), item_options_6);
    end
end

procedure item_options_0 begin
    cur_section_start := start0;
    call item_options_mode;
end

procedure item_options_1 begin
    cur_section_start := start1;
    call item_options_mode;
end

procedure item_options_2 begin
    cur_section_start := start2;
    call item_options_mode;
end

procedure item_options_3 begin
    cur_section_start := start3;
    call item_options_mode;
end

procedure item_options_4 begin
    cur_section_start := start4;
    call item_options_mode;
end

procedure item_options_5 begin
    cur_section_start := start5;
    call item_options_mode;
end

procedure item_options_6 begin
    cur_section_start := start6;
    call item_options_mode;
end

procedure batch_item(variable num) begin
    variable begin
        line := PARSER_START;
        c_pid := 0;
        c_quantity := 0;
        hours;
        mins;
    end
    game_time_advance(cur_time * num);
    while (field(line) != ITEM_COMPONENTS and line < SECTION_STEP) do line += 1;
    line += 1;
    while (line < SECTION_STEP and field(line) != "Error" and bstr(cur_section_start) == ITEM_ITEM) do begin
        c_pid := atoi(field(line));
        c_quantity := atoim(field(line), c_pid + ":");
        remove_pid_qty(dude_obj, c_pid, c_quantity * num)
        line += 1;
    end
    give_pid_qty(dude_obj, cur_pid, num)
    hours := ((cur_time * num) / ONE_GAME_MINUTE) / 60;
    mins  := ((cur_time * num) / ONE_GAME_MINUTE) % 60;
    display_msg(bstr(400) + proto_data(cur_pid, it_name) + bstr(402) + num + bstr(403) + hours + bstr(404) + mins + bstr(405));
    call batch_ok_mode;
end

procedure undo_batch(variable num) begin
    variable begin
        line := PARSER_START;
        c_pid := 0;
        c_quantity := 0;
        hours;
        mins;
    end
    game_time_advance(cur_time * num);
    while (field(line) != ITEM_COMPONENTS and line < SECTION_STEP) do line += 1;
    line += 1;
    while (line < SECTION_STEP and field(line) != "Error" and bstr(cur_section_start) == ITEM_ITEM) do begin
        c_pid := atoi(field(line));
        c_quantity := atoim(field(line), c_pid + ":");
        give_pid_qty(dude_obj, c_pid, c_quantity * num)
        line += 1;
    end
    remove_pid_qty(dude_obj, cur_pid, num)
    hours := ((cur_time * num) / ONE_GAME_MINUTE) / 60;
    mins  := ((cur_time * num) / ONE_GAME_MINUTE) % 60;
    display_msg(bstr(401) + proto_data(cur_pid, it_name) + bstr(402) + num + bstr(403) + hours + bstr(404) + mins + bstr(405));
    call undo_ok_mode;
end

procedure batch_one_item begin
    call batch_item(1);
end

procedure batch_all_items begin
    call batch_item(max);
end

procedure undo_one_item begin
    call undo_batch(1);
end

procedure undo_all_items begin
    call undo_batch(max_undo);
end

procedure draw_item_properties begin
    variable begin
        line := PARSER_START;
        saved_line := PARSER_START;
        display_line := 100;
        has_tools := 1;
        has_skills := 1;
        has_components := 1;
        tool := 0;
        skill := 0;
        skill_lv := 0;
        c_pid := 0;
        c_quantity := 0;
        max2;
        hours;
        mins;
        tool_word;
        end_flag;
        i;
        has_any;
        hours_str := bstr(307);
        mins_str := bstr(308);
    end
    SelectWin("win_dscr");
    SetTextColor(0.0, 1.0, 0.0);
    Format(proto_data(cur_pid, it_name), 25, display_line, 250, 10, justifycenter);
    display_line += 30;
    while (field(line) != ITEM_TOOLS and line < SECTION_STEP) do line += 1;
    line += 1;
    Format(bstr(300), 25, display_line, 250, 10, justifycenter);
    display_line += 10;
    saved_line := line;
    while (field(line) != ITEM_SKILLS and line < SECTION_STEP and field(line) != "Error" and bstr(cur_section_start) == ITEM_ITEM) do begin
        i := 0;
        has_any := 0;
        end_flag := 0;
        while (not(end_flag)) do begin
            tool_word := wordar(field(line), i);
            if (tool_word == "") then begin
                end_flag := 1;
                if (has_any == 0) then has_tools := 0;
            end
            else begin
                tool := atoi(tool_word);
                if (obj_is_carrying_obj_pid(dude_obj, tool)) then begin
                    SetTextColor(0.0, 1.0, 0.0);
                    has_any := 1;
                end
                else begin
                    SetTextColor(1.0, 0.0, 0.0);
                end
                if (i) then
                    Format(bstr(150) + proto_data(tool, it_name), 25, display_line, 250, 10, justifyleft);
                else
                    Format(proto_data(tool, it_name), 25, display_line, 250, 10, justifyleft);
                display_line += 10;
                i += 1;
            end
        end
        line += 1;
    end
    display_line += 10;

    if (saved_line == line) then begin
        SetTextColor(0.0, 1.0, 0.0);
        Format(bstr(303), 25, display_line, 250, 10, justifyleft);
        display_line += 10;
    end
    line += 1;
    SetTextColor(0.0, 1.0, 0.0);
    Format(bstr(301), 25, display_line, 250, 10, justifycenter);
    display_line += 10;
    saved_line := line;
    while (field(line) != ITEM_COMPONENTS and line < SECTION_STEP and field(line) != "Error" and bstr(cur_section_start) == ITEM_ITEM) do begin
        skill := parse_skill_name(field(line));
        skill_lv := atoim(field(line), skill_def(skill) + ":");
        if (critter_skill_level(dude_obj, skill) >= skill_lv) then begin
            SetTextColor(0.0, 1.0, 0.0);
        end
        else begin
            SetTextColor(1.0, 0.0, 0.0);
            has_skills := 0;
        end
        Format(skill_name(skill) + " " + skill_lv + "%", 25, display_line, 250, 10, justifyleft);
        display_line += 10;
        line += 1;
    end
    display_line += 10;

    if (saved_line == line) then begin
        SetTextColor(0.0, 1.0, 0.0);
        Format(bstr(303), 25, display_line, 250, 10, justifyleft);
        display_line += 10;
    end
    line += 1;
    SetTextColor(0.0, 1.0, 0.0);
    Format(bstr(302), 25, display_line, 250, 10, justifycenter);
    display_line += 10;
    saved_line := line;
    max := 32767;
    while (line < SECTION_STEP and field(line) != "Error" and bstr(cur_section_start) == ITEM_ITEM) do begin
        c_pid := atoi(field(line));
        c_quantity := atoim(field(line), "" + c_pid + ":");
        if (obj_is_carrying_obj_pid(dude_obj, c_pid) >= c_quantity) then begin
            SetTextColor(0.0, 1.0, 0.0);
        end
        else begin
            SetTextColor(1.0, 0.0, 0.0);
            has_components := 0;
        end
        max2 := obj_is_carrying_obj_pid(dude_obj, c_pid) / c_quantity;
        if (max2 < max) then max := max2;
        Format(proto_data(c_pid, it_name) + " x" + c_quantity, 25, display_line, 250, 10, justifyleft);
        display_line += 10;
        line += 1;
    end
    display_line += 10;

    if (saved_line == line) then begin
        SetTextColor(0.0, 1.0, 0.0);
        Format(bstr(303), 25, display_line, 250, 10, justifyleft);
        display_line += 10;
    end
    if (has_tools and has_skills and has_components) then can_batch := 1;
    else can_batch := 0;
    cur_undo := field(ITEM_UNDO);
    if (cur_undo == "YES" and has_tools and has_skills and obj_is_carrying_obj_pid(dude_obj, cur_pid)) then can_undo := 1;
    else can_undo := 0;
    SetTextColor(0.0, 1.0, 0.0);
    Format(bstr(304), 25, display_line, 250, 10, justifycenter);
    display_line += 10;
    cur_time := atoi(field(ITEM_TIME));
    hours := (cur_time / ONE_GAME_MINUTE) / 60;
    mins  := (cur_time / ONE_GAME_MINUTE) % 60;

    if(hours > 0) then begin

        if(hours > 1) then begin
            hours_str = hours_str + "s";
        end

        Format(hours + " " + hours_str, 25, display_line, 250, 10, justifyleft);
        display_line += 10;
    end

    if(mins > 0) then begin

        if(mins > 1) then begin
            mins_str = mins_str + "s";
        end

        Format(mins + " " + mins_str, 25, display_line, 250, 10, justifyleft);
    end
    ShowWin;
end

procedure draw_item_pcx begin
    variable begin
        w;
        h;
    end
    cur_pcx := field(ITEM_PCX);
    cur_size := atoi(field(ITEM_SIZE));
    w := cur_size / 1000;
    h := cur_size % 1000;
    call redraw_win_dscr;
    SelectWin("win_dscr");
    DisplayGFX(cur_pcx, 150 - w/2, 55 - h/2, w, h);
    ShowWin;
end

procedure parse_skill_name(variable s_name) begin
    variable begin
        i := 0;
        ret := -1;
    end
    while (i < 18 and ret < 0) do begin
        if (s_name > skill_def(i) and s_name < skill_def(i) + ";") then ret := i;
        i += 1;
    end
    return ret;
end


// Player has the cursor on the button?
procedure do_on begin
end

procedure do_off begin
   if (button_pressed) then play_sfx(SFX_BUTTON_UP);
   button_pressed := false;
end

procedure do_down begin
   if (button_pressed == false) then begin
      button_pressed := true;
      play_sfx(SFX_BUTTON_DOWN);
   end
end

procedure do_up begin
   if (not button_pressed) then return;

   button_pressed := false;
   play_sfx(SFX_BUTTON_UP);

    if combat_is_initialized then begin
      display_msg(mstr_proto(902));
   end
   else if (not(get_game_mode) and (mode < 1)) then begin
      if (obj_is_carrying_obj_pid(dude_obj, PID_LIL_PIP_3000)) then
        call batch_init;
    else begin
        display_msg(mstr_misc(7000));
    end
   end
end


// Create the button

procedure create_button begin
   // Mash's HRP has a bug when clicking on main interface - it goes on top (sfall doesn't have this).
   // Workaround: delete and recreate button when going to/from these UI's with moveontop flag only when button is actually clickable.
   variable onTop := true;// not(get_game_mode bwand (BARTER bwor INVENTORY bwor DIALOG));
   if (global_var(GVAR_CRAFTING_BUTTON_SHOWN) == 0) then begin
      //if (crafting_button_top != onTop) then
      //   DeleteWin(WIN_CRAFT_BTN);
      //else
        variable
            x := get_interface_x(WINTYPE_IFACEBAR) + get_interface_width(WINTYPE_IFACEBAR) - BUTTON_RIGHT_OFFSET,
            y := (get_screen_height - BUTTON_BOTTOM_OFFSET);
        create_win_flag(WIN_CRAFT_BTN, x, y, BUTTON_WIDTH, BUTTON_HEIGHT, WIN_FLAG_DONTMOVE bwor (WIN_FLAG_MOVEONTOP if onTop else 0));
        SelectWin(WIN_CRAFT_BTN);
        AddButton("but", 0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
        AddButtonGFX("but", PCX_BUTTON_DOWN, PCX_BUTTON_UP, PCX_BUTTON_UP);
        AddButtonProc("but", do_on, do_off, do_down, do_up);
        ShowWin;
        //crafting_button_top := onTop;
        set_global_var(GVAR_CRAFTING_BUTTON_SHOWN, 1);
    end
end

procedure delete_button begin
    if (global_var(GVAR_CRAFTING_BUTTON_SHOWN) == 1) then begin
        set_global_var(GVAR_CRAFTING_BUTTON_SHOWN, 0);
        DeleteWin(WIN_CRAFT_BTN);
    end
 end
