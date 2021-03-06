/*
Copyright(c) 2016-2019 Christopher Joseph Dean Schaefer

This software is provided 'as-is', without any express or implied
warranty.In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions :

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software.If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
 
#ifndef NOMINMAX
#define NOMINMAX
#endif // NOMINMAX

#include "CVolumeTexture9.h"
#include "CDevice9.h"
#include "CSurface9.h"
#include "CVolume9.h"
#include "LogManager.h"
//#include "PrivateTypes.h"

CVolumeTexture9::CVolumeTexture9(CDevice9* device, UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, HANDLE *pSharedHandle)
	: mReferenceCount(1),
	mDevice(device),
	mWidth(Width),
	mHeight(Height),
	mDepth(Depth),
	mLevels(Levels),
	mUsage(Usage),
	mFormat(Format),
	mPool(Pool),
	mSharedHandle(pSharedHandle),
	mResult(VK_SUCCESS)
{
	Log(info) << "CVolumeTexture9::CVolumeTexture9" << std::endl;

	if (Usage & D3DUSAGE_AUTOGENMIPMAP)
	{
		mLevels = 1;
	}
	else if (!mLevels)
	{
		mLevels = (UINT)std::min(std::log2(std::max(mWidth, mHeight)) + 1.0, 10.0);
	}

	mVolumes.reserve(mLevels);
	UINT width = mWidth, height = mHeight, depth = mDepth;
	for (int32_t i = 0; i < (int32_t)mLevels; i++)
	{
		CVolume9* ptr = new CVolume9(device, this, width, height, depth, mUsage, mFormat, mPool, mSharedHandle);

		ptr->mMipIndex = i;

		mVolumes.push_back(ptr);

		width /= 2;
		height /= 2;
		depth /= 2;
	}
}

CVolumeTexture9::~CVolumeTexture9()
{
	Log(info) << "CVolumeTexture9::~CVolumeTexture9" << std::endl;

	for (int32_t i = 0; i < (int32_t)mVolumes.size(); i++)
	{
		mVolumes[i]->Release();
	}
}

ULONG STDMETHODCALLTYPE CVolumeTexture9::AddRef(void)
{
	return InterlockedIncrement(&mReferenceCount);
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::QueryInterface(REFIID riid,void  **ppv)
{
	if (ppv == nullptr)
	{
		return E_POINTER;
	}

	if (IsEqualGUID(riid, IID_IDirect3DVolumeTexture9))
	{
		(*ppv) = this;
		this->AddRef();
		return D3D_OK;
	}

	if (IsEqualGUID(riid, IID_IDirect3DTexture9))
	{
		(*ppv) = this;
		this->AddRef();
		return D3D_OK;
	}

	if (IsEqualGUID(riid, IID_IDirect3DResource9))
	{
		(*ppv) = this;
		this->AddRef();
		return D3D_OK;
	}

	if (IsEqualGUID(riid, IID_IUnknown))
	{
		(*ppv) = this;
		this->AddRef();
		return D3D_OK;
	}

	return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE CVolumeTexture9::Release(void)
{
	ULONG ref = InterlockedDecrement(&mReferenceCount);

	if (ref == 0 && mPrivateReferenceCount==0)
	{
		delete this;
	}

	return ref;
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::GetDevice(IDirect3DDevice9** ppDevice)
{ 
	mDevice->AddRef(); 
	(*ppDevice) = (IDirect3DDevice9*)mDevice; 
	return D3D_OK; 
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::FreePrivateData(REFGUID refguid)
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::FreePrivateData is not implemented!" << std::endl;

	return E_NOTIMPL;
}

DWORD STDMETHODCALLTYPE CVolumeTexture9::GetPriority()
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::GetPriority is not implemented!" << std::endl;

	return 1;
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::GetPrivateData is not implemented!" << std::endl;

	return E_NOTIMPL;
}

void STDMETHODCALLTYPE CVolumeTexture9::PreLoad()
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::PreLoad is not implemented!" << std::endl;

	return; 
}

DWORD STDMETHODCALLTYPE CVolumeTexture9::SetPriority(DWORD PriorityNew)
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::SetPriority is not implemented!" << std::endl;

	return 1;
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::SetPrivateData is not implemented!" << std::endl;

	return E_NOTIMPL;
}

VOID STDMETHODCALLTYPE CVolumeTexture9::GenerateMipSubLevels()
{

}

D3DTEXTUREFILTERTYPE STDMETHODCALLTYPE CVolumeTexture9::GetAutoGenFilterType()
{
	return mMipFilter;
}

DWORD STDMETHODCALLTYPE CVolumeTexture9::GetLOD()
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::GetLOD is not implemented!" << std::endl;

	return 0;
}

DWORD STDMETHODCALLTYPE CVolumeTexture9::GetLevelCount()
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::GetLevelCount is not implemented!" << std::endl;

	return 0;
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
	mMipFilter = FilterType; //revisit

	return D3D_OK;
}

DWORD STDMETHODCALLTYPE CVolumeTexture9::SetLOD(DWORD LODNew)
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::SetLOD is not implemented!" << std::endl;

	return 0;
}

D3DRESOURCETYPE STDMETHODCALLTYPE CVolumeTexture9::GetType()
{
	//return D3DRTYPE_SURFACE;
	//return D3DRTYPE_VOLUME;
	//return D3DRTYPE_TEXTURE;
	return D3DRTYPE_VOLUMETEXTURE;
	//return D3DRTYPE_CUBETEXTURE;
	//return D3DRTYPE_VERTEXBUFFER;
	//return D3DRTYPE_INDEXBUFFER;
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::AddDirtyBox(const D3DBOX* pDirtyBox)
{
	//TODO: Implement.

	Log(warning) << "CVolumeTexture9::AddDirtyBox is not implemented!" << std::endl;

	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::GetLevelDesc(UINT Level, D3DVOLUME_DESC* pDesc)
{
	return mVolumes[Level]->GetDesc(pDesc);
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::GetVolumeLevel(UINT Level, IDirect3DVolume9** ppVolumeLevel)
{
	IDirect3DVolume9* Volume = (IDirect3DVolume9*)this->mVolumes[Level];

	Volume->AddRef();

	(*ppVolumeLevel) = Volume;

	return D3D_OK;
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::LockBox(UINT Level, D3DLOCKED_BOX* pLockedVolume, const D3DBOX* pBox, DWORD Flags)
{
	return mVolumes[Level]->LockBox(pLockedVolume, pBox, Flags);
}

HRESULT STDMETHODCALLTYPE CVolumeTexture9::UnlockBox(UINT Level)
{
	return mVolumes[Level]->UnlockBox();
}

void CVolumeTexture9::Flush()
{
	for (int32_t i = 0; i < (int32_t)mVolumes.size(); i++)
	{
		mVolumes[i]->Flush();
	}
}
