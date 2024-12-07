#ifndef LSTARDUST_HIERARCHYVIEW_H
#define LSTARDUST_HIERARCHYVIEW_H

namespace sceneExplorer
{
	namespace hierarchyView
	{
		void Draw()
		{
			ImGui::SetNextWindowSize(ImVec2(580, 700), ImGuiCond_FirstUseEver);
			if (!ImGui::Begin("Hierarchy", nullptr))
			{
				ImGui::End();
				return;
			}

			ImGui::Separator();

			ImGui::InputTextWithHint("##scn_hier_srch_qry", "Search in hierarchy", &explorerSearchQuery);
			ImGui::SameLine();
			if (ImGui::Button(OBFUSTR("Refresh")))
				updateObjList();

			ImGui::Separator();

			ImGui::BeginChild("##scn_hier_chld_holder", ImVec2(500, 480));
			{
				BeginListBox("##scn_hier", ImVec2(500, 480));
				int i = 0;
				for (gobj_inst obj: objListDyn) {
					std::string &item_name = obj.name;
					std::string &t = item_name;
					t += "##idx_" + std::to_string(i);
					if (!explorerSearchQuery.empty())
						if (!strstr(lowercase(item_name).c_str(),
									lowercase(explorerSearchQuery).c_str())) {
							i++;
							continue;
						}
					if (Selectable(t.c_str(), &obj.selected)) {
						selectedGObj = i;
					}
					i++;
				}
				EndListBox();
			}
			ImGui::EndChild();
		}
	}
}

#endif //LSTARDUST_HIERARCHYVIEW_H
