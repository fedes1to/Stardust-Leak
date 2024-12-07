#ifndef LSTARDUST_INSPECTORVIEW_H
#define LSTARDUST_INSPECTORVIEW_H

namespace sceneExplorer
{
	namespace inspectorView
	{
		void Draw()
		{
			ImGui::SetNextWindowSize(ImVec2(530, 680), ImGuiCond_FirstUseEver);
			if (!ImGui::Begin("Inspector", nullptr))
			{
				ImGui::End();
				return;
			}

			ImGui::Separator();

			ImGui::BeginDisabled();
			if (objListDyn.empty() || !objListDyn[selectedGObj].obj) {
				ImGui::InputTextWithHint("##scn_insp_obj_nm", "Object is invalid!",
										 &empty_str_placeholder);
			}
			else {
				ImGui::InputTextWithHint("##scn_insp_obj_nm", "Object name",
										 &objListDyn[selectedGObj].name);
			}
			ImGui::EndDisabled();

			ImGui::Separator();

			if (Checkbox(OBFUSTR("Active"), &qCurObjActive)) {
				if (objListDyn.empty() || !objListDyn[selectedGObj].obj) return;
				GameObject$$SetActive(objListDyn[selectedGObj].obj, qCurObjActive);
			}
			EndListBox();
		}
	}
}

#endif //LSTARDUST_INSPECTORVIEW_H
