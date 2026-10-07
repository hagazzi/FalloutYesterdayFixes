Great mod by PJ Hexer and friends(?)

Here's their Patreon https://www.patreon.com/fallouty


# FalloutYesterdayFixes

## Disclaimer
* some changes were made to the MAIN category scripts therefore to see these changes appear one need to remove data/Scripts/*.int scripts which shouldnt be an issue since they are also in patch001.dat/Scripts
* changes were made to 0.65.1 so depending on changes to later version this will become obsolete

## Provision
* in order to be able to match it to actual save rather than new save, i've made the choice to use placeholder values as such i'm using:
	* GVAR_PLACEHOLDER500 (Blackfoot "quest")
	* TMP_500			  (Bos Quartermaster)
	* TMP_501			  (Blackfoot General Store Vendor)
	* TMP_502			  (NCR Ranger Vendor)
	* TMP_503			  (BHMINE2 map script)
	* TMP_504			  (Car Battery script)
* didnt want to initially since it might then requires deleting save values, but i had to modify some maps to add some items and fix ai, team / fix an exit grid behavior that kept returning me to Tibbets
* if you need to, for having already entered said maps, using editors such as F12se will let delete the particular map.sav for these zones

## Advice(?)
* had maps reset on me several time during my playthrough im reading fallout 2 not really made for multi-core and in the process of saving its possible for some of the map.sav to be lost in the process
modifying ddraw.ini setting to SingleCore=1 might be advised, if one don't want to have the same trouble, wasnt default on 0.65.1, never had this issue with RPU that made it default

## Installation
* copy content in Fallout 2 Folder after having installed Fallout Yesterday, remove / backup the .int script from Fallout2/Data/Scripts/ folder (they should be in patch001.dat already, repeat from disclaimer)
* in Fallout2/patch001.dat/Scripts/Source/ use buildall.bat it comes with the 0.65.1 install and will compile all script to .int 

### made a clean install to test and it compiles and i can still load my old saves so i think it can be tested 

## Fixes
* Make both hoover dam safes from caravan merchant unlockable, error in condition prevented that to happen if LCK < 9<br/>
* Adding Extra way to complete Miracle Wheat quest from Mesa Verde, include changes to Denom (MV) and Pierre (HD) nodes<br/> 
* Changes to Dr Davide (Tibbets) so that Radscorpion quest can still be completed after having already talked to him once<br/>
* BoS implant time calculation was off, it looked like it squared ONE_GAME_DAY ending up a result in years instead of weeks<br/> 
* Wasn't really warranting a fix but there were dialogs to kill magik in his sleep that did nothing i tried a bit to do it, and ended up succeeding so added that to the list<br/>
* Bea fixed so no longer unresponsive in other maps than Hoover Map Downtown<br/>
* Dave quest shouldnt be one you can complete since there are no way to complete the material part of it (?) i added the GVAR for it my issue being with map respawning several time i had much more than 81 kills in that map so moved to >= instead of ==<br/>
* Fixed Bea barfight so you can move to her while the barfight event starting too many hex to move to even with 10 action point due to vanilla companion hp being very low<br/>
* Unseen fix to gl_PartySkillBooksMod.ssl some change to it so that it stop spamming the debug.log with opcode error<br/>
* Adding some config to the FalloutYesterday.ini, i'd prefer for these thing to not happen but i understand that some would like it, it's more of a in case of replay playthrough i'd guess, since my maps kept respawning i saw its effect and don't like it.<br/>
* Change to Dodge in Hoover Dam so that several quests can be done, some quests if not completed at the same time with other would block progress later on, also a mistype where Dodge was expecting int <=3 character in the middle of an int 4+ string of messages<br/>
* Very Basic changes to Hangdman so that he stops trying to attack any tribals<br/>
* Possibly Unneeded fix for Mark in Bloomfield, was bugging for me<br/>
* Changes on CITY.TXT so that all tp arent stack on each other for Blackfoot, Dogtown, Ouroboros and Moletown Elevation typo<br/>
* not quite a fix per se, but some check used old Fallout2_enclave_destroyed check which i think doesnt work here, so i decided to "fix" that using a gvar that is set once finishing act3, some date with a Hoover Dam critter might be hanging on that change<br/>
* in Tibbets Salem's routine about tipping off about Sol was breaking dialog, can be fixed my moving to timed event instead, made the fix but decided to disable it, and change it for simply exiting dialog, it looks like it was intended for Salem to be killed by Sol too? doesnt make much sense in my playthrough since she's dead.
* Dr Tobillo is supposed to be on the move but ended up disappearing and never reappearing, script correctly made him disappear but forgot about making him reappear this should fix it
* Didnt know Dr Davide had pretty much the same issue as Dr Tobillo, I guess i always got the right roll.
* Weird condition on Dr Nora that prevented radscorpion nest completion if done on your own, through unmet some condition prevented to get into the procedure that was setting the gvar, and through met the setting was missing<br/>
	* i've also added some xp reward i've choose to make it +500xp, if not doing on your own through Dr Nora help one would get 500 cap and 250xp, on your own if it had worked that would have been 1000 cap and 0xp, in my book more effort is more reward <br/>
* Fixed a probably planned but unfinished quest intended for an evil playthrough, here Dr Nora ask to kill her patient, it start by killing Taz <br/>
	* The issue was that unlike Taz, pretty much all the target for that quest are in the generic Tibbets Prisoner Team, so instead i made all the target in TEAM_TAZ. <br/>
	* Prevented that quest from completing without doing anything <br/>
	* Some of the intended target were also missing the line that incremented the quest counter, it should now be all of them<br/> 
	* Some of the target will increase karma but there aren't enough that does, so it should be a net negative even without including the -50 karma from the quest reward<br/>
* Small fix to the fridge container in the asylum, can't quite have it being unlockable without changing the map files, but unlocking it from the map script was doable at least <br/>
* Weird set of condition was preventing Grandma Spider from teaching Healing Powder and wasting materials, also it was never creating any items, changed that
* Made a workaround to be able to complete Sheriff Carmichael quest, the violent way isnt working / doing anything, and the other way was missing CODE flags that are not set anywhere to begin with, i've also made them being removed from your inventory
* Changed yet another Proto, Greater Healing Powder according to its description was Healing Powder without the sleepiness component, yet the proto still included the PE debuff, i've removed that, heal value are the same
* Pugilism Illustrated (Unarmed Skillbooks) weren't working since they share id with Nikola Tesla and You (Energy Weapon Skillbooks) fixed by shifting id by one for each skillbook after.
* VACS guardman was giving you the password to the door but this didnt result in GVAR state change, this way you can bypass the door with luck <=5<br/>
* Not really a fix since Vault 70 area appears non existing right now, but i wanted the xp reward for it, so i made a generic message like your learn of it and it gives the same xp discovering it would<br/>
* Kind of a fix, i don't think you can get the Particle Matrix item currently, but if you have it from F12se or change i made to Blackfoot cave, going the repair route leave you with less than just delivering and then getting Otto, Diane or Pierre to fix it, also wasnt removing the Particle Matrix from inventory.
* Noticed as i was using big book of science craft gvar, that it was not used likely due to a copy pasta error, fixed that in gl_pipwake

## Fixes to my Fixes
* DTCL was fixed a second time to make caesar legion critter actually having equipped weapons, was using the left slot also in some case weapon the sprite appear to not being able to use.
* TMP501 was pointing to TMP502 and therefore had ranger weapon instead of tribal weapons
* Was using LVAR on map script, which obviously didnt work, moved them to MVAR
* Made a typo in my added settings which prevented effectively the new plague to ever do something since it was checking for allow_plage instead of allow_plague
* There were 2 magneto laser pistol as a result of my MrFixit changes, shifted by one recipe to fix that
* Fixing the issue about the radscorpion nest quest reveal another issue, changed the GVAR setting so that the quest isnt "reset" and therefore an infinite cap chain for 1000 cap, kind of fixing my fix
* Forgot a zero when i redid dodge's council quest reward, made the success worse than the failure
* I thought set_car_carry_amount did more, happens its only for the highwayman trunk, successfully found a way to apply it to other trunk, modified both Diane and Ed to do just that, adding on top of that a global script that might be useless but does the same on game loaded, if set_proto_data is persistent on saved data its prolly unneeded, if its not persistent then its actually worth something

## Added
* TMP500 (BoS Quartermaster - Stocks up Combat Armor - Might Stock Up Energy Weapons)<br/>
* Frieda Restock<br/>
* Milko Restock<br/>
* Add Caps to Skill Book Vendor<br/>
* Diane now can upgrade Vehicle for efficiency, speed, trunk storage and super_car once all the other are done, outside of caps cost requirement includes NCR quest advancement<br />
* Kind of a big one wanted to only add a couple recipes but it was bugging on me so i ended up redoing it in google spreadsheet, so that the index might be freely moved around without having to type each index one by one
	* from that google sheet i've created a template for mrfixit made into an ods file in a template folder
	* as a result i've reordered category a bit, would need to be ordered a bit better but from brotherhood armor, its like newly added armor > Endgame (recipes from ciphers) > tools > survival (food) > books.
	* new recipes includes advanced power armor, adv power armor mkII, combat armor mkII and combat armor mkIII, im making use of these recipes to craft it up to adv power armor mkII that can be used for athena power armor, makes full use of TMP500 (the new bos quartermaster selling combat armors, that has a change to stockup some mkII or mkIII rarely) 
		* combat armor mkII need 2x combat armor mkI (otto does it with only one combat armor i think)
		* combat armor mkIII need 2x combat armor  mkII
		* adv PA need 3x combat armor mkII and 1x hardened power armor
		* adv PA mk II need 3x combat armor mkIII and 1x adv PA		
	* added 3 pcx, to cover for the icons of these in mrfixit (adv Pa mkII has the same inventory appearance as mkI)
	* wasnt intended at the start but i ended up reducing books crafting to 3 days instead of 2 weeks
	* all the new recipes are unlocked from the "library" in maxson bunker lv3, when unlocking Hardened Power Armor, one gets both Adv PA, when unlocking Brotherhood combat armor, one get both MkII and MkIII
* TMP502 (NCR Ranger quartermaster) will restock "Big" weapons, some gauss rifle and ammunition, i made the weapon possibly not restocking so might have to wait some more for it to restock
* TMP501 (Blackfoot general vendor) will restock some unarmed / melee weapons, healing powder and some chems including strange poultice, also will stock up one time some ammo for pistols and one leather vest, included with it is a change to strange poultice proto, i had a much higher price than psycho yet being in a way the tribal psycho, move its price more in line with usual chems price <br/>
* Big Talbot and Grandma Spider now can point you toward new location, Big Talbot knows Hoover Dam, while Grandma Spider knows Blackfoot and The Reservation
* Added some quest to Chagas in Blackfoot, i intend for Blackfoot to be a stop just before Mesa Verde, Chagas will also teach you Gecko Skinning (Drake would do that too, but it felt wasteful that going up to drake would unavoidably make you kill gecko that you wouldnt be able to skin later) fixed the mine relocating you to Tibbets when you left it, well not really fixed but i've managed to relocate you back to Blackfoot to do that i had to make a change to the map in order to give it the TMP503 script.<br/>
	* As a result of needing to change the map, i've added some loot to the empty container, might have been heavy handed on the loot but should be fine
	* I've added the medimatrix part in one of the containers, i'd prolly just add it on a science check to the nearby autodoc at a later time
	* Since it now has a script i'm thinking of using it for one of Bob's bounty target that are currently missing.
* Now akin to Hakunin in Fallout 2, Grandma Spider can craft Healing Powder / Greater Healing Powder for you as long as you've learned how to craft Healing Powder and Greater Healing Powder, she batch them too
* Added a repeat option to Dusty in Hoover Dam, it just loop into the last called node so you can buy multiple beer, cookie...etc without having to return to that node each time<br/>
* Added an xp reward from convincing 3some company to supply Pablo (500xp)
* Added an xp reward from fixing (100xp 2 times) / "scienc-ing" the cannons (50xp) / using it, 1000xp might be too much but i've counted about 1750xp from killing Drake and the hounds / lastly an xp reward from quest completion (500xp)<br/>
	* recognized and used myself the exploit that would be killing most but not all and then using cannon, could perfect it with a global thats incremented on hounds kills that would reduce the cannon use xp
	* i think i could consider incrementing the good kills from using that cannon too
* Added technical manual and chemistry manual to the list of craftable book, unlike other book they require 150% in a skill, technical manual being 150% repair and chemistry 150% science, reused the big book of science pcx for chemistry, used the repair one for technical manual, will get / change technical manual FRM into a pcx later
* Added extra settings to set restock time of each merchants one by one, was thinking of changing the makeinven function to use stock_pid_qty instead of adding things continuously to their inventory, but i think its mostly harmless 
* Added both upgrades (Diane's upgrades and Otto's upgrades) to Ed Whatley(?), BoS mechanics, made very little change in the dialog, only toned down Otto lines since i don't want Ed to call himself Otto, made changes that should be ported later to Diane to make car upgrades more global so that one doesnt get upgrade twice, chose to use different breakpoint for BoS, GVAR quest wise, should let one not having to worry betraying / destroying Hoover Dam, since these upgrades are now available from Ed, having access to these upgrades in the first place requires dealing with all the repair work for Ed first, i also made Ed Car upgrades free for now, im not sure whether betraying HD cut access to merchant (design document mentionned destroying the dam)<br/>

## Changed
* Hangdman agression toward Slaver was seeping in toward Tribals due to how ai critter are set up, made some change so that it allow one to keep Hangdman around even in Tibbet Blackfoot or Mesa Verde
* Change to companion so that they get extra health depending on their Endurance and your character (dude_obj) level, using the basic hp per level formula used for your own character Floor(END / 2) + 2
* Dune Buggy trunk, theres no art for it currently therefore it wasnt added to this version, but since it was planned to have it theres a ptr therefore an inventory, i felt like adding it for extra storage space
* Changed JRTOWNE.map to be able to get the Highwayman from Jericho if one get there first, included a change in car battery scenery proto to be able to pick it up, using TMP_504 script to destroy that obj and pick up a car battery, the type of car battery depends on dude luck made it to be a charged one on LCK >= 6, made no change to cocar.ssl so once repaired it teleports to tile 24106


# TODO

## TODO Adds maybe (?)
*  ̶T̶M̶P̶5̶0̶1̶ ̶	̶(̶B̶l̶a̶c̶k̶f̶o̶o̶t̶ ̶v̶e̶n̶d̶o̶r̶ ̶-̶ ̶s̶o̶m̶e̶ ̶o̶f̶ ̶w̶h̶a̶t̶ ̶m̶i̶l̶k̶o̶ ̶c̶u̶r̶r̶e̶n̶t̶l̶y̶ ̶r̶e̶s̶t̶o̶c̶k̶e̶d̶ ̶m̶o̶v̶e̶d̶ ̶h̶e̶r̶e̶ ̶l̶i̶k̶e̶ ̶b̶r̶o̶c̶ ̶/̶ ̶x̶a̶n̶d̶e̶r̶ ̶/̶ ̶p̶o̶w̶d̶e̶r̶,̶ ̶a̶l̶s̶o̶ ̶a̶d̶d̶i̶n̶g̶ ̶i̶n̶ ̶t̶r̶i̶b̶a̶l̶ ̶c̶h̶e̶m̶s̶)̶
*  ̶T̶M̶P̶5̶0̶2̶ ̶	̶(̶N̶C̶R̶ ̶v̶e̶n̶d̶o̶r̶ ̶-̶ ̶R̶e̶s̶t̶o̶c̶k̶ ̶b̶i̶g̶ ̶g̶u̶n̶s̶ ̶a̶n̶d̶ ̶a̶m̶m̶o̶s̶ ̶a̶l̶s̶o̶ ̶s̶o̶m̶e̶ ̶g̶a̶u̶s̶s̶ ̶g̶u̶n̶s̶)̶
* ̶D̶i̶a̶n̶e̶ ̶ ̶	̶(̶S̶e̶l̶l̶i̶n̶g̶ ̶c̶a̶r̶ ̶u̶p̶g̶r̶a̶d̶e̶s̶ ̶a̶t̶ ̶v̶a̶r̶i̶o̶u̶s̶ ̶N̶C̶R̶ ̶q̶u̶e̶s̶t̶ ̶a̶d̶v̶a̶n̶c̶e̶m̶e̶n̶t̶ ̶(̶i̶n̶c̶l̶u̶d̶i̶n̶g̶ ̶c̶a̶r̶ ̶s̶t̶o̶r̶a̶g̶e̶ ̶u̶p̶g̶r̶a̶d̶e̶ ̶a̶t̶ ̶t̶h̶e̶ ̶s̶a̶m̶e̶ ̶t̶i̶m̶e̶ ̶(̶?̶)̶)̶)̶
*  ̶M̶r̶F̶i̶x̶i̶t̶	̶(̶E̶x̶t̶r̶a̶ ̶R̶e̶c̶i̶p̶e̶s̶ ̶=̶>̶ ̶f̶o̶r̶ ̶A̶d̶v̶P̶A̶ ̶a̶n̶d̶ ̶A̶d̶v̶P̶A̶ ̶m̶k̶I̶I̶ ̶-̶ ̶L̶o̶r̶e̶ ̶w̶i̶s̶e̶ ̶N̶C̶R̶ ̶a̶n̶d̶ ̶B̶o̶S̶ ̶s̶a̶l̶v̶a̶g̶e̶d̶ ̶t̶h̶e̶ ̶e̶n̶c̶l̶a̶v̶e̶ ̶s̶o̶ ̶A̶d̶v̶ ̶P̶A̶ ̶s̶h̶o̶u̶l̶d̶ ̶b̶e̶ ̶k̶n̶o̶w̶n̶ ̶t̶o̶ ̶B̶o̶S̶)̶
* Random loot based on container type for flavour container (most are empty right now)
* Restock for Dr Yuri (also Jet antidote maybe(?))
* Rethink Armor progression, from armored vault suit to leather armor mkII goes well then theres not much more reservation has some metal armor but thats about it short of stealing Mark Tesla Armor rest is Isaac PA or ranger guard armor
	* Combat armor used as stepstool to get into adv PA is possibly working but to into combat armor itself comes a bit late (?)
	* Metal Armor could be craftable from regular gecko hide + junk + gas tank
	* Metal Armor mkII from gold gecko hide + junk + metal armor mkI (?)
	* Could get Metal Armor recipes from Mesa Verde recipes like maybe Geiger counter one
	* Combat Armor MkI recipe could be Leather Armor MkII + Metal Armor MkII + Combat Leather Vest, would be inefficient to build multiple but could get one before getting into HD, and Otto would be able to get it MkII after Jericho, after that getting more from MaxsonB and/or possibly adding it to Ranger Vendor
* Since i'm thinking about adding Kyle's Head to one of the Hook and considering the number of Hook, maybe other bounty target should be accompanied by a huge number of subordinates as well
* Give MBED (Maxson Bunker's Edward Whatley) all of Diane and Otto specialized nodes, Diane being the car upgrades ones, and Otto the weapon / armor upgrades, conditionned upon having completed all the maintenance tasks
	* possibly having car upgrades dependent of current BoS rank, could possibly be free from Senior rank onward since losing all of the merchants from HD (?)
* Add PCX for technical manual
* Thinking of preventing Mark GVAR to be set prior to Act2 in Bloomfield in the offchance you got the location from Pierce
* I've noticed that i understood set_car_carry_amount wrong, i thought it was using the baseline of 250 for each upgrades, but it appears its not the case so rather than having upgrade from 250> 300> 350> 400> 475, it instead gives me upgrade into 250> 300> 420> 672> 1276, kept it as such for now but to be congruent with fallout 2 mag plate 475 would need to be the max, might change it into a setting and fixing with flat values instead

## TODO Change maybe (?)
*  ̶a̶d̶d̶ ̶s̶o̶m̶e̶ ̶x̶p̶ ̶t̶o̶ ̶q̶u̶e̶s̶t̶s̶ ̶t̶h̶a̶t̶ ̶d̶i̶d̶n̶t̶ ̶h̶a̶v̶e̶ ̶a̶n̶y̶ ̶(̶M̶V̶C̶A̶N̶N̶O̶N̶.̶S̶S̶L̶ ̶n̶o̶ ̶x̶p̶ ̶f̶r̶o̶m̶ ̶h̶o̶u̶n̶d̶ ̶k̶i̶l̶l̶ ̶/MVNEMONK.SSL no xp from computer quest /̶ ̶M̶V̶A̶K̶Z̶E̶E̶.̶S̶S̶L̶ ̶n̶o̶ ̶x̶p̶ ̶f̶r̶o̶m̶ ̶h̶o̶u̶n̶d̶ ̶q̶u̶e̶s̶t̶ ̶/̶ ̶H̶D̶P̶A̶B̶L̶O̶.̶S̶S̶L̶ ̶s̶o̶m̶e̶ ̶x̶p̶ ̶f̶o̶r̶ ̶t̶h̶a̶t̶ ̶h̶a̶r̶d̶ ̶s̶p̶e̶e̶c̶h̶ ̶c̶h̶e̶c̶k̶ ̶i̶ ̶t̶h̶i̶n̶k̶)̶ ̶
* b̶a̶l̶a̶n̶c̶e̶ ̶x̶p̶ ̶a̶m̶o̶u̶n̶t̶ ̶d̶e̶p̶e̶n̶d̶i̶n̶g̶ ̶o̶n̶ ̶g̶a̶m̶e̶ ̶p̶r̶o̶g̶r̶e̶s̶s̶i̶o̶n̶ ̶T̶i̶b̶b̶e̶t̶s̶ ̶<̶ ̶M̶e̶s̶a̶ ̶V̶e̶r̶d̶e̶ ̶<̶ ̶H̶o̶o̶v̶e̶r̶ ̶D̶a̶m̶ ̶<̶ ̶M̶a̶x̶s̶o̶n̶ ̶B̶u̶n̶k̶e̶r̶ ̶?̶
*  ̶s̶o̶m̶e̶ ̶a̶l̶t̶e̶r̶n̶a̶t̶e̶ ̶w̶a̶y̶ ̶t̶o̶ ̶p̶r̶o̶g̶r̶e̶s̶s̶ ̶w̶i̶t̶h̶o̶u̶t̶ ̶c̶o̶m̶b̶a̶t̶ ̶s̶h̶o̶u̶l̶d̶ ̶r̶e̶w̶a̶r̶d̶ ̶x̶p̶ ̶e̶s̶p̶e̶c̶i̶a̶l̶l̶y̶ ̶i̶f̶ ̶i̶t̶ ̶k̶i̶l̶l̶ ̶t̶h̶i̶n̶g̶s̶ ̶s̶i̶m̶i̶l̶a̶r̶ ̶t̶o̶ ̶M̶V̶C̶A̶N̶N̶O̶N̶ ̶t̶h̶e̶r̶e̶f̶o̶r̶e̶ ̶g̶r̶i̶e̶f̶i̶n̶g̶ ̶y̶o̶u̶ ̶f̶r̶o̶m̶ ̶t̶h̶e̶i̶r̶ ̶c̶o̶m̶b̶i̶n̶e̶d̶ ̶x̶p̶
* a̶d̶d̶i̶n̶g̶ ̶L̶e̶g̶i̶o̶n̶ ̶f̶l̶a̶g̶ ̶t̶o̶ ̶s̶o̶m̶e̶ ̶l̶e̶g̶i̶o̶n̶ ̶n̶p̶c̶ ̶i̶n̶ ̶D̶o̶g̶t̶o̶w̶n̶ ̶V̶i̶l̶l̶a̶
*  ̶m̶a̶k̶i̶n̶g̶ ̶s̶o̶m̶e̶ ̶n̶p̶c̶ ̶f̶r̶o̶m̶ ̶t̶i̶b̶b̶e̶t̶s̶ ̶t̶o̶ ̶g̶e̶t̶ ̶y̶o̶u̶ ̶l̶o̶c̶a̶t̶i̶o̶n̶ ̶f̶r̶o̶m̶ ̶o̶u̶t̶s̶i̶d̶e̶ ̶(̶b̶i̶g̶ ̶t̶a̶l̶b̶o̶t̶ ̶=̶>̶ ̶H̶o̶o̶v̶e̶r̶ ̶D̶a̶m̶)̶ ̶(̶G̶r̶a̶n̶d̶m̶o̶t̶h̶e̶r̶ ̶S̶p̶i̶d̶e̶r̶ ̶=̶>̶ ̶B̶l̶a̶c̶k̶f̶o̶o̶t̶ ̶+̶ ̶R̶e̶s̶e̶r̶v̶a̶t̶i̶o̶n̶)̶
*  ̶s̶o̶m̶e̶ ̶n̶p̶c̶ ̶f̶r̶o̶m̶ ̶B̶l̶a̶c̶k̶f̶o̶o̶t̶ ̶c̶o̶u̶l̶d̶ ̶m̶a̶r̶k̶ ̶M̶e̶s̶a̶ ̶V̶e̶r̶d̶e̶
* I think it could possibly be doable to make the Sheriff Carmichael "violent" way doable using Dr Nora scripts used when you don't want to do the radscorpion nest on your own, the main issue being i don't know who are the prisoners that provoked his ire (i'm thinking either of the bar patrons + food dispenser ones, or alternatively the 2nd Bar in the vehicle bay )
* I'm thinking of making bounty targets and their cohort giving good kills not just to the one that kill them, thats a vanilla fallout 2 setting but i don't like that you aren't a berserker with a certain number of bad kill but then you start only doing good kill and you still become a berserker
* I think i saw a more complete highwayman model somewhere, might give it the highwayman script 

# OTHER

## Changes i made for myself that im not porting
* changes to gl_stealing_mod.ssl so that i never ever see a message such as you need 450 steal skill to steal that item even tho everyone got PER == 1 since i've spammed beer on them
	* made sneak apply in full to steal skill
	* disabled the bonus to critter steal skill given by many other being in the vicinity of the one who steal is being used on.
*  ̶c̶h̶a̶n̶g̶e̶s̶ ̶t̶o̶ ̶V̶E̶H̶I̶C̶L̶E̶S̶.̶H̶ ̶s̶o̶ ̶t̶h̶a̶t̶ ̶G̶V̶A̶R̶ ̶u̶p̶g̶r̶a̶d̶e̶s̶ ̶a̶r̶e̶n̶'̶t̶ ̶r̶e̶s̶e̶t̶ ̶e̶a̶c̶h̶ ̶t̶i̶m̶e̶,̶ ̶w̶i̶l̶l̶ ̶p̶o̶r̶t̶ ̶i̶t̶ ̶i̶f̶ ̶i̶ ̶m̶a̶k̶e̶ ̶c̶h̶a̶n̶g̶e̶s̶ ̶t̶o̶ ̶D̶i̶a̶n̶e̶.̶= DONE
* made a change to dude_looks_like_bos specifically making a dude_wearing_power_armor_bos distinction, to only recognize regular PA and Hardened PA, while i can understand why making the choice of having all PA be recognized as BOS i think there are many other armor that could be shot on sight due to how foreign they look to both BoS and NCR, also like they can tell combat armor from bos combat armor, so i've decided to make it precise instead, for now i'm still conflicted, so im not sure whether porting it or not


## Incomplete
* several of what is alluded to be quests in Tibbets dialog actually aren't linked to actual quest edit: [it looks that the content of some appear to have some weak link to the informant side quest]
* Angela
* Dr Siren
* Seb
*  ̶T̶a̶z̶(̶?̶)̶ Made the target of one evil playthrough quest
*  ̶T̶r̶o̶p̶o̶s̶h̶e̶r̶e̶(̶?̶)̶ Made the target of one evil playthrough quest
* There are no trigger to let you know to go and speak to Odysseus to start Act2 (?)
* Bloomfield Hook talk about with float text someone fixing thing in the basement, theres noone there

### i don't think these quest can be completed (there might be some other but i checked the script for these) :
1. Tibbets - prologue :<br/>
	* Locate the rare .50 Magnum Revolver<br/>
2. Tibbets :<br/>
	* Find a new "home" for the Vault Boy hologram<br/>
3. Mesa Verde :<br/>
	* Ask the Ciphers to process ZAX's raw data<br/>
	* Forge an alliance between the Brotherhood and the Ciphers<br/>
	* Rescue Ciphers<br/>
4. Hoover Dam :<br/>
	* Any Bounty Quests?<br/>
	* Theres also a ranger quest to join them that requires a legion flag but noone loot it right now (according to design document a vexillarius (flag bearer) should be in dogtown)<br/>

### keeping previous category as such but i intend to tackle some of these
1. Bounty Quests
2. Ranger Quests already available through the changed dogtown maps