const char* curList[] = { OBFUSTR("GemsCurrency"), OBFUSTR("Coins"), OBFUSTR("ClanSilver"), OBFUSTR("ClanLootBoxPoints"),  OBFUSTR("Coupons"), OBFUSTR("PixelPassCurrency"), OBFUSTR("RouletteAdsCurrency"), OBFUSTR("RouletteAdsSpin"), OBFUSTR("PixelBucks"), OBFUSTR("BattlePassCurrency"), OBFUSTR("CurrencyCompetitionTier1"), OBFUSTR("CurrencyCompetitionTier2"), OBFUSTR("KeySmallChest"), OBFUSTR("KeyEventChest"), OBFUSTR("KeyBigChest"), OBFUSTR("EventChestsSuperSpin"), OBFUSTR("EventRouletteSuperSpin"), OBFUSTR("EventRouletteSuperSpin"), OBFUSTR("Exp"), OBFUSTR("TankKeys"), OBFUSTR("PixelPassExp"), OBFUSTR("clan_building_black_market_point"), OBFUSTR("MainModeSlotTokens"), OBFUSTR("SmallChest"), OBFUSTR("BigChest"), OBFUSTR("EventChest"), OBFUSTR("MegaChest"), OBFUSTR("MerchOnBirthday2023"), OBFUSTR("TemplateEventCurrency"), OBFUSTR("MainModeSlot"), OBFUSTR("AchievementTimeInGame"), OBFUSTR("AdventNyCurrency"), OBFUSTR("ClanRankExperience"), OBFUSTR("ConfrontationEventV2Currency"), OBFUSTR("EventCurrency"), OBFUSTR("CraftCurrency"), OBFUSTR("TopUpCurrency"), OBFUSTR("ChestSmall"), OBFUSTR("ChestBig"), OBFUSTR("ChestEvent"), OBFUSTR("ChestMega"), OBFUSTR("BattleRoyaleSlotTokens"), OBFUSTR("CaptureSlotTokens"), OBFUSTR("CompetitiveSlotTokens"), OBFUSTR("BrawlsSlotTokens"), OBFUSTR("") };
const char *rocketModes[] = {"None", "Homing", "Follow Crosshair"};

const char* ItemRarity[] {
        "Common", "Uncommon", "Rare", "Epic", "Legendary", "Mythic", "None"
};

static const char *mode[] = {OBFUSTR("Distance"), OBFUSTR("Radius")};
static const char *mode2[] = {OBFUSTR("New"), OBFUSTR("Old")};

const int levelExp[] = { 0, 15, 65, 170, 280, 395, 515, 640, 770, 910, 1055, 1210, 1370, 1540, 1715, 1900, 2095, 2300, 2515, 2750, 3000, 3270, 3560, 3870, 4195, 4540, 4905, 5290, 5690, 6110, 6550, 7010, 7485, 7980, 8495, 9030, 9580, 10150, 10740, 11350, 11975, 12620, 13285, 13970, 14670, 15390, 16130, 16890, 17665, 18640, 19275, 20110, 20960, 21830, 22720, 23630, 24555, 25500, 26465, 27450, 28450, 29470, 30510, 31570, 32645 };

