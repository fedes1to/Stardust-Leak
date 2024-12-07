Pointer<void(il2cppString*)> LoadLevel;
Pointer<void(il2cppString*)> OpenURL;
Pointer<void(il2cppString*, int)> setInt;
Pointer<void(void*, bool)> EnableJetpack;
Pointer<void(void*, il2cppString*, bool, il2cppString*)> SendChat;
Pointer<void(void*, il2cppString*)> SendInviteToPlayer;
Pointer<void*()> get_UTF8;
Pointer<void*()> get_royaleInstance;
Pointer<void*()> get_RoyaleList;
Pointer<void*()> webInstance;
Pointer<void*()> AuthInstance;
Pointer<void*()> tutorialInstance;
Pointer<void*(void*)> get_playerCamera;
Pointer<void*(void*)> BaseCamera$$Camera;
Pointer<void*(void*)> PD$$GetTransform;
Pointer<void*(void*)> PhotonView$Get;
Pointer<void*(void*)> Component$get_transform;
Pointer<void*(void*, void*)> GameObject$$AddComponent;
Pointer<void*(void*, void*)> GameObject$$GetComponent;
Pointer<void*(void*, il2cppString*)> Encoding$$GetBytes;
Pointer<void*(il2cppString*)> Type$$GetType;
Pointer<void*(il2cppString*, void*)> Resources$$Load;
Pointer<void*(il2cppString*, void*)> DeserializeObject;
Pointer<void*(void*, il2cppVector3, il2cppQuaternion)> GameObject$$Instantiate;
Pointer<il2cppString*(void*, void*)> Encoding$$GetString;
Pointer<void*(void*)> Component$get_object;
Pointer<il2cppVector3(void*)> get_position;
Pointer<il2cppQuaternion(void*)> get_rotation;
Pointer<void(void*, il2cppVector3)> set_position;
Pointer<void(void*, il2cppVector3)> set_local_scale;
Pointer<void(void*, int, int, int, bool)> addchestp;
Pointer<void(int)> targetFrameRate;
Pointer<int()> getTargetFrameRate;
Pointer<void(il2cppString*, bool)> ShowToast;
Pointer<il2cppString*()> getAuthURL;
Pointer<il2cppString*()> getAuthID;
Pointer<il2cppString*(void*)> GameObject$$get_tag;
Pointer<il2cppString*(void*)> getAuthSecret;
Pointer<il2cppString*(void*)> getAuthInfo;
Pointer<il2cppString*(void*)> Object$$get_name;
Pointer<il2cppString*(void*)> get_photonName;
Pointer<il2cppString*(void*)> JsonConvert$$SerializeObject;
Pointer<il2cppString*(il2cppString*, int)> string$$Substring2;
Pointer<il2cppString*(il2cppString*, il2cppString*)> string$$Concat;
Pointer<il2cppString*(il2cppString*, il2cppString*, il2cppString*)> string$$Replace;
Pointer<il2cppString*(il2cppString*)> string$$ToLower;
Pointer<il2cppString*(int)> GetNameInternal;
Pointer<void(void*, void*, float, float)> SetPlayerSpeed;
Pointer<void(void*, void*, float)> DisablePlayerJump;
Pointer<int()> GetActiveScene;
Pointer<int(void*)> get_photonID;
Pointer<int(void*)> get_OfferItemType;
Pointer<int(void*, il2cppString*)> sendCommand;
Pointer<void()> fillTutorial2;
Pointer<void(void*, uint8_t, int, Il2CppArray*)> PhotonView$RPC;
Pointer<void(void* , bool, bool)> InGameGUI$$SetInterfaceVisible;
Pointer<void(void*, bool)> GameObject$$SetActive;
Pointer<bool(void*)> GameObject$$GetActive;
Pointer<void(void*)> Object$$DontDestroyOnLoad;
Pointer<void(void*, il2cppString*, il2cppString*)> AddMessage;
Pointer<void(bool)> setEnabledConsole;
Pointer<void(void*, il2cppVector3)> Transform$$LookAt;
Pointer<void(void*, il2cppString*)> setAuthSecret;
Pointer<void(void*, il2cppString*)> setAuthInfo;
Pointer<void(il2cppString*)> setAuthID;
Pointer<void(void*)> ShotPressed;
Pointer<void(void*)> winInSpleef;
Pointer<void(void*)> RequestOwnership;
Pointer<void(void*)> fillTutorial1;
Pointer<void(il2cppString*, int, bool, bool)> Storager$$setInt;
Pointer<void(il2cppString*)> banAccount;
Pointer<void(void*, int, int)> addclanlevel;
Pointer<void(void*, int)> addToScore;
Pointer<bool()> isInMatch;
Pointer<bool(void*, int)> hasRoyaleItem;
Pointer<bool(void*, void*)> IsEnemyTo;
Pointer<bool(void*)> PhotonView$IsMine;
Pointer<bool(il2cppString*, il2cppString*)> string$$Equals;
Pointer<bool(il2cppString*, il2cppString*)> string$$Contains;
Pointer<bool(void*, int, bool)> set_master;
Pointer<bool(il2cppString*, float)> float$$TryParse;
Pointer<bool(void*, il2cppVector3)> IsTargetVisible;
Pointer<float(il2cppString*)> float$$Parse;
Pointer<il2cppArray<void**>*(void*)> Resources$$FindObjectsOfTypeAll;
Pointer<il2cppArray<void**>*()> PhotonNetwork_playerListothers;
Pointer<il2cppVector3(void*)> Transform$$forward;
Pointer<il2cppVector3(void*, il2cppVector3)> Camera_WorldToScreenPoint;
Pointer<il2cppList<void**>*()> GetItemRecordList;
Pointer<void(void*, il2cppString*, int)> addWeapon;
Pointer<void(void*, bool)> EnableXray;
Pointer<void(void*, bool)> SetXrayShader;
Pointer<void*()> get_petsList;
Pointer<bool(void*)> get_isMine;
Pointer<void*(void*)> get_IDamage;
Pointer<void(void*, void*, float, void*, il2cppVector3, il2cppString*, int, int)> ApplyDamageToTarget;
Pointer<void(void*, int, bool, il2cppString*)> SetModuleGadgetEffectActive;
Pointer<void(void*, int, bool, il2cppString*, int)> SetGadgetEffectActive;
Pointer<void*(il2cppString*, il2cppVector3, il2cppQuaternion, uint8_t, Il2CppArray*)> InstantiateSceneObject;
Pointer<void*(il2cppString*, il2cppVector3, il2cppQuaternion, uint8_t, Il2CppArray*)> InstantiateObject;
Pointer<void*()> localPhotonPlayer;
Pointer<void(void*)> U_StartNewGameClicked;

