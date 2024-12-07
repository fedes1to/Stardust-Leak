#pragma once

#ifndef ZYCHEATS_SGUYS_FUNCTIONS_H
#define ZYCHEATS_SGUYS_FUNCTIONS_H

#include <android/log.h>
#include <string>
#include <thread>
#include <sstream>
#include <fstream>
#include "Auth.h"
#include <random>
#include <list>
#include <cstddef>
#include <unwind.h>

using json = nlohmann::ordered_json;

// here you can define variables for the patches
bool    modKeys, tgod, removedrone, god, ammo, collectibles, crithit, charm, fte, enemymarker, electric, doublejump,
        coindrop, isDiscordPressed, blindness, kniferange, expbull, shotbull, jumpdisable, slowdown, headmagnify, destroy, recoilandspread, quickscope, speedup,
        speed, isAddCurPressed, ninjaJump, spamchat, gadgetdisabler, xray, scopef, gadgetsEnabled, xrayApplied, kniferangesex, portalBull, snowstormbull,
        silentaim, polymorph, harpoonBull, reload, modules, gundmg, catspam, gadgetcd, addAllGadgets, showItems, gadgetduration, teamkill, pgod,
        pspeed, pdamage, prespawntime, addAllPets, playerScore, gbullets, flamethrower, pnoclip, reflections, clanparts, showInfo, spoofMe3 = true,
        bundles, clanEnergy, invisible, ignorereflect, wearUnlocker, wepSkins6, lobbyItems, firerate,
        loopAddCur, allEffects, ricochet, longLifetime, dontDoSelfDmg, gravity, telekill, loadMenu,
        nuke, rocketTower, shouldUpdateList, polymorph1, polymorph2, spoofkillfeed, penetrate, curse, poison, stun, nocharge, blackmarket, taskclicker, swear = true,
        speedupAll, slowdownAll, disableJumpAll, useShovel, illegalWeaponReplace, logItemRecord, changeRarity,
        spoofNick, spoofNick2, isEditor, enableConsole, antiban = true, upModule, headshotMode, throughenemies, triggerbot, sendReload, setlevel65, addweaponss, addwearss,
        tpPlayer, aimbot, buyMenu, blackScreenAll, noClipAll, handBugAll, corruptedSniper,
        loadAcc, playerScore2, unsafeCurrency, addchest1, addchest2, addchest3, sendWebsocket, logWS, espline, espbox, espdistance, addingscore,
        winspleeef, aimVisible, esphp, espline2, judsngraffiti, customLvl, unsafeLvl, giftpp, openPanel,
        unsafeCollectibles, banAcc, playerScale, otherPlayerScale, tpPlayer2Me, tpPlayerAll, unsafeKeys, logprogress, maxAccountws,
        completeTutorial, createAcc, addmoduless, addmodulelevel, logrequests = true, autoreload = true, addallweaponskins, addallgraffiti, AddBattlePassExp_, addbooosters,
        kickPlayer, kickAllPlayers, AddBattlePassPremium_, AddKeys_, AddGemBoosters_, UpdateStats_, logprogresstofile, capModules = true, addRoyale,
        AddClan_, SetClanRank_, SetClanLevelFort_, BuffClan_, SetClanLevelTank_, AddChestWS, unsafechests, showing_term = false, showWatermark = false, rainbowColor,
        includeTrails = true, forcegadget, AddWinsandmatches_, CompleteEliteChallanges_, droneStrike, spawnPrefab, spinPrefabs, spawnPrefabLoop, spawnPrefabRandom,
        spamJoin, spamVehicle, testgift, allenemyfloat, hackrankexperience_, hackclanvalor_, AddThropies_;
//parts
bool AddWearParts_, AddWeaponParts_, AddRoyaleParts_;
//judsn
bool peteggmodifier, peteggcd, unreleasedroyale, clanchestopenprice, unlimitedsuperclanchest, maxmods, unreleasedroyaleandhats, showdeletedgadgets;
//clan ranks
bool emperorrank, generalrank, colonelrank, ltcolonelrank, majorrank, captainrank, lieutenantrank, warriorrank, fighterrank, recruitrank, newbierank;
//adders
bool addWeapons;

