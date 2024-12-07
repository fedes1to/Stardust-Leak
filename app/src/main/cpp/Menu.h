//
// Created by lbert on 4/15/2023.
//

#ifndef ZYGISK_MENU_TEMPLATE_MENU_H
#define ZYGISK_MENU_TEMPLATE_MENU_H

#include "ImGui/user_interface.h"
#include "ImGui/imgui_stdlib.h"

using namespace ImGui;
bool isMinimized = OBFUSINT(false);

bool logged;

enum selected {
    Account,
    GameTab,
    WeaponTab,
    VisualTab,
    WebsocketTab,
    MiscTab
};

enum sub_Selected {
    Recovery,
    Shop,
    Player,
    Game,
    Other,
    Weapon,
    Bullet2,
    Effect,
    Visual,
    Wear,
    WeaponUnl,
    Stats,
    WebSocket,
    Events,
    WSClan,
    WSClan2,
    Misc,
    Spawn,
    RocketSubTab,
    Network,
    Clickers,
    AccountSub,
    SpoofOptions,
    Info,
    Aimbot,
    ESPSub,
    JUDSN,
    Commands,
    Explorer,
};

static int selected = GameTab;
static int sub_selected = Game;

std::vector<msg> ChatMessages;
static char chatInput[256] = "";

