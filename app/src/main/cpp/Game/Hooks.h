void NetworkStartTable(void* ths) {
    if(ths != nullptr && timeSinceMatch > 5.f && isInMatch()) {
        photonViewList = GetStaticField<il2cppList<void**>*>(il2cpp_class_from_name(LibImages.AssemblyCSharp, "", "PhotonObjectCacher"), "丌丌七丆丅丈丂东不");

        if(winspleeef) {
            winInSpleef(ths);
            winspleeef = OBFUSINT(false);
        }

        if (spoofNick2) {
            GetField<il2cppString*>(ths, 0xF0) = CreateIl2cppString(nickName.c_str());
        }

        if(blackScreenAll) {
            float val0 = 0.0f/0.0f;
            float val1 = 99999999999.0f;
            Il2CppArray* arr = il2cpp_array_new(CSharpTypeClass.Object, 2);
            arr->vector[0] = il2cpp_value_box(CSharpTypeClass.Float, &val0);
            arr->vector[1] = il2cpp_value_box(CSharpTypeClass.Float, &val1);

            if(photonViewList != nullptr) {
                photonViewList->foreach([&](void *view, int index) {
                    if (view != nullptr && !PhotonView$IsMine(view)) {
                        PhotonView$RPC(view, EventEnum::SlowdownRPC, PhotonTargets::All, arr);
                    }
                });
            }

            blackScreenAll = false;
        }

        if(handBugAll) {

            int16_t val3 = 834;
            int16_t val4 = 2;
            int32_t val5 = 0;

            Il2CppArray* arr = il2cpp_array_new(CSharpTypeClass.Object, 3);
            arr->vector[0] = il2cpp_value_box(CSharpTypeClass.Int16, &val3);
            arr->vector[1] = il2cpp_value_box(CSharpTypeClass.Int16, &val4);
            arr->vector[2] = il2cpp_value_box(CSharpTypeClass.Int32, &val5);

            if(photonViewList != nullptr) {

                photonViewList->foreach([&](void* view, int index) {
                    if(view != nullptr && !PhotonView$IsMine(view)) {
                        PhotonView$RPC(view, EventEnum::SetWeaponRPC, PhotonTargets::All, arr);
                    }
                });
            }

            handBugAll = false;
        }

        if (addingscore) {
            addToScore(ths, addscoreamount);
            addingscore = OBFUSINT(false);
        }

        if(speedupAll && sharedPlayerList != nullptr && timeSinceMatch > 5.f) {
            sharedPlayerList->foreach([&](void* player, int index) {
                if (!get_isMine(player)) {
                    void *playerGameObject = Component$get_object(get_PlayerTransform(player));
                    void *playerDamageable = get_PlayerDamageable(player);
                    SetPlayerSpeed(myPlayer, playerDamageable, 99999999.0f, 99999999.0f);
                }
            });
            slowdownAll = OBFUSINT(false);
        }
        if(slowdownAll && sharedPlayerList != nullptr && timeSinceMatch > 5.f) {
            sharedPlayerList->foreach([&](void* player, int index) {
                if (!get_isMine(player)) {
                    void *playerGameObject = Component$get_object(get_PlayerTransform(player));
                    void *playerDamageable = get_PlayerDamageable(player);
                    SetPlayerSpeed(myPlayer, playerDamageable, 99999999.0f, -99999999.0f);
                }
            });
            speedupAll = OBFUSINT(false);
        }
        if(disableJumpAll && sharedPlayerList != nullptr && timeSinceMatch > 5.f) {
            sharedPlayerList->foreach([&](void* player, int index) {
                if (!get_isMine(player)) {
                    void *playerGameObject = Component$get_object(get_PlayerTransform(player));
                    void *playerDamageable = get_PlayerDamageable(player);
                    DisablePlayerJump(myPlayer, playerDamageable, 99999999.0f);
                }
            });
        }

    }
}

void (*old_WeaponManager)(void* obj);
void WeaponManager(void* obj) {
    if (obj != nullptr) {

        myPlayer = GetField<void*>(obj, 0x48);
        if(myPlayer != nullptr) {
            NetworkStartTable(GetField<void*>(myPlayer, 0x60)); // myNetworkStartTable 16.6.1
        }

        if (corruptedSniper) {
            addWeapon(obj, (il2cppString*)il2cpp_string_new("mutagen_neutralizer"), 14);
            addWeapon(obj, (il2cppString*)il2cpp_string_new("anniversary_anti_champion"), 14);
            addWeapon(obj, (il2cppString*)il2cpp_string_new("disruptive_howitzer"), 14);
        }

    }
    old_WeaponManager(obj);
}

void DrawESP() {
    if (aimbot && aimbotmode != 0 && aimbotradius > 1)
        ESP::DrawCircle(glWidth / 2, glHeight / 2, aimbotradius, false, ImVec4(1, 0, 0, 1));
    if (!espline && !espbox && !espdistance && !esphp && !espline2)
        return;
    if (!isInMatch() || timeSinceMatch < 5.f)
        return;

    if (sharedPlayerList != nullptr && pg_me.instance != nullptr) {
        sharedPlayerList->foreach([&](void* player, int index) {
            if (player != nullptr) {
                if (!get_isMine(player) && pg_me.transform != nullptr && pg_me.camera != nullptr && pg_me.firstPersonControl != nullptr) {
                    void *playerDamageable = get_PlayerDamageable(player);
                    void *transform = Component$get_transform(playerDamageable);
                    il2cppVector3 location = get_position(transform);
                    int distance = il2cppVector3::Distance(location, pg_me.location);
                    if (distance < 999) { // very intentional
                        //ESP
                        /* W2s offset is not updated because fuck dnspy on linux */
                        il2cppVector3 w2sPoint = Camera_WorldToScreenPoint(pg_me.camera, location); // we cant call pointers from non libil2cpp.so methods // ? the fuck you mean
                        if (w2sPoint.Z > 0) {
                            il2cppVector3 w2s = Camera_WorldToScreenPoint(pg_me.camera, location - il2cppVector3(0, 1.1, 0));
                            il2cppVector3 head = Camera_WorldToScreenPoint(pg_me.camera, location + il2cppVector3(0, 1, 0));
                            il2cppVector2 to = il2cppVector2(head.X, glHeight - head.Y);
                            ImVec4 espColor;
                            if (IsEnemyTo(playerDamageable, pg_me.instance))
                                espColor = ImVec4(1, 0, 0, 1);
                            else
                                espColor = ImVec4(0, 1, 0, 1);
                            if (espline && head.X != 0 && head.Z != 0)
                                ESP::DrawLine(ImVec2(glWidth / 2, 0), ImVec2(head.X, glHeight - head.Y), espColor);
                            else if (espline2 && head.X != 0 && head.Z != 0)
                                ESP::DrawLine(ImVec2(glWidth / 2, glHeight / 2), ImVec2(head.X, glHeight - head.Y), espColor);
                            if (espbox) {
                                float boxHeight = abs(head.Y - w2s.Y);
                                float boxWidth = boxHeight * 0.65f;
                                il2cppVector2 vBox = {head.X - (boxWidth / 2), head.Y};

                                ESP::DrawFilledRect(vBox.X, glHeight - vBox.Y, boxWidth, boxHeight, espColor);
                            }
                            if (espdistance) {
                                char dispsize[100];
                                sprintf(dispsize, "%d m", distance);
                                ESP::DrawText(ImVec2(to.X, to.Y), espColor, dispsize);
                            }
                        }
                    }
                }
            }
        });
    }
}

int floatCont;

