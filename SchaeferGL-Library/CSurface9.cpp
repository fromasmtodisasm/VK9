/*
Copyright(c) 2016 Christopher Joseph Dean Schaefer

This software is provided 'as-is', without any express or implied
warranty.In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions :

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software.If you use this software
in a product, an acknowledgement in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
 
#include "CSurface9.h"
#include "CDevice9.h"

CSurface9::CSurface9(CDevice9* Device,UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard,HANDLE *pSharedHandle)
	: mDevice(Device),
	mWidth(Width),
	mHeight(Height),
	mFormat(Format),
	mMultiSample(MultiSample),
	mMultisampleQuality(MultisampleQuality),
	mDiscard(Discard),
	mSharedHandle(pSharedHandle),
	mReferenceCount(0)
{
	//TODO: Implement.
}

CSurface9::~CSurface9()
{
	
}

ULONG STDMETHODCALLTYPE CSurface9::AddRef(void)
{
	mReferenceCount++;

	return mReferenceCount;
}

HRESULT STDMETHODCALLTYPE CSurface9::QueryInterface(REFIID riid,void  **ppv)
{
	//TODO: Implement.

	return E_NOTIMPL;
}

ULONG STDMETHODCALLTYPE CSurface9::Release(void)
{
	mReferenceCount--;

	if (mReferenceCount <= 0)
	{
		delete this;
	}

	return mReferenceCount;
}

HRESULT STDMETHODCALLTYPE CSurface9::FreePrivateData(REFGUID refguid)
{
	//TODO: Implement.

	return E_NOTIMPL;
}

DWORD STDMETHODCALLTYPE CSurface9::GetPriority()
{
	//TODO: Implement.

	return 1;
}

HRESULT STDMETHODCALLTYPE CSurface9::GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
	//TODO: Implement.

	return E_NOTIMPL;
}

D3DRESOURCETYPE STDMETHODCALLTYPE CSurface9::GetType()
{
	//TODO: Implement.

	return D3DRTYPE_SURFACE;
}

void STDMETHODCALLTYPE CSurface9::PreLoad()
{
	//TODO: Implement.

	return; 
}

DWORD STDMETHODCALLTYPE CSurface9::SetPriority(DWORD PriorityNew)
{
	//TODO: Implement.

	return 1;
}

HRESULT STDMETHODCALLTYPE CSurface9::SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags)
{
	//TODO: Implement.

	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CSurface9::GetContainer(REFIID riid, void** ppContainer)
{
	//TODO: Implement.

	return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CSurface9::GetDC(HDC* phdc)
{
	//TODO: Implement.

	return E_NOTIMPL;
}


HRESULT STDMETHODCALLTYPE CSurface9::GetDesc(D3DSURFACE_DESC* pDesc)
{
	//TODO: Implement.

	return S_OK;	
}

HRESULT STDMETHODCALLTYPE CSurface9::LockRect(D3DLOCKED_RECT* pLockedRect, const RECT* pRect, DWORD Flags)
{
	//TODO: Implement.
	
	return S_OK;	
}


HRESULT STDMETHODCALLTYPE CSurface9::ReleaseDC(HDC hdc)
{
	//TODO: Implement.

	return E_NOTIMPL;
}


HRESULT STDMETHODCALLTYPE CSurface9::UnlockRect()
{
	//TODO: Implement.

	return S_OK;	
}