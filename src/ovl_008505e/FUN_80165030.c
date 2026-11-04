/* FUN_80165030
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165030  body 0x80165030..0x801651bf  size 400 B
 * body sha256 740ebec1251b3b0884cd93c068dde61e0ba446c82a80f1b10a7c8aeb388d6ee2
 * provider record sha256 bdd6d6b37636f5b5790089754e9b7055df47b8613f0e601836e5fc710bcaf785
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165030(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x2c3) == '\0') {
    iVar4 = -0x7ff1eed0;
  }
  else {
    iVar4 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 700) == '\0') {
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 500));
    FUN_8016655c(param_1,10,0);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,(int)*(short *)(param_1 + 0x1f6));
  if (iVar2 != 0) {
    bVar1 = *(byte *)(param_1 + 7);
    if (bVar1 == 1) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x7000f00;
      *(undefined1 *)(param_1 + 7) = 2;
      *(undefined2 *)(param_1 + 0x1f6) = 0x100;
    }
    else if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(undefined1 *)(param_1 + 7) = 1;
        *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) & 0xc0 | 2;
        *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x1ea) * 0x100 + 0x12000000;
      }
    }
    else if (bVar1 == 2) {
      FUN_80165a5c(param_1,1);
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xdfff;
      *(undefined1 *)(param_1 + 0x2bf) = 0;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
      if (*(char *)(param_1 + 0x2c9) == '\0') {
        iVar4 = func_0x80032e74(param_1,*(undefined4 *)(iVar4 + 0x28),*(undefined4 *)(iVar4 + 0x30),
                                0x200);
        uVar3 = 0x1060000;
        if (iVar4 == 0) {
          uVar3 = 0x1050000;
        }
      }
      else {
        uVar3 = 0x10d0100;
      }
      *(undefined4 *)(param_1 + 4) = uVar3;
    }
  }
  return;
}
