#pragma once
#include "../Include/picosha2.h"

/*
*  Created by lbert on 2/13/2023
*  Updated/Remade by Acessor 29/05/2023
*  Updated by Acessor 05/06/2023
*  Updated by Pulsed 6/08/2023
*  why the fuck are we adding whos changing you fucking retards
*  for real
*/

#include "curl/curl.h"
#include "json.hpp"
#include "base64.hpp"
#include "guid.hpp"

// Activation check
bool isVerifed;

// Stuff for the protocol
std::string sniff_msg = OBFUSTR("Stop sniffing me and go touch some grass!");
std::string enc_key = OBFUSTR("ReallySecureTrustMe");

// Keyauth credendials
std::string name = OBFUSTR("Stardust");
std::string ownerid = OBFUSTR("dQuvjgCnUs");
std::string subscription = OBFUSTR("default");
std::string secret = OBFUSTR("1d2948d2593df8be8bf190efd59a68398882d926bb08e991d871403b647cfa25");
std::string host = OBFUSTR("https://modfs.dev"); // OBFUSTR("http://localhost");
std::string webhook_url = OBFUSTR("https://discord.com/api/webhooks/1163411411607769098/Oc4Og23dCASvlWfjTSGz3gwncTAZZQbydHpRvWOLZsoO8XKD9xoTVTB2vyBXsTJpfoW9");
std::string enckey, status, sessionid, expiry, hwid, guid, licuser;

std::string xor_str(const std::string& data, const std::string& key) {
    std::string result;
    for (int a = 0; a < data.length(); a += key.length())
        for (int b = 0; b < key.length(); b++)
            if ((a + b) < data.length())
                result += data[a+b] ^ (key[b] + (a+b));
    return result;
}

std::string rand_str(int length) {
    srand (time (NULL) % (intptr_t)&length); // yeah I seed random with ptr address 💀
    std::string charset = OBFUSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"),
            result;
    for (int i = 0; i < length; i++)
        result += charset[rand() % (charset.length() - 1)];
    return result;
}

inline std::string hexval(int value) {
    char hex[16];
    sprintf(hex, OBFUSTR("%X"), value);
    return std::string(hex);
}

std::string epoch_to_utc(std::string epoch) {
    long temp = stol(epoch);
    const time_t old = (time_t)temp;
    struct tm *oldt = gmtime(&old);
    return asctime(oldt);
}

inline uint32_t adler32(const std::string& str) {
    const uint32_t kModulus = 65521;
    uint32_t a = 1, b = 0;
    for (const char& c : str) {
        a = (a + c) % kModulus;
        b = (b + a) % kModulus;
    }
    return (b << 16) | a;
}

std::string encrypt_packet(std::string packet) {
    auto body = nlohmann::json::parse("{}");
    body[OBFUSTR("message")] = sniff_msg;
    body[OBFUSTR("data")] = base64::to_base64(xor_str(packet, enc_key));
    return body.dump();
}

std::string decrypt_packet(std::string packet) {
    auto body = nlohmann::json::parse(packet);
    if (body != NULL && body[OBFUSTR("data")] != NULL) {
        return xor_str(base64::from_base64(body[OBFUSTR("data")]), enc_key);
    } else {
        return packet; // invalid
    }
}

size_t write_callback(char *ptr, size_t size, size_t nmemb, std::string *data) {
    size_t bytes = size * nmemb;
    data->append(ptr, bytes);
    return bytes;
}

std::string http_post(const std::string& url, const std::string& data) {
    CURL* curl = curl_easy_init();
    std::string response_data;
    if (!curl) {
        LOGE("%s", OBFUSTR("Failed to initialize curl"));
        return response_data;
    }
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, OBFUSTR("Content-Type: application/json"));
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        LOGE(OBFUSTR("curl_easy_perform() failed: %s"), curl_easy_strerror(res));
    } else {
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        /* LOGI(OBFUSTR("curl_easy_perform()\nRequest: %s,\nResponse data: %s\nCode: %ld"),data.c_str(), response_data.c_str(),
             response_code); */
    }
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    return response_data;
}

/* if we don't use this discord won't allow to pass
some symbols in the POST and it will be 400 bad request */
std::string unicode_escape(const std::string& str) {
    std::ostringstream escaped;
    escaped << std::hex << std::setfill('0');
    for (char c : str) {
        escaped << "\\u";
        escaped << std::setw(4) << static_cast<unsigned int>(c);
    }
    return escaped.str();
}

void webhook_log(const std::string& message) {
    http_post(webhook_url,  OBFUSTR("{\"content\":\"") + unicode_escape(message) + OBFUSTR("\"}"));
}