void (*old_WeaponSounds)(void* obj);
void WeaponSounds(void* obj) {
    if (obj != nullptr) {
        if (allEffects) {
            FieldOffset<bool>(obj, "WeaponSounds", "isPoisoning") = true;
            FieldOffset<int>(obj, "WeaponSounds", "poisonCount") = 3;
            FieldOffset<float>(obj, "WeaponSounds", "poisonDamageMultiplier") = 0.1;
            FieldOffset<float>(obj, "WeaponSounds", "poisionTime") = 60;
        }

        if (allenemyfloat && floatCont < 10) {
            FieldOffset<bool>(obj, "WeaponSounds", "isBlindEffect") = true;
            FieldOffset<int>(obj, "WeaponSounds", "blindEffect") = 12;
            FieldOffset<float>(obj, "WeaponSounds", "isBlindEffectTime") = 99999;
            FieldOffset<bool>(obj, "WeaponSounds", "isFrostSword")  = true;
            FieldOffset<float>(obj, "WeaponSounds", "frostDamageMultiplier") = -22340000;
            FieldOffset<float>(obj, "WeaponSounds", "frostRadius") = 999999;
            floatCont++;
        } else if (floatCont >= 10) {
            floatCont = 0;
            allenemyfloat = false;
        }

        if (ammo) {
            FieldOffset<int>(obj, "WeaponSounds", "ammoInClip") = 9999;
            FieldOffset<bool>(obj, "WeaponSounds", "isUnlimitedAmmo") = true;
        }


        if (gundmg) {
            FieldOffset<bool>(obj, "WeaponSounds", "isSectorsAOE") = true;
            FieldOffset<float>(obj, "WeaponSounds", "sectorsAOEDamageMultiplierFront") = 2.5f;
            FieldOffset<float>(obj, "WeaponSounds", "sectorsAOEDamageMultiplierSide") = 2.5f;
            FieldOffset<float>(obj, "WeaponSounds", "sectorsAOEDamageMultiplierBack") = 2.5f;
            FieldOffset<float>(obj, "WeaponSounds", "sectorsAOERadiusSectorsAoE") = 16.f;
        }

        if (invisible) {
            FieldOffset<bool>(obj, "WeaponSounds", "isInvisibleAfterRespawn") = true;
            FieldOffset<float>(obj, "WeaponSounds", "isInvisibleAfterRespawnTime") = 99999.f;
        }

        if(nocharge){
            FieldOffset<float>(obj, "WeaponSounds", "gadgetDisableTime") = 0.1f;
            FieldOffset<bool>(obj, "WeaponSounds", "isGadgetDisabler") = true;
            FieldOffset<float>(obj, "WeaponSounds", "chargeTime") = 0.f;
        }

        if(curse){
            FieldOffset<bool>(obj, "WeaponSounds", "isSlowdown") = true;
            FieldOffset<float>(obj, "WeaponSounds", "slowdownCoeff") = 99999.f;
        }

        if(stun){
            FieldOffset<bool>(obj, "WeaponSounds", "isStun") = true;
            FieldOffset<float>(obj, "WeaponSounds", "stunTime") = 99999.f;
        }

        if(poison){
            FieldOffset<bool>(obj, "WeaponSounds", "isPoisoning") = true;
            FieldOffset<float>(obj, "WeaponSounds", "poisontime") = 99999.f;
        }

        if(penetrate){
            FieldOffset<bool>(obj, "WeaponSounds", "ignoreBarrier") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "ignoreSlyWofl") = true; // ignoreSlyWofl ?
            FieldOffset<bool>(obj, "WeaponSounds", "ignoreReflector") = true;
        }

        if (ignorereflect) {
            FieldOffset<bool>(obj, "WeaponSounds", "isDamageReflection") = false;
            FieldOffset<bool>(obj, "WeaponSounds", "isDamageAbsortion") = false;
        }

        if (gadgetdisabler) {
            FieldOffset<bool>(obj, "WeaponSounds", "isGadgetDisabler") = false;
            FieldOffset<float>(obj, "WeaponSounds", "gadgetDisableTime") = 99999.f;
        }

        if (catspam) {
            FieldOffset<bool>(obj, "WeaponSounds", "is3CatSpam") = true;
        }

        if (portalBull) {
            FieldOffset<bool>(obj, "WeaponSounds", "portalGun") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "isPortalExplosion") = true;
        }

        if (charm) {
            FieldOffset<bool>(obj, "WeaponSounds", "isCharm") = true;
            FieldOffset<float>(obj, "WeaponSounds", "charmTime") = 99999.f;
        }

        if (scopef) {
            FieldOffset<bool>(obj, "WeaponSounds", "isZooming") = true;
        }

        if (fte) {
            FieldOffset<bool>(obj, "WeaponSounds", "fireImmunity") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "bleedingImmunity") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "toxicImmunity") = true;
        }

        if (silentaim) {
            if (silentaimmode == 0) {
                FieldOffset<float>(obj, "WeaponSounds", "radiusRoundMelee") = 99999.f;
                FieldOffset<bool>(obj, "WeaponSounds", "flamethrower") = true;
                FieldOffset<float>(obj, "WeaponSounds", "range") = silentaimdistance;
                FieldOffset<bool>(obj, "WeaponSounds", "throughEnemies") = throughenemies;
            }
            else {
                FieldOffset<bool>(obj, "WeaponSounds", "isRoundMelee") = true;
                FieldOffset<float>(obj, "WeaponSounds", "radiusRoundMelee") = silentaimradius; //  float radiusRoundMelee
                FieldOffset<bool>(obj, "WeaponSounds", "bazooka") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "railgun") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "harpoon") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "isDash") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "flamethrower") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "isShotgun") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "grenadeLauncher") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "isMelee") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "isShotMelee") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "dotFlamethrower") = false;
                FieldOffset<bool>(obj, "WeaponSounds", "portalGun") = false;
            }
        }

        if (snowstormbull) {
            FieldOffset<bool>(obj, "WeaponSounds", "snowStorm") = false;
            FieldOffset<float>(obj, "WeaponSounds", "snowStormBonusMultiplier") = 6.f;
            if (snowstormbullval != 0 && !kniferange) {
                FieldOffset<float>(obj, "WeaponSounds", "shootDistance") = snowstormbullval;
                FieldOffset<float>(obj, "WeaponSounds", "range") = snowstormbullval;
            }
        }

        if (playerScore) {
            FieldOffset<bool>(obj, "WeaponSounds", "isBuffPoints") = true;
            FieldOffset<float>(obj, "WeaponSounds", "buffBonusPointsForKill") = 99999.f;
        }

        if (playerScore2) { //every field under buffpoints header
            FieldOffset<bool>(obj, "WeaponSounds", "isBuffPoints") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "buffPointsRevengeDesigner") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "buffPointsKillDesigner") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "buffPointsAssistDesigner") = true;
            FieldOffset<float>(obj, "WeaponSounds", "buffPointsRevenge") = 999999.f;
            FieldOffset<float>(obj, "WeaponSounds", "buffBonusPointsForKill") = 999999.f;
            FieldOffset<float>(obj, "WeaponSounds", "buffBonusPointsForAssist") = 999999.f;
            FieldOffset<float>(obj, "WeaponSounds", "buffPointsOther") = 999999.f;
            playerScore = OBFUSINT(false);
        }

        if (polymorph) {
            FieldOffset<bool>(obj, "WeaponSounds", "polymorpher") = true;
            FieldOffset<float>(obj, "WeaponSounds", "polymorphDuarationTime") = 999999.f;
            FieldOffset<float>(obj, "WeaponSounds", "polymorphMaxHealth")  = 999999.f;
            harpoonBull = OBFUSINT(true);
        }

        if(polymorph1){
            FieldOffset<bool>(obj, "WeaponSounds", "polymorpher") = true;
            FieldOffset<float>(obj, "WeaponSounds", "polymorphDuarationTime") = 99999.f;
            FieldOffset<int>(obj, "WeaponSounds", "polymorphType") = 1;
            FieldOffset<float>(obj, "WeaponSounds", "polymorphMaxHealth") = 99999.f;
            harpoonBull = OBFUSINT(true);
        }

        if(polymorph2){
            FieldOffset<bool>(obj, "WeaponSounds", "polymorpher") = true;
            FieldOffset<float>(obj, "WeaponSounds", "polymorphDuarationTime") = 99999.f;
            FieldOffset<int>(obj, "WeaponSounds", "polymorphType") = 1;
            FieldOffset<float>(obj, "WeaponSounds", "polymorphMaxHealth") = 99999.f;
            harpoonBull = OBFUSINT(true);
        }

        if (enemymarker) {
            FieldOffset<bool>(obj, "WeaponSounds", "enemyMarker") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "enemyMarkerWhenShot") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "enemyMarkerWhenAiming") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "enemyMarketChargeTime") = 0;
        }

        if (electric) {
            FieldOffset<bool>(obj, "WeaponSounds", "isElectricShock") = true;
            FieldOffset<float>(obj, "WeaponSounds", "electricShockCoeff") = 99999.f;
            FieldOffset<float>(obj, "WeaponSounds", "electricShockTime") = 99999.f;
        }

        if (gbullets) {
            FieldOffset<bool>(obj, "WeaponSounds", "isGrenadeWeapon") = true;
        }

        if (reflections) {
            FieldOffset<bool>(obj, "WeaponSounds", "isDamageReflection") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "isDamageAbsorption") = false;
            FieldOffset<float>(obj, "WeaponSounds", "damageReflectionValue") = -99999.f;
        }

        if (flamethrower) {
            FieldOffset<bool>(obj, "WeaponSounds", "flamethrower") = true;
        }

        if (blindness) {
            FieldOffset<bool>(obj, "WeaponSounds", "isBlindEffect") = true;
            FieldOffset<float>(obj, "WeaponSounds", "isBlindEffectTime") = 99999.f;
        }

        if (crithit) {
            FieldOffset<float>(obj, "WeaponSounds", "criticalHitCoef") = 9999.f;
            FieldOffset<float>(obj, "WeaponSounds", "criticalHitChance") = 9999.f;
        }

        if (doublejump) {
            FieldOffset<bool>(obj, "WeaponSounds", "isDoubleJump") = true;
        }

        if (coindrop) {
            FieldOffset<bool>(obj, "WeaponSounds", "isCoinDrop") = true;
            FieldOffset<float>(obj, "WeaponSounds", "coinDropChance") = 9999.f;
        }

        if (expbull) {
            FieldOffset<bool>(obj, "WeaponSounds", "bulletExplode") = true;
        }

        if (shotbull) {
            FieldOffset<bool>(obj, "WeaponSounds", "isShotGun") = true;
        }

        if (kniferangesex && !kniferange) {
            FieldOffset<float>(obj, "WeaponSounds", "shootDistance") = 9999.f;
            FieldOffset<float>(obj, "WeaponSounds", "range") = 9999.f;
        }

        if (reflection != 0) {
            FieldOffset<bool>(obj, "WeaponSounds", "railgun") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "railgunStopAtWall") = false;
        }

        if (harpoonBull) {
            FieldOffset<bool>(obj, "WeaponSounds", "harpoon") = true;
            FieldOffset<float>(obj, "WeaponSounds", "harpoonMaxDistance") = 99999.f;
            FieldOffset<float>(obj, "WeaponSounds", "harpoonMinDistance") = 99999.f; // shouldnt this be lower?
        }

        if (jumpdisable) {
            FieldOffset<bool>(obj, "WeaponSounds", "jumpDisabler") = true;
            FieldOffset<float>(obj, "WeaponSounds", "jumpDisableTime") = 99999.f;
        }

        if (speedup) {
            FieldOffset<bool>(obj, "WeaponSounds", "isSlowdown") = true;
            FieldOffset<float>(obj, "WeaponSounds", "slowdownCoeff") = 99999.f;
            FieldOffset<float>(obj, "WeaponSounds", "slowdownTime") = 99999.f;
        }

        if (slowdown) {
            FieldOffset<bool>(obj, "WeaponSounds", "isSlowdown") = true;
            FieldOffset<float>(obj, "WeaponSounds", "slowdownCoeff") = -99999.f;
            FieldOffset<float>(obj, "WeaponSounds", "slowdownTime") = 99999.f;
        }

        if (headmagnify) {
            FieldOffset<bool>(obj, "WeaponSounds", "isHeadMagnifier") = true;
            FieldOffset<float>(obj, "WeaponSounds", "headMagnifierTime") = 99999.f;
        }

        if (reflection != 0) {
            FieldOffset<int>(obj, "WeaponSounds", "countReflectionRay") = reflection;
        }

        /*  if(spleef){
              *(bool*)((uint64_t) obj + 0x424) = OBFUSINT(true);//isSpleef
          }*/

        if (recoilandspread) {
            FieldOffset<float>(obj, "WeaponSounds", "maxKoofZoom") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "upKoofFireZoom") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "downKoofFirstZoom") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "downKoofZoom") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "maxKoof") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "tekKoof") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "upKoofFire") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "downKoofFirst") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "downKoof") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "timerForTekKoofVisual") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "timeForTekKoofVisual") = 0;
            FieldOffset<float>(obj, "WeaponSounds", "recoilCoeffZoom") = 0;
            FieldOffset<il2cppVector2>(obj, "WeaponSounds", "startZone") = il2cppVector2(0, 0);
        }

        if (pnoclip) {
            FieldOffset<bool>(obj, "WeaponSounds", "IsGhost") = true;
        }

        if (god && isInMatch()) {
            FieldOffset<bool>(obj, "WeaponSounds", "isArmorRegeneration") = true;
            FieldOffset<float>(obj, "WeaponSounds", "armorRegenerationPercent") = 10.f;
            FieldOffset<float>(obj, "WeaponSounds", "armorRegenerationTime") = 0.f;
            FieldOffset<bool>(obj, "WeaponSounds", "isDamageHeal") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "isDamageAndArmorHeal") = true;
            FieldOffset<float>(obj, "WeaponSounds", "damageHealMultiplier") = 9999.f;
            FieldOffset<bool>(obj, "WeaponSounds", "healingArea") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "healingHimSelf") = true;
            FieldOffset<bool>(obj, "WeaponSounds", "radiusHealing") = true;
        }

        if (quickscope) {
            FieldOffset<float>(obj, "WeaponSounds", "scopeSpeed") = 9999.f;
        }
    }
    old_WeaponSounds(obj);
}

float (*old_gadgetDuration)(void* obj);
float gadgetDuration(void* obj) {
    if (obj != nullptr && gadgetduration) {
        return 99999.f;
    }
    return old_gadgetDuration(obj);
}

void (*old_FirstPersonControllSharp)(void* obj);
void FirstPersonControllSharp(void* obj) {
    if (obj != nullptr) {
        if (jumpHeight > 0.001f) {
            GetField<float>(obj, 0x4A0) = jumpHeight;
        }
    }
    return old_FirstPersonControllSharp(obj);
}

float (*old_Speed)(void* obj);
float Speed(void* obj) {
    if (obj != nullptr) {
        if(illegalWeaponReplace) {
            GetField<il2cppString*>(obj, 0xC8) = CreateIl2cppString(gaySexWeapons[gaySexIndex]);
            illegalWeaponReplace = OBFUSINT(false);
        }
        if(speed)
            return 1000;
    }
    return old_Speed(obj);
}


float (*old_petSpeed)(void* obj);
float petSpeed(void* obj) {
    if (obj != nullptr && pspeed) {
        return 999999;
    }
    return old_petSpeed(obj);
}

float (*old_petHealth)(void* obj);
float petHealth(void* obj) {
    if (obj != nullptr && pgod) {
        return 9999999;
    }
    return old_petHealth(obj);
}

float (*old_petAttack)(void* obj);
float petAttack(void* obj) {
    if (obj != nullptr && pdamage) {
        return 1000;
    }
    return old_petAttack(obj);
}

void* Player_move_c$$gunCameraTransform(void* instance) {
    void* gunCamera = GetField<void*>(instance, 0x2A8);
    return Component$get_transform(gunCamera);
}