const char *prefabList[] {
        "fortdefence/Generator1",
        "flags/Flag2",
        "flags/Flag1",
        "gadgetscontent/gadget_snowman",
        "gadgetscontent/BionicShield",
        "gadgetscontent/gadget_class_mex_turret",
        "gadgetscontent/gadget_shield",
        "gadgetscontent/singularity",
        "gadgetscontent/gadget_sticky_turret",
        "gadgetscontent/gadget_medicalstation",
        "gadgetscontent/Drone",
        "gadgetscontent/gadget_turret",
        "gadgetscontent/MusicBox",
        "gadgetscontent/gadget_armor_regeneration",
        "gadgetscontent/gadget_hologram_projector",
        "gadgetscontent/gadget_class_lifeline_medstation",
        "gadgetscontent/gadget_christmastreeturret",
        "hungergames/Chest",
        "newyearmodemobs/Enemy116_go",
        "newyearmodemobs/Enemy134_go",
        "newyearmodemobs/Enemy120_go",
        "newyearmodemobs/Enemy113_go",
        "newyearmodemobs/Enemy124_go",
        "newyearmodemobs/Enemy111_go",
        "newyearmodemobs/Enemy135_go",
        "newyearmodemobs/Enemy130_go",
        "newyearmodemobs/Enemy125_go",
        "newyearmodemobs/Enemy137_go",
        "newyearmodemobs/Enemy136_go",
        "newyearmodemobs/Enemy119_go",
        "newyearmodemobs/Enemy126_go",
        "newyearmodemobs/Enemy127_go",
        "explosionobjects/Bomb_Goo",
        "explosionobjects/DamagedExplosionTest",
        "explosionobjects/Bomb_Freeze_Tank",
        "explosionobjects/Bomb_TNT",
        "explosionobjects/Bomb_Oil_Tank",
        "explosionobjects/Bomb_TNT_BR",
        "explosionobjects/Bomb_Poison_Tank",
        "explosionobjects/DetectExplosionTest",
        "explosionobjects/Bomb_Mine",
        "dungeonmobs/Enemy187_go",
        "dungeonmobs/Enemy118_go",
        "dungeonmobs/SpawnBase_school 2",
        "dungeonmobs/Enemy500_go",
        "dungeonmobs/Enemy142_go",
        "dungeonmobs/enemy174_go",
        "dungeonmobs/enemy176_go",
        "dungeonmobs/key_hospital",
        "dungeonmobs/Enemy123_go",
        "dungeonmobs/key_supermarket",
        "dungeonmobs/enemy167_go",
        "dungeonmobs/SpawnBase_medusatemple 1",
        "dungeonmobs/SpawnBase_goblinfactory 3",
        "dungeonmobs/Enemy185_go",
        "dungeonmobs/Enemy149_go",
        "dungeonmobs/Enemy116_go",
        "dungeonmobs/SpawnBase_hospital 4",
        "dungeonmobs/Enemy134_go",
        "dungeonmobs/SpawnBase_medusatemple 2",
        "dungeonmobs/stone_skull",
        "dungeonmobs/stone_gear",
        "dungeonmobs/Enemy121_go",
        "dungeonmobs/Enemy112_go",
        "dungeonmobs/Flask",
        "dungeonmobs/enemy186_go",
        "dungeonmobs/enemy169_go",
        "dungeonmobs/SpawnBase_goblinfactory 1",
        "dungeonmobs/stone_blood",
        "dungeonmobs/enemy170_go",
        "dungeonmobs/enemy147_go",
        "dungeonmobs/sсroll",
        "dungeonmobs/Enemy183_go",
        "dungeonmobs/Enemy190_go",
        "dungeonmobs/SpawnBase_supermarket 4",
        "dungeonmobs/Enemy158_go",
        "dungeonmobs/Enemy188_go",
        "dungeonmobs/key_bridge",
        "dungeonmobs/enemy175_go",
        "dungeonmobs/enemy148_go",
        "dungeonmobs/SpawnBase_elvenforest 1",
        "dungeonmobs/SpawnBase_school 3",
        "dungeonmobs/SpawnBase_hospital 3",
        "dungeonmobs/Enemy155_go",
        "dungeonmobs/enemy168_go",
        "dungeonmobs/scroll",
        "dungeonmobs/Enemy192_go",
        "dungeonmobs/Enemy180_go",
        "dungeonmobs/Enemy139_go",
        "dungeonmobs/Enemy182_go",
        "dungeonmobs/Enemy120_go",
        "dungeonmobs/enemy177_go",
        "dungeonmobs/SpawnBase_hospital 2",
        "dungeonmobs/Enemy113_go",
        "dungeonmobs/Enemy133_go",
        "dungeonmobs/SpawnBase_school 1",
        "dungeonmobs/SpawnBase_Magic",
        "dungeonmobs/enemy178_go",
        "dungeonmobs/enemy160_go",
        "dungeonmobs/SpawnBase_medusatemple 3",
        "dungeonmobs/Enemy159_go",
        "dungeonmobs/Enemy124_go",
        "dungeonmobs/Enemy111_go",
        "dungeonmobs/enemy172_go",
        "dungeonmobs/Enemy156_go",
        "dungeonmobs/SpawnBase_supermarket 3",
        "dungeonmobs/Enemy140_go",
        "dungeonmobs/Enemy154_go",
        "dungeonmobs/Enemy181_go",
        "dungeonmobs/Enemy129_go",
        "dungeonmobs/Enemy135_go",
        "dungeonmobs/key_school",
        "dungeonmobs/Enemy138_go",
        "dungeonmobs/SpawnBase_supermarket 1",
        "dungeonmobs/SpawnBase_goblinfactory 2",
        "dungeonmobs/enemy164_go",
        "dungeonmobs/enemy173_go",
        "dungeonmobs/SpawnBase_goblinfactory 4",
        "dungeonmobs/Enemy130_go",
        "dungeonmobs/Enemy125_go",
        "dungeonmobs/SpawnBase_medusatemple 4",
        "dungeonmobs/stone_leaf",
        "dungeonmobs/Enemy191_go",
        "dungeonmobs/SpawnBase_supermarket 2",
        "dungeonmobs/SpawnBase_elvenforest 4",
        "dungeonmobs/Enemy128_go",
        "dungeonmobs/enemy153_go",
        "dungeonmobs/Key",
        "dungeonmobs/Enemy157_go",
        "dungeonmobs/Enemy137_go",
        "dungeonmobs/SpawnBase_hospital 1",
        "dungeonmobs/SpawnBase_elvenforest 3",
        "dungeonmobs/Enemy146_go",
        "dungeonmobs/Enemy136_go",
        "dungeonmobs/enemy161_go",
        "dungeonmobs/Enemy189_go",
        "dungeonmobs/SpawnBase_elvenforest 2",
        "dungeonmobs/Enemy119_go",
        "dungeonmobs/stone_ice",
        "dungeonmobs/enemy150_go",
        "dungeonmobs/stone_water",
        "dungeonmobs/Enemy126_go",
        "dungeonmobs/enemy151_go",
        "dungeonmobs/enemy171_go",
        "dungeonmobs/Enemy122_go",
        "dungeonmobs/Enemy184_go",
        "dungeonmobs/Enemy127_go",
        "dungeonmobs/Enemy132_go",
        "dungeonmobs/SpawnBase_school 4",
        "dungeonmobs/Enemy117_go",
        "dungeonmobs/enemy166_go",
        "dungeonmobs/Enemy141_go",
        "dungeonmobs/Enemy115_go",
        "dungeonmobs/Enemy114_go",
        "dungeonmobs/enemy152_go",
        "dungeonmobs/enemy165_go",
        "weapon_bonuses/Weapon_Bonus",
        "weapon_bonuses/skin_royale_cubic_hat_Bonus",
        "weapons/Weapon1547_hologram_projector",
        "bonuses/Bonus_4",
        "bonuses/Bonus_5",
        "bonuses/Bonus_6",
        "bonuses/Bonus_7",
        "bonuses/Bonus_0",
        "bonuses/Bonus_8",
        "bonuses/Bonus_3",
        "bonuses/Bonus_2",
        "bonuses/Bonus_1",
        "enemies/Enemy33_go",
        "enemies/Enemy41_go",
        "enemies/Enemy107_go",
        "enemies/Enemy89_go",
        "enemies/Enemy12_go",
        "enemies/Enemy48_go",
        "enemies/Enemy73_go",
        "enemies/Enemy80_go",
        "enemies/Enemy144_go",
        "enemies/Enemy70_go",
        "enemies/Enemy85_go",
        "enemies/Enemy38_go",
        "enemies/Enemy15_go",
        "enemies/Enemy83_go",
        "enemies/Enemy145_go",
        "enemies/Enemy82_go",
        "enemies/Enemy44_go",
        "enemies/Enemy56_go",
        "enemies/Enemy87_go",
        "enemies/Enemy3_go",
        "enemies/Enemy51_go",
        "enemies/Enemy93_go",
        "enemies/Enemy86_go",
        "enemies/Enemy34_go",
        "enemies/Enemy14_go",
        "enemies/Enemy2_go",
        "enemies/Enemy30_go",
        "enemies/Enemy98_go",
        "enemies/Enemy92_go",
        "enemies/Enemy81_go",
        "enemies/Enemy45_go",
        "enemies/Enemy9_go",
        "enemies/Enemy31_go",
        "enemies/Enemy29_go",
        "enemies/Enemy1_go",
        "enemies/Enemy28_go",
        "enemies/Enemy32_go",
        "enemies/Enemy10_go",
        "enemies/Enemy53_go",
        "enemies/Enemy101_go",
        "enemies/Enemy57_go",
        "enemies/Enemy104_go",
        "enemies/Enemy91_go",
        "enemies/Enemy79_go",
        "enemies/Enemy27_go",
        "enemies/Enemy143_go",
        "enemies/Enemy52_go",
        "enemies/Enemy106_go",
        "enemies/Enemy66_go",
        "enemies/Enemy90_go",
        "enemies/Enemy42_go",
        "enemies/Enemy16_go",
        "enemies/Enemy84_go",
        "enemies/Enemy105_go",
        "enemies/Enemy39_go",
        "enemies/Enemy60_go",
        "enemies/Enemy43_go",
        "enemies/Enemy11_go",
        "enemies/Enemy88_go",
        "enemies/Enemy109_go",
        "enemies/Enemy46_go",
        "bots/BotInstance",
        "bots/PlayerBot",
        "graffitiprefabs/Graffiti_Mark_Of_The_Veteran",
        "graffitiprefabs/Graffiti_Black_Rabbit_Gang",
        "graffitiprefabs/Graffiti_KillStreak_Violence",
        "graffitiprefabs/Graffiti_It_Watching_You",
        "graffitiprefabs/Graffiti_Cute_Tamagochi",
        "graffitiprefabs/Graffiti_Street_Daredevils_Gang",
        "graffitiprefabs/GraffitiDefault",
        "graffitiprefabs/Graffiti_Chill_Duck",
        "graffitiprefabs/Graffiti_3CatSpam",
        "graffitiprefabs/Graffiti_Christmas_Doge",
        "graffitiprefabs/Graffiti_Hepi_Angels",
        "graffitiprefabs/Graffiti_KingOfPG",
        "graffitiprefabs/Graffiti_GG",
        "VehicleBattleRoyale/Helicopter_prefabs/freeplay_helicopter",
        "VehicleBattleRoyale/fps_all_terrain_vehicle/FreePlayAllTerrain",
        "VehicleBattleRoyale/hovercar/FreePlayHoverCar",
        "gadgetscontent/gadget_shop_preview/gadget_class_mex_turret",
        "gadgetscontent/gadget_shop_preview/gadget_turret",
        "pets/content/pet_bullfinch_the_giver",
        "pets/content/pet_elementals_helper",
        "pets/content/pet_sheep",
        "pets/content/pet_rhino",
        "pets/content/pet_ostrich",
        "pets/content/pet_owl",
        "pets/content/pet_sacred_scarab",
        "pets/content/pet_chick01",
        "pets/content/pet_blue_buddy",
        "pets/content/pet_griffin",
        "pets/content/pet_cat_2",
        "pets/content/pet_snake",
        "pets/content/pet_lucky_duck",
        "pets/content/pet_eaglespirit",
        "pets/content/pet_tukan",
        "pets/content/pet_panda",
        "pets/content/pet_phoenix",
        "pets/content/pet_horse_figure",
        "pets/content/pet_arnold_3000",
        "pets/content/pet_combat_robb_e",
        "pets/content/pet_shiny_companion",
        "pets/content/pet_flappy_fish",
        "pets/content/pet_alien_cat",
        "pets/content/pet_pterodactyl",
        "pets/content/pet_tankmouse",
        "pets/content/pet_headbug",
        "pets/content/pet_festive_black_rabbit",
        "pets/content/pet_support_piglet",
        "pets/content/pet_unicorn",
        "pets/content/pet_trex",
        "pets/content/pet_porcupine",
        "pets/content/pet_raven",
        "pets/content/pet_goat",
        "pets/content/pet_ice_dragon_egg",
        "pets/content/pet_dinosaur",
        "pets/content/pet_zombiecat",
        "pets/content/pet_skunk",
        "pets/content/pet_cat",
        "pets/content/pet_turkey",
        "pets/content/pet_bear",
        "pets/content/pet_backwater_dweller",
        "pets/content/pet_crab",
        "pets/content/pet_fox",
        "pets/content/pet_panther",
        "pets/content/pet_tiger",
        "pets/content/pet_stone",
        "pets/content/pet_boar",
        "pets/content/pet_meerkat",
        "pets/content/pet_wise_owl",
        "pets/content/pet_small_floppa",
        "pets/content/pet_blocston_dogmatics",
        "pets/content/pet_mecha_cat",
        "pets/content/pet_squirrel",
        "pets/content/pet_hyena",
        "pets/content/pet_eagle",
        "pets/content/pet_zazou",
        "pets/content/pet_penguin",
        "pets/content/pet_lion",
        "pets/content/pet_firefly_cat",
        "pets/content/pet_sabertooth_tiger",
        "pets/content/pet_pocket_demon",
        "pets/content/pet_dachshund",
        "pets/content/pet_raccoon",
        "pets/content/pet_ram",
        "pets/content/pet_green_novice",
        "pets/content/pet_knitted_pony",
        "pets/content/pet_zombie_head",
        "pets/content/pet_chicken",
        "pets/content/pet_wolf",
        "pets/content/pet_magical_dragon",
        "pets/content/pet_dog_FX",
        "pets/content/pet_vacuum_helpbro_2000",
        "pets/content/pet_stingray_3000",
        "pets/content/pet_armadillo",
        "pets/content/pet_tactical_ferret",
        "pets/content/pet_rabbit",
        "pets/content/pet_robo_dog",
        "pets/content/pet_fighting_turtle",
        "pets/content/pet_dog",
        "pets/content/pet_mammoth",
        "pets/content/pet_husky",
        "pets/content/pet_pga_statue",
        "pets/content/pet_monkey",
        "pets/content/pet_bat",
        "pets/content/pet_red_panda",
        "pets/content/pet_kangaroo",
        "pets/content/pet_griffin_owl",
        "pets/content/pet_stone_elemental",
        "pets/content/pet_deer",
        "pets/content/pet_cat_3",
        "pets/content/pet_parrot",
        "pets/content/pet_8_bit_boi",
        "pets/content/pet_cyberphoenix",
        "pets/content/pet_horse",
        "bots/scenariobots/FortBot",
        "bots/scenariobots/FortBotInstance",
        "bots/scenariobots/FortAttackBot",
        "bots/scenariobots/FortAttackBotInstance",
        "fortfield/prefabs/FortCraft",
        "fortfield/fortitemscontent/fort_easy_mobs",
        "fortfield/fortitemscontent/ingame/fort_easy_mobs",
        "Bullet",
        "NetworkTable",
        "BonusController",
        "PlayerBattleRoyale",
        "FreePlaySnowmobile",
        "FreePlayAtv",
        "Player",
        "Rocket",
        "FreePlayCar",
        "RacingCar",
        "Turret",
        "PlayerSavedStateListener",
};