inline std::string get_sessionid() {
    auto post_body = nlohmann::json::parse("{}");
    post_body[OBFUSTR("type")] = OBFUSTR("init");
    post_body[OBFUSTR("ver")] = OBFUSTR("1.0");
    post_body[OBFUSTR("name")] = name;
    post_body[OBFUSTR("ownerid")] = ownerid;
    post_body[OBFUSTR("enckey")] = enckey;
    std::string encryptedRawdata = encrypt_packet(post_body.dump());
    std::string response = http_post(host + OBFUSTR("/api/1.3/"), encryptedRawdata);
    std::string decryptedResponse = decrypt_packet(response);
    auto respJson = nlohmann::json::parse(decryptedResponse);
    if (respJson != NULL && respJson[OBFUSTR("success")] == true)
        return respJson[OBFUSTR("sessionid")];
    return NULL;
}

inline bool login(std::string username, std::string password) {
    sessionid = get_sessionid();
    if (sessionid.empty())
        return false;
    auto post_body = nlohmann::json::parse("{}");
    std::string salt = rand_str(5);
    int hash = adler32(salt);
    post_body[OBFUSTR("type")] = OBFUSTR("login");
    post_body[OBFUSTR("username")] = username;
    post_body[OBFUSTR("pass")] = password;
    post_body[OBFUSTR("sessionid")] = sessionid;
    post_body[OBFUSTR("name")] = name;
    post_body[OBFUSTR("ownerid")] = ownerid;
    post_body[OBFUSTR("hwid")] = hwid;
    post_body[OBFUSTR("salt")] = salt;
    std::string encryptedRawdata = encrypt_packet(post_body.dump());
    std::string response = http_post(host + OBFUSTR("/api/1.3/"), encryptedRawdata);
    std::string decryptedResponse = decrypt_packet(response);
    auto respJson = nlohmann::json::parse(decryptedResponse);
    if (respJson != NULL) {
        if (respJson[OBFUSTR("hash")] != hash) {
            webhook_log(OBFUSTR("A request tampering attempt (possibly), hardware ID: ") + hwid);
            status = OBFUSTR("Stop tampering the requests :skull:");
            return false;
        }
        if (respJson[OBFUSTR("success")] != true) {
            status = respJson[OBFUSTR("message")];
            return false;
        }
        licuser = respJson[OBFUSTR("info")][OBFUSTR("username")];
        for (auto& element : respJson[OBFUSTR("info")][OBFUSTR("subscriptions")]) {
            if (element[OBFUSTR("subscription")] != NULL && element[OBFUSTR("subscription")] == subscription) {
                expiry = epoch_to_utc(element[OBFUSTR("expiry")]);
                return OBFUSINT(true);
            }
        }
    }
    return false;
}

bool logout() {
    if (sessionid.empty())
        return OBFUSINT(false);
    std::remove(OBFUSTR("/storage/emulated/0/Android/data/com.pixel.gun3d/account.txt"));
    auto post_body = nlohmann::json::parse("{}");
    post_body["type"] = OBFUSTR("logout");
    post_body["sessionid"] = sessionid;
    post_body["name"] = name;
    post_body["ownerid"] = ownerid;
    std::string encryptedRawData = encrypt_packet(post_body.dump());
    std::string response = http_post(host + OBFUSTR("/api/1.3/"), encryptedRawData);
    std::string decryptedResponse = decrypt_packet(response);
    auto respJson = nlohmann::json::parse(decryptedResponse);
    if (respJson != NULL && respJson[OBFUSTR("success")] == true)
        return true;
    return false;
}

std::string findBuildString(const char* str, JNIEnv *env) {
    jboolean isCopy;
    jclass build_class = env->FindClass(OBFUSTR("android/os/Build"));
    jfieldID id = env->GetStaticFieldID(build_class, str, OBFUSTR("Ljava/lang/String;"));
    jstring brand_obj = (jstring)env->GetStaticObjectField(build_class, id);
    const char *convertedValue = (env)->GetStringUTFChars(brand_obj, &isCopy);
    return convertedValue;
}

std::string get_hardware_id(JNIEnv *env) {
    std::string result =
    findBuildString(OBFUSTR("BOARD"), env) +
    findBuildString(OBFUSTR("BRAND"), env) +
    findBuildString(OBFUSTR("DISPLAY"), env) +
    findBuildString(OBFUSTR("DEVICE"), env) +
    findBuildString(OBFUSTR("MANUFACTURER"), env) +
    findBuildString(OBFUSTR("MODEL"), env) +
    findBuildString(OBFUSTR("PRODUCT"), env) +
    findBuildString(OBFUSTR("FINGERPRINT"), env) +
    findBuildString(OBFUSTR("HARDWARE"), env) +
    findBuildString(OBFUSTR("ID"), env);
    std::string hash_hex_str;
    picosha2::hash256_hex_string(result, hash_hex_str);
    return hash_hex_str;
}

std::string xor_shift(const std::string& data, const std::string& key) {
    std::string result;
    for (int a = 0; a < data.length(); a += key.length())
        for (int b = 0; b < key.length(); b++)
            if ((a + b) < data.length())
                result += data[a+b] ^ (key[b] + (a+b));
    return result;
}