void (*old_PlayerMoveC)(void* obj);
void PlayerMoveC(void* obj) {
    if (obj != nullptr) {

        if (get_isMine(obj) && timeSinceMatch > 5.f && isInMatch()) {
            pg_me.instance = myPlayer; //fuck niggers who use obj instead of instance
            pg_me.playerDamageable = get_PlayerDamageable(obj);
            pg_me.camera = getPlayerCamera(obj);

            void* skinName = GetField<void*>(obj, 0x678);
            if (skinName != nullptr) {
                pg_me.firstPersonControl = GetField<void*>(skinName, 0x1E0);
                if (pg_me.firstPersonControl != nullptr) {
                    pg_me.cameraPivot = GetField<void*>(get_playerCamera(obj), 0x48);
                    pg_me.fpsCameraController = GetField<void*>(pg_me.firstPersonControl, 0x18);
                    pg_me.transform = get_PlayerTransform(obj);

                    if (pg_me.cameraPivot != nullptr) {
                        pg_me.rotation = get_PlayerRot(obj);
                    }
                }
            }

            if(noClipAll) {
                if(tpToNormalPosTimer <= 0) {
                    oldPos = get_PlayerVec(obj);
                }

                if(tpToNormalPosTimer < 5) {
                    tpToNormalPosTimer++;
                    set_position(get_PlayerTransform(obj), il2cppVector3(0.0f/0.0f, 0.0f/0.0f, 0.0f/0.0f));
                }
                else
                {
                    set_position(get_PlayerTransform(obj), oldPos);
                    tpToNormalPosTimer = 0;
                    noClipAll = false;
                }
            }

            if(kniferange && sharedPlayerList != nullptr && delayTime % 50 == 0) {
                sharedPlayerList->foreach([&](void *player, int index) {
                    if (player != nullptr && !get_isMine(player)) {
                        void *playerTransform = get_PlayerTransform(player);
                        void *bodyAimCollider = GetField<void*>(player, 0x158);
                        il2cppVector3 playerVec = get_PlayerVec(player);
                        void* IDamagePlayer = get_IDamage(playerTransform);
                        if (IDamagePlayer != nullptr) {
                            ApplyDamageToTarget(obj, IDamagePlayer, 100.f, bodyAimCollider, playerVec,
                                                CreateIl2cppString("gadget_reflector"), 1, 0);
                        }
                    }
                });
            }

        }

        if (forcegadget && sharedPlayerList != nullptr) {
            sharedPlayerList->foreach([&](void *player, int index) {
                if (player != nullptr && !get_isMine(player)) {
                    for (int i = 0; i <= 0x13; i++) {
                        SetModuleGadgetEffectActive(player, i, true, CreateIl2cppString("gadget_mech"));
                        SetGadgetEffectActive(player, i, true, CreateIl2cppString("gadget_mech"), desiredLevel);
                    }
                }
            });
            forcegadget = false;
        }

        if (aimbot && timeSinceMatch > 5.f && sharedPlayerList != nullptr) {
            void *player = nullptr;
            if (aimbotmode == 0) {
                player = getClosestTarget();
            } else if (aimbotmode == 1) {
                player = getBestTarget();
            }

            if (player != nullptr && pg_me.instance != nullptr && pg_me.camera != nullptr && pg_me.firstPersonControl != nullptr) {
                void *playerDamageable = get_PlayerDamageable(player);
                if (playerDamageable != nullptr) {
                    void *transformMine = Component$get_transform(pg_me.camera);
                    void *transformTarget = Component$get_transform(playerDamageable);
                    il2cppVector3 targetPos;
                    if (headshotMode)
                        targetPos = get_position(transformTarget) + il2cppVector3(0, 0.7, 0);
                    else
                        targetPos = get_position(transformTarget);
                    if (transformTarget != nullptr) {
                        Transform$$LookAt(transformMine, targetPos);
                    }
                }
            }
        }

        if (telekill && obj != nullptr) {
            void* nearestPlayer = nullptr;
            float minDist = MAXFLOAT;

            sharedPlayerList->foreach([&](void* player, int index) {
                if (!get_isMine(player)) {
                    float dist = il2cppVector3::Distance(get_PlayerVec(obj), get_PlayerVec(player));
                    if(dist < minDist) {
                        minDist = dist;
                        nearestPlayer = player;
                    }
                }
            });

            if (nearestPlayer != nullptr && IsEnemyTo(get_PlayerDamageable(nearestPlayer), obj)) {
                set_position(get_PlayerTransform(obj),
                                       get_PlayerVec(nearestPlayer) + il2cppVector3(0, 0, 3));
                Transform$$LookAt(get_PlayerTransform(obj),
                                  get_PlayerVec(nearestPlayer));
            }
        }

        if (get_isMine(obj)) {
            sharedPlayerList = GetStaticField<il2cppList<void**>*>(il2cpp_class_from_name(LibImages.AssemblyCSharp, "", "万下丐业丐丙丕丛与"), "丞丞丒七与上七三丕");
            inGameGUI = GetField<void*>(obj, 0x5A8); // internal InGameGUI 丛与一丝丕丌丘上丟;
            if (isTpingFromButton)
            {
                isTpingFromButton = OBFUSINT(false);
                void* gunCameraTransform = Player_move_c$$gunCameraTransform(obj);
                il2cppVector3 forward = Transform$$forward(gunCameraTransform) * tpDistance;
                set_position(get_PlayerTransform(obj), get_PlayerVec(obj) + forward);
            }

            if (playerScale) {
                void* skinName = GetField<void*>(obj, 0x678);
                if (skinName != nullptr) {
                    void* fpsControl = GetField<void*>(skinName, 0x1E0);
                    if (fpsControl != nullptr) {
                        void *trans = Component$get_transform(fpsControl);
                        set_local_scale(trans, il2cppVector3(myScale, myScale, myScale));
                    }
                }
            }
        } else {
            if (otherPlayerScale) {
                void* skinName = GetField<void*>(obj, 0x678);
                if (skinName != nullptr) {
                    void* fpsControl = GetField<void*>(skinName, 0x1E0);
                    if (fpsControl != nullptr) {
                        void *trans = Component$get_transform(fpsControl);
                        set_local_scale(trans, il2cppVector3(otherScale, otherScale, otherScale));
                    }
                }
            }
        }

        // get_PlayerTransform(obj);
        // get_PlayerVec(obj);

        if (xrayApplied && delayTime % 50 == 0) {
            EnableXray(obj, true);
        }

        if (spawnPrefab) {
            il2cppVector3 location;
            il2cppQuaternion rotation;
            if (spinPrefabs)
                rotation = il2cppQuaternion(generateRandomNumber(-1, 1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1));
            else
                rotation = il2cppQuaternion::Identity();
            if (selectedLocation == 0 && sharedPlayerList != nullptr) {
                void *player = sharedPlayerList->getItems()[rand() % sharedPlayerList->getSize()];
                location = get_PlayerVec(player);
            } else if (selectedLocation == 1) {
                location = il2cppVector3(generateRandomNumber(-25, 25), generateRandomNumber(-25, 25), generateRandomNumber(-25, 25));
            }
            switch (selectedSpawnMode) {
                case 0: {
                    contSpawn = spawnAmount;
                    break;
                }
                case 1: {
                    for (int i = 0; i < spawnAmount; i++)
                        InstantiateNetworkObject(prefabList[selectedPrefab],location, rotation);
                    break;
                }
                case 2: {
                    float xPos = location.X + 13.0f; float yPos = location.Y + 13.0f; float zPos = location.Z + 13.0f;
                    for (int i = 0; i < 25; i++) {
                        InstantiateNetworkObject(prefabList[selectedPrefab],
                                               il2cppVector3(xPos, yPos, zPos), rotation);
                        xPos -= 0.5f; yPos -= 0.5f; zPos -= 0.5f;
                    }
                    xPos = location.X + 13.0f; yPos = location.Y + 13.0f; zPos = location.Z + 13.0f;
                    for (int i = 0; i < 25; i++) {
                        InstantiateNetworkObject(prefabList[selectedPrefab],
                                               il2cppVector3(xPos, yPos, zPos), rotation);
                        xPos += 0.5f; yPos -= 0.5f; zPos -= 0.5f;
                    }
                    xPos = location.X + 13.0f; yPos = location.Y + 13.0f; zPos = location.Z + 13.0f;
                    for (int i = 0; i < 25; i++) {
                        InstantiateNetworkObject(prefabList[selectedPrefab],
                                               il2cppVector3(xPos, yPos, zPos), rotation);
                        xPos -= 0.5f; yPos -= 0.5f; zPos += 0.5f;
                    }
                    xPos = location.X + 13.0f; yPos = location.Y + 13.0f; zPos = location.Z + 13.0f;
                    for (int i = 0; i < 25; i++) {
                        InstantiateNetworkObject(prefabList[selectedPrefab],
                                               il2cppVector3(xPos, yPos, zPos), rotation);
                        xPos += 0.5f; yPos -= 0.5f; zPos += 0.5f;
                    }
                    break;
                }
                case 3: {
                    float xPos = location.X; float yPos = location.Y; float zPos = location.Z - 30.0f;
                    for (int i = 0; i < 10; i++) {
                        yPos += 1.0;
                        zPos = 0 - 25;
                        for (int j = 0; j < 10; j++) {
                            zPos += 1.0;
                            InstantiateNetworkObject(prefabList[selectedPrefab],
                                                   il2cppVector3(xPos, yPos, zPos), rotation);
                        }
                    }
                    break;
                }
                case 4: {
                    float xPos = location.X; float yPos = location.Y; float zPos = location.Z;
                    for (int i = 0; i < 25; i++) {
                        InstantiateNetworkObject(prefabList[selectedPrefab],
                                               il2cppVector3(xPos, yPos, zPos), rotation);
                        xPos += 0.5f; yPos += 0.5f; zPos += 0.5f;
                    }
                    xPos = location.X; yPos = location.Y; zPos = location.Z;
                    for (int i = 0; i < 25; i++) {
                        InstantiateNetworkObject(prefabList[selectedPrefab],
                                               il2cppVector3(xPos, yPos, zPos), rotation);
                        xPos -= 0.5f; yPos += 0.5f; zPos -= 0.5f;
                    }
                    xPos = location.X; yPos = location.Y; zPos = location.Z;
                    for (int i = 0; i < 25; i++) {
                        InstantiateNetworkObject(prefabList[selectedPrefab],
                                               il2cppVector3(xPos, yPos, zPos), rotation);
                        xPos += 0.5f; yPos += 0.5f; zPos -= 0.5f;
                    }
                    xPos = location.X; yPos = location.Y; zPos = location.Z;
                    for (int i = 0; i < 25; i++) {
                        InstantiateNetworkObject(prefabList[selectedPrefab],
                                               il2cppVector3(xPos, yPos, zPos), rotation);
                        xPos -= 0.5f; yPos += 0.5f; zPos += 0.5f;
                    }
                    break;
                }
                case 5: {
                    const int boundryX = 10;
                    const int boundryY = 10;
                    const int boundryZ = 10;
                    const float sphereRadius = 5.0f;
                    const float sphereCenterX = boundryX / 2.0f;
                    const float sphereCenterY = boundryY / 2.0f;
                    const float sphereCenterZ = boundryZ / 2.0f;
                    for (int x = static_cast<int>(location.X); x < boundryX; x++) {
                        for (int y = static_cast<int>(location.Y); y < boundryY; y++) {
                            for (int z = static_cast<int>(location.Z); z < boundryZ; z++) {
                                float distance = sqrt((x - sphereCenterX) * (x - sphereCenterX) +
                                                      (y - sphereCenterY) * (y - sphereCenterY) +
                                                      (z - sphereCenterZ) * (z - sphereCenterZ));

                                if (abs(distance - sphereRadius) < 0.5f) {
                                    InstantiateNetworkObject(prefabList[selectedPrefab], il2cppVector3(x, y, z), rotation);
                                }
                            }
                        }
                    }
                    break;
                }
            }
            spawnPrefab = OBFUSINT(false);
        }

        if(contSpawn != 0) {
            il2cppVector3 location;
            il2cppQuaternion rotation;
            if (spinPrefabs)
                rotation = il2cppQuaternion(generateRandomNumber(-1, 1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1));
            else
                rotation = il2cppQuaternion::Identity();
            if (selectedLocation == 0 && sharedPlayerList != nullptr) {
                void *player = sharedPlayerList->getItems()[rand() % sharedPlayerList->getSize()];
                location = get_PlayerVec(player);
            } else if (selectedLocation == 1) {
                location = il2cppVector3(generateRandomNumber(-25, 25), generateRandomNumber(-25, 25), generateRandomNumber(-25, 25));
            }

            InstantiateNetworkObject(prefabList[selectedPrefab], location, rotation);

            contSpawn--;
        }

        if(spawnPrefabLoop && delayTime % delayCont == 0) {
            il2cppVector3 location;
            il2cppQuaternion rotation;
            void *player;
            if (spinPrefabs)
                rotation = il2cppQuaternion(generateRandomNumber(-1, 1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1));
            else
                rotation = il2cppQuaternion::Identity();
            if (selectedLocation == 0 && sharedPlayerList != nullptr) {
                player = sharedPlayerList->getItems()[rand() % sharedPlayerList->getSize()];
                location = get_PlayerVec(player);
            } else if (selectedLocation == 1) {
                location = il2cppVector3(generateRandomNumber(-25, 25), generateRandomNumber(-25, 25), generateRandomNumber(-25, 25));
            }
            if(player != nullptr || selectedLocation == 1) {
                InstantiateNetworkObject(prefabList[selectedPrefab], location, rotation);
            }
        }

        if(spawnPrefabRandom && delayTime % delayCont == 0) {
            il2cppVector3 location;
            il2cppQuaternion rotation;
            void *player;
            if (spinPrefabs)
                rotation = il2cppQuaternion(generateRandomNumber(-1, 1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1));
            else
                rotation = il2cppQuaternion::Identity();
            if (selectedLocation == 0) {
                player = sharedPlayerList->getItems()[rand() % sharedPlayerList->getSize()];
                location = get_PlayerVec(player);
            } else if (selectedLocation == 1) {
                location = il2cppVector3(generateRandomNumber(-25, 25), generateRandomNumber(-25, 25), generateRandomNumber(-25, 25));
            }
            int objToSpawn = rand() % IM_ARRAYSIZE(randPrefabList);
            if(player != nullptr || selectedLocation == 1) {
                InstantiateNetworkObject(randPrefabList[objToSpawn], location, rotation);
            }
        }

        if(spamJoin && delayTime % delayCont == 0) {
            void *player = sharedPlayerList->getItems()[rand() % sharedPlayerList->getSize()];
            InstantiateNetworkObject(OBFUSTR("bots/BotInstance"), il2cppVector3(0, 0, 0), il2cppQuaternion().Identity());
        }

        if(spamVehicle && delayTime % delayCont == 0) {
            il2cppVector3 location;
            il2cppQuaternion rotation;
            void *player;
            if (spinPrefabs)
                rotation = il2cppQuaternion(generateRandomNumber(-1, 1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1), generateRandomNumber(-1, -1));
            else
                rotation = il2cppQuaternion::Identity();
            if (selectedLocation == 0) {
                player = sharedPlayerList->getItems()[rand() % sharedPlayerList->getSize()];
                location = get_PlayerVec(player);
            } else if (selectedLocation == 1) {
                location = il2cppVector3(generateRandomNumber(-25, 25), generateRandomNumber(-25, 25), generateRandomNumber(-25, 25));
            }
            if(player != nullptr || selectedLocation == 1) {
                InstantiateNetworkObject(OBFUSTR("vehiclebattleroyale/fps_all_terrain_vehicle/FreePlayAllTerrain"), location, rotation);
            }
        }

        if (spamchat && get_isMine(obj) && delayTime % delayChat == 0) {
            int rand = generateRandomNumber(0, sharedPlayerList->getSize() - 1);
            void *player = sharedPlayerList->getItems()[rand];
            SendChat(player, CreateIl2cppString(spamMessage.c_str()), false, CreateIl2cppString("0"));
        }

        if (tpPlayer && sharedPlayerList != nullptr) {
            int cont = 0;
            for (PhotonPlayer photonPlayer : playerListDyn) {
                if (selectedPlayer == cont && sharedPlayerList != nullptr) {
                    sharedPlayerList->foreach([&](void* player, int index) {
                        void* photonView = PhotonView$Get(player);
                        if (!get_isMine(player) && photonPlayer.id == GetField<int>(photonView, 0x20)) {
                            if (player != nullptr && pg_me.instance != nullptr)
                                set_position(get_PlayerTransform(pg_me.instance), get_PlayerVec(player));
                        }
                    });
                }
                cont++;
            }
            tpPlayer = OBFUSINT(false);
        }

        if (tpPlayer2Me && sharedPlayerList != nullptr) {
            int cont = 0;
            for (PhotonPlayer photonPlayer : playerListDyn) {
                if (selectedPlayer == cont && sharedPlayerList != nullptr) {
                    sharedPlayerList->foreach([&](void* player, int index) {
                        void* photonView = PhotonView$Get(player);
                        if (!get_isMine(player) && photonPlayer.id == GetField<int>(photonView, 0x20)) {
                            if (player != nullptr && pg_me.instance != nullptr)
                                set_position(get_PlayerTransform(player), get_PlayerVec(pg_me.instance) + il2cppVector3(2, 0, 0));
                        }
                    });
                }
                cont++;
            }
        }

        if (tpPlayerAll && sharedPlayerList != nullptr) {
            sharedPlayerList->foreach([&](void* player, int index) {
                void* photonView = PhotonView$Get(player);
                if (!get_isMine(player)) {
                    if (player != nullptr && pg_me.instance != nullptr)
                        set_position(get_PlayerTransform(player), get_PlayerVec(pg_me.instance) + il2cppVector3(2, 0, 0));
                }
            });
        }

        if (xray) {
            SetXrayShader(obj, true);
            GetField<bool>(obj, 0x738) = OBFUSINT(true); // search ZombiManager then its above
        }

        if (ninjaJump) {
            EnableJetpack(obj, true);//search for jetpack in player_move_C
            ninjaJump = OBFUSINT(false);
        }

        if (gadgetsEnabled) {
            GetField<bool>(obj, 0xDDC) = OBFUSINT(false);//search for Action, the field should be under the gadget class
        }

        if (freezeYPos) {
            void *transform = Component$get_transform(obj);
            if (transform != nullptr) {
                il2cppVector3 pos = get_position(transform);
                pos.Y = targetYPos;

                set_position(transform, pos);
            }
        }
    }
    old_PlayerMoveC(obj);
}