bool uwufy, isTpingFromButton, rmColliders, yesCollider, enableUIInput, isGuiVisible = true, oldIsGuiVisible, logRPC, qUpdateObjList, qCloneObj, qCurObjActive;
float aimbotdistance, aimbotradius, myScale = 0.5f, otherScale = 0.5f;
int aimbotmode = 1;
int silentaimmode = 0;
int keysint;
bool hasUpdated = true;
int authid = 0;
bool isSceneExplorerOpen;

int selectedLocation, selectedSpawnMode, spawnAmount = 100, delayCont = 5, selectedPrefab, contSpawn;

float silentaimdistance = 0.0f;
float silentaimradius = 0.0f;

std::string spamMessage = OBFUSTR("modfs.dev owns pg3d");
std::string nickName;
std::string authSecret, authID;
std::string explorerSearchQuery;
std::vector<std::string> files = {};
static int fileSelection = 0;

// declare here strings for ImGui::InputText
std::string idlog, secretlog, scene, oldScene;

int refocus=0;

std::string lowercase(const std::string& orig)
{
	std::string nevv = orig;
	std::transform(nevv.begin(), nevv.end(), nevv.begin(), ::tolower);
	return nevv;
}

float jumpHeight, tpDistance;
int spawnRate = 1;
float snowstormbullval = 1000.0f;
int reflection, nicknameIndex, amountws, selectedCur, selectedPlayer, gaySexIndex,
        selectedRarity, selectedWepRarity = 5, delayChat = 5, delayTime,
        unsafeLevel = 1, addscoreamount = 5000, desiredLevel = 65, collectiblesVal = 2500, selectedCause = 129;
int selectedGObj;
int rocketMode = 0;
bool freezeYPos;
float targetYPos = 0;
int selectedAvatarRPC = 0;
bool ___ran = false;
std::string empty_str_placeholder = "";

int wepValFirst = 1, wepValLast = 1;

float timeSinceMatch;

int chestslider;

void* myPlayer = nullptr;
void* inGameGUI = nullptr;
void* WSMInstance = nullptr;

class PhotonPlayer {
public:
    void* obj; // photonplayer instance
    int id;
    std::string name;
    bool IsSelected;
};

struct pg_me_t {
    void* instance;
    void* playerDamageable;
    void* firstPersonControl;
    void* cameraPivot;
    void* fpsCameraController;
    void* transform;
    void* camera;
    void *baseCamera;
    il2cppVector3 location;
    il2cppQuaternion rotation;
};

pg_me_t pg_me;

// from https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string#3418285
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

std::unordered_map<int, std::unique_ptr<json>> commandParams = {};
std::unordered_map<int, std::unique_ptr<json>> awaitingResponse = {};
std::unordered_set<int> awaitingGetProgress = {};
bool massRequest = false; // temporary fix

enum class SlotState {
    READY,
    FETCHING,
    FETCHED
};
struct ProgressSlot
{
    SlotTypes type = SlotTypes::Wear;
    struct {
        SlotState state = SlotState::READY;
        std::time_t time = 0;
    } slotUpdate;
    json data = {};

    ProgressSlot() = default;
    ProgressSlot(SlotTypes type) : type(type) {}
};
std::vector<ProgressSlot> progressSlots(100);

std::string SerializeProgressSlots(const std::vector<ProgressSlot>& progressSlots) {
    json serializedData;
    for (size_t i = 0; i < progressSlots.size(); i++) {
        const auto& slot = progressSlots[i];
        json slotJson;
        slotJson["index"] = i;
        slotJson["type"] = static_cast<int>(slot.type);
        slotJson["slotUpdate"]["state"] = static_cast<int>(slot.slotUpdate.state);
        slotJson["slotUpdate"]["time"] = slot.slotUpdate.time;
        if (slot.data.is_null()) {
            continue;
        }
        slotJson["data"] = slot.data;
        serializedData.push_back(slotJson);
    }
    return serializedData.dump();
}

