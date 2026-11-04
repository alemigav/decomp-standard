/* FUN_801699d4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x801699d4  body 0x801699d4..0x80169c67  size 660 B
 * body sha256 62535fa3098b748b3935acb85836143f329050645bf6d29f12b59fd86ab8efd8
 * provider record sha256 d6015eb4173e02e01c546c8fc9d62dd04ca43b4e47a942aa6cac5da5e1e17b08
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801699d4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  
  if ((*(ushort *)((int)param_1 + 0x2b6) & 0x4000) == 0) {
    _DAT_800e8b4c = _DAT_800e8b4c + 1;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x4000;
  }
  *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfdff;
  if ((DAT_800e1134 == '\x05') && (_DAT_800e1380 == param_1)) {
    DAT_800e139f = DAT_800e139f & 0x7f;
    DAT_800e138c = DAT_800e138c & 0xed;
    *param_1 = *param_1 & 0xffffeffb;
    _DAT_800e1134 = 0x1000000;
    _DAT_800e1130 = _DAT_800e1130 & 0xffffeffb;
  }
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(uint *)(param_1[0x8d] + 0x468) = *(uint *)(param_1[0x8d] + 0x468) | 0x8000;
    *(uint *)(param_1[0x8d] + 0x5e0) = *(uint *)(param_1[0x8d] + 0x5e0) | 0x8000;
    *(uint *)(param_1[0x8d] + 0x8d0) = *(uint *)(param_1[0x8d] + 0x8d0) | 0x8000;
    *(uint *)(param_1[0x8d] + 0xa48) = *(uint *)(param_1[0x8d] + 0xa48) | 0x8000;
    *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) | 0x8000;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 1) == 0) {
    if ((*(ushort *)((int)param_1 + 0x2b6) & 0x10) != 0) {
      FUN_8016b1f4(param_1,param_2,param_3);
      return;
    }
    if ((*(ushort *)((int)param_1 + 0x2b6) & 2) != 0) {
      func_0x80037780(8000,0,param_1[0x8d] + 0x38,0);
      uVar2 = func_0x80033604();
      uVar4 = 0xb;
      if ((uVar2 & 1) != 0) {
        uVar4 = 0xd;
      }
      func_0x80077d18(uVar4,param_1);
      cVar3 = *(char *)((int)param_1 + 5);
      if ((cVar3 == '\n') && ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0)) {
        FUN_80167910(param_1);
        cVar3 = *(char *)((int)param_1 + 5);
      }
      if (cVar3 == '\v') {
        FUN_80167abc(param_1);
      }
      cVar3 = *(char *)((int)param_1 + 5);
      if ((cVar3 == '\t') || (cVar3 == '\x11')) {
        if ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0) {
          FUN_80167ba4(param_1);
        }
        cVar3 = *(char *)((int)param_1 + 5);
      }
      if (cVar3 == '\x0e') {
        FUN_80167c88(param_1);
      }
      param_1[1] = 0x7090000;
      return;
    }
    pcVar1 = (code *)(&PTR_FUN_8016e568)
                     [(*(byte *)((int)param_1 + 5) - 1) * 9 + (uint)*(byte *)((int)param_1 + 0x26e)]
    ;
  }
  else {
    pcVar1 = (code *)(&PTR_FUN_8016e7f0)[*(byte *)((int)param_1 + 5) - 1];
  }
  (*pcVar1)(param_1,param_2,param_3);
  return;
}