int (*old_getItemRarity)(void *obj);
int getItemRarity(void *obj) {
    if (obj != nullptr && changeRarity) {
        /* if (selectedCur != 6 && changeRarity)
            return selectedCur;
        if (changeRarity && selectedCur == 6)
            return -1; */
        return selectedRarity;
    }
    return old_getItemRarity(obj);
}

bool deUncapFps, messageBomb;

bool logsEnabled = OBFUSINT(false);

// non auth pixeltime
void (*old_PixelTime2)(void* obj);
void PixelTime2(void* obj) {
    if (obj != nullptr) {

        if (openPanel) {
            OpenURL(CreateIl2cppString(OBFUSTR("https://modfs.dev/panel")));
            openPanel = OBFUSINT(false);
        }

        if (isDiscordPressed) {
            OpenURL(CreateIl2cppString(OBFUSTR("https://discord.gg/GuGQ3xmd3r")));
            isDiscordPressed = OBFUSINT(false);
        }
        if (buyMenu) {
            OpenURL(CreateIl2cppString(OBFUSTR("https://modfs.dev")));
            buyMenu = OBFUSINT(false);
        }
    }
    old_PixelTime2(obj);
}

int upd_timer = 0;

// auth enabled pixeltime
void (*old_PixelTime)(void* obj);
void PixelTime(void* obj) {
    if (obj != nullptr) {
        ws::StringToInt(ws::ClanIDint, ws::ClanIDstr);
        ws::StringToInt(ws::killslider, ws::killsliderStr);
        ws::StringToInt(ws::deathslider, ws::deathsliderStr);
        ws::StringToInt(ws::headshotslider, ws::headshotsliderStr);
        ws::StringToInt(ws::killstreakslider, ws::killstreaksliderStr);
        ws::StringToInt(ws::winstreakslider, ws::winstreaksliderStr);
        ws::StringToInt(ws::MonthlyCountSlider, ws::MonthlyCountSliderStr);
        ws::StringToInt(ws::winandmatchamount, ws::winandmatchamountStr);
        ws::StringToInt(ws::PlayerIDint, ws::PlayerIDstr);
        ws::StringToInt(ws::WarIDint, ws::WarIDstr);
        ws::StringToInt(ws::scoreaddthropies, ws::scoreaddthropiesstr);
        ws::StringToInt(ws::currentscore, ws::currentscorestr);
	    
        if (openPanel) {
            OpenURL(CreateIl2cppString(OBFUSTR("https://modfs.dev/panel")));
            openPanel = OBFUSINT(false);
        }

        if (banAcc) {
            antiban = false;
            banAccount(CreateIl2cppString("Ban from dev console haha !!!1"));
            banAcc = false;
        }

        if (createAcc) {
            Storager$$setInt(CreateIl2cppString("skip-account-blocked-window-and-unban-automatically"), 1, false, false);
            createAcc = false;
        }

        if (setlevel65) {
            setlevel65 = OBFUSINT(false);
            callWebsocket(ws::SetLevel(ws::desiredLevel));
        }

        if (addbooosters) {
            addbooosters = OBFUSINT(false);
            callWebsocket(ws::AddBoosters(ws::boosteramount, ws::boostertype));
        }

        if (hackclanvalor_) {
            hackclanvalor_ = OBFUSINT(false);
            for (int i = 0; i < 150; i++) {
                callWebsocket(ws::HackClanValor());
            }
        }

        if (hackrankexperience_) {
            hackrankexperience_ = OBFUSINT(false);
            callWebsocket(ws::HackClanRankPoints(ws::rankexpsliderhack));
            callWebsocket(ws::HackClanRankPoints2(ws::rankexpsliderhack));
        }
        
        if (AddThropies_) {
            AddThropies_ = OBFUSINT(false);
            callWebsocket(ws::AddThropies(ws::scoreaddthropies, ws::currentscore));
            callWebsocket(ws::AddThropies2(ws::scoreaddthropies,ws::currentscore));
            callWebsocket(ws::AddThropies3(ws::scoreaddthropies, ws::currentscore));
            callWebsocket(ws::AddThropies4(ws::scoreaddthropies));
            callWebsocket(ws::AddThropies5(ws::scoreaddthropies));
        }

        delayTime++;

        if (addwearss) {
            if (fetchSlot(13)) {
                callWebsocket(ws::AddWear(0, progressSlots[13].data, true, ws::playerLevel));
                addwearss = false;
                progressSlots[13].slotUpdate.state = SlotState::READY;
            }
        }

        if (AddBattlePassExp_) {
            AddBattlePassExp_ = OBFUSINT(false);
            callWebsocket(ws::AddBattlePassExp(ws::passexp));
        }

        if (AddWinsandmatches_) {
            AddWinsandmatches_ = OBFUSINT(false);
            callWebsocket(ws::AddWinsandmatches(0, ws::winandmatchamount));
        }
        
        if (AddKeys_) {
            AddKeys_ = OBFUSINT(false);
            callWebsocket(ws::AddKeysWS(ws::keysamount));
        }
        
        if (CompleteEliteChallanges_) {
            CompleteEliteChallanges_ = OBFUSINT(false);
            callWebsocket(ws::CompleteEliteChallanges());
        }
        
        if (AddWearParts_) {
            AddWearParts_ = OBFUSINT(false);
            callWebsocket(ws::AddParts(0, 250, 8));
            //callWebsocket(ws::AddParts(0, 250, 2));
            callWebsocket(ws::AddParts(0, 250, 23));
        }

        if (AddWeaponParts_) {
            AddWeaponParts_ = OBFUSINT(false);
            callWebsocket(ws::AddParts(0, 250, 1));
        }

        if (AddRoyaleParts_) {
            AddRoyaleParts_ = OBFUSINT(false);
            callWebsocket(ws::AddParts(0, 100, 5));
            callWebsocket(ws::AddParts(0, 100, 19));
        }

        if (AddBattlePassPremium_) {
            AddBattlePassPremium_ = OBFUSINT(false);
            callWebsocket(ws::AddBattlePassPremium());
        }

        if (AddGemBoosters_) {
            AddGemBoosters_ = OBFUSINT(false);
            callWebsocket(ws::AddGemBoosters(ws::boosteramount));
        }

        if (UpdateStats_) {
            UpdateStats_ = OBFUSINT(false);
            callWebsocket(ws::UpdatePlayerStats(ws::killslider, ws::deathslider, ws::headshotslider, ws::killstreakslider, ws::winstreakslider));
        }

        if (addmoduless) {
            addmoduless = OBFUSINT(false);
            callWebsocket(ws::AddModules(0));
        }

        if (addmodulelevel) {
            if (fetchSlot(37)) {
                LOGWS("Adding modules %s", progressSlots[37].data.dump().c_str());
                callWebsocket(ws::UpgradeModules(ws::moduleLevel, progressSlots[37].data, capModules));
                progressSlots[37].slotUpdate.state = SlotState::READY;
                addmodulelevel = false;
            }
        }

        if (addWeapons) {
            callWebsocket(ws::AddWeaponV17(wepValFirst, wepValLast, ws::playerLevel, selectedWepRarity));
            addWeapons = false;
        }

        if (addweaponss) {
            addweaponss = OBFUSINT(false);
            callWebsocket(ws::AddWeaponV17(1, 2000, ws::playerLevel, selectedWepRarity));
        }

        if (addallweaponskins) {
            addallweaponskins = OBFUSINT(false);
            callWebsocket(ws::AddWeaponSkins(0));
        }

        if (SetClanRank_) {
            SetClanRank_ = OBFUSINT(false);
            callWebsocket(ws::SetClanRank(ws::clanrankk));
        }

        if (AddChestWS) {
            AddChestWS = OBFUSINT(false);
            callWebsocket(ws::AddChests(ws::chestamount, ws::chesttype));
        }

        if (SetClanLevelFort_) {
            SetClanLevelFort_ = OBFUSINT(false);
            callWebsocket(ws::SetClanLevel(ws::clanlevell, ws::ClanIDint));
        }

        if (SetClanLevelTank_) {
            SetClanLevelTank_ = OBFUSINT(false);
            callWebsocket(ws::SetClanLevelTank(ws::clanlevell, ws::ClanIDint));
        }

        if (BuffClan_) {
            BuffClan_ = OBFUSINT(false);
            callWebsocket(ws::BuffClan(ws::lenght_in_seconds));
        }

        if (addallgraffiti) {
            addallgraffiti = OBFUSINT(false);
            callWebsocket(ws::AddGraffiti(0));
        }

        if (AddClan_) {
            AddClan_ = OBFUSINT(false);
            callWebsocket(ws::AddClan(ws::ClanIDstr, 0, ws::clanitemamount));
        }

        for (GameMode& mode : gameModes) {
            if (mode.winFlag) {
                mode.winFlag = OBFUSINT(false);
                massRequest = true;
                for (int i = 0; i < ws::MonthlyCountSlider; i++) {
                    if (mode.isRaid)
                        callWebsocket(ws::AddMonthlyStatsRaid(mode.modeId, mode.raidDifficulty));
                    else if (mode.isTournament)
                        callWebsocket(ws::AddMonthlyStatsTournament(mode.modeId));
                    else
                        callWebsocket(ws::AddMonthlyStatsNormal(mode.modeId));
                }
                massRequest = false;
            }
        }

        if (completeTutorial) {
            // keep in mind this also sets as analytics "Dev call(1) of CompleteTutorial"
            fillTutorial1(tutorialInstance());
            fillTutorial2();
            LoadLevel(CreateIl2cppString(OBFUSTR("Menu_Custom")));
            completeTutorial = false;
        }

        if (!isInMatch() && pg_me.instance != nullptr) {
            memset(&pg_me, 0, sizeof(pg_me));
        }

        if (!isInMatch()) {
            sharedPlayerList = nullptr;
            photonViewList = nullptr;
        }

        if (!isInMatch()) {
            timeSinceMatch = 0.f;
        } else {
            timeSinceMatch += 0.1f;
        }

        if (GetActiveScene() != 0)
            scene = GetNameInternal(GetActiveScene())->getString();

		if (oldScene != scene)
		{
			oldScene = scene;
			if (isSceneExplorerOpen) updateObjList();
		}

		if (isSceneExplorerOpen)
		{
			/*upd_timer++;
			if (upd_timer >= 30)
			{
				*/upd_timer = 0;
				if (!objListDyn.empty() && objListDyn[selectedGObj].obj != nullptr)
				{
					qCurObjActive = GameObject$$GetActive(objListDyn[selectedGObj].obj);
				}
				/*updateObjList();
			}*/
		}

        if (enableConsole) {
            setInt(CreateIl2cppString(OBFUSTR("Dev.DebugConsoleEnabled")), 1);
            setEnabledConsole(true);
            enableConsole = OBFUSINT(false);
        }

        if (enableUIInput) {
            enableUIInput = OBFUSINT(false);
            enableUIInputs();
        }

		if (qUpdateObjList)
		{
			qUpdateObjList = OBFUSINT(false);
			updateObjList();
		}

		if (qCloneObj)
		{
			qCloneObj = OBFUSINT(false);
			void* qGObj = objListDyn[selectedGObj].obj;
			void* qTransform = Component$get_transform(qGObj);
			GameObject$$Instantiate(qGObj, get_position(qTransform), get_rotation(qTransform));
			qUpdateObjList = OBFUSINT(true);
		}

        if (sendWebsocket) {
            sendWebsocket = OBFUSINT(false);
            callWebsocket(ws::CreateGift(306207807, std::stoi(getAuthID()->getString()), 26015, 180, "1"));
        }

        if (addRoyale) {
            if (fetchSlot(11)) {
                std::string currentSlot = progressSlots[11].data.dump();
                callWebsocket(ws::AddRoyale(progressSlots[11].data));
                addRoyale = false;
                progressSlots[11].slotUpdate.state = SlotState::READY;
            }
        }

        if (testgift) {
            testgift = false;
            callWebsocket(ws::SendGift(306207807, "1"));
        }

        if (logprogresstofile) {
            logprogresstofile = OBFUSINT(false);
            std::string str = SerializeProgressSlots(progressSlots);
            std::ofstream outt("/storage/emulated/0/Android/data/com.pixel.gun3d/progress.txt");
            outt << str;
            outt.close();
            LOGWS("Progress saved to /storage/emulated/0/Android/data/com.pixel.gun3d/progress.txt");
        }

        if (sendReload) {
            sendReload = OBFUSINT(false);
            sendCommand(WSMInstance, CreateIl2cppString(OBFUSTR("update_progress")));
        }

        static int readDelay = 0;

        if(ws::console_isConnected && readDelay % 10 == 0) {

            std::string data = ws::console_read();

            if(!data.empty() && WSMInstance != nullptr) {
                try {
                    json crayz = json::parse(data);
                    ws::console_send("Client has received the queue.");
                    callWebsocket(crayz);
                } catch (nlohmann::json::parse_error& e) {
                    ws::console_send("Proplam from the client: parsing error.");
                }
            }
        }

        readDelay++;

        if (rmColliders) {
            rmColliders = OBFUSINT(false);
            removeColliders();
        }

        if (yesCollider) {
            yesCollider = OBFUSINT(false);
            enableColliders();
        }

        if (oldIsGuiVisible != isGuiVisible) {
            oldIsGuiVisible = isGuiVisible;
            if (inGameGUI != nullptr) {
                InGameGUI$$SetInterfaceVisible(inGameGUI, isGuiVisible, false);
            }
        }

        if (deUncapFps && getTargetFrameRate() != 60)
            targetFrameRate(60);
        else if (getTargetFrameRate() != 999)
            targetFrameRate(999);

        if (showInfo) {
            LOGW(OBFUSTR("AuthSecret: %s"), getAuthSecret(AuthInstance())->getChars());
            LOGW(OBFUSTR("AuthID: %s"), getAuthID()->getChars());
            LOGW(OBFUSTR("AuthInfo: %s"), getAuthInfo(AuthInstance())->getChars());
            LOGW(OBFUSTR("AuthURL: %s"), getAuthURL()->getChars());
            authSecret = getAuthSecret(AuthInstance())->getString();
            authID = getAuthID()->getString();

            std::string folderPath = "/storage/emulated/0/Android/data/com.pixel.gun3d/dumps/";
            mkdir(folderPath.c_str(), 0777);

            std::ofstream outputFile(folderPath + authID + ".txt");
            outputFile << authSecret << std::endl;
            outputFile << authID << std::endl; // just in case
            outputFile << std::endl;
            outputFile.close();
            showInfo = OBFUSINT(false);
        }
        if (loadAcc) {
            setAuthID(CreateIl2cppString(idlog.c_str()));
            setAuthInfo(AuthInstance(), CreateIl2cppString(idlog.c_str()));
            setAuthSecret(AuthInstance(), CreateIl2cppString(secretlog.c_str()));

            loadMenu = true;
            loadAcc = false;
        }
        if (loadMenu) {
            LoadLevel(CreateIl2cppString(OBFUSTR("Menu_Custom")));
            loadMenu = OBFUSINT(false);
        }

        // TODO: replace with wsd functions
        if (addchest1) {
            addchestp(webInstance(), 1, 0, chestslider, true);
            addchest1 = OBFUSINT(false);
        }
        if (addchest2) {
            addchestp(webInstance(), 2, 0, chestslider, true);
            addchest2 = OBFUSINT(false);
        }
        if (addchest3) {
            addchestp(webInstance(), 3, 0, chestslider, true);
            addchest3 = OBFUSINT(false);
        }
        if(emperorrank) {
            addclanlevel(webInstance(), 11, 130000);
            emperorrank = OBFUSINT(false);
        }
        if(generalrank) {
            addclanlevel(webInstance(), 10, 97500);
            generalrank = OBFUSINT(false);
        }
        if(colonelrank) {
            addclanlevel(webInstance(), 9, 72500);
            colonelrank = OBFUSINT(false);
        }
        if(ltcolonelrank) {
            addclanlevel(webInstance(), 8, 52500);
            ltcolonelrank = OBFUSINT(false);
        }
        if(majorrank) {
            addclanlevel(webInstance(), 7, 37500);
            majorrank = OBFUSINT(false);
        }
        if(captainrank) {
            addclanlevel(webInstance(), 6, 25000);
            captainrank = OBFUSINT(false);
        }
        if(lieutenantrank) {
            addclanlevel(webInstance(), 5, 13700);
            lieutenantrank = OBFUSINT(false);
        }
        if(warriorrank) {
            addclanlevel(webInstance(), 4, 5750);
            warriorrank = OBFUSINT(false);
        }
        if(fighterrank) {
            addclanlevel(webInstance(), 3, 950);
            fighterrank = OBFUSINT(false);
        }
        if(recruitrank) {
            addclanlevel(webInstance(), 2, 50);
            recruitrank = OBFUSINT(false);
        }
        if(newbierank) {
            addclanlevel(webInstance(), 1, 0);
            newbierank = OBFUSINT(false);
        }
        if (addAllGadgets) {
            if (fetchSlot(16)) {
                LOGWS("Gadget data: %s", progressSlots[16].data.dump().c_str());
                callWebsocket(ws::AddGadget(0, ws::playerLevel, progressSlots[16].data));
                progressSlots[16].slotUpdate.state = SlotState::READY;
                addAllGadgets = false;
            }
        }

        if (addAllPets) {
            if (fetchSlot(53)) {
                void* petsDict = get_petsList();
                il2cppString* petsJson = JsonConvert$$SerializeObject(petsDict);
                json pets = json::parse(petsJson->getString());

                std::vector<int> petsList = {};
                for (auto& pet : pets) {
                    petsList.push_back(pet["Index"]);
                }
                callWebsocket(ws::AddPet(0, progressSlots[53].data, petsList));
                progressSlots[53].slotUpdate.state = SlotState::READY;
                addAllPets = false;
            }
        }
        if (maxAccountws) {
            bool wearFetched = fetchSlot(static_cast<int>(SlotTypes::Wear));
            bool gadgetsFetched = fetchSlot(static_cast<int>(SlotTypes::Gadgets));
            bool royaleFetched = fetchSlot(static_cast<int>(SlotTypes::BattleRoyaleIds));
            bool petsFetched = fetchSlot(static_cast<int>(SlotTypes::Gadgets));

            if (wearFetched && gadgetsFetched && royaleFetched && petsFetched) {
                maxAccountws = OBFUSINT(false);

                std::vector<int> petList = getPetList();
                callWebsocket(ws::MaxAccount(
                    progressSlots[13].data, progressSlots[16].data, progressSlots[11].data, 
                    progressSlots[53].data, petList));

                progressSlots[static_cast<int>(SlotTypes::Wear)].slotUpdate.state = SlotState::READY;
                progressSlots[static_cast<int>(SlotTypes::Gadgets)].slotUpdate.state = SlotState::READY;
                progressSlots[static_cast<int>(SlotTypes::BattleRoyaleIds)].slotUpdate.state = SlotState::READY;
                progressSlots[static_cast<int>(SlotTypes::Pets)].slotUpdate.state = SlotState::READY;
            }
        }

        if (isAddCurPressed) {
            //setSomething(webInstance(), CreateIl2cppString(curList[selectedCur]), amountws, 138, true, false);
            // addCurrency(webInstance(), CreateIl2cppString(curList[selectedCur]), amountws, 1, false, false, offerwallParams);
            callWebsocket(ws::AddCurrency(amountws, curList[selectedCur], analyticsCauses[selectedCause]));
            isAddCurPressed = OBFUSINT(false);
        }

        if (loopAddCur) {
            massRequest = true;
            callWebsocket(ws::AddCurrency(amountws, curList[selectedCur], analyticsCauses[selectedCause]));
            hasUpdated = false;
        } else if (!hasUpdated && massRequest) {
            massRequest = false;
            hasUpdated = true;
            callWebsocket(ws::AddCurrency(amountws, curList[selectedCur], analyticsCauses[selectedCause]));
        }

        auto photonplayers = PhotonNetwork_playerListothers();

        if (photonplayers->getLength() != playerListDyn.size() || shouldUpdateList) {
            playerList();
            shouldUpdateList = OBFUSINT(false);
        }

        if(useShovel)
        {
            il2cppList<void**>* ItemRecordList = GetItemRecordList();

            for(int i = 0; i < ItemRecordList->getSize(); ++i) {
                void *ItemRecord = ItemRecordList->getItems()[i];
                GetField<bool>(ItemRecord, 0x30) = OBFUSINT(false);
                GetField<bool>(ItemRecord, 0x6A) = OBFUSINT(false);
            }

            useShovel = OBFUSINT(false);
        }

        if(logItemRecord) {
            logItemRecord = OBFUSINT(false);
            il2cppList<void**>* ItemRecordList = GetItemRecordList();
            std::string str = JsonConvert$$SerializeObject(ItemRecordList)->getString();

            std::ofstream out("/storage/emulated/0/Android/data/com.pixel.gun3d/ItemRecordList.txt");
            out << str;
            out.close();
        }
    }
    old_PixelTime(obj);
}