struct GameMode {
    std::string name;
    bool winFlag;
    int modeId;
    bool isRaid;
    int raidDifficulty;
    bool isTournament = false;
};

std::vector<GameMode> gameModes = {
        {"Tournament Wins", false, 8, false, 0, true},
        {"Teamfight Wins", false, 2, false, 0},
        {"Deathmatch Wins", false, 0, false, 0},
        {"Royale Wins", false, 20, false, 0},
        {"Free Play Tops", false, 31, false, 0},
        {"Capture Wins", false, 5, false, 0},
        {"Duel Wins", false, 8, false, 0},
        {"Team Strike Wins", false, 16, false, 0},
        {"Easy Raid Wins", false, 22, true, 1},
        {"Medium Raid Wins", false, 22, true, 2},
        {"Hard Raid Wins", false, 22, true, 3}
};

int currentMode = 0;

using namespace std::chrono_literals;

template <typename T>
inline T& GetField(void* instance, uint64_t offset) {
    return (T&)(*(T *) ((uint64_t) instance + offset));
}

// this will return a new Dictionary<string, object>();
inline void* jsonToDict(const char* str) {
    auto dictType = Type$$GetType(CreateIl2cppString(OBFUSTR("System.Collections.Generic.Dictionary`2[System.String,System.Object]")));
    return DeserializeObject(CreateIl2cppString(str), dictType);
}

std::string generateRandomHexCode() {
    // Use a random device as the seed for the random number engine
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate a random hex code (6 characters)
    std::uniform_int_distribution<int> dis(0, 0xFFFFFF);
    int randomHex = dis(gen);

    // Format the hex code as [xxxxxx]
    std::ostringstream oss;
    oss << "[" << std::hex << std::setw(6) << std::setfill('0') << randomHex << "[ff]]";

    return oss.str();
}