const char* randPrefabList[] {
        "VehicleBattleRoyale/Helicopter_prefabs/freeplay_helicopter",
        "vehiclebattleroyale/fps_all_terrain_vehicle/FreePlayAllTerrain",
        "vehiclebattleroyale/hovercar/FreePlayHoverCar",
        "hungergames/Chest",
        "fortdefence/Generator1",
        "gadgetscontent/BionicShield",
        "gadgetscontent/singularity",
        "explosionobjects/Bomb_Goo",
        "explosionobjects/DamagedExplosionTest",
        "explosionobjects/Bomb_Freeze_Tank",
        "explosionobjects/Bomb_TNT",
        "explosionobjects/Bomb_Oil_Tank",
        "explosionobjects/Bomb_TNT_BR",
        "explosionobjects/Bomb_Poison_Tank",
        "explosionobjects/DetectExplosionTest",
        "explosionobjects/Bomb_Mine",
        "bots/BotInstance",
        "graffitiprefabs/Graffiti_Mark_Of_The_Veteran",
        "graffitiprefabs/Graffiti_Black_Rabbit_Gang",
        "graffitiprefabs/Graffiti_KillStreak_Violence",
        "graffitiprefabs/Graffiti_It_Watching_You",
        "graffitiprefabs/Graffiti_Cute_Tamagochi",
        "graffitiprefabs/Graffiti_Street_Daredevils_Gang",
        "graffitiprefabs/GraffitiDefault",
        "graffitiprefabs/Graffiti_Chill_Duck",
        "graffitiprefabs/Graffiti_3CatSpam",
        "graffitiprefabs/Graffiti_Christmas_Doge",
        "graffitiprefabs/Graffiti_Hepi_Angels",
        "graffitiprefabs/Graffiti_KingOfPG",
        "graffitiprefabs/Graffiti_GG",
        "pets/content/pet_bullfinch_the_giver",
        "pets/content/pet_elementals_helper",
        "pets/content/pet_sheep",
        "pets/content/pet_rhino",
        "pets/content/pet_ostrich",
        "pets/content/pet_owl",
        "pets/content/pet_sacred_scarab",
        "pets/content/pet_chick01",
        "pets/content/pet_blue_buddy",
        "pets/content/pet_griffin",
        "pets/content/pet_cat_2",
        "pets/content/pet_snake",
        "pets/content/pet_lucky_duck",
        "pets/content/pet_eaglespirit",
        "pets/content/pet_tukan",
        "pets/content/pet_panda",
        "pets/content/pet_phoenix",
        "pets/content/pet_horse_figure",
        "pets/content/pet_arnold_3000",
        "pets/content/pet_combat_robb_e",
        "pets/content/pet_shiny_companion",
        "pets/content/pet_flappy_fish",
        "pets/content/pet_alien_cat",
        "pets/content/pet_pterodactyl",
        "pets/content/pet_tankmouse",
        "pets/content/pet_headbug",
        "pets/content/pet_festive_black_rabbit",
        "pets/content/pet_support_piglet",
        "pets/content/pet_unicorn",
        "pets/content/pet_trex",
        "pets/content/pet_porcupine",
        "pets/content/pet_raven",
        "pets/content/pet_goat",
        "pets/content/pet_ice_dragon_egg",
        "pets/content/pet_dinosaur",
        "pets/content/pet_zombiecat",
        "pets/content/pet_skunk",
        "pets/content/pet_cat",
        "pets/content/pet_turkey",
        "pets/content/pet_bear",
        "pets/content/pet_backwater_dweller",
        "pets/content/pet_crab",
        "pets/content/pet_fox",
        "pets/content/pet_panther",
        "pets/content/pet_tiger",
        "pets/content/pet_stone",
        "pets/content/pet_boar",
        "pets/content/pet_meerkat",
        "pets/content/pet_wise_owl",
        "pets/content/pet_small_floppa",
        "pets/content/pet_blocston_dogmatics",
        "pets/content/pet_mecha_cat",
        "pets/content/pet_squirrel",
        "pets/content/pet_hyena",
        "pets/content/pet_eagle",
        "pets/content/pet_zazou",
        "pets/content/pet_penguin",
        "pets/content/pet_lion",
        "pets/content/pet_firefly_cat",
        "pets/content/pet_sabertooth_tiger",
        "pets/content/pet_pocket_demon",
        "pets/content/pet_dachshund",
        "pets/content/pet_raccoon",
        "pets/content/pet_ram",
        "pets/content/pet_green_novice",
        "pets/content/pet_knitted_pony",
        "pets/content/pet_zombie_head",
        "pets/content/pet_chicken",
        "pets/content/pet_wolf",
        "pets/content/pet_magical_dragon",
        "pets/content/pet_dog_FX",
        "pets/content/pet_vacuum_helpbro_2000",
        "pets/content/pet_stingray_3000",
        "pets/content/pet_armadillo",
        "pets/content/pet_tactical_ferret",
        "pets/content/pet_rabbit",
        "pets/content/pet_robo_dog",
        "pets/content/pet_fighting_turtle",
        "pets/content/pet_dog",
        "pets/content/pet_mammoth",
        "pets/content/pet_husky",
        "pets/content/pet_pga_statue",
        "pets/content/pet_monkey",
        "pets/content/pet_bat",
        "pets/content/pet_red_panda",
        "pets/content/pet_kangaroo",
        "pets/content/pet_griffin_owl",
        "pets/content/pet_stone_elemental",
        "pets/content/pet_deer",
        "pets/content/pet_cat_3",
        "pets/content/pet_parrot",
        "pets/content/pet_8_bit_boi",
        "pets/content/pet_cyberphoenix",
        "pets/content/pet_horse",
        "dungeonmobs/key_hospital",
        "dungeonmobs/key_supermarket",
        "dungeonmobs/stone_skull",
        "dungeonmobs/stone_gear",
        "dungeonmobs/Flask",
        "dungeonmobs/stone_blood",
        "dungeonmobs/key_bridge",
        "dungeonmobs/scroll",
        "dungeonmobs/SpawnBase_Magic",
        "dungeonmobs/SpawnBase_school 2",
        "dungeonmobs/SpawnBase_medusatemple 1",
        "dungeonmobs/SpawnBase_goblinfactory 3",
        "dungeonmobs/SpawnBase_hospital 4",
        "dungeonmobs/SpawnBase_medusatemple 2",
        "dungeonmobs/SpawnBase_goblinfactory 1",
        "dungeonmobs/SpawnBase_supermarket 4",
        "dungeonmobs/SpawnBase_elvenforest 1",
        "dungeonmobs/SpawnBase_school 3",
        "dungeonmobs/SpawnBase_hospital 3",
};

const char* gaySexWeapons[] = {
        "Weapon298", // Just A Hand
        "Weapon1485", // irradiated shovel
};

const char* spawnOptions[] = {
        "Delayed",
        "Instant",
        "Pyramid",
        "Wall",
        "Stairs",
        "Sphere"
};

const char* spawnlocation[] = {
    "On players",
    "Random"
};

const char *nicknamesCombo[] = {"Empty", "modfs on top", "xXJewsHunterXx", "NiggaSlayerGamingYT", "iiSwagMuslimFucker01", "KKK enjoyer", "Dm Hades for cp", "Dm X999 for cp", "Dm JustKirby for cp", "Square Wall", "Striker's Quit Message", "Booty Cheeks Copypasta", "Markiplier fnaf Copypasta", "Kys Copypasta", "Walter White Copypasta", "Cotton Picker Copypasta", "Boy Kisser ASCII", "Minos Prime ASCII", "Walter White ASCII", "Bull of Heaven", "Dist's dox"};

