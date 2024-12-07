// reverse engineering the websocket, stupid devs lol!!!

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <ctime>

#include "json.hpp"
#include "Unity/Unity.h"
#include "Misc.h"
#include "obfusheader.h"
#include <random>
#include <sstream>
#include <climits>
#include <chrono>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <queue>

static std::unordered_map<std::string, int> cmdID {
  {"None", 0},
  {"SetNick", 1},
  {"AddRating", 2},
  {"SetLeagueInTournament", 3},
  {"AddCurrency", 10},
  {"GetGemOrCoinInCompany", 11},
  {"ShowComicsInCompany", 13},
  {"CompleteLevelInCompany", 14},
  {"UpdateAchivements", 15},
  {"ShowComicsInBox", 16},
  {"AddOrUpgradePet", 17},
  {"AddEgg", 18},
  {"EggHatched", 19},
  {"UpdateLobbyItems", 20},
  {"RemoveLobbyItem", 21},
  {"UpdateLobbyItemAndRewardExperience", 22},
  {"UpdateBestScore", 23},
  {"MergeCampaingSlot", 24},
  {"UpdatePlayerEquipment", 25},
  {"UpdateBool", 26},
  {"UpdateSkinList", 27},
  {"UpdateBattleRoyaleList", 28},
  {"UpdateCustomSkin", 29},
  {"DeleteCustomSkin", 30},
  {"AddPurchasedWear", 31},
  {"StartUpArmor", 32},
  {"AddPurhasedGadget", 33},
  {"SetTutorialStage", 35},
  {"PurchaseWeaponSkin", 36},
  {"GameEvents_Spin", 38},
  {"GameEvents_FreeSpin", 39},
  {"GameEvents_UpdateFreeSpin", 40},
  {"GameEvents_UpdateCurreny", 41},
  {"GameEvents_RemoveCurreny", 42},
  {"GameEvents_RemoveGameEvent", 43},
  {"GameEvents_SetDurtyChest", 44},
  {"BattlePassInitSeason", 50},
  {"BattlePassGiveDailyExp", 51},
  {"BattlePassBuyPaymentStatus", 52},
  {"BattlePassTutorialChangeState", 53},
  {"BattlePassChangeInfo", 54},
  {"BattlePassCompleteSeason", 55},
  {"BattlePassChangeChallengesProgress", 56},
  {"BattlePassBannerEndViewed", 57},
  {"BattlePassBuyLevel", 58},
  {"UpdateConfig", 60},
  {"UpdateProgress", 61},
  {"UpdateRewards", 62},
  {"Snapshot", 63},
  {"UpdateLevel", 64},
  {"UpdateExperience", 65},
  {"SpendCurrency", 66},
  {"UpdateUtilityDictionaryValue", 67},
  {"UpdateUtilityIds", 68},
  {"UpdateWeaponsGotInCampaing", 69},
  {"GatchaGifts_UpdateFreeSpin", 71},
  {"GatchaGifts_UpdateGiftIndex", 72},
  {"GatchaGifts_UpdateSpinStep", 73},
  {"GatchaGifts_UpdateCachedState", 74},
  {"GatchaGifts_UpdateGiftList", 75},
  {"GatchaGifts_UpdateGiftTime", 76},
  {"GatchaGifts_UpdateConfigVersion", 77},
  {"InventoryAddItemExpiryOnServer", 78},
  {"InventoryAddItemExpiry", 79},
  {"InventoryAddItemConsumable", 80},
  {"InventoryRemoveItemConsumable", 81},
  {"InventoryAddItemUnique", 82},
  {"InventoryRemoveItemUnique", 83},
  {"InventoryAddItemSingle", 84},
  {"InventoryRemoveItemSingle", 85},
  {"InventoryRemoveItemExpiry", 86},
  {"ModuleInfoIncreaseUp", 87},
  {"ModuleStorageAddModule", 88},
  {"ModuleStorageRemoveModule", 89},
  {"AddWeapon", 100},
  {"StartUpgradingWeapon", 101},
  {"FinishUpgradingWeapon", 102},
  {"StartCraftItem", 103},
  {"FinishCraftItem", 104},
  {"UpdateFirstUps", 105},
  {"EmptyCommand", 106},
  {"AddTryGun", 110},
  {"DecreaseTryGunMatchesCount", 111},
  {"AddTryGunOffer", 112},
  {"UpdateTryGunTime", 113},
  {"RemoveTryGunOffer", 114},
  {"RemoveTryGun", 115},
  {"EquipWeaponSkin", 116},
  {"UpdateLobbyItemTimer", 117},
  {"UpdateEgg", 118},
  {"AddDetails", 120},
  {"UpdateBRVehicle", 130},
  {"UpdateUpgradingBRVehicle", 131},
  {"AddWeaponV17", 132},
  {"AddTryGunV17", 133},
  {"RemoveTryGunV17", 134},
  {"AddTryGunOfferV17", 135},
  {"RemoveTryGunOfferV17", 136},
  {"DecreaseTryGunMatchesCountV17", 137},
  {"UpdateTryGunTimeV17", 138},
  {"UpdateFirstUpsV17", 139},
  {"Offers_ResetSeason", 141},
  {"ChangeRank", 142},
  {"EquipWeaponSkinV2", 143},
  {"UnequipWeaponSkinV2", 144},
  {"AddTryGunBuffV17", 145},
  {"GameTaskChangeProgress", 150},
  {"GameTaskCompleted", 151},
  {"GameTaskRewarded", 152},
  {"GameTaskChangeInfoInBattle", 153},
  {"GameTaskReset", 154},
  {"GameTaskResetAllTasks", 155},
  {"Almanach_SetRewarded_Weapons", 160},
  {"Almanach_SetRewarded_WeaponSets", 161},
  {"Almanach_SetRewarded_CollectWeaponsSteps", 162}, 
  {"Almanach_SetCount_CollectWeaponsStep", 163},
  {"ValidateInApp", 164},
  {"AddGiftInSlot", 165},
  {"UnpackGift", 166},
  {"RemoveGiftFromSlot", 167},
  {"ReplaceGiftsInSlot", 168},
  {"Offers_AddOrUpdateOffer", 169},
  {"Offers_RemoveOffer", 170},
  {"Offers_ResetOffers", 171},
  {"Offers_UpdateOffersModule", 172},
  {"Offers_ResetOffersModule", 173},
  {"AddClanItems", 174},
  {"RemoveClanItems", 175},
  {"ReplaceClanItems", 176},
  {"ClanWarSetClanWarSeasonId", 177},
  {"ClanWarAddRewardedCaptureCellKey", 178},
  {"CheckSubscriptionOnGiveReward", 179},
  {"UpdateClanLevel", 180},
  {"UpdateClanExperience", 181},
  {"CreateClanItems", 182},
  {"AddFinishingClanItemUpgrade", 184}, 
  {"RemoveFinishingClanItemUpgrade", 185},
  {"ClanWarRewardedKeysMigration", 186},
  {"AddMailBoxRewardRecord", 187},
  {"RemoveMailBoxRewardRecord", 188},
  {"ClanWarSetGoblinCollectSilverAndShields", 189},
  {"UpdateClanLevelAndExperience", 190},
  {"BuyArmor", 191},
  {"CompleteCommonMatch", 192},
  {"CompleteBRDGMatch", 193},
  {"BlackMarketReset", 194},
  {"BlackMarketOpenCell", 195},
  {"BlackMarketUpdateCells", 196},
  {"EquipArmorSkin", 197},
  {"UnequipArmorSkin", 198},
  {"BlackMarketFirstSetClanWarSeasonId", 199},
  {"RemoveLegacyArmors", 200},
  {"ClanStorePromotionSetLastGenerateIndex", 201},
  {"ClanStorePromotionSetLastDollarPrice", 202},
  {"ClanStorePromotionReInit", 203},
  {"ClanStorePromotionSave", 204},
  {"ClanStorePromotionClear", 205},
  {"ClanBuildingsAddItems", 206},
  {"ClanBuildingsUpgradeBuilding", 207},
  {"ClanStorePromotionSendGenerateData", 208},
  {"BlackMarketUpdateRefreshCounter", 211},
  {"ClanGovernorSaveTask", 212},
  {"ClanGovernorResetCell", 213},
  {"ClanGovernorOpenCell", 214},
  {"ClanGovernorGiveCellReward", 215},
  {"ClanGovernorSetRefreshCountByVideo", 216},
  {"ClanGovernorSetRefreshCountByPrice", 217},
  {"ClanGovernorSelectBuilding", 218},
  {"ClanGovernorSetBuildingPoints", 219},
  {"ClanGovernorResetSlot", 220},
  {"AddTryGunAdCell", 221},
  {"RemoveTryGunAdCell", 222},
  {"AdsGunSetSeason", 223},
  {"AdsGunResetCells", 224},
  {"AdsGunIncrementAds", 225},
  {"AdsGunCollectTryGun", 226},
  {"AdsGunEndTryGun", 227},
  {"AdsGunSetAsShown", 228},
  {"AddPetV3", 229},
  {"UpgradePetV3", 230},
  {"RenamePetV3", 231},
  {"AddPetCardsV3", 232},
  {"RemovePetCardsV3", 233},
  {"GameModeTapReward_SetRewardTime", 234},
  {"ConnectSceneChestSetCountOpenedSmallChest", 235},
  {"ConnectSceneChestSetCountAlgorithmAttempt", 236},
  {"ConnectSceneChestSetAlgorithmWeights", 237},
  {"ConnectSceneChestSetIsInitAvailableKeys", 238},
  {"ConnectSceneChestSetAvailableKeys", 239},
  {"ConnectSceneChestSetRefreshKeyStartTime", 240},
  {"ConnectSceneChestSaveSpendKeys", 241},
  {"AddEggV3", 242},
  {"RemoveEggV3", 243},
  {"StartEggV3", 244},
  {"SpeedUpEggV3", 245},
  {"UpdateRankV2", 246},
  {"UpdateTrophyRoadLevel", 247},
  {"TrophyRoadGiveReward", 248},
  {"TrophyRoadStartSeason", 249},
  {"TrophyRoadEndSeason", 250},
  {"TrophyRoadMarkEndSeason", 251},
  {"TrophyRoadDevEndSeason", 252},
  {"TutorialComplete", 253},
  {"SaveMatchInHistory", 254},
  {"UpdateCupsForMatchHistory", 255},
  {"UpdateCupsForPlayersMatchHistory", 256},
  {"ConstructableOffersSaveGeneratedOffers", 257},
  {"ConstructableOffersSelectItemInCell", 258},
  {"ConstructableOffersIncrementPurchasedCount", 259}, 
  {"MarkWeaponSkinDiscovered", 260},
  {"Marathon", 261},
  {"GameEventDropChanceSetEventUniqueId", 262},
  {"GameEventDropChanceSetEventFirstInit", 263},
  {"GameEventDropChanceAddInappPrice", 264},
  {"GameEventDropChanceClearInappPrice", 265},
  {"GameEventDropChanceSetChances", 266},
  {"SetSecretPickedUp", 267},
  {"PiggyUpdateLevel_OLD", 268},
  {"PiggyUpdateSeason_OLD", 269},
  {"PiggyViewBanner_OLD", 270},
  {"PiggyBuyPromotion_OLD", 271},
  {"PiggyUpdateLevelView_OLD", 272},
  {"ManualOffersUpdateSlot", 273},
  {"ManualOffersBuyPromotion", 274},
  {"ManualOffersViewBanner", 275},
  {"DoubleOffersGenerateOffers", 276},
  {"DoubleOffersSetIsBought", 277},
  {"DoubleOffersSetStartTime", 278},
  {"DoubleOffersSetLastShowTime", 279},
  {"Vip20UpdatePaymentType", 280},
  {"Vip20BuyPromotion", 281},
  {"Vip20UpdateState", 282},
  {"Vip20ViewOverBanner", 283},
  {"ConstructableOffersViewBanner", 284},
  {"ManualOffersPresentationViewBanner", 285},
  {"ConstructableOffersViewPresentationBanner", 286},
  {"SetCurrentLoadoutNumber", 287},
  {"WriteUpdateLoadout", 288},
  {"Vip20CompleteMigration", 289},
  {"DoubleOffersRegenerateItems", 290},
  {"GachaNoviceGiftSetItemIndex", 291},
  {"GachaNoviceGiftCollectItem", 292},
  {"GachaNoviceGiftSetWasShow", 293},
  {"GachaNoviceGiftIncrementCountBattle", 294},
  {"GachaNoviceGiftCompleteTutorial", 295},
  {"PiggyStartSeason", 296},
  {"PiggyCompleteSeason_OLD_V2", 297},
  {"PiggyFakeCompleteSeason", 298},
  {"PiggyGiveRewards", 299},
  {"PiggyBuyPromotion", 300},
  {"PiggyUpdateLevel", 301},
  {"PiggyViewBanner", 302},
  {"PiggyUpdateLevelView", 303},
  {"NoviceDoubleOffersOpen", 304},
  {"NoviceDoubleOffersStart", 305},
  {"NoviceDoubleOffersShow", 306},
  {"NoviceDoubleOffersPurchase", 307},
  {"ProgressRoadUpdateRewardsProgress", 308},
  {"PiggyCompleteSeasonV3", 309},
  {"AttributeChange", 310},
  {"ProgressRoadUpdateStateMigration", 311},
  {"ProgressRoadSetTakenRewards", 312},
  {"UniversalPromotionStartPromotion", 313},
  {"UniversalPromotionSetGroupStartCounter", 314},
  {"UniversalPromotionSetGroupCooldownStartTime", 315},
  {"UniversalPromotionBuyPromotion", 316},
  {"UniversalPromotionStopPromotion", 317},
  {"UniversalPromotionSetPromotionLastBannerView", 318},
  {"UniversalPromotionGenerate", 319},
  {"GameModeHubTapRewardsSet", 320},
  {"ShopSetBuyTime", 321},
  {"PixelPassSaveConfig", 322},
  {"PixelPassGiveLevelCellReward", 323}, 
  {"PixelPassBuyPremium", 324},
  {"PixelPassGiveEliteReward", 325},
  {"PixelPassObtainExp", 326},
  {"PixelPassSpendExp", 327},
  {"PixelPassSetIsCompleteEliteTasks", 328},
  {"PixelPassSetChangedTaskIndex", 329},
  {"PixelPassSetWatchedVideo", 330},
  {"PixelPassCloseSeason", 331},
  {"PixelPassIncrementOfferBuyCount", 332},
  {"PixelPassSaveOffersStartDay", 333},
  {"RemoveWearItemIndeces", 334},
  {"PixelPassPresentationView", 335},
  {"BattleStatisticEndMatch", 336},
  {"PixelPassAddCompleteTaskReward", 337},
  {"PixelPassRemoveCompleteTaskReward", 338},
  {"PixelPassSaveLastViewedBuyPremiumWindow", 339},
  {"UniversalPromotionSetGroupPromotionLastBannerView", 340},
  {"Subscription20Subscribe", 341},
  {"Subscription20CollectReward", 342},
  {"Subscription20CollectLastReward", 343},
  {"Subscription20RemoveSubscription", 344},
  {"Subscription20SetPromotionLastBannerView", 345},
  {"UniversalPromotionSetSeasonId", 350},
  {"PromocodeUsePromocode", 351},
  {"UpdatePlayerStats", 352},
  {"InappTransactionAddTransaction", 353},
  {"InappTransactionsMarkTransactionAsRefunded", 354},
  {"RemoveWeapon", 355},
  {"RemoveDetails", 356},
  {"RemoveBRVehicle", 357},
  {"RemoveGadget", 358},
  {"EquipWearSkin", 360},
  {"UnequipWearSkin", 361},
  {"RouletteAdsSaveConfig", 362},
  {"RouletteAdsSelectReward", 363},
  {"RouletteAdsIncrementTotalSpins", 364},
  {"RouletteAdsAddGivenProgressBarReward", 365},
  {"RouletteAdsIncrementOfferBuyCount", 366},
  {"RouletteAdsEndSeason", 367},
  {"RouletteAdsSetWatchedVideo", 368},
  {"RouletteAdsSetLastTimeAdView", 369},
  {"UpdatePlayerStatsV2", 370},
  {"AnalyticsProgress", 777}
};
enum class SlotTypes {
    PlayerInfo = 1,
    Rating = 2,
    Currency = 3,
    Leveling = 4,
    Achievement = 5,
    LobbyCraft = 6,
    Campaign = 7,
    Pets = 8,
    PlayerEquipment = 9,
    SkinsIds = 10,
    BattleRoyaleIds = 11,
    CustomSkin = 12,
    Wear = 13,
    UtilityDictionary = 14,
    UtilityIds = 15,
    Gadgets = 16,
    WeaponSkin = 17,
    BattlePass = 18,
    GameEvents = 19,
    GME = 20,
    GatchaGifts = 21,
    Weapons = 22,
    FirstUps = 23,
    Details = 24,
    BattleRoyaleVehicle = 25,
    Inventory = 26,
    ModuleStorage = 27,
    WeaponsV17 = 28,
    FirstUpsV17 = 29,
    Offers = 30,
    RankSlot = 31,
    WeaponSkinV2 = 32,
    GameTask = 33,
    AlmanachSlot = 34,
    InAppValidatorSlot = 35,
    Gifts = 36,
    ModulesInfo = 37,
    ClanItems = 38,
    ClanWar = 39,
    ClanFinishingUpgrades = 40,
    InventoryExpiry = 41,
    MailBoxRewards = 42,
    Armor = 43,
    ArmorSkins = 44,
    KillRate = 45,
    BlackMarket = 46,
    ClanStorePromotion = 47,
    ClanGovernor = 48,
    ClanBuildings = 49,
    AdsGun = 50,
    GameModeTapReward = 51,
    ConnectSceneChest = 52,
    PetsV3 = 53,
    RankV2 = 54,
    TrophyRoad = 55,
    Tutorial = 56,
    MatchHistory = 57,
    ConstructableOffers = 58,
    WeaponSkinsNotification = 59,
    GameEventDropChance = 60,
    Marathon = 61,
    MapSecretsSlot = 62,
    Piggy_OLD = 63,
    ManualOffers = 64,
    DoubleOffers = 65,
    Vip20 = 66,
    Loadouts = 67,
    GachaNoviceGift = 68,
    Piggy = 69,
    NoviceDoubleOffers = 70,
    ProgressRoad = 71,
    Attributes = 72,
    UniversalPromotion = 73,
    PixelPass = 74,
    GameModeHub = 75,
    Shop = 76,
    BattleStatistic = 77,
    Subscription20 = 78,
    Promocode = 79,
    PlayerStats = 80,
    InappTransaction = 81,
    WearSkins = 82,
    RouletteAds = 83,
    PlayerStatsV2 = 84,
    ConstructableAdsOffers = 85,
    ClanWarV2 = 86,
    CardRoulette = 87,
    TopUp = 88,
    AdventCalendar = 89,
    ConfrontationEvent = 90,
    TemplateEventsSlot = 91,
    ConfrontationEventV2 = 92,
    GameModeShop = 93,
    ChainOfferEventsSlot = 94
};