std::string randhex (int length) {
    char result[length];
    char hex_characters[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    for (int i = 0; i < length; i++) {
        result[i] = hex_characters[rand() % 16];
    }

    return result;
}

int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

void logSplit(const std::string& str) {
    const size_t chunkSize = 1000;
    size_t length = str.length();

    for (size_t i = 0; i < length; i += chunkSize) {
        std::string chunk = str.substr(i, chunkSize);
        LOGD(OBFUSTR("%s"), chunk.c_str());
    }
}

int *getWearIndex(const char *str) {
    static int *(*wearIndex)(il2cppString *str) =
    (int *(*)(il2cppString *str)) OFFSET("0x59FDD44");//search for ERROR!!!!!!! Нет серверной айдишки для одежды {0}
    return wearIndex(CreateIl2cppString(str));
}

using namespace std::chrono_literals;

bool validStructure(const json& j) {
    if (!j.is_array() || j.size() != 2) {
        return false;
    }
    return (j[0].is_string() && j[1].is_object());
}

void callWebsocket(const json& request) {
    if (WSMInstance == nullptr) {
        LOGD("WSMInstance is null");
        return;
    }

    if (!validStructure(request)) {
        LOGD("Invalid request structure");
        return;
    }

    std::string eventName = request[0];

    int currentID = *(int*)((uint64_t)WSMInstance + 0x38);
    if (eventName == "get_progress")
        awaitingGetProgress.insert(currentID);
    commandParams.insert(std::make_pair(currentID, std::make_unique<json>(request)));
    LOGWS("Sending command %s with id %d", eventName.c_str(), currentID);
    LOGWS("Request: %s", request.dump().c_str());
    sendCommand(WSMInstance, CreateIl2cppString(eventName.c_str()));
}

enum Validation {
    None = 0,
    Integer = 1,
    Float = 2,
    Alphanumeric = 3,
    Username = 4,
    Name = 5,
    Filename = 6,
    ValidateSpaces = 7,
};

struct il2cpp_test_TypeDec {
	void *clazz;
	void *type;
};

il2cpp_test_TypeDec D_TYPE(const Il2CppImage* img, const char* namespaze, const char* name, const char* scope) {
	void *clazz = GetClass_API(img, namespaze, name);
	if (!clazz) {
		LOGE("Stardust(%s): %s class not found.", scope, name);
		return {};
	}// else { LOGI("Stardust(%s): %s class was found.", scope, name); }
	void *type = (void *) il2cpp_type_get_object(il2cpp_class_get_type((Il2CppClass *) clazz));
	if (!type) {
		LOGE("Stardust(%s): %s type not found.", scope, name);
		return {};
	}// else { LOGI("Stardust(%s): %s type was found.", scope, name); }
	return il2cpp_test_TypeDec { clazz, type };
}

struct gobj_inst
{
	std::string name;
	void* obj;
	bool selected;
};

std::list<PhotonPlayer> playerListDyn;
std::vector<gobj_inst> objListDynBackHold;
std::vector<gobj_inst> objListDyn;
il2cppList<void**>* sharedPlayerList;
il2cppList<void**>* photonViewList;

void playerList() {
    playerListDyn.clear();
    auto photonplayers = PhotonNetwork_playerListothers();
    for (int i = 0; i < photonplayers->getLength(); ++i) {
        PhotonPlayer newPlayer;
        auto photonplayer = photonplayers->getPointer()[i];
        newPlayer.name = get_photonName(photonplayer)->getString();
        newPlayer.obj = photonplayer;
        newPlayer.id = get_photonID(photonplayer);
        playerListDyn.push_back(newPlayer);
    }
}

void updateObjList()
{
	//objListDynBackHold.clear();
	objListDyn.clear();
	il2cpp_test_TypeDec gameObjectDef = D_TYPE(LibImages.UnityCoreModule, "UnityEngine", "GameObject", "updateObjList");
	il2cppArray<void**>* curObjects = Resources$$FindObjectsOfTypeAll(gameObjectDef.type);
	for (int i = 0; i < curObjects->getLength(); i++) {
		void *thisObject = curObjects->getPointer()[i];
		gobj_inst thisInstance = {Object$$get_name(thisObject)->getString(), thisObject};
		//objListDynBackHold.push_back(thisInstance);
		objListDyn.push_back(thisInstance);
	}
	//objListDyn = objListDynBackHold;
}

void SetMasterClient(void* player) {
    void* networkingPeer = GetStaticField<void*>(il2cpp_class_from_name(LibImages.AssemblyCSharp, "", "丂丝七不丈丐丒丙三"), "丝丐丌丏万业上三丑"); // yeah this needs updating, what the fuck
    int playerid = get_photonID(player);
    set_master(networkingPeer, playerid, false);
}

// Player_move_c
void *get_PlayerDamageable(void *player) {
    return GetField<void*>(player, 0x650);
}

void* getPlayerCamera(void *playermovec) {
    return BaseCamera$$Camera(get_playerCamera(playermovec));
}

// Player_move_c
void *get_PlayerTransform(void *player) {
    return Component$get_transform(GetField<void*>(player, 0x3A0)); // public Transform myPlayerTransform;
}

void ownAllIds() {
    if(photonViewList != nullptr) {
        photonViewList->foreach([&](void* view, int index) {
            if(view != nullptr && !PhotonView$IsMine(view)) {
                RequestOwnership(view);
            }
        });
    }
}

il2cppQuaternion GetRotationFromLocation(il2cppVector3 targetLocation, float y_bias) {
    return il2cppQuaternion::LookRotation((targetLocation + il2cppVector3(y_bias, 0, 0)) - pg_me.location, il2cppVector3(0, 1, 0));
}

// Player_move_c
il2cppVector3 get_PlayerVec(void *player) {
    return get_position(get_PlayerTransform(player));
}

// Player_move_c
il2cppQuaternion get_PlayerRot(void *player) {
    return get_rotation(get_PlayerTransform(player));
}

void Appendil2cppString(il2cppString*& str0, il2cppString* str1) {
    str0 = string$$Concat(str0, str1);
}


void enableUIInputs() {
    void* uiInputType = Type$$GetType(CreateIl2cppString(OBFUSTR("UIInput")));
    void* boxColliderType = Type$$GetType(CreateIl2cppString(OBFUSTR("UnityEngine.BoxCollider")));
    il2cppArray<void**>* uiInputs = Resources$$FindObjectsOfTypeAll(uiInputType);
    for (int i = 0; i < uiInputs->getLength(); i++) {
        void* uiInput = uiInputs->getPointer()[i];
        void* gameObject = Component$get_object(uiInput);
        GameObject$$AddComponent(gameObject, boxColliderType);
    }
}

void enableColliders() {
	il2cpp_test_TypeDec collider = D_TYPE(LibImages.UnityPhysicsModule, "UnityEngine", "Collider", "enableColliders");
	il2cpp_test_TypeDec rigidbody = D_TYPE(LibImages.UnityPhysicsModule, "UnityEngine", "Rigidbody", "enableColliders");
	il2cppArray<void**> *allGameObjects = Resources$$FindObjectsOfTypeAll(collider.type);
	for (int i = 0; i < allGameObjects->getLength(); i++) {
		void* theGameObject = Component$get_object(allGameObjects->getPointer()[i]);
		std::string gameObjectName = Object$$get_name(theGameObject)->getString();
		std::string gameObjectTag = GameObject$$get_tag(theGameObject)->getString();
		if (gameObjectName.find("ollider") != std::string::npos && gameObjectTag.find("Untagged") != std::string::npos) {
			if (GameObject$$GetComponent(theGameObject, rigidbody.type) == nullptr && !GameObject$$GetActive(theGameObject)) {
				GameObject$$SetActive(theGameObject, true);
			}
		}
	}
}

void removeColliders() {
	il2cpp_test_TypeDec collider = D_TYPE(LibImages.UnityPhysicsModule, "UnityEngine", "Collider", "removeColliders");
	il2cpp_test_TypeDec rigidbody = D_TYPE(LibImages.UnityPhysicsModule, "UnityEngine", "Rigidbody", "removeColliders");
    il2cppArray<void**> *allGameObjects = Resources$$FindObjectsOfTypeAll(collider.type);
    for (int i = 0; i < allGameObjects->getLength(); i++) {
        void* theGameObject = Component$get_object(allGameObjects->getPointer()[i]);
        std::string gameObjectName = Object$$get_name(theGameObject)->getString();
        std::string gameObjectTag = GameObject$$get_tag(theGameObject)->getString();
        if (gameObjectName.find("ollider") != std::string::npos && gameObjectTag.find("Untagged") != std::string::npos) {
            if (GameObject$$GetComponent(theGameObject, rigidbody.type) == nullptr) {
                GameObject$$SetActive(theGameObject, false);
            }
        }
    }
}

int tpToNormalPosTimer;
il2cppVector3 oldPos;

void* getBestTarget() {
    void* bestPlayer = nullptr;
    float bestDistance = aimbotdistance;
    float bestFov = aimbotradius;

    if (sharedPlayerList != nullptr && pg_me.instance != nullptr) {
        sharedPlayerList->foreach([&](void* player, int index) {
            if (player != nullptr && !get_isMine(player) ) {
                void *playerDamageable = get_PlayerDamageable(player);
                if (playerDamageable != nullptr && IsEnemyTo(playerDamageable, pg_me.instance)) {
                    void *transform = Component$get_transform(playerDamageable);
                    if (transform != nullptr) {
                        il2cppVector3 location = get_position(transform);
                        il2cppVector3 w2sPoint = Camera_WorldToScreenPoint(pg_me.camera, location);
                        il2cppVector2 screenCenter = il2cppVector2(glWidth / 2, glHeight / 2);
                        il2cppVector2 to = il2cppVector2(w2sPoint.X, glHeight - w2sPoint.Y);
                        float distance = il2cppVector3::Distance(location, pg_me.location);
                        float crosshairDistance = il2cppVector2::Distance(screenCenter, to);

                        if (IsTargetVisible(pg_me.instance, location)) {
                            if (distance < bestDistance) {
                                bestDistance = distance;
                            }

                            if (crosshairDistance < bestFov) {
                                bestFov = crosshairDistance;
                            }

                            if (distance == bestDistance && crosshairDistance == bestFov) {
                                bestPlayer = player;
                            }
                        }
                    }
                }
            }
        });
    }
    return bestPlayer;
}

void* getClosestTarget() {
    void* bestPlayer = nullptr;
    float bestDistance = 1000;
    if (sharedPlayerList != nullptr && pg_me.instance != nullptr) {
        sharedPlayerList->foreach([&](void* player, int index) {
            if (player != nullptr && !get_isMine(player)) {
                void *playerDamageable = get_PlayerDamageable(player);
                if (playerDamageable != 0 && IsEnemyTo(playerDamageable, pg_me.instance)) {
                    void *transform = PD$$GetTransform(playerDamageable);
                    if (transform != 0) {
                        il2cppVector3 location = get_position(transform);
                        float distance = il2cppVector3::Distance(location, pg_me.location);

                        if (aimVisible && distance < bestDistance && IsTargetVisible(pg_me.instance, location)) {
                            bestDistance = distance;
                            bestPlayer = player;
                        } else if (distance < bestDistance && !aimVisible) {
                            bestDistance = distance;
                            bestPlayer = player;
                        }
                    }
                }
            }
        });
    }
    return bestPlayer;
}

il2cppString* uwufyMessage(il2cppString* x) {
    std::string kaomoji[] = {
            "^~^",
            "UwU",
            "OwO",
            "O_O",
            "O_o",
            "oWo",
            "OvO",
            "UvU",
            "*~*",
            ":3",
            "=3",
            "<(^V^<)",
            "UmU",
    };
    std::string editedString = string$$ToLower(x)->getString();

    // replace strings
    replaceAll(editedString, ".", "!!!");
    // editedString = string$$Replace(editedString, CreateIl2cppString("th"), CreateIl2cppString("f"));
    replaceAll(editedString, "l", "w");
    replaceAll(editedString, "r", "w");

    // add kaomoji
    editedString += " ";
    editedString += kaomoji[rand() % 13];

    // add prefix
    //editedString = string$$Concat(prefixes[rand() % IM_ARRAYSIZE(prefixes)], editedString);

    return CreateIl2cppString(editedString.c_str());
}

void tpForward(void* instance, il2cppString* steps, bool isClan, il2cppString* logoid) {
    float stepsFloat = 0;
    bool stepsTry = float$$TryParse(steps, stepsFloat);
    if (!stepsTry) {
        SendChat(instance, CreateIl2cppString(OBFUSTR("- teleport/tp")), isClan, logoid);
        SendChat(instance, CreateIl2cppString(OBFUSTR("Example: !teleport 10, !tp 10")), isClan, logoid);
        return;
    } else {
        stepsFloat = float$$Parse(steps);
    }
    if (instance != nullptr) {
        set_position(get_PlayerTransform(instance), get_PlayerVec(instance)+Transform$$forward(get_PlayerTransform(instance))*stepsFloat);
    }
}

void instantiateClientside(void* instance, il2cppString* path) {
    bool isDontDestroyOnLoad = string$$Contains(path, CreateIl2cppString(OBFUSTR("-ddol")));
    il2cppString* actualPath = string$$Substring2(string$$Replace(path, CreateIl2cppString(OBFUSTR(" -ddol")), CreateIl2cppString(OBFUSTR(""))), strlen("!instantiate "));
    void* gameObjectType = Type$$GetType(CreateIl2cppString("UnityEngine.GameObject"));
    void* loadedGameObject = Resources$$Load(actualPath, gameObjectType);
    il2cppVector3 position = get_PlayerVec(instance);
    void* theObject = GameObject$$Instantiate(loadedGameObject, position, il2cppQuaternion::Identity());
    if (isDontDestroyOnLoad) {
        Object$$DontDestroyOnLoad(theObject);
    }
    std::string instantiateToast = OBFUSTR("Instantiated ");
    instantiateToast += actualPath->getString();
    instantiateToast += OBFUSTR(" correctly!");
    ShowToast(CreateIl2cppString(instantiateToast.c_str()), false);
}

void otax(void* instance, bool isClan, il2cppString* logoid, std::string arg1) {
    std::string otaxMessage = OBFUSTR("Otaxing ");
    otaxMessage += arg1;
    otaxMessage += OBFUSTR("...");
    SendChat(instance, CreateIl2cppString(otaxMessage.c_str()), isClan, logoid);
}

struct NullableFloat {
    bool hasValue;
    float value;
};

bool fetchSlot(int slotNumber) {
    ProgressSlot& slot = progressSlots[slotNumber];
    LOGWS("Slot state: %d", slot.slotUpdate.state);
    if (slot.slotUpdate.state == SlotState::READY) {
        if (authid == 0)
            authid = stoi(getAuthID()->getString());
        callWebsocket(ws::GetProgress(authid, {slotNumber}));
        slot.slotUpdate.state = SlotState::FETCHING;
        return false;
    }
    else if (slot.slotUpdate.state == SlotState::FETCHED) {
        return true;
    }
    return false;
}

std::vector<int> getRemainingRoyale() {
    std::vector<int> hasIndex;
    void* dict = get_RoyaleList();
    json defaultJson = json::parse(JsonConvert$$SerializeObject(dict)->getString());
    void* royaleInstance = get_royaleInstance();

    for (auto& [key, value] : defaultJson.items()) {
        int index = std::stoi(to_string(value["Index"]));

        if (!hasRoyaleItem(royaleInstance, index) && index != 108005) {
            LOGW("Added %i", index);
            hasIndex.push_back(index);
        }
    }

    return hasIndex;
}

std::vector<int> getPetList() {
    void* petsDict = get_petsList();
    il2cppString* petsJson = JsonConvert$$SerializeObject(petsDict);
    json pets = json::parse(petsJson->getString());

    std::vector<int> petsList = {};
    for (auto& pet : pets) {
        petsList.push_back(pet["Index"]);
    }
    return petsList;
}

void* InstantiateNetworkObject(std::string objname, il2cppVector3 pos, il2cppQuaternion rot) {

    SetMasterClient(localPhotonPlayer());
    Il2CppArray* arr = il2cpp_array_new(CSharpTypeClass.Object, 0);

    /* std::string lowername;

    for (char ch : objname) {
        lowername += std::tolower(ch);
    }

    if (lowername.find("gadget") != std::string::npos) {
        int val0 = desiredLevel;
        int val1 = desiredLevel;
        arr = il2cpp_array_new(CSharpTypeClass.Object, 2);
        arr->vector[0] = il2cpp_value_box(CSharpTypeClass.Int32, &val0);
        arr->vector[1] = il2cpp_value_box(CSharpTypeClass.Int32, &val1);
    } else if (lowername.find("vehicle") != std::string::npos) {
        int val0 = 1;
        bool val1 = true;
        arr = il2cpp_array_new(CSharpTypeClass.Object, 2);
        arr->vector[0] = il2cpp_value_box(CSharpTypeClass.Int32, &val0);
        arr->vector[1] = il2cpp_value_box(CSharpTypeClass.Boolean, &val1);
    } else if (lowername.find("car") != std::string::npos) {
        int val0 = 1;
        arr = il2cpp_array_new(CSharpTypeClass.Object, 1);
        arr->vector[0] = il2cpp_value_box(CSharpTypeClass.Int32, &val0);
    } else {
        arr = il2cpp_array_new(CSharpTypeClass.Object, 0);
    } */

    return InstantiateSceneObject(CreateIl2cppString(objname.c_str()), pos, rot, 0, arr);

}

// void handleSlot(ProgressSlot& progressSlots, int slotNumber, std::function<void(json&)> func, bool& done) {
//     ProgressSlot& slot = progressSlots[slotNumber];
//     if (slot.slotUpdate.state == SlotState::READY) {
//         if (authid == 0)
//             authid = stoi(getAuthID()->getString());
//         callWebsocket(ws::GetProgress(authid, {slotNumber}));
//         slot.slotUpdate.state = SlotState::FETCHING;
//     }
//     else if (slot.slotUpdate.state == SlotState::FETCHED) {
//         func(slot.data);
//         slot.slotUpdate.state = SlotState::READY;
//         done = false;
//     }
// }




#endif //ZYCHEATS_SGUYS_FUNCTIONS_H