const char *nicknames[] ={
        // Empty
        "",

        // no need to explain
        "\n"
        " /$$$$                                     /$$  /$$$$$$                /$$$$\n"
        "| $$_/                                    | $$ /$$__  $$              |_  $$\n"
        "| $$         /$$$$$$/$$$$   /$$$$$$   /$$$$$$$| $$  \\__//$$$$$$$        | $$\n"
        "| $$        | $$_  $$_  $$ /$$__  $$ /$$__  $$| $$$$   /$$_____/        | $$\n"
        "| $$        | $$ \\ $$ \\ $$| $$  \\ $$| $$  | $$| $$_/  |  $$$$$$         | $$\n"
        "| $$        | $$ | $$ | $$| $$  | $$| $$  | $$| $$     \\____  $$        | $$\n"
        "| $$$$      | $$ | $$ | $$|  $$$$$$/|  $$$$$$$| $$     /$$$$$$$/       /$$$$\n"
        "|____/      |__/ |__/ |__/ \\______/  \\_______/|__/    |_______/       |____/\n"
        "                                                                            \n"
        ,

        // xXJewsHunterXx
        "xXJewsHunterXx",

        //Nigga Slayer
        "NiggaSlayerGamingYT",

        // Muslim Fucker
        "iiSwagMuslimFucker01",

        //KKK Member
        "Ku Klux Klan enjoyer",

        // Hades
        "Dm me hadespg3d on discord for free cp",

        //x999
        "Dm me x999 on discord for free cp",

        // kirby
        "Dm me justkirby. on discord for free cp",

        // Square Wall
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n",

        // Striker
        "@everyone, I apologize for the mention, but I have made the difficult decision to close the shop permanently and cancel the project of updating zygisk. \n"
        "I may either delete this server or transform it into a chat-only platform. \n"
        "I have lost all passion for playing PG3D, so I am quitting it forever. \n"
        "I have experienced both joyous and sorrowful moments, but now I feel compelled to bring an end to the shop and the zygisk project. \n"
        "I sincerely apologize for any inconvenience caused.(it deleted)",

        // Booty Cheeks
        "I like watching videos of black men shaking their booty cheeks, \n"
        "I don't know why, but when I click on a video and see a black man shaking his cheeks, it just makes my mouth drool, \n"
        "and I start dancing with the black men aswell. \n"
        "sometimes when I look at myself in the mirror, \n"
        "I sometimes  hallucinate and see black men twerking on my couch it, brings a smile to my face. \n"
        "I wish I could become one with the black men twerking aggressively, \n"
        "please understand what I'm going through and support me on my journey.",

        // Markplier fnaf Copypasta
        "Hello everybody my name is Markiplier and welcome to Five Nights at Freddies, \n"
        "an indie horror game that you guys suggested in mass, \n"
        "and I saw that Yamimash played it and he said that it was really really good; \n"
        "so I’m very eager to see what is up - and that is a terrifying animatronic bear \n"
        "*reads off script* family pizzeria looking for security guard to work the night shift. Oh, 12:00 A.M, the first night. \n"
        "If I didn’t want to stay the first night, why would I stay any more than five? Why would I say anymore than two - hello. \n"
        "Okay...Hello? Hello - oh, ah I can’t move. That’s a creepy skull...There’s creepy things on the wall - Oh, hello. \n"
        "*Phone Guy begins dialogue* “Hello, hello hello,” Hi! “Uh, I wanted to record a message for you, to help you get settled in on your first night.” \n"
        "Eugh.. “Um, I actually worked in that office before you, and I’m finishing up my last week now as a matter of fact. So, I know it can be a bit overwhelming..” \n"
        "Euuagh..! “But I’m here to tell you, there’s nothing to worry about,” \n"
        "Agh.. \n"
        "“You’ll do fine! So, let’s just focus on getting you through your first week..” \n"
        "Okay! Sounds go- \n"
        "“Ah, let’s see..First there’s an introductory greeting from the company that I’m supposed to read - i-it’s kind of a legal thing, you know, ahm - ‘Welcome to Freddy Fazbear’s Pizza-” \n"
        "Okay “‘..A magical place for kids and grownups alike-” \n"
        "*Mark wheezes indistinctly in the background* Heheha.. \n"
        "“..Where fantasy and fun come to life,” \n"
        "Eugha..! \n"
        "”Freddy Fazbear entertainment is not responsible for damage to property or person, upon discovering that damage or death has occured, a missing person report will be filed within ninety days or as soon as property and premises had been thoroughly cleaned and bleached, and the carpet’s have been replaced,’ \nblah blah blah - now that might sound bad, I know, but-” \n"
        "Yeah! \n"
        "“-There’s really nothing to worry about! Uh, the animatronic characters here do get a bit quirky at night, but do I blame them? No, if I was forced to sing those same stupid songs for twenty years, and I never got a bath, I’d probably be a bit irritable at night too. So just remember, these characters hold a special place in the hearts of children, and you need show them a little respect, Right?” \n"
        "Okay! \n"
        "“-Okay-” \n"
        "Ha-okay! \n"
        "“So just be aware, the characters fo tend to wander a bit-” \n"
        "Nehaheugh- \n"
        "“They’re one some kinda of free-roaming mode-” \n"
        "hehauhuhugh! \n"
        "“Uhh.. Something about their servos locking up if they get turned off for two long,” \n"
        "Oohoohoo- \n"
        "“Uh, they used to be allowed to walk around during the day, too, but then there was the bite of eighty-seven.”",

        // Walter White Copypasta
        "My name is Walter Hartwell White. I live at 308 Negra Arroyo Lane, Albuquerque, New Mexico, 87104. This is my confession. \n"
        "If you're watching this tape, I'm probably dead– murdered by my brother-in-law, Hank Schrader. \n"
        "Hank has been building a meth empire for over a year now, and using me as his chemist. \n"
        "Shortly after my 50th birthday, he asked that I use my chemistry knowledge to cook methamphetamine, which he would then sell using connections that he made through his career with the DEA. \n"
        "I was... astounded. I... I always thought Hank was a very moral man, and I was particularly vulnerable at the time – something he knew and took advantage of. \n"
        "I was reeling from a cancer diagnosis that was poised to bankrupt my family. Hank took me in on a ride-along and showed me just how much money even a small meth operation could make. \n"
        "And I was weak. I didn't want my family to go into financial ruin, so I agreed. Hank had a partner, a businessman named Gustavo Fring. \n"
        "Hank sold me into servitude to this man. And when I tried to quit, Fring threatened my family. I didn't know where to turn. \n"
        "Eventually, Hank and Fring had a falling-out. Things escalated. \n"
        "Fring was able to arrange – uh, I guess... I guess you call it a \"hit\" – on Hank, and failed, but Hank was seriously injured. \n"
        "And I wound up paying his medical bills, which amounted to a little over $177,000. Upon recovery, Hank was bent on revenge. \n"
        "Working with a man named Hector Salamanca, he plotted to kill Fring. The bomb that he used was built by me, and he gave me no option in it. \n"
        "I have often contemplated suicide, but I'm a coward. I wanted to go to the police, but I was frightened. \n"
        "Hank had risen to become the head of the Albuquerque DEA. To keep me in line, he took my children. For three months, he kept them. \n"
        "My wife had no idea of my criminal activities, and was horrified to learn what I had done. \n"
        "I was in hell. I hated myself for what I had brought upon my family. Recently, I tried once again to quit, and in response, he gave me this. \n"
        "[Walt points to the bruise on his face left by Hank in \"Blood Money.\"] I can't take this anymore. \n"
        "I live in fear every day that Hank will kill me, or worse, hurt my family. \n"
        "All I could think to do was to make this video and hope that the world will finally see this man for what he really is.",

        // Kys Copypasta
        "Your life literally is as valuable as a summer ant. \n"
        "I'm just gonna stomp you, you're gonna keep coming back, I'm gonna seal up all my cracks, you're gonna keep coming back, why? \n"
        "Cause you keep smelling the syrup, you worthless bitchass nigga! You're gonna stay on my dick until you die. \n"
        "You serve no purpose in life, your purpose in life is to be on my stream sucking on my dick daily. \n"
        "Your purpose in life is to be in that chat blowing a dick daily. Your life is nothing, you serve ZERO purpose. \n"
        "You should kill yourself, NOW! \n"
        "And give somebody else a piece of that oxygen and ozone layer that's covered up so we can breathe inside this blue trapped bubble. \n"
        "Cause what are you here for? To worship me? Kill yourself! \n"
        "I mean that with a hundred percent with a thousand percent.",

        // Cotton Picker
        "A cotton picker is either a machine that harvests cotton, or a person who picks ripe cotton fibre from the plants.\n"
        "[1][2] The machine is also referred to as a cotton harvester.\n"
        "History:"
        "\n"
        "In many societies, like America, slave and serf labor was utilized to pick the cotton, increasing the plantation owner's profit margins (See Trans-Atlantic Slave Trade). \n"
        "The first practical cotton picker was invented over a period of years beginning in the late 1920s by John Daniel Rust (1892–1954) with the later help of his brother Mack Rust. \n"
        "Other inventors had tried designs with a barbed spindle to twist cotton fibers onto the spindle and then pull the cotton from the boll, but these early designs were impractical because the spindle became clogged with cotton. \n"
        "Rust determined that a smooth, moist spindle could be used to strip the fibers from the boll without trapping them in the machinery. \n"
        "In 1933 John Rust received his first patent, and eventually, he and his brother owned forty-seven patents on cotton picking machinery. \n"
        "However, during the Great Depression it was difficult to obtain financing to develop their inventions.[4]\n"
        "In 1935 the Rust brothers founded the Rust Cotton Picker Company in Memphis, Tennessee, and on 31 August 1936 demonstrated the Rust picker at the Delta Experiment Station in Stoneville, Mississippi. \n"
        "Although the first Rust picker was not without serious deficiencies, it did pick cotton and the demonstration attracted considerable national press coverage. \n"
        "Nevertheless, the Rusts' company did not have the capability of manufacturing cotton pickers in significant quantities. With the success of the Rust picker, other companies redoubled their efforts to produce practical pickers not based on the Rust patents. \n"
        "Then, widespread adoption was delayed by the manufacturing demands of World War II. \n"
        "The International Harvester Company produced a commercially successful commercial cotton picker in 1944. \n"
        "After World War II, the Allis-Chalmers Manufacturing Company manufactured cotton pickers using an improved Rust design. \n"
        "In the following years mechanical pickers were gradually improved and were increasingly adopted by farmers.[4]\n"
        "\n"
        "The introduction of the cotton picker has been cited as a factor in the Second Great Migration.\n"
        "Cotton plant improvements:\n"
        "\n"
        "To make mechanical cotton pickers more practical, improvements in the cotton plant and in cotton culture were also necessary. \n"
        "In earlier times, cotton fields had to be picked by hand three and four times each harvest season because the bolls matured at different rates. \n"
        "It was not practical to delay picking until all the bolls were ready for picking because the quality of the cotton deteriorated as soon as bolls opened. \n"
        "But about the time mechanical pickers were introduced, plant breeders developed hybrid cotton varieties with bolls higher off the ground and that ripened uniformly. \n"
        "With those innovations, the harvester could make just one pass through the field. Also, herbicides were developed to defoliate the plants and drop their leaves before the picker came through, producing a cleaner harvest.\n"
        "Conventional harvester:"
        "\n"
        "The first harvesters were only capable of harvesting one row of cotton at a time, but were still able to replace up to forty hand laborers. \n"
        "The current cotton picker is a self-propelled machine that removes cotton lint and seed (seed-cotton) from the plant at up to six rows at a time.\n"
        "\n"
        "There are two types of pickers in use today. One is the \"stripper\" picker, primarily found in use in Texas. They are also found in Arkansas. \n"
        "It removes not only the lint from the plant, but a fair deal of the plant matter as well (such as unopened bolls). \n"
        "Later, the plant matter is separated from the lint through a process dropping heavier matter before the lint makes it to the basket at the rear of the picker. \n"
        "The other type of picker is the \"spindle\" picker. It uses rows of barbed spindles that rotate at high speed and remove the seed-cotton from the plant. \n"
        "The seed-cotton is then removed from the spindles by a counter-rotating doffer and is then blown up into the basket. \n"
        "Once the basket is full the picker dumps the seed-cotton into a \"module builder\". \n"
        "The module builder creates a compact \"brick\" of seed-cotton, weighing approximately 21,000 lb (16 un-ginned bales), which can be stored in the field or in the \"gin yard\" until it is ginned. \n"
        "Each ginned bale weighs roughly 480 lb (218.2 kg).\n"
        "\n"
        "An industry-exclusive on-board round module builder was offered by John Deere in 2007. \n"
        "In c.2008 the Case IH Module Express 625 was designed in collaboration with ginners and growers to provide a cotton picker with the ability to build modules while harvesting the crop.",

        // Furry Sex Stare
        "⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣤⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣷⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣶⡆\n"
        "⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⠟⠛⠛⠿⢿⣿⣿⣿⣿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⡿⠁\n"
        "⠀⠀⠀⠀⠀⢰⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠈⠉⠻⠿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡆\n"
        "⠀⠀⠀⠀⠀⣾⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣿⣧⣤⡀⠀⠀⠀⠀⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣿⣿⣷⣀⠀⠀⠀⠀⠀⠀⣼⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠇\n"
        "⠀⠀⠀⠀⠀⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣇⠀⠀⠀⠀⢹⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣷⣄⠀⠀⠀⣰⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣧⠀⠀⠀⠀⢿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣷⣶⢠⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣷⣄⠀⠀⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⡆⠀⣠⣿⣿⣿⣷⣶⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⠿⠛⠉⠈⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣶⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠛⠛⠛⠛⠛⠛⠛⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀\n"
        "⠀⠀⠀⠀⢸⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀\n"
        "⠀⠀⠀⠀⢸⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀\n"
        "⠀⠀⠀⠀⠸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⡇⠀\n"
        "⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠇⠀\n"
        "⠀⠀⠀⠀⠀⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⡿⠀⠀\n"
        "⠀⠀⠀⠀⠀⣿⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠃⠀⠀\n"
        "⠀⠀⠀⠀⠀⢻⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣤⣤⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⡟⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠈⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⢰⣶⣶⣶⣶⣦⣤⣾⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠛⠛⠛⢿⣿⣿⡟⠻⠿⠿⠇⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⠁⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⢸⣿⣿⡄⠀⠀⠀⠀⠀⠀⠸⠿⠿⢿⣿⣿⣿⣿⡟⠛⠛⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠘⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⣿⣿⣿⡏⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⡆⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣷⣄⣀⠀⠀⠀⠀⠀⢰⣿⣿⡏⠛⠁⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⢀⣿⣿⣿⡀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣏⣀⡀⠀⠀⠀⠀⠀\n"
        "⣀⣀⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣿⡀⠀⠀⠀⠀⣾⣿⣿⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠈⣿⣿⣿⡇⠀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀\n"
        "⣿⣿⣿⣷⣶⣤⣤⣤⣤⣼⣿⣿⣿⣿⣆⠀⠀⢀⣿⣿⡇⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠈⣿⣿⡇⠀⠀⠀⢿⣿⣿⠟⠛⠛⠋⠉⠉⠉⢉⣿⣿⣿⠀\n"
        "⠻⣿⣿⣿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⠏⠀\n"
        "⠀⢿⣿⣿⣧⠀⠀⠈⠉⠉⠉⠙⢿⣿⡿⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⠏⠀⠀\n"
        "⠀⠈⢿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡄⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⢿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⡿⠁⠀⠀⠀\n"
        "⠀⠀⠈⠻⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⣤⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⠋⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠙⢿⣿⣿⣿⣤⡀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⠟⠁⠀⠀⢀⣤⣶⣶⣶⣿⣿⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⢠⣤⡼⠿⢿⣧⡀⠀⠀⠀⠀⠀⢠⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠻⢿⣿⣿⣿⣦⣄⡀⠀⢀⣀⣀⣘⢿⣿⠏⣀⡀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⡇⢀⣼⣿⣧⠀⠀⠀⠀⢠⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠛⠛⣻⣾⣿⣿⣿⣿⡆⠀⣾⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣾⣿⣿⣿⣣⣾⣿⣿⡿⠀⠀⠀⠀⠸⠿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⡏⠀⢸⣿⣿⡟⣹⣿⣿⣧⣾⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⢀⣾⣿⡿⠀⠀⠀⠙⠛⠃⣿⣿⣿⣿⣿⡿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠛⣿⣿⣿⣿⣿⠟⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣶⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⣾⣿⣿⠁⠀⠀⠀⠀⠀⠀⢻⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣦⡀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣶⣶⣤⣄⣠⣶⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣆⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⢠⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣧⣤⣴⣿⣿⣿⡿⠛⠛⠻⢿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⡄⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⢸⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⡄⠀⠀⠀⠀⠀⢀⣶⣄⣀⣤⣼⣿⣿⣧⡄⠀⠀\n"
        "⠀⠀⠀⠀⠀⢸⣿⣿⣦⣄⣀⣀⣿⣷⣶⣤⣿⣿⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣷⣶⣦⣤⣤⣤⣾⣿⣿⣿⣿⣿⡿⠿⠟⠃⠀⠀\n"
        "⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣾⣿⣿⣿⠿⠋⣿⣿⠿⠿⠿⠿⠿⠟⠋⠉⠉⠁⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣿⣿⣿⣶⣶⣦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣶⣿⣿⣿⣿⡿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠻⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⡿⠿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠿⢿⣿⣿⣿⣿⣶⣶⣶⣶⣾⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠋⢩⣶⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣦⠀⠈⠙⠛⠻⠿⠛⠻⠿⠿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣾⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣷⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⡟⠁⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣶⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠿⠛⠛⠛⠛⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⡟⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",

        // Minos Prime
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠁⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⣿⣦⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠀⠀⠀⠀⢀⡏⠀⠀⠀⠀⠀⠀⣿⡅⠀⠈⡉⢳⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⡇⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠐⣿⠃⠀⠀⠰⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣶⡇⠀⠀⠀⠀⢸⠇⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠈⣷⣦⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣄⣀⣿⣿⠃⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠈⣿⡅⠻⢦⣀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⡿⣿⠉⠻⢿⠀⠀⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀⢰⡇⠀⠀⠀⠀⠀⠃⠀⠀⠀⣸⡇⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣀⣀⡀⣾⣶⡇⠀⠀⠀⣼⠀⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀⣸⠇⠀⠀⠀⠀⢸⠀⠀⠀⠀⢹⡇⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⡿⠇⠁⢿⠁⠀⠀⠀⣽⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⡟⠀⠀⠀⠀⢸⣷⣶⡄⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣿⢿⣷⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⣸⠏⢿⡟⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣼⠀⠀⠀⡀⠀⠀⠀⡇⠀⠀⠀⠀⢰⠀⠀⠀⠀⠀⠀⢀⡇⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⢀⡇⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⢰⢸⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⣿⠀⢠⠇⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⡇⠋⣿⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠈⡚⠀⠀⠀⠀⠀⠀⣾⠀⠀⠀⠀⠀⡼⠀⠀⠀⠀⠀⡇⠀⢸⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡅⡀⢿⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⢰⠇⠀⡾⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠟⡀⣇⡸⠀⠀⠀⠀⠀⠀⠘⠀⠀⠀⠀⢠⠁⠀⠀⠀⠀⠀⠀⣟⠀⠀⠀⠀⠀⢧⠀⠀⠀⠀⣸⠀⠀⡇⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⡧⣬⡃⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⢰⡿⠀⠀⠀⠀⢸⠈⠀⠀⠀⠀⣿⠀⢠⠃⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⣿⡇⠀⠀⠘⡇⠀⠀⠀⠀⠀⠀⣘⡌⣄⠀⠀⠀⠀⠀⣼⣇⠀⠀⠀⠀⢸⠁⠀⠀⠀⢠⡇⠀⢸⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣧⡄⢀⣤⣿⣦⣴⣿⣾⣇⡴⡷⢧⣿⣸⡆⢠⣼⣿⣿⣿⣦⠀⠀⠀⣿⠁⠀⠀⠀⢸⡇⠀⡏⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣷⣿⡿⢿⣿⣿⢙⡋⠋⠀⠀⠘⠟⠹⠃⠈⠈⠙⠻⡿⢻⠟⢿⣿⣿⣳⡆⢠⣀⣾⠁⢰⠇⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⠙⢻⡁⢿⣿⣿⠚⠋⠀⠀⠀⠀⠀⢀⡠⣄⣶⣦⣶⣶⣦⣤⣄⡀⡀⠀⠋⠋⠹⠙⡾⢿⣯⣀⣾⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣗⡘⡑⠀⢿⠟⠁⠀⠀⠀⠀⠀⢀⣼⡻⣿⣿⡿⡿⡟⢹⣿⣿⣿⣿⡀⠀⠀⠀⠀⢷⣴⣟⣿⠋⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣆⢀⠘⠀⠁⠀⠀⠀⠀⢠⣾⣿⣣⠈⠋⠐⠀⠀⠁⢸⣿⣿⣿⣿⣇⠀⠀⠀⢸⣻⡟⠁⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⡸⣼⡆⠀⠀⠀⠀⣠⣿⡮⡇⠉⠀⠀⠀⠀⠀⠀⠀⣻⣿⣿⣿⣿⠀⠀⠀⢸⣿⠃⠐⠒⠒⠀⠀⠉⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⢸⡟⣹⣿⣿⣿⣿⣇⠀⠀⠀⠀⣾⡗⠁⠉⠀⠀⠀⠀⠀⠀⠀⠀⠼⢛⣿⣿⣿⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⣿⡿⡍⣿⣻⡟⣿⡿⡀⠀⠀⣰⡿⠁⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⠀⠀⠀⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠁⢉⠘⢷⢻⢷⡇⠀⠀⣿⢃⠁⠀⠀⠀⠀⠀⠀⠀⠀⡀⠘⠀⣿⣿⣿⡇⠀⠀⠀⡍⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠐⠀⠀⠀⢿⡿⠘⢨⠐⠐⣿⡎⠀⠀⠀⣙⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⢼⣿⣿⣾⠇⠀⠀⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⢸⡧⡄⠀⢢⠠⡹⠁⠀⠀⠠⣿⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢽⣿⣿⡿⠀⠀⢀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣷⡆⠀⡎⢸⠀⠀⠀⢸⣧⠀⠀⠀⠀⠀⠀⠀⠀⢄⣄⣀⣿⣾⣿⡿⠀⠀⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⢯⡇⠀⠀⠀⠸⣷⠄⠀⠀⠀⠀⠀⠀⠀⠀⠁⢒⣼⣿⣿⠣⠁⠀⡰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⡌⠓⠀⠀⠀⠀⢿⡍⠀⠀⠀⠈⠀⠀⠐⠀⣥⣼⣿⣿⡟⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣰⣀⠀⠀⠀⠨⣯⠀⠀⠀⠠⠀⠀⢠⢰⣿⣿⣿⡿⠀⠀⢰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡏⣿⣿⣿⣿⡏⠀⠀⠀⠀⠻⣦⣦⡆⡀⡄⢃⣿⣿⣿⣿⠏⠁⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⣀⣠⣤⣶⣿⠛⠀⡏⣿⣿⣿⣷⡆⡀⠀⠀⠀⠈⠻⢷⣯⣾⣾⣿⣿⠟⠁⠀⢀⣾⠇⠐⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⡰⠤⠶⠿⠿⣿⣿⣿⡏⠀⠀⠘⣾⣯⣿⣿⣿⣧⡄⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⣠⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⢀⣴⣿⣿⠟⠃⠀⠀⠀⢹⣿⡿⣿⣿⣿⣷⣴⣀⡀⠀⠀⡘⠀⠀⠀⠀⣴⣿⠟⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⣹⣿⣿⠁⠀⠀⠀⠀⠀⠈⢹⣷⠈⡿⠹⠉⢻⠿⢿⣾⣿⣧⣴⣦⢷⣾⣿⣿⣆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⣠⣶⠟⢯⡿⣽⡧⠀⠀⠀⠀⠀⠀⢸⣿⠂⠀⠀⠀⠀⠀⠈⠀⠈⠈⠀⠘⢿⣿⣿⣿⣻⣷⣦⡀⠀⠀⠀⠀⠀⠀",

        // Walter White ASCII
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⣤⣤⣤⣤⣤⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠖⣀⠉⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣷⣶⣶⣦⣤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⢀⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⢿⣛⡟⠛⠛⠛⠛⠛⣛⠛⠛⣟⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠉⠁⠀⠀⠀⣀⣀⡉⣁⣘⣀⣀⡛⠀⠉⠀⠀⠉⠉⠳⢽⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠘⠻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠉⠡⠤⠤⢄⡀⠉⠉⡿⣷⣆⠀⠀⡇⠈⣿⡇⢈⣛⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⢿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⣀⣀⣠⣶⣀⣀⣀⣀⣀⣠⣷⡎⢿⣄⣴⣧⣴⣿⣿⣿⣿⣿⣿⣎⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢩⣯⣝⢿⣿⣶⣤⣤⣴⣿⣥⣼⠟⢻⣿⣿⣿⣿⣿⣿⣧⣾⣿⣿⣿⣿⣿⣿⣯⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⠁⢤⡈⣿⠈⠛⢿⣿⣿⡷⠿⠻⣿⣿⣿⡟⠁⣼⡏⠙⣿⣿⣿⣿⡏⢹⣿⣿⣿⣿⡿⢾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠐⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣄⣶⣷⢻⡀⠀⠸⡆⢹⡇⠀⠈⠙⠛⠋⠃⣨⡿⠀⠀⣿⣿⣿⣿⣿⡄⢨⣿⡿⠋⢀⣼⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⠃⢸⣇⠀⠀⠻⣾⣇⠀⠀⠀⠀⣀⣴⡿⠁⠀⠀⠸⣿⣿⣿⣿⣿⣬⣁⣤⣴⣞⡽⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡟⢷⣼⣿⠀⠀⠀⠀⠉⠛⠓⠛⢛⢛⣭⠄⠀⠀⠀⡀⢹⣿⣿⣧⣤⡈⢻⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡶⣽⣿⡾⠂⠀⡀⠀⠀⠀⠀⣴⡿⠳⣤⣤⣤⣤⣽⣾⣿⣿⣿⣿⣿⣄⣯⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⢿⣷⠀⠀⠿⠂⠀⠀⢸⣿⣠⣴⣿⣿⣦⣿⣿⣿⣟⣿⣿⣿⣯⣿⣟⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⠰⢲⠄⣦⣤⢲⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣷⡀⣼⠀⢸⢡⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢹⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⡏⢷⣼⡄⠈⢸⣿⣿⣿⠋⠀⠀⣀⣤⣤⣤⣤⣴⣿⣿⣿⣿⣟⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⢀⣴⣾⣿⣿⣿⡇⠈⠻⣿⡀⢸⣿⣿⣿⣿⣦⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⡟⠀⠃⠈⠁\n"
        "⢀⣀⠀⠀⠀⢀⣀⡀⠀⢠⣍⣉⣴⣿⣿⣿⣿⣿⣿⣇⠀⠀⠈⠻⣾⣿⣿⣿⣿⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠋⠉⣉⡉⠉⠉⠉⣉⡩⠯⠉⠁⣄⣤⠀⠀⠀⠀⠀⠀⠀\n"
        "⣁⣠⣄⣠⣤⣤⣤⣤⣤⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠸⢿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣤⣴⣶⣄⡉⢿⠶⠁⣠⣶⡆⠀⠀⠀⠀⠀⠀⣠\n"
        "⣬⣿⣏⣹⣿⣭⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⢹⣿⣿⣿⣼⣿⣯⠉⠉⠀⣠⣴⣷⣿⣿⣿⡟⠀⠀⢀⣉⢀⡀⠛\n"
        "⣁⣀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠈⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢀⣾⣿⣿⣿⠙⣿⣿⣷⣤⣾⡿⣿⣿⣿⣿⣿⣿⣿⡄⢀⡀⠈⠛⠛\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠛⠁⣸⣿⣿⣿⣿⣤⣿⣿⣿⣿⣿⣿⣿⡇⢙⡿⣿⣿⣿⣷⣜⣿⣦⡀⠀\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣄⣸⣿⣿⡿⠀⣾⣿⣿⡏⠀⢠⣿⣿⣿⣿⣿⡏⢼⣿⣿⣿⣿⣿⣿⣿⣶⣯⡔⣽⣟⠿⣿⣿⣛⢷⡄\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣉⠉⠉⢉⣛⣿⣿⣿⣷⣦⣿⣿⣿⣿⣿⣿⣷⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣛⠛⠀\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⣾⣿⣿⣿⣿⣿⣿⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",

        // Bull of Heaven wikipedia page
        "Bull of Heaven is an American experimental/avant-garde group. The band originally consisted\n"
        "of Clayton Counts and Neil Keener, with help from various contributors. After Counts' death,\n"
        "Keener remains the only member left.\n"
        "Both key members behind Bull of Heaven started with a variety of earlier projects. Neil\n"
        "Keener was (and in some cases, still is) involved with several punk rock and post-hardcore\n"
        "bands, including Planes Mistaken for Stars, Git Some, Red Cloud West, and Wovenhand.\n"
        "Clayton Counts was also involved in Git Some, before he and Neil moved from Chicago to Denver,\n"
        "where Bull of Heaven was founded. Counts also gained notoriety in September 2006 when he created a\n"
        "mash-up of The Beach Boys' Pet Sounds with The Beatles' Sgt. Pepper's Lonely Hearts Club Band,\n"
        "aptly titled Sgt. Petsound's Lonely Hearts Club Band and credited to the band The Beachles.\n"
        "Various blogs and news sites favoured it; however, Counts was issued with a cease and desist.\n"
        "Bull of Heaven's first piece, 001: Weed Problem, was released on their site on January 31, 2008.\n"
        "The same time the following year, the band had already released more than fifty pieces,\n"
        "totalling nearly three hundred hours of music. Nearly all of Bull of Heaven's song titles are sourced from\n"
        "(sometimes obscure) literature. Even at this early stage in the band's history, they were already becoming\n"
        "known for their incredible song lengths; 019: Hypnosis, Drugs, and Mind Control (The Beginning: A Touch)\n"
        "is eight hours long, 028: Even to the Edge of Doom is twenty-four hours long, 044:\n"
        "A Corpse in My Arms on Awakening breaks the one-day mark at thirty-seven hours long,\n"
        "but is surpassed by 045: The Wicked Cease From Struggling which is one\n"
        "hundred sixty-eight hours long.",

        "|      Publicly available information (make sure to bully him)     |\n"
        "discord - dist#4348 , dist#0098\n"
        "github - ElMagoDist\n"
        "tiktok - elmagodist\n"
        "email - dist.information@gmail.com\n"
        "instagram - paramountmessi\n"
        "twitter - argentiniangoat\n"
        "game guardian - dist94\n"
        "youtube - @dist94\n"
        "minecraft hypixel - dist94\n"
        "roblox - amigodist\n"
        "\n"
        "|      Personal Information        |\n"
        "name - Josh\n"
        "surname - Unknown\n"
        "age - 17\n"
        "IP address 220.253.26.107 (Australia)\n"
        "Vulnerable ports - 53\n"
        "OS: Microsoft Windows 10 Pro(x64) - Not Activated\n"
        "phone number - +61 434782475\n"
        "\n"
        "|      PC Information        |"
        "UserName - dist\n"
        "PCName - DESKTOP-AOFVI56\n"
        "Platform - Win32NT\n"
        "OS - Microsoft Windows 10 Pro SP0 x64"
        "GPU - Intel(R) HD Graphics 4600"
        "CPU - Intel  i5-4590  @ 3.30GHz"
        "Ram - 7.91 GB"
        "Identifier - Intel64 Family 6 Model 60 Stepping 3\n"
        "BIOSVersion - A25\n"
        "BIOSReleaseDate - 05/30/2019\n"
        "SystemProductName - OptiPlex 9020\n"
        "MachineType - Desktop\n"
        "Antivirus - Windows Defender\n"
        "Filewall - N/A\n"
        "Mac Address - 989096CFF527\n"
        "HDD Serial - TW0XRV8D550854993654 \n"
        "Default Browser - Iexplore\n"
        "Current Language - EN\n"
        "\n"
        "|      Address     |"
        "address - 16 MacKay Rd, Manor Lakes VIC 3024, Australia\n"
        "street view (3D map) - https://maps.app.goo.gl/LEcQZMbuNSLMNCsg6\n"
        "normal map (2D map) - https://maps.app.goo.gl/9GCSqXioqVxFsKrq8\n"
        "coordinates - -37.87859513983189, 144.60322989833057\n"

};