namespace ws
{
    using json = nlohmann::ordered_json;
    std::string version = "24.0.1";
    void* websocketManager = nullptr;
    int moduleLevel = 1, playerLevel = 1, currencyAmount = 0, amo_unt_thropy_ies, time_in__sec, refre___shes,
        ecx_p, cla_n_id, levelllll_l, passexp, boosteramount, boostertype, keysamount, clanitemamount, desiredLevel = 1;
    int chesttype, chestamount;
    std::string killsliderStr, deathsliderStr, headshotsliderStr, killstreaksliderStr, winstreaksliderStr, MonthlyCountSliderStr, winandmatchamountStr;
    int killslider, deathslider, headshotslider, killstreakslider, winstreakslider, MonthlyCountSlider, winandmatchamount;
    int clanrankk, clanlevell, lenght_in_seconds;
    std::string ClanIDstr;
    int rankexpsliderhack;
    std::string PlayerIDstr;
    int PlayerIDint;
    int ClanIDint;
    std::string localIp;
    int consoleClientFd = -1;
    bool console_isConnected = false;
    struct sockaddr_in consoleServerAddress;
    int test_time = 0;
    int valorloopslider;
    std::string WarIDstr;
    int WarIDint;
    std::string scoreaddthropiesstr;
    int scoreaddthropies;
    std::string currentscorestr;
    int currentscore;

