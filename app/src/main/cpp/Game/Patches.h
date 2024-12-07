void Patches() {
    // automatically updated patches
    PATCH_SWITCH_IL2CPP(get_AmmoInClip, "E0E184D2C0035FD6", ammo);
    PATCH_SWITCH_IL2CPP(get_MaxAmmo, "E0E184D2C0035FD6", ammo);
    PATCH_SWITCH_IL2CPP(get_IsUnlimitedAmmo, "20008052C0035FD6", ammo);
    PATCH_SWITCH_IL2CPP(get_InitialAmmo, "E0E184D2C0035FD6", ammo);
    PATCH_SWITCH_IL2CPP(get_isEditor, "20008052C0035FD6", isEditor);
    PATCH_SWITCH_IL2CPP(get_platform, "E00080D2C0035FD6", isEditor);
    PATCH_SWITCH_IL2CPP(get_AnyLogEnabled, "20008052C0035FD6", isEditor);
    PATCH_SWITCH_IL2CPP(get_Energy, "00008052C0035FD6", clanEnergy);
    PATCH_SWITCH_IL2CPP(get_Available, "20008052C0035FD6", bundles);
    PATCH_SWITCH_IL2CPP(get_NextUpPower, "00008052C0035FD6", clanparts);
    PATCH_SWITCH_IL2CPP(MinusLive, "C0035FD6", tgod);
    PATCH_SWITCH_IL2CPP(MinusLiveReal, "C0035FD6", tgod);
    PATCH_SWITCH_IL2CPP(MinusLive2, "C0035FD6", tgod);
    PATCH_SWITCH_IL2CPP(get_RespawnTime, "00008052C0035FD6", prespawntime);
    PATCH_SWITCH_IL2CPP(NextHitCritical, "200080D2C0035FD6", crithit);
    PATCH_SWITCH_IL2CPP(ValidateNickName, "200080D2C0035FD6", swear);
    PATCH_SWITCH_IL2CPP(ValidateNickNameNoAnalytics, "200080D2C0035FD6", swear);
    PATCH_IL2CPP(GetRequiredState, "00008012C0035FD6"); // (gg bypass)
    PATCH_IL2CPP(InhouseAnalyticsController$$Awake, "00008012C0035FD6");
    PATCH_IL2CPP(InhouseAnalyticsController$$Start, "C0035FD6");
    PATCH_IL2CPP(SendAnalytics, "C0035FD6");
    PATCH_IL2CPP(CustomHungerBase$$Awake, "C0035FD6");
    PATCH_IL2CPP(CustomHungerBase, "C0035FD6");
    PATCH_IL2CPP(CoinsMessage$$Start, "C0035FD6");
    PATCH_IL2CPP(NotificationController$$Update, "C0035FD6");

    if (isInMatch()) {
        PATCH_SWITCH("0x4D62B74", "C0035FD6", god); // search int viewID and you'll find it (player_move_c)
        PATCH_SWITCH("0x45A88B4", "C0035FD6", god); // search for SkinName skinName = this.mySkinName; dont panic, itll be used alot, try to find the one which only takes SkinName and has the argument CategoryNames
        PATCH_SWITCH_IL2CPP(OnTriggerEnter, "C0035FD6", god);
        PATCH_SWITCH_IL2CPP(OnControllerColliderHit, "C0035FD6", god);
    } else {
        // these 4 are same as above
        PATCH_SWITCH("0x4D62B74", "C0035FD6", false); // search int viewID and you'll find it (player_move_c)
        PATCH_SWITCH("0x45A88B4", "C0035FD6", false); // search for SkinName skinName = this.mySkinName; dont panic, itll be used alot, try to find the one which only takes SkinName and has the argument CategoryNames
        PATCH_SWITCH_IL2CPP(OnTriggerEnter, "C0035FD6", false);
        PATCH_SWITCH_IL2CPP(OnControllerColliderHit, "C0035FD6", false);
    }

    PATCH_SWITCH("0x51B7188", "E07B40B2C0035FD6", firerate);
    PATCH_SWITCH("0x3D46014", "00008052C0035FD6", isEditor); // getIsLogEnabled MIGHT CAUSE BANS! Search for GoogleLite check enum usage, static of itself method is below
    PATCH_SWITCH("0x3D2B5B0", "20008052C0035FD6", isEditor);

    //stuff from judsn
    PATCH_SWITCH("0x2160C58", "20008052C0035FD6", giftpp);
    PATCH_SWITCH("0x21609D0", "20008052C0035FD6", giftpp);
    PATCH_SWITCH("0x2160C1C", "20008052C0035FD6", giftpp);
    PATCH_SWITCH("0x29BA158", "20008052C0035FD6", judsngraffiti);
    PATCH_SWITCH("0x29B9F20", "E07C8052C0035FD6", judsngraffiti);
    PATCH_SWITCH("0x37F083C", "20008052C0035FD6", showdeletedgadgets);
    PATCH_SWITCH("0x40F6A2C", "20008052C0035FD6", showdeletedgadgets);
    PATCH_SWITCH("0x37F0020", "20008052C0035FD6", unreleasedroyaleandhats);
    PATCH_SWITCH("0x37D463C", "C0035FD6F55301A9", maxmods);
    PATCH_SWITCH("0x37D4ED0", "20008052C0035FD6", maxmods);
    PATCH_SWITCH("0x289D964", "40018052C0035FD6", maxmods);
    PATCH_SWITCH("0x24ED2C4", "00008052C0035FD6", unlimitedsuperclanchest);
    PATCH_SWITCH("0x24EDA14", "00008052C0035FD6", clanchestopenprice);
    PATCH_SWITCH("0x24EE6EC", "00008052C0035FD6", clanchestopenprice);
    PATCH_SWITCH("0x3C1B3E8", "00008052C0035FD6", unreleasedroyale);
    PATCH_SWITCH("0x37F0F2C", "20008052C0035FD6", unreleasedroyale);
    PATCH_SWITCH("0x2740318", "20008052C0035FD6", peteggcd);
    PATCH_SWITCH("0x273EE40", "E07C8052C0035FD6", peteggmodifier);

    PATCH_SWITCH("0x3C2DA78", "20008052C0035FD6", wepSkins6);
    PATCH_SWITCH("0x2AF38DC", "00008052C0035FD6", wepSkins6);

    // missing upModule and lobbyItemBundles
    PATCH_SWITCH("0x47F24C0", "20008052C0035FD6", lobbyItems);
    PATCH_SWITCH("0x47F1F20", "00008052C0035FD6", lobbyItems);
    PATCH_SWITCH("0x289E0C4", "00008052C0035FD6", upModule);
    PATCH_SWITCH("0x45AE3F8", "00008052C0035FD6", bundles); // just analyze LobbyItemsBundle and compare it to the other one to find
    PATCH_SWITCH("0x45AE708", "00008052C0035FD6", bundles); // after you find the class ^^^^^^^^^^^^ search for LobbyItemBuff and get the set

    PATCH_SWITCH("0x2AF38DC", "80258052C0035FD6", wearUnlocker); // below string search Weapon_CraftDe_tailsInfo: you should not add fort parts to Weapo_nCraft_Detai_lsInfo
    PATCH_SWITCH("0x28897CC", "E0868052C0035FD6", wearUnlocker);
    PATCH_SWITCH("0x45ED4A0", "00008052C0035FD6", clanparts); // same class as above search for internal int obfshit(int obfshit)

    // PATCH_SWITCH("0x1C00FA4", "40339F52208FA8720000271EC0035FD6", god);// get_TeammateHealMultiplier()
    // pretty sure this makes game freak out a bit PATCH_SWITCH("0x4CD6504", "C0035FD6", god);// SkinName.OnControllerColliderHit

    PATCH_SWITCH("0x26968F8", "603E8012C0035FD6", modKeys);// string search "Free" and find the class with '0', '1', etc then get the int below the constructor

    PATCH_SWITCH("0x4D544FC", "C0035FD6", removedrone);//player_move_c and droneController.Deactivate();
    PATCH_SWITCH("0x4D53C60", "C0035FD6", removedrone);//right below this ^^^

    PATCH_SWITCH("0x507CD24", "00F0271EC0035FD6", reload);//mask_hitman_1_up1 in strings and the method with weaponsounds
    PATCH_SWITCH("0x2E9FB90", "200080D2C0035FD6", gadgetcd); // same class as below, idk if true or false tho
    PATCH_SWITCH("0x2E9FC0C", "000080D2C0035FD6", gadgetcd);//search Action in player_move_c find the 2 fields with action exactly then above some bools should be a classname which is GADGET

    PATCH_SWITCH("0x18D4480", "00008052C0035FD6", teamkill);//compare isTeamMode to 16.6.1  version goodluck (hint it should be the same as in 16.6.1)
    PATCH_SWITCH("0x18D5890", "00008052C0035FD6", teamkill);//look for Random in PlayerBotInstance, you'll find the bool at the end of the method
    //
    PATCH_SWITCH("0x52CA59C", "000080D2C0035FD6", blackmarket); //compare, search : internal static List<int> should be few lines under
    PATCH_SWITCH("0x28B4170", "200080D2C0035FD6", taskclicker);
    PATCH_SWITCH("0x547D404", "000080D2C0035FD6", swear);//Swear filter search for fuck

    PATCH_SWITCH("0x45A8A9C", "C0035FD6", antiban);//antiban -  search DeveloperConsoleController.HandleBanUs and the method inside is the one

    // extern calls to anticheat in libunityads.so ALL OF THESE ARE IN CLASS: UAds
    PATCH("0x4177F18", "C0035FD6"); // ChainOfferEventsAnalyticsController instance methods
    PATCH("0x4177FE4", "C0035FD6");
    PATCH("0x41781D0", "C0035FD6");
    PATCH("0x41780B0", "C0035FD6");
    PATCH("0x444540C", "00008052C0035FD6"); // search for signatures == null

    // detection checks
    PATCH("0x32F55E4", "C0035FD6"); // string search Y29tLnVuaXR5M2QucGxheWVyLlVuaXR5UGxheWVy
    PATCH("0x3CD0448", "C0035FD6"); // string search Ｓａ
    PATCH("0x19F6A80", "C0035FD6"); // string search Speedhack detected!
    PATCH("0x32B8A18", "00008052C0035FD6"); // string search AEAD:
    PATCH("0x40509BC", "C0035FD6");

    // idk if true or false these next ones
    PATCH("0x311AF4C", "00008052C0035FD6"); // above com.Rilisoft
    PATCH("0x311AE60", "00008052C0035FD6"); // string search key look for obf bool
    PATCH("0x44BE6B8", "00008052C0035FD6"); // look for usages in MiscAppsMenu

    PATCH("0x48551C4", "C0035FD6"); // coinsShop
    //  PATCH("0x34D6EC4", "00008052C0035FD6"); same as below
    //  PATCH("0x3A9A8C8", "00008052C0035FD6"); moved after 23.6.2 and couldnt find it in 23.7.1

    PATCH("0x5ABF964", "C0035FD6"); // search for number 2000 void without params that class obf

    // PATCH("0x2D2DE40", "C0035FD6"); // GameController sus method, whenever we nop this, on kicks we get our player's objects deleted
    // related to above sus methods here: , consider hooking 0x531B334
    PATCH("0x19F4344", "C0035FD6");
    /* PATCH("0x167EA88", "C0035FD6");
    PATCH("0x167E950", "C0035FD6");
    PATCH("0x2B792F8", "C0035FD6");
    PATCH("0x285092C", "C0035FD6");
    PATCH("0x2B3597C", "C0035FD6"); */

    PATCH("0x32C1170", "C0035FD6"); // Application.Quit usage
    PATCH("0x19F3E64", "C0035FD6"); // string search for chunger
    PATCH("0x19F3D88", "C0035FD6"); // sus chunger method

    // AndroidJNI usages are supersus, thats why im patching them all
    PATCH("0x3CEED14", "00008052C0035FD6");
    PATCH("0x3CEEFA8", "00008052C0035FD6");
    PATCH("0x3CEF0B8", "00008052C0035FD6");
    PATCH("0x3CEFE10", "00008052C0035FD6");
    PATCH("0x3CF0D3C", "00008052C0035FD6");
    PATCH("0x3CF1480", "00008052C0035FD6");
    PATCH("0x3CF1D70", "00008052C0035FD6");
    PATCH("0x3CF1E74", "00008052C0035FD6");
    PATCH("0x3CEFA48", "00008052C0035FD6"); // string search An AndroidJavaException occurred during a call to
    PATCH("0x3CEF5C4", "00008052C0035FD6");
    PATCH("0x3CF0280", "00008052C0035FD6");

    PATCH("0x4EE495C", "C0035FD6"); // PLUGIN RPC

    // analytics
    // firebaseanalytics logevent
    PATCH("0x560A4F4", "00008052C0035FD6");
    PATCH("0x560A698", "00008052C0035FD6");
    PATCH("0x560A8A8", "00008052C0035FD6");
    PATCH("0x560AAB4", "00008052C0035FD6");
    PATCH("0x560AF64", "00008052C0035FD6");
    PATCH("0x3998044", "00008052C0035FD6");
    PATCH("0x3998118", "00008052C0035FD6");
    PATCH("0x39981F4", "00008052C0035FD6");
    PATCH("0x39982C8", "00008052C0035FD6");
    PATCH("0x399839C", "00008052C0035FD6");
    PATCH("0x3998458", "00008052C0035FD6");

    //this is going to be fun to update
    //another analytics, acquire currency + level
    PATCH("0x3919058", "00008052C0035FD6");
    PATCH("0x3919ED4", "00008052C0035FD6");
    PATCH("0x391A1FC", "00008052C0035FD6");
    PATCH("0x3919F68", "00008052C0035FD6");
    PATCH("0x391A2A0", "00008052C0035FD6");
    PATCH("0x391ABFC", "00008052C0035FD6");
    PATCH("0x391ACA0", "00008052C0035FD6");
    PATCH("0x391B218", "00008052C0035FD6");
    PATCH("0x391515C", "00008052C0035FD6");
    PATCH("0x391B528", "00008052C0035FD6");
    PATCH("0x391B8F8", "00008052C0035FD6");
    PATCH("0x391BA30", "00008052C0035FD6");
    PATCH("0x391BD14", "00008052C0035FD6");
    PATCH("0x391BDD0", "00008052C0035FD6");
    PATCH("0x391C8C4", "00008052C0035FD6");
    PATCH("0x391C980", "00008052C0035FD6");
    PATCH("0x391D044", "00008052C0035FD6");
    PATCH("0x3919A48", "00008052C0035FD6");

    PATCH("0x391ECBC", "00008052C0035FD6");
    PATCH("0x391ED88", "00008052C0035FD6");
    PATCH("0x391EE30", "00008052C0035FD6");
    PATCH("0x391EE34", "00008052C0035FD6");
    PATCH("0x391EE38", "00008052C0035FD6");
    PATCH("0x391EE3C", "00008052C0035FD6");
    PATCH("0x391EF30", "00008052C0035FD6");
    PATCH("0x391EF3C", "00008052C0035FD6");

    //highly suspicious class //has moved methods from coinsshop (analytics)
    PATCH("0x33386B4", "00008052C0035FD6");

    //module purchase & upgrade analytics
    PATCH("0x35A07E8", "00008052C0035FD6");
    PATCH("0x35A0B24", "00008052C0035FD6");
    PATCH("0x35A1120", "00008052C0035FD6");
    PATCH("0x35A1434", "00008052C0035FD6");
    PATCH("0x35A1784", "00008052C0035FD6");

    //currency analytic patches
    PATCH("0x359F268", "00008052C0035FD6");
    PATCH("0x359F594", "00008052C0035FD6");
    PATCH("0x359F6A0", "00008052C0035FD6");
    PATCH("0x359F794", "00008052C0035FD6");
    PATCH("0x359F984", "00008052C0035FD6");
    PATCH("0x359FA60", "00008052C0035FD6");

    //player level analytics
    PATCH("0x359E5EC", "00008052C0035FD6");
    PATCH("0x358B73C", "00008052C0035FD6");

    //PATCH("0x214D8E0", "C0035FD6");// Search for DataSystem.DataValidation and the cctor inside the first class //24.0.1 either moved or gone
    PATCH("0x586DAA4", "C0035FD6"); // search for the enumerator called step
    PATCH("0x4B99370", "20008052C0035FD6"); // isPayingUser StoreKitEventListener Above ProvideContent()
}