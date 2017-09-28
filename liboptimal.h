#pragma once

#include <stdint.h>
#include <stdio.h>

#ifdef __linux__

#include <string.h>

#else

#include "stm32f4xx.h"
#include <string.h>

#undef printf
#define printf(...)

#endif

// IFACE
typedef struct _stbp    { uint8_t *p; uint8_t msk; } stbp ;
typedef struct _stInfo  { int code, value; } stInfo;
typedef struct _strect  { uint16_t x1,y1,x2,y2; } strect;
typedef struct _stline  { uint16_t n; uint16_t l; } stline;
typedef struct _stfig   { uint16_t linescnt; uint16_t w; uint16_t h; uint16_t offs; uint16_t sx; uint16_t sy; uint16_t ex; uint16_t ey; } stfig;
typedef struct _stProps { uint16_t ws; uint16_t wx; uint16_t wy; uint16_t wt; int iw; int ih; void *_pmem; int _smem; } stProps;

void        EXTERNAL_GetImageSize(int *w, int *h);
int         EXTERNAL_GetPixels(int x, int y, int cnt, uint8_t *result);
void        EXTERNAL_Info(stProps *pInfo);

// void        OPATH_SetMemBlock(void *p, int s);
// void        OPATH_SetCellSize(int s);
uint8_t 	OPATH_StartScanningRoutine();
int		OPATH_GetObjectsCount();
int		OPATH_GetObjectRegions(int fn);
void        	OPATH_GetObjectPosition(int fn, int *x, int *y, int *xx, int *yy);
int         	OPATH_GetRectsTotal();
void        	OPATH_GetRegionRect(int fn, int n, int *x, int *y, int *w, int *h);
stline *    	OPATH_GetRegionCell(int fn, int n);
void 		Local_GetCellXY(int n, uint16_t *cx, uint16_t *cy);
void 		OPATH_Internal_Sort(stfig *pfig, stline *plines, int figcnt, uint8_t *po);

