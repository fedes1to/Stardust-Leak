#ifndef ImGuiAndroid_ESP
#define ImGuiAndroid_ESP

#include "../ImGui/imgui_internal.h"

namespace ESP {
    void DrawLine(ImVec2 start, ImVec2 end, ImVec4 color) {
        auto background = ImGui::GetBackgroundDrawList();
        if(background) {
            background->AddLine(start, end, ImColor(color.x,color.y,color.z,color.w));
        }
    }
    void DrawLine2(ImVec2 start, ImVec2 end, float thickness, ImVec4 color) {
        auto background = ImGui::GetBackgroundDrawList();
        if(background) {
            background->AddLine(start, end, ImColor(color.x,color.y,color.z,color.w), thickness);
        }
    }

    void DrawBox(float x, float y, float z, float w, ImVec4 color) {
        ImVec2 v1(x, y);
        ImVec2 v2(x + z, y);
        ImVec2 v3(x + z, y + w);
        ImVec2 v4(x, y + w);

        DrawLine(v1, v2, color);
        DrawLine(v2, v3, color);
        DrawLine(v3, v4, color);
        DrawLine(v4, v1, color);
    }

    void DrawBoxFilled(float x, float y, float z, float w, ImVec4 color) {
        auto background = ImGui::GetBackgroundDrawList();
        if(background) {
            background->AddRectFilled(ImVec2(x, y), ImVec2(z, w), ImColor(color.x,color.y,color.z,color.w), 0.0f);
        }
    }

    void DrawHealthBar(ImVec2 start, ImVec2 end, ImVec4 color, float width, float height, float health) {
        auto background = ImGui::GetBackgroundDrawList();
        int healthAmount = (height / 100) * health;

        //Health Bar
        background->AddRect({start.x + width, start.y}, {end.x + 10, end.y}, ImColor(color.x, color.y, color.z, color.w), 0, 0, 1.7f);
        background->AddRectFilled({start.x + width, start.y + height}, {end.x + 10, ((start.y + height) - healthAmount)}, ImColor(color.x, color.y, color.z, 0.7), 0, 0);
    }

    void DrawFilledRect(int x, int y, int w, int h, ImVec4 color) {
        auto background = ImGui::GetBackgroundDrawList();
        background->AddRectFilled(ImVec2(x, y - 1), ImVec2(x + w, y + h), ImColor(color.x,color.y,color.z, 0.07), 0, 0);
        background->AddRectFilled(ImVec2(x, y + 1), ImVec2(x + w, y + h), ImColor(color.x,color.y,color.z, 0.07), 0, 0);
        background->AddRectFilled(ImVec2(x - 1, y), ImVec2(x + w, y + h), ImColor(color.x,color.y,color.z, 0.07), 0, 0);
        background->AddRectFilled(ImVec2(x + 1, y), ImVec2(x + w, y + h), ImColor(color.x,color.y,color.z, 0.07), 0, 0);
        background->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(color.x,color.y,color.z,0.07), 0, 0);

        background->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(color.x,color.y,color.z, 1.0), 0, 0);
    }

    void DrawCircle(float X, float Y, float radius, bool filled, ImVec4 color) {
        auto background = ImGui::GetBackgroundDrawList();
        if(background) {
            if(filled) {
                background->AddCircleFilled(ImVec2(X, Y), radius, ImColor(color.x,color.y,color.z,color.w));
            } else {
                background->AddCircle(ImVec2(X, Y), radius, ImColor(color.x,color.y,color.z,color.w));
            }
        }
    }

    void DrawText(ImVec2 position, ImVec4 color, const char *text) {
        auto background = ImGui::GetBackgroundDrawList();
        if(background) {
            background->AddText(nullptr, 25.0f, position, ImColor(color.x,color.y,color.z,color.w), text);
        }
    }

    void DrawText2(ImVec2 position, ImVec4 color, const char *text) {
        auto background = ImGui::GetBackgroundDrawList();
        if(background) {
            background->AddText(nullptr, 40.0f, position, ImColor(color.x,color.y,color.z,color.w), text);
        }
    }

    void DrawText3(float fontSize, ImVec2 position, ImVec4 color, const char *text) {
        auto background = ImGui::GetBackgroundDrawList();
        if(background) {
            background->AddText(nullptr, fontSize, position, ImColor(color.x,color.y,color.z,color.w), text);
        }
    }

    void DrawBackground(ImVec2 start, ImVec2 end, ImVec4 color) {
        auto background = ImGui::GetBackgroundDrawList();
        background->AddRectFilled(start, end, ImColor(color.x,color.y,color.z, 0.7), 0, 0);
    }

    void DrawCrosshair(float screenWidth, float screenHeight, float size, ImVec4 color) {
        ESP::DrawLine2(ImVec2(screenWidth / 2, (screenHeight / 2) + size), ImVec2(screenWidth / 2, (screenHeight / 2) - size), 3, color);
        ESP::DrawLine2(ImVec2((screenWidth / 2) + size, screenHeight / 2), ImVec2((screenWidth / 2) - size, screenHeight / 2), 3, color);
    }
}

#endif