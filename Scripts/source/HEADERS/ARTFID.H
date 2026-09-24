/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef ARTFID_H
#define ARTFID_H

/******************************************************************
   File Name: ArtFid.H


   Purpose: This file will contain defines for all the critter
            fids for the game. The pids can be found by using mapper
            and selecting the critter and then edit. The FID will show
            up on the debug screen preceded by "proto->fid = ".
            Note: all the FID defines with that only have () were not
            in the game at the time that this file was made so if they
            show up, make 'em.


   Created: April 28, 1998

*******************************************************************

   Changelog: - Added missing FID numbers
              - Fixed incorrect FID numbers
              - Added missing critters
                (List now matches critters.lst patch 1.02d)
              - Added FoT critter pack art

   Updated: Nov 23, 2004 by dude_obj

******************************************************************/

// Reserved     	(16777216)
#define FID_HAPOWR	(16777217)  // Hero Androgynous Power Armor
#define FID_HAROBE	(16777218)  // Hero Androgynous Robe (Purple)
#define FID_HFCMBT	(16777219)  // Hero Female Combat Armor
#define FID_HFJMPS	(16777220)  // Hero Female Vault Jumpsuit
#define FID_HFLTHR	(16777221)  // Hero Female Leather Armor
#define FID_HFMAXX	(16777222)  // Hero Female Leather Jacket
#define FID_HFMETL	(16777223)  // Hero Female Metal Armor
#define FID_HMBJMP	(16777224)  // Hero Black Male Vault Jumpsuit
#define FID_HMBMET	(16777225)  // Hero Black Male Metal Armor
#define FID_HMCMBT	(16777226)  // Hero Male Combat Armor
#define FID_HMJMPS	(16777227)  // Hero Male Vault Jumpsuit
#define FID_HMLTHR	(16777228)  // Hero Male Leather Armor
#define FID_HMMAXX	(16777229)  // Hero Male Leather Jacket
#define FID_HMMETL	(16777230)  // Hero Male Metal Armor
#define FID_MABROM	(16777231)  // Brahmin
#define FID_MADDOG	(16777232)  // Wild Dog
#define FID_MAHAND	(16777233)  // Robot (Mr Handy)
#define FID_MALIEU	(16777234)  // Super Mutant Lieutenant
#define FID_MAMRAT	(16777235)  // Mole Rat
#define FID_MAMTN2	(16777236)  // Super Mutant (Black/Marcus)
#define FID_MAMTNT	(16777237)  // Super Mutant (Green)
#define FID_MASCRP	(16777238)  // Rad Scorpion (Large)
#define FID_MASPHN	(16777239)  // Floater
#define FID_MASRAT	(16777240)  // Giant Rat
#define FID_MATHNG	(16777241)  // Centaur
#define FID_NABLUE	(16777242)  // NPC Androgynous Robe (Blue)
#define FID_NACHLD	(16777243)  // NPC Androgynous Child
#define FID_NAGHUL	(16777244)  //	NPC Androgynous Ghoul (Green)
#define FID_NAGLOW	(16777245)  //	NPC Androgynous Ghoul (White)
#define FID_NAPOWR	(16777246)  // NPC Androgynous Power Armor
#define FID_NAROBE	(16777247)  //	NPC Androgynous Robe (Brown)
#define FID_MACRBS	(16777248)  // CRB-S
#define FID_NFBRLP	(16777249) //		NPC Female Pretty Blonde
#define FID_NFMAXX	(16777250) //		NPC Female Leather Jacket
#define FID_NFMETL	(16777251) //		NPC Female Metal Armor
#define FID_NFPEAS	(16777252) //		NPC Female Peasant
#define FID_NFTRMP	(16777253) //		NPC Female Tramp
#define FID_NFVRED	(16777254) // Fixed	NPC Female Redhead Vault Jumpsuit
#define FID_NMBPEA	(16777255) //		NPC Black Male Peasant
#define FID_NMBRLP	(16777256) //		NPC Male Peasant
#define FID_NMBSNP	(16777257) //		NPC Male Peasant
#define FID_NMGRCH	(16777258) // Fixed	NPC Male Midget
#define FID_NMLOSR	(16777259) //		NPC Male Loser
#define FID_NMLTHR	(16777260) //		NPC Male Leather Armor Bald
#define FID_NMMAXX	(16777261) //		NPC Male Leather Jacket
#define FID_NMOVER   (16777262) // NPC Overseer Chair
#define FID_NMOVR2	(16777263) // NPC Overseer
#define FID_NMPEAS	(16777264) //		NPC Male Peasant
#define FID_MARIPO		(16777265) // Mariposa
#define FID_MATHND		(16777266) // Thunderbird
#define FID_MACLAW	(16777267) // 		Deathclaw (Large)
#define FID_MAMANT	(16777268) // 		Mantis
#define FID_MAROBO	(16777269) // Fixed	Robot (Skynet)
#define FID_MAFEYE	(16777270) // Fixed	Robot (Floating Eye)
#define FID_MAMURT	(16777271) // 		Pig Rat
#define FID_NABRWN	(16777272) // Fixed 	NPC Androgynous Robe (Brown)
#define FID_NMDOCC	(16777273) //		NPC Male Doctor
#define FID_MADEGG	(16777274) // Added	Deathclaw Egg
#define FID_MASCP2	(16777275) // 		Rad Scorpion (Small)
#define FID_MACLW2	(16777276) // 		Deathclaw (Small)
#define FID_HFPRIM	(16777277) //		Hero Female Primitive
#define FID_HMWARR	(16777278) //		Hero Male Primitive Warrior
#define FID_NFPRIM	(16777279) //		NPC Female Primitive
#define FID_NMWARR	(16777280) //		NPC Male Primitive Warrior
#define FID_MAPLNT	(16777281) //		Spore Plant
#define FID_MAROBT	(16777282) // Added	Robot (Sentry)
#define FID_MAGKO2	(16777283) // 		Gecko (Silver/Little)
#define FID_MAGCKO	(16777284) // 		Gecko (Green/Golden)
#define FID_NMVALT	(16777285) //		NPC Male Vault Jumpsuit
#define FID_MALICH	(16777286) // RadLeech
#define FID_HANPWR	(16777287) //		Hero Androgynous Advanced Power Armor
#define FID_NMNICE	(16777288) // Added	NPC Male Dressy Suit (President)
#define FID_NFNICE	(16777289) // Added	NPC Female Dressy Skirt (Kitty)
#define FID_NFVALT	(16777290) // Added	NPC Female Vault Jumpsuit
#define FID_MACYBR	(16777291) // Added	Cyber Dog
#define FID_MABRAN	(16777292) // Added	Giant Rat (The Brain)
#define FID_NMBONC	(16777293) // Added	NPC Male Bouncer (Blue)
#define FID_NMBRSR	(16777294) // Added	NPC Male Bouncer (Grey)
#define FID_NAVGUL	(16777295) // Added	NPC Androgynous Ghoul
#define FID_MALIEN	(16777296) // Added	Alien/Wanamingo
#define FID_MAFIRE	(16777297) // Added	Fire Gecko
#define FID_NMASIA	(16777298) // Added	NPC Male Asian
#define FID_NFLYNN	(16777299) // Added	NPC Black Female Vault Jumpsuit (Lynette)
#define FID_NAWHIT	(16777300) // Added	NPC Androgynous Robe (Grey)
#define FID_MABOSS	(16777301) // Added	Horrigan
#define FID_MAQUEN	(16777302) // Added	Queen Alien/Wanamingo
#define FID_NMCOPP	(16777303) // Added	NPC Male Police
#define FID_NMMYRN	(16777304) // Added	NPC Male Myron
#define FID_NMLABB	(16777305) // Added	NPC Male Scientist
#define FID_MAGUN2	(16777306) // Added	Gun Turret (Dual Cannon)
#define FID_NMFATT	(16777307) // Added	NPC Male Fat (Vic)
#define FID_NMRGNG	(16777308) // Added	NPC Male Asian Gang (Lo Pan Gang)
#define FID_NMGANG	(16777309) // Added	NPC Male Asian Gang (Dragon Gang)
#define FID_NFASIA	(16777310) // Added	NPC Female Asian
#define FID_NMMEXI	(16777311) // Added	NPC Male Mexican Gang (Mordino Men)
#define FID_NMBOXX	(16777312) // Added	NPC Male Boxer
#define FID_MAANTT	(16777313) // Added	Giant Ant
#define FID_NMOLDD	(16777314) // Added	NPC Male Old
#define FID_MAROBE	(16777315) // Added	Deathclaw (Goris)
#define FID_MADETH	(16777316) // Added	Deathclaw (Grey)
#define FID_MAGUNN	(16777317) // Added	Gun Turret (Auto Cannon)
#define FID_MABOS2	(16777318) // Added	Horrigan (Death)