const char *avatarRPC[] = {
        "avatar_unknown",
        "avatar_up_future_ninja",
        "avatar_mr_streamer",
        "avatar_king_of_bros",
        "avatar_digital_hero",
        "avatar_3catspammer",
        "avatar_robotic",
        "avatar_log",
        "avatar_wooden",
};

enum PhotonTargets
{
    All = 0,
    Others = 1,
    MasterClient = 2,
    AllBuffered = 3,
    OthersBuffered = 4,
    AllViaServer = 5,
    AllBufferedViaServer = 6,
    SelfViaServer = 7
};

// !! _levelReloadEventOptions is a private field in NetworkingPeer
// !! AsynchLevelLoadCall doesn't matter, can be both true or false
// !! OpRaiseEvent is in NetworkingPeer
// // // // public override bool OpRaiseEvent(byte eventCode, object customEventContent, bool sendReliable, RaiseEventOptions raiseEventOptions)
// OpRaiseEvent (PunEvent.levelReload, AsynchLevelLoadCall, true, _levelReloadEventOptions);

enum PunEvent
{
    RPC = 200,
    SendSerialize = 201,
    Instantiation = 202,
    CloseConnection = 203,
    Destroy = 204,
    RemoveCachedRPCs = 205,
    SendSerializeReliable = 206,  // TS: added this but it's not really needed anymore
    DestroyPlayer = 207,  // TS: added to make others remove all GOs of a player
    AssignMaster = 208,  // TS: added to assign someone master client (overriding the current)
    OwnershipRequest = 209,
    OwnershipTransfer = 210,
    VacantViewIds = 211,
    levelReload = 212,
};

