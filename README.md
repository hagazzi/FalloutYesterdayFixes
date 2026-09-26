Great mod by PJ Hexer and friends(?)

Here's their Patreon https://www.patreon.com/fallouty


# FalloutYesterdayFixes

## Disclaimer
* some changes were made to the MAIN category scripts therefore to see these changes appear one need to remove data/Scripts/*.int scripts which shouldnt be an issue since they are also in patch001.dat/Scripts

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


## Changed
* Hangdman agression toward Slaver was seeping in toward Tribals due to how ai critter are set up, made some change so that it allow one to keep Hangdman around even in Tibbet Blackfoot or Mesa Verde
* Change to companion so that they get extra health depending on their Endurance and your character (dude_obj) level, using the basic hp per level formula used for your own character Floor(END / 2) + 2
* Dune Buggy trunk, theres no art for it currently therefore it wasnt added to this version, but since it was planned to have it theres a ptr therefore an inventory, i felt like adding it for extra storage space


# TODO

## TODO Adds maybe (?)
* TMP501 	(Blackfoot vendor - some of what milko currently restocked moved here like broc / xander / powder, also adding in tribal chems)
* TMP502 	(NCR vendor - Restock big guns and ammos also some gauss guns)
* ̶D̶i̶a̶n̶e̶ ̶ ̶	̶(̶S̶e̶l̶l̶i̶n̶g̶ ̶c̶a̶r̶ ̶u̶p̶g̶r̶a̶d̶e̶s̶ ̶a̶t̶ ̶v̶a̶r̶i̶o̶u̶s̶ ̶N̶C̶R̶ ̶q̶u̶e̶s̶t̶ ̶a̶d̶v̶a̶n̶c̶e̶m̶e̶n̶t̶ ̶(̶i̶n̶c̶l̶u̶d̶i̶n̶g̶ ̶c̶a̶r̶ ̶s̶t̶o̶r̶a̶g̶e̶ ̶u̶p̶g̶r̶a̶d̶e̶ ̶a̶t̶ ̶t̶h̶e̶ ̶s̶a̶m̶e̶ ̶t̶i̶m̶e̶ ̶(̶?̶)̶)̶)̶
*  ̶M̶r̶F̶i̶x̶i̶t̶	̶(̶E̶x̶t̶r̶a̶ ̶R̶e̶c̶i̶p̶e̶s̶ ̶=̶>̶ ̶f̶o̶r̶ ̶A̶d̶v̶P̶A̶ ̶a̶n̶d̶ ̶A̶d̶v̶P̶A̶ ̶m̶k̶I̶I̶ ̶-̶ ̶L̶o̶r̶e̶ ̶w̶i̶s̶e̶ ̶N̶C̶R̶ ̶a̶n̶d̶ ̶B̶o̶S̶ ̶s̶a̶l̶v̶a̶g̶e̶d̶ ̶t̶h̶e̶ ̶e̶n̶c̶l̶a̶v̶e̶ ̶s̶o̶ ̶A̶d̶v̶ ̶P̶A̶ ̶s̶h̶o̶u̶l̶d̶ ̶b̶e̶ ̶k̶n̶o̶w̶n̶ ̶t̶o̶ ̶B̶o̶S̶)̶
* Random loot based on container type for flavour container (most are empty right now)

## TODO Change maybe (?)
* add some xp to quests that didnt have any (MVCANNON.SSL no xp from hound kill / MVNEMONK.SSL no xp from computer quest / MVAKZEE.SSL no xp from hound quest / HDPABLO.SSL some xp for that hard speech check i think) 
* balance xp amount depending on game progression Tibbets < Mesa Verde < Hoover Dam < Maxson Bunker ?
* some alternate way to progress without combat should reward xp especially if it kill things similar to MVCANNON therefore griefing you from their combined xp
* adding Legion flag to some legion npc in Dogtown Villa
* making some npc from tibbets to get you location from outside (big talbot => Hoover Dam) (Grandmother Spider => Blackfoot + Reservation)
* some npc from Blackfoot could mark Mesa Verde

# OTHER

## Changes i made for myself that im not porting
* changes to gl_stealing_mod.ssl so that i never ever see a message such as you need 450 steal skill to steal that item even tho everyone got PER == 1 since i've spammed beer on them
*  ̶c̶h̶a̶n̶g̶e̶s̶ ̶t̶o̶ ̶V̶E̶H̶I̶C̶L̶E̶S̶.̶H̶ ̶s̶o̶ ̶t̶h̶a̶t̶ ̶G̶V̶A̶R̶ ̶u̶p̶g̶r̶a̶d̶e̶s̶ ̶a̶r̶e̶n̶'̶t̶ ̶r̶e̶s̶e̶t̶ ̶e̶a̶c̶h̶ ̶t̶i̶m̶e̶,̶ ̶w̶i̶l̶l̶ ̶p̶o̶r̶t̶ ̶i̶t̶ ̶i̶f̶ ̶i̶ ̶m̶a̶k̶e̶ ̶c̶h̶a̶n̶g̶e̶s̶ ̶t̶o̶ ̶D̶i̶a̶n̶e̶.̶= DONE


## Incomplete
* several of what is alluded to be quests in Tibbets dialog actually aren't linked to actual quest
* Angela
* Dr Siren
* Seb
* Taz(?)
* Troposhere(?)
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
	* Rescue Cyphers<br/>
4. Hoover Dam :<br/>
	* Any Bounty Quests?<br/>
	* Theres also a ranger quest to join them that requires a legion flag but noone loot it right now (according to design document a vexillarius (flag bearer) should be in dogtown)<br/>

