/* FUN_80162fbc
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162fbc  body 0x80162fbc..0x8016332b  size 880 B
 * body sha256 1c72d87a0d49ffc37673bacb98ed8dc3d36a5ab63643f261b2242b755dbe498b
 * provider record sha256 020e6e4029edc8533f3a1cf92b44abfe5861079190a6a04aa8f757c8af7696e5
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162fbc(int param_1)

{
  short sVar3;
  short sVar4;
  int iVar1;
  uint uVar2;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x28c);
  sVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  sVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x514);
  if (*(char *)(param_1 + 0x2da) == '\0') {
    if ((((*(uint *)(param_1 + 0x290) & 0xc0000000) != 0) &&
        ((*(uint *)(param_1 + 0x290) & 0x3fffffff) < 2000)) &&
       (iVar1 = func_0x80032f64(param_1,(int)*(short *)(param_1 + 0x294),0x100), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x10e0000;
      return;
    }
    if (((*(char *)(param_1 + 0x2da) == '\0') && (sVar4 == 0)) &&
       ((uVar5 < 2000 && ((*(char *)(param_1 + 0x1a2) != DAT_800e12d2 && (DAT_800e139f == 0)))))) {
      *(undefined4 *)(param_1 + 4) = 0x10e0000;
    }
  }
  if ((((int)*(short *)(param_1 + 0x270) & 0xc000U) != 0) && ((*(uint *)(param_1 + 0x1ac) & 1) != 0)
     ) {
    *(undefined4 *)(param_1 + 4) = 0x10a0000;
  }
  if ((((uVar5 < 0xdac) && (sVar3 != 0)) && ((_DAT_800e112a & 0x15) != 0)) &&
     (uVar2 = func_0x80033604(), (uVar2 & 3) == 0)) {
    *(undefined4 *)(param_1 + 4) = 0x10c0000;
  }
  if (((uVar5 < 0x9c4) && (sVar3 != 0)) &&
     (((_DAT_800e112a & 0x17) != 0 && (uVar2 = func_0x80033604(), (uVar2 & 1) == 0)))) {
    *(undefined4 *)(param_1 + 4) = 0x10c0000;
  }
  if (DAT_800e1138 == '\x0f') {
    if (((*(char *)(param_1 + 0x2da) == '\0') && (sVar4 == 0)) &&
       ((uVar5 < 2000 && (DAT_800e139f == 0)))) {
      *(undefined4 *)(param_1 + 4) = 0x10e0000;
    }
  }
  else if (((uVar5 < 0x4b0) && ((DAT_800e139f & 0x80) == 0)) &&
          (*(char *)(param_1 + 0x1a2) == DAT_800e12d2)) {
    if (((*(ushort *)(param_1 + 0x2b6) & 0x20) == 0) &&
       (iVar1 = func_0x80032fac(param_1 + 0x28,&DAT_800e1158,
                                (int)((*(ushort *)(param_1 + 0x66) + 0x100) * 0x10000) >> 0x10),
       iVar1 == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
    if (((*(ushort *)(param_1 + 0x2b6) & 0x40) == 0) &&
       (iVar1 = func_0x80032fac(param_1 + 0x28,&DAT_800e1158,
                                (int)((*(ushort *)(param_1 + 0x66) - 0x100) * 0x10000) >> 0x10,0x100
                               ), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
  }
  if (((_DAT_800e1322 == -0x8000) && (sVar4 == 0)) && (uVar5 < 1000)) {
    *(undefined4 *)(param_1 + 4) = 0x1080600;
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x4000;
  }
  return;
}