// Added critters extracted from Fallout Tactics
// Critter Packs plus Behemoth and Pacification Bots

#define FID_MANDY2	(16777319) // Andy MK2
#define FID_HABROB	(16777320) // Hero Black Robe
#define FID_NMCOAT	(16777321) // NPC Coat
#define FID_EYEBOT	(16777322) // Eyebot
#define FID_MANDY1	(16777323) // Andy MK1
#define FID_HASROB	(16777324) // Hero Yellow Robe
#define FID_HFBLND	(16777325) // Hero Female Blonde Vault Jumpsuit
#define FID_HFBLMX	(16777326) //
#define FID_HFBLMT	(16777327) //
#define FID_HFBLL1	(16777328) //
#define FID_HFBLL2	(16777329) //
#define FID_HFBLN1	(16777330) //
#define FID_HFDSRT	(16777331) //
#define FID_HFRJMP	(16777332) //
#define FID_HFRLT1	(16777333) //
#define FID_HFRLT2	(16777334) //
#define FID_HFRMAX	(16777335) //
#define FID_HFRMTL	(16777336) //
#define FID_HFRPRM	(16777337) //
#define FID_HFCABL	(16777338) //
#define FID_GLCMBT	(16777339) //
#define FID_HFCBTB	(16777340) //
#define FID_HFFGLT	(16777341) //
#define FID_HMBTRB	(16777342) //
#define FID_HMCBTB	(16777343) //
#define FID_HMCLJ	   (16777344) //
#define FID_HMCMBL	(16777345) //
#define FID_HMDSRT	(16777346) //
#define FID_HMFGLT	(16777347) //
#define FID_HMLJMP	(16777348) //
#define FID_HMLFGA	(16777349) //
#define FID_HMLLTH	(16777350) //
#define FID_HMLMAX	(16777351) //
#define FID_HMLMET	(16777352) //
#define FID_HMLWAR	(16777353) //
#define FID_HMMAX2	(16777354) //
#define FID_MAADOG	(16777355) //
#define FID_MADSTK	(16777356) //
#define FID_MADIRO	(16777357) //
#define FID_MAMTN3	(16777358) //
#define FID_MAPRTR	(16777359) //
#define FID_MAROBB	(16777360) //
#define FID_MABUSH	(16777361) //
#define FID_NABOYB	(16777362) //
#define FID_NABOYW	(16777363) //
#define FID_NAGRLB	(16777364) //
#define FID_NAGRLW	(16777365) //
#define FID_NAGUL1	(16777366) //
#define FID_NAGUL2	(16777367) //
#define FID_NFBTEN	(16777368) //
#define FID_NFCHLD	(16777369) //
#define FID_NFLIFE	(16777370) //
#define FID_NFPGJS	(16777371) //
#define FID_NFPGLT	(16777372) //
#define FID_NFPGMT	(16777373) //
#define FID_NFPGPR	(16777374) //
#define FID_NFVAL2	(16777375) //
#define FID_NFWTEN	(16777376) //
#define FID_NMBLEC	(16777377) //
#define FID_NMBTEN	(16777378) //
#define FID_NMCAMA	(16777379) //
#define FID_NMEKZO	(16777380) //
#define FID_NMEVCA	(16777381) //
#define FID_NMKHAN	(16777382) //
#define FID_NMLIFE	(16777383) //
#define FID_NMMAXA	(16777384) //
#define FID_NMSULJ	(16777385) //
#define FID_NMUCAS	(16777386) //
#define FID_NMVAL2	(16777387) //
#define FID_NMWTEN	(16777388) //
#define FID_NMWTN2	(16777389) //
#define FID_SSHARK	(16777390) //
#define FID_RICHRD	(16777391) //
#define FID_MAWSBT	(16777392) //
#define FID_NFPRM2	(16777393) //
#define FID_NMHAIR	(16777394) //
#define FID_NMURSL	(16777395) //
#define FID_NMCHLD	(16777396) //
#define FID_NFBWEK	(16777397) //
#define FID_NMBIGG	(16777398) //
#define FID_NMFRM1	(16777399) //
#define FID_NMFRM2	(16777400) //
#define FID_NMRMTL	(16777401) //
#define FID_NMSCRM	(16777402) //
#define FID_HMCOMB	(16777403) //
#define FID_HAENVR	(16777404) //
#define FID_MAANTQ	(16777405) //
#define FID_MA3SNS	(16777406) //
#define FID_MAURSS	(16777407) //
#define FID_MADSTS	(16777408) //
#define FID_MAGCEN	(16777409) //
#define FID_NFRECH	(16777410) //
#define FID_NMFRAK	(16777411) //
#define FID_HMCMBB	(16777412) //
#define FID_HMBLDJ	(16777413) //
#define FID_MAMIRE	(16777414) //
#define FID_NAGHFL	(16777415) //
#define FID_NAGLGR	(16777416) //
#define FID_NFTECH	(16777417) //
#define FID_NMMAX8	(16777418) //
#define FID_NFVAL3	(16777419) //
#define FID_NMVAL3	(16777420) //
#define FID_HFJRED	(16777421) //
#define FID_HMJRED	(16777422) //
#define FID_HFCRED	(16777423) //
#define FID_HMCRED	(16777424) //
#define FID_HFLTGR	(16777425) //
#define FID_HMLTGR	(16777426) //
#define FID_HFCBRW	(16777427) //
#define FID_HMCBRW	(16777428) //
#define FID_HFLMK2	(16777429) //
#define FID_HMBPRM	(16777430) //
#define FID_HMBMTL	(16777431) //
#define FID_HMBMAX	(16777432) //
#define FID_HMBLT1	(16777433) //
#define FID_HMBLT2	(16777434) //
#define FID_HMBJM2	(16777435) //
#define FID_NMVBOY	(16777436) //
#define FID_HMBOXS	(16777437) //
#define FID_MABEHE	(16777438) // Behemoth
#define FID_MAPACI	(16777439) //
#define FID_NMCIT1	(16777440) //
#define FID_NMCIT2	(16777441) //
#define FID_NMCIT3	(16777442) //
#define FID_NFCIT1	(16777443) //
#define FID_NFCIT2	(16777444) //
#define FID_HMVBOY	(16777445) // Vault Boy Hologram
#define FID_MABULL	(16777446) // Brahmin Bull
#define FID_DVLDOG	(16777447) // Devil Dog
#define FID_MARAT4	(16777448) //
#define FID_NAPOWR_F	(16777449) //
#define FID_NFVAUL	(16777450) //
#define FID_NMVAUL	(16777451) //
#define FID_HAFOTP	(16777452) //
#define FID_MATOA1	(16777453) //
#define FID_NMBOH2	(16777454) //
#define FID_NMBOH3	(16777455) //
#define FID_MAGUN3	(16777456) //
#define FID_MAGUN4	(16777457) //
#define FID_MAGUN5	(16777458) //
#define FID_MAGUN6	(16777459) //
#define FID_MABOT2	(16777460) //
#define FID_MABOT3	(16777461) //
#define FID_MABOT4	(16777462) //
#define FID_MACYBG	(16777463) //
#define FID_NMRAID	(16777464) //
#define FID_MACHKN	(16777465) //
//#define FID_RESERV	(16777466) //
//#define FID_RESERV	(16777467) //
#define FID_MARGOS	(16777468) //
#define FID_HFFOTL	(16777469) //
#define FID_NMDVDS	(16777470) //
#define FID_HFFOTM	(16777471) //
#define FID_NAGUL3	(16777472) //
#define FID_MASPDS	(16777473) // Radspider Small
#define FID_MARCH1	(16777474) //
#define FID_MARCH2	(16777475) //
#define FID_MAWASP	(16777476) //
#define FID_NMSULA	(16777477) //
#define FID_NMSUCA	(16777478) //
#define FID_NMSUMA	(16777479) //
#define FID_MAGCMT	(16777480) //
#define FID_MAPLNR	(16777481) //
#define FID_MASLUG	(16777482) //
#define FID_NMBGRY	(16777483) //
#define FID_NMLGRY	(16777484) //
#define FID_MASPDR	(16777485) // Radspider
#define FID_RACOON	(16777486) //
#define FID_MAMLIZ	(16777487) //
#define FID_MABIGH	(16777488) //
//#define FID_RESERV	(16777489) //
//#define FID_RESERV	(16777490) //
//#define FID_RESERV	(16777491) //
#define FID_HM2AVT	(16777492) //
#define FID_TURR01	(16777493) //
#define FID_PLSMAT	(16777494) //
//#define FID_RESERV	(16777495) //
#define FID_NMWATR	(16777496) //
#define FID_NMSTMP	(16777497) //
#define FID_MAPROT	(16777498) //
#define FID_LASERT	(16777499) //
//#define FID_RESERV	(16777500) //
#define FID_NMCOOK	(16777501) //
#define FID_NMEKZX	(16777502) //
#define FID_NFSCNT	(16777503) //
#define FID_NFWATR	(16777504) //
#define FID_NFWEAK	(16777505) //
#define FID_MARCKT	(16777506) //
#define FID_HAPWR1	(16777507) //
#define FID_HAPWR2	(16777508) //
#define FID_HAPWR3	(16777509) //
#define FID_MNGTRT	(16777510) //
#define FID_NADEAD	(16777511) //
#define FID_NADEA2	(16777512) //
#define FID_NADEA3	(16777513) //
#define FID_NFCLEO	(16777514) //
#define FID_NFJCKT	(16777515) //
#define FID_NFPRST	(16777516) //
#define FID_NFSTMP	(16777517) //
#define FID_NMHALF	(16777518) //
#define FID_NMHAL2	(16777519) //
#define FID_NMPULL	(16777520) //
#define FID_NMRBIN	(16777521) //
#define FID_NMRECH	(16777522) //
#define FID_NMROB1	(16777523) //
#define FID_NMROBE	(16777524) //
#define FID_NMHTRE	(16777525) //
#define FID_HM2BAS	(16777526) //
#define FID_HM2BSB	(16777527) //
#define FID_HM2LET	(16777528) //
#define FID_HM2MAK	(16777529) //
#define FID_HM2MLT	(16777530) //
#define FID_HM2MTL	(16777531) //
#define FID_MACCCC	(16777532) //
#define FID_NMBFRM	(16777533) //
#define FID_NMDOCT	(16777534) //
#define FID_NAEKZ2	(16777535) //
#define FID_MASHEP	(16777536) //
#define FID_MARRAT	(16777537) //
#define FID_MARMLR	(16777538) //
#define FID_VCTUR1	(16777539) //
#define FID_MASPH2	(16777540) //
//#define FID_RESERV	(16777541) //
#define FID_MAANTS	(16777542) //
#define FID_HFBLPR	(16777543) //
#define FID_NFOVER	(16777544) //
#define FID_MAANT2	(16777545) //
#define FID_NFMIRI	(16777546) //
#define FID_MONSTR	(16777547) //
#define FID_MANEWS	(16777548) //
#define FID_MGIANT	(16777549) //
#define FID_MAWEED	(16777550) //
#define FID_NMMEAS	(16777551) //
#define FID_NMREPR	(16777552) //
#define FID_NMFERM	(16777553) //
#define FID_HMBASE	(16777554) //
//#define FID_RESERV	(16777555) //
#define FID_MAARDE	(16777556) //
#define FID_NMCAPA	(16777557) //
#define FID_NMSUPA	(16777558) //
#define FID_MAUNDR	(16777559) //
#define FID_HMAVTR	(16777560) //
#define FID_HMSMPL	(16777561) //
#define FID_NMFAT2	(16777562) //
#define FID_NMRHND	(16777563) //
#define FID_HAPOWR_F	(16777564) // Hero Female Power Armor
#define FID_HANPWR_F	(16777565) //
#define FID_HAPWR1_F	(16777566) //
#define FID_HAPWR2_F	(16777567) //
#define FID_HAPWR3_F	(16777568) //
#define FID_NAEKZ2_F	(16777569) //
#define FID_HMDSON	(16777570) //
#define FID_HMCOMB_F	(16777571) //
#define FID_NAROBE_F	(16777572) //
#define FID_MAHAGS	(16777573) //
#define FID_HMPRSN	(16777574) //
//#define FID_RESERV	(16777575) //
#define FID_MABUGM	(16777576) //
#define FID_NAHGUL	(16777577) //
#define FID_CRGHUL	(16777578) //
#define FID_MATESL	(16777579) //
//#define FID_RESERV	(16777580) //
#define FID_NFREAV	(16777581) //
#define FID_NAREAV_M	(16777582) //
#define FID_NAREAV_F	(16777583) //
//#define FID_RESERV	(16777584) //
#define FID_HAENVR_F	(16777585) //
//#define FID_RESERV	(16777586) //
//#define FID_RESERV	(16777587) //
//#define FID_RESERV	(16777588) //
#define FID_NABRN	   (16777589) //
#define FID_HMCMSM	(16777590) //
#define FID_HFCMSM	(16777591) //
#define FID_MANKTL	(16777592) //
#define FID_NAGLAB	(16777593) //
#define FID_NAGLTH	(16777594) //
#define FID_MACLIZ	(16777595) //
#define FID_MA3SNK	(16777596) //
#define FID_NAWHIT_F	(16777597) //
#define FID_NAROBE_G	(16777598) //
#define FID_HASROB_F	(16777599) //
#define FID_MACENT	(16777600) //
#define FID_NMMEX2	(16777601) //
#define FID_NABLUE_F	(16777602) //
#define FID_MAMIGT	(16777603) //
#define FID_NFD2GL	(16777604) //
#define FID_NFDGLW	(16777605) //
#define FID_NMDGLW	(16777606) //
#define FID_NMGHLW	(16777607) //
#define FID_SCROBO	(16777608) //
#define FID_NMLEE	   (16777609) // Little Dragon
//#define FID_RESERV	(16777610) //
#define FID_NMNCR1	(16777611) //
#define FID_MATOA2	(16777612) //
#define FID_MATOA3	(16777613) //
#define FID_NFMTLB	(16777614) //
#define FID_NFMTL2	(16777615) //
#define FID_NFNCR1	(16777616) //
#define FID_NFNCR2	(16777617) //
#define FID_NMNCR2	(16777618) //
#define FID_NMNCR3	(16777619) //
#define FID_NMNCR4	(16777620) //
#define FID_NMVLTS	(16777621) //
#define FID_NFALEX	(16777622) //
#define FID_MABART	(16777623) // Bartholomew
#define FID_NFPSF1	(16777624) // NPC Female Peasant Brunette
#define FID_NFPSF2	(16777625) // NPC Female Peasant Blonde

#endif // ARTFID_H
