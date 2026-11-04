/* FUN_8018152c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8018152c  body 0x8018152c..0x8018189f  size 884 B
 * body sha256 b389909e49f38fed1e29fe78620f148883aa548d89a1e516202c8341242b09a3
 * provider record sha256 c9b09e175b35a7081b426a6fa68a7d8b8ce83e098bd08dffd4a02adf052480f6
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8018183c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8018152c(int param_1,int param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  
  FUN_8017b7a8();
  iVar2 = FUN_8017d0f0();
  if (iVar2 != 0) {
    FUN_80181020();
    DAT_80186c98 = 0;
    FUN_801813d8();
    if (param_1 == 1) {
      FUN_801813d8();
      _DAT_801344fc = DAT_80184b38 ^ 1;
      _DAT_801344d0 = param_1;
      func_0x8009ec1c(&DAT_80184b3c,(&DAT_80184b30)[DAT_80184b38 ^ 1]);
      osRecvMesg(0x801344dc,0,1);
      if ((&DAT_80185490)[_DAT_801344fc] == 0) {
        FUN_80181414((&DAT_80184b30)[_DAT_801344fc]);
        (&DAT_80185490)[_DAT_801344fc] = 1;
      }
      FUN_80180b10();
      func_0x8000ec60((&DAT_80184b30)[DAT_80184b38 ^ 1]);
    }
    do {
      iVar2 = FUN_801813d8();
      if (iVar2 == 0) {
        _DAT_801344d0 = 1;
        FUN_8017b5e8(&DAT_80185710);
        osRecvMesg(0x801344dc,0,1);
        if (param_1 == 4) {
          if (param_2 != 0) goto LAB_80181808;
          do {
          } while (_DAT_801344c4 != 3);
        }
        break;
      }
      FUN_801806f4();
      _DAT_801344d0 = 1;
      if (_DAT_801344c4 == 0) {
        _DAT_801344c8 = 4;
      }
      bVar1 = false;
      if ((*(ushort *)(_DAT_801344b0 * 0x112 + -0x7fecbaee) & 0x8000) == 0) {
        iVar2 = FUN_80180c10();
        bVar1 = iVar2 != 0;
      }
      if (bVar1) {
        DAT_8018547c = 1;
        do {
        } while (_DAT_801344c4 != 3);
        goto LAB_80181864;
      }
      osRecvMesg(0x801344dc,0,1);
      if ((&DAT_80185490)[_DAT_801344fc] == 0) {
        FUN_80181414((&DAT_80184b30)[_DAT_801344fc]);
        (&DAT_80185490)[_DAT_801344fc] = 1;
      }
    } while ((param_3 == -1) || (param_3 = param_3 + -2, param_3 != '\0'));
    if (param_2 != 0) {
LAB_80181808:
      _DAT_801344d8 = param_2 << 1;
      do {
      } while (_DAT_801344c4 != 3);
      do {
        FUN_801806f4();
      } while (_DAT_801344c4 == 3);
    }
  }
LAB_80181864:
  FUN_8017b598(DAT_80185828);
  return;
}
