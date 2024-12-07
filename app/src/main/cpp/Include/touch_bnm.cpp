#include "ByNameModding/BNM.hpp"
#include "../ImGui/imgui.h"
#include <cmath>

namespace Input {
    bool isEmulator;

    void setEmulator() {
        isEmulator = true;
    }

    enum TouchPhase {
        Began,
        Moved,
        Stationary,
        Ended,
        Canceled
    };

    enum TouchType {
        Direct,
        Indirect,
        Stylus
    };

    using namespace BNM::UNITY_STRUCTS;

    struct Touch {
        int m_FingerId{};
        Vector2 m_Position;
        Vector2 m_RawPosition;
        Vector2 m_PositionDelta;
        float m_TimeDelta{};
        int m_TapCount{};
        TouchPhase m_Phase{};
        TouchType m_Type{};
        float m_Pressure{};
        float m_maximumPossiblePressure{};
        float m_Radius{};
        float m_RadiusVariance{};
        float m_AltitudeAngle{};
        float m_AzimuthAngle{};
    };


    static BNM::LoadClass Input;
    static BNM::Method<Touch> GetTouch;
    static BNM::Method<bool> GetMouseButtonDown;

    Touch (*old_FakeGetTouch)(int index);

    Touch FakeGetTouch(int index) {
        Touch _touch = old_FakeGetTouch(index);

        if (!isEmulator)
            return _touch;

        if (index == 0) {
            ImGuiIO &io = ImGui::GetIO();
            float x = _touch.m_Position.x;
            float y = static_cast<float>(std::round(io.DisplaySize.y)) - _touch.m_Position.y;

            if (_touch.m_Phase == TouchPhase::Began) {
                io.AddMousePosEvent(x, y);
                io.AddMouseButtonEvent(0, Input::GetMouseButtonDown(0));
            }
            if (_touch.m_Phase == TouchPhase::Moved) {
                io.AddMousePosEvent(x, y);
            }
            if (_touch.m_Phase == TouchPhase::Ended) {
                io.AddMouseButtonEvent(0, Input::GetMouseButtonDown(0));
                io.AddMouseButtonEvent(1, Input::GetMouseButtonDown(1));
                io.AddMouseButtonEvent(2, Input::GetMouseButtonDown(3));
            }

            if (io.WantCaptureMouse)
                return old_FakeGetTouch(-1);
        }

        return _touch;
    }

    void Attach() {
        BNM::AttachIl2Cpp();
    }

    void Detach() {
        BNM::DetachIl2Cpp();
    }

    void Setup()
    {
        Input = BNM::LoadClass("UnityEngine", "Input");
        GetTouch = Input.GetMethodByName("GetTouch", 1);
        GetMouseButtonDown = Input.GetMethodByName("GetMouseButtonDown", 1);
        HOOK(GetTouch.GetOffset(), FakeGetTouch, old_FakeGetTouch);
    }
}