// pointers for patches so they are not called every frame
uintptr_t get_AmmoInClip, get_MaxAmmo, get_IsUnlimitedAmmo, get_InitialAmmo, get_isEditor, get_platform, get_AnyLogEnabled, get_Energy, get_Available, get_NextUpPower,
        OnTriggerEnter, OnControllerColliderHit, MinusLive, MinusLiveReal, MinusLive2, NextHitCritical, get_RespawnTime, ValidateNickName,
        ValidateNickNameNoAnalytics, GetRequiredState, InhouseAnalyticsController$$Awake, InhouseAnalyticsController$$Start, SendAnalytics, CustomHungerBase$$Awake,
        CustomHungerBase, CoinsMessage$$Start, NotificationController$$Update;

void Pointers() {
    // need to update these
    InstantiateObject = OFFSET("0x57B6C60");
    InstantiateSceneObject = OFFSET("0x57B72AC");
    Transform$$LookAt = OFFSET("0x4EC6BF0"); // we cant use il2cpp api as it will get the one with transform parameter
    SetGadgetEffectActive = OFFSET("0x4D4D818");
    GetItemRecordList = OFFSET("0x230B764");
    SetModuleGadgetEffectActive = OFFSET("0x4D4D818");
    ApplyDamageToTarget = OFFSET("0x4D6EF94");
    get_IDamage = OFFSET("0x3320E7C");
    get_isMine = OFFSET("0x4CFA5A8");
    EnableXray = OFFSET("0x4D08450");
    SetXrayShader = OFFSET("0x4D317F0");
    addWeapon = OFFSET("0x182CF1C");
    DeserializeObject = OFFSET("0x495ED5C"); // DONT USE IL2CPP API ON THIS AS IT WILL BREAK
    Storager$$setInt = OFFSET("0x374F410");
    tutorialInstance = OFFSET("0x370A14C");
    fillTutorial1 = OFFSET("0x3724600");
    fillTutorial2 = OFFSET("0x223B378");
    banAccount = OFFSET("0x45A8A9C");
    ShotPressed = OFFSET("0x4D6F1C0");
    IsTargetVisible = OFFSET("0x4D476F4");
    isInMatch = OFFSET("0x38D2174");
    winInSpleef = OFFSET("0x4ED84D4"); // search "PlayerScoreController myScoreController = WeaponManager." in networkstarttable its that method
    addToScore = OFFSET("0x4ED00E8"); // search "internal RatingSystem." in networkstarttable its 2 methods above that (one with int param)
    addclanlevel = OFFSET("0x599EC8C"); //remove this its replaced by ws
    set_master = OFFSET("0x5CC7048");
    setAuthSecret = OFFSET("0x3D18A28");
    setAuthInfo = OFFSET("0x3D18838");
    setAuthID = OFFSET("0x566AA08");
    getAuthSecret = OFFSET("0x3D188A8");
    getAuthInfo = OFFSET("0x3D18808");
    getAuthURL = OFFSET("0x3D187D8");
    getAuthID = OFFSET("0x566A8D4");
    AuthInstance = OFFSET("0x3D18D78");
    PhotonView$RPC = OFFSET("0x57BDBD8");
    get_playerCamera = OFFSET("0x4D0635C");
    get_OfferItemType = OFFSET("0x2D83AAC");
    SetPlayerSpeed = OFFSET("0x4D813DC");
    DisablePlayerJump = OFFSET("0x4D86088");
    get_photonName = OFFSET("0x57B9AD4");
    get_photonID = OFFSET("0x57B9ACC");
    webInstance = OFFSET("0x598810C");
    addchestp = OFFSET("0x5995A74");
    LoadLevel =  OFFSET("0x57B94CC");//search LoadScene
    PhotonNetwork_playerListothers = OFFSET("0x57B08B0");//same steps as localplayer, its the 2nd array, so below the first array method you see
    EnableJetpack = OFFSET("0x4D1CD20");//search for AddBonusAfterKillPlayerRPC, PhotonTargets.Others in player_move_c
    AddMessage = OFFSET("0x4D0CC1C"); // search in player_move_c for methods with arguments "string, float, int, int, string", analyze and it should be the second method, with arguments "string, string" and it uses weaponmanager
    JsonConvert$$SerializeObject = OFFSET("0x495E2D4");
    sendCommand = OFFSET("0x3F0C088");
    Encoding$$GetString = OFFSET("0x3891400");
    Encoding$$GetBytes = OFFSET("0x38905B0");
    get_RoyaleList = OFFSET("0x4487C2C");
    get_royaleInstance = OFFSET("0x2B3DE50");
    hasRoyaleItem = OFFSET("0x5DF5F84");
    get_petsList = OFFSET("0x4648548");
    localPhotonPlayer = OFFSET("0x57B05A0");

    // patches that are automatically updated
    get_AmmoInClip = OFFSET_IL2CPP("", "ItemRecord", "get_AmmoInClip", 0);
    get_MaxAmmo = OFFSET_IL2CPP("", "ItemRecord", "get_MaxAmmo", 0);
    get_IsUnlimitedAmmo = OFFSET_IL2CPP("", "ItemRecord", "get_IsUnlimitedAmmo", 0);
    get_InitialAmmo = OFFSET_IL2CPP("", "ItemRecord", "get_InitialAmmo", 0);
    get_isEditor = OFFSET_IL2CPP("UnityEngine", "Application", "get_isEditor", 0);
    get_platform = OFFSET_IL2CPP("UnityEngine", "Application", "get_platform", 0);
    get_AnyLogEnabled = OFFSET_IL2CPP("", "LogController", "get_AnyLogEnabled", 0);
    get_Energy = OFFSET_IL2CPP("", "PlaceableItemSettings", "get_Energy", 0);
    get_Available = OFFSET_IL2CPP("Rilisoft", "LobbyItemsBundle", "get_Available", 0);
    get_NextUpPower = OFFSET_IL2CPP("", "PlaceableItemSettings", "get_NextUpPower", 0);
    OnTriggerEnter = OFFSET_IL2CPP("", "SkinName", "OnTriggerEnter", 1);
    OnControllerColliderHit = OFFSET_IL2CPP("", "SkinName", "OnControllerColliderHit", 1);
    MinusLive = OFFSET_IL2CPP("", "TurretController", "MinusLive", 2);
    MinusLiveReal = OFFSET_IL2CPP("", "TurretController", "MinusLiveReal", 3);
    MinusLive2 = OFFSET_IL2CPP("", "ChestController", "MinusLive", 1);
    NextHitCritical = OFFSET_IL2CPP("", "WeaponSounds", "NextHitCritical", 0);
    get_RespawnTime = OFFSET_IL2CPP("", "PetInfo", "get_RespawnTime", 0);
    ValidateNickName = OFFSET_IL2CPP("", "NickNameValidator", "ValidateNickName", 1);
    ValidateNickNameNoAnalytics = OFFSET_IL2CPP("", "NickNameValidator", "ValidateNickNameNoAnalytics", 1);
    GetRequiredState = OFFSET_IL2CPP("", "UAds", "GetRequiredState", 0);
    InhouseAnalyticsController$$Awake = OFFSET_IL2CPP("PGCompany.Analytics", "InhouseAnalyticsController", "Awake", 0);
    InhouseAnalyticsController$$Start = OFFSET_IL2CPP("PGCompany.Analytics", "InhouseAnalyticsController", "Start", 0);
    SendAnalytics = OFFSET_IL2CPP("", "NetworkStartTableNGUIController", "SendAnalytics", 0);
    CustomHungerBase$$Awake = OFFSET_IL2CPP("", "CustomHungerBase", "Awake", 0);
    CustomHungerBase = OFFSET_IL2CPP("", "CustomHungerBase", ".ctor", 0);
    CoinsMessage$$Start = OFFSET_IL2CPP("", "CoinsMessage", "Start", 0);
    NotificationController$$Update = OFFSET_IL2CPP("", "NotificationController", "Update", 0);

    // pointers that are automatically updated
    PhotonView$Get = OFFSET_IL2CPP("", "PhotonView", "Get", 1); // OFFSET("0x57BDDE0");
    RequestOwnership = OFFSET_IL2CPP("", "PhotonView", "RequestOwnership", 0); // OFFSET("0x57BC88C");
    SendInviteToPlayer =  OFFSET_IL2CPP("", "SquadController", "SendInviteToPlayer", 1); // OFFSET("0x1BFEB74");
    PD$$GetTransform = OFFSET_IL2CPP("", "PlayerDamageable", "get_transform", 0); // OFFSET("0x4EE6530");
    GetNameInternal = OFFSET_IL2CPP("UnityEngine.SceneManagement", "Scene", "GetNameInternal", 1); // OFFSET("0x52ED16C");
    GetActiveScene = OFFSET_IL2CPP("UnityEngine.SceneManagement", "SceneManager", "GetActiveScene", 0); // OFFSET("0x52ECE9C");
    PhotonView$IsMine = OFFSET_IL2CPP("", "PhotonView", "get_isMine", 0); // OFFSET("0x57BC618");
    Camera_WorldToScreenPoint = OFFSET_IL2CPP("UnityEngine", "Camera", "WorldToScreenPoint", 1); // OFFSET("0x4E7C918");
    setEnabledConsole = OFFSET_IL2CPP("", "DebugConsole", "set_Enabled", 1); // OFFSET("0x3B7F278");
    setInt = OFFSET_IL2CPP("UnityEngine", "PlayerPrefs", "SetInt", 2); // OFFSET("0x4E621D4");
    Component$get_object = OFFSET_IL2CPP("UnityEngine", "Component", "get_gameObject", 0); // OFFSET("0x4EB9394");
    BaseCamera$$Camera = OFFSET_IL2CPP("", "BaseCamera", "get_camera", 0); // OFFSET("0x5008968");
    get_position = OFFSET_IL2CPP("UnityEngine", "Transform", "get_position", 0); // OFFSET("0x4EC57B0");
    set_position = OFFSET_IL2CPP("UnityEngine", "Transform", "set_position", 1); // OFFSET("0x4EC5850");
    get_rotation = OFFSET_IL2CPP("UnityEngine", "Transform", "get_rotation", 0); // OFFSET("0x4EC5A48");
    set_local_scale = OFFSET_IL2CPP("UnityEngine", "Transform", "set_localScale", 1); // OFFSET("0x4EC5FD0");
    targetFrameRate = OFFSET_IL2CPP("UnityEngine", "Application", "set_targetFrameRate", 1); // OFFSET("0x4EC4904");
    getTargetFrameRate = OFFSET_IL2CPP("UnityEngine", "Application", "get_targetFrameRate", 0); // OFFSET("0x4EC48DC");
    SendChat = OFFSET_IL2CPP("", "Player_move_c", "SendChat", 3); // OFFSET("0x4D16548");//search SendChat
    Component$get_transform = OFFSET_IL2CPP("UnityEngine", "Component", "get_transform", 0); // OFFSET("0x4EB9358");
    ShowToast = OFFSET_IL2CPP("Prime31", "EtceteraAndroid", "showToast", 2); // OFFSET("0x5616B2C");
    IsEnemyTo = OFFSET_IL2CPP("", "PlayerDamageable", "IsEnemyTo", 1); // OFFSET("0x4EE7818");
    float$$TryParse = OFFSET_IL2CPP("System", "Single", "TryParse", 2); // OFFSET("0x5A244A8");
    float$$Parse = OFFSET_IL2CPP("System", "Single", "Parse", 1); // OFFSET("0x5A2425C");
    Transform$$forward = OFFSET_IL2CPP("UnityEngine", "Transform", "get_forward", 0); // OFFSET("0x4EC5D90");
    string$$Replace = OFFSET_IL2CPP("System", "String", "Replace", 2); // OFFSET("0x4F4DCBC");
    string$$Concat = OFFSET_IL2CPP("System", "String", "Concat", 2); // OFFSET("0x4F3F06C");
    string$$ToLower = OFFSET_IL2CPP("System", "String", "ToLower", 0); // OFFSET("0x4F501F0");
    string$$Substring2 = OFFSET_IL2CPP("System", "String", "Substring", 1); // OFFSET("0x4F500A0");
    Resources$$Load = OFFSET_IL2CPP("UnityEngine", "Resources", "Load", 2); // OFFSET("0x4EC3754");
    Type$$GetType = OFFSET_IL2CPP("System", "Type", "GetType", 2); // OFFSET("0x5A2D178");
    GameObject$$Instantiate = OFFSET_IL2CPP("UnityEngine", "Object", "Instantiate", 3); // OFFSET("0x4EB4C40");
    Resources$$FindObjectsOfTypeAll = OFFSET_IL2CPP("UnityEngine", "ResourcesAPIInternal", "FindObjectsOfTypeAll", 1); // OFFSET("0x4EB596C");
    Object$$get_name = OFFSET_IL2CPP("UnityEngine", "Object", "get_name", 0); // OFFSET("0x4EB4B78");
    string$$Equals = OFFSET_IL2CPP("System", "String", "Equals", 2); // OFFSET("0x4F4B874");
    InGameGUI$$SetInterfaceVisible = OFFSET_IL2CPP("", "InGameGUI", "SetInterfaceVisible", 2); // OFFSET("0x2E82D20");
    GameObject$$SetActive = OFFSET_IL2CPP("UnityEngine", "GameObject", "SetActive", 1); // OFFSET("0x4E8257C");
	GameObject$$GetActive = OFFSET_IL2CPP("UnityEngine", "GameObject", "get_active", 0); // OFFSET("0x4E8257C");
    GameObject$$AddComponent = OFFSET_IL2CPP("UnityEngine", "GameObject", "AddComponent", 1); // OFFSET("0x4E82438");
    GameObject$$GetComponent = OFFSET_IL2CPP("UnityEngine", "GameObject", "GetComponent", 1); // OFFSET("0x4E68298");
    string$$Contains = OFFSET_IL2CPP("System", "String", "Contains", 1); // OFFSET("0x4F50904");
    Object$$DontDestroyOnLoad = OFFSET_IL2CPP("UnityEngine", "Object", "DontDestroyOnLoad", 1); // OFFSET("0x4EB5720");
    GameObject$$get_tag = OFFSET_IL2CPP("UnityEngine", "GameObject", "get_tag", 0); // OFFSET("0x4E826B8");
    OpenURL = OFFSET_IL2CPP("UnityEngine", "Application", "OpenURL", 1); // OFFSET("0x4EC48A0");
    get_UTF8 = OFFSET_IL2CPP("System.Text", "Encoding", "get_UTF8", 0); // OFFSET("0x388DD3C");
}

// add pointers here for non auth'ed users
void Pointers2() {
    OpenURL = OFFSET_IL2CPP("UnityEngine", "Application", "OpenURL", 1); // OFFSET("0x4EC48A0");
}