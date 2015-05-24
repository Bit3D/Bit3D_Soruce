#pragma once

#ifndef _INCLUDES_H
#define _INCLUDES_H

#include<Windows.h>
#include<windowsx.h>
#include<D3D11.h>
#include<D3DX11.h>
#include<D3DX10math.h>
#include<xnamath.h>
#include<vector>
#include"Common.h"
#include<map>

#define MemSecure(N) SecureZeroMemory(&N,sizeof(N))
#define RELEASE(N) if(N){ N->Release();}

#endif