void (*old_SendPlayerEffect)(void *ths, void *player, il2cppString *source, int effectIndex, float duration, int senderPixelID);
void SendPlayerEffect(void *ths, void *player, il2cppString *source, int effectIndex, float duration, int senderPixelID) {
    if (ths != nullptr && allEffects && isInMatch() && timeSinceMatch > 5.f) {
        for (int i = 0; i < 67; ++i) {
            if (i != 9 && !get_isMine(ths)) {
                old_SendPlayerEffect(ths, player, source, i, 99999999999.0f, senderPixelID);
            }

        }
        return;
    }
    old_SendPlayerEffect(ths, player, source, effectIndex, duration, senderPixelID);
}


void* (*old_Rocket)(void *ths, void *RocketSettings);
void* Rocket(void *ths, void *RocketSettings) {
    if (ths != nullptr) {

        // Checking the rocket is mine
        if (GetField<bool>(ths, 0x138)) {
            if (ricochet) {
                GetField<bool>(RocketSettings, 0x158) = OBFUSINT(true);
                GetField<int>(RocketSettings, 0x15C) = INT_MAX;
            }

            if (spoofkillfeed) {
                GetField<int>(ths, 0x50) = 5; //typeKilsIconChat //sets kill cause to flag
            }

            if (longLifetime) {
                GetField<float>(RocketSettings, 0x54) = 999999999999.0f;
            }

            if (dontDoSelfDmg) {
                GetField<bool>(ths, 0x7E) = OBFUSINT(true);
            }

            if (gravity) {
                GetField<bool>(RocketSettings, 0x78) = OBFUSINT(true);
            }

            if (nuke) {
                GetField<il2cppString*>(ths, 0x68) = CreateIl2cppString(OBFUSTR("A-bomb_mini"));
            }

            switch (rocketMode) {
                case 1: // Homing
                    GetField<int>(RocketSettings, 0x48) = 10;
                    GetField<float>(RocketSettings, 0xCC) = 15.0f;
                    GetField<float>(RocketSettings, 0xD0) = 999999999999.0f;
                    GetField<float>(RocketSettings, 0x190) = 999999999999.0f;
                    break;

                case 2: // Follow Crosshair
                    GetField<int>(RocketSettings, 0x48) = 4;
                    GetField<float>(RocketSettings, 0xCC) = 15.0f;
                    break;
            }
        }
    }

    return old_Rocket(ths, RocketSettings);
}