struct msg {
    std::string message;
    std::string author;
    std::string timestamp;
};

std::vector<msg> chatget(std::string channel) {
    sessionid = get_sessionid();
    CURL *hnd = curl_easy_init();
    std::string response_data;
    long response_code;
    std::ostringstream stream;
    stream << OBFUSTR("https://modfs.dev/api/1.2/?type=chatget&channel=") << channel << OBFUSTR("&sessionid=") <<
              sessionid << OBFUSTR("&name=") << name << OBFUSTR("&ownerid=") << ownerid;
    std::string URL = stream.str();
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(hnd, CURLOPT_URL, URL.c_str());
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &response_data);
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(hnd, CURLOPT_USE_SSL, CURLUSESSL_ALL);
    curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYHOST, 1);
    CURLcode ret = curl_easy_perform(hnd);
    curl_easy_getinfo(hnd, CURLINFO_RESPONSE_CODE, &response_code);
    auto json = nlohmann::json::parse(response_data);
    std::vector<msg> buff;
    if (json[OBFUSTR("success")]) {
        for (const auto message : json[OBFUSTR("messages")]) {
            buff.push_back(msg{ message[OBFUSTR("message")],message[OBFUSTR("author")] ,message[OBFUSTR("timestamp")] });
        }
        return buff;
    } else {
        return buff;
    }
    curl_easy_cleanup(hnd);
}

bool chatsend(std::string message, std::string channel) {
    sessionid = get_sessionid();
    CURL *hnd = curl_easy_init();
    std::string response_data;
    long response_code;
    std::ostringstream stream;
    stream << OBFUSTR("https://modfs.dev/api/1.2/?type=chatsend&channel=") << channel << OBFUSTR("&sessionid=") <<
    sessionid << OBFUSTR("&name=") << name << OBFUSTR("&ownerid=") << ownerid << OBFUSTR("&message=") << message;
    std::string URL = stream.str();
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(hnd, CURLOPT_URL, URL.c_str());
    curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &response_data);
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(hnd, CURLOPT_USE_SSL, CURLUSESSL_ALL);
    curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYHOST, 1);
    CURLcode ret = curl_easy_perform(hnd);
    curl_easy_getinfo(hnd, CURLINFO_RESPONSE_CODE, &response_code);
    auto json = nlohmann::json::parse(response_data);
	if (json[OBFUSTR("success")]) {
		return OBFUSINT(true);
	} else {
		return OBFUSINT(false);
	}
    curl_easy_cleanup(hnd);
}

// OLD AUTH HERE (DEPRECATED)

/* BE SURE TO ADD YOUR DEVICE ID HERE!!!
this is deprecated, but I won't delete it just for the memories */
std::vector<std::string> uuid_whitelist = {
        OBFUSTR("8e69fda98c9a6e748c24b3669eb751a0"), // UnknwonUser 100% no leak no cap
        OBFUSTR("92e396439b38fb3024a7d03f39d6b0ab"), // ac3ss0r (don't leak)
        OBFUSTR("14fdf09c06056bbd17e9a8e5713572eb"), // fedes1to (wtf ofc no leak)
        OBFUSTR("e4897241391260a7b593cff71ac43cc1"), // oh my faggot (sex)
        OBFUSTR("b5e1192bf8f452588d080d631b61ab88"), // verifed matt (leaking resulted in balls decapitation)
        OBFUSTR("83a09aafa32fc9d499f040877c478650"), // Hussain (don't leak)
        OBFUSTR("a31ef921b9d7d09c52e8a0e3456d39ce"), // Pulsed (gock gock 3000 machine sex slave)
        OBFUSTR("4fdc95906c42fd308c25bd8bf60c2bac"),  // BowedKawma (furries united)
        OBFUSTR("FF0F1679-8021-4B47-A6F5-298C4E781193"), // YeetDisDude (fuck android users) WHY THE FUCK DID YOU ADD YOUR UUID
        OBFUSTR("a52c6200651bffcff2dc1aaed36d8329") // sexultima
};

/* 100% anti-jewminazi protection DEPRECATED
void verifyDeviceOld() {
    std::string hwidStr = GetDeviceUniqueIdentifier()->getString(),
            nickStr = GetPlayerNickname()->getString(),
            playerID = GetPlayerID()->getString();
    std::stringstream msg;
    isVerifed = hwid_valid(hwidStr);
    msg << OBFUSTR("## **Stardust loaded!**\n- Device ID: ") << hwidStr
        << OBFUSTR("\n- HWID Valid: ") << isVerifed
        << OBFUSTR("\n- Player ID: ") << playerID
        << OBFUSTR("\n- Nickname: ") << nickStr;
    webhook_log( msg.str());
    if (!isVerifed)
        exit(0);
}*/