void NewDrawMenu() {

    if (showWatermark) {
        auto draw_list = ImGui::GetBackgroundDrawList();
        auto watermark = OBFUSTR("Stardust PG3D | 24.0.1 | [modfs]");
        auto watermark_size = ImGui::CalcTextSize(watermark);

        auto yOffset = 20;
        auto offset = 20;

        draw_list->AddRectFilled(ImVec2(6 + offset, 4 + yOffset),
                                 ImVec2((4 * 2) + watermark_size.x + 6 + offset,
                                        watermark_size.y + 6 + yOffset),
                                 ImColor(0.345f, 0.396f, 0.949f, 1.000f));
        draw_list->AddRectFilled(ImVec2(6 + offset, 6 + yOffset),
                                 ImVec2((4 * 2) + watermark_size.x + 6 + offset,
                                        watermark_size.y + 6 + yOffset),
                                 ImColor(0.2117647081613541f, 0.2235294133424759f,
                                         0.2470588237047195f, 1.0f));
        draw_list->AddText(ImVec2(10 + offset, 6 + yOffset), ImColor(255, 255, 255, 255),
                           watermark);
    }

    Begin(OBFUSTR("Stardust"), nullptr, ImGuiWindowFlags_NoDecoration);
    {

        auto draw = GetWindowDrawList();

        if (!isMinimized) { // this makes it look ugly when minimized before verifed pls fix
            // reset cursor
            SetCursorPos(ImVec2(0, 0));

            // set window size for minimize purposes 520, 395
            ImGuiIO &io = GetIO();
            SetWindowSize(ImVec2(1040, 790));
            ImVec2 pos = GetWindowPos();
            ImVec2 size = GetWindowSize();

            draw->AddRectFilled(pos, ImVec2(pos.x + 110, pos.y + size.y),
                                ImColor(20, 20, 20, 255)); // left rect
            draw->AddRectFilled(ImVec2(pos.x + 110, pos.y), ImVec2(pos.x + size.x, pos.y + 70),
                                ImColor(20, 20, 20, 255)); // upper rect

            draw->AddLine(ImVec2(pos.x + 110, pos.y + 70), ImVec2(pos.x + size.x, pos.y + 70),
                          ImColor(255, 255, 255, 15)); // upper line
            draw->AddLine(ImVec2(pos.x + 110, pos.y), ImVec2(pos.x + 110, pos.y + size.y),
                          ImColor(255, 255, 255, 15)); // left line

            //Close button
            SetCursorPos(ImVec2(920, 10));
            if (ImGui::Button(ICON_KI_MINUS)) {
                isMinimized = OBFUSINT(true);
            }

            SetCursorPos(ImVec2(-19, 15));
            BeginGroup();
            if (custom_interface::tab(ICON_KI_COIN, Account == selected)) { // Account tab
                selected = Account;
                sub_selected = Recovery;
            }
            if (custom_interface::tab(ICON_KI_GAMEPAD, GameTab == selected)) { // Game + Player tab
                selected = GameTab;
                sub_selected = Game;
            }
            if (custom_interface::tab(ICON_KI_FIST, WeaponTab == selected)) { // Weapon tab
                selected = WeaponTab;
                sub_selected = Weapon;
            }
            if (custom_interface::tab(ICON_KI_REC, VisualTab == selected)) { // Visual tab
                selected = VisualTab;
                sub_selected = Visual;
            }
            if (custom_interface::tab(ICON_KI_DIAMOND, WebsocketTab == selected)) { // UNSAFE tab
                selected = WebsocketTab;
                sub_selected = Wear;
            }
            if (custom_interface::tab(ICON_KI_USER, MiscTab == selected)) { // MISC tab
                selected = MiscTab;
                sub_selected = Misc;
            }
            EndGroup();

            if (selected == Account) {
                BeginGroup();
                SetCursorPos(ImVec2(130, 28));
                if (custom_interface::subtab(OBFUSTR("Recovery"), Recovery == sub_selected)) {
                    sub_selected = Recovery;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Shop"), Shop == sub_selected)) {
                    sub_selected = Shop;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Clickers"), Clickers == sub_selected)) {
                    sub_selected = Clickers;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Other"), JUDSN == sub_selected)) {
                    sub_selected = JUDSN;
                }
                EndGroup();

                if (sub_selected == Recovery) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("MiscUnlocks"), ImVec2(438, 684));
                    {
                        if (unsafeCurrency)
                            SliderInt(OBFUSTR("Amount"), &amountws, 0, unsafeLevel * 1000000);
                        else SliderInt(OBFUSTR("Amount"), &amountws, 0, 10000);
                        TextUnformatted(OBFUSTR("Count for the added currency"));
                        Combo(OBFUSTR("Currency"), &selectedCur, curList, IM_ARRAYSIZE(curList));
                        // Combo(OBFUSTR("Obtain Cause"), &selectedCause, analyticsCauses, IM_ARRAYSIZE(analyticsCauses)); lets keep this dev only
                        if (Button(OBFUSTR("Add Currency"))) {
                            isAddCurPressed = OBFUSINT(true);
                        }
                        Checkbox(OBFUSTR("Loop Add Currency"), &loopAddCur);
                        Checkbox(OBFUSTR("Unsafe Currency Amounts"), &unsafeCurrency);
                        if (unsafeCurrency) SliderInt(OBFUSTR("Unsafe Level"), &unsafeLevel, 1, 10);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Currency"), ImVec2(438, 684));
                    {
                        if (Button("Complete tutorial"))
                            completeTutorial = true;
                        Separator();
                        SliderInt(OBFUSTR("##Account level"), &ws::desiredLevel, 1, 65);
                        if (Button(OBFUSTR("Set account level")))
                            setlevel65 = OBFUSINT(true);
                    }
                    EndChild();
                }

                if (sub_selected == Shop) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Shopping/Modules"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Free Module Upgrade"), &upModule);
                        Checkbox(OBFUSTR("Show hidden lobby items"), &lobbyItems);
                        Checkbox(OBFUSTR("Free Lobby Bundles"), &bundles);
                        Checkbox(OBFUSTR("Free Clan Parts"), &clanparts);
                        Checkbox(OBFUSTR("Show Hidden Wear"), &wearUnlocker);
                        Checkbox(OBFUSTR("Purchase any weapon skin"), &wepSkins6);
                        Checkbox(OBFUSTR("Infinite Clan Energy"), &clanEnergy);
                        Checkbox(OBFUSTR("Show Weapons"), &showItems);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("MiscShop"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Unsafe Collectibles"), &unsafeCollectibles);
                        if (unsafeCollectibles)
                            SliderInt(OBFUSTR("Collect Value"), &collectiblesVal, -999999, 999999);
                        else
                            SliderInt(OBFUSTR("Collect Value"), &collectiblesVal, -32676, 32676);
                        Checkbox(OBFUSTR("Collectibles"), &collectibles);
                        Separator();
                        Checkbox(OBFUSTR("Unsafe Level"), &unsafeLvl); // move this somewhere else
                        if (!unsafeLvl)
                            SliderInt("Level", &desiredLevel, 1, 65);
                        else
                            SliderInt("Level", &desiredLevel, -99999, 99999);
                        Checkbox(OBFUSTR("Spoof custom level"), &customLvl);
                    }
                    EndChild();
                }

                if (sub_selected == Clickers) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Clickers1"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Free Lottery"), &modKeys);
                        Checkbox(OBFUSTR("Task Clicker"),
                                 &taskclicker); //someone who knows gui optimize this and every checkbox under this one
                        Checkbox(OBFUSTR("Black Market Clicker"), &blackmarket);
                        Checkbox(OBFUSTR("Wear Unlocker"), &wearUnlocker);
                        Combo(" ", &selectedRarity, ItemRarity, IM_ARRAYSIZE(ItemRarity));
                        Checkbox(OBFUSTR("Change Item Rarity"), &changeRarity);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Clickers2"), ImVec2(438, 684));
                    {
                        if (Button(OBFUSTR("Get Corrupted Snipers"))) {
                            corruptedSniper = OBFUSINT(true);
                        }
                        TextUnformatted(OBFUSTR("Any player killed by Kill All "
                                                "\nwill get stuck on Kill-cam when you hold it."
                                                "\nBasically, a fancy version of crash all."
                                                "\n"
                                                "\nMake sure you don't unlock \nany weapons before."));
                    }
                    EndChild();
                }

                if (sub_selected == JUDSN) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Clickers1"), ImVec2(438, 684));
                    {
                        // shit
                        Checkbox(OBFUSTR("Show Removed Gadgets"), &showdeletedgadgets);
                        Checkbox(OBFUSTR("Show Unreleased Hats"), &unreleasedroyaleandhats);
                        Checkbox(OBFUSTR("Unlimited clan chests"), &unlimitedsuperclanchest);
                        Checkbox(OBFUSTR("Buy Graffiti"), &judsngraffiti);
                        Checkbox(OBFUSTR("PixelPass Gift"), &giftpp);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Clickers2"), ImVec2(438, 684));
                    {
                        // fuck
                        Checkbox(OBFUSTR("Max modules"), &maxmods);
                        Checkbox(OBFUSTR("Free clan chests"), &clanchestopenprice);
                        Checkbox(OBFUSTR("Show unreleased royale"), &unreleasedroyale);
                        Checkbox(OBFUSTR("Pet Egg CD"), &peteggcd);
                        Checkbox(OBFUSTR("Pet Modifier"), &peteggmodifier);
                    }
                    EndChild();
                }
            }

            if (selected == GameTab) {
                BeginGroup();
                SetCursorPos(ImVec2(130, 28));
                if (custom_interface::subtab(OBFUSTR("Game"), Game == sub_selected)) {
                    sub_selected = Game;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Player"), Player == sub_selected)) {
                    sub_selected = Player;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Other"), Other == sub_selected)) {
                    sub_selected = Other;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Spawn"), Spawn == sub_selected)) {
                    sub_selected = Spawn;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Network"), Network == sub_selected)) {
                    sub_selected = Network;
                }
                EndGroup();

                if (sub_selected == Player) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Player"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Godmode"), &god);
                        Checkbox(OBFUSTR("Force Double Jump"), &doublejump);
                        if (Button(OBFUSTR("Get Jetpack/Fly"))) {
                            ninjaJump = OBFUSINT(true);
                        }
                        Checkbox(OBFUSTR("Speed"), &speed);
                        Checkbox(OBFUSTR("Invisible"), &invisible);
                        SliderFloat("##", &jumpHeight, 0.0f, 2.5f);
                        TextUnformatted("Jump/Jetpack Height");
                        if (Button(OBFUSTR("Add Score"))) {
                            addingscore = OBFUSINT(true);
                        };
                        SameLine();
                        SliderInt("##score_slider", &addscoreamount, 1, 100000);

                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Social"), ImVec2(438, 684));
                    {
                        Combo(OBFUSTR("Funny Weapons"), &gaySexIndex, gaySexWeapons,
                              IM_ARRAYSIZE(gaySexWeapons), 6);
                        if (Button(OBFUSTR("Replace"))) {
                            illegalWeaponReplace = OBFUSINT(true);
                        }
                        TextUnformatted(
                                OBFUSTR("Replace the weapon you hold \nwith funny weapon."));
                        if (Button(OBFUSTR("Allow to use shovel"))) {
                            useShovel = OBFUSINT(true);
                        }
                        Checkbox(OBFUSTR("Telekill"), &telekill);
                    }
                    EndChild();
                } else if (sub_selected == Game) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Main Mods"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Kill All"), &kniferange);
                        Checkbox(OBFUSTR("Friendly-Fire"), &teamkill);
                        Separator();
                        Checkbox(OBFUSTR("Spam Chat"), &spamchat);
                        InputText(OBFUSTR("##"), &spamMessage);
                        Checkbox(OBFUSTR("Random Chat Color"), &rainbowColor);
                        SliderInt(OBFUSTR("Delay (Chat)"), &delayChat, 1, 10);
                        Separator();
                        Checkbox(OBFUSTR("Spoof Kill Cause"), &spoofkillfeed);
                        Checkbox(OBFUSTR("Force Coin Drop"), &coindrop);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Main Mods 2"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Glitch Everyone"), &xrayApplied);
                        TextUnformatted(OBFUSTR("Every weapon will have a scope."));
                        Checkbox(OBFUSTR("Infinite Game Score"), &playerScore);
                        Checkbox(OBFUSTR("Infinite Game Score +"), &playerScore2);
                        // Checkbox(OBFUSTR("Crash Everyone (Loop)"), &loopdestroy);
                        Separator();
                        Checkbox(OBFUSTR("Speedup All"), &speedupAll);
                        Checkbox(OBFUSTR("Slowdown All"), &slowdownAll);
                        Checkbox(OBFUSTR("Disable Jump All"), &disableJumpAll);
                        Separator();
                        Checkbox(OBFUSTR("Give All Effects"), &allEffects);
                    }
                    EndChild();

                } else if (sub_selected == Other) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("OtherStuff"), ImVec2(438, 582));
                    {
                        Checkbox(OBFUSTR("Drone Godmode"), &removedrone);
                        TextUnformatted(OBFUSTR("Don't get more than 1 drone"));
                        Checkbox(OBFUSTR("No Gadget Cooldown"), &gadgetcd);
                        TextUnformatted(OBFUSTR("Do not change gadgets."));
                        Checkbox(OBFUSTR("Infinite Gadget Duration"), &gadgetduration);
                        TextUnformatted(OBFUSTR("Disable after placing down"));
                        Checkbox(OBFUSTR("Turret Godmode"), &tgod);
                        TextUnformatted(OBFUSTR("Gives the Turret Infinite Health"));
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("OtherPlaceholder"), ImVec2(438, 582));
                    {
                        Checkbox(OBFUSTR("Pet 1 Shot"), &pdamage);
                        Checkbox(OBFUSTR("Pet Godmode"), &pgod);
                        Checkbox(OBFUSTR("Pet speed"), &pspeed);
                        SliderFloat("TP", &tpDistance, -300.0f, 300.0f);
                        if (Button(OBFUSTR("Teleport (FORWARD)"))) {
                            isTpingFromButton = OBFUSINT(true);
                        }
                        if (Button(OBFUSTR("Win In Spleef"))) {
                            winspleeef = OBFUSINT(true);
                        }

                    }
                    EndChild();
                } else if (sub_selected == Spawn) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Instantiate"), ImVec2(438, 582));
                    {
                        if (Button(OBFUSTR("Spawn Prefab"))) {
                            spawnPrefab = OBFUSINT(true);
                        }
                        Combo(OBFUSTR("Mode"), &selectedSpawnMode, spawnOptions,
                              IM_ARRAYSIZE(spawnOptions));
                        Combo(OBFUSTR("Location"), &selectedLocation, spawnlocation,
                              IM_ARRAYSIZE(spawnlocation));
                        SliderInt(OBFUSTR("Amount"), &spawnAmount, 1, 1000);
                        SliderInt(OBFUSTR("Delay (Loop)"), &delayCont, 1, 100);
                        Checkbox(OBFUSTR("Spin Prefabs"), &spinPrefabs);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("PrefabList"), ImVec2(438, 582));
                    {
                        TextUnformatted(OBFUSTR("Chosen prefab:"));
                        Combo(OBFUSTR("##"), &selectedPrefab, prefabList, IM_ARRAYSIZE(prefabList));
                        Checkbox(OBFUSTR("Loop Spawn Prefab"), &spawnPrefabLoop);
                        Checkbox(OBFUSTR("Spawn Random Prefabs"), &spawnPrefabRandom);
                        Checkbox(OBFUSTR("Spam Join Bots"), &spamJoin);
                        Checkbox(OBFUSTR("Spam Vehicles"), &spamVehicle);
                    }
                    EndChild();
                } else if (sub_selected == Network) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Player Options"), ImVec2(438, 582));
                    {
                        if (Button("Update List")) {
                            shouldUpdateList = OBFUSINT(true);
                        }
                        if (Button("Tp To Player")) {
                            tpPlayer = OBFUSINT(true);
                        }
                        Checkbox(OBFUSTR("Tp Player Here"), &tpPlayer2Me);
                        Checkbox(OBFUSTR("Tp All Players"), &tpPlayerAll);
                        Separator();
                        if (Button(OBFUSTR("Hand Bug All")))
                            handBugAll = OBFUSINT(true);
                        SameLine();
                        if (Button(OBFUSTR("No-clip All")))
                            noClipAll = OBFUSINT(true);
                        if (Button(OBFUSTR("Black Screen All")))
                            noClipAll = OBFUSINT(true);
                        SameLine();
                        if (Button(OBFUSTR("Float All")))
                            allenemyfloat = true;
                        if (Button(OBFUSTR("Force Gadget All")))
                            forcegadget = OBFUSINT(true);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("PlayerList"), ImVec2(438, 582));
                    {
                        BeginListBox("##", ImVec2(350, 560));
                        int i = 0;
                        for (PhotonPlayer item: playerListDyn) {
                            std::string &item_name = item.name;
                            if (Selectable(item_name.c_str(), &item.IsSelected))
                                selectedPlayer = i;
                            i++;
                        }
                        EndListBox();
                    }
                    EndChild();
                }
            }

            if (selected == WeaponTab) {
                BeginGroup();
                SetCursorPos(ImVec2(130, 28));
                if (custom_interface::subtab(OBFUSTR("Weapon"), Weapon == sub_selected)) {
                    sub_selected = Weapon;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Aimbot"), Aimbot == sub_selected)) {
                    sub_selected = Aimbot;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Bullet"), Bullet2 == sub_selected)) {
                    sub_selected = Bullet2;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Rocket"), RocketSubTab == sub_selected)) {
                    sub_selected = RocketSubTab;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Effect"), Effect == sub_selected)) {
                    sub_selected = Effect;
                }
                EndGroup();

                if (sub_selected == Weapon) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Weapon"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Force Critical Hits"), &crithit);
                        Checkbox(OBFUSTR("Unlimited Ammo"), &ammo);
                        Checkbox(OBFUSTR("More Damage"), &gundmg);
                        Checkbox(OBFUSTR("No Reload Length"), &reload);
                        TextUnformatted(OBFUSTR("Re-equip after enabling"));
                        Checkbox(OBFUSTR("Instant Charge"), &nocharge);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Aim"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("No Recoil and Spread"), &recoilandspread);
                        Checkbox(OBFUSTR("Force Scope"), &scopef);
                        Checkbox(OBFUSTR("Infinite Knife Range"), &kniferangesex);
                        Checkbox(OBFUSTR("Firerate"), &firerate);
                    }
                    EndChild();
                } else if (sub_selected == Bullet2) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Bullet"), ImVec2(876, 684));
                    {
                        Checkbox(OBFUSTR("Force Explosive Bullets"), &expbull);
                        SliderInt(OBFUSTR("Reflection Rays"), &reflection, 0, 1000);
                        Checkbox(OBFUSTR("Force Polymorph Bullets (Method 1)"), &polymorph);
                        Checkbox(OBFUSTR("Force Polymorph Bullets (Method 2)"), &polymorph1);
                        Checkbox(OBFUSTR("Force Polymorph Bullets (Method 3)"), &polymorph2);
                        Checkbox(OBFUSTR("Force Harpoon Bullets"), &harpoonBull);
                        Checkbox(OBFUSTR("Force Flamethrower Shots"), &flamethrower);
                        Checkbox(OBFUSTR("Force Penetrating Bullets"), &penetrate);
                    }
                    EndChild();
                } else if (sub_selected == RocketSubTab) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Rocket"), ImVec2(438, 684));
                    {
                        Combo("Fly types", &rocketMode, rocketModes, IM_ARRAYSIZE(rocketModes));
                        Checkbox(OBFUSTR("Long Lifetime"), &longLifetime);
                        Checkbox(OBFUSTR("Ricochet"), &ricochet);
                        Checkbox(OBFUSTR("No Self-Damage"), &dontDoSelfDmg);
                        Checkbox(OBFUSTR("Rocket Tower"), &rocketTower);
                        Checkbox(OBFUSTR("Drone strike"), &droneStrike);
                    }
                    EndChild();
                } else if (sub_selected == Effect) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Effect"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Ignore Reflection"), &ignorereflect);
                        TextUnformatted(OBFUSTR("Ignores the reflection effect."));
                        Checkbox(OBFUSTR("Force Charm"), &charm);
                        TextUnformatted(OBFUSTR("Adds the charm effect"));
                        Checkbox(OBFUSTR("Force Electric Shock"), &electric);
                        TextUnformatted(OBFUSTR("Adds the electric shock effect"));
                        Checkbox(OBFUSTR("Force Blindness Effect"), &blindness);
                        TextUnformatted(OBFUSTR("Adds the electric shock effect"));
                        Checkbox(OBFUSTR("Force Gadget Disabler Effect"), &gadgetdisabler);
                        TextUnformatted(OBFUSTR("Adds the head gadget disabler effect"));
                    }
                    EndChild();
                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Effect2"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Force Speed-Up Effect"), &speedup);
                        Checkbox(OBFUSTR("Force Slow-down Effect"), &slowdown);
                        Checkbox(OBFUSTR("Force Jump Disabler Effect"), &jumpdisable);
                        Checkbox(OBFUSTR("Force Head Magnifier Effect"), &headmagnify);
                        Checkbox(OBFUSTR("Force Poison Effect"), &poison);
                        Checkbox(OBFUSTR("Force Cursing Effect"), &curse);
                        Checkbox(OBFUSTR("Force Stun Effect"), &stun);
                    }
                    EndChild();
                } else if (sub_selected == Aimbot) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Aimbot"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Aimbot"), &aimbot);
                        Combo(OBFUSTR("##Type"), (int *) &aimbotmode, mode, 2);
                        TextUnformatted(OBFUSTR("Aim Radius"));
                        SliderFloat(OBFUSTR("##Radius"), &aimbotradius, 0, 700);
                        TextUnformatted(OBFUSTR("Aim Distance"));
                        SliderFloat(OBFUSTR("##Distance"), &aimbotdistance, 0, 1000);
                        Checkbox(OBFUSTR("Headshot"), &headshotMode);
                        if (aimbotmode == 0) {
                            Checkbox(OBFUSTR("Visible Only"), &aimVisible);
                        }
                        Checkbox(OBFUSTR("Triggerbot"), &triggerbot);
                    }
                    EndChild();
                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Silent Aimbot"), ImVec2(438, 684));
                    {
                        Checkbox(OBFUSTR("Silent Aimbot"), &silentaim);
                        Combo(OBFUSTR("##Typemode"), (int *) &silentaimmode, mode2, 2);
                        if (silentaimmode == 0) {
                            Checkbox(OBFUSTR("Through enemies"), &throughenemies);
                            TextUnformatted(OBFUSTR("Silent Aim Distance"));
                            SliderFloat(OBFUSTR("##Distance"), &silentaimdistance, 0, 9999);
                        } else {
                            TextUnformatted(OBFUSTR("Silent Aim Radius"));
                            SliderFloat(OBFUSTR("##Radius"), &silentaimradius, 0, 9999);
                        }
                    }
                    EndChild();
                }
            }

            if (selected == VisualTab) {
                BeginGroup();
                SetCursorPos(ImVec2(130, 28));
                if (custom_interface::subtab(OBFUSTR("Visual"), Visual == sub_selected)) {
                    sub_selected = Visual;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("ESP"), ESPSub == sub_selected)) {
                    sub_selected = ESPSub;
                }
                EndGroup();

                if (sub_selected == Visual) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Visual Mods"), ImVec2(876, 684));
                    {
                        Checkbox(OBFUSTR("Nuclear Explosion"), &nuke);
                        Checkbox(OBFUSTR("Chams"), &xray);
                        TextUnformatted(OBFUSTR("Shows the enemy body through walls."));
                        Checkbox(OBFUSTR("Show marker"), &enemymarker);
                        TextUnformatted(OBFUSTR("Shows the enemy after you shoot them once."));
                        Checkbox(OBFUSTR("Quick-Scope"), &quickscope);

                        Checkbox(OBFUSTR("My Player Scale"), &playerScale);
                        SameLine();
                        SliderFloat(OBFUSTR("##MyScale"), &myScale, 0.5f, 50.0f);

                        Checkbox(OBFUSTR("Others Player Scale"), &otherPlayerScale);
                        SameLine();
                        SliderFloat(OBFUSTR("##OtherScale"), &otherScale, 0.5f, 50.0f);
                    }
                    EndChild();
                } else if (sub_selected == ESPSub) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("ESP"), ImVec2(876, 684));
                    {
                        Checkbox(OBFUSTR("ESP Line"), &espline);
                        Checkbox(OBFUSTR("ESP Line from middle"), &espline2);
                        Checkbox(OBFUSTR("ESP Box"), &espbox);
                        Checkbox(OBFUSTR("ESP Distance"), &espdistance);
                        // TODO Checkbox(OBFUSTR("ESP HP"), &esphp);
                    }
                    EndChild();
                }
            }

            if (selected == WebsocketTab) {
                BeginGroup();
                SetCursorPos(ImVec2(130, 28));
                if (custom_interface::subtab(OBFUSTR("Adders"), Wear == sub_selected)) {
                    sub_selected = Wear;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Weapons"), WeaponUnl == sub_selected)) {
                    sub_selected = WeaponUnl;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Stat-Changer"), Stats == sub_selected)) {
                    sub_selected = Stats;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Events"), Events == sub_selected)) {
                    sub_selected = Events;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Clan"), WSClan == sub_selected)) {
                    sub_selected = WSClan;
                }
		SameLine();
                if (custom_interface::subtab(OBFUSTR("Clan2"), WSClan2 == sub_selected)) {
                    sub_selected = WSClan2;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Options"), WebSocket == sub_selected)) {
                    sub_selected = WebSocket;
                }
                EndGroup();

                if (sub_selected == Wear) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Adders"), ImVec2(438, 684));
                    {
                        if (Button(OBFUSTR("Add All Wear"))) {
                            addwearss = OBFUSINT(true);
                        }
                        if (Button(OBFUSTR("Add All Gadgets"))) {
                            addAllGadgets = OBFUSINT(true);
                        }
                        if (Button(OBFUSTR("Add All Royale Items")))
                            addRoyale = true;
                        if (Button(OBFUSTR("Test Gift")))
                            testgift = true;
                        if (Button(OBFUSTR("Add All Pets")))
                            addAllPets = OBFUSINT(true);
                        if (Button(OBFUSTR("Add Wear Parts")))
                            AddWearParts_ = OBFUSINT(true);
                        if (Button(OBFUSTR("Add Royale Parts")))
                            AddRoyaleParts_ = OBFUSINT(true);
                        if (Button(OBFUSTR("Add all weapon skins")))
                            addallweaponskins = OBFUSINT(true);
                        if (Button(OBFUSTR("Add all graffiti")))
                            addallgraffiti = OBFUSINT(true);
                    }
                    EndChild();
                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Special Unlocks"), ImVec2(438, 684));
                    {
                        if (Button(OBFUSTR("Add all modules")))
                            addmoduless = OBFUSINT(true);
                        if (Button(OBFUSTR("Add module level")))
                            addmodulelevel = OBFUSINT(true);
                        SliderInt(OBFUSTR("Level##asdasd"), &ws::moduleLevel, 1, 9);
                        Checkbox(OBFUSTR("Cap Module Level At Max"), &capModules);
                        Separator();
                        if (Button(OBFUSTR("Max Account")))
                            maxAccountws = OBFUSINT(true);
                        Checkbox(OBFUSTR("Include Royale"), &includeTrails);
                        TextUnformatted(OBFUSTR("This is just a quick way\n"
                                                "to add all items in the game\n"
                                                "except lobby items."));
                    }
                    EndChild();
                } else if (sub_selected == WeaponUnl) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Weapons"), ImVec2(438, 684));
                    {
                        TextUnformatted(OBFUSTR("Add weapons:"));
                        TextUnformatted(OBFUSTR("From Index: "));
                        SameLine();
                        SliderInt("##from_index", &wepValFirst, 1, 2000);
                        TextUnformatted(OBFUSTR("To Index: "));
                        SameLine();
                        SliderInt("##to_index", &wepValLast, wepValFirst, 2000);
                        if (Button("Add selected weapons"))
                            addWeapons = true;
                        if (Button("Add all weapons"))
                            addweaponss = OBFUSINT(true);
                        TextUnformatted("Weapon rarity");
                        Combo("##", &selectedWepRarity, ItemRarity, IM_ARRAYSIZE(ItemRarity));
                        if (Button(OBFUSTR("Add Weapon Parts")))
                            AddWeaponParts_ = OBFUSINT(true);

                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("ManualWeapon"), ImVec2(438, 684));
                    {
                        // ListBox(OBFUSTR("Illegals"), &selectedWeapon, goofyWeps, IM_ARRAYSIZE(goofyWeps), 10);
                        // TODO: Implement the method that actually gets these types of weapons
                    }
                    EndChild();
                } else if (sub_selected == Stats) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Page1 stats"), ImVec2(438, 684));
                    {
                        InputTextWithHint(OBFUSTR("######Kills"), OBFUSTR("Enter Kills"),
                                          &ws::killsliderStr, ImGuiInputTextFlags_CharsDecimal);
                        InputTextWithHint(OBFUSTR("##Deaths"), OBFUSTR("Enter Deaths"),
                                          &ws::deathsliderStr, ImGuiInputTextFlags_CharsDecimal);
                        InputTextWithHint(OBFUSTR("###Headshots"), OBFUSTR("Enter Headshots"),
                                          &ws::headshotsliderStr, ImGuiInputTextFlags_CharsDecimal);
                        InputTextWithHint(OBFUSTR("####Killstreak"), OBFUSTR("Enter Killstreak"),
                                          &ws::killstreaksliderStr,
                                          ImGuiInputTextFlags_CharsDecimal);
                        InputTextWithHint(OBFUSTR("#####Winstreak"), OBFUSTR("Enter Winstreak"),
                                          &ws::winstreaksliderStr,
                                          ImGuiInputTextFlags_CharsDecimal);

                        if (Button(OBFUSTR("Update Stats")))
                            UpdateStats_ = OBFUSINT(true);
                        TextUnformatted(
                                OBFUSTR("warning for the feature below \nUsing values over 1000 \nwill most likely lag/freeze your game.\n"));
                        InputTextWithHint(OBFUSTR("######Wins & Matches"),
                                          OBFUSTR("Enter Wins & Matches"),
                                          &ws::winandmatchamountStr,
                                          ImGuiInputTextFlags_CharsDecimal);
                        if (Button(OBFUSTR("Update Wins & Matches")))
                            AddWinsandmatches_ = OBFUSINT(true);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Page2 stats"), ImVec2(438, 684));
                    {
                        TextUnformatted(
                                OBFUSTR("warning for the feature below \nUsing values over 1000 \nwill most likely lag/freeze your game.\n"));
                        InputTextWithHint(OBFUSTR("#####MonthlyWinCount"),
                                          OBFUSTR("Enter Monthly Wins"), &ws::MonthlyCountSliderStr,
                                          ImGuiInputTextFlags_CharsDecimal);

                        if (ImGui::BeginCombo("Game Mode", gameModes[currentMode].name.c_str())) {
                            for (int n = 0; n < gameModes.size(); n++) {
                                bool is_selected = (currentMode == n);
                                if (ImGui::Selectable(gameModes[n].name.c_str(), is_selected))
                                    currentMode = n;
                                if (is_selected)
                                    ImGui::SetItemDefaultFocus();
                            }
                            ImGui::EndCombo();
                        }

                        if (Button(OBFUSTR("Add Win")))
                            gameModes[currentMode].winFlag = OBFUSINT(true);
                        TextUnformatted(OBFUSTR(""));
                        InputTextWithHint(OBFUSTR("#####playerid"), OBFUSTR("Enter Player ID"), &ws::PlayerIDstr, ImGuiInputTextFlags_CharsDecimal);
                        InputTextWithHint(OBFUSTR("#####curtrophies"), OBFUSTR("Enter Current Trophies"), &ws::currentscorestr, ImGuiInputTextFlags_CharsDecimal);
                        InputTextWithHint(OBFUSTR("#####trophies"), OBFUSTR("Enter New Trophies"), &ws::scoreaddthropiesstr, ImGuiInputTextFlags_CharsDecimal);
                        if (Button(OBFUSTR("Update Trophies")))
                            AddThropies_ = OBFUSINT(true);
                    }
                    EndChild();
                } else if (sub_selected == WebSocket) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("WS-1-1"), ImVec2(438, 684));
                    {
                        if (Button(OBFUSTR("Send Websocket")))
                            sendWebsocket = OBFUSINT(true);
                        if (Button(OBFUSTR("Reload Websocket")))
                            sendReload = OBFUSINT(true);
                        Checkbox(OBFUSTR("Log Websocket"), &logWS);
                        Checkbox(OBFUSTR("Log Progress"), &logprogress);
                        Checkbox(OBFUSTR("Toast Requests"), &logrequests);
                        if (logrequests)
                            Checkbox(OBFUSTR("Auto reload"), &autoreload);
                    }
                    EndChild();

                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("WS-1-2"), ImVec2(438, 684));
                    {
#ifdef DEBUG_WEBSOCKET
                        if (Button(OBFUSTR("Log to file")))
                            logprogresstofile = OBFUSINT(true);
                        TextUnformatted(OBFUSTR("Enter console IP here:"));
                        InputTextWithHint(OBFUSTR(" "), OBFUSTR("IP HERE"), &ws::localIp);
                        if (!ws::console_isConnected) {
                            if (Button("Connect Websocket Console")) {
                                ws::console_connect();
                                sendReload = true;
                            }
                        } else {
                            if (Button("Disconnect Websocket Console")) {
                                ws::console_disconnect();
                            }
                        }
#endif
                    }
                    EndChild();
                } else if (sub_selected == Events) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("WS-2-1"), ImVec2(438, 684));
                    {
                        TextUnformatted(OBFUSTR("Battle Pass"));
                        SliderInt(OBFUSTR("Exp"), &ws::passexp, 0, 100000);
                        if (Button(OBFUSTR("Add Battle Pass Exp")))
                            AddBattlePassExp_ = OBFUSINT(true);
                        if (Button(OBFUSTR("Add Premium Battle Pass")))
                            AddBattlePassPremium_ = OBFUSINT(true);
                        if (Button(OBFUSTR("Complete Elite Challenges")))
                            CompleteEliteChallanges_ = OBFUSINT(true);
                        TextUnformatted(OBFUSTR("Boosters"));
                        SliderInt(OBFUSTR("amount"), &ws::boosteramount, 0, 50000);
                        SliderInt(OBFUSTR("type"), &ws::boostertype, 1, 4);
                        if (Button(OBFUSTR("Add Boosters")))
                            addbooosters = OBFUSINT(true);
                        SameLine();
                        if (Button(OBFUSTR("Add Gem Boosters")))
                            AddGemBoosters_ = OBFUSINT(true);
                    }

                    EndChild();
                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("WS-2-2"), ImVec2(438, 684));
                    {
                        TextUnformatted(OBFUSTR("Lottery"));
                        Checkbox("Unsafe Key Slider", &unsafeKeys);
                        if (unsafeKeys)
                            SliderInt("", &ws::keysamount, 0, 2147000000);
                        else
                            SliderInt("", &ws::keysamount, 0, 10000);
                        if (Button(OBFUSTR("Set Keys")))
                            AddKeys_ = OBFUSINT(true);
                        Separator();
                        Checkbox("Unsafe Chest Slider", &unsafechests);
                        if (unsafechests)
                            SliderInt("###sexsex", &ws::chestamount, 0, 2147000000);
                        else
                            SliderInt("###sex123456", &ws::chestamount, 0, 10000);
                        SliderInt(OBFUSTR("ChestType"), &ws::chesttype, 1, 3);
                        if (Button(OBFUSTR("Set Chests")))
                            AddChestWS = OBFUSINT(true);

                    }
                    EndChild();
                } else if (sub_selected == WSClan) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("WS-3-1"), ImVec2(438, 684));
                    {
                        TextUnformatted(OBFUSTR("These Commands Require ClanID"));
                        InputTextWithHint(OBFUSTR("  "), "Enter Clan ID", &ws::ClanIDstr);
			TextUnformatted(OBFUSTR(""));
                        SliderInt(OBFUSTR("ItemAmount"), &ws::clanitemamount, 0, 50000);
                        if (Button(OBFUSTR("Bug Clan Fort (adds bugged parts)")))
                            AddClan_ = OBFUSINT(true);
			TextUnformatted(OBFUSTR("You need to be officer or higher\nto use the feature below\n"));
			SliderInt(OBFUSTR("Clan Level"), &ws::clanlevell, 0, 10);
                        if (Button(OBFUSTR("Set Clan Level (fort)")))
                            SetClanLevelFort_ = OBFUSINT(true);
                        if (Button(OBFUSTR("Set Clan Level (tank)")))
                            SetClanLevelTank_ = OBFUSINT(true);    
                        
                    }

                    EndChild();
                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("WS-3-2"), ImVec2(438, 684));
                    {
			TextUnformatted(OBFUSTR("ClanID is not needed\nfor features below\n"));    
                        SliderInt(OBFUSTR("Clan Rank"), &ws::clanrankk, 0, 11);
                        if (Button(OBFUSTR("Set Clan Rank")))
                            SetClanRank_ = OBFUSINT(true);
                        SliderInt(OBFUSTR("Seconds"), &ws::lenght_in_seconds, 0, 1000000000);
                        if (Button(OBFUSTR("Add Silver Boosts")))
                            BuffClan_ = OBFUSINT(true);    
                        TextUnformatted(OBFUSTR(""));
                    }
                    EndChild();
                } else if (sub_selected == WSClan2) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("WS-4-1"), ImVec2(438, 684));
                    {
                        TextUnformatted(OBFUSTR("WarID can only be obtained with logcat\nthis is only needed for add valor\n"));
                        InputTextWithHint(OBFUSTR("     "), "Enter War ID", &ws::WarIDstr);
			TextUnformatted(OBFUSTR(""));
                        InputTextWithHint(OBFUSTR("  "), "Enter Clan ID", &ws::ClanIDstr);
                        InputTextWithHint(OBFUSTR("   "), "Enter Player ID", &ws::PlayerIDstr);
                        SliderInt(OBFUSTR("Points"), &ws::rankexpsliderhack, 0, 100000);
                        if (Button(OBFUSTR("Add Rank Points")))
                            hackrankexperience_ = OBFUSINT(true);
                        TextUnformatted(OBFUSTR("Button below can be used\nonly once, amount is random\n"));
                        if (Button(OBFUSTR("Try to add valor")))
                            hackclanvalor_ = OBFUSINT(true);

                    }

                    EndChild();
                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("WS-4-2"), ImVec2(438, 684));
                    {
                        
                    }
                    EndChild();
                }
            }

            if (selected == MiscTab) {
                BeginGroup();
                SetCursorPos(ImVec2(130, 28));
                if (custom_interface::subtab(OBFUSTR("Misc"), Misc == sub_selected)) {
                    sub_selected = Misc;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Account"), AccountSub == sub_selected)) {
                    sub_selected = AccountSub;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Spoof"), SpoofOptions == sub_selected)) {
                    sub_selected = SpoofOptions;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Commands"), Commands == sub_selected)) {
                    sub_selected = Commands;
                }
                SameLine();
                if (custom_interface::subtab(OBFUSTR("Info"), Info == sub_selected)) {
                    sub_selected = Info;
                }
                /*SameLine();
                if (custom_interface::subtab(OBFUSTR("Scene Explorer"), Explorer == sub_selected)) {
                    sub_selected = Explorer;
                }*/
                EndGroup();

                if (sub_selected == Misc) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("MiscTT"), ImVec2(876, 684));
                    {
                        Checkbox(OBFUSTR("UwUify messages"), &uwufy);
                        SameLine();
                        Checkbox(OBFUSTR("Log RPC"), &logRPC);
                        Checkbox(OBFUSTR("GUI visible"), &isGuiVisible);
                        SameLine();
                        Checkbox(OBFUSTR("Bypass Swear Filter"), &swear);
                        SameLine();
                        Checkbox(OBFUSTR("deUncap FPS"), &deUncapFps);
                        Separator();
                        if (Button(OBFUSTR("Enable Console")))
                            enableConsole = OBFUSINT(true);
                        SameLine();
                        if (Button(OBFUSTR("Enable UIInputs")))
                            enableUIInput = OBFUSINT(true);
                        if (Button(OBFUSTR("Remove colliders")))
                            rmColliders = OBFUSINT(true);
                        SameLine();
                        if (Button(OBFUSTR("Re-enable colliders")))
                            yesCollider = OBFUSINT(true);
                        Separator();
                        if (Button(OBFUSTR("Force Load Menu"))) {
                            loadMenu = OBFUSINT(true);
                        }
                        std::string sceneInfoName = "Current scene: ";
                        sceneInfoName += scene;
                        TextUnformatted(sceneInfoName.c_str());
                    }
                    EndChild();
                } /*else if (sub_selected == Explorer) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("SceneHierarchy"), ImVec2(438, 702));
                    {
                        BeginListBox("##scn_hier", ImVec2(350, 658));
                        int i = 0;
                        for (gobj_inst obj: objListDyn) {
                            std::string &item_name = obj.name;
                            if (!explorerSearchQuery.empty())
                                if (!strstr(lowercase(item_name).c_str(),
                                            lowercase(explorerSearchQuery).c_str())) {
                                    i++;
                                    continue;
                                }
                            if (Selectable(item_name.c_str(), &obj.selected)) {
                                selectedGObj = i;
                                qCurObjActive = GameObject$$GetActive(objListDyn[selectedGObj].obj);
                            }
                            i++;
                        }
                        EndListBox();
                    }
                    EndChild();
                    SetCursorPos(ImVec2(482, 88));
                    BeginChild(OBFUSTR("SceneHierarchy__btns"), ImVec2(438, 702));
                    {
                        if (Button(OBFUSTR("Refresh"))) {
                            qUpdateObjList = OBFUSINT(true);
                        }
                        SameLine();
                        if (Button(OBFUSTR("Clone"))) {
                            if (!objListDyn[selectedGObj].obj) return;
                            qCloneObj = OBFUSINT(true);
                            updateObjList();
                        }
                        InputTextWithHint(OBFUSTR("##e_srch_qry"), "Search Query",
                                          &explorerSearchQuery);
                        if (Checkbox(OBFUSTR("Active"), &qCurObjActive)) {
                            if (!objListDyn[selectedGObj].obj) return;
                            GameObject$$SetActive(objListDyn[selectedGObj].obj, qCurObjActive);
                            updateObjList();
                        }
                    }
                    EndChild();
                }*/ else if (sub_selected == AccountSub) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Account Mods"), ImVec2(438, 684));
                    {
                        TextUnformatted(OBFUSTR("WARNING! THESE ARE NOT \nRECOVERABLE ACTIONS\n"));
                        if (Button("Ban Account (Press twice)"))
                            banAcc = true;
                        if (Button("Create new account"))
                            createAcc = true;
                        TextUnformatted(
                                OBFUSTR("Press this button and restart\nto force creation of a new account"));
                    }
                    EndChild();
                    SetCursorPos(ImVec2(582, 88));
                    BeginChild(OBFUSTR("Special Unlocks"), ImVec2(438, 684));
                    {
                        if (Button(OBFUSTR("DumpAcc")))
                            showInfo = true;
                        const char *combo_label = files.empty() ? "No dumps found"
                                                                : files[fileSelection].c_str();
                        if (ImGui::BeginCombo("##combo", combo_label)) {
                            for (int n = 0; n < files.size(); n++) {
                                const bool is_selected = (fileSelection == n);
                                if (ImGui::Selectable(files[n].c_str(), is_selected)) {
                                    fileSelection = n;
                                    std::ifstream inputFile(
                                            "/storage/emulated/0/Android/data/com.pixel.gun3d/dumps/" +
                                            files[n]);
                                    std::getline(inputFile, secretlog);
                                    std::getline(inputFile, idlog);
                                    inputFile.close();
                                }
                                if (is_selected)
                                    ImGui::SetItemDefaultFocus();
                            }
                            ImGui::EndCombo();
                        }
                        SameLine();
                        if (Button(OBFUSTR("Refresh##aaa"))) {
                            files.clear();
                            std::string dumps_path = "/storage/emulated/0/Android/data/com.pixel.gun3d/dumps/";

                            if (std::filesystem::exists(dumps_path)) {
                                for (const auto &entry: std::filesystem::directory_iterator(
                                        dumps_path)) {
                                    files.push_back(entry.path().filename().string());
                                }
                            }
                        }
                        TextUnformatted(OBFUSTR("Display account details"));
                        if (Button(OBFUSTR("LoadAcc")))
                            loadAcc = true;
                        TextUnformatted(OBFUSTR("Attempts to log into an account."));
                        InputText("ID", &idlog);
                        InputText("Secret", &secretlog);
                        if (!authSecret.empty() && !authID.empty()) {
                            Text("authSecret: ");
                            Text("%s", authSecret.c_str());
                            Text("authID = %s", authID.c_str());
                            Text("Succesfully wrote the file dump.txt,\n"
                                 "check for a file with the name of your ID\n"
                                 "in pg3d's data folder");
                        }
                    }
                    EndChild();
                } else if (sub_selected == SpoofOptions) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("Spoof Options"), ImVec2(876, 684));
                    {
                        Checkbox(OBFUSTR("Spoof an invalid ID"), &spoofMe3);
                        Checkbox(OBFUSTR("Spoof Editor"), &isEditor);
                        Separator();
                        Combo(OBFUSTR("##Select name"), &nicknameIndex, nicknamesCombo,
                              IM_ARRAYSIZE(nicknamesCombo));
                        Checkbox(OBFUSTR("Spoof Nickname"), &spoofNick);
                    }
                    EndChild();
                } else if (sub_selected == Commands) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("AuthInfo"), ImVec2(876, 684));
                    {
                        TextUnformatted(OBFUSTR("Command list here:"));
                        TextUnformatted(OBFUSTR("!tp [nearest/random] {steps}"));
                        TextUnformatted(OBFUSTR("!nick {nickname}"));
                        TextUnformatted(OBFUSTR("!instantiate {prefabName}"));
                        TextUnformatted(OBFUSTR("!otax {name}"));
                        TextUnformatted(
                                OBFUSTR("!invite {playerID} {spamAmount} (Squad Chat Only)"));
                    }
                    EndChild();
                } else if (sub_selected == Info) {
                    SetCursorPos(ImVec2(130, 88));
                    BeginChild(OBFUSTR("AuthInfo"), ImVec2(876, 684));
                    {
                        if (Button(OBFUSTR("Log Out"))) {
                            if (logout())
                                isVerifed = false;
                        }
                        std::string exp = "Expiry: ";
                        exp += expiry;
                        TextUnformatted(exp.c_str());
                        std::string usr = "You're currently logged in as: ";
                        usr += licuser;
                        TextUnformatted(usr.c_str());
                        if (Button(OBFUSTR("Open Panel")))
                            openPanel = OBFUSINT(true);
                        TextUnformatted(OBFUSTR("Made by [modfs]"));
                        TextUnformatted(
                                OBFUSTR("fedesito, chr1s, xz3phyr, fatnegro, 55ar., acessor, VerifedMatt"));
                        TextUnformatted(
                                OBFUSTR("BoredKarma, YeetDisDude, soto_sapi1, ARandomPerson"));
                        Checkbox(OBFUSTR("Show console"), &showing_term);
						Checkbox(OBFUSTR("Show scene explorer"), &isSceneExplorerOpen);
                        Checkbox(OBFUSTR("Show watermark"), &showWatermark);
                        Checkbox(OBFUSTR("Antiban"), &antiban); // move this somewhere else
                    }
                    EndChild();
                }
            }
        } else {
            // sadly cant use SetNextWindowSize, we run the risk of a fatal crash
            SetWindowSize(ImVec2(140, 120));

            SetCursorPos(ImVec2(32, 32));
            if (Button(ICON_KI_ADJUST)) {
                isMinimized = OBFUSINT(false);
            }
        }
        End();
    }
}