enum EventEnum
{
    ActivateMechRPC = 0,
    AddBonusAfterKillPlayerRPC = 1,
    AddForceRPC = 2,
    AddFreezerRayWithLength = 3,
    AddPaticleBazeRPC = 4,
    AddPlayerInCapturePoint = 5,
    AddScoreDuckHuntRPC = 6,
    AddWeaponAfterKillPlayerRPC = 7,
    AdvancedEffectRPC = 8,
    AdvancedEffectWithSenderRPC = 9,
    ApplyDamageRPC = 10,
    ApplyDebuffRPC = 11,
    ChargeGunAnimation = 12,
    ClearScoreCommandInFlagGameRPC = 13,
    Collide = 14,
    CountKillsCommandSynch = 15,
    CreateChestRPC = 16,
    DeactivateMechRPC = 17,
    DestroyRpc = 18,
    GetInPlayerRPC = 19,
    ShowSelectedFortNotification = 20,
    fireFlash = 21,
    GetBonusRewardRPC = 22,
    ActivateGadgetRPC = 23,
    GetDamageRPC = 24,
    RespawnRPC = 25,
    Go = 26,
    GoBazaRPC = 27,
    GoMatchRPC = 28,
    HoleRPC = 29,
    ImDeadInHungerGamesRPC = 30,
    imDeath = 31,
    ImKilledRPC = 32,
    IsVisible_RPC = 33,
    KilledByRPC = 34,
    LikeRPC = 35,
    MakeBonusRPC = 36,
    MeKillRPC = 37,
    OpponentLeftGame = 38,
    PlayDestroyEffectRpc = 39,
    PlayerEffectRPC = 40,
    PlayMusic = 41,
    PlayPortalSoundRPC = 42,
    PlayZombieAttackRPC = 43,
    PlayZombieRunRPC = 44,
    plusCountKillsCommand = 45,
    CheckActivityRPC = 46,
    HitByVehicleRPC = 47,
    ReloadGun = 48,
    RemoveBonusRPC = 49,
    RemoveBonusWithRewardRPC = 50,
    RemovePlayerInCapturePoint = 51,
    ResumeMatchRPC = 52,
    RevengeRequestRPC = 53,
    SendBuffParameters = 54,
    SendChatMessageWithIcon = 55,
    SendSystemMessegeFromFlagAddScoreRPC = 56,
    SendSystemMessegeFromFlagDroppedRPC = 57,
    SendSystemMessegeFromFlagReturnedRPC = 58,
    SetArmorVisInvisibleRPC = 59,
    setBootsRPC = 60,
    SetBotHealthRPC = 61,
    setCapeRPC = 62,
    SetCaptureRPC = 63,
    SetEnemyArmor = 64,
    SetEnemyBoots = 65,
    SetEnemyCape = 66,
    SetEnemyHat = 67,
    SetEnemyMask = 68,
    SetEnemyPet = 69,
    SetEnemySkin = 70,
    SetEnemyWeapon = 71,
    SetGadgetEffectActiveRPC = 72,
    SetGadgetesRPC = 73,
    SetHatWithInvisebleRPC = 74,
    SetBigHeadRPC = 75,
    SetJetpackEnabledRPC = 76,
    SetJetpackParticleEnabledRPC = 77,
    SetMaskRPC = 78,
    SetMyClanTexture = 79,
    SetMySkin = 80,
    SetNickName = 81,
    SetNOCaptureRPC = 82,
    SetPixelBookID = 83,
    SetRocketActive = 84,
    SetRocketActiveWithCharge = 85,
    SetRocketStickedRPC = 86,
    SetTargetRPC = 87,
    SetVisibleFireEffectRpc = 88,
    SetWeaponRPC = 89,
    SetWeaponSkinRPC = 90,
    SetWearIsInvisibleRPC = 91,
    ShotRPC = 92,
    ShowBonuseParticleRPC = 93,
    ShowExplosion = 94,
    ShowMultyKillRPC = 95,
    SinchCapture = 96,
    SlowdownRPC = 97,
    StartFlashRPC = 98,
    StartGame = 99,
    StartMatchRPC = 100,
    StartNewRespanObjectRpc = 101,
    StartRocketRPC = 102,
    StartShootLoopRPC = 103,
    StartTurretRPC = 104,
    SynchCaptureCounter = 105,
    SynchCaptureCounterNewPlayer = 106,
    SynchGameRating = 107,
    SynchGameTimer = 108,
    SynchNamberSpawnZoneRPC = 109,
    SynchNumUpdateRPC = 110,
    SynchronizeTimeRPC = 111,
    SynchScoreCommandRPC = 112,
    SynchScoresCommandsNewPlayerRPC = 113,
    SynchScoresCommandsRPC = 114,
    SynchStartTimer = 115,
    SynhCommandRPC = 116,
    SynhCountKillsRPC = 117,
    SynhDeltaHealthRPC = 118,
    SynhHealthRPC = 119,
    SynhIsZoming = 120,
    SynhNameRPC = 121,
    SynhRanksRPC = 122,
    SynhScoreRPC = 123,
    SynhDeltaArmorRPC = 124,
    PropertyRPC = 125,
    winInHungerRPC = 126,
    SetPlayerUniqID = 127,
    SynchLivesItems = 128,
    RegisterPlayerRPC = 129,
    SetGamemodeRPC = 130,
    SetMapRPC = 131,
    StartGameRPC = 132,
    SetReadyRPC = 133,
    QuitFromSquadRPC = 134,
    ShowStartGameRPC = 135,
    StartTimerRPC = 136,
    KickPlayerRPC = 137,
    SynchCurrentCategory = 138,
    ResetVersusTimerRPC = 139,
    StartAirDropItemRPC = 140,
    MakeBetRPC = 141,
    GoTeamMatchRPC = 142,
    StartTeamMatchRPC = 143,
    SynchronizeMatchTimeRPC = 144,
    SetRocketActiveWithNumSmoke = 145,
    SynhDeathCountRPC = 146,
    GoRevengeMatchRPC = 147,
    EndRoundRPC = 148,
    SynchronizeGoTimeRPC = 149,
    SyncronizeTeamWins = 150,
    FireFlashDamagebleRPC = 151,
    SetMaxArmorAndHealthRPC = 152,
    SendEmojiRPC = 153,
    SynchGetGadgets = 154,
    SyncTramPosition = 155,
    UnregisterPlayerRPC = 156,
    SyncLastMoveTime = 157,
    RemoveTargetRPC = 158,
    AttackGateRPC = 159,
    ShotArtilleryRPC = 160,
    SetDestinationRPC = 161,
    SetEquipRPC = 162,
    ShowEndEventRPC = 163,
    ShowEndEventNotificationRPC = 164,
    PlayingInSquadRPC = 165,
    SynchCombatLevelRPC = 166,
    SendPetIdRPC = 167,
    SynchGameLeague = 168,
    ActiveChunkChangedRPC = 169,
    GetBonusRPC = 170,
    SetGliderRPC = 171,
    AddWeaponAfterBonusPreviewRPC = 172,
    RemoveWeaponPreviewRPC = 173,
    SetRoyaleAvatarRPC = 174,
    SetMapPositionSquadRPC = 175,
    PlayerInjuredRPC = 176,
    SynhHealthInjuredRPC = 177,
    PlayerInjuryHealedRPC = 178,
    SetLandingTrailRPC = 179,
    SetUserMapMarkerRPC = 180,
    RemoveUserMapMarkerRPC = 181,
    FlyOnGliderSynchRPC = 182,
    BattleRoyaleSquadMemberKilledRPC = 183,
    HealingByPlayerRPC = 184,
    PlayerInjuryHealingProgressRPC = 185,
    WinRequestRPC = 186,
    SetMyAvatar = 187,
    SetEnemyAvatar = 188,
    SetEquipTypeRPC = 189,
    SynchMinigunRotationRPC = 190,
    PlayZombieBeforeAttackRPC = 191,
    SendNewEmojiRPC = 192,
    SynchVehicleParamsRPC = 193,
    SendBattleEmojiRPC = 194,
    SynchVehicleColorRPC = 195,
    SendChangeMobRPC = 196,
    EnterInTrigger = 197,
    SynchWeaponModulesRPC = 198,
    SynchArmorModulesRPC = 199,
    SetModuleGadgetEffectActiveRPC = 200,
    CreateRocketRPC = 201,
    ShowEffectOnOtherPlayersRPC = 202,
    SetParticleToWeaponRPC = 203,
    RegenerateHealthMob = 204,
    SendKillMob = 205,
    SynhDeltaHealthFromWeaponRPC = 206,
    JumpDisableRPC = 207,
    SetPortalRPC = 208,
    ActivatePolymorphRPC = 209,
    DeactivatePolymorphRPC = 210,
    AlternativeMobAttack = 211,
    AlternativeMobShot = 212,
    DetonateKamikadze = 213,
    SetWeaponLevel = 214,
    MarkEnemy = 215,
    GetDamageToShieldRPC = 216,
    SendOnGroundEffect = 217,
    PluginRPC = 218,
    EnableTeleportEffectsRPC = 219,
    AddAmmoFromWeaponRPC = 220,
    KillerInvisiblityRPC = 221,
    SyncGadgetReflectorCoeffRPC = 222,
    SynchVipStatusRPC = 223,
    InviteToSquadRPC = 224,
    JoinSquadRPC = 225,
    InviteToSquadFailRPC = 226,
    SyncBreakableObjects = 227,
    FreeFallSynchRPC = 228,
    SyncCableCarRPC = 229,
    StartPlantingBomb = 230,
    ResetPlantingBomb = 231,
    StartDefusingBomb = 232,
    ResetDefusingBomb = 233,
    SetIsPaidTransport = 234,
    SyncOwnerTransport = 235,
    SyncCharIdRPC = 236,
    SyncTeammateRegenByMe = 237,
    BossSpawned = 238,
    NewPlayerFillSafe = 239,
    SetPlayerWantedRPC = 240
};

