namespace ExATKDataPlugin
{
	constexpr std::string_view ScriptName = "ExReplaceATKDataScript";

	void ReplaceATKData(RE::StaticFunctionTag*, RE::TESNPC* src, RE::TESNPC* dest)
	{
		if (!src || !dest) {
			REX::WARN("ReplaceATKData: source or destination ActorBase is None");
			return;
		}

		if (src == dest) {
			return;
		}

		auto* source = static_cast<RE::BGSAttackDataForm*>(src);
		auto* destination = static_cast<RE::BGSAttackDataForm*>(dest);

		destination->attackDataMap = source->attackDataMap;
	}

	bool RegisterPapyrusFunctions(RE::BSScript::IVirtualMachine* a_vm)
	{
		a_vm->RegisterFunction("ReplaceATKData", ScriptName, ReplaceATKData);
		return true;
	}
}



SKSE_PLUGIN_PRELOAD(const SKSE::PreLoadInterface* a_skse)
{
	SKSE::Init(a_skse);
	return true;
}

SKSE_PLUGIN_LOAD(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse);
	SKSE::GetPapyrusInterface()->Register(ExATKDataPlugin::RegisterPapyrusFunctions);
	REX::INFO("ExATKDataPlugin loaded");

	return true;
}