void DrawLoginPanel() {
    // code for no auth detected...
    Begin(OBFUSTR("AuthPanel"), nullptr, ImGuiWindowFlags_NoDecoration);
    {
        if (logged) {
            TextUnformatted(OBFUSTR("Successfully logged in!"));
            TextUnformatted(OBFUSTR("Restart to load the mod menu."));
        } else {
            TextUnformatted(OBFUSTR("Welcome to the auth panel! Log in to access the menu."));
            if (isEmu) {
                TextUnformatted(
                        OBFUSTR("An emulator has been detected, text inputs will NOT work"));
                TextUnformatted(OBFUSTR("Make a new file named acc.txt and put it inside:"));
                TextUnformatted(OBFUSTR("/storage/emulated/0/Android/data/com.pixel.gun3d"));
                TextUnformatted(
                        OBFUSTR("It must have on the 1st line your USERNAME and on the 2nd line your PASSWORD"));
            }
            InputText(OBFUSTR("Username"), &user);
            InputText(OBFUSTR("Password"), &pass, ImGuiInputTextFlags_Password);
            if (Button(OBFUSTR("Log In"))) {
                logged = login(user, pass);
                if (logged) {
                    std::remove(
                            OBFUSTR("/storage/emulated/0/Android/data/com.pixel.gun3d/account.txt"));
                    nlohmann::json j;
                    j[OBFUSTR("username")] = user;
                    j[OBFUSTR("password")] = pass;
                    std::string s = j.dump();
                    std::string contents = xor_shift(s, OBFUSTR("ZhEbCs6DDHLwIGA4"));
                    std::ofstream out(
                            OBFUSTR("/storage/emulated/0/Android/data/com.pixel.gun3d/account.txt"));
                    out << contents;
                    out.close();
                }
            }
        }

        std::string s = OBFUSTR("Status: ");
        s += status.c_str();

        TextUnformatted(s.c_str());

        if (!logged && Button(OBFUSTR("Buy the Menu")))
            buyMenu = OBFUSINT(true);
        if (Button(OBFUSTR("Join Discord Server")))
            isDiscordPressed = OBFUSINT(true);
        if (Button(OBFUSTR("Open Panel")))
            openPanel = OBFUSINT(true);
        End();
    }
    return;
}