void* (*old_CreateRocket)(void *weaponSounds, il2cppVector3 pos, il2cppQuaternion rot, float chargePower, int smoke, int whateverthisis);
void* CreateRocket(void *weaponSounds, il2cppVector3 pos, il2cppQuaternion rot, float chargePower, int smoke, int whateverthisis) {
    if (rocketTower) {
        for (float i = 0; i < 15; ++i) {
            il2cppVector3 moddedPos = pos + il2cppVector3(0, i, 0);
            old_CreateRocket(weaponSounds, moddedPos, rot, chargePower, smoke, whateverthisis);
        }
    }
    if (droneStrike) {
        for (float y = 0; y < 7; y++) {
            for (float xp = -3; xp <= 3; xp++) {
                for (float z = -3; z <= 3; z++) {
                    il2cppVector3 moddedPos = pos + il2cppVector3(xp*5, y*2, z*5);
                    old_CreateRocket(weaponSounds, moddedPos, rot, chargePower, smoke, whateverthisis);
                }
            }
        }
    }
    return old_CreateRocket(weaponSounds, pos, rot, chargePower, smoke, whateverthisis);
}

void (*old_SendChatHOOK)(void* instance, il2cppString* text, bool isClan, il2cppString* logoid);
void SendChatHOOK(void* instance, il2cppString* text, bool isClan, il2cppString* logoid) {
    // may god forgive me, for i have sinned

    if (strlen(text->getChars()) <= 1) {
        old_SendChatHOOK(instance, text, isClan, logoid);
        return;
    }

    if (rainbowColor) {
        std::string message = generateRandomHexCode() + text->getString();
        text = CreateIl2cppString(message.c_str());
    }

    LOGW("SendChat text: %s", text->getChars());
    LOGW("SendChat isClan: %d", isClan);
    LOGW("SendChat logoid: %s", logoid->getChars());

    std::stringstream stream(text->getString());
    std::string segment;
    std::vector<std::string> args;

    while(std::getline(stream, segment, ' ')) {
        args.push_back(segment);
    }

    // TELEPORT COMMAND
    // ALIAS IS !TP
    if (args[0] == "!tp" || args[0] == "!teleport") {

        if (args[1] == "random") {
            void *player = sharedPlayerList->getItems()[rand() % sharedPlayerList->getSize()];

            if(player != nullptr)
                set_position(get_PlayerTransform(instance), get_PlayerVec(player));
        }
        else if(args[1] == "nearest") {

            void* nearestPlayer = nullptr;
            float minDist = MAXFLOAT;

            sharedPlayerList->foreach([&](void* player, int index) {
                if (!get_isMine(player)) {
                    float dist = il2cppVector3::Distance(get_PlayerVec(instance), get_PlayerVec(player));
                    if(dist < minDist) {
                        minDist = dist;
                        nearestPlayer = player;
                    }
                }
            });

            if(nearestPlayer != nullptr)
                set_position(get_PlayerTransform(instance), get_PlayerVec(nearestPlayer));
        }
        else {
            if (args.size() == 1) {
                old_SendChatHOOK(instance, CreateIl2cppString(OBFUSTR("Incorrect syntax!")), isClan, logoid);
                old_SendChatHOOK(instance, CreateIl2cppString(OBFUSTR("Correct syntax: !tp [steps]")), isClan, logoid);
                return;
            } else {
                float stepsFloat = stof(args[1]);
                void* gunCameraTransform = Player_move_c$$gunCameraTransform(instance);
                il2cppVector3 forward = Transform$$forward(gunCameraTransform) * stepsFloat;
                set_position(get_PlayerTransform(instance), get_PlayerVec(instance) + forward);
                return;
            }
        }

        return;
    }

    // CLIENTSIDED INSTANTIATE
    // USEFUL FOR FUCKY SHIT I DONT KNOW LMFAO
    if(args[0] == "!instantiate") {
        //il2cppString *path = string$$Substring2(text, CreateIl2cppString(OBFUSTR("!instantiate "))->getLength());
        instantiateClientside(instance, text);
        return;
    }

    // HELP COMMAND
    if (args[0] == "!help") {
        AddMessage(instance, CreateIl2cppString(OBFUSTR("!help - Shows every command")), CreateIl2cppString(OBFUSTR("")));
        AddMessage(instance, CreateIl2cppString(OBFUSTR("!tp/!teleport [steps] - Teleports you forward")), CreateIl2cppString(OBFUSTR("")));
        AddMessage(instance, CreateIl2cppString(OBFUSTR("!msg [message] - Sets the spam chat message to the argument")), CreateIl2cppString(OBFUSTR("")));
        AddMessage(instance, CreateIl2cppString(OBFUSTR("!nick [message] - Sets the nickname spoof to the argument")), CreateIl2cppString(OBFUSTR("")));
        AddMessage(instance, CreateIl2cppString(OBFUSTR("!nocollider - Disables (most) map bounds and death colliders")), CreateIl2cppString(OBFUSTR("")));
        AddMessage(instance, CreateIl2cppString(OBFUSTR("!yescollider - Re-enables (most) map bounds and death colliders")), CreateIl2cppString(OBFUSTR("")));
        return;
    }

    // set message for spamming
    if (args[0] == "!msg") {
        spamMessage = text->getString().substr(5);
        return;
    }

    // change nickname
    if (args[0] == "!nick") {
        nickName = text->getString().substr(6);
        spoofNick2 = OBFUSINT(true);
        return;
    }

    // REMOVE ALL BOUND COLLIDERS
    // THIS HAS NO ARGUMENTS
    if (args[0] == "!nocollider") {
        removeColliders();
        return;
    }
    if (args[0] == "!yescollider") {
        enableColliders();
        return;
    }

    // OTAX
    if (args[0] == "!otax") {
        if (args.size() == 1) {
            old_SendChatHOOK(instance, CreateIl2cppString(OBFUSTR("Can't otax!")), isClan, logoid);
            return;
        }
        otax(instance, isClan, logoid, args[1]);
        return;
    }

    if (uwufy) {
        text = uwufyMessage(text);
    }

    old_SendChatHOOK(instance, text, isClan, logoid);

}