    struct {
        bool isTerminated = false;
        int errorCode = 0;
        bool shouldIgnore = false;
    } terminationInfo;

    enum class Mode {
        DEATHMATCH
    };
    std::string randHex() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 255);
        std::stringstream ss;
        for (int i = 0; i < 4; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << distrib(gen);
        }
        return ss.str();
    }
    void StringToInt(int& target, const std::string& source) {
        try {
            target = std::stoi(source);
        } catch (...) {
        }
    }
    int getCurrentTimestamp() {
        auto now = std::chrono::system_clock::now();
        std::chrono::seconds currentTime = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
        return currentTime.count();
    }
    std::string RandomStringGenerator(int length) {
        const char charset[] = "0123456789abcdef";
        const int charsetSize = sizeof(charset) - 1;

        srand(static_cast<unsigned int>(time(0)));

        std::string randomString;
        randomString.reserve(length);

        for (int i = 0; i < length; ++i) {
            randomString += charset[rand() % charsetSize];
        }

        return randomString;
    }
    int random(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(min, max);
        return distrib(gen);
    }
    json _createCommand(std::string id, json params, std::vector<int> u = {140, 6}) {
        return {
                {"id", cmdID[id]},
                {"ci", randHex()},
                {"p", params},
                {"h", {}},
                {"v", version},
                {"u", u}
        };
    }


    void console_send(const char *data) {
        if (!console_isConnected) return;

        int length = strlen(data) + 1;
        char sendBuffer[length];

        strcpy(sendBuffer, data);
        sendBuffer[length] = 0;

        char *ptr = (char *) sendBuffer;

        while (length > 0) {
            int i = send(consoleClientFd, ptr, length, 0);

            if (i < 1) {
                break;
            }

            ptr += i;
            length -= i;
        }
    }

    std::string console_read() {

        std::string out;

        if (!console_isConnected) return out;

        console_send("GET");

        while (true) {
            char currByte[1];
            int i = recv(consoleClientFd, currByte, sizeof(currByte), 0);

            if (i >= 1) {
                if (currByte[0] == 0) break;
                out.push_back(currByte[0]);
            }
            else {
                break;
            }
        }
        return out;
    }

    void console_connect() {

        consoleClientFd = socket(AF_INET, SOCK_STREAM, 0);
        if (consoleClientFd < 0) {
            return;
        }

        consoleServerAddress.sin_family = AF_INET;
        consoleServerAddress.sin_port = htons(8080);

        if (inet_pton(AF_INET, localIp.c_str(), &consoleServerAddress.sin_addr) <= 0) {
            return;
        }

        if (connect(consoleClientFd, (struct sockaddr *) &consoleServerAddress,
                    sizeof(consoleServerAddress)) < 0) {
            return;
        }

        console_send("Client connected.");
        console_isConnected = true;
    }

    void console_disconnect() {
        console_send("EXIT");
        close(consoleClientFd);
        ws::console_isConnected = false;
    }

    json SendGift(int player_id, const std::string &counter) {
        if (test_time == 0) {
            LOGE("umm wtf!! time null wtf wtf wtf!!!!");
        }

        nlohmann::json result = {
                {"id", cmdID["RemoveGiftFromSlot"]},
                {"i", "b94433f8"},
                {"p", {
                               {"category", "1"},
                               {"gifts", {std::to_string(player_id) + "." + std::to_string(test_time) + "." + counter}}
                       }},
                {"h", {}},
                {"v", version},
        };

        return json::array({"update_progress", result});
    }
    json CreateGift(int player_id, int your_own_id, int _type, int amount, const std::string& counter) {
        test_time = static_cast<int>(std::round(std::time(nullptr)));
        json gift_object = {
                {"gifts", {{
                              {"id", std::to_string(player_id) + "." + std::to_string(test_time) + "." + counter},
                              {"v", 1},
                              {"from", std::to_string(your_own_id)},
                              {"for", std::to_string(player_id)},
                              {"data", {std::to_string(_type) + ":" + std::to_string(amount)}}},
                              {"pid", "pixel-pass-1_1702030335"},
                              {"ppl", "PixelPassStore"}
                }},
        };

        return json::array({"create_gifts", gift_object});
    }

    json AddCurrency(int amount, const std::string& _type, const std::string& cause = "WebShop") {
        json commands = {
                _createCommand("AddCurrency", {{"c", _type}, {"v", amount}, {"ca", 6}}, {141, 278}),
                _createCommand("AnalyticsProgress", {
                        {"eid", 1012},
                        {"params", {
                                        {"ip1", amount},
                                        {"sp1", _type},
                                        {"sp2", cause},
                                        {"ip2", 0}
                                }}
                }, {141, 278})
        };

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json SetLevel(int target_level) {
        json commands;

        if (target_level > 0) {
            for (int level = 1; level <= target_level; level += 2) {
                commands.push_back(_createCommand("UpdateLevel", {{"l", level}}));
            }
        }
        else {
            commands.push_back(_createCommand("UpdateLevel", {{"l", target_level}}));
        }

        commands.insert(commands.end(), {
                _createCommand("AnalyticsProgress", {{"eid", 52}, {"params", {{"ip1", 0}, {"ip2", 0}}}}),
                _createCommand("UpdateExperience", {{"e", 0}, {"ec", 4}, {"ad", {}}}),
                _createCommand("AnalyticsProgress", {
                        {"eid", 1043},
                        {"params", {
                                        {"ip1", levelExp[target_level] - levelExp[playerLevel]},
                                        {"ip2", levelExp[target_level]},
                                        {"ip3", levelExp[playerLevel]},
                                        {"sp1", "MultiplayerMatchReward"},
                                        {"jp1", {{"v_ProgressRoad", target_level}, {"v_Tutorial", 8}}}
                                }}
                }),
        });

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}},
                {"req_id", 0}
        };

        return json::array({"update_progress", result});
    }
    json AddThropies(int amount) {
        json commands = _createCommand("AddRating", {{"dr", amount}, {"c", 1}});

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json BuffClan(int length_in_seconds) {
        json commands;
        auto currentTime = std::chrono::system_clock::now();
        std::time_t currentTimeInSeconds = std::chrono::system_clock::to_time_t(currentTime);
        int timestampInSeconds = static_cast<int>(currentTimeInSeconds);

        commands.push_back(_createCommand("InventoryAddItemExpiry", {{"t", 1320}, {"i", 1020}, {"s", length_in_seconds}, {"st", timestampInSeconds}}));
        commands.push_back(_createCommand("AnalyticsProgress", {{"eid", 208},{"params", {{"ip1", 1},{"sp1", "GemsCurrency"},{"sp2", "offers"},{"jp1", {{{"name", "clan_silver_buff"},{"count", 0},{"type", "PlayerBuff"}}}}}}}));
        commands.push_back(_createCommand("AnalyticsProgress", {{"eid", 1020},{"params", {{"ip1", 0},{"ip2", length_in_seconds},{"ip3", 0},{"ip5", 1},{"sp1", "clan_silver_buff"},{"ip4", 1},{"sp2", "GemsCurrency"}}}}));


        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddChests(int amount, int type_) {
        json commands;

        commands.push_back(_createCommand("GameEvents_UpdateFreeSpin", {{"i", type_},{"c", amount},{"t", 0}}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }

    json CompleteEliteChallanges() {
        json commands;

        commands.push_back(_createCommand("GameTaskCompleted", {{"5_328", {{"p", 1}}},{"5_3001", {{"p", 90000}, {"c", 1}}}}));
        commands.push_back(_createCommand("GameTaskCompleted", {{"5_3002", {{"c", 1}}}}));
        commands.push_back(_createCommand("GameTaskCompleted", {{"5_3003", {{"c", 1}}}}));
        commands.push_back(_createCommand("GameTaskCompleted", {{"5_3004", {{"c", 1}}}}));
        commands.push_back(_createCommand("GameTaskCompleted", {{"5_3000", {{"c", 1}}}}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json SetClanLevelTank(int level, int clanid) {
        std::map<int, std::pair<int, int>> levelDataMap = {{1, {0, 29}}, {2, {1, 499}}, {3, {2, 1349}}, {4, {3, 5649}}, {5, {4, 10199}}, {6, {5, 18749}}, {7, {6, 38999}}, {8, {7, 141999}}, {9, {8, 219999}}, {10, {9, 220000}}};

        if (levelDataMap.find(level) != levelDataMap.end()) {
            std::pair<int, int> data = levelDataMap[level];
            json result = {{"tank_level", data.first},{"tank_points", data.second},{"clan_id", clanid}};

            return json::array({"set_clan_building_levels", result});
        }
        else {
            return json::array();
        }
    }
    json AddBlackMarketRefresh(int refreshes) {
        json commands = _createCommand("BlackMarketUpdateRefreshCounter", {{"rc", refreshes}});

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddBlackMarketExp(int xp, int clan_id) {
        json commands = _createCommand("ClanBuildingsAddItems", {{"items", {{{"i", 102015}, {"c", xp}, {"ci", clan_id}}}}});

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json SetClanRankWs(int clan_rank) {
        json commands = _createCommand("UpdateClanLevelAndExperience", {{"cr", clan_rank}});

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddBattlePassExp(int amount) {
        json commands;
        commands.push_back(_createCommand("PixelPassObtainExp", {{"e", amount}}));
        commands.push_back(_createCommand("AnalyticsProgress", {{"ip1", amount}, {"ip2", 2000}, {"sp1", "BuyLevel"}}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddKeysWS(int amount) {
        json commands;
        commands.push_back(_createCommand("GameEvents_UpdateCurreny", {{"i", "97"},{"ca", 2},{"c", amount}}));
        commands.push_back(_createCommand("AnalyticsProgress", {{"eid", 1012},{"params", {{"ip1", amount},{"sp1", "keys_fulfillment_of_desires_lottery"},{"sp2", "MainStore"},{"ip2", 0},{"sp3", "GameOffer_1728211"}}}}));
        commands.push_back(_createCommand("AnalyticsProgress", {{"eid", 1048},{"params", {{"ip1", 6015},{"ip2", amount},{"sp1", "GameOffer"},{"sp2", "1728211"}}}}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddClan(const std::string& ClanID, int index, int amount) {
        json commands;

        commands.push_back(_createCommand("InventoryRemoveItemConsumable", {{"t", 1460},{"i", 56027},{"c", 1}}));
        commands.push_back(_createCommand("CreateClanItems", {{"items", {{{"id", "302262401.1698698027.1"},{"clan", ClanID},{"item_index", 1017},{"count", amount},{"buy", false}}}}}));
        if (index == 0) {
            for (int i = 1; i < 2000; i++) {
                commands.push_back(_createCommand("AnalyticsProgress", {{"t", 1460},{"i", 56027},{"c", 1}}));
                commands.push_back(_createCommand("CreateClanItems", {{"items", {{{"id", "302262401.1698698027.1"},{"clan", ClanID},{"item_index", i*1000+17+1000},{"count", amount},{"buy", false}}}}}));
            }
        }
        else {
            commands.push_back(_createCommand("AnalyticsProgress", {{"t", 1460},{"i", 56027},{"c", 1}}));
            commands.push_back(_createCommand("CreateClanItems", {{"items", {{{"id", "302262401.1698698027.1"},{"clan", ClanID},{"item_index", index*1000+17+1000},{"count", amount},{"buy", false}}}}}));
        }
        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json CustomCape(const std::string& cape_image) {
        json commands = _createCommand("UpdateCustomSkin", {{"i", "-1"}, {"c", cape_image}, {"h", "abcdefabcdefabcdef"}});

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddBattlePassPremium() {
        json commands;

        commands.push_back(_createCommand("PixelPassBuyPremium", {}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json UpdatePlayerStats(int kills, int deaths, int headshots, int killstreak, int winstreak) {
        json commands;

        auto currentTime = std::chrono::system_clock::now();
        std::time_t currentTimeInSeconds = std::chrono::system_clock::to_time_t(currentTime);
        int timestampInSeconds = static_cast<int>(currentTimeInSeconds);
        std::tm* localTime = std::localtime(&currentTimeInSeconds);
        char dateStr[11];
        std::strftime(dateStr, sizeof(dateStr), "%m-%d-%Y", localTime);

        commands.push_back(_createCommand("UpdatePlayerStatsV2", {{"k", kills},{"d", deaths},{"w", true},{"hds", headshots},{"h", headshots},{"s", killstreak},{"ks", killstreak},{"c", false},{"tw", winstreak},{"sw", winstreak},{"sid", ""},{"dk", dateStr}}));
        commands.push_back(_createCommand("BattleStatisticEndMatch", {{"u", timestampInSeconds},{"w", 10000}}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddWinsandmatches(int index, int amount) {
        json commands;

        auto currentTime = std::chrono::system_clock::now();
        std::time_t currentTimeInSeconds = std::chrono::system_clock::to_time_t(currentTime);
        int timestampInSeconds = static_cast<int>(currentTimeInSeconds);
        std::tm* localTime = std::localtime(&currentTimeInSeconds);
        char dateStr[11];
        std::strftime(dateStr, sizeof(dateStr), "%m-%d-%Y", localTime);
        if (index == 0) {
            for (int i = 1; i < amount; i++) {
                commands.push_back(_createCommand("UpdatePlayerStatsV2", {{"k", 0},{"d", 0},{"w", true},{"hds", 0},{"h", 0},{"s", 0},{"ks", 0},{"c", false},{"tw", 0},{"sw", 0},{"sid", ""},{"dk", dateStr}}));
                commands.push_back(_createCommand("BattleStatisticEndMatch", {{"u", timestampInSeconds},{"w", 10000}}));
            }
        }
        else {
            commands.push_back(_createCommand("UpdatePlayerStatsV2", {{"k", 0},{"d", 0},{"w", true},{"hds", 0},{"h", 0},{"s", 0},{"ks", 0},{"c", false},{"tw", 0},{"sw", 0},{"sid", ""},{"dk", dateStr}}));
            commands.push_back(_createCommand("BattleStatisticEndMatch", {{"u", timestampInSeconds},{"w", 10000}}));
        }
        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddGemBoosters(int amount) {
        json commands;
        commands.push_back(_createCommand("InventoryAddItemConsumable", {{"t", 1590},{"i", 1034},{"c", amount}}));
        for (int l = 0; l < 10; l++) {
            commands.push_back(_createCommand("AnalyticsProgress", {{"ip1", 1034},{"ip2", amount},{"sp1", "GameOffer"},{"sp2", "1537211"}}));
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddParts(int index, int amount, int item_records) {
        json commands;

        if (index == 0) {
            for (int i = 1; i < 2000; i++) {
                int ItemIndex = i * 1000 + item_records;
                commands.push_back(_createCommand("AddDetails", {{"i", ItemIndex}, {"d", amount}}));
            }
        }
        else {
            int ItemIndex = index * 1000 + item_records;
            commands.push_back(_createCommand("AddDetails", {{"i", ItemIndex}, {"d", amount}}));
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json CustomSkin(const std::string& skin_image, const std::string& name) {
        json commands = _createCommand("UpdateCustomSkin", {
            {"c", skin_image},
            {"i", "-1"},
            {"h", "abcdefabcdefabcdef"}
        });

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddLobbyItems(int index) {
        json commands;
        if (index == 0) {
            for (int i = 1; i < 5000; i++) {
                commands.push_back(_createCommand("UpdateLobbyItemAndRewardExperience", {{"i", i*1000+6}}));
            }
        }
        else {
            commands.push_back(_createCommand("UpdateLobbyItemAndRewardExperience", {{"i", index*1000+6}}));
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddWeaponV17(int startIndex, int endIndex, int level, int grade) {
        json commands;

        for (int i = startIndex; i <= endIndex; i++) {
            commands.push_back(_createCommand("AddWeaponV17", {{"i", i*1000+1},{"u", {{"l", level}, {"r", grade}}}}));
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddWear(int index, const json& wearSlot, bool armor = true, int level = playerLevel) {
        json commands;
        std::vector<int> wearData;

        if (!wearSlot.empty() && !wearSlot["w"].empty()) {
            wearData = wearSlot["w"].get<std::vector<int>>();
            LOGWS("Wear size: %d", wearData.size());
        }

        if (index == 0) {
            for (int i = 1; i < 2000; i++) {
                if (!wearData.empty() && std::find(wearData.begin(), wearData.end(), i*1000+2) != wearData.end()) {
                    continue;
                }
                commands.push_back(_createCommand("AddPurchasedWear", {{"w", "a*" + std::to_string(i*1000+2)}})); // wear
                commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+29}})); // skins
                if (armor) {
                    commands.push_back(_createCommand("BuyArmor", {{"a", i*1000+2},{"u", level}})); // armor
                    commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+23}})); // armor skins
                }
            }
        }
        else {
            if (wearData.empty() || std::find(wearData.begin(), wearData.end(), index) == wearData.end()) {
                commands.push_back(_createCommand("AddPurchasedWear", {{"w", "a*" + std::to_string(index*1000+2)}}));
            }
        }

        json result = {
            {"id", cmdID["Snapshot"]},
            {"i", randHex()},
            {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddArmor(int index, int level) {
        json commands;

        if (index == 0) {
            for (int i = 1; i < 2000; i++) {
                commands.push_back(_createCommand("BuyArmor", {{"a", i*1000+2},{"u", level}}));
                commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+23}}));
            }
        }
        else {
            commands.push_back(_createCommand("BuyArmor", {{"a", index*1000+2},{"u", level}}));
        }

        json result = {
            {"id", cmdID["Snapshot"]},
            {"i", randHex()},
            {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddGadget(int index, int level, const json& gadgetSlot) {
        json commands;
        std::vector<int> existingGadgets;
        LOGWS("gadgetSlot: %s", gadgetSlot.dump().c_str());

        if (!gadgetSlot.empty() && !gadgetSlot.empty()) {
            for (auto& [key, value] : gadgetSlot.items()) {
                existingGadgets.push_back(std::stoi(key));
            }
        }

        if (index == 0) {
            for (int& currentGadget : gadgetIds) {
                if (!existingGadgets.empty() && std::find(existingGadgets.begin(), existingGadgets.end(), currentGadget) != existingGadgets.end()) {
                    continue;
                }
                commands.push_back(_createCommand("AddPurhasedGadget", {{"g", currentGadget},{"u", level}}));
            }
        }
        else {
            commands.push_back(_createCommand("AddPurhasedGadget", {{"g", index*1000+7},{"u", level}}));
        }

        json result = {
            {"id", cmdID["Snapshot"]},
            {"i", randHex()},
            {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json SetClanLevel(int level, int clanid) {
        std::map<int, std::pair<int, int>> levelDataMap = {{1, {0, 14}}, {2, {1, 124}}, {3, {2, 4159}}, {4, {3, 7869}}, {5, {4, 20239}}, {6, {5, 40469}}, {7, {6, 80939}}, {8, {7, 170999}}, {9, {8, 341999}}, {10, {9, 342000}}};

        if (levelDataMap.find(level) != levelDataMap.end()) {
            std::pair<int, int> data = levelDataMap[level];
            json result = {{"field_level", data.first}, {"field_points", data.second}, {"clan_id", clanid}};

            return json::array({"set_clan_building_levels", result});
        }
        else {
            return json::array();
        }
    }
    json HackClanRankPoints(int amount) {
        json result = {{"clan_id", ClanIDstr},{"war_id", 52134},{"member_id", PlayerIDstr},{"rank_experience", amount}};


        return json::array({"warV2_obtain_rank_experience", result});
    }
    json HackClanRankPoints2(int amount) {
        json commands;
        commands.push_back(_createCommand("AnalyticsProgress", {{"clan_id", ClanIDstr},{"war_id", 52134},{"member_id", PlayerIDstr},{"rank_experience", amount}}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json HackClanValor() {
        json result = {{"clan_id", ClanIDstr},{"war_id", WarIDint},{"shields", random(1, 25)},{"task_id", random(1, 10000)}};


        return json::array({"warV2_obtain_clan_shields", result});
    }
    json AddThropies(int score, int currentscore) {
        json result = {{"score", currentscore+score},{"league", 0},{"leaderboard_id", ""},{"platform", 1}};


        return json::array({"update_score_v3", result});
    }
    json AddThropies2(int score, int currentscore) {
        json result = {{"mode", 8},{"tournament", 1},{"rating", currentscore+score},{"league_id", 0}};


        return json::array({"synch_rating_tiers_v5", result});
    }
    json AddThropies3(int score, int currentscore) {
        json result = {{"rating", currentscore+score},{"kill_cnt", 5.0},{"death_cnt", 2.0},{"accuracy", random(0, 100)},{"mode", 8},{"tournament", 1},{"league_id", 0},{"req_id", random(100, 1000)},{"sid", RandomStringGenerator(32)}};


        return json::array({"update_player", result});
    }
    json AddThropies4(int score) {
        json commands;

        commands.push_back(_createCommand("AddRating", {{"dr", score},{"c", 1}}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddThropies5(int score) {
        json commands;

        commands.push_back(_createCommand("UpdateCupsForMatchHistory", {{"p", {{"303543357", 0},{PlayerIDstr, score}}},{"t", getCurrentTimestamp()}}));

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json SetClanRank(int level) {
        struct LevelData {
            int cr;
            int cre;
            std::string sp1;
            std::string sp2;
        };

        std::vector<LevelData> levelData = {{1, 0, "Newbie", "Newbie"}, {2, 50, "Newbie", "Recruit"}, {3, 950, "Recruit", "Fighter"}, {4, 5750, "Fighter", "Warrior"}, {5, 13700, "Warrior", "Lieutenant"}, {6, 25000, "Lieutenant", "Captain"}, {7, 37500, "Captain", "Major"}, {8, 52500, "Major", "Lt. Colonel"}, {9, 72500, "Lt. Colonel", "Colonel"}, {10, 97500, "Colonel", "General"}, {11, 130000, "General", "Emperor"}};

        json commands;

        if (level >= 1 && level <= 11) {
            const LevelData& data = levelData[level - 1];
            commands.push_back(_createCommand("UpdateClanLevelAndExperience", {{"cr", data.cr}, {"cre", data.cre}}));
            commands.push_back(_createCommand("AnalyticsProgress", {{"eid", 1017}, {"params", {{"ip1", data.cre}, {"sp1", data.sp1}, {"sp2", data.sp2}}}}));
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddMonthlyStatsTournament(int gamemodetype) {
        json result = {{"rating", 20}, {"kill_cnt", 379}, {"death_cnt", 34}, {"mode", gamemodetype}, {"tournament", 1}, {"league_id", 0}};

        return json::array({"update_player", result});
    }
    json AddMonthlyStatsNormal(int gamemodetype) {
        json result = {{"kill_cnt", 100}, {"death_cnt", 0}, {"kill_cnt_month", 100}, {"death_cnt_month", 0}, {"accuracy", 100}, {"mode", gamemodetype}, {"rating", 0}, {"league_id", 0}};

        return json::array({"update_player", result});
    }
    json AddMonthlyStatsRaid(int gamemodetype, int raidtype) {
        json result = {{"death_cnt", 0}, {"mode", gamemodetype}, {"raid_diff", raidtype}, {"rating", 0}, {"league_id", 0}};

        return json::array({"update_player", result});
    }
    json AddPet(int index, const json& petSlot, const std::vector<int>& petData = {}) {
        json commands;
        std::vector<int> ownedPetsData;

        if (!petSlot.empty() && !petSlot["p"].empty()) {
            for (auto& pet : petSlot["p"]) {
                ownedPetsData.push_back(pet["i"].get<int>());
            }
        }

        if (index == 0 && !petData.empty()) {
            for (const int& curPet : petData) {
                bool exists = false;
                if (!ownedPetsData.empty() && std::find(ownedPetsData.begin(), ownedPetsData.end(), curPet) != ownedPetsData.end()) {
                    exists = true;
                }
                if (!exists)
                    commands.push_back(_createCommand("AddPetV3", {{"i", curPet}, {"n", ""}}));
                commands.push_back(_createCommand("AddPetCardsV3", {{"i", curPet}, {"a", 260}}));
            }
        }
        else {
            commands.push_back(_createCommand("AddPetV3", {{"i", index*1000+3}, {"n", ""}}));
        }

        json result = {
            {"id", cmdID["Snapshot"]},
            {"i", randHex()},
            {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddRoyale(const json& royaleData) {
        json commands;
        std::vector<int> blacklist;

        if (!royaleData.empty()) {
            blacklist = royaleData.get<std::vector<int>>();
        }

    #ifdef DEBUG_WEBSOCKET
        for (auto& data : blacklist) {
            LOGWS("Blacklist data: %d", data);
        }
    #endif

        for (int i = 1; i <= 2000; i++) {
            if (!blacklist.empty() && std::find(blacklist.begin(), blacklist.end(), i*1000+5) != blacklist.end()) {
                continue;
            }
            commands.push_back(_createCommand("UpdateBattleRoyaleList", {{"1", i*1000+5}}));
            commands.push_back(_createCommand("UpdateBRVehicle", {{"i", i*1000+5}, {"u", 4}}));
        }

        json result = {
            {"id", cmdID["Snapshot"]},
            {"i", randHex()},
            {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }

    json GetProgress(int uniq_id, std::vector<int> slots = {}) {
        json j = {
            {"player_id", std::to_string(uniq_id)}
        };
        LOGWS("GetProgress: %d", uniq_id);

        if (!slots.empty()) {
            LOGWS("Slots size: %d", slots.size());
            for (auto& slot : slots) {
                j["slots"].push_back(slot);
            }
        }

        return json::array({"get_progress", j});
    }

    json AddWeaponSkins(int index) {
        json commands;

        if (index == 0) {
            for (int i = 1; i < 2000; i++) {
                commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+14}}));
            }
        }
        else {
            commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", index*1000+14}}));
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    json AddGraffiti(int index) {
        json commands;

        if (index == 0) {
            for (int i = 1; i < 2000; i++) {
                commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+28}}));
            }
        }
        else {
            commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", index*1000+28}}));
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}},
        };

        return json::array({"update_progress", result});
    }
    json AddModules(int index = 0, int amount = 2500) {
        json commands;

        if (index == 0) {
            for (int i = 346; i <= 387; i++) {
                commands.push_back(_createCommand("InventoryAddItemConsumable", {
                    {"t", 1155},
                    {"i", i*1000+9},
                    {"c", amount}
                }));
            }
        }
        else {
            commands.push_back(_createCommand("InventoryAddItemConsumable", {
                {"t", 1155},
                {"i", index*1000+9},
                {"c", amount} 
            }));
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }

    json UpgradeModules(int times = 10, json moduleSlot = {}, bool capLevel = false) {
        json commands;

        for (int i = 304; i <= 345; i++) {
            for (int j = 0; j < times; j++) {
                std::string key = std::to_string(i*1000+9);
                auto it = moduleSlot.find(key);
                if (it != moduleSlot.end()) {
                    int level = *it;
                    LOGWS("Module %d level: %d", i, level);
                    if (level < 10 || !capLevel) {
                        commands.push_back(_createCommand("ModuleInfoIncreaseUp", {{"i", i*1000+9}}));
                    }
                }
                else {
                    commands.push_back(_createCommand("ModuleInfoIncreaseUp", {{"i", i*1000+9}}));
                }
            }
        }

        json result = {
                {"id", cmdID["Snapshot"]},
                {"i", randHex()},
                {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }

    json MaxAccount(const json& wearSlot, const json& gadgetSlot, const json& royaleSlot,
                    const json& petsSlot, const std::vector<int>& petsList) {
        json commands;
        std::vector<int> wearData;
        std::vector<int> existingGadgets;
        std::vector<int> royaleData;
        std::vector<int> petsData;

        if (!wearSlot.empty() && !wearSlot["w"].empty()) {
            wearData = wearSlot["w"].get<std::vector<int>>();
        }
        if (!gadgetSlot.empty()) {
            for (auto& [key, value] : gadgetSlot.items()) {
                existingGadgets.push_back(std::stoi(key));
            }
        }
        if (!royaleSlot.empty()) {
            royaleData = royaleSlot.get<std::vector<int>>();
        }
        if (!petsSlot.empty() && !petsSlot["p"].empty()) {
            for (auto& pet : petsSlot["p"]) {
                petsData.push_back(pet["i"].get<int>());
            }
        }

        // Add all royale items
        for (int i = 1; i <= 2000; i++) {
            if (!royaleData.empty() && std::find(royaleData.begin(), royaleData.end(), i*1000+5) != royaleData.end()) {
                continue;
            }
            commands.push_back(_createCommand("UpdateBattleRoyaleList", {{"1", i*1000+5}}));
            commands.push_back(_createCommand("UpdateBRVehicle", {{"i", i*1000+5}, {"u", 4}}));
        }

        // Add all pets
        for (const int& curPet : petsList) {
            bool petExists = false; // Reset the flag at the beginning of each iteration
            if (!petsData.empty() && std::find(petsData.begin(), petsData.end(), curPet) != petsData.end()) {
                petExists = true;
            }
            if (!petExists)
                commands.push_back(_createCommand("AddPetV3", {{"i", curPet}, {"n", ""}}));
            commands.push_back(_createCommand("AddPetCardsV3", {{"i", curPet}, {"a", 260}}));
        }

        // Add all weapons
        for (int i = 1; i < 2000; i++) {
            commands.push_back(_createCommand("AddWeaponV17", {{"i", i*1000+1},{"u", {{"l", playerLevel}, {"r", 5}}}}));
        }

        // add all modules
        for (int i = 346; i <= 387; i++) {
            commands.push_back(_createCommand("InventoryAddItemConsumable", {
                {"t", 1155},
                {"i", i*1000+9},
                {"c", 2500}
            }));
        }

        // upgrade said modules
        for (int i = 304; i <= 345; i++) {
            for (int j = 0; j < 9; j++) {
                commands.push_back(_createCommand("ModuleInfoIncreaseUp", {{"i", i*1000+9}}));
            }
        }

        // add all wears
        for (int i = 1; i < 200; i++) {
            if (wearData.empty() || std::find(wearData.begin(), wearData.end(), i*1000+2) == wearData.end()) {
                commands.push_back(_createCommand("AddPurchasedWear", {{"w", "a*" + std::to_string(i*1000+2)}}));
                commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+29}})); // skins
                commands.push_back(_createCommand("BuyArmor", {{"a", i*1000+2},{"u", playerLevel}})); // armor
                commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+23}})); // armor skins
            }
        }

        // add all gadgets
        for (int& currentGadget : gadgetIds) {
            if (existingGadgets.empty() || std::find(existingGadgets.begin(), existingGadgets.end(), currentGadget) == existingGadgets.end()) {
                commands.push_back(_createCommand("AddPurhasedGadget", {{"g", currentGadget},{"u", playerLevel}}));
            }
        }

        // add all weapon skins and graffiti
        for (int i = 1; i < 600; i++) {
            commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+14}}));
        }
        for (int i = 1; i < 50; i++) {
            commands.push_back(_createCommand("InventoryAddItemSingle", {{"i", i*1000+28}}));
        }

        json result = {
            {"id", cmdID["Snapshot"]},
            {"i", randHex()},
            {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }

    json Win(Mode mode) {
        int kill = random(1, 40);
        int death = random(1, 10);

        json result = {
                {"kill_cnt", kill}, {"death_cnt", death}, {"kill_cnt_month", kill}, {"death_cnt_month", death}, {"accuracy", 100},
                {"mode", static_cast<int>(mode)}, {"rating", 0}, {"league_id", 0}, {"req_id", 106}, {"sid", ""}
        };

        return json::array({"update_player", result});
    }
    json EvaluateLobby(const std::string& uniq_id, int likes) {
        json result = {{"like", likes}, {"player_id", uniq_id}};
        return json::array({"evaluate_lobby", result});
    }

    json AddBoosters(int amount, int index) {
        json commands;

        commands.push_back(_createCommand("InventoryAddItemConsumable", {{"t", 1520}, {"i", index*1000+30}, {"c", amount}}));
            for (int l = 0; l < 10; l++) {
                commands.push_back(_createCommand("AnalyticsProgress", {{"t", 1520}, {"i", index*1000+30}, {"c", amount}}));
            }

        json result = {
            {"id", cmdID["Snapshot"]},
            {"i", randHex()},
            {"p", {{"c", commands}}}
        };

        return json::array({"update_progress", result});
    }
    std::string nullToArray(const std::string& str) {
        std::string::size_type n = 0;
        std::string out = str;
        while ((n = out.find("null", n)) != std::string::npos) {
            out.replace(n, 4, "[]");
            n += 2;
        }
        return out;
    }
}