void CustomImGuiStyle() {
    // Fork of Comfy #2 style from ImThemes
    ImGuiStyle &style = ImGui::GetStyle();

    style.Alpha = 0.95f;
    style.DisabledAlpha = 0.1000000014901161f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 0.f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(30.0f, 30.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Right;
    style.ChildRounding = 0.f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.f;
    style.PopupBorderSize = 0.0f;
    style.FramePadding = ImVec2(5.0f, 3.5f);
    style.FrameRounding = 0.f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(5.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(5.0f, 5.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 5.0f;
    style.ColumnsMinSpacing = 5.0f;
    style.ScrollbarSize = 15.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 15.0f;
    style.GrabRounding = 0.f;
    style.TabRounding = 0.f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(1.0f, 1.0f, 1.0f, 0.3605149984359741f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.09803921729326248f, 0.09803921729326248f,
                                             0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.4806866645812988f, 0.0f, 1.0f, 0.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.09803921729326248f, 0.09803921729326248f,
                                            0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.5318465232849121f, 0.0f, 1.0f, 0.54935622215271f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1287550032138824f, 0.1287540942430496f,
                                            0.1287553906440735f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2417668849229813f, 0.1107775121927261f,
                                                   0.4163089990615845f, 0.5490196347236633f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.4547991752624512f, 0.0f, 1.0f,
                                                  0.5490196347236633f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.09803921729326248f, 0.09803921729326248f,
                                            0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.09803921729326248f, 0.09803921729326248f,
                                                  0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.2588235437870026f, 0.2588235437870026f,
                                                     0.2588235437870026f, 0.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.270386278629303f, 0.2703835666179657f,
                                                0.2703835666179657f, 0.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3218883872032166f, 0.3218851685523987f,
                                                  0.3218851685523987f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.4763948321342468f, 0.4763900637626648f,
                                                         0.4763900637626648f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.5193133354187012f, 0.5193081498146057f,
                                                        0.5193081498146057f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.5858368873596191f, 0.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.4705417156219482f, 0.2145922780036926f, 1.0f,
                                               0.5490196347236633f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.4648565053939819f, 0.3602387309074402f,
                                                     0.6824034452438354f, 0.5490196347236633f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.4612926542758942f, 0.1944408863782883f,
                                           0.7811158895492554f, 0.5879828333854675f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.4826622009277344f, 0.370185524225235f,
                                                  0.8712446689605713f, 0.5490196347236633f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.6669709086418152f, 0.3957155346870422f,
                                                 0.9313304424285889f, 0.5490196347236633f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.5564724802970886f, 0.2655786871910095f,
                                           0.7639485001564026f, 0.5490196347236633f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.5803452134132385f, 0.173294797539711f,
                                                  0.8412017226219177f, 0.5490196347236633f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.5321526527404785f, 0.0f, 1.0f,
                                                 0.5490196347236633f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.4885548949241638f, 0.2191972583532333f,
                                              0.7510729432106018f, 0.5490196347236633f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.6343529224395752f, 0.3736668229103088f,
                                                     0.8884119987487793f, 0.5490196347236633f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.6187081336975098f, 0.3219621181488037f,
                                                    0.9742489457130432f, 0.5490196347236633f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.4801560044288635f, 0.2474166005849838f,
                                               0.7896995544433594f, 0.5490196347236633f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.5724889039993286f, 0.3088470995426178f,
                                                      0.8884119987487793f, 0.5490196347236633f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.7197113633155823f, 0.3989389836788177f,
                                                     0.9484978318214417f, 0.5490196347236633f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.4878284335136414f, 0.2078873962163925f,
                                        0.733905553817749f, 0.5490196347236633f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.6060428619384766f, 0.400265246629715f,
                                               0.8798283338546753f, 0.5490196347236633f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.7706860899925232f, 0.5586398839950562f,
                                              0.9570815563201904f, 0.5490196347236633f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.0f, 0.4509803950786591f, 1.0f, 0.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1333333402872086f, 0.2588235437870026f,
                                                       0.4235294163227081f, 0.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.294117659330368f, 0.294117659330368f,
                                              0.294117659330368f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f,
                                                     0.886274516582489f, 0.5490196347236633f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.6196078658103943f, 0.5764706134796143f,
                                                  0.7686274647712708f, 0.5490196347236633f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.7372549176216125f, 0.6941176652908325f,
                                                         0.886274516582489f, 0.5490196347236633f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f,
                                                  0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.4235294163227081f, 0.3803921639919281f,
                                                      0.572549045085907f, 0.5490196347236633f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.4235294163227081f, 0.3803921639919281f,
                                                     0.572549045085907f, 0.2918455004692078f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.03433477878570557f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.7372549176216125f, 0.6941176652908325f,
                                                   0.886274516582489f, 0.5490196347236633f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f,
                                                      0.800000011920929f, 0.2000000029802322f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f,
                                                     0.800000011920929f, 0.3499999940395355f);
}

#endif //ZYGISK_MENU_TEMPLATE_MENU_H