const char* rpcEntries[] = {
        "ActivateMechRPC",
        "AddBonusAfterKillPlayerRPC",
        "AddForceRPC",
        "AddFreezerRayWithLength",
        "AddPaticleBazeRPC",
        "AddPlayerInCapturePoint",
        "AddScoreDuckHuntRPC",
        "AddWeaponAfterKillPlayerRPC",
        "AdvancedEffectRPC",
        "AdvancedEffectWithSenderRPC",
        "ApplyDamageRPC",
        "ApplyDebuffRPC",
        "ChargeGunAnimation",
        "ClearScoreCommandInFlagGameRPC",
        "Collide",
        "CountKillsCommandSynch",
        "CreateChestRPC",
        "DeactivateMechRPC",
        "DestroyRpc",
        "GetInPlayerRPC",
        "ShowSelectedFortNotification",
        "fireFlash",
        "GetBonusRewardRPC",
        "ActivateGadgetRPC",
        "GetDamageRPC",
        "RespawnRPC",
        "Go",
        "GoBazaRPC",
        "GoMatchRPC",
        "HoleRPC",
        "ImDeadInHungerGamesRPC",
        "imDeath",
        "ImKilledRPC",
        "IsVisible_RPC",
        "KilledByRPC",
        "LikeRPC",
        "MakeBonusRPC",
        "MeKillRPC",
        "OpponentLeftGame",
        "PlayDestroyEffectRpc",
        "PlayerEffectRPC",
        "PlayMusic",
        "PlayPortalSoundRPC",
        "PlayZombieAttackRPC",
        "PlayZombieRunRPC",
        "plusCountKillsCommand",
        "CheckActivityRPC",
        "HitByVehicleRPC",
        "ReloadGun",
        "RemoveBonusRPC",
        "RemoveBonusWithRewardRPC",
        "RemovePlayerInCapturePoint",
        "ResumeMatchRPC",
        "RevengeRequestRPC",
        "SendBuffParameters",
        "SendChatMessageWithIcon",
        "SendSystemMessegeFromFlagAddScoreRPC",
        "SendSystemMessegeFromFlagDroppedRPC",
        "SendSystemMessegeFromFlagReturnedRPC",
        "SetArmorVisInvisibleRPC",
        "setBootsRPC",
        "SetBotHealthRPC",
        "setCapeRPC",
        "SetCaptureRPC",
        "SetEnemyArmor",
        "SetEnemyBoots",
        "SetEnemyCape",
        "SetEnemyHat",
        "SetEnemyMask",
        "SetEnemyPet",
        "SetEnemySkin",
        "SetEnemyWeapon",
        "SetGadgetEffectActiveRPC",
        "SetGadgetesRPC",
        "SetHatWithInvisebleRPC",
        "SetBigHeadRPC",
        "SetJetpackEnabledRPC",
        "SetJetpackParticleEnabledRPC",
        "SetMaskRPC",
        "SetMyClanTexture",
        "SetMySkin",
        "SetNickName",
        "SetNOCaptureRPC",
        "SetPixelBookID",
        "SetRocketActive",
        "SetRocketActiveWithCharge",
        "SetRocketStickedRPC",
        "SetTargetRPC",
        "SetVisibleFireEffectRpc",
        "SetWeaponRPC",
        "SetWeaponSkinRPC",
        "SetWearIsInvisibleRPC",
        "ShotRPC",
        "ShowBonuseParticleRPC",
        "ShowExplosion",
        "ShowMultyKillRPC",
        "SinchCapture",
        "SlowdownRPC",
        "StartFlashRPC",
        "StartGame",
        "StartMatchRPC",
        "StartNewRespanObjectRpc",
        "StartRocketRPC",
        "StartShootLoopRPC",
        "StartTurretRPC",
        "SynchCaptureCounter",
        "SynchCaptureCounterNewPlayer",
        "SynchGameRating",
        "SynchGameTimer",
        "SynchNamberSpawnZoneRPC",
        "SynchNumUpdateRPC",
        "SynchronizeTimeRPC",
        "SynchScoreCommandRPC",
        "SynchScoresCommandsNewPlayerRPC",
        "SynchScoresCommandsRPC",
        "SynchStartTimer",
        "SynhCommandRPC",
        "SynhCountKillsRPC",
        "SynhDeltaHealthRPC",
        "SynhHealthRPC",
        "SynhIsZoming",
        "SynhNameRPC",
        "SynhRanksRPC",
        "SynhScoreRPC",
        "SynhDeltaArmorRPC",
        "PropertyRPC",
        "winInHungerRPC",
        "SetPlayerUniqID",
        "SynchLivesItems",
        "RegisterPlayerRPC",
        "SetGamemodeRPC",
        "SetMapRPC",
        "StartGameRPC",
        "SetReadyRPC",
        "QuitFromSquadRPC",
        "ShowStartGameRPC",
        "StartTimerRPC",
        "KickPlayerRPC",
        "SynchCurrentCategory",
        "ResetVersusTimerRPC",
        "StartAirDropItemRPC",
        "MakeBetRPC",
        "GoTeamMatchRPC",
        "StartTeamMatchRPC",
        "SynchronizeMatchTimeRPC",
        "SetRocketActiveWithNumSmoke",
        "SynhDeathCountRPC",
        "GoRevengeMatchRPC",
        "EndRoundRPC",
        "SynchronizeGoTimeRPC",
        "SyncronizeTeamWins",
        "FireFlashDamagebleRPC",
        "SetMaxArmorAndHealthRPC",
        "SendEmojiRPC",
        "SynchGetGadgets",
        "SyncTramPosition",
        "UnregisterPlayerRPC",
        "SyncLastMoveTime",
        "RemoveTargetRPC",
        "AttackGateRPC",
        "ShotArtilleryRPC",
        "SetDestinationRPC",
        "SetEquipRPC",
        "ShowEndEventRPC",
        "ShowEndEventNotificationRPC",
        "PlayingInSquadRPC",
        "SynchCombatLevelRPC",
        "SendPetIdRPC",
        "SynchGameLeague",
        "ActiveChunkChangedRPC",
        "GetBonusRPC",
        "SetGliderRPC",
        "AddWeaponAfterBonusPreviewRPC",
        "RemoveWeaponPreviewRPC",
        "SetRoyaleAvatarRPC",
        "SetMapPositionSquadRPC",
        "PlayerInjuredRPC",
        "SynhHealthInjuredRPC",
        "PlayerInjuryHealedRPC",
        "SetLandingTrailRPC",
        "SetUserMapMarkerRPC",
        "RemoveUserMapMarkerRPC",
        "FlyOnGliderSynchRPC",
        "BattleRoyaleSquadMemberKilledRPC",
        "HealingByPlayerRPC",
        "PlayerInjuryHealingProgressRPC",
        "WinRequestRPC",
        "SetMyAvatar",
        "SetEnemyAvatar",
        "SetEquipTypeRPC",
        "SynchMinigunRotationRPC",
        "PlayZombieBeforeAttackRPC",
        "SendNewEmojiRPC",
        "SynchVehicleParamsRPC",
        "SendBattleEmojiRPC",
        "SynchVehicleColorRPC",
        "SendChangeMobRPC",
        "EnterInTrigger",
        "SynchWeaponModulesRPC",
        "SynchArmorModulesRPC",
        "SetModuleGadgetEffectActiveRPC",
        "CreateRocketRPC",
        "ShowEffectOnOtherPlayersRPC",
        "SetParticleToWeaponRPC",
        "RegenerateHealthMob",
        "SendKillMob",
        "SynhDeltaHealthFromWeaponRPC",
        "JumpDisableRPC",
        "SetPortalRPC",
        "ActivatePolymorphRPC",
        "DeactivatePolymorphRPC",
        "AlternativeMobAttack",
        "AlternativeMobShot",
        "DetonateKamikadze",
        "SetWeaponLevel",
        "MarkEnemy",
        "GetDamageToShieldRPC",
        "SendOnGroundEffect",
        "PluginRPC",
        "EnableTeleportEffectsRPC",
        "AddAmmoFromWeaponRPC",
        "KillerInvisiblityRPC",
        "SyncGadgetReflectorCoeffRPC",
        "SynchVipStatusRPC",
        "InviteToSquadRPC",
        "JoinSquadRPC",
        "InviteToSquadFailRPC",
        "SyncBreakableObjects",
        "FreeFallSynchRPC",
        "SyncCableCarRPC",
        "StartPlantingBomb",
        "ResetPlantingBomb",
        "StartDefusingBomb",
        "ResetDefusingBomb",
        "SetIsPaidTransport",
        "SyncOwnerTransport",
        "SyncCharIdRPC",
        "SyncTeammateRegenByMe",
        "BossSpawned",
        "NewPlayerFillSafe",
        "SetPlayerWantedRPC",
        "InitMobSpawnPoint"
};

