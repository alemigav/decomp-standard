/* FUN_800a924c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a924c  body 0x800a924c..0x800a941f  size 468 B
 * body sha256 eb1630c527935296a10d09e9983a9d040f53bfa434e4ba0132cdbdd590f5970c
 * provider record sha256 bf0b430cfd59bc14c199fbc485f030f838bf61eb7c9a15391077ec28b98d98cb
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800a924c(undefined1 param_1,undefined4 param_2,undefined4 param_3,uint param_4,byte param_5,
                byte param_6,byte param_7,byte param_8,undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  int iVar2;
  float fVar3;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  
  if (DAT_80136310 == '\0') {
    iVar1 = -1;
  }
  else {
    FUN_800a5678();
    iVar1 = FUN_800aedc0(param_1);
    if (iVar1 != -1) {
      iVar2 = iVar1 * 0x18;
      *(undefined4 *)(&DAT_801481e8 + iVar2) = param_2;
      *(undefined4 *)(&DAT_801481ec + iVar2) = param_3;
      *(undefined4 *)(&DAT_801481f0 + iVar2) = 0;
      *(undefined4 *)(&DAT_801481e4 + iVar2) = param_9;
      (&DAT_801481e0)[iVar2] = 1;
      *(undefined4 *)(&DAT_801481f4 + iVar2) = param_10;
      local_48 = param_4 | 0x400000;
      local_40 = 0;
      local_38 = 0;
      local_30 = 0;
      local_44 = param_2;
      local_3c = param_3;
      local_34 = param_3;
      FUN_800a54ec(iVar1,&local_48);
      if ((int)param_4 < 0) {
        fVar3 = (float)(int)param_4 + 4.2949673e+09;
      }
      else {
        fVar3 = (float)(int)param_4;
      }
      fVar3 = (fVar3 / (float)_DAT_80147fa4) * 4096.0;
      if (2.1474836e+09 <= fVar3) {
        fVar3 = fVar3 - 2.1474836e+09;
      }
      FUN_800a5a00(iVar1,(int)fVar3 & 0xffff);
      FUN_800a5a60(iVar1,(uint)param_5 << 0x10,(uint)param_6 << 0x10,(uint)param_7 << 0x10,
                   (uint)param_8 << 0x10);
      FUN_800a597c(iVar1);
    }
    FUN_800a56c0();
  }
  return iVar1;
}