void (*old_SendChatSquad)(void* instance, il2cppString* text, il2cppString* logoid);
void SendChatSquad(void* instance, il2cppString* text, il2cppString* logoid) {
    std::stringstream stream(text->getString());
    std::string segment;
    std::vector<std::string> args;

    while(std::getline(stream, segment, ' ')) {
        args.push_back(segment);
    }

    // Invite jew to the squad with their id
    if (args[0] == "!invite") {

        for(int i = 0; i < stoi(args[2]); ++i) {
            SendInviteToPlayer(instance, CreateIl2cppString(args[1].c_str()));
        }
        return;
    }

    old_SendChatSquad(instance, text, logoid);
}

il2cppString* (*old_GetPlayerNameOrDefault)();
il2cppString* GetPlayerNameOrDefault() {
    if (spoofNick) {
        return CreateIl2cppString(nicknames[nicknameIndex]);
    }
    return old_GetPlayerNameOrDefault();
}

void (*old_UIInput$$Update)(void* instance);
void UIInput$$Update(void* instance) {
    GetField<int>(instance, 0x44) = -1; // characterLimit
    GetField<int>(instance, 0x40) = Validation::None; // validation, 0 = None
    old_UIInput$$Update(instance);
}

bool (*old_get_shouldHide)(void* instance);
bool get_shouldHide(void* instance) {
    if (instance != nullptr && showItems) {
        int type = get_OfferItemType(instance);
        if (type == 10)
            return false;
    }
    return old_get_shouldHide(instance);
}

void (*old_PeerRPC)(void* ths, void* view, uint8_t eventEnum, int photonTargets, void* targetPlayer, bool encrypt, Il2CppArray* parameters);
void PeerRPC(void* ths, void* view, uint8_t eventEnum, int photonTargets, void* targetPlayer, bool encrypt, Il2CppArray* parameters) {
    // setpixelbookid, THIS BANS NOW FOR SOME GODDAMM REASON
    if (eventEnum == 0x53 && spoofMe3) {
        return;
    }

    if(!logRPC) {
        old_PeerRPC(ths, view, eventEnum, photonTargets, targetPlayer, encrypt, parameters);
        return;
    }


    LOGI("===[PeerRPC]===");
    LOGI("[PeerRPC] eventEnum: %s", rpcEntries[eventEnum]);

    if(parameters == nullptr) {
        LOGI("[PeerRPC] (eventEnum: %s) parameters is null", rpcEntries[eventEnum]);
        old_PeerRPC(ths, view, eventEnum, photonTargets, targetPlayer, encrypt, parameters);
        return;
    }

    if(targetPlayer != nullptr) {
        LOGI("[PeerRPC] (eventEnum: %s) targetPlayer is not null.", rpcEntries[eventEnum]);
    }
    else
    {
        LOGI("[PeerRPC] (eventEnum: %s) photonTargets: %i", rpcEntries[eventEnum], photonTargets);
    }
    for (int i = 0; i < parameters->max_length; ++i) {

        if(parameters->vector[i]== nullptr) {
            LOGI("[PeerRPC] (eventEnum: %s) index %i is null", rpcEntries[eventEnum], i);
        }
        else {

            //const char *namespaceName = il2cpp_class_get_namespace(il2cpp_object_get_class((Il2CppObject *) parameters->vector[i]));
            //const char *className = il2cpp_class_get_name(il2cpp_object_get_class((Il2CppObject *) parameters->vector[i]));
            const char *typeName = il2cpp_type_get_name(il2cpp_class_get_type(il2cpp_object_get_class((Il2CppObject *) parameters->vector[i])));

            LOGI("[PeerRPC] (eventEnum: %s) index: %i", rpcEntries[eventEnum], i);

            if (typeName != nullptr) {
                LOGI("[PeerRPC] (eventEnum: %s) typeName: %s", rpcEntries[eventEnum], typeName);
                if(strcmp(typeName, "System.Single") == 0 ) {
                    LOGI("[PeerRPC] (eventEnum: %s) value: %f", rpcEntries[eventEnum], UnboxIl2cppObject<float>((Il2CppObject*)parameters->vector[i]));
                }
                else if(strcmp(typeName, "System.Int32") == 0 ) {
                    LOGI("[PeerRPC] (eventEnum: %s) value: %i", rpcEntries[eventEnum], UnboxIl2cppObject<int>((Il2CppObject*)parameters->vector[i]));
                }
                else if(strcmp(typeName, "System.Double") == 0 ) {
                    LOGI("[PeerRPC] (eventEnum: %s) value: %f", rpcEntries[eventEnum], UnboxIl2cppObject<double>((Il2CppObject*)parameters->vector[i]));
                }
                else if(strcmp(typeName, "System.Boolean") == 0 ) {
                    LOGI("[PeerRPC] (eventEnum: %s) value: %i", rpcEntries[eventEnum], UnboxIl2cppObject<bool>((Il2CppObject*)parameters->vector[i]));
                }
                else if(strcmp(typeName, "System.String") == 0 ) {
                    LOGI("[PeerRPC] (eventEnum: %s) value: %s", rpcEntries[eventEnum], reinterpret_cast<il2cppString*>(parameters->vector[i])->getChars());
                }

            } else {
                LOGI("[PeerRPC] (eventEnum: %s) typeName is null", rpcEntries[eventEnum]);
            }
        }
    }
    old_PeerRPC(ths, view, eventEnum, photonTargets, targetPlayer, encrypt, parameters);
}

void* (*old_WSManager$$SendMessage)(void* instance, il2cppString* command, void* params, float idk1, void* delegate, void* bytearr);
void* WSManager$$SendMessage(void* instance, il2cppString* command, void* params, float idk1, void* delegate, void* bytearr) {
    WSMInstance = instance;

    if (instance != nullptr) {
        if (logWS) {
            auto str = JsonConvert$$SerializeObject(params)->getString();
            // backtrace();
            LOGD(OBFUSTR(">>> %s"), command->getString().c_str());
            logSplit(str);
        }
        if(ws::console_isConnected) {
            auto str = JsonConvert$$SerializeObject(params)->getString();
            ws::console_send((command->getString() + " (send): " + str).c_str());
        }
    }
    return old_WSManager$$SendMessage(instance, command, params, idk1, delegate, bytearr);
}

void* (*old_encryptCommand)(void* instance, void* byteArr, bool idk);
void* encryptCommand(void* instance, void* byteArr, bool idk) {
    if (instance != nullptr && !commandParams.empty()) {
        std::string currentCommand = Encoding$$GetString(get_UTF8(), byteArr)->getString();
        bool commandFound = false;

        for (const auto& param : commandParams) {
            if (currentCommand == (*param.second)[0]) {
                commandFound = true;
                break;
            }
        }

        if (!commandFound) {
            json parsedJson;
            try {
                parsedJson = json::parse(currentCommand);
                LOGD("Parsed JSON successfully");

                auto requestIdIterator = parsedJson.find("req_id");
                if (requestIdIterator == parsedJson.end()) {
                    LOGD("No req_id found in request!");
                    return old_encryptCommand(instance, byteArr, idk);
                }

                int requestId = *requestIdIterator;
                LOGD("Found req_id: %i", requestId);

                auto commandIterator = commandParams.find(requestId);
                if (commandIterator == commandParams.end()) {
                    LOGD(OBFUSTR("No request with id %i"), requestId);
                    return old_encryptCommand(instance, byteArr, idk);
                }

                (*commandIterator->second)[1]["req_id"] = requestId;
                std::string newParamsStr = ws::nullToArray((*commandIterator->second)[1].dump());
                std::string message = "Request with id " + std::to_string(requestId) + " has been sent successfully!";
                LOGD(OBFUSTR("Sending request with id %i"), requestId);
                std::string eventLog = ">>> " + (*commandIterator->second)[0].get<std::string>();
                std::string paramsLog = ">>> " + newParamsStr;
                LOGCONSOLE("%s", eventLog.c_str());
                LOGCONSOLE("%s", paramsLog.c_str());


                if (!massRequest) {
                    awaitingResponse.insert(std::make_pair(requestId, std::move(commandIterator->second)));
                    if (logrequests)
                        ShowToast(CreateIl2cppString(message.c_str()), false);
                }

                commandParams.erase(commandIterator);
                return old_encryptCommand(instance, Encoding$$GetBytes(get_UTF8(), CreateIl2cppString(newParamsStr.c_str())), idk);
            } catch (nlohmann::json::parse_error& e) {
                LOGD("Failed to parse JSON: %s", currentCommand.c_str());
            }
        }
    }

    return old_encryptCommand(instance, byteArr, idk);
}


void processProgressResponse(json& parsedJson) {
    auto progressIterator = parsedJson.find("slots");
    if (progressIterator == parsedJson.end()) {
        LOGD("No progress found in response!");
        return;
    }
    LOGWS("got json %s", parsedJson.dump().c_str());

    for (auto& [key, value] : progressIterator->items()) {
        int index;
        try {
            index = std::stoi(key);
        } catch (std::invalid_argument& e) {
            LOGWS("Key %s is not an integer", key.c_str());
            continue;
        }
        if (!value.is_object() && !value.is_array()) {
            LOGWS("Key %s is not an object", key.c_str());
            continue;
        }

        LOGWS("Updating slot %i", index);

        ProgressSlot& slot = progressSlots[index];
        slot.type = static_cast<SlotTypes>(index);
        slot.data = value;
        if (slot.slotUpdate.state == SlotState::FETCHING) {
            slot.slotUpdate.state = SlotState::FETCHED;
            LOGWS("Slot %i has been fetched", index);
        }
    }

    auto reqidit = parsedJson.find("req_id");
    if (reqidit == parsedJson.end()) {
        LOGD("No req_id found in response!");
        return;
    }
    int reqid = *reqidit;

    awaitingResponse.erase(reqid);
}


void processOkResponse(int requestId, il2cppString* command, json& parsedJson) {
    std::string message = "Response for request with id " + std::to_string(requestId) + " has been received successfully!";
    LOGWS("%s", message.c_str());
    std::string eventName = command->getString();

    ShowToast(CreateIl2cppString(message.c_str()), false);
    if (autoreload)
        sendReload = true;
    awaitingResponse.erase(requestId);
}


struct response_t {
    bool isSuccessful;
    int requestIdFound;
    std::string responseStatus;
};

response_t parseResponse(json& parsedJson) {
    response_t checkResult;
    checkResult.isSuccessful = false;

    auto reqIdIterator = parsedJson.find("req_id");
    if (reqIdIterator == parsedJson.end()) {
        LOGWS("No req_id found in the response");
        return checkResult;
    }
    checkResult.requestIdFound = *reqIdIterator;
    LOGWS("Found req_id: %i", checkResult.requestIdFound);

    auto responseIterator = awaitingResponse.find(checkResult.requestIdFound);
    if (responseIterator == awaitingResponse.end()) {
        return checkResult;
    }
    LOGWS(OBFUSTR("Found request with id %i"), checkResult.requestIdFound);

    auto statusIterator = parsedJson.find("status");
    if (statusIterator == parsedJson.end()) {
        LOGWS("No status found in the response");
        return checkResult;
    }
    checkResult.responseStatus = *statusIterator;

    checkResult.isSuccessful = true;
    return checkResult;
}


