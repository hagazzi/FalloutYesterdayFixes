Great mod by PJ Hexer and friends(?)

Here's their Patreon https://www.patreon.com/fallouty


# FalloutYesterdayFixes

#Disclaimer
some changes were made to the MAIN category scripts therefore to see these changes appear one need to remove data/Scripts/*.int scripts which shouldnt be an issue since they are also in patch001.dat/Scripts

#Fixes
-Make both hoover dam safes from caravan merchant unlockable, error in condition prevented that to happen if LCK < 9
-Adding Extra way to complete Miracle Wheat quest from Mesa Verde, include changes to Denom (MV) and Pierre (HD) nodes
-Changes to Dr Davide (Tibbets) so that Radscorpion quest can still be completed after having already talked to him once
-BoS implant time calculation was off, it looked like it squared ONE_GAME_DAY ending up a result in years instead of weeks
-Wasn't really warranting a fix but there were dialogs to kill magik in his sleep that did nothing i tried a bit to do it, and ended up succeeding so added that to the list
-Bea fixed so no longer unresponsive in other maps than Hoover Map Downtown
-Dave quest shouldnt be one you can complete since there are no way to complete the material part of it (?) i added the GVAR for it my issue being with map respawning several time i had much more than 81 kills in that map so moved to >= instead of ==
-Fixed Bea barfight so you can move to her while the barfight event starting too many hex to move to even with 10 action point due to vanilla companion hp being very low
-Unseen fix to gl_PartySkillBooksMod.ssl some change to it so that it stop spamming the debug.log with opcode error
-Adding some config to the FalloutYesterday.ini, i'd prefer for these thing to not happen but i understand that some would like it, it's more of a in case of replay playthrough i'd guess, since my maps kept respawning i saw its effect and don't like it.
-Change to Dodge in Hoover Dam so that several quests can be done, some quests if not completed at the same time with other would block progress later on, also a mistype where Dodge was expecting int <=3 character in the middle of an int 4+ string of messages
-Very Basic changes to Hangdman so that he stops trying to attack any tribals 
-Possibly Unneeded fix for Mark in Bloomfield, was bugging for me
-Changes on CITY.TXT so that all tp arent stack on each other for Blackfoot, Dogtown, Ouroboros and Moletown Elevation typo


#Added
-TMP500 (BoS Quartermaster - Stocks up Combat Armor - Might Stock Up Energy Weapons)
-Frieda Restock
-Milko Restock
-Add Caps to Skill Book Vendor

#Changed
-Hangdman agression toward Slaver was seeping in toward Tribals due to how ai critter are set up, made some change so that it allow one to keep Hangdman around even in Tibbet Blackfoot or Mesa Verde
-Change to companion so that they get extra health depending on their Endurance and your character (dude_obj) level, using the basic hp per level formula used for your own character Floor(END / 2) + 2


#TODO Adds maybe (?)
-TMP501 	(Blackfoot vendor - some of what milko currently restocked moved here like broc / xander / powder, also adding in tribal chems)
-TMP502 	(NCR vendor - Restock big guns and ammos also some gauss guns)
-Diane  	(Selling car upgrades at various NCR quest advancement (including car storage upgrade at the same time (?)))
-MrFixit	(Extra Recipes => for AdvPA and AdvPA mkII - Lore wise NCR and BoS salvaged the enclave so Adv PA should be known to BoS)
-Random loot based on container type for flavour container (most are empty right now)

#TODO Change maybe (?)
-add some xp to quests that didnt have any (MVCANNON.SSL no xp from hound kill / MVNEMONK.SSL no xp from computer quest / MVAKZEE.SSL no xp from hound quest / HDPABLO.SSL some xp for that hard speech check i think) 
-balance xp amount depending on game progression Tibbets < Mesa Verde < Hoover Dam < Maxson Bunker ?
-some alternate way to progress without combat should reward xp especially if it kill things similar to MVCANNON therefore griefing you from their combined xp
-adding Legion flag to some legion npc in Dogtown Villa
-making some npc from tibbets to get you location from outside (big talbot => Hoover Dam) (Grandmother Spider => Blackfoot + Reservation)
-some npc from Blackfoot could mark Mesa Verde


#Incomplete
-several of what is alluded to be quests in Tibbets dialog actually aren't linked to actual quest
-Angela
-Dr Siren
-Seb
-Taz(?)
-Troposhere(?)
-There are no trigger to let you know to go and speak to Odysseus to start Act2 (?)
-Bloomfield Hook talk about with float text someone fixing thing in the basement, theres noone there

i don't think these quest can be completed (there might be some other but i checked the script for these) :
Tibbets - prologue :
-Locate the rare .50 Magnum Revolver
Tibbets :
-Find a new "home" for the Vault Boy hologram
Mesa Verde :
-Ask the Ciphers to process ZAX's raw data
-Forge an alliance between the Brotherhood and the Ciphers
-Rescue Cyphers
Hoover Dam :
-Any Bounty Quests?
-Theres also a ranger quest to join them that requires a legion flag but noone loot it right now (according to design document a vexillarius (flag bearer) should be in dogtown)


#Advice(?)
-had maps reset on me several time during my playthrough im reading fallout 2 not really made for multi-core and in the process of saving its possible for some of the map.sav to be lost in the process
modifying ddraw.ini setting to SingleCore=1 might be advised, if one don't want to have the same trouble, wasnt default on 0.65.1, never had this issue with RPU that made it default
