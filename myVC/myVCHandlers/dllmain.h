// dllmain.h: 模块类的声明。

class CmyVCHandlersModule : public ATL::CAtlDllModuleT< CmyVCHandlersModule >
{
public :
	DECLARE_LIBID(LIBID_myVCHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MYVCHANDLERS, "{744827FF-27E3-46C8-B9C8-AB622E65CD78}")
};

extern class CmyVCHandlersModule _AtlModule;
