/* FUN_801665e8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801665e8  body 0x801665e8..0x801666f7  size 272 B
 * body sha256 343a551ac69b7479a7a4efedbb2c6b59b8c8ccdc3c914c0ec7e9a5db2a079a45
 * provider record sha256 d56d9f97fad890feda65510f844359de93ad76a57cce027b2f8ec45cf61f1258
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801665e8(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 0x2c3) == '\0') {
    iVar5 = -0x7ff1eed0;
  }
  else {
    iVar5 = _DAT_800e13ec;
  }
  uVar1 = 0xfffffffe;
  if (-1 < *(short *)(iVar5 + 0x1f2)) {
    if (*(char *)(param_1 + 0x2c3) == '\0') {
      uVar2 = *(uint *)(param_1 + 0x28c);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
    }
    uVar1 = 0;
    if (((int)uVar2 < 4000) && (uVar1 = 0, *(char *)(iVar5 + 0x1a2) == *(char *)(param_1 + 0x1a2)))
    {
      iVar3 = func_0x80032fac(param_1 + 0x28,iVar5 + 0x28,(int)*(short *)(param_1 + 0x66),0x100);
      uVar1 = 0xffffffff;
      if ((iVar3 == 0) && (uVar1 = 0xfffffffc, (*(byte *)(iVar5 + 0x26f) & 0x80) == 0)) {
        if (*(short *)(iVar5 + 0x1f2) < 0x15) {
          cVar4 = func_0x80033144(param_1,iVar5);
          if (cVar4 == '\0') {
            return 1;
          }
          if (*(short *)(param_1 + 0x2b6) < 600) {
            return 0xfffffffe;
          }
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}