void* (*old_receiveWebsocket)(il2cppString* command, void* dict1, void* dict2, void* listbytearr);
void* receiveWebsocket(il2cppString* command, void* dict1, void* dict2, void* listbytearr) {
    std::string response = JsonConvert$$SerializeObject(dict1)->getString();

    if (logWS) {
        LOGD(OBFUSTR("<<< %s"), command->getString().c_str());
        logSplit(response);
    }

    if(ws::console_isConnected) {
        ws::console_send((command->getString() + " (receive): " + response).c_str());
    }

    json parsedJson;
    try {
        parsedJson = json::parse(response);
    }
    catch (nlohmann::json::parse_error& e) {
        LOGWS("Failed to parse JSON: %s", response.c_str());
        return old_receiveWebsocket(command, dict1, dict2, listbytearr);
    }

    if (command->getString() == "get_progress" && !awaitingGetProgress.empty()) {
        auto [isSuccessful, requestId, rStatus] = parseResponse(parsedJson);
        if (!isSuccessful) {
            LOGWS("Response is not successful");
            return old_receiveWebsocket(command, dict1, dict2, listbytearr);
        }

        if (rStatus == "ok") {
            auto getProgressIterator = awaitingGetProgress.find(requestId);
            if (getProgressIterator == awaitingGetProgress.end()) {
                LOGWS("No request with id %i in awaitingGetProgress", requestId);
                return old_receiveWebsocket(command, dict1, dict2, listbytearr);
            }
            awaitingGetProgress.erase(getProgressIterator);

            processProgressResponse(parsedJson);
        }
        else {
            std::string message = "Error: " + response;
            ShowToast(CreateIl2cppString(message.c_str()), false);
            LOGWS("Error status received: %s", response.c_str());
        }
    }
    else if (logrequests && !awaitingResponse.empty()) {
        LOGWS("There are currently %i requests in queue", awaitingResponse.size());
        if (!parsedJson.empty()) {
            LOGWS("Parsed JSON successfully");

            auto [isSuccessful, requestId, rStatus] = parseResponse(parsedJson);
            if (!isSuccessful) {
                LOGWS("Response is not successful");
                return old_receiveWebsocket(command, dict1, dict2, listbytearr);
            }

            std::string eventLog = "<<< " + command->getString();
            std::string paramsLog = "<<< " + parsedJson.dump();
            LOGCONSOLE("%s", eventLog.c_str());
            LOGCONSOLE("%s", paramsLog.c_str());

            // if ok and get_progress
            if (rStatus == "ok") {
                processOkResponse(requestId, command, parsedJson);
            }
            else {
                std::string message = "Error: " + response;
                ShowToast(CreateIl2cppString(message.c_str()), false);
                LOGWS("Error status received: %s", response.c_str());
                awaitingResponse.erase(requestId);
            }
        }
        else {
            LOGWS("Parsed JSON is empty");
        }
    }
    else {
        // LOGWS("No log requests or awaiting response is empty");
    }
    return old_receiveWebsocket(command, dict1, dict2, listbytearr);
}

il2cppString* (*old_getDeviceUniqeIdentifier)();
il2cppString* getDeviceUniqeIdentifier() {
    std::string s = std::to_string(rand());
    return CreateIl2cppString(s.c_str());
}

void (*old_setCrossHairColor)(void *instance, Vector4 color);
void setCrossHairColor(void *instance, Vector4 color) {
    if(instance != nullptr && triggerbot && color == Vector4(1.0f, 0.0f, 0.0f, 1.0f) && pg_me.instance != nullptr) {
        ShotPressed(pg_me.instance);
    }
    old_setCrossHairColor(instance, color);
}

int (*old_getLevel)(void *instance);
int getLevel(void *instance) {
    if(instance != nullptr) {
        int level = old_getLevel(instance);
        ws::playerLevel = level;
        if (customLvl)
            level = desiredLevel;
        return level;
    }
    return old_getLevel(instance);
}

int (*old_getCollectibles)(void *instance);
int getCollectibles(void *instance) {
    if(instance != nullptr && collectibles) {
        return collectiblesVal;
    }
    return old_getCollectibles(instance);
}

int (*old_IsReady)();
int IsReady() {
    JNIEnv* _env = getEnv();
    // LOGW("==========[IsReady]==========");
    // called whenever GameConnect is created
    const char* s = "k2N3tpo51US8iE";
    int len = strlen(s);
    jbyteArray byteArray = _env->NewByteArray(len);
    _env->SetByteArrayRegion(byteArray, 0, len, (jbyte *)s);
    newnativeUnitySendMessage(_env, _env->FindClass("com/unity3d/player/UnityPlayer"), _env->NewStringUTF("GameConnect"),
                              _env->NewStringUTF("SetGameConnectProperty"), byteArray);
    return 0;
}

int (*old_GetPlacementState)();
int GetPlacementState() {
    JNIEnv* _env = getEnv();
    // LOGW("==========[GetPlacementState]==========");
    const char* s = "0YLRiyDQv9C40LTQvtGA";
    int len = strlen(s);
    jbyteArray byteArray = _env->NewByteArray(len);
    _env->SetByteArrayRegion(byteArray, 0, len, (jbyte *)s);

    newnativeUnitySendMessage(_env, _env->FindClass("com/unity3d/player/UnityPlayer"), _env->NewStringUTF("SwitcherController"),
                              _env->NewStringUTF("ChangeTextureFolderName"), byteArray);
    return 0;
}

int (*old_SupportedOrientations)();
int SupportedOrientations() {
    // LOGW("==========[SupportedOrientations]==========");
    return 0;
}

void* (*old_SendInstantiate)(void* obj, il2cppString* prefabName, il2cppVector3 position, il2cppQuaternion rotation, uint8_t group,
        il2cppArray<int*>* viewIDs, Il2CppArray* data, bool isRoomObject);
void* SendInstantiate(void* obj, il2cppString* prefabName, il2cppVector3 position, il2cppQuaternion rotation, uint8_t group,
                      il2cppArray<int*>* viewIDs, Il2CppArray* data, bool isRoomObject) {

    LOGW("SendInstantiate: %s, group %d, isRoomObject %d", prefabName->getChars(), group, isRoomObject);

    for (int i = 0; i < viewIDs->getLength(); i++) {
        LOGW("SendInstantiate: viewID %d: %d", i, viewIDs->getPointer()[i]);
    }

    LOGW("SendInstantiate data: %s", JsonConvert$$SerializeObject((void*)data)->getChars());

    return old_SendInstantiate(obj, prefabName, position, rotation, group, viewIDs, data, isRoomObject);
}

void (*old_OnOperationResponse)(void* obj, void* OperationResponse);
void OnOperationResponse(void* obj, void* OperationResponse) {
    if (obj != nullptr && logRPC) {
        il2cppString* opdata = JsonConvert$$SerializeObject(OperationResponse);
        LOGW("OnOperationResponse: %s", opdata->getChars());
    }
    old_OnOperationResponse(obj, OperationResponse);
}

void (*old_OnEvent)(void* obj, void* EventData);
void OnEvent(void* obj, void* EventData) {
    if (obj != nullptr && logRPC) {
        il2cppString* opdata = JsonConvert$$SerializeObject(EventData);
        LOGW("OnEvent: %s", opdata->getChars());
    }
    old_OnEvent(obj, EventData);
}

void (*old_OnStatusChanged)(void* obj, int StatusCode);
void OnStatusChanged(void* obj, int StatusCode) {
    if (obj != nullptr && logRPC) {
        LOGW("OnStatusChanged: %d", StatusCode);
    }
    old_OnStatusChanged(obj, StatusCode);
}

bool (*old_OpCustom)(void* obj, uint8_t customOpCode, void* customOpParameters, bool sendReliable, uint8_t channelId, bool encrypt);
bool OpCustom(void* obj, uint8_t customOpCode, void* customOpParameters, bool sendReliable, uint8_t channelId, bool encrypt) {
    if (obj != nullptr && logRPC) {
        LOGW("OpCustom: customOpCode %d, sendReliable %d, channelId %d, encrypt %d", customOpCode, sendReliable, channelId, encrypt);
        LOGW("OpCustom customOpParameters: %s", JsonConvert$$SerializeObject(customOpParameters)->getChars());
    }
    return old_OpCustom(obj, customOpCode, customOpParameters, sendReliable, channelId, encrypt);
}

void bypassHooks() { // DO NOT USE HOOK_IL2CPP IN THIS METHOD
    // we need to call these before to avoid kicks
    // ANTICHEAT
    HOOKD("0x479E268", SupportedOrientations);
    HOOKD("0x479E198", IsReady);
    HOOKD("0x479E3FC", GetPlacementState);
}

void Hooks() {
    //HOOKD("0x4DC0E98", OpCustom);
    //HOOKD("0x5CCA1A8", OnStatusChanged);
    //HOOKD("0x5CCAF94", OnEvent);
    //HOOKD("0x5CC750C", OnOperationResponse);
    HOOKD("0x5CD0424", SendInstantiate);
    HOOKD("0x5CD1B60", PeerRPC);
    HOOKD("0x2D83EC4", getCollectibles);
    HOOKD("0x2C29674", getLevel);
    HOOKD("0x2D83F6C", get_shouldHide);
    HOOKD("0x4D2BCE0", SendPlayerEffect); // search for ".PlayerEffectRPC, PhotonTargets.Others," then find method with default -1 int parameter
    HOOKD("0x2E9FC0C", gadgetDuration);//search for gadget_combat_spinner and find the float via analyze
    HOOKD("0x4198D1C", Rocket); // Rocket.IsGravityRocket  HOOK ISNT UPDATED //HOOK IS UPDATED NOW!
    HOOKD("0x4D51830", CreateRocket); // player_move_c.CreateRocket  HOOK ISNT UPDATED //HOOK IS UPDATED NOW!
    HOOKD("0x29F6FE8", GetPlayerNameOrDefault); // search ".WeaponBuy)" in ProfileController
    HOOKD("0x3F02C78", receiveWebsocket);
    HOOKD("0x3F0B8A0", WSManager$$SendMessage);
    HOOKD("0x272F990", encryptCommand);
    // HOOK("0x4195030", decryptCommand, old_decryptCommand);

    HOOK_IL2CPP("", "AimCrosshairController", "SetCrosshairColor", 1, setCrossHairColor);
    HOOK_IL2CPP("UnityEngine", "SystemInfo", "GetDeviceUniqueIdentifier", 0, getDeviceUniqeIdentifier); // proplam, fix this
    HOOK_IL2CPP("", "ItemRecord", "get_Rarity", 0, getItemRarity);
    HOOK_IL2CPP("", "PixelTime", "Update", 0, PixelTime);
    HOOK_IL2CPP("", "WeaponSounds", "Update", 0, WeaponSounds);
    HOOK_IL2CPP("", "WeaponManager", "Update", 0, WeaponManager);
    HOOK_IL2CPP("", "Player_move_c", "Update", 0, PlayerMoveC);
    HOOK_IL2CPP("", "UIInput", "Update", 0, UIInput$$Update);
    HOOK_IL2CPP("", "ItemRecord", "get_SpeedModifier", 0, Speed);
    HOOK_IL2CPP("", "FirstPersonControlSharp", "Update", 0, FirstPersonControllSharp);
    HOOK_IL2CPP("", "PetInfo", "get_SpeedModif", 0, petSpeed);
    HOOK_IL2CPP("", "PetInfo", "get_HP", 0, petHealth);
    HOOK_IL2CPP("", "PetInfo", "get_Attack", 0, petAttack);
    HOOK_IL2CPP("", "Player_move_c", "SendChat", 3, SendChatHOOK);
    HOOK_IL2CPP("", "SquadController", "SendChatMessage", 2, SendChatSquad);
}

void Hooks2() {
    HOOK_IL2CPP("", "PixelTime", "Update", 0, PixelTime2);
}