std::vector<int> gadgetIds = {36007, 42007, 47007, 1007, 2007, 73007, 75007, 74007, 3007, 56007, 57007, 58007, 62007, 61007, 68007, 67007, 66007, 65007, 72007, 63007, 64007, 60007, 59007, 70007, 69007, 78007, 43007, 40007, 4007, 5007, 46007, 6007, 7007, 8007, 9007, 10007, 11007, 12007, 13007, 41007, 76007, 14007, 15007, 16007, 17007, 18007, 19007, 20007, 21007, 22007, 23007, 24007, 25007, 55007, 44007, 26007, 35007, 27007, 28007, 29007, 30007, 38007, 31007, 45007, 32007, 33007, 37007};
const char* analyticsCauses[] = {
    "None", "OfferWall", "fortItem", "VideoFreeAward", "Leprechaunt", "lobbyItem", "maxUpPet", "inappBonus", "GiftControllerGiveReward", "ProvideOfferItem", "DuelReturnBet", "RewardedLikeButton", "StoreKitAmazon", "StoreKitAndroid", "StoreKit", "Bank", "ItemSystem", "BattlePassRewardWindowController", "BattlePassSeeNewChallenge", "RewardSubscriptionNewsEmail", "ModulesMigrationToV2", "TrainingCapital", "EndSeasonChestsGameEvent", "ClanChest", "GameEventReward", "Gift", "Offer", "GameEventBloggerButton", "returnDuelBet", "SubscribeToBlogger", "ModuleChest", "Almanach", "BattlePass", "EventTournament", "GameTask", "Battle", "BattleBonus", "Tournament", "BattlePassEndSeason", "LevelUp", "Campaing", "BrawlReward", "StorePromotionPurchase", "ClanWarGiveTributeReward", "ClanWarGiveRewardEventMonsterSiege", "ClanWarGiveRewardEventFortRaid", "ClanWarGiveRewardCaptureCell", "ClanWarGiveRewardWinEvent", "OpenLootBox", "SubscriptionOfferTrial", "SubscriptionOfferPaid", "ClanWarGiveEndReward", "UnpackGift", "ClanItemFinishUpgradeRefund", "ClanSilverDirectBuy", "ClanLootBoxFreeInStorePromotion", "ClanLootBoxPurchaseInStorePromotion", "RewardSubcribeMailBox", "RewardDeveloperMessageMailbox", "ClanWarGiveAutoTributeReward", "ClanRankPromoteReward", "ClanGovernorTaskReward", "BlackMarketBuyCell", "ConnectSceneChestOpen", "ConnectSceneModeTapReward", "ExtraRewardForVideoAfterMatch", "GameEventsChestsMigration", "MatchRewards", "MainStore", "TrophyRoadGiveReward", "ConnectSceneRollbackMigration", "ConstructableOffersPromotionBuy", "Marathon", "GameEventSuperSpin", "PiggyPromotion", "ClanPromotionRefund", "DoubleOffers", "ManualPromotion", "Vip20", "FreeDailyGift", "Vip20Rewards", "PiggyRewards", "RewardForPickupsInFreeMode", "NoviceDoubleOffers", "ChangeLogCollectReward", "ProgressRoad", "TutorialGameEventChest", "VeteranLootBox", "GameOffer", "V2V3TournamentMigration", "CleanLobbyMigrate", "GameModeHubTapReward", "AutoOpenLootBox", "TournamentV3", "ShopCompetition", "PixelPassEndSeason", "PixelPassGiveEliteReward", "PixelPassGiveLevelReward", "PixelPassStore", "PixelPassTask", "FreePlayTask", "PixelPassStore_inapp", "PixelPassStore_exchange", "LackBuy", "Subscription20", "RewardedInterstitial", "Promocode", "FreeStuff", "SocialReward", "Refund", "RouletteAdsSpin", "RouletteAdsProgressBar", "RouletteAds", "RouletteAdsStore", "RouletteAdsBanner", "ClanWarV2Task", "ClanWarV2EventBattle", "CardRouletteObtainReward", "TopUpAds", "TopUp", "AdventCalendarOpenCell", "ConfrontationEventGiveRewards", "Leaderboard2023WinterGameModeGiveRewards", "TemplateEventPurchaseCell", "OfferWallV2", "AutoOpenPackagedItem", "ChainOfferEventBuyCell", "ChainOfferEventRewardVideo", "TemplateEventRewardVideo", "WebShop", "Leaderboard2023AutumnGameModeGiveRewards", "TemplateEventMechanicReward", "LotteryObtainReward", "RouletteObtainReward", "GemsHarvester", "CodaShop", "Leaderboard2023HalloweenGameModeGiveRewards"